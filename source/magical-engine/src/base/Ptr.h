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

NS_MAGICAL_BEGIN

using ::std::nullptr_t;

template< class T >
class Ptr;
class Reference;

template< class T >
class Initializer
{
public:
	Initializer( T* ref );

private:
	template< class T >
	friend class Ptr;
	T* m_reference = nullptr;
};

template< class T >
class Ptr
{
public:
	Ptr( void );
	Ptr( nullptr_t nt );
	Ptr( T* rhs );
	Ptr( Ptr<T>& rhs );
	Ptr( Ptr<T>&& rhs );
	Ptr( Initializer<T>& ir );
	Ptr( Initializer<T>&& ir );
	~Ptr( void );

	template< class Tz >
	Ptr( Ptr<Tz>& rhs );
	template< class Tz >
	Ptr( Ptr<Tz>&& rhs );

public:
	void reset( void );
	void set( nullptr_t nt );
	void set( T* rhs );
	void set( Ptr<T>& rhs );
	void set( Ptr<T>&& rhs );
	void set( Initializer<T>& ir );
	T* get( void ) const;
	T* take( void );
	Ptr<T> share( void ) const;
	
	template< class Tz > 
	void set( Ptr<Tz>& rhs );
	template< class Tz > 
	void set( Ptr<Tz>&& rhs );
	template< class Tz > 
	Tz* get( void ) const;
	template< class Tz > 
	Tz* take( void );
	template< class Tz >
	Ptr<Tz> share( void ) const;

public:
	Ptr<T>& operator=( nullptr_t nt );
	Ptr<T>& operator=( T* rhs );
	Ptr<T>& operator=( Ptr<T>& rhs );
	Ptr<T>& operator=( Ptr<T>&& rhs );
	T* operator->( void ) const;
	bool operator==( const Ptr<T>& rhs ) const;
	bool operator!=( const Ptr<T>& rhs ) const;
	bool operator==( nullptr_t nt ) const;
	bool operator!=( nullptr_t nt ) const;

protected:
	T* m_reference = nullptr;
};

#include "Ptr.inl"

NS_MAGICAL_END

#endif //__PTR_H__