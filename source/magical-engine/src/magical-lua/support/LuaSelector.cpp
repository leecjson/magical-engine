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
#include "LuaSelector.h"
#include "LuaState.h"
#include "LuaTable.h"
#include "LuaFunction.h"
#include "LuaMacros.h"
#include "LuaObject.h"

LuaGlobalSelector::LuaGlobalSelector( void )
{

}

LuaGlobalSelector::~LuaGlobalSelector( void )
{

}

bool LuaGlobalSelector::isNil( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	bool ret = false;
	lua_getglobal( L, _key.c_str() );
	if( lua_isnil( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 1 );
	return ret;
}

bool LuaGlobalSelector::isNumber( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	bool ret = false;
	lua_getglobal( L, _key.c_str() );
	if( lua_isnumber( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 1 );
	return ret;
}

bool LuaGlobalSelector::isString( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	bool ret = false;
	lua_getglobal( L, _key.c_str() );
	if( lua_isstring( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 1 );
	return ret;
}

bool LuaGlobalSelector::isUserData( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	bool ret = false;
	lua_getglobal( L, _key.c_str() );
	if( lua_isuserdata( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 1 );
	return ret;
}

bool LuaGlobalSelector::isTable( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	bool ret = false;
	lua_getglobal( L, _key.c_str() );
	if( lua_istable( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 1 );
	return ret;
}

bool LuaGlobalSelector::isFunction( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	bool ret = false;
	lua_getglobal( L, _key.c_str() );
	if( lua_isfunction( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 1 );
	return ret;
}

bool LuaGlobalSelector::operator==( LuaT t ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	bool ret = false;
	lua_getglobal( L, _key.c_str() );
	switch( t )
	{
	case LuaT::Nil:
		ret = lua_isnil( L, -1 );
		break;
	case LuaT::Boolean:
		ret = lua_isboolean( L, -1 );
		break;
	case LuaT::Number:
		ret = lua_isnumber( L, -1 );
		break;
	case LuaT::String:
		ret = lua_isstring( L, -1 );
		break;
	case LuaT::UserData:
		ret = lua_isuserdata( L, -1 );
		break;
	case LuaT::Function:
		ret = lua_isfunction( L, -1 );
		break;
	case LuaT::Table:
		ret = lua_istable( L, -1 );
		break;
	default:
		ret = false;
		break;
	}
	lua_pop( L, 1 );
	return ret;
}

int LuaGlobalSelector::toInt( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	int ret = 0;
	lua_getglobal( L, _key.c_str() );
	if( lua_isnumber( L, -1 ) )
	{
		ret = (int) lua_tointeger( L, -1 );
	}
	lua_pop( L, 1 );
	return ret;
}

float LuaGlobalSelector::toFloat( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	float ret = 0.0f;
	lua_getglobal( L, _key.c_str() );
	if( lua_isnumber( L, -1 ) )
	{
		ret = (float) lua_tonumber( L, -1 );
	}
	lua_pop( L, 1 );
	return ret;
}

double LuaGlobalSelector::toDouble( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	double ret = 0.0;
	lua_getglobal( L, _key.c_str() );
	if( lua_isnumber( L, -1 ) )
	{
		ret = (double) lua_tonumber( L, -1 );
	}
	lua_pop( L, 1 );
	return ret;
}

std::string LuaGlobalSelector::toString( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	std::string ret;
	lua_getglobal( L, _key.c_str() );
	if( lua_isstring( L, -1 ) )
	{
		ret = lua_tostring( L, -1 );
	}
	lua_pop( L, 1 );
	return ret;
}

void* LuaGlobalSelector::toUserData( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	void* ret = nullptr;
	lua_getglobal( L, _key.c_str() );
	if( lua_isuserdata( L, -1 ) )
	{
		ret = lua_touserdata( L, -1 );
	}
	lua_pop( L, 1 );
	return ret;
}

LuaFunction LuaGlobalSelector::toLuaFunction( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	LuaFunction lf;
	lua_getglobal( L, _key.c_str() );

	int handler = tolua_ext_tofunction( L, lua_gettop( L ), 0 );
	if( handler != 0 )
	{
		lf.bind( _L, handler );
	}
	lua_pop( L, 1 );
	return lf;
}

LuaTable LuaGlobalSelector::toLuaTable( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	LuaTable lt;
	lua_getglobal( L, _key.c_str() );

	int handler = tolua_ext_totable( L, lua_gettop( L ), 0 );
	if( handler != 0 )
	{
		lt.bind( _L, handler );
	}
	lua_pop( L, 1 );
	return lt;
}

LuaObject LuaGlobalSelector::toLuaObject( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	lua_State* L = _L->cPtr();
	LuaObject lobj;
	lua_getglobal( L, _key.c_str() );

	switch( lua_type( L, -1 ) )
	{
	case LUA_TNIL:
		lobj = nullptr;
		break;
	case LUA_TBOOLEAN:
		lobj = (bool) lua_toboolean( L, -1 );
		break;
	case LUA_TNUMBER:
		lobj = (double) lua_tonumber( L, -1 );
		break;
	case LUA_TSTRING:
		lobj = lua_tostring( L, -1 );
		break;
	case LUA_TUSERDATA:
		{
			int top = lua_gettop( L );
			std::string type = tolua_typename( L, top );
			lua_pop( L, 1 );
			void* userdata = tolua_tousertype( L, top, 0 );
			lobj.set( userdata, type.c_str() );
		}
		break;
	case LUA_TFUNCTION:
		{
			LuaFunction lf;
			int handler = tolua_ext_tofunction( L, lua_gettop( L ), 0 );
			if( handler != 0 )
			{
				lf.bind( _L, handler );
			}
			lobj = lf;
		}
		break;
	case LUA_TTABLE:
		{
			LuaTable lt;
			int handler = tolua_ext_totable( L, lua_gettop( L ), 0 );
			if( handler != 0 )
			{
				lt.bind( _L, handler );
			}
			lobj = lt;
		}
		break;
	default:
		lobj = nullptr;
		break;
	}
	lua_pop( L, 1 );
	return lobj;
}

void LuaGlobalSelector::operator=( int num )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	_L->push( num );
	lua_setglobal( _L->cPtr(), _key.c_str() );
}

void LuaGlobalSelector::operator=( float num )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	_L->push( num );
	lua_setglobal( _L->cPtr(), _key.c_str() );
}

void LuaGlobalSelector::operator=( double num )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	_L->push( num );
	lua_setglobal( _L->cPtr(), _key.c_str() );
}

void LuaGlobalSelector::operator=( const char* str )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	_L->push( str );
	lua_setglobal( _L->cPtr(), _key.c_str() );
}

void LuaGlobalSelector::operator=( const std::string& str )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	_L->push( str );
	lua_setglobal( _L->cPtr(), _key.c_str() );
}

void LuaGlobalSelector::operator=( std::nullptr_t nil )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	_L->push( nil );
	lua_setglobal( _L->cPtr(), _key.c_str() );
}

