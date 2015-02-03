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
	growCapacity( 32 );
}

template< class T >
CachePool<T>::CachePool( size_t capacity )
{
	growCapacity( capacity );
}

template< class T >
CachePool<T>::CachePool( size_t capacity, size_t fillsize )
{
	growCapacity( capacity );
	fill( fillsize );
}

template< class T >
CachePool<T>::~CachePool( void )
{
	clear();
}

template< class T >
void CachePool<T>::fill( size_t size )
{
	size_t obj_size = sizeof( T );

	if( obj_size == 0 )
		obj_size = 1;

	for( size_t i = 0; i < size; ++i )
	{
		growCapacity();
		T* ptr = static_cast< T* >( malloc( obj_size ) );

		if( ptr == nullptr )
			throw std::bad_alloc();

		m_objects[ m_size ] = ptr;
		m_size += 1;
	}
}

template< class T >
void CachePool<T>::push( void* ptr )
{
	growCapacity();

	m_objects[ m_size ] = static_cast< T* >( ptr );
	m_size += 1;
}

template< class T >
void* CachePool<T>::take( void )
{
	if( m_size == 0 )
	{
		growCapacity();
		fill( m_capacity );

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
void CachePool<T>::clear( void )
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
size_t CachePool<T>::size( void ) const
{
	return m_size;
}

template< class T >
bool CachePool<T>::empty( void ) const
{
	return m_size == 0
}

template< class T >
void CachePool<T>::growCapacity( void )
{
	if( m_objects )
	{
		if( m_size == m_capacity )
		{
			growCapacity( m_capacity );
		}
	}
	else
	{
		growCapacity( 32 );
	}
}

template< class T >
void CachePool<T>::growCapacity( size_t size )
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