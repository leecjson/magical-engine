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

#include "lua.hpp"
#include "tolua_ext.h"
#include "Common.h"
#include "AssetsSystem.h"

#include "LuaCommon.h"

LuaState_t::LuaState_t( void )
{
	_L = luaL_newstate();
	magicalAssert( _L, "_L = luaL_newstate()" );
	luaL_openlibs( _L );
	luaopen_tolua_ext( _L );
	luaopen_common( _L );
}

LuaState_t::~LuaState_t( void )
{
	if( _L != nullptr ) 
	{
		lua_close(_L);
	}
}

lua_State* LuaState_t::getState( void ) const
{
	return _L;
}

int LuaState_t::executeScriptFile( const char* file ) const
{
//#ifdef MAG_WIN32
//	std::string abs_path = AssetsSystem::toAbsolutePath( file );
//	int ret = luaL_dofile( _L, abs_path.c_str() );
//#endif
//	if( ret != 0 )
//	{
//		handleLuaError();
//		lua_pop(_L, 1);
//		return ret;
//	}
//	return 0;
	return 0;
}

int LuaState_t::executeScriptCode( const char* codes ) const
{
	int ret = luaL_dostring( _L, codes );
	if( ret != 0 )
	{
		handleLuaError();
		lua_pop(_L, 1);
		return ret;
	}
	return 0;
}

int LuaState_t::executeGlobalFunction( const char* func_name, int retc, int argc ) const
{
	lua_getglobal( _L, func_name );
	if( lua_isfunction(_L, -1) )
	{
		int ret = 0;
		if( argc != 0 )
		{
			lua_insert( _L, -(argc + 1) );
			ret = lua_pcall( _L, argc, retc, 0 );
		}
		else
		{
			ret = lua_pcall( _L, 0, retc, 0 );
		}
		if( ret != 0 )
		{
			handleLuaError();
		}
		return ret;
	}
	else
	{
		char buf[256];
		sprintf( buf, "name '%s' does not represent a lua global function", func_name );

		magicalSetLastErrorInfo( buf );
		magicalLogLastError();
		lua_pop( _L, 1 );
	}
	return -1;
}

int LuaState_t::isGlobalFunctionExists( const char* func_name ) const
{
	int ret = 0;
	lua_getglobal( _L, func_name );
	ret = lua_isfunction( _L, -1 );
	lua_pop( _L, 1 );
	return ret;
}

void LuaState_t::pushNil( void ) const
{
	lua_pushnil( _L );
}

void LuaState_t::pushInt( int num ) const
{
	lua_pushinteger( _L, num );
}

void LuaState_t::pushFloat( float num ) const
{
	lua_pushnumber( _L, num );
}

void LuaState_t::pushBoolean( bool con ) const
{
	lua_pushboolean( _L, con );
}

void LuaState_t::pushString( const char* str ) const
{
	lua_pushstring( _L, str );
}

void LuaState_t::pushString( const char* str, int len ) const
{
	lua_pushlstring( _L, str, len );
}

void LuaState_t::pushUserData( void* obj, const char* type ) const
{
	tolua_pushusertype( _L, obj, type );
}

void LuaState_t::clean( void ) const
{
	lua_settop( _L, 0 );
}

void LuaState_t::handleLuaError( void ) const
{
	if( lua_type(_L, -1) == LUA_TSTRING )
	{
		const char* info  = lua_tostring( _L, -1 );
		magicalSetLastErrorInfo( info );
		magicalLogLastError();
		lua_pop(_L, -1);
	}
}