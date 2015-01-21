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
#ifndef __PTR_H__
#define __PTR_H__

#include "PlatformMacros.h"
#include "Common.h"
#include "Reference.h"

NS_MAGICAL_BEGIN

template< class T >
class Ptr;
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
	friend class Ptr;
	T* _reference = nullptr;
};

template< class T >
class Ptr
{
public:
	Ptr( void )
	{

	}

	Ptr( std::nullptr_t nt )
	{
		_reference = nt;
	}

	~Ptr( void )
	{
		if( _reference )
		{
			_reference->release();
		}
	}

	Ptr( T* other )
	{
		if( other )
		{
			other->retain();
			_reference = other;
		}
	}

	Ptr( Ptr<T>& other )
	{
		if( other._reference )
		{
			other._reference->retain();
			_reference = other._reference;
		}
	}

	Ptr( Ptr<T>&& other )
	{
		if( other._reference )
		{
			_reference = other._reference;
			other._reference = nullptr;
		}
	}

	template< class Tz >
	Ptr( Ptr<Tz>& other )
	{
		Tz* ref = other.get();
		if( ref != nullptr )
		{
			ref->retain();
			_reference = static_cast<Tz*>( ref );
		}
	}

	Ptr( Initializer<T>& ir )
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

	void set( std::nullptr_t nt )
	{
		if( _reference )
		{
			_reference->release();
			_reference = nt;
		}
	}

	void set( T* other )
	{
		if( other )
		{
			other->retain();
		}

		if( _reference )
		{
			_reference->release();
		}

		_reference = other;
	}

	void set( Ptr<T>& other )
	{
		if( other._reference )
		{
			other._reference->retain();
		}

		if( _reference )
		{
			_reference->release();
		}

		_reference = other._reference;
	}

	void set( Ptr<T>&& other )
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

	template< class Tz >
	void set( Ptr<Tz>& other )
	{
		Tz* ref = other.get();
		if( ref != nullptr )
		{
			ref->retain();
			if( _reference )
				_reference->release();

			_reference = static_cast< Tz* >( ref );
		}
		else
		{
			if( _reference )
			{
				_reference->release();
				_reference = nullptr;
			}
		}
	}

	void set( Initializer<T>& ir )
	{
		if( _reference )
		{
			_reference->release();
			_reference = nullptr;
		}

		if( ir._reference )
		{
			_reference = ir._reference;
		}
	}

	T* get( void ) const
	{
		return _reference;
	}

	template< class Tz >
	Tz* get( void ) const
	{
		return static_cast< Tz* >( _reference );
	}

	T* take( void )
	{
		T* ref = _reference;
		_reference = nullptr;
		return ref;
	}

	template< class Tz >
	Tz* take( void )
	{
		Tz* ref = static_cast< Tz* >( _reference );
		_reference = nullptr;
		return ref;
	}

	Ptr<T> share( void ) const
	{
		return Ptr<T>( _reference );
	}

	template< class Tz >
	Ptr<Tz> share( void ) const
	{
		return Ptr<Tz>( static_cast< Tz* >( _reference ) );
	}

	Ptr<Reference> shareReference( void ) const
	{
		return Ptr<Reference>( _reference );
	}

public:
	Ptr<T>& operator=( std::nullptr_t nt )
	{
		set( nt );
		return *this;
	}

	Ptr<T>& operator=( T* other )
	{
		set( other );
		return *this;
	}

	Ptr<T>& operator=( const Ptr<T>& other )
	{
		set( other );
		return *this;
	}

	Ptr<T>& operator=( Ptr<T>&& other )
	{
		set( std::forward< Ptr<T> >( other ) );
		return *this;
	}

	T* operator->( void ) const
	{
		return _reference;
	}

	bool operator==( const Ptr<T>& other ) const
	{
		return _reference == other._reference;
	}

	bool operator!=( const Ptr<T>& other ) const
	{
		return _reference != other._reference;
	}

	bool operator==( std::nullptr_t nt ) const
	{
		return _reference == nt;
	}

	bool operator!=( std::nullptr_t nt ) const
	{
		return _reference != nt;
	}

private:
	T* _reference = nullptr;
};

NS_MAGICAL_END

#endif //__PTR_H__