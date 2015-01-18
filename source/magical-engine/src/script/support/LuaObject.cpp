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
#include "LuaObject.h"
#include "LuaState.h"

LuaObject::LuaObject( void )
{
	
}

LuaObject::LuaObject( LuaObject&& lobj )
{
	switch( lobj._type )
	{
	case LuaT::Nil:
		_type = LuaT::Nil;
		break;
	case LuaT::Boolean:
		_type = LuaT::Boolean;
		_boolean = lobj._boolean;
		lobj._type = LuaT::Nil;
		lobj._boolean = false;
		break;
	case LuaT::Number:
		_type = LuaT::Number;
		_number = lobj._number;
		lobj._type = LuaT::Nil;
		lobj._number = 0.0;
		break;
	case LuaT::String:
		_type = LuaT::String;
		_string = lobj._string;
		lobj._type = LuaT::Nil;
		lobj._string.clear();
		break;
	case LuaT::UserData:
		_type = LuaT::UserData;
		_userdata = lobj._userdata;
		_usertype = lobj._usertype;
		_is_gc = lobj._is_gc;
		lobj._type = LuaT::Nil;
		lobj._userdata = nullptr;
		lobj._usertype.clear();
		lobj._is_gc = false;
		break;
	case LuaT::Function:
		_type = LuaT::Function;
		_function = std::move( lobj._function );
		lobj._type = LuaT::Nil;
		lobj._function = nullptr;
		break;
	case LuaT::Table:
		_type = LuaT::Table;
		_table = std::move( lobj._table );
		lobj._type = LuaT::Nil;
		lobj._table = nullptr;
		break;
	default:
		_type = LuaT::Nil;
		break;
	}
}

LuaObject::LuaObject( const LuaObject& lobj )
{
	switch( lobj._type )
	{
	case LuaT::Nil:
		_type = LuaT::Nil;
		break;
	case LuaT::Boolean:
		_type = LuaT::Boolean;
		_boolean = lobj._boolean;
		break;
	case LuaT::Number:
		_type = LuaT::Number;
		_number = lobj._number;
		break;
	case LuaT::String:
		_type = LuaT::String;
		_string = lobj._string;
		break;
	case LuaT::UserData:
		_type = LuaT::UserData;
		_userdata = lobj._userdata;
		_usertype = lobj._usertype;
		_is_gc = lobj._is_gc;
		break;
	case LuaT::Function:
		_type = LuaT::Function;
		_function = lobj._function;
		break;
	case LuaT::Table:
		_type = LuaT::Table;
		_table = lobj._table;
		break;
	default:
		_type = LuaT::Nil;
		break;
	}
}

LuaObject::~LuaObject( void )
{
	
}

LuaObject::LuaObject( std::nullptr_t nt )
{

}

LuaObject::LuaObject( bool b )
{
	_boolean = b;
	_type = LuaT::Boolean;
}

LuaObject::LuaObject( int number )
{
	_number = (double) number;
	_type = LuaT::Number;
}

LuaObject::LuaObject( float number )
{
	_number = (double) number;
	_type = LuaT::Number;
}

LuaObject::LuaObject( double number )
{
	_number = number;
	_type = LuaT::Number;
}

LuaObject::LuaObject( const char* str )
{
	_string = str;
	_type = LuaT::String;
}

LuaObject::LuaObject( const std::string& str )
{
	_string = str;
	_type = LuaT::String;
}

LuaObject::LuaObject( void* userdata, const char* type )
{
	magicalAssert( userdata, "userdata should not be nullptr" );
	magicalAssert( type && strlen( type ) > 0, "userdata type string should not be empty" );
	_userdata = userdata;
	_usertype = type;
	_type = LuaT::UserData;
}

LuaObject::LuaObject( LuaFunction&& lf )
{
	_function = std::forward<LuaFunction>( lf );
	_type = LuaT::Function;
}

LuaObject::LuaObject( const LuaFunction& lf )
{
	_function = lf;
	_type = LuaT::Function;
}

LuaObject::LuaObject( LuaTable&& lt )
{
	_table = std::forward<LuaTable>( lt );
	_type = LuaT::Table;
}

LuaObject::LuaObject( const LuaTable& lt )
{
	_table = lt;
	_type = LuaT::Table;
}

bool LuaObject::operator==( std::nullptr_t nt ) const
{
	return _type == LuaT::Nil;
}

bool LuaObject::operator==( LuaT t ) const
{
	return _type == t;
}

bool LuaObject::operator!=( std::nullptr_t nt ) const
{
	return _type != LuaT::Nil;
}

bool LuaObject::operator!=( LuaT t ) const
{
	return _type != t;
}

