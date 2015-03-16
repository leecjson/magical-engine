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
#include <stdlib.h>

NS_MAGICAL_BEGIN

Data::Data( void )
{

}

Data::~Data( void )
{
	magicalSafeFree( m_data );
}

Ptr<Data> Data::Create( void )
{
	Data* ret = new Data();
	magicalAssert( ret, "new Data() failed" );
	return Ptr<Data>( PtrCtor<Data>( ret ) );
}

Ptr<Data> Data::Create( size_t size )
{
	Data* ret = new Data();
	magicalAssert( ret, "new Data() failed" );
	ret->Malloc( size );
	return Ptr<Data>( PtrCtor<Data>( ret ) );
}

Ptr<Data> Data::Create( char* data, size_t size )
{
	Data* ret = new Data();
	magicalAssert( ret, "new Data() failed" );
	ret->Assign( data, size );
	return Ptr<Data>( PtrCtor<Data>( ret ) );
}

void Data::Assign( char* data, size_t size )
{
	magicalAssert( data && size > 0, "data should not be nullptr and size should > 0" );

	magicalSafeFree( m_data );
	m_data = data;
	m_size = size;
}

void Data::Malloc( size_t size )
{
	magicalAssert( size > 0, "size should > 0" );

	magicalSafeFree( m_data );
	m_data = (char*) ::malloc( size );
	magicalAssert( m_data, "(char*) ::malloc( size );" );
	m_size = size;
}

void Data::Realloc( size_t size )
{
	magicalAssert( size > 0, "size should > 0" );
	magicalAssert( m_data, "Invalid!" );

	if( size > m_size )
	{
		m_data = (char*) ::realloc( m_data, size );
		magicalAssert( m_data, "::realloc( _data, size );" );
	}
	else
	{
		m_size = size;
	}
}

void Data::Free( void )
{
	magicalSafeFreeNull( m_data );
}

bool Data::Empty( void ) const
{
	return m_data == nullptr;
}

size_t Data::Size( void ) const
{
	return m_size;
}

char* Data::CPtr( void ) const
{
	return m_data;
}

NS_MAGICAL_END