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
#include "LuaTable.h"
#include "LuaObject.h"
#include "LuaState.h"
#include "LuaFunction.h"

LuaTable::LuaTable( void )
{

}

LuaTable::LuaTable( std::nullptr_t nt )
{

}

LuaTable::LuaTable( LuaTable&& lt )
{
	_L = lt._L;
	_handler = lt._handler;
	_reference_count = lt._reference_count;

	lt._handler = 0;
	lt._L = nullptr;
	lt._reference_count = nullptr;
}

LuaTable::LuaTable( const LuaTable& lt )
{
	_L = lt._L;
	_handler = lt._handler;
	_reference_count = lt._reference_count;

	++( *_reference_count );
}

LuaTable::~LuaTable( void )
{
	release();
}

LuaTable& LuaTable::operator=( LuaTable&& lt )
{
	release();
	_L = lt._L;
	_handler = lt._handler;
	_reference_count = lt._reference_count;

	lt._handler = 0;
	lt._L = nullptr;
	lt._reference_count = nullptr;
	return *this;
}

LuaTable& LuaTable::operator=( const LuaTable& lt )
{
	release();
	_L = lt._L;
	_handler = lt._handler;
	_reference_count = lt._reference_count;

	++( *_reference_count );
	return *this;
}

LuaTable& LuaTable::operator=( std::nullptr_t nt )
{
	release();
	return *this;
}

bool LuaTable::operator==( std::nullptr_t nt ) const
{
	return !( _L && _handler );
}

bool LuaTable::operator!=( std::nullptr_t nt ) const
{
	return  _L && _handler;
}

LuaTableSelector& LuaTable::operator[]( const char* key )
{
	_selector.select( key, _L, _handler );
	return _selector;
}

void LuaTable::bind( LuaState* L, LuaTableHandler handler )
{
	magicalAssert( L && handler, "invalid lua state or lua table handler" );
	release();

	_L = L;
	_L->retain();
	_handler = handler;
	_reference_count = new int( 1 );
}

void LuaTable::release( void )
{
	if( !_reference_count )
		return;

	magicalAssert( *_reference_count > 0, "invalid lua table _reference_count." );
	--( *_reference_count );

	if( *_reference_count == 0 )
	{
		magicalAssert( _L && _handler, "invaild lua state or lua table handler" );
		tolua_ext_remove_table_by_handler( _L->cPtr(), _handler );

		_L->release();
		delete _reference_count;
	}

	_L = nullptr;
	_handler = 0;
	_reference_count = nullptr;
}