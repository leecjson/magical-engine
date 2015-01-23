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
#ifndef __CACHE_POOL_H__
#define __CACHE_POOL_H__

#include "PlatformMacros.h"
#include "Common.h"

NS_MAGICAL_BEGIN

template< class T >
class CachePool
{
public:
	CachePool( void )
	{
		growCapacity( 32 );
	}

	CachePool( size_t capacity )
	{
		growCapacity( capacity );
	}

	CachePool( size_t capacity, size_t fillsize )
	{
		growCapacity( capacity );
		fill( fillsize );
	}

	~CachePool( void )
	{
		clear();
	}

	void fill( size_t size )
	{
		size_t obj_size = sizeof( T );

		if( obj_size == 0 ) 
			obj_size = 1;

		for( size_t i = 0; i < size; ++i )
		{
			growCapacity();
			typename T* ptr = (T*) malloc( obj_size );

			if( !ptr ) 
				throw std::bad_alloc();

			m_objects[ m_size ] = ptr;
			m_size += 1;
		}
	}

	void push( void* ptr )
	{
		growCapacity();

		m_objects[ m_size ] = (T*) ptr;
		m_size += 1;
	}

	void* take( void )
	{
		if( m_size == 0 )
		{
			growCapacity();
			fill( m_capacity );

			typename T* ptr = m_objects[ m_size - 1 ];
			if( m_size != 0 )
				-- m_size;

			return ptr;
		}
		else
		{
			typename T* ptr = m_objects[ m_size - 1 ];
			if( m_size != 0 )
				-- m_size;

			return ptr;
		}
	}

	void growCapacity( void )
	{
		if( m_objects )
		{
			if( m_size == m_capacity )
			{
				growCapacity( m_capacity );
			}
		}
		else
		{
			growCapacity( 32 );
		}
	}

	void growCapacity( size_t size )
	{
		if( size == 0 )
			return;

		if( m_objects )
		{
			m_capacity += size;
			m_objects = (T**) realloc( m_objects, m_capacity * sizeof( T* ) );
		}
		else
		{
			m_capacity = size;
			m_objects = (T**) malloc( size * sizeof( T* ) );
		}

		if( !m_objects ) 
			throw std::bad_alloc();
	}

	void clear( void )
	{
		if( m_objects )
		{
			for( size_t i = 0; i < m_size; ++i )
			{
				free( m_objects[i] );
			}

			free( m_objects );
			m_objects = nullptr;
			m_size = 0;
			m_capacity = 0;
		}
	}

	size_t size( void ) const
	{
		return m_size;
	}

	bool empty( void ) const
	{
		return m_size == 0
	}

private:
	size_t m_size = 0;
	size_t m_capacity = 0;
	typename T** m_objects = nullptr;
};

NS_MAGICAL_END

#endif //__CACHE_POOL_H__