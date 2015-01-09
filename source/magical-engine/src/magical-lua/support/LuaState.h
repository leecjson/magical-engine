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
#include "LuaTable.h"
#include "LuaFunction.h"
#include "LuaValue.h"

class LuaValue;

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
	void operator=( LuaState&& ls ) = delete;
	void operator=( const LuaState& ls ) = delete;
	virtual ~LuaState( void );
	static Shared<LuaState> create( void );

public:
	void openLibs( void );
	void attachPath( const char* path );
	lua_State* cPointer( void ) const;
	LuaCode runScript( const char* script );
	LuaCode runScriptFile( const char* file );

public:
	LuaState& back( void );
	LuaState& back( int count );
	void clean( void );
	LuaState& operator<<( int count );
	LuaState& operator--( void );
	LuaState& enter( const char* name );
	LuaState& operator>>( const char* name );
	LuaState& operator[]( const char* name );
	LuaState& operator[]( size_t i );

public:
	bool isNumber( void ) const;
	bool isString( void ) const;
	bool isUserData( void ) const;
	bool isTable( void ) const;
	bool isFunction( void ) const;

public:
	LuaState& operator=( int n );
	LuaState& operator=( float n );
	LuaState& operator=( double n );
	LuaState& operator=( bool b );
	LuaState& operator=( const char* str );
	LuaState& set( int n );
	LuaState& set( float n );
	LuaState& set( double n );
	LuaState& set( bool b );
	LuaState& set( const char* str );
	LuaState& set( void* userdata, const char* type, bool gc = false );
	int toInt( void ) const;
	float toFloat( void ) const;
	double toDouble( void ) const;
	const char* toString( void ) const;
	void* toUserData( void ) const;

public:
	template< typename... Args >
	LuaState& operator()( const Args&... args )
	{
		magicalAssert( _lso.model & LuaStateOperation::ReadyKey, "invaild operate!" );
		int nresults = 0;
		if( _lso.model & LuaStateOperation::ReadyArg1 && _lso.arg1 > 0 )
		{
			nresults = _lso.arg1;
			_lso.model = LuaStateOperation::Invoking;
		}
		else
		{
			_lso.model = LuaStateOperation::None;
		}

		int idx = LUA_GLOBALSINDEX;
		if( _is_global == false ) idx = -1;

		lua_getfield( _L, idx, _lso.key.c_str() );
		pushArgs( args... );
		int ret = lua_pcall( _L, sizeof...( args ), nresults, 0 );
		magicalAssert( ret == 0, lua_tostring( _L, -1 ) );
		return *this;
	}

	void operator()( void );
	int returnInt( void ) const;
	float returnFloat( void ) const;
	double returnDouble( void ) const;
	const char* returnString( void ) const;
	void* returnUserData( void ) const;
	void ignore( void ) const;
	void ignoreAll( void ) const;
	
private:
	void push( std::nullptr_t nil );
	void push( int n );
	void push( float n );
	void push( double n );
	void push( bool b );
	void push( const char* str );

	template< typename T >
	inline void pushArgs( const T& var )
	{
		push( var );
	}

	template< typename T, typename... Args >
	inline void pushArgs( const T& var, const Args&... args )
	{
		push( var );
		pushArgs( args... );
	}

private:
	struct LuaStateOperation
	{
		enum {
			None = 0x0,
			ReadyKey = 0x1,
			ReadyArg1 = 0x2,
			ReadyArg2 = 0x4,
			Invoking = 0x8,
		};
		int arg1 = 0;
		int arg2 = 0;
		int model = None;
		std::string key;
	};

	enum LuaStateOpScope
	{
		Global = 0,
		Table = 1,
	};
	
private:
	bool _is_global = true;
	mutable LuaStateOperation _lso;
	lua_State* _L = nullptr;
};



#endif //__LUA_STATE_H__