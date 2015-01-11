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
#include "tolua_ext.h"

#include <stdlib.h>
#include <string.h>

static int _s_growing_function_id = 0;
static int _s_growing_table_id = 0;

TOLUA_API void luaopen_tolua_ext( lua_State* L )
{
	lua_pushstring( L, TOLUA_MAPPING_FUNCTION_KEY );
	lua_createtable( L, 255, 0 );
	lua_rawset( L, LUA_REGISTRYINDEX );

	lua_pushstring( L, TOLUA_MAPPING_TABLE_KEY );
	lua_createtable( L, 255, 0 );
	lua_rawset( L, LUA_REGISTRYINDEX );
}

TOLUA_API int tolua_ext_istable( lua_State* L, int lo, const char* type, int def, tolua_Error* err )
{
	if( lua_gettop( L ) >= abs( lo ) && lua_istable( L, lo ) )
		return 1;

	err->index = lo;
	err->array = 0;
	err->type = "[not table]";
	return 0;
}

TOLUA_API int tolua_ext_totable( lua_State* L, int lo, int def )
{
	if( !lua_istable( L, lo ) )
		return 0;

	++ _s_growing_table_id;

	lua_pushstring( L, TOLUA_MAPPING_TABLE_KEY );
	lua_rawget( L, LUA_REGISTRYINDEX );
	lua_pushinteger( L, _s_growing_table_id );
	lua_pushvalue( L, lo );
	lua_rawset( L, -3 );
	lua_pop( L, 1 );
	return _s_growing_table_id;
}

TOLUA_API int tolua_ext_isfunction( lua_State* L, int lo, const char* type, int def, tolua_Error* err )
{
	if( lua_gettop( L ) >= abs( lo ) && lua_isfunction( L, lo ) )
		return 1;

	err->index = lo;
	err->array = 0;
	err->type = "[not function]";
	return 0;
}

TOLUA_API int tolua_ext_tofunction( lua_State* L, int lo, int def )
{
	if( !lua_isfunction( L, lo ) )
		return 0;
    
	++ _s_growing_function_id;
    
	lua_pushstring( L, TOLUA_MAPPING_FUNCTION_KEY );
	lua_rawget( L, LUA_REGISTRYINDEX );
	lua_pushinteger( L, _s_growing_function_id );
	lua_pushvalue( L, lo );
	lua_rawset( L, -3 );
	lua_pop( L, 1 );
	return _s_growing_function_id;
}

TOLUA_API void tolua_ext_get_table_by_id( lua_State* L, int refid )
{
	lua_pushstring( L, TOLUA_MAPPING_TABLE_KEY );
	lua_rawget( L, LUA_REGISTRYINDEX );
	lua_pushinteger( L, refid );
	lua_rawget( L, -2 );
	lua_remove( L, -2 );
}

TOLUA_API void tolua_ext_remove_table_by_id( lua_State* L, int refid )
{
	lua_pushstring( L, TOLUA_MAPPING_TABLE_KEY );
	lua_rawget( L, LUA_REGISTRYINDEX );
	lua_pushinteger( L, refid );
	lua_pushnil( L );
	lua_rawset( L, -3 );
	lua_pop( L, 1 );
}

TOLUA_API void tolua_ext_get_function_by_id( lua_State* L, int refid )
{
	lua_pushstring( L, TOLUA_MAPPING_FUNCTION_KEY );
	lua_rawget( L, LUA_REGISTRYINDEX );
	lua_pushinteger( L, refid );
	lua_rawget( L, -2 );
	lua_remove( L, -2 );
}

TOLUA_API void tolua_ext_remove_function_by_id( lua_State* L, int refid )
{
	lua_pushstring( L, TOLUA_MAPPING_FUNCTION_KEY );
	lua_rawget( L, LUA_REGISTRYINDEX );
	lua_pushinteger( L, refid );
	lua_pushnil( L );
	lua_rawset( L, -3 );
	lua_pop( L, 1 );
}
