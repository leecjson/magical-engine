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