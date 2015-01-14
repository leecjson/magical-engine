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
#include "LuaSystem.h"
#include "AssetsSystem.h"

#include "lua.hpp"
#include "tolua++.h"
#include "tolua_ext.h"
#include "LuaExtensions.h"

#include "BindCommon.h"

static LuaState* _s_L = nullptr;

void Lua::init( void )
{
	_s_L = new LuaState();
	_s_L->openLibs();

	luaopen_tolua_ext( _s_L->cPtr() );
	luaopen_extensions( _s_L->cPtr() );
	luaopen_common( _s_L->cPtr() );

#ifdef MAGICAL_WIN32
	std::string standard_path = Assets::getAssetsPath() + "standard/scripts";
	_s_L->attachPath( standard_path.c_str() );
#endif
}

void Lua::delc( void )
{
	_s_L->release();
}

LuaState& Lua::sharedLuaState( void )
{
	return *_s_L;
}
