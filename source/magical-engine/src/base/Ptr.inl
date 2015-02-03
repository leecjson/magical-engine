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
Initializer<T>::Initializer( T* ref )
{
	m_reference = ref;
}

template< class T >
Ptr<T>::Ptr( void )
{

}

template< class T >
Ptr<T>::Ptr( nullptr_t nt )
{
	m_reference = nt;
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
Ptr<T>::Ptr( Initializer<T>& ir )
{
	if( ir.m_reference )
	{
		m_reference = ir.m_reference;
	}
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
void Ptr<T>::set( nullptr_t nt )
{
	if( m_reference )
	{
		m_reference->release();
		m_reference = nt;
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
void Ptr<T>::set( Initializer<T>& ir )
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
template< class Tz >
Tz* Ptr<T>::get( void ) const
{
	return static_cast< Tz* >( m_reference );
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
Tz* Ptr<T>::take( void )
{
	Tz* ref = static_cast< Tz* >( m_reference );
	m_reference = nullptr;
	return ref;
}

template< class T >
Ptr<T> Ptr<T>::share( void ) const
{
	return Ptr<T>( m_reference );
}

template< class T >
template< class Tz >
Ptr<Tz> Ptr<T>::share( void ) const
{
	return Ptr<Tz>( static_cast< Tz* >( m_reference ) );
}

template< class T >
Ptr<T>& Ptr<T>::operator=( nullptr_t nt )
{
	set( nt );
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
bool Ptr<T>::operator==( nullptr_t nt ) const
{
	return m_reference == nt;
}

template< class T >
bool Ptr<T>::operator!=( nullptr_t nt ) const
{
	return m_reference != nt;
}