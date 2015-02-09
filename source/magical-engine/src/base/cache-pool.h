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

#include "platform-macros.h"
#include "common.h"

NS_MAGICAL_BEGIN

template< class T >
class CachePool
{
public:
	CachePool( void );
	CachePool( size_t capacity );
	CachePool( size_t capacity, size_t fillsize );
	~CachePool( void );

public:
	void fill( size_t size );
	void push( void* ptr );
	void* take( void );
	void clear( void );
	size_t size( void ) const;
	bool empty( void ) const;

protected:
	void growCapacity( void );
	void growCapacity( size_t size );

protected:
	size_t m_size = 0;
	size_t m_capacity = 0;
	T** m_objects = nullptr;
};

#include "cache-pool.inl"

NS_MAGICAL_END

#endif //__CACHE_POOL_H__