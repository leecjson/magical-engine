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
CachePool<T>::CachePool( void )
{
	GrowCapacity( 32 );
}

template< class T >
CachePool<T>::CachePool( size_t capacity )
{
	GrowCapacity( capacity );
}

template< class T >
CachePool<T>::CachePool( size_t capacity, size_t fillsize )
{
	GrowCapacity( capacity );
	Fill( fillsize );
}

template< class T >
CachePool<T>::~CachePool( void )
{
	Clear();
}

template< class T >
void CachePool<T>::Fill( size_t size )
{
	size_t obj_size = sizeof( T );

	if( obj_size == 0 )
		obj_size = 1;

	for( size_t i = 0; i < size; ++i )
	{
		GrowCapacity();
		T* ptr = static_cast< T* >( malloc( obj_size ) );

		if( ptr == nullptr )
			throw std::bad_alloc();

		m_objects[ size_m ] = ptr;
		m_size += 1;
	}
}

template< class T >
void CachePool<T>::Push( void* ptr )
{
	GrowCapacity();

	m_objects[ m_size ] = static_cast< T* >( ptr );
	m_size += 1;
}

template< class T >
void* CachePool<T>::Take( void )
{
	if( m_size == 0 )
	{
		GrowCapacity();
		Fill( m_capacity );

		T* ptr = m_objects[ m_size - 1 ];
		if( m_size != 0 )
			-- m_size;

		return ptr;
	}
	else
	{
		T* ptr = m_objects[ m_size - 1 ];
		if( m_size != 0 )
			-- m_size;

		return ptr;
	}
}

template< class T >
void CachePool<T>::Clear( void )
{
	if( m_objects )
	{
		for( size_t i = 0; i < m_size; ++i )
		{
			free( m_objects[i] );
		}

		free( m_objects );
		m_objects = nullptr;
		m_size = 0;
		m_capacity = 0;
	}
}

template< class T >
size_t CachePool<T>::Size( void ) const
{
	return m_size;
}

template< class T >
bool CachePool<T>::Empty( void ) const
{
	return m_size == 0
}

template< class T >
void CachePool<T>::GrowCapacity( void )
{
	if( m_objects )
	{
		if( m_size == m_capacity )
		{
			GrowCapacity( m_capacity );
		}
	}
	else
	{
		GrowCapacity( 32 );
	}
}

template< class T >
void CachePool<T>::GrowCapacity( size_t size )
{
	if( size == 0 )
		return;

	if( m_objects )
	{
		m_capacity += size;
		m_objects = static_cast< T** >( realloc( m_objects, m_capacity * sizeof( T* ) ) );
	}
	else
	{
		m_capacity = size;
		m_objects = static_cast< T** >( malloc( size * sizeof( T* ) ) );
	}

	if( m_objects == nullptr )
	{
		throw std::bad_alloc();
	}
}