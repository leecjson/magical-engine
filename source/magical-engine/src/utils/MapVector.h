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
#ifndef __MAP_VECTOR_H__
#define __MAP_VECTOR_H__

#include "magical-macros.h"
#include "Common.h"
#include "Vector.h"

NAMESPACE_MAGICAL

template< class Ty1, class Ty2 >
using Pair = std::pair< Ty1, Ty2 >;

template< class TyKey, class TyValue >
class MapVector
{
public:
	typedef typename TyKey key_type;
	typedef typename TyValue mapped_type;

	typedef typename Vector< Pair<TyKey, TyValue> >::value_type value_type;
	typedef typename Vector< Pair<TyKey, TyValue> >::size_type size_type;
	typedef typename Vector< Pair<TyKey, TyValue> >::reference reference;
	typedef typename Vector< Pair<TyKey, TyValue> >::const_reference const_reference;
	typedef typename Vector< Pair<TyKey, TyValue> >::iterator iterator;
	typedef typename Vector< Pair<TyKey, TyValue> >::const_iterator const_iterator;
	typedef typename Vector< Pair<TyKey, TyValue> >::reverse_iterator reverse_iterator;
	typedef typename Vector< Pair<TyKey, TyValue> >::const_reverse_iterator const_reverse_iterator;

public:
	iterator begin( void ) { return m_vec.begin(); }
	iterator end( void ) { return m_vec.end(); }
	const_iterator begin( void ) const { return m_vec.begin(); }
	const_iterator end( void ) const { return m_vec.end(); }
	const_iterator cbegin( void ) const { return m_vec.cbegin(); }
	const_iterator cend( void ) const { return m_vec.cend(); }
	reverse_iterator rbegin( void ) { return m_vec.rbegin(); }
	reverse_iterator rend( void ) { return m_vec.rend(); }
	const_reverse_iterator rbegin( void ) const { return m_vec.rbegin(); }
	const_reverse_iterator rend( void ) const { return m_vec.rend(); }
	const_reverse_iterator crbegin( void ) const { return m_vec.crbegin(); }
	const_reverse_iterator crend( void ) const { return m_vec.crend(); }

public:
	const_iterator at( size_t index ) const { return m_vec.at( index ); }
	iterator at( size_t index ) { return m_vec.at( index ); }
	void reserve( size_t count ) { m_vec.reserve( count ); }
	void reverse( void ) { std::reverse( std::begin( m_vec ), std::end( m_vec ) ); }
	void resize( size_t size ) { m_vec.resize( size ); }
	size_t capacity( void ) const { return m_vec.capacity(); }
	size_t size( void ) const { return m_vec.size(); }
	bool empty( void ) const { return m_vec.empty(); }
	void clear( void ) { m_vec.clear(); }
	const_reference front( void ) const { return m_vec.front(); }
	reference front( void ) { return m_vec.front(); }
	const_reference back( void ) const { return m_vec.back(); }
	reference back( void ) { return m_vec.back(); }
	void pop_back( void ) { m_vec.pop_back(); }
	iterator erase( const_iterator pos ) { return m_vec.erase( pos ); }
	iterator erase( const_iterator first, const_iterator last ) { return m_vec.erase( first, last ); }
	void push_back( const value_type& val ) { m_vec.push_back( val ); }
	void push_back( value_type&& val ) { m_vec.push_back( std::forward<value_type>( val ) ); }
	const_reference operator[]( size_type index ) const { return m_vec[ index ]; }
	reference operator[]( size_type index ) { return m_vec[ index ]; }

public:
	const_iterator find( const key_type& key ) const
	{
		size_type i = 0;
		size_type size = m_vec.size(); 
		for( ; i < size; ++ i )
		{
			if( m_vec[i].first == key )
				return begin() + i;
		}
		return end();
	}

	iterator find( const key_type& key )
	{
		size_type i = 0;
		size_type size = m_vec.size(); 
		for( ; i < size; ++ i )
		{
			if( m_vec[i].first == key )
				return begin() + i;
		}
		return end();
	}

	void push_back_unique( const value_type& val )
	{
		iterator itr = find( val.first );
		MAGICAL_ASSERT( itr == end(), "key exists" );

		if( itr != end() )
			return;

		m_vec.push_back( val );
	}

	void push_back_unique( value_type&& val )
	{
		iterator itr = find( val.first );
		MAGICAL_ASSERT( itr == end(), "key exists" );

		if( itr != end() )
			return;

		m_vec.push_back( std::forward<value_type>( val ) );
	}
	
	iterator erase( size_t index )
	{
		MAGICAL_ASSERT( m_vec.empty() == false, "Invalid! empty vector." );
		MAGICAL_ASSERT( index >= 0 && index < size(), "Invalid index!" );

		return m_vec.erase( std::next( begin(), index ) );
	}

	//mapped_type& operator[]( const key_type& key )
	//{
	//	iterator itr = find( val.first );
	//	if( itr != end() )
	//		return itr->second;

	//	push_back( std::make_pair( key, mapped_type() ) );
	//	return back().second;
	//}

private:
	Vector< Pair<TyKey, TyValue> > m_vec;
};

NAMESPACE_END

#endif //__MAP_VECTOR_H__