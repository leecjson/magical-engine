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
#include "LuaSelector.h"

class LuaTable;
class LuaFunction;
class LuaObject;
class LuaGlobalSelector;

enum class LuaCode
{
	OK = 0,
};

class LuaState : public Reference
{
public:
	LuaState( void );
	LuaState( LuaState&& ls ) = delete;
	LuaState( const LuaState& ls ) = delete;
	virtual ~LuaState( void );
	LuaState& operator=( LuaState&& ls ) = delete;
	LuaState& operator=( const LuaState& ls ) = delete;

public:
	void openLibs( void );
	void attachPath( const char* path );
	inline lua_State* cPtr( void ) const { return _L; }
	LuaCode runScript( const char* lscript );
	LuaCode runScriptFile( const char* lfile );
	LuaGlobalSelector& operator[]( const char* key );

public:
	void push( std::nullptr_t nil );
	void push( bool b );
	void push( int num );
	void push( float num );
	void push( double num );
	void push( const char* str );
	void push( const std::string& str );
	void push( void* userdata, const char* type, bool gc = false );
	void push( const LuaFunction& lf );
	void push( const LuaTable& lt );
	void push( const LuaObject& lobj );
	
private:
	LuaGlobalSelector _selector;
	lua_State* _L = nullptr;
};



#endif //__LUA_STATE_H__