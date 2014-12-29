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
#ifndef __CACHED_POOL_H__
#define __CACHED_POOL_H__

#include "PlatformMacros.h"
#include "Common.h"

#define MAGICAL_CACHED_POOL_DEFAULT_CAPACITY 32

template< class T >
class CachedPool
{
public:
	CachedPool( void )
	{
		grow_capacity( MAGICAL_CACHED_POOL_DEFAULT_CAPACITY );
	}

	CachedPool( size_t capacity )
	{
		grow_capacity( capacity );
	}

	CachedPool( size_t capacity, size_t fill_size )
	{
		grow_capacity( capacity );
		fill( fill_size );
	}

	~CachedPool( void )
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
			grow_capacity();
			typename T* ptr = (T*)malloc( obj_size );

			if( !ptr ) throw std::bad_alloc();

			_objects[_size] = ptr;
			++_size;
		}
	}

	void push( void* ptr )
	{
		grow_capacity();

		_objects[_size] = (T*)ptr;
		++_size;
	}

	void* take( void )
	{
		if( _size == 0 )
		{
			grow_capacity();
			fill( _capacity );
			
			typename T* ptr = _objects[_size - 1];

			if( _size != 0 )
				--_size;

			return ptr;
		}
		else
		{
			typename T* ptr = _objects[_size - 1];

			if( _size != 0 )
				--_size;

			return ptr;
		}
	}

	void grow_capacity( void )
	{
		if( _objects )
		{
			if( _size == _capacity )
			{
				grow_capacity( _capacity );
			}
		}
		else
		{
			grow_capacity( MAGICAL_CACHED_POOL_DEFAULT_CAPACITY );
		}
	}

	void grow_capacity( size_t size )
	{
		if( size == 0 )
			return;

		if( _objects )
		{
			_capacity += size;
			_objects = (T**)realloc( _objects, _capacity * sizeof( T* ) );
		}
		else
		{
			_capacity = size;
			_objects = (T**)malloc( size * sizeof( T* ) );
		}

		if( !_objects ) throw std::bad_alloc();
	}

	void clear( void )
	{
		if( _objects )
		{
			for( size_t i = 0; i < _size; ++i )
			{
				free( _objects[i] );
			}

			free( _objects );
			_size = 0;
			_capacity = 0;
			_objects = nullptr;
		}
	}

	size_t size( void ) const
	{
		return _size;
	}

	bool empty( void ) const
	{
		return _size == 0
	}

private:
	size_t _size = 0;
	size_t _capacity = 0;
	typename T** _objects = nullptr;
};

#endif //__CACHED_POOL_H__