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
#ifndef __SHARED_H__
#define __SHARED_H__

#include "PlatformMacros.h"
#include "Common.h"

template< class T >
class Shared
{
public:
	Shared( void )
	{
	}

	~Shared( void )
	{
	}

	Shared( const T* ref )
	{
	}

	Shared( const Shared& other )
	{
	}

	Shared( Shared&& other )
	{
	}

	Shared( std::nullptr_t nil )
	{
	}

public:
	void reset( void )
	{
	}

	void set( const Shared& other )
	{
	}

	void set( Shared&& other )
	{
	}

	T* get( void ) const
	{
	}

public:
	Shared& operator=( const T* ref )
	{
	}

	Shared& operator=( const Shared& other )
	{
	}

	Shared& operator=( Shared&& other )
	{
	}

	Shared& operator=( std::nullptr_t nil )
	{
	}

public:
	bool operator==( const Shared& other ) const
	{
	}

	bool operator!=( const Shared& other ) const
	{
	}

private:
	T* _reference = nullptr;
};


#endif //__SHARED_H__