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

#include "magical-macros.h"
#include "Common.h"

NS_MAGICAL_BEGIN

template< class T >
class CachePool
{
public:
	member_method CachePool( void );
	member_method CachePool( size_t capacity );
	member_method CachePool( size_t capacity, size_t fillsize );
	member_method ~CachePool( void );

public:
	member_method void Fill( size_t size );
	member_method void Push( void* ptr );
	member_method void* Take( void );
	member_method void Clear( void );
	member_method size_t Size( void ) const;
	member_method bool Empty( void ) const;

protected:
	member_method void GrowCapacity( void );
	member_method void GrowCapacity( size_t size );

protected:
	size_t m_size = 0;
	size_t m_capacity = 0;
	T** m_objects = nullptr;
};

#include "CachePool.inl"

NS_MAGICAL_END

#endif //__CACHE_POOL_H__