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
#include "LuaObject.h"
#include "LuaTable.h"
#include "LuaFunction.h"

#include "BindCommon.h"

LuaState::LuaState( void )
{
	_L = luaL_newstate();
	magicalAssert( _L, "luaL_newstate() failed" );

	_selector._L = this;
}

LuaState::~LuaState( void )
{
	if( _L != nullptr ) 
	{
		lua_close( _L );
	}
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

LuaCode LuaState::runScript( const char* lscript )
{
	int ret = luaL_dostring( _L, lscript );
	if( ret == 0 )
		return (LuaCode) 0;

	magicalHandleLuaError( _L );
	lua_pop( _L, 1 );
	return (LuaCode) ret;
}

LuaCode LuaState::runScriptFile( const char* lfile )
{
	int ret = luaL_dofile( _L, lfile );
	if( ret == 0 )
		return (LuaCode) 0;

	magicalHandleLuaError( _L );
	lua_pop( _L, 1 );
	return (LuaCode) ret;
}

LuaGlobalSelector& LuaState::operator[]( const char* key )
{
	_selector.select( key );
	return _selector;
}

void LuaState::push( std::nullptr_t nil )
{
	lua_pushnil( _L );
}

void LuaState::push( bool b )
{
	lua_pushboolean( _L, (int) b );
}

void LuaState::push( int num )
{
	lua_pushinteger( _L, (lua_Integer) num );
}

void LuaState::push( float num )
{
	lua_pushnumber( _L, (lua_Number) num );
}

void LuaState::push( double num )
{
	lua_pushnumber( _L, (lua_Number) num );
}

void LuaState::push( const char* str )
{
	lua_pushstring( _L, str );
}

void LuaState::push( const std::string& str )
{
	lua_pushstring( _L, str.c_str() );
}

void LuaState::push( void* userdata, const char* type, bool gc )
{
	tolua_pushusertype( _L, userdata, type );

	if( gc )
	{
		tolua_register_gc( _L, lua_gettop( _L ) );
	}
}

void LuaState::push( const LuaFunction& lf )
{
	if( lf == nullptr )
	{
		lua_pushnil( _L );
	}
	else
	{
		tolua_ext_get_function_by_handler( _L, lf._handler );
	}
}

void LuaState::push( const LuaTable& lt )
{
	if( lt == nullptr )
	{
		lua_pushnil( _L );
	}
	else
	{
		tolua_ext_get_table_by_handler( _L, lt._handler );
	}
}

void LuaState::push( const LuaObject& lobj )
{
	switch( lobj._type )
	{
	case LuaT::Nil:
		lua_pushnil( _L );
		break;
	case LuaT::Boolean:
		lua_pushboolean( _L, (int) lobj._boolean );
		break;
	case LuaT::Number:
		lua_pushnumber( _L, (lua_Number) lobj._number );
		break;
	case LuaT::String:
		lua_pushstring( _L, lobj._string.c_str() );
		break;
	case LuaT::UserData:
		push( lobj._userdata, lobj._usertype.c_str(), lobj._is_gc );
		break;
	case LuaT::Function:
		push( lobj._function );
		break;
	case LuaT::Table:
		push( lobj._table );
		break;
	default:
		lua_pushnil( _L );
		break;
	}
}