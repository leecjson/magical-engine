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
#include "LuaMacros.h"
#include "tolua++.h"
#include "tolua_ext.h"
#include "LogSystem.h"

#ifdef MAGICAL_DEBUG

void magicalLuaStateDump( lua_State* L )
{
	int i = 0;
	int top = lua_gettop( L );

	magicalFormat( "Total [%d] in lua stack: ", top );
	magicalLog( magicalBuffer );

	for( i = -1; i >= -top; i-- )
	{
		int t = lua_type( L, i );
		switch( t )
		{
		case LUA_TNIL:
			magicalFormat( "[%02d] nil", i );
			break;
		case LUA_TSTRING:
			magicalFormat( "[%02d] string %s", i, lua_tostring( L, i ) );
			break;
		case LUA_TBOOLEAN:
			magicalFormat( "[%02d] boolean %s", i, lua_toboolean( L, i ) ? "true" : "false" );
			break;
		case LUA_TNUMBER:
			magicalFormat( "[%02d] number %g", i, lua_tonumber( L, i ) );
			break;
		default:
			magicalFormat( "[%02d] %s", i, lua_typename( L, t ) );
		}
		magicalLog( magicalBuffer );
	}

	magicalLog( "-----------------------" );
}

#endif

void magicalHandleLuaError( lua_State* L )
{
	if( lua_type( L, -1 ) == LUA_TSTRING )
	{
		const char* info = lua_tostring( L, -1 );
		magicalSetLastErrorInfo( info );
		magicalLogLastError();
		lua_pop( L, -1 );
	}
}