void LuaGlobalSelector::operator=( const LuaTable& lt )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	_L->push( lt );
	lua_setglobal( _L->cPtr(), _key.c_str() );
}

void LuaGlobalSelector::operator=( const LuaFunction& lf )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	_L->push( lf );
	lua_setglobal( _L->cPtr(), _key.c_str() );
}

void LuaGlobalSelector::operator=( const LuaObject& lobj )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	_L->push( lobj );
	lua_setglobal( _L->cPtr(), _key.c_str() );
}

void LuaGlobalSelector::set( void* userdata, const char* type, bool gc )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	magicalAssert( userdata && type && strlen( type ) > 0, "userdata and type should not be nullptr" );
	_L->push( userdata, type, gc );
	lua_setglobal( _L->cPtr(), _key.c_str() );
}

void LuaGlobalSelector::select( const char* key )
{
	_key = key;
}

LuaTableSelector::LuaTableSelector( void )
{

}

LuaTableSelector::~LuaTableSelector( void )
{

}

bool LuaTableSelector::isNil( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return false;

	bool ret = false;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	if( lua_isnil( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 2 );
	return ret;
}

bool LuaTableSelector::isNumber( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return false;

	bool ret = false;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	if( lua_isnumber( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 2 );
	return ret;
}

bool LuaTableSelector::isString( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return false;

	bool ret = false;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	if( lua_isstring( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 2 );
	return ret;
}

bool LuaTableSelector::isUserData( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return false;

	bool ret = false;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	if( lua_isuserdata( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 2 );
	return ret;
}

bool LuaTableSelector::isTable( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return false;

	bool ret = false;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	if( lua_istable( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 2 );
	return ret;
}

bool LuaTableSelector::isFunction( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return false;

	bool ret = false;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	if( lua_isfunction( L, -1 ) )
	{
		ret = true;
	}
	lua_pop( L, 2 );
	return ret;
}

bool LuaTableSelector::operator==( LuaT t ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return false;

	bool ret = false;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	switch( t )
	{
	case LuaT::Nil:
		ret = lua_isnil( L, -1 );
		break;
	case LuaT::Boolean:
		ret = lua_isboolean( L, -1 );
		break;
	case LuaT::Number:
		ret = lua_isnumber( L, -1 );
		break;
	case LuaT::String:
		ret = lua_isstring( L, -1 );
		break;
	case LuaT::UserData:
		ret = lua_isuserdata( L, -1 );
		break;
	case LuaT::Function:
		ret = lua_isfunction( L, -1 );
		break;
	case LuaT::Table:
		ret = lua_istable( L, -1 );
		break;
	default:
		ret = false;
		break;
	}
	lua_pop( L, 2 );
	return ret;
}

int LuaTableSelector::toInt( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return 0;

	int ret = 0;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	if( lua_isnumber( L, -1 ) )
	{
		ret = (int) lua_tointeger( L, -1 );
	}
	lua_pop( L, 2 );
	return ret;
}

float LuaTableSelector::toFloat( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return 0.0f;

	float ret = 0.0f;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	if( lua_isnumber( L, -1 ) )
	{
		ret = (float) lua_tonumber( L, -1 );
	}
	lua_pop( L, 2 );
	return ret;
}

double LuaTableSelector::toDouble( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return 0.0;

	double ret = 0.0;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	if( lua_isnumber( L, -1 ) )
	{
		ret = (double) lua_tonumber( L, -1 );
	}
	lua_pop( L, 2 );
	return ret;
}

std::string LuaTableSelector::toString( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return "";

	std::string ret;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	if( lua_isstring( L, -1 ) )
	{
		ret = lua_tostring( L, -1 );
	}
	lua_pop( L, 2 );
	return ret;
}

void* LuaTableSelector::toUserData( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return nullptr;

	void* ret = nullptr;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	if( lua_isuserdata( L, -1 ) )
	{
		ret = lua_touserdata( L, -1 );
	}
	lua_pop( L, 2 );
	return ret;
}

LuaFunction LuaTableSelector::toLuaFunction( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return nullptr;

	LuaFunction lf;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	int handler = tolua_ext_tofunction( L, lua_gettop( L ), 0 );
	if( handler != 0 )
	{
		lf.bind( _L, handler );
	}
	lua_pop( L, 2 );
	return lf;
}

LuaTable LuaTableSelector::toLuaTable( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return nullptr;

	LuaTable lt;
	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	lua_getfield( L, -1, _key.c_str() );
	int handler = tolua_ext_totable( L, lua_gettop( L ), 0 );
	if( handler != 0 )
	{
		lt.bind( _L, handler );
	}
	lua_pop( L, 2 );
	return lt;
}

LuaObject LuaTableSelector::toLuaObject( void ) const
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return nullptr;

	lua_State* L = _L->cPtr();
	LuaObject lobj;
	tolua_ext_get_table_by_handler( L, _handler );
	lua_getfield( L, -1, _key.c_str() );

	switch( lua_type( L, -1 ) )
	{
	case LUA_TNIL:
		lobj = nullptr;
		break;
	case LUA_TBOOLEAN:
		lobj = (bool) lua_toboolean( L, -1 );
		break;
	case LUA_TNUMBER:
		lobj = (double) lua_tonumber( L, -1 );
		break;
	case LUA_TSTRING:
		lobj = lua_tostring( L, -1 );
		break;
	case LUA_TUSERDATA:
		{
			int top = lua_gettop( L );
			std::string type = tolua_typename( L, top );
			lua_pop( L, 1 );
			void* userdata = tolua_tousertype( L, top, 0 );
			lobj.set( userdata, type.c_str() );
		}
		break;
	case LUA_TFUNCTION:
		{
			LuaFunction lf;
			int handler = tolua_ext_tofunction( L, lua_gettop( L ), 0 );
			if( handler != 0 )
			{
				lf.bind( _L, handler );
			}
			lobj = lf;
		}
		break;
	case LUA_TTABLE:
		{
			LuaTable lt;
			int handler = tolua_ext_totable( L, lua_gettop( L ), 0 );
			if( handler != 0 )
			{
				lt.bind( _L, handler );
			}
			lobj = lt;
		}
		break;
	default:
		lobj = nullptr;
		break;
	}
	lua_pop( L, 1 );
	return lobj;
}

void LuaTableSelector::operator=( int num )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return;

	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	_L->push( num );
	lua_setfield( L, -2, _key.c_str() );
	lua_pop( L, 1 );
}

void LuaTableSelector::operator=( float num )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return;

	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	_L->push( num );
	lua_setfield( L, -2, _key.c_str() );
	lua_pop( L, 1 );
}

void LuaTableSelector::operator=( double num )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return;

	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	_L->push( num );
	lua_setfield( L, -2, _key.c_str() );
	lua_pop( L, 1 );
}

void LuaTableSelector::operator=( const char* str )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return;

	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	_L->push( str );
	lua_setfield( L, -2, _key.c_str() );
	lua_pop( L, 1 );
}

void LuaTableSelector::operator=( const std::string& str )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return;

	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	_L->push( str );
	lua_setfield( L, -2, _key.c_str() );
	lua_pop( L, 1 );
}

void LuaTableSelector::operator=( std::nullptr_t nil )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return;

	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	_L->push( nil );
	lua_setfield( L, -2, _key.c_str() );
	lua_pop( L, 1 );
}

void LuaTableSelector::operator=( const LuaTable& lt )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return;

	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	_L->push( lt );
	lua_setfield( L, -2, _key.c_str() );
	lua_pop( L, 1 );
}

void LuaTableSelector::operator=( const LuaFunction& lf )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return;

	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	_L->push( lf );
	lua_setfield( L, -2, _key.c_str() );
	lua_pop( L, 1 );
}

void LuaTableSelector::operator=( const LuaObject& lobj )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	if( !_L || !_handler ) 
		return;

	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	_L->push( lobj );
	lua_setfield( L, -2, _key.c_str() );
	lua_pop( L, 1 );
}

void LuaTableSelector::set( void* userdata, const char* type, bool gc )
{
	magicalAssert( !_key.empty(), "key should not be empty!" );
	magicalAssert( userdata && type && strlen( type ) > 0, "userdata and type should not be nullptr" );
	if( !_L || !_handler ) 
		return;

	lua_State* L = _L->cPtr();
	tolua_ext_get_table_by_handler( L, _handler );

	_L->push( userdata, type, gc );
	lua_setfield( L, -2, _key.c_str() );
	lua_pop( L, 1 );
}

void LuaTableSelector::select( const char* key, LuaState* L, LuaTableHandler handler )
{
	_key = key;
	_L = L;
	_handler = handler;
}