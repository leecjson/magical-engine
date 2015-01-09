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
#ifndef __LUA_VALUE_H__
#define __LUA_VALUE_H__

#include "PlatformMacros.h"
#include "Common.h"
#include "LuaMacros.h"
#include "LuaState.h"
#include "Array.h"

class LuaState;

class LuaValue
{
public:
	friend class LuaState;

public:
	LuaValue( void );
	~LuaValue( void );

//public:
//	void push( void );
//	void pop( void );
//
//public:
//	bool isNumber( void ) const;
//	bool isString( void ) const;
//	bool isUserData( void ) const;
//	bool isTable( void ) const;
//	bool isFunction( void ) const;
//
//public:
//	void operator=( int n );
//	void operator=( float n );
//	void operator=( double n );
//	void operator=( bool b );
//	void operator=( const char* str );
//	void operator=( const std::string& str );
//
//	int toInt( void );
//	float toFloat( void );
//	double toDouble( void );
//	const char* toString( void );
//	void* toUserData( void );
//
//	void operator()( ... );

private:
	/*int _scope;
	std::vector<std::string> _names;
	bool _in_stack = false;
	int _in_stack_num = 0;
	LuaState* _cpp_L = nullptr;
	lua_State* _L = nullptr;*/

	lua_State* _L = nullptr;
};

#endif //__LUA_VALUE_H__