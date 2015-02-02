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
		m_reference = ref;
	}

private:
	template< class T >
	friend class Ptr;
	T* m_reference = nullptr;
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
		m_reference = nt;
	}

	~Ptr( void )
	{
		if( m_reference )
		{
			m_reference->release();
		}
	}

	Ptr( T* rhs )
	{
		if( rhs )
		{
			rhs->retain();
			m_reference = rhs;
		}
	}

	Ptr( Ptr<T>& rhs )
	{
		if( rhs.m_reference )
		{
			rhs.m_reference->retain();
			m_reference = rhs.m_reference;
		}
	}

	Ptr( Ptr<T>&& rhs )
	{
		if( rhs.m_reference )
		{
			m_reference = rhs.m_reference;
			rhs.m_reference = nullptr;
		}
	}

	template< class Tz >
	Ptr( Ptr<Tz>& rhs )
	{
		Tz* ref = rhs.get();
		if( ref != nullptr )
		{
			ref->retain();
			m_reference = static_cast< Tz* >( ref );
		}
	}

	Ptr( Initializer<T>& ir )
	{
		if( ir.m_reference )
		{
			m_reference = ir.m_reference;
		}
	}

public:
	void reset( void )
	{
		if( m_reference )
		{
			m_reference->release();
			m_reference = nullptr;
		}
	}

	void set( std::nullptr_t nt )
	{
		if( m_reference )
		{
			m_reference->release();
			m_reference = nt;
		}
	}

	void set( T* rhs )
	{
		if( rhs )
		{
			rhs->retain();
		}

		if( m_reference )
		{
			m_reference->release();
		}

		m_reference = rhs;
	}

	void set( Ptr<T>& rhs )
	{
		if( rhs.m_reference )
		{
			rhs.m_reference->retain();
		}

		if( m_reference )
		{
			m_reference->release();
		}

		m_reference = rhs.m_reference;
	}

	void set( Ptr<T>&& rhs )
	{
		if( m_reference )
		{
			m_reference->release();
			m_reference = nullptr;
		}

		if( rhs.m_reference )
		{
			m_reference = rhs.m_reference;
			rhs.m_reference = nullptr;
		}
	}

	template< class Tz >
	void set( Ptr<Tz>& rhs )
	{
		Tz* ref = rhs.get();
		if( ref != nullptr )
		{
			ref->retain();

			if( m_reference )
				m_reference->release();

			m_reference = static_cast< Tz* >( ref );
		}
		else
		{
			if( m_reference )
			{
				m_reference->release();
				m_reference = nullptr;
			}
		}
	}

	void set( Initializer<T>& ir )
	{
		if( m_reference )
		{
			m_reference->release();
			m_reference = nullptr;
		}

		if( ir.m_reference )
		{
			m_reference = ir.m_reference;
		}
	}

	T* get( void ) const
	{
		return m_reference;
	}

	template< class Tz >
	Tz* get( void ) const
	{
		return static_cast< Tz* >( m_reference );
	}

	T* take( void )
	{
		T* ref = m_reference;
		m_reference = nullptr;
		return ref;
	}

	template< class Tz >
	Tz* take( void )
	{
		Tz* ref = static_cast< Tz* >( m_reference );
		m_reference = nullptr;
		return ref;
	}

	Ptr<T> share( void ) const
	{
		return Ptr<T>( m_reference );
	}

	template< class Tz >
	Ptr<Tz> share( void ) const
	{
		return Ptr<Tz>( static_cast< Tz* >( m_reference ) );
	}

	Ptr<Reference> shareReference( void ) const
	{
		return Ptr<Reference>( m_reference );
	}

public:
	Ptr<T>& operator=( std::nullptr_t nt )
	{
		set( nt );
		return *this;
	}

	Ptr<T>& operator=( T* rhs )
	{
		set( rhs );
		return *this;
	}

	Ptr<T>& operator=( const Ptr<T>& rhs )
	{
		set( rhs );
		return *this;
	}

	Ptr<T>& operator=( Ptr<T>&& rhs )
	{
		set( std::forward< Ptr<T> >( rhs ) );
		return *this;
	}

	T* operator->( void ) const
	{
		return m_reference;
	}

	bool operator==( const Ptr<T>& rhs ) const
	{
		return m_reference == rhs.m_reference;
	}

	bool operator!=( const Ptr<T>& rhs ) const
	{
		return m_reference != rhs.m_reference;
	}

	bool operator==( std::nullptr_t nt ) const
	{
		return m_reference == nt;
	}

	bool operator!=( std::nullptr_t nt ) const
	{
		return m_reference != nt;
	}

private:
	T* m_reference = nullptr;
};

NS_MAGICAL_END

#endif //__PTR_H__