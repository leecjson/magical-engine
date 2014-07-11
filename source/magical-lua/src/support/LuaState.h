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
#ifndef __LUA_STATE_H__
#define __LUA_STATE_H__

#include "PlatformMacros.h"
#include "Common.h"
#include "Reference.h"
#include "LuaMacros.h"

class LuaState : public Reference
{
public:
	LuaState( void );
	virtual ~LuaState( void );

public:
	static Shared<LuaState> createShared( void );
	static LuaState* create( void );

public:
	lua_State* ptr( void ) const;
	int executeScriptFile( const char* file ) const;
	int executeScriptCode( const char* codes ) const;
	int executeGlobalFunction( const char* func_name, int retc = 0, int argc = 0 ) const;
	int isGlobalFunctionExist( const char* func_name ) const;

	void pushNil( void ) const;
	void pushInt( int num ) const;
	void pushFloat( float num ) const;
	void pushBoolean( bool con ) const;
	void pushString( const char* str ) const;
	void pushString( const char* str, int len ) const;
	void pushUserData( void* obj, const char* type ) const;
	void clean( void ) const;

private:
	void handleLuaError( void ) const;

private:
	lua_State* _L = nullptr;
};



#endif //__LUA_STATE_H__