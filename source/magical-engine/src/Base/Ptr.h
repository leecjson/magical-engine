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
	member_inline Ptr( void );
	member_inline Ptr( T* rhs );
	member_inline Ptr( Ptr<T>& rhs );
	member_inline Ptr( Ptr<T>&& rhs );
	member_inline Ptr( PtrCtor<T>& rhs );
	member_inline Ptr( PtrCtor<T>&& rhs );
	member_inline Ptr( nullptr_t rhs );
	template< class Tz > 
	member_inline Ptr( Ptr<Tz>& rhs );
	template< class Tz > 
	member_inline Ptr( Ptr<Tz>&& rhs );
	member_inline ~Ptr( void );

public:
	member_inline void Set( T* rhs );
	member_inline void Set( Ptr<T>& rhs );
	member_inline void Set( Ptr<T>&& rhs );
	member_inline void Set( PtrCtor<T>& rhs );
	member_inline void Set( PtrCtor<T>&& rhs );
	member_inline void Set( nullptr_t rhs );

	template< class Tz > 
	member_inline void Set( Ptr<Tz>& rhs );
	template< class Tz > 
	member_inline void Set( Ptr<Tz>&& rhs );

	member_inline void Reset( void );
	member_inline T* Take( void );
	member_inline T* Get( void ) const;

	template< class Tz > 
	member_inline Tz* StaticCastTo( void ) const;
	template< class Tz > 
	member_inline Tz* DynamicCastTo( void ) const;

public:
	member_inline Ptr<T>& operator=( nullptr_t rhs );
	member_inline Ptr<T>& operator=( T* rhs );
	member_inline Ptr<T>& operator=( Ptr<T>& rhs );
	member_inline Ptr<T>& operator=( Ptr<T>&& rhs );
	member_inline T* operator->( void ) const;
	member_inline bool operator==( const Ptr<T>& rhs ) const;
	member_inline bool operator!=( const Ptr<T>& rhs ) const;
	member_inline bool operator==( nullptr_t rhs ) const;
	member_inline bool operator!=( nullptr_t rhs ) const;

protected:
	T* m_reference = nullptr;
};

#include "Ptr.inl"

NS_MAGICAL_END

#endif //__PTR_H__