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
#ifndef __LUA_SELECTOR_H__
#define __LUA_SELECTOR_H__

#include "PlatformMacros.h"
#include "Common.h"
#include "LuaMacros.h"

class LuaState;
class LuaTable;
class LuaFunction;
class LuaObject;

class LuaGlobalSelector
{
public:
	LuaGlobalSelector( void );
	LuaGlobalSelector( const LuaGlobalSelector& ls ) = delete;
	LuaGlobalSelector( LuaGlobalSelector&& ls ) = delete;
	~LuaGlobalSelector( void );
	LuaGlobalSelector& operator=( const LuaGlobalSelector& ls ) = delete;
	LuaGlobalSelector& operator=( LuaGlobalSelector&& ls ) = delete;

public:
	bool isNil( void ) const;
	bool isNumber( void ) const;
	bool isString( void ) const;
	bool isUserData( void ) const;
	bool isTable( void ) const;
	bool isFunction( void ) const;
	bool operator==( LuaT t ) const;

public:
	int toInt( void ) const;
	float toFloat( void ) const;
	double toDouble( void ) const;
	std::string toString( void ) const;
	void* toUserData( void ) const;
	LuaFunction toLuaFunction( void ) const;
	LuaTable toLuaTable( void ) const;
	LuaObject toLuaObject( void ) const;

public:
	void operator=( int num );
	void operator=( float num );
	void operator=( double num );
	void operator=( const char* str );
	void operator=( const std::string& str );
	void operator=( std::nullptr_t nil );
	void operator=( const LuaTable& lt );
	void operator=( const LuaFunction& lf );
	void operator=( const LuaObject& lobj );
	void set( void* userdata, const char* type, bool gc = false );

private:
	void select( const char* key );

private:
	friend class LuaState;
	std::string _key;
	LuaState* _L = nullptr;
};

class LuaTableSelector
{
public:
	LuaTableSelector( void );
	LuaTableSelector( const LuaTableSelector& ls ) = delete;
	LuaTableSelector( LuaTableSelector&& ls ) = delete;
	~LuaTableSelector( void );
	LuaTableSelector& operator=( const LuaTableSelector& ls ) = delete;
	LuaTableSelector& operator=( LuaTableSelector&& ls ) = delete;

public:
	bool isNil( void ) const;
	bool isNumber( void ) const;
	bool isString( void ) const;
	bool isUserData( void ) const;
	bool isTable( void ) const;
	bool isFunction( void ) const;
	bool operator==( LuaT t ) const;

public:
	int toInt( void ) const;
	float toFloat( void ) const;
	double toDouble( void ) const;
	std::string toString( void ) const;
	void* toUserData( void ) const;
	LuaFunction toLuaFunction( void ) const;
	LuaTable toLuaTable( void ) const;
	LuaObject toLuaObject( void ) const;

public:
	void operator=( int num );
	void operator=( float num );
	void operator=( double num );
	void operator=( const char* str );
	void operator=( const std::string& str );
	void operator=( std::nullptr_t nil );
	void operator=( const LuaTable& lt );
	void operator=( const LuaFunction& lf );
	void operator=( const LuaObject& lobj );
	void set( void* userdata, const char* type, bool gc = false );

private:
	void select( const char* key, LuaState* L, LuaTableHandler handler );

private:
	friend class LuaTable;
	std::string _key;
	LuaState* _L = nullptr;
	LuaTableHandler _handler = 0;
};

#endif //__LUA_SELECTOR_H__