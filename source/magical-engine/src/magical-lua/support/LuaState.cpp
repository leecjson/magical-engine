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
