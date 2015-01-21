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

NS_MAGICAL_BEGIN

Data::Data( void )
{

}

Data::~Data( void )
{
	magicalSafeFree( _data );
}

Ptr<Data> Data::create( void )
{
	Data* ret = new Data();
	magicalAssert( ret, "new Data() failed" );
	return Ptr<Data>( Initializer<Data>( ret ) );
}

Ptr<Data> Data::create( size_t size )
{
	Data* ret = new Data();
	magicalAssert( ret, "new Data() failed" );
	ret->malloc( size );
	return Ptr<Data>( Initializer<Data>( ret ) );
}

Ptr<Data> Data::create( char* data, size_t size )
{
	Data* ret = new Data();
	magicalAssert( ret, "new Data() failed" );
	ret->assign( data, size );
	return Ptr<Data>( Initializer<Data>( ret ) );
}

void Data::assign( char* data, size_t size )
{
	magicalAssert( data && size > 0, "data should not be nullptr and size should > 0" );

	magicalSafeFree( _data );
	_data = data;
	_size = size;
}

void Data::malloc( size_t size )
{
	magicalAssert( size > 0, "size should > 0" );

	magicalSafeFree( _data );
	_data = (char*) ::malloc( size );
	magicalAssert( _data, "(char*) ::malloc( size );" );
	_size = size;
}

void Data::realloc( size_t size )
{
	magicalAssert( size > 0, "size should > 0" );
	magicalAssert( _data, "Invalid!" );

	if( size > _size )
	{
		_data = (char*) ::realloc( _data, size );
		magicalAssert( _data, "::realloc( _data, size );" );
	}
	else
	{
		_size = size;
	}
}

void Data::free( void )
{
	magicalSafeFreeNull( _data );
}

bool Data::empty( void ) const
{
	return _data == nullptr;
}

size_t Data::size( void ) const
{
	return _size;
}

char* Data::cPtr( void )
{
	return _data;
}

NS_MAGICAL_END