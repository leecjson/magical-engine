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
class Shared;

template< class T >
class Initializer
{
public:
	Initializer( void )
	{
		
	}

	Initializer( T* ref )
	{
		_reference = ref;
	}

private:
	template< class T >
	friend class Shared;
	T* _reference = nullptr;
};

template< class T >
class Shared
{
public:
	Shared( void )
	{

	}

	~Shared( void )
	{
		if( _reference )
		{
			_reference->release();
		}
	}

	Shared( T* ref )
	{
		if( ref )
		{
			_reference = ref;
			_reference->retain();
		}
	}

	Shared( const Shared& other )
	{
		if( other._reference )
		{
			_reference = other._reference;
			_reference->retain();
		}
	}

	Shared( Shared&& other )
	{
		if( other._reference )
		{
			_reference = other._reference;
			other._reference = nullptr;
		}
	}
	
	Shared( std::nullptr_t nil )
	{
		_reference = nil;
	}

	Shared( const Initializer<T>& ir )
	{
		if( ir._reference )
		{
			_reference = ir._reference;
		}
	}

	Shared( Initializer<T>&& ir )
	{
		if( ir._reference )
		{
			_reference = ir._reference;
		}
	}

public:
	void reset( void )
	{
		if( _reference )
		{
			_reference->release();
			_reference = nullptr;
		}
	}

	void set( T* ref )
	{
		if( _reference )
		{
			_reference->release();
			_reference = nullptr;
		}

		if( ref )
		{
			_reference = ref;
			_reference->retain()
		}
	}

	void set( const Shared& other )
	{
		if( _reference )
		{
			_reference->release();
			_reference = nullptr;
		}

		if( other._reference )
		{
			_reference = other._reference;
			_reference->retain();
		}
	}

	void set( Shared&& other )
	{
		if( _reference )
		{
			_reference->release();
			_reference = nullptr;
		}

		if( other._reference )
		{
			_reference = other._reference;
			other._reference = nullptr;
		}
	}

	void set( std::nullptr_t nil )
	{
		if( _reference )
		{
			_reference->release();
			_reference = nil;
		}
	}

	T* get( void ) const
	{
		return _reference;
	}

	T* take( void )
	{
		if( _reference )
		{
			_reference->retatin();
		}
		return _reference;
	}

public:
	Shared& operator=( T* ref )
	{
		set( ref );
		return *this;
	}

	Shared& operator=( const Shared& other )
	{
		set( other );
		return *this;
	}

	Shared& operator=( Shared&& other )
	{
		set( std::forward<Shared>( other ) );
		return *this;
	}

	Shared& operator=( std::nullptr_t nil )
	{
		set( nil );
		return *this;
	}

	T* operator->( void ) const
	{
		return _reference;
	}

public:
	bool operator==( const Shared& other ) const
	{
		return _reference == other._reference;
	}

	bool operator!=( const Shared& other ) const
	{
		return _reference != other._reference;
	}

	bool operator==( std::nullptr_t nil ) const
	{
		return _reference == nil;
	}

	bool operator!=( std::nullptr_t nil ) const
	{
		return _reference != nil;
	}

private:
	T* _reference = nullptr;
};


#endif //__SHARED_H__