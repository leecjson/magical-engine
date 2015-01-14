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
#ifndef __LUA_FUNCTION_H__
#define __LUA_FUNCTION_H__

#include "PlatformMacros.h"
#include "Common.h"

#include "LuaMacros.h"
//#include "LuaObject.h"

class LuaState;
class LuaObject;

class LuaFunction
{
public:
	LuaFunction( void );
	LuaFunction( std::nullptr_t nt );
	LuaFunction( LuaFunction&& lf );
	LuaFunction( const LuaFunction& lf );
	~LuaFunction( void );

public:
	LuaFunction& operator=( LuaFunction&& lf );
	LuaFunction& operator=( const LuaFunction& lf );
	LuaFunction& operator=( std::nullptr_t nt );
	bool operator==( std::nullptr_t nt ) const;
	bool operator!=( std::nullptr_t nt ) const;
	void bind( LuaState* L, LuaFunctionHandler handler );
	void release( void );

public:
	template< typename... Args >
	auto operator()( const Args&... args ) const -> decltype( returnCall() )
	{
		if( !_L || !_handler ) 
			return nullptr;

		lua_State* L = _L->cPtr();
		tolua_ext_get_function_by_handler( L, _handler );
		pushArgs( args... );

		int ret = lua_pcall( L, sizeof...( args ), 1, 0 );
		if( ret == 0 )
			return returnCall();

		magicalSetLastErrorInfoB( lua_tostring( L, -1 ) );
		magicalLogLastError();
		lua_pop( L, 1 );
		return nullptr;
	}

private:
	inline void pushArgs( void ) const { };
	template< typename T >
	void pushArgs( const T& t ) const { _L->push( t ); }
	template< typename T, typename... Args >
	void pushArgs( const T& t, const Args&... args ) const { _L->push( t ); pushArgs( args... ); }
	LuaObject returnCall( void ) const;

private:
	friend class LuaState;
	LuaState* _L = nullptr;
	LuaFunctionHandler _handler = 0;
	int* _reference_count = nullptr;
};

#endif //__LUA_FUNCTION_H__