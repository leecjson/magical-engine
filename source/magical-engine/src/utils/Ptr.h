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

#include "magical-macros.h"
#include "Common.h"
#include "Reference.h"
#include "Ptrctor.h"

NAMESPACE_MAGICAL

template< class T >
class Ptr 
{
public:
	inline Ptr( void )
	{

	}

	inline Ptr( T* rhs )
	{
		if( rhs )
		{
			rhs->retain();
			m_reference = rhs;
		}
	}

	inline Ptr( Ptr<T>& rhs )
	{
		if( rhs.m_reference )
		{
			rhs.m_reference->retain();
			m_reference = rhs.m_reference;
		}
	}

	inline Ptr( Ptr<T>&& rhs )
	{
		if( rhs.m_reference )
		{
			m_reference = rhs.m_reference;
			rhs.m_reference = nullptr;
		}
	}

	inline Ptr( Ptrctor<T>& rhs )
	{
		if( rhs.m_reference )
		{
			m_reference = rhs.m_reference;
			rhs.m_reference = nullptr;
		}
	}

	inline Ptr( nullptr_t rhs )
	{
		m_reference = rhs;
	}

	template< class Tz >
	inline Ptr( Ptr<Tz>& rhs )
	{
		Tz* ref = rhs.get();
		if( ref != nullptr )
		{
			ref->retain();
			m_reference = static_cast< Tz* >( ref );
		}
	}

	template< class Tz >
	inline Ptr( Ptr<Tz>&& rhs )
	{
		Tz* ref = rhs.get();
		if( ref != nullptr )
		{
			m_reference = static_cast< Tz* >( ref );
			rhs.m_reference = nullptr;
		}
	}

	inline ~Ptr( void )
	{
		if( m_reference )
		{
			m_reference->release();
		}
	}

	inline void set( T* rhs )
	{
		if( rhs )
			rhs->retain();

		if( m_reference )
			m_reference->release();

		m_reference = rhs;
	}

	inline void set( Ptr<T>& rhs )
	{
		if( rhs.m_reference )
			rhs.m_reference->retain();

		if( m_reference )
			m_reference->release();

		m_reference = rhs.m_reference;
	}

	inline void set( Ptr<T>&& rhs )
	{
		MAGICAL_ASSERT( m_reference != rhs.m_reference || ( !rhs.m_reference && !m_reference ), "Invalid!" );

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

	inline void set( Ptrctor<T>& rhs )
	{
		MAGICAL_ASSERT( m_reference != rhs.m_reference || ( !rhs.m_reference && !m_reference ), "Invalid!" );

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

	inline void set( nullptr_t rhs )
	{
		if( m_reference )
		{
			m_reference->release();
			m_reference = rhs;
		}
	}

	template< class Tz >
	inline void set( Ptr<Tz>& rhs )
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

	template< class Tz >
	inline void set( Ptr<Tz>&& rhs )
	{
		Tz* ref = rhs.get();
		MAGICAL_ASSERT( m_reference != ref || ( !ref && !m_reference ), "Invalid!" );

		if( ref != nullptr )
		{
			if( m_reference )
				m_reference->release();

			m_reference = static_cast< Tz* >( ref );
			rhs.m_reference = nullptr;
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

	inline void clean( void )
	{
		if( m_reference )
		{
			m_reference->release();
			m_reference = nullptr;
		}
	}

	inline T* take( void )
	{
		T* ref = m_reference;
		m_reference = nullptr;
		return ref;
	}

	inline T* get( void ) const
	{
		return m_reference;
	}

	template< class Tz >
	inline Tz* staticCast( void ) const
	{
		return m_reference ? static_cast< Tz* >( m_reference ) : nullptr;
	}

	template< class Tz >
	inline Tz* dynamicCast( void ) const
	{
		return m_reference ? dynamic_cast< Tz* >( m_reference ) : nullptr;
	}

	inline Ptr<T>& operator=( nullptr_t rhs )
	{
		set( rhs );
		return *this;
	}

	inline Ptr<T>& operator=( T* rhs )
	{
		set( rhs );
		return *this;
	}

	inline Ptr<T>& operator=( Ptr<T>& rhs )
	{
		set( rhs );
		return *this;
	}

	inline Ptr<T>& operator=( Ptr<T>&& rhs )
	{
		set( std::forward< Ptr<T> >( rhs ) );
		return *this;
	}

	inline T* operator->( void ) const
	{
		return m_reference;
	}

	inline bool operator==( const Ptr<T>& rhs ) const
	{
		return m_reference == rhs.m_reference;
	}

	inline bool operator==( const T* rhs ) const
	{
		return m_reference == rhs;
	}

	inline bool operator!=( const Ptr<T>& rhs ) const
	{
		return m_reference != rhs.m_reference;
	}

	inline bool operator!=( const T* rhs ) const
	{
		return m_reference != rhs;
	}

	inline bool operator==( nullptr_t rhs ) const
	{
		return m_reference == rhs;
	}

	inline bool operator!=( nullptr_t rhs ) const
	{
		return m_reference != rhs;
	}

	inline operator bool( void ) const
	{
		return m_reference != nullptr;
	}

	inline operator T*( void ) const
	{
		return m_reference;
	}

protected:
	T* m_reference = nullptr;
};

template< class T >
static inline bool operator==( const T* lhs, const Ptr<T>& rhs )
{
	return lhs == rhs.get();
}

template< class T >
static inline bool operator!=( const T* lhs, const Ptr<T>& rhs )
{
	return lhs != rhs.get();
}


NAMESPACE_END

#endif //__PTR_H__