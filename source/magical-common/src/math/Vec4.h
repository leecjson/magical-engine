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
#ifndef __VEC4_HPP__
#define __VEC4_HPP__

#include "PlatformMacros.h"
#include "Common.h"
#include "Math3D.h"

struct Vec4
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	Vec4( float rx, float ry, float rz, float rw );
	Vec4( const Vec4& rhs );
	Vec4( void );

	inline Vec4  operator+( float rhs ) const;
	inline Vec4  operator+( const Vec4& rhs ) const;
	inline Vec4  operator-( float rhs ) const;
	inline Vec4  operator-( const Vec4& rhs ) const;
	inline Vec4  operator*( float rhs ) const;
	inline Vec4  operator*( const Vec4& rhs ) const;
	inline Vec4  operator/( float rhs ) const;
	inline Vec4  operator/( const Vec4& rhs ) const;
	inline Vec4& operator=( const Vec4& rhs );
	inline Vec4& operator+=( const Vec4& rhs );
	inline Vec4& operator+=( float rhs );
	inline Vec4& operator-=( const Vec4& rhs );
	inline Vec4& operator-=( float rhs );
	inline Vec4& operator*=( const Vec4& rhs );
	inline Vec4& operator*=( float rhs  );
	inline Vec4& operator/=( const Vec4& rhs );
	inline Vec4& operator/=( float rhs );
	inline bool  operator==( const Vec4& rhs ) const;
	inline bool  operator!=( const Vec4& rhs ) const;
	inline bool  isZero( void ) const;
	inline bool  isOne( void ) const;

public:
	inline void  fill( float rx, float ry, float rz, float rw );
	inline void  fill( const float* rhs );
	inline void  fill( const Vec4& rhs );
	inline void  fillZero( void );
	inline Vec4  copy( void ) const;
	inline void  negate( void );
	inline void  normalize( void );
	inline void  clamp( const Vec4& min, const Vec4& max );
	inline float angle( const Vec4& rhs ) const;
	inline float dot( const Vec4& v ) const;
	inline float distance( const Vec4& v ) const;
	inline float distanceSq( const Vec4& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	
public:
	static const Vec4 Zero;
	static const Vec4 One;
};

class MathVec4
{
public:
	static inline Vec4 add( const Vec4& lhs, float rhs );
	static inline Vec4 add( const Vec4& lhs, const Vec4& rhs );
	static inline Vec4 sub( const Vec4& lhs, float rhs );
	static inline Vec4 sub( const Vec4& lhs, const Vec4& rhs );
	static inline Vec4 mul( const Vec4& lhs, float rhs );
	static inline Vec4 mul( const Vec4& lhs, const Vec4& rhs );
	static inline Vec4 div( const Vec4& lhs, float rhs );
	static inline Vec4 div( const Vec4& lhs, const Vec4& rhs );
	static inline bool equals( const Vec4& v1, const Vec4& v2 );
	static inline bool isZero( const Vec4& v );
	static inline bool isOne( const Vec4& v );

	static inline Vec4  copy( const Vec4& v );
	static inline Vec4  fill( float rx, float ry, float rz, float rw );
	static inline Vec4  fill( const Vec4& rhs );
	static inline Vec4  fillZero( void );
	static inline Vec4  fillOne( void );
	static inline Vec4  negate( const Vec4& v );
	static inline Vec4  normalize( const Vec4& v );
	static inline Vec4  clamp( const Vec4& v, const Vec4& min, const Vec4& max );
	static inline float angle( const Vec4& v, const Vec4& rhs );
	static inline float dot( const Vec4& v1, const Vec4& v2 );
	static inline float distance( const Vec4& v1, const Vec4& v2 );
	static inline float distanceSq( const Vec4& v1, const Vec4& v2 );
	static inline float length( const Vec4& v );
	static inline float lengthSq( const Vec4& v );
};

#include "Vec4.inl"
	
#endif //__VEC4_HPP__