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
#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <vector>

#include "PlatformMacros.h"
#include "Common.h"

template< class T >
using Array = std::vector< T >;
 

#if 0
template< class T >
class Array
{
public:
	typedef typename std::vector<T>::iterator iterator;
	typedef typename std::vector<T>::const_iterator const_iterator;
	typedef typename std::vector<T>::reverse_iterator reverse_iterator;
	typedef typename std::vector<T>::const_reverse_iterator const_reverse_iterator;
	iterator begin( void ) { return _data.begin(); }
	iterator end( void ) { return _data.end(); }
	const_iterator begin( void ) const { return _data.begin(); }
	const_iterator end( void ) const { return _data.end(); }
	const_iterator cbegin( void ) const { return _data.cbegin(); }
	const_iterator cend( void ) const { return _data.cend(); }
	reverse_iterator rbegin( void ) { return _data.rbegin(); }
	reverse_iterator rend( void ) { return _data.rend(); }
	const_reverse_iterator rbegin( void ) const { return _data.rbegin(); }
	const_reverse_iterator rend( void ) const { return _data.rend(); }
	const_reverse_iterator crbegin( void ) const { return _data.crbegin(); }
	const_reverse_iterator crend( void ) const { return _data.crend(); }

public:
	Array<T>(){};

public:
	void reserve( size_t count )
	{
		_data.reserve( count );
	}

	void reverse( void )
    {
        std::reverse( std::begin(_data), std::end(_data) );
    }

	void resize( size_t n )
	{
		_data.resize( n );
	}

	size_t capacity( void ) const
	{
		return _data.capacity();
	}

	size_t size( void ) const
	{
		return _data.size();
	}

	bool empty( void ) const
	{
		return _data.empty();
	}

	T at( size_t index ) const
    {
        magicalAssert( index >= 0 && index < size(), "index out of range" );

        return _data[index];
    }

	void set( size_t index, const T& obj )
    {
        magicalAssert( index >= 0 && index < size(), "invalid index!" );
        magicalAssert( obj != nullptr, "should not nullptr" );

        _data[index] = obj;
    }

	void clear( void )
    {
        _data.clear();
    }

	T front( void ) const
    {
        return _data.front();
    }
    
    T back( void ) const
    {
        return _data.back();
    }

	void pushBack( const T& obj )
    {
        _data.push_back( obj );
    }

	void pushBack( T&& obj )
	{
		_data.push_back( std::forward<T>(obj) );
	}
    
    void pushBack( const Array<T>& other )
    {
        for( const auto& obj : other->collection() ) 
		{
            _data.push_back(obj);
        }
    }

	void pushBack( Array<T>&& other )
	{
		for( auto&& obj : other->collection() ) 
		{
            _data.push_back( std::forward<T>(obj) );
        }
		other->clear();
	}

	void popBack( void )
    {
        magicalAssert( _data.empty() == false, "no objects exist" );
        _data.pop_back();
    }

	iterator erase( iterator position )
    {
        magicalAssert( position >= _data.begin() && position < _data.end(), "invalid position!" );
        return _data.erase( position );
    }

	iterator erase( iterator first, iterator last )
    {
        return _data.erase( first, last );
    }

	iterator erase( size_t index )
    {
        magicalAssert( (_data.empty() == false) && index >=0 && index < size(), "invalid index!" );
        auto itr = std::next( begin(), index );
        return _data.erase( itr );
    }

	void insert( size_t index, const T& obj )
    {
        magicalAssert( index >= 0 && index <= size(), "invalid index!" );
        magicalAssert( obj != nullptr, "should not nullptr" );

        _data.insert( (std::begin(_data) + index), obj );
    }

public:
	void swap( size_t index1, size_t index2 )
    {
        magicalAssert( index1 >=0 && index1 < size() && index2 >= 0 && index2 < size() , "Invalid indices");

        std::swap( _data[index1], _data[index2] );
    }

	const_iterator find( const T& obj ) const
    {
        return std::find( _data.begin(), _data.end(), obj );
    }
    
    iterator find( const T& obj )
    {
        return std::find( _data.begin(), _data.end(), obj );
    }

	size_t indexOf( const T& obj ) const
	{
		auto iter = std::find( _data.begin(), _data.end(), obj );
		if( iter != _data.end() )
		{
			return iter - _data.begin();
		}
		return -1;
	}

	bool contains( const T& obj ) const
    {
        return( std::find(_data.begin(), _data.end(), obj) != _data.end() );
    }

    bool equals( const Array<T>& other )
    {
		size_t my_size = size();

		if( my_size != other.size() )
		{
			return false;
		}
        for( size_t i = 0; i < my_size; ++i )
        {
            if( at( i ) != other.at( i ) )
            {
                return false;
            }
        }
        return true;
    }

private:
	std::vector<T> _data;
};

#endif

#endif //__ARRAY_H__