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
#include "PlatformMacros.h"
#include "Data.h"

<<<<<<< HEAD
Data_t::Data_t( void )
: _data(nullptr)
=======
Data::Data( void )
>>>>>>> ec1b54020335b76df015817be9eeaa46104a0857
{

}

Data::~Data( void )
{
<<<<<<< HEAD
	if( _data )
	{
<<<<<<< HEAD
		free( _data );
	}
}

void Data_t::malloc( const size_t t )
=======
		magicalFree( _data );
	}
}

void Data_t::assign( char* data, const size_t size )
>>>>>>> origin/master
=======
	magicalSafeFree( _data );
}

Shared<Data> Data::createShared( void )
>>>>>>> ec1b54020335b76df015817be9eeaa46104a0857
{
	Data* ret = new Data();
	magicalAssert( ret, "new Data() failed" );
	return Shared<Data>( Initializer<Data>(ret) );
}

<<<<<<< HEAD
	if( _data )
	{
	}
<<<<<<< HEAD
=======
=======
Data* Data::create( void )
{
	Data* ret = new Data();
	magicalAssert( ret, "new Data() failed" );
	return ret;
}

void Data::assign( char* data, const size_t size )
{
	magicalAssert( data && size > 0, "data should not be nullptr and size should > 0" );

	magicalSafeFree( _data );
>>>>>>> ec1b54020335b76df015817be9eeaa46104a0857
	_data = data;
	_size = size;
}

void Data::malloc( const size_t size )
{
	magicalAssert( size > 0, "size should > 0" );

	magicalSafeFree( _data );
	_data = (char*) ::malloc( size );
	magicalAssert( _data, "(char*) ::malloc( size );" );
	_size = size;
}

void Data::realloc( const size_t size )
{
	magicalAssert( size > 0, "size should > 0" );
	magicalAssert( _data, "_data should not be nullptr" );

	if( size > _size )
	{
		_data = (char*) ::realloc( _data, size );
		magicalAssert( _data, "(char*) ::realloc( _data, size );" );
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

size_t Data::size( void ) const
{
	return _size;
}

char* Data::ptr( void ) const
{
<<<<<<< HEAD
	return _size;
>>>>>>> origin/master
=======
	return _data;
>>>>>>> ec1b54020335b76df015817be9eeaa46104a0857
}