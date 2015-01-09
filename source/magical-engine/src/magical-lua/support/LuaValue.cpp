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
#include "LuaValue.h"

enum 
{
	kNone = 0,
	kGlobal = 1,
	kTable = 2,
};

LuaValue::LuaValue( void )
//: _scope( kNone )
{
	
}

LuaValue::~LuaValue( void )
{
	//magicalSafeRelease( _cpp_L );
}

//void LuaValue::push( void )
//{
//	magicalAssert( _names.size() > 0 && _in_stack == false, "invaild operate!" );
//	magicalAssert( _in_stack_num == 0, "push and pop operation has some issus!" );
//
//	size_t size = _names.size();
//	if( size == 1 )
//	{
//		lua_getglobal( _L, _names[0].c_str() );
//		magicalAssert( lua_type( _L, -1 ) == LUA_TTABLE, "invaild operate!" );
//		++_in_stack_num;
//	}
//	else
//	{
//		lua_getglobal( _L, _names[0].c_str() );
//		magicalAssert( lua_type( _L, -1 ) == LUA_TTABLE, "invaild operate!" );
//		++_in_stack_num;
//
//		for( size_t i = 0; i < size; ++i )
//		{
//			lua_getfield( _L, -1, name.c_str() );
//			magicalAssert( lua_type( _L, -1 ) == LUA_TTABLE, "invaild operate!" );
//			++_in_stack_num;
//		}
//		_in_stack = true;
//	}
//
//	
//
//	
//}
//
//void LuaValue::pop( void )
//{
//
//}
//
//bool LuaValue::isNumber( void ) const
//{
//	if( _in_stack )
//	{
//		return lua_isnumber( _L->cPointer() , -1 );
//	}
//	else
//	{
//		
//	}
//
//	magicalAssert( _type != LUA_TNONE, "invaild operate!" );
//	return _type == LUA_TNUMBER;
//}
//
//bool LuaValue::isString( void ) const
//{
//	magicalAssert( _type != LUA_TNONE, "invaild operate!" );
//	return _type == LUA_TSTRING;
//}
//
//bool LuaValue::isUserData( void ) const
//{
//	magicalAssert( _type != LUA_TNONE, "invaild operate!" );
//	return _type == LUA_TUSERDATA;
//}
//
//bool LuaValue::isTable( void ) const
//{
//	magicalAssert( _type != LUA_TNONE, "invaild operate!" );
//	return _type == LUA_TTABLE;
//}
//
//bool LuaValue::isFunction( void ) const
//{
//	magicalAssert( _type != LUA_TNONE, "invaild operate!" );
//	return _type == LUA_TFUNCTION;
//}