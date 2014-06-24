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
#include "PlatformMacros.h"
#include "LuaSupport.h"
#include "Common.h"
#include "LuaState.h"

const char* const kLuaMain = "main.lua";
const char* const kLuaOnFinishLaunching = "onFinishLaunching";
const char* const kLuaOnCreate = "onCreate";
const char* const kLuaOnUpdate = "onUpdate";
const char* const kLuaOnDestroy = "onDestroy";

MAGAPI_USER void magicalLuaPrintError( lua_State* L )
{
	if( lua_type(L, -1) == LUA_TSTRING )
	{
		char  buff[kMaxErrLength];
		const char* info  = lua_tostring(L, -1);
		const char* title = magicalTagError("%s");
		sprintf(buff, title, info);

		magicalSetLastErrorInfo(buff);
		magicalReportLastError();
		lua_pop(L, -1);
	}
}

MAGAPI_USER void magicalLuaStateDump( lua_State* L, const char* tag )
{
	int  i = 0;
	int  top = lua_gettop(L);
	char buf[kMaxErrLength];
	std::string str_buffer;

	sprintf(buf, "Total [%d] in lua stack: %s\n", top, tag ? tag : "");
	str_buffer += buf;

	for( i = -1; i >= -top; i-- )
	{
		int t = lua_type(L, i);
		switch( t )
		{
		case LUA_TSTRING:
			sprintf(buf, "  [%02d] string %s\n", i, lua_tostring(L, i));
			break;
		case LUA_TBOOLEAN:
			sprintf(buf, "  [%02d] boolean %s\n", i, lua_toboolean(L, i) ? "true" : "false");
			break;
		case LUA_TNUMBER:
			sprintf(buf, "  [%02d] number %g\n", i, lua_tonumber(L, i));
			break;
		default:
			sprintf(buf, "  [%02d] %s\n", i, lua_typename(L, t));
		}
		str_buffer += buf;
	}

	str_buffer += "\n";
	magicalReport( str_buffer.c_str() );
}