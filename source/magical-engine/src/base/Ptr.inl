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

template< class T >
PtrCtor<T>::PtrCtor( T* rhs )
{
	m_reference = rhs;
}

template< class T >
Ptr<T>::Ptr( void )
{

}

template< class T >
Ptr<T>::Ptr( T* rhs )
{
	if( rhs )
	{
		rhs->retain();
		m_reference = rhs;
	}
}

template< class T >
Ptr<T>::Ptr( Ptr<T>& rhs )
{
	if( rhs.m_reference )
	{
		rhs.m_reference->retain();
		m_reference = rhs.m_reference;
	}
}

template< class T >
Ptr<T>::Ptr( Ptr<T>&& rhs )
{
	if( rhs.m_reference )
	{
		m_reference = rhs.m_reference;
		rhs.m_reference = nullptr;
	}
}

template< class T >
Ptr<T>::Ptr( PtrCtor<T>& rhs )
{
	if( rhs.m_reference )
	{
		m_reference = rhs.m_reference;
	}
}

template< class T >
Ptr<T>::Ptr( PtrCtor<T>&& rhs )
{
	if( rhs.m_reference )
	{
		m_reference = rhs.m_reference;
		rhs.m_reference = nullptr;
	}
}

template< class T >
Ptr<T>::Ptr( nullptr_t rhs )
{
	m_reference = rhs;
}

template< class T >
template< class Tz >
Ptr<T>::Ptr( Ptr<Tz>& rhs )
{
	Tz* ref = rhs.get();
	if( ref != nullptr )
	{
		ref->retain();
		m_reference = static_cast< Tz* >( ref );
	}
}

template< class T >
template< class Tz >
Ptr<T>::Ptr( Ptr<Tz>&& rhs )
{
	Tz* ref = rhs.get();
	if( ref != nullptr )
	{
		m_reference = static_cast< Tz* >( ref );
		rhs.m_reference = nullptr;
	}
}

template< class T >
Ptr<T>::~Ptr( void )
{
	if( m_reference )
	{
		m_reference->release();
	}
}

template< class T >
void Ptr<T>::reset( void )
{
	if( m_reference )
	{
		m_reference->release();
		m_reference = nullptr;
	}
}

template< class T >
void Ptr<T>::set( T* rhs )
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

template< class T >
void Ptr<T>::set( Ptr<T>& rhs )
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

template< class T >
void Ptr<T>::set( Ptr<T>&& rhs )
{
	magicalAssert( m_reference != rhs.m_reference || ( !rhs.m_reference && !m_reference ), "Invalid!" );

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

template< class T >
void Ptr<T>::set( PtrCtor<T>& rhs )
{
	magicalAssert( m_reference != rhs.m_reference || ( !rhs.m_reference && !m_reference ), "Invalid!" );

	if( m_reference )
	{
		m_reference->release();
		m_reference = nullptr;
	}

	if( rhs.m_reference )
	{
		m_reference = rhs.m_reference;
	}
}

template< class T >
void Ptr<T>::set( PtrCtor<T>&& rhs )
{
	magicalAssert( m_reference != rhs.m_reference || ( !rhs.m_reference && !m_reference ), "Invalid!" );

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

template< class T >
void Ptr<T>::set( nullptr_t rhs )
{
	if( m_reference )
	{
		m_reference->release();
		m_reference = rhs;
	}
}

template< class T >
template< class Tz >
void Ptr<T>::set( Ptr<Tz>& rhs )
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

template< class T >
template< class Tz >
void Ptr<T>::set( Ptr<Tz>&& rhs )
{
	Tz* ref = rhs.get();
	magicalAssert( m_reference != ref || ( !ref && !m_reference ), "Invalid!" );

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

template< class T >
T* Ptr<T>::get( void ) const
{
	return m_reference;
}

template< class T >
T* Ptr<T>::take( void )
{
	T* ref = m_reference;
	m_reference = nullptr;
	return ref;
}

template< class T >
template< class Tz >
Tz* Ptr<T>::static_cast_to( void ) const
{
	return static_cast< Tz* >( m_reference );
}

template< class T >
template< class Tz >
Tz* Ptr<T>::dynamic_cast_to( void ) const
{
	return dynamic_cast< Tz* >( m_reference );
}

template< class T >
Ptr<T>& Ptr<T>::operator=( nullptr_t rhs )
{
	set( rhs );
	return *this;
}

template< class T >
Ptr<T>& Ptr<T>::operator=( T* rhs )
{
	set( rhs );
	return *this;
}

template< class T >
Ptr<T>& Ptr<T>::operator=( Ptr<T>& rhs )
{
	set( rhs );
	return *this;
}

template< class T >
Ptr<T>& Ptr<T>::operator=( Ptr<T>&& rhs )
{
	set( std::forward< Ptr<T> >( rhs ) );
	return *this;
}

template< class T >
T* Ptr<T>::operator->( void ) const
{
	return m_reference;
}

template< class T >
bool Ptr<T>::operator==( const Ptr<T>& rhs ) const
{
	return m_reference == rhs.m_reference;
}

template< class T >
bool Ptr<T>::operator!=( const Ptr<T>& rhs ) const
{
	return m_reference != rhs.m_reference;
}

template< class T >
bool Ptr<T>::operator==( nullptr_t rhs ) const
{
	return m_reference == rhs;
}

template< class T >
bool Ptr<T>::operator!=( nullptr_t rhs ) const
{
	return m_reference != rhs;
}