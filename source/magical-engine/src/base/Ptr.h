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

class Reference;
template< class T >
class Ptr;
template< class T >
class PtrCtor;

template< class T >
class PtrCtor
{
public:
	PtrCtor( T* rhs );

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
	Ptr( T* rhs );
	Ptr( Ptr<T>& rhs );
	Ptr( Ptr<T>&& rhs );
	Ptr( PtrCtor<T>& rhs );
	Ptr( PtrCtor<T>&& rhs );
	Ptr( nullptr_t rhs );
	template< class Tz >
	Ptr( Ptr<Tz>& rhs );
	template< class Tz >
	Ptr( Ptr<Tz>&& rhs );
	~Ptr( void );

public:
	void reset( void );
	void set( T* rhs );
	void set( Ptr<T>& rhs );
	void set( Ptr<T>&& rhs );
	void set( PtrCtor<T>& rhs );
	void set( PtrCtor<T>&& rhs );
	void set( nullptr_t rhs );
	template< class Tz > 
	void set( Ptr<Tz>& rhs );
	template< class Tz > 
	void set( Ptr<Tz>&& rhs );
	T* get( void ) const;
	T* take( void );
	template< class Tz >
	Tz* static_cast_to( void ) const;
	template< class Tz >
	Tz* dynamic_cast_to( void ) const;

public:
	Ptr<T>& operator=( nullptr_t rhs );
	Ptr<T>& operator=( T* rhs );
	Ptr<T>& operator=( Ptr<T>& rhs );
	Ptr<T>& operator=( Ptr<T>&& rhs );
	T* operator->( void ) const;
	bool operator==( const Ptr<T>& rhs ) const;
	bool operator!=( const Ptr<T>& rhs ) const;
	bool operator==( nullptr_t rhs ) const;
	bool operator!=( nullptr_t rhs ) const;

protected:
	T* m_reference = nullptr;
};

#include "Ptr.inl"

NS_MAGICAL_END

#endif //__PTR_H__