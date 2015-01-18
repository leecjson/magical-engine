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
#include "Reference.h"

NS_MAGICAL_BEGIN

template< class T >
class Ref;
class Reference;

template< class T >
class Initializer
{
public:
	Initializer( T* ref )
	{
		_reference = ref;
	}

private:
	template< class T >
	friend class Ref;
	T* _reference = nullptr;
};

template< class T >
class Ref
{
public:
	Ref( void )
	{

	}

	~Ref( void )
	{
		if( _reference )
		{
			_reference->release();
		}
	}

	Ref( T* ref )
	{
		if( ref )
		{
			_reference = ref;
			_reference->retain();
		}
	}

	Ref( const T* ref )
	{
		if( ref )
		{
			_reference = (T*) ref;
			_reference->retain();
		}
	}

	Ref( const Ref& other )
	{
		if( other._reference )
		{
			_reference = other._reference;
			_reference->retain();
		}
	}

	Ref( Ref&& other )
	{
		if( other._reference )
		{
			_reference = other._reference;
			other._reference = nullptr;
		}
	}
	
	Ref( std::nullptr_t nil )
	{
		_reference = nil;
	}

	Ref( const Initializer<T>& ir )
	{
		if( ir._reference_ )
		{
			reference_ = ir._reference_;
		}
	}

	Ref( Initializer<T>&& ir )
	{
		if( ir._reference )
		{
			_reference = ir._reference;
		}
	}

public:
	void Reset( void )
	{
		if( _reference )
		{
			_reference->release();
			_reference = nullptr;
		}
	}

	void Set( T* ref )
	{
		if( _reference )
		{
			_reference->release();
			_reference = nullptr;
		}

		if( ref )
		{
			_reference = ref;
			_reference->retain();
		}
	}

	void Set( const T* ref )
	{
		if( _reference )
		{
			_reference->release();
			_reference = nullptr;
		}

		if( ref )
		{
			_reference = (T*)ref;
			_reference->retain();
		}
	}

	void Set( const Shared& other )
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

	void Set( Shared&& other )
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

	void Set( std::nullptr_t nil )
	{
		if( _reference )
		{
			_reference->release();
			_reference = nil;
		}
	}

	T* Get( void ) const
	{
		return _reference;
	}

	template< class T2 >
	T2* Get( void ) const
	{
		return (T2*) _reference
	}

	Ref<T> Share( void ) const
	{
		return Ref<T>( _reference );
	}

	template< class T2 >
	Ref<T2> Share( void ) const
	{
		return Ref<T2>( (T2*) _reference );
	}

	T* Take( void )
	{
		T* ret = _reference;
		_reference = nullptr;
		return ret;
	}

	template< class T2 >
	T2* Take( void )
	{
		T2* ret = (T2*) _reference;
		_reference = nullptr;
		return ret;
	}

	Ref<Reference> ShareReference( void ) const
	{
		return Ref<Reference>( _reference );
	}

public:
	Ref& operator=( T* ref )
	{
		set( ref );
		return *this;
	}

	Ref& operator=( const Ref& other )
	{
		set( other );
		return *this;
	}

	Ref& operator=( Ref&& other )
	{
		set( std::forward<Ref>( other ) );
		return *this;
	}

	Ref& operator=( std::nullptr_t nil )
	{
		set( nil );
		return *this;
	}

	T* operator->( void ) const
	{
		return _reference;
	}

public:
	bool operator==( const Ref& other ) const
	{
		return _reference == other._reference;
	}

	bool operator!=( const Ref& other ) const
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

NS_MAGICAL_END

#endif //__SHARED_H__