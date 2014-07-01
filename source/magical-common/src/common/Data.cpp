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
#include "Data.h"
#include "Common.h"

Data_t::Data_t( void )
: _data(nullptr)
, _size(0)
{

}

Data_t::~Data_t( void )
{
	if( _data )
	{
		magicalFree( _data );
		_data = nullptr;
	}
}

void Data_t::assign( char* data, const tsize size )
{
	magicalAssert( data && size > 0, "data should not nullptr and size should > 0" );

	if( _data )
	{
		magicalFree( _data );
	}
	_data = data;
	_size = size;
}

void Data_t::malloc( const tsize size )
{
	magicalAssert( size > 0, "size should > 0" );

	if( _data )
	{
		magicalFree( _data );
	}
	_data = (char*) ::malloc( size );
	magicalAssert( _data, "(char*)::malloc( size );" );
	_size = size;
}

void Data_t::realloc( const tsize size )
{
	magicalAssert( size > 0, "size should > 0" );
	magicalAssert( _data, "_data should not nullptr" );

	_data = (char*) ::realloc( _data, size );
	magicalAssert( _data, "(char*) ::realloc( _data, size );" );
}

char* Data_t::data( void ) const
{
	return _data;
}

bool Data_t::empty( void ) const
{
	return _data == nullptr;
}