LuaObject& LuaObject::operator=( LuaObject&& lobj )
{
	switch( lobj._type )
	{
	case LuaT::Nil:
		_type = LuaT::Nil;
		break;
	case LuaT::Boolean:
		_type = LuaT::Boolean;
		_boolean = lobj._boolean;
		lobj._type = LuaT::Nil;
		lobj._boolean = false;
		break;
	case LuaT::Number:
		_type = LuaT::Number;
		_number = lobj._number;
		lobj._type = LuaT::Nil;
		lobj._number = 0.0;
		break;
	case LuaT::String:
		_type = LuaT::String;
		_string = lobj._string;
		lobj._type = LuaT::Nil;
		lobj._string.clear();
		break;
	case LuaT::UserData:
		_type = LuaT::UserData;
		_userdata = lobj._userdata;
		_usertype = lobj._usertype;
		lobj._type = LuaT::Nil;
		lobj._userdata = nullptr;
		lobj._usertype.clear();
		break;
	case LuaT::Function:
		_type = LuaT::Function;
		_function = std::move( lobj._function );
		lobj._type = LuaT::Nil;
		lobj._function = nullptr;
		break;
	case LuaT::Table:
		_type = LuaT::Table;
		_table = std::move( lobj._table );
		lobj._type = LuaT::Nil;
		lobj._table = nullptr;
		break;
	default:
		_type = LuaT::Nil;
		break;
	}
	return *this;
}

LuaObject& LuaObject::operator=( const LuaObject& lobj )
{
	switch( lobj._type )
	{
	case LuaT::Nil:
		_type = LuaT::Nil;
		break;
	case LuaT::Boolean:
		_type = LuaT::Boolean;
		_boolean = lobj._boolean;
		break;
	case LuaT::Number:
		_type = LuaT::Number;
		_number = lobj._number;
		break;
	case LuaT::String:
		_type = LuaT::String;
		_string = lobj._string;
		break;
	case LuaT::UserData:
		_type = LuaT::UserData;
		_userdata = lobj._userdata;
		_usertype = lobj._usertype;
		break;
	case LuaT::Function:
		_type = LuaT::Function;
		_function = lobj._function;
		break;
	case LuaT::Table:
		_type = LuaT::Table;
		_table = lobj._table;
		break;
	default:
		_type = LuaT::Nil;
		break;
	}
	return *this;
}

//void LuaObject::clean( void )
//{
//	if( _type != LuaT::Function )
//		_function.release();
//
//	if( _type != LuaT::Table )
//		_table.release();
//}

LuaObject& LuaObject::operator=( std::nullptr_t nt )
{
	_type = LuaT::Nil;
	return *this;
}

LuaObject& LuaObject::operator=( bool b )
{
	_boolean = b;
	_type = LuaT::Boolean;
	return *this;
}

LuaObject& LuaObject::operator=( int number )
{
	_number = (double) number;
	_type = LuaT::Number;
	return *this;
}

LuaObject& LuaObject::operator=( float number )
{
	_number = (double) number;
	_type = LuaT::Number;
	return *this;
}

LuaObject& LuaObject::operator=( double number )
{
	_number = number;
	_type = LuaT::Number;
	return *this;
}

LuaObject& LuaObject::operator=( const char* str )
{
	_string = str;
	_type = LuaT::String;
	return *this;
}

LuaObject& LuaObject::operator=( const std::string& str )
{
	_string = str;
	_type = LuaT::String;
	return *this;
}

LuaObject& LuaObject::operator=( LuaFunction&& lf )
{
	_function = std::forward<LuaFunction>( lf );
	_type = LuaT::Function;
	return *this;
}

LuaObject& LuaObject::operator=( const LuaFunction& lf )
{
	_function = lf;
	_type = LuaT::Function;
	return *this;
}

LuaObject& LuaObject::operator=( LuaTable&& lt )
{
	_table = std::forward<LuaTable>( lt );
	_type = LuaT::Table;
	return *this;
}

LuaObject& LuaObject::operator=( const LuaTable& lt )
{
	_table = lt;
	_type = LuaT::Table;
	return *this;
}

void LuaObject::set( void* userdata, const char* type )
{
	magicalAssert( userdata, "userdata should not be nullptr" );
	magicalAssert( type && strlen( type ) > 0, "userdata type string should not be empty" );
	_userdata = userdata;
	_usertype = type;
	_type = LuaT::UserData;
}

LuaObject& LuaObject::toGcObject( void )
{
	_is_gc = true;
	return *this;
}

bool LuaObject::toBoolean( void ) const
{
	return _type == LuaT::Boolean ? _boolean : false;
}

int LuaObject::toInt( void ) const
{
	return _type == LuaT::Number ? (int) _number : 0.0;
}

float LuaObject::toFloat( void ) const
{
	return _type == LuaT::Number ? (float) _number : 0.0;
}

double LuaObject::toDouble( void ) const
{
	return _type == LuaT::Number ? _number : 0.0;
}

std::string LuaObject::toString( void ) const
{
	return _type == LuaT::String ? _string : "";
}

void* LuaObject::toUserData( void ) const
{
	return _type == LuaT::UserData ? _userdata : nullptr;
}

LuaFunction LuaObject::toLuaFunction( void ) const
{
	return _type == LuaT::Function ? _function : nullptr;
}

LuaTable LuaObject::toLuaTable( void ) const
{
	return _type == LuaT::Table ? _table : nullptr;
}

const char* LuaObject::userdataType( void ) const
{
	return _type == LuaT::UserData ? _usertype.c_str() : nullptr;
}