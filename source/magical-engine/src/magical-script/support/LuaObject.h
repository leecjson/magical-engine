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
#ifndef __LUA_OBJECT_H__
#define __LUA_OBJECT_H__

#include "PlatformMacros.h"
#include "Common.h"
#include "Reference.h"

#include "LuaMacros.h"
#include "LuaTable.h"
#include "LuaFunction.h"

class LuaState;
class LuaTable;
class LuaFunction;

class LuaObject
{
public:
	LuaObject( void );
	LuaObject( LuaObject&& lobj );
	LuaObject( const LuaObject& lobj );
	~LuaObject( void );

public:
	LuaObject( std::nullptr_t nt );
	LuaObject( bool b );
	LuaObject( int number );
	LuaObject( float number );
	LuaObject( double number );
	LuaObject( const char* str );
	LuaObject( const std::string& str );
	LuaObject( LuaFunction&& lf );
	LuaObject( const LuaFunction& lf );
	LuaObject( LuaTable&& lt );
	LuaObject( const LuaTable& lt );
	LuaObject( void* userdata, const char* type );

public:
	bool operator==( std::nullptr_t nt ) const;
	bool operator==( LuaT t ) const;
	bool operator!=( std::nullptr_t nt ) const;
	bool operator!=( LuaT t ) const;
	LuaObject& operator=( LuaObject&& lobj );
	LuaObject& operator=( const LuaObject& lobj );
	//void clean( void );
	
public:
	LuaObject& operator=( std::nullptr_t nt );
	LuaObject& operator=( bool b );
	LuaObject& operator=( int number );
	LuaObject& operator=( float number );
	LuaObject& operator=( double number );
	LuaObject& operator=( const char* str );
	LuaObject& operator=( const std::string& str );
	LuaObject& operator=( LuaFunction&& lf );
	LuaObject& operator=( const LuaFunction& lf );
	LuaObject& operator=( LuaTable&& lt );
	LuaObject& operator=( const LuaTable& lt );
	void set( void* userdata, const char* type );
	LuaObject& toGcObject( void );
	
public:
	bool toBoolean( void ) const;
	int toInt( void ) const;
	float toFloat( void ) const;
	double toDouble( void ) const;
	std::string toString( void ) const;
	void* toUserData( void ) const;
	LuaFunction toLuaFunction( void ) const;
	LuaTable toLuaTable( void ) const;
	const char* userdataType( void ) const;

private:
	friend class LuaState;
	friend class LuaFunction;
	friend class LuaGlobalSelector;
	friend class LuaTableSelector;
	LuaT _type = LuaT::Nil;
	std::string _string;
	bool _boolean = false;
	double _number = 0.0;
	void* _userdata = nullptr;
	std::string _usertype;
	bool _is_gc = false;
	LuaFunction _function;
	LuaTable _table;
};

#endif //__LUA_OBJECT_H__