/******************************************************************************
The MIT License (MIT)

Copyright (c) 2014 Jason.lee

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/
#include "LuaState.h"
#include "AssetsSystem.h"

#include "lua.hpp"
#include "tolua++.h"
#include "tolua_ext.h"
#include "LuaExtensions.h"

#include "BindCommon.h"

//int LuaState::executeGlobalFunction( const char* func_name, int retc, int argc ) const
//{
//	lua_getglobal( _L, func_name );
//	if( lua_isfunction( _L, -1 ) )
//	{
//		int ret = 0;
//		if( argc != 0 )
//		{
//			lua_insert( _L, -( argc + 1 ) );
//			ret = lua_pcall( _L, argc, retc, 0 );
//		}
//		else
//		{
//			ret = lua_pcall( _L, 0, retc, 0 );
//		}
//		if( ret != 0 )
//		{
//			magicalHandleLuaError( _L );
//		}
//		return ret;
//	}
//	else
//	{
//		magicalFormat( "name '%s' does not represent a lua global function", func_name );
//		magicalSetLastErrorInfoB( magicalBuffer );
//		magicalLogLastError();
//		lua_pop( _L, 1 );
//	}
//	return -1;
//}

LuaState::LuaState( void )
{
	_L = luaL_newstate();
	magicalAssert( _L, "luaL_newstate() failed" );
}

LuaState::~LuaState( void )
{
	if( _L != nullptr ) 
	{
		lua_close( _L );
	}
}

Shared<LuaState> LuaState::create( void )
{
	LuaState* ret = new LuaState();
	magicalAssert( ret, "new LuaState() failed" );
	return Shared<LuaState>( Initializer<LuaState>(ret) );
}

void LuaState::openLibs( void )
{
	luaL_openlibs( _L );
}

void LuaState::attachPath( const char* path )
{
	lua_getglobal( _L, "package" );
	lua_getfield( _L, -1, "path" );
	const char* cur_path = lua_tostring( _L, -1 );
	lua_pushfstring( _L, "%s;%s/?.lua", cur_path, path );
	lua_setfield( _L, -3, "path" );
	lua_pop( _L, 2 );
}

lua_State* LuaState::cPointer( void ) const
{
	return _L;
}

LuaCode LuaState::runScript( const char* script )
{
	int ret = luaL_dostring( _L, script );
	if( ret == 0 )
		return (LuaCode) 0;

	magicalHandleLuaError( _L );
	lua_pop( _L, 1 );
	return (LuaCode) ret;
}

LuaCode LuaState::runScriptFile( const char* file )
{
	int ret = luaL_dofile( _L, file );
	if( ret == 0 )
		return (LuaCode) 0;

	magicalHandleLuaError( _L );
	lua_pop( _L, 1 );
	return (LuaCode) ret;
}

LuaState& LuaState::back( void )
{
	magicalAssert( _lso.model == LuaStateOperation::None, "invaild operate!" );
	lua_pop( _L, 1 );
	_is_global = lua_gettop( _L ) == 0 ? true : false;
	_lso.model = LuaStateOperation::None;
	return *this;
}

LuaState& LuaState::back( int count )
{
	magicalAssert( _lso.model == LuaStateOperation::None, "invaild operate!" );
	lua_pop( _L, count );
	_is_global = lua_gettop( _L ) == 0 ? true : false;
	_lso.model = LuaStateOperation::None;
	return *this;
}

void LuaState::clean( void )
{
	magicalAssert( _lso.model == LuaStateOperation::None, "invaild operate!" );
	lua_settop( _L, 0 );
	_is_global = true;
	_lso.model = LuaStateOperation::None;
}

LuaState& LuaState::operator<<( int count )
{
	return back( count );
}

LuaState& LuaState::operator--( void )
{
	return back();
}

LuaState& LuaState::enter( const char* name )
{
	magicalAssert( _lso.model == LuaStateOperation::None, "invaild operate!" );
	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, name );
	magicalAssert( lua_type( _L, -1 ) == LUA_TTABLE, "invaild operate!" );

	_is_global = false;
	_lso.model = LuaStateOperation::None;
	return *this;
}

LuaState& LuaState::operator>>( const char* name )
{
	return enter( name );
}

LuaState& LuaState::operator[]( const char* name )
{
	magicalAssert( _lso.model == LuaStateOperation::None, "invaild operate!" );
	magicalAssert( name && strlen( name ) > 0, "name should not be nullptr or length should > 0." );
	_lso.model |= LuaStateOperation::ReadyKey;
	_lso.key = name;
	return *this;
}

LuaState& LuaState::operator[]( size_t i )
{
	_lso.model |= LuaStateOperation::ReadyArg1;
	_lso.arg1 = i;
	return *this;
}

bool LuaState::isNumber( void ) const
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, _lso.key.c_str() );
	bool ret = lua_isnumber( _L, -1 );
	lua_pop( _L, 1 );

	_lso.model = LuaStateOperation::None;
	return ret;
}

bool LuaState::isString( void ) const
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, _lso.key.c_str() );
	bool ret = lua_isstring( _L, -1 );
	lua_pop( _L, 1 );

	_lso.model = LuaStateOperation::None;
	return ret;
}

bool LuaState::isUserData( void ) const
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, _lso.key.c_str() );
	bool ret = lua_isuserdata( _L, -1 );
	lua_pop( _L, 1 );

	_lso.model = LuaStateOperation::None;
	return ret;
}

bool LuaState::isTable( void ) const
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, _lso.key.c_str() );
	bool ret = lua_istable( _L, -1 );
	lua_pop( _L, 1 );

	_lso.model = LuaStateOperation::None;
	return ret;
}

bool LuaState::isFunction( void ) const
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, _lso.key.c_str() );
	bool ret = lua_isfunction( _L, -1 );
	lua_pop( _L, 1 );

	_lso.model = LuaStateOperation::None;
	return ret;
}

LuaState& LuaState::operator=( int n )
{
	return set( n );
}

LuaState& LuaState::operator=( float n )
{
	return set( n );
}

LuaState& LuaState::operator=( double n )
{
	return set( n );
}

LuaState& LuaState::operator=( bool b )
{
	return set( b );
}

LuaState& LuaState::operator=( const char* str )
{
	return set( str );
}

LuaState& LuaState::set( int n )
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -2;

	lua_pushinteger( _L, (lua_Integer) n );
	lua_setfield( _L, idx, _lso.key.c_str() );
	_lso.model = LuaStateOperation::None;
	return *this;
}

LuaState& LuaState::set( float n )
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -2;

	lua_pushnumber( _L, (lua_Number) n );
	lua_setfield( _L, idx, _lso.key.c_str() );
	_lso.model = LuaStateOperation::None;
	return *this;
}

LuaState& LuaState::set( double n )
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -2;

	lua_pushnumber( _L, (lua_Number) n );
	lua_setfield( _L, idx, _lso.key.c_str() );
	_lso.model = LuaStateOperation::None;
	return *this;
}

LuaState& LuaState::set( bool b )
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -2;

	lua_pushboolean( _L, (int) b );
	lua_setfield( _L, idx, _lso.key.c_str() );
	_lso.model = LuaStateOperation::None;
	return *this;
}

LuaState& LuaState::set( const char* str )
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -2;

	lua_pushstring( _L, str );
	lua_setfield( _L, idx, _lso.key.c_str() );
	_lso.model = LuaStateOperation::None;
	return *this;
}

LuaState& LuaState::set( void* userdata, const char* type, bool gc )
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -2;

	tolua_pushusertype( _L, userdata, type );
	if( gc )
		tolua_register_gc( _L, lua_gettop( _L ) );

	lua_setfield( _L, idx, _lso.key.c_str() );
	_lso.model = LuaStateOperation::None;
	return *this;
}

int LuaState::toInt( void ) const
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, _lso.key.c_str() );
	magicalAssert( lua_isnumber( _L, -1 ), "top of stack is not a int value" );
	int ret = (int) lua_tonumber( _L, -1 );
	lua_pop( _L, 1 );

	_lso.model = LuaStateOperation::None;
	return ret;
}

float LuaState::toFloat( void ) const
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, _lso.key.c_str() );
	magicalAssert( lua_isnumber( _L, -1 ), "top of stack is not a number value" );
	float ret = (float) lua_tonumber( _L, -1 );
	lua_pop( _L, 1 );

	_lso.model = LuaStateOperation::None;
	return ret;
}

double LuaState::toDouble( void ) const
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, _lso.key.c_str() );
	magicalAssert( lua_isnumber( _L, -1 ), "top of stack is not a number value" );
	double ret = (double) lua_tonumber( _L, -1 );
	lua_pop( _L, 1 );

	_lso.model = LuaStateOperation::None;
	return ret;
}

const char* LuaState::toString( void ) const
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, _lso.key.c_str() );
	magicalAssert( lua_isstring( _L, -1 ), "top of stack is not a string value" );
	const char* ret = lua_tostring( _L, -1 );
	lua_pop( _L, 1 );

	_lso.model = LuaStateOperation::None;
	return ret;
}

void* LuaState::toUserData( void ) const
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, _lso.key.c_str() );
	magicalAssert( lua_isuserdata( _L, -1 ), "top of stack is not a userdata value" );
	void* ret = lua_touserdata( _L, -1 );
	lua_pop( _L, 1 );

	_lso.model = LuaStateOperation::None;
	return ret;
}

void LuaState::operator()( void )
{
	magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );
	int nresults = 0;
	if( _lso.model & LuaStateOperation::ReadyArg1 && _lso.arg1 > 0 )
	{
		nresults = _lso.arg1;
		_lso.model = LuaStateOperation::Invoking;
	}
	else
	{
		_lso.model = LuaStateOperation::None;
	}

	int idx = LUA_GLOBALSINDEX;
	if( _is_global == false ) idx = -1;

	lua_getfield( _L, idx, _lso.key.c_str() );
	int ret = lua_pcall( _L, 0, nresults, 0 );
	magicalAssert( ret == 0, lua_tostring( _L, -1 ) );
}

int LuaState::returnInt( void ) const
{
	magicalAssert( _lso.model == LuaStateOperation::Invoking, "invaild operate!" );
	magicalAssert( lua_isnumber( _L, -_lso.arg1 ), "return value is not type of int" );
	int ret = (int) lua_tonumber( _L, -_lso.arg1 );
	lua_remove( _L, -_lso.arg1 );

	_lso.arg1 --;
	if( _lso.arg1 == 0 )
		_lso.model = LuaStateOperation::None;
	return ret;
}

float LuaState::returnFloat( void ) const
{
	magicalAssert( _lso.model == LuaStateOperation::Invoking, "invaild operate!" );
	magicalAssert( lua_isnumber( _L, -_lso.arg1 ), "return value is not type of number" );
	float ret = (float) lua_tonumber( _L, -_lso.arg1 );
	lua_remove( _L, -_lso.arg1 );

	_lso.arg1 --;
	if( _lso.arg1 == 0 )
		_lso.model = LuaStateOperation::None;
	return ret;
}

double LuaState::returnDouble( void ) const
{
	magicalAssert( _lso.model == LuaStateOperation::Invoking, "invaild operate!" );
	magicalAssert( lua_isnumber( _L, -_lso.arg1 ), "return value is not type of number" );
	double ret = (double) lua_tonumber( _L, -_lso.arg1 );
	lua_remove( _L, -_lso.arg1 );

	_lso.arg1 --;
	if( _lso.arg1 == 0 )
		_lso.model = LuaStateOperation::None;
	return ret;
}

const char* LuaState::returnString( void ) const
{
	magicalAssert( _lso.model == LuaStateOperation::Invoking, "invaild operate!" );
	magicalAssert( lua_isstring( _L, -_lso.arg1 ), "return value is not type of string" );
	const char* ret = lua_tostring( _L, -_lso.arg1 );
	lua_remove( _L, -_lso.arg1 );

	_lso.arg1 --;
	if( _lso.arg1 == 0 )
		_lso.model = LuaStateOperation::None;
	return ret;
}

void* LuaState::returnUserData( void ) const
{
	magicalAssert( _lso.model == LuaStateOperation::Invoking, "invaild operate!" );
	magicalAssert( lua_isstring( _L, -_lso.arg1 ), "return value is not type of userdata" );
	void* ret = lua_touserdata( _L, -_lso.arg1 );
	lua_remove( _L, -_lso.arg1 );
	
	_lso.arg1 --;
	if( _lso.arg1 == 0 )
		_lso.model = LuaStateOperation::None;
	return ret;
}

void LuaState::ignore( void ) const
{
	magicalAssert( _lso.model == LuaStateOperation::Invoking, "invaild operate!" );
	lua_remove( _L, -_lso.arg1 );

	_lso.arg1 --;
	if( _lso.arg1 == 0 )
		_lso.model = LuaStateOperation::None;
}

void LuaState::ignoreAll( void ) const
{
	magicalAssert( _lso.model == LuaStateOperation::Invoking, "invaild operate!" );
	lua_pop( _L, _lso.arg1 );
	_lso.model = LuaStateOperation::None;
}

void LuaState::push( std::nullptr_t nil )
{
	lua_pushnil( _L );
}

void LuaState::push( int n )
{
	lua_pushinteger( _L, (lua_Integer) n );
}

void LuaState::push( float n )
{
	lua_pushnumber( _L, (lua_Number) n );
}

void LuaState::push( double n )
{
	lua_pushnumber( _L, (lua_Number) n );
}

void LuaState::push( bool b )
{
	lua_pushboolean( _L, b );
}

void LuaState::push( const char* str )
{
	lua_pushstring( _L, str );
}

//void LuaState::pushLString( const char* str, size_t len )
//{
//	lua_pushlstring( _L, str, len );
//}
//
//void LuaState::pushUserData( void* userdata, const char* type, bool gc )
//{
//	tolua_pushusertype( _L, userdata, type );
//
//	if( gc )
//	{
//		tolua_register_gc( _L, lua_gettop( _L ) );
//	}
//}


