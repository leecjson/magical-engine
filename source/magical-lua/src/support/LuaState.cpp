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

LuaState::LuaState( void )
{
	_L = luaL_newstate();
	magicalAssert( _L, "luaL_newstate() failed" );

	// std
	luaL_openlibs( _L );
	luaopen_tolua_ext( _L );

	// extensions
	luaopen_extensions( _L );
	// binding
	luaopen_common( _L );

#ifdef MAG_WIN32
	std::string default_search_path = Assets::getAssetsPath();
	default_search_path += "standard/script";
	addModulePath( default_search_path.c_str() );
#endif
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

lua_State* LuaState::ptr( void ) const
{
	return _L;
}

void LuaState::addModulePath( const char* path )
{
	lua_getglobal( _L, "package" );
    lua_getfield( _L, -1, "path" );
    const char* cur_path = lua_tostring( _L, -1 );
    lua_pushfstring( _L, "%s;%s/?.lua", cur_path, path );
    lua_setfield( _L, -3, "path" );
    lua_pop( _L, 2 );
}

int LuaState::executeScriptFile( const char* file ) const
{
	int ret = luaL_dofile( _L, file );
	if( ret != 0 )
	{
		handleLuaError();
		lua_pop(_L, 1);
		return ret;
	}
	return 0;
}

int LuaState::executeScriptCode( const char* codes ) const
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

int LuaState::executeGlobalFunction( const char* func_name, int retc, int argc ) const
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

int LuaState::isGlobalFunctionExist( const char* func_name ) const
{
	int ret = 0;
	lua_getglobal( _L, func_name );
	ret = lua_isfunction( _L, -1 );
	lua_pop( _L, 1 );
	return ret;
}

void LuaState::pushNil( void ) const
{
	lua_pushnil( _L );
}

void LuaState::pushInt( int num ) const
{
	lua_pushinteger( _L, num );
}

void LuaState::pushFloat( float num ) const
{
	lua_pushnumber( _L, num );
}

void LuaState::pushBoolean( bool con ) const
{
	lua_pushboolean( _L, con );
}

void LuaState::pushString( const char* str ) const
{
	lua_pushstring( _L, str );
}

void LuaState::pushString( const char* str, int len ) const
{
	lua_pushlstring( _L, str, len );
}

void LuaState::pushUserData( void* obj, const char* type ) const
{
	tolua_pushusertype( _L, obj, type );
}

void LuaState::clean( void ) const
{
	lua_settop( _L, 0 );
}

void LuaState::handleLuaError( void ) const
{
	if( lua_type(_L, -1) == LUA_TSTRING )
	{
		const char* info  = lua_tostring( _L, -1 );
		magicalSetLastErrorInfo( info );
		magicalLogLastError();
		lua_pop(_L, -1);
	}
}