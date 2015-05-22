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
#ifndef __TOLUA_EXT_H__
#define __TOLUA_EXT_H__

#include "tolua++.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TOLUA_MAPPING_TABLE_KEY "MAPPINGTABLE"
#define TOLUA_MAPPING_FUNCTION_KEY "MAPPINGFUNCTION"

typedef int LuaTableHandler;
typedef int LuaFunctionHandler;

TOLUA_API void luaopen_tolua_ext( lua_State* L );

TOLUA_API int tolua_ext_istable( lua_State* L, int lo, const char* type, int def, tolua_Error* err );
TOLUA_API int tolua_ext_totable( lua_State* L, int lo, int def );
TOLUA_API int tolua_ext_isfunction( lua_State* L, int lo, const char* type, int def, tolua_Error* err );
TOLUA_API int tolua_ext_tofunction( lua_State* L, int lo, int def );

TOLUA_API void tolua_ext_get_table_by_handler( lua_State* L, LuaTableHandler handler );
TOLUA_API void tolua_ext_remove_table_by_handler( lua_State* L, LuaTableHandler handler );
TOLUA_API void tolua_ext_get_function_by_handler( lua_State* L, LuaFunctionHandler handler );
TOLUA_API void tolua_ext_remove_function_by_handler( lua_State* L, LuaFunctionHandler handler );

#ifdef __cplusplus
}
#endif

#endif //__TOLUA_EXT_H__