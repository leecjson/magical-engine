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

#include "Object.h"
#include "LuaSupport.h"

class LuaState_t;

typedef std::shared_ptr<LuaState_t> LuaState;
typedef std::shared_ptr<const LuaState_t> LuaState_const;
#define newLuaState() (std::move(std::shared_ptr<LuaState_t>(new LuaState_t())))

class LuaState_t : public Object_t
{
public:
	LuaState_t( void );
	virtual ~LuaState_t( void );

	lua_State* getState( void ) const;
	int executeScriptFile( const char* file ) const;
	int executeScriptCode( const char* codes ) const;
	int executeGlobalFunction( const char* func_name, int retc = 0, int argc = 0 ) const;
	int isGlobalFunctionExists( const char* func_name ) const;

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
	lua_State* _L;
};



#endif //__LUA_STATE_H__