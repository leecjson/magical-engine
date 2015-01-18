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
#include "LuaFunction.h"
#include "LuaState.h"
#include "LuaObject.h"

LuaFunction::LuaFunction( void )
{

}

LuaFunction::LuaFunction( std::nullptr_t nt )
{

}

LuaFunction::LuaFunction( LuaFunction&& lf )
{
	_L = lf._L;
	_handler = lf._handler;
	_reference_count = lf._reference_count;
	
	lf._L = nullptr;
	lf._handler = 0;
	lf._reference_count = nullptr;
}

LuaFunction::LuaFunction( const LuaFunction& lf )
{
	_L = lf._L;
	_handler = lf._handler;
	_reference_count = lf._reference_count;

	++( *_reference_count );
}

LuaFunction::~LuaFunction( void )
{
	release();
}

LuaFunction& LuaFunction::operator=( LuaFunction&& lf )
{
	release();
	_L = lf._L;
	_handler = lf._handler;
	_reference_count = lf._reference_count;

	lf._handler = 0;
	lf._L = nullptr;
	lf._reference_count = nullptr;
	return *this;
}

LuaFunction& LuaFunction::operator=( const LuaFunction& lf )
{
	release();
	_L = lf._L;
	_handler = lf._handler;
	_reference_count = lf._reference_count;

	++( *_reference_count );
	return *this;
}

LuaFunction& LuaFunction::operator=( std::nullptr_t nt )
{
	release();
	return *this;
}

bool LuaFunction::operator==( std::nullptr_t nt ) const
{
	return !( _L && _handler );
}

bool LuaFunction::operator!=( std::nullptr_t nt ) const
{
	return _L && _handler;
}

void LuaFunction::bind( LuaState* L, LuaFunctionHandler handler )
{
	magicalAssert( L && handler, "invalid lua state or lua function handler" );
	release();

	_L = L;
	_L->retain();
	_handler = handler;
	_reference_count = new int( 1 );
}

void LuaFunction::release( void )
{
	if( !_reference_count )
		return;

	magicalAssert( *_reference_count > 0, "invalid lua function _reference_count." );
	--( *_reference_count );

	if( *_reference_count == 0 )
	{
		magicalAssert( _L && _handler, "invaild lua state or lua function handler" );
		tolua_ext_remove_function_by_handler( _L->cPtr(), _handler );

		_L->release();
		delete _reference_count;
	}

	_L = nullptr;
	_handler = 0;
	_reference_count = nullptr;
}

LuaObject LuaFunction::returnCall( void ) const
{
	LuaObject lobj;
	lua_State* L = _L->cPtr();
	switch( lua_type( L, -1 ) )
	{
	case LUA_TNIL:
		lobj = nullptr;
		break;
	case LUA_TBOOLEAN:
		lobj = (bool) lua_toboolean( L, -1 );
		break;
	case LUA_TNUMBER:
		lobj = (double) lua_tonumber( L, -1 );
		break;
	case LUA_TSTRING:
		lobj = lua_tostring( L, -1 );
		break;
	case LUA_TUSERDATA:
		{
			int top = lua_gettop( L );
			std::string type = tolua_typename( L, top );
			lua_pop( L, 1 );
			void* userdata = tolua_tousertype( L, top, 0 );
			lobj.set( userdata, type.c_str() );
		}
		break;
	case LUA_TFUNCTION:
		{
			LuaFunction lf;
			int handler = tolua_ext_tofunction( L, lua_gettop( L ), 0 );
			if( handler != 0 )
			{
				lf.bind( _L, handler );
			}
			lobj = lf;
		}
		break;
	case LUA_TTABLE:
		{
			LuaTable lt;
			int handler = tolua_ext_totable( L, lua_gettop( L ), 0 );
			if( handler != 0 )
			{
				lt.bind( _L, handler );
			}
			lobj = lt;
		}
		break;
	default:
		lobj = nullptr;
		break;
	}
	lua_pop( L, 1 );
	return lobj;
}