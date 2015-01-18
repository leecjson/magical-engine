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

Data::Data( void )
{

}

Data::~Data( void )
{
	magicalSafeFree( _data );
}

Shared<Data> Data::create( void )
{
	Data* ret = new Data();
	magicalAssert( ret, "new Data() failed" );
	return Shared<Data>( Initializer<Data>( ret ) );
}

void Data::assign( char* data, uint32_t size )
{
	magicalAssert( data && size > 0, "data should not be nullptr and size should > 0" );

	magicalSafeFree( _data );
	_data = data;
	_size = size;
}

void Data::malloc( uint32_t size )
{
	magicalAssert( size > 0, "size should > 0" );

	magicalSafeFree( _data );
	_data = (char*) std::malloc( size );
	magicalAssert( _data, "(char*) std::malloc( size );" );
	_size = size;
}

void Data::realloc( uint32_t size )
{
	magicalAssert( size > 0, "size should > 0" );
	magicalAssert( _data, "_data should not be nullptr." );

	if( size > _size )
	{
		_data = (char*) std::realloc( _data, size );
		magicalAssert( _data, "(char*) std::realloc( _data, size );" );
	}
	else
	{
		_size = size;
	}
}

bool Data::empty( void ) const
{
	return _data == nullptr;
}

uint32_t Data::size( void ) const
{
	return _size;
}

char* Data::ptr( void )
{
	return _data;
}