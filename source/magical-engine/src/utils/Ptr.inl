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
		rhs->Retain();
		m_reference = rhs;
	}
}

template< class T >
Ptr<T>::Ptr( Ptr<T>& rhs )
{
	if( rhs.m_reference )
	{
		rhs.m_reference->Retain();
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
	Tz* ref = rhs.Get();
	if( ref != nullptr )
	{
		ref->Retain();
		m_reference = static_cast< Tz* >( ref );
	}
}

template< class T >
template< class Tz >
Ptr<T>::Ptr( Ptr<Tz>&& rhs )
{
	Tz* ref = rhs.Get();
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
		m_reference->Release();
	}
}

template< class T >
void Ptr<T>::Set( T* rhs )
{
	if( rhs )
	{
		rhs->Retain();
	}

	if( m_reference )
	{
		m_reference->Release();
	}

	m_reference = rhs;
}

template< class T >
void Ptr<T>::Set( Ptr<T>& rhs )
{
	if( rhs.m_reference )
	{
		rhs.m_reference->Retain();
	}

	if( m_reference )
	{
		m_reference->Release();
	}

	m_reference = rhs.m_reference;
}

template< class T >
void Ptr<T>::Set( Ptr<T>&& rhs )
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
void Ptr<T>::Set( PtrCtor<T>& rhs )
{
	magicalAssert( m_reference != rhs.m_reference || ( !rhs.m_reference && !m_reference ), "Invalid!" );

	if( m_reference )
	{
		m_reference->Release();
		m_reference = nullptr;
	}

	if( rhs.m_reference )
	{
		m_reference = rhs.m_reference;
	}
}

template< class T >
void Ptr<T>::Set( PtrCtor<T>&& rhs )
{
	magicalAssert( m_reference != rhs.m_reference || ( !rhs.m_reference && !m_reference ), "Invalid!" );

	if( m_reference )
	{
		m_reference->Release();
		m_reference = nullptr;
	}

	if( rhs.m_reference )
	{
		m_reference = rhs.m_reference;
		rhs.m_reference = nullptr;
	}
}

template< class T >
void Ptr<T>::Set( nullptr_t rhs )
{
	if( m_reference )
	{
		m_reference->Release();
		m_reference = rhs;
	}
}

template< class T >
template< class Tz >
void Ptr<T>::Set( Ptr<Tz>& rhs )
{
	Tz* ref = rhs.Get();
	if( ref != nullptr )
	{
		ref->Retain();

		if( m_reference )
			m_reference->Release();

		m_reference = static_cast< Tz* >( ref );
	}
	else
	{
		if( m_reference )
		{
			m_reference->Release();
			m_reference = nullptr;
		}
	}
}

template< class T >
template< class Tz >
void Ptr<T>::Set( Ptr<Tz>&& rhs )
{
	Tz* ref = rhs.Get();
	magicalAssert( m_reference != ref || ( !ref && !m_reference ), "Invalid!" );

	if( ref != nullptr )
	{
		if( m_reference )
			m_reference->Release();

		m_reference = static_cast< Tz* >( ref );
		rhs.m_reference = nullptr;
	}
	else
	{
		if( m_reference )
		{
			m_reference->Release();
			m_reference = nullptr;
		}
	}
}

template< class T >
void Ptr<T>::Reset( void )
{
	if( m_reference )
	{
		m_reference->Release();
		m_reference = nullptr;
	}
}

template< class T >
T* Ptr<T>::Take( void )
{
	T* ref = m_reference;
	m_reference = nullptr;
	return ref;
}

template< class T >
T* Ptr<T>::Get( void ) const
{
	return m_reference;
}

template< class T >
template< class Tz >
Tz* Ptr<T>::StaticCastTo( void ) const
{
	return static_cast< Tz* >( m_reference );
}

template< class T >
template< class Tz >
Tz* Ptr<T>::DynamicCastTo( void ) const
{
	return dynamic_cast< Tz* >( m_reference );
}

template< class T >
Ptr<T>& Ptr<T>::operator=( nullptr_t rhs )
{
	Set( rhs );
	return *this;
}

template< class T >
Ptr<T>& Ptr<T>::operator=( T* rhs )
{
	Set( rhs );
	return *this;
}

template< class T >
Ptr<T>& Ptr<T>::operator=( Ptr<T>& rhs )
{
	Set( rhs );
	return *this;
}

template< class T >
Ptr<T>& Ptr<T>::operator=( Ptr<T>&& rhs )
{
	Set( std::forward< Ptr<T> >( rhs ) );
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