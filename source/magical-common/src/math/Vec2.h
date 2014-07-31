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
#ifndef __VEC2_HPP__
#define __VEC2_HPP__

#include "PlatformMacros.h"
#include "Common.h"
#include "Math3D.h"

struct Vec2
{
public:
	float x;
	float y;

public:
	Vec2( float rx, float ry );
	Vec2( const float* rhs );
	Vec2( const Vec2& rhs );
	Vec2( void );

	inline Vec2  operator+( float rhs ) const;
	inline Vec2  operator+( const Vec2& rhs ) const;
	inline Vec2  operator-( float rhs ) const;
	inline Vec2  operator-( const Vec2& rhs ) const;
	inline Vec2  operator*( float rhs ) const;
	inline Vec2  operator*( const Vec2& rhs ) const;
	inline Vec2  operator/( float rhs ) const;
	inline Vec2  operator/( const Vec2& rhs ) const;
	inline Vec2& operator=( const Vec2& rhs );
	inline Vec2& operator+=( const Vec2& rhs );
	inline Vec2& operator+=( float rhs );
	inline Vec2& operator-=( const Vec2& rhs );
	inline Vec2& operator-=( float rhs );
	inline Vec2& operator*=( const Vec2& rhs );
	inline Vec2& operator*=( float rhs );
	inline Vec2& operator/=( const Vec2& rhs );
	inline Vec2& operator/=( float rhs );
	inline bool  operator==( const Vec2& rhs ) const;
	inline bool  operator!=( const Vec2& rhs ) const;
	inline bool  isZero( void ) const;

	inline Vec2  copy( void ) const;
	inline void  fill( float rx, float ry );
	inline void  fill( const float* rhs );
	inline void  fill( const Vec2& rhs );
	inline void  fillZero( void );
	inline void  clamp( const Vec2& min, const Vec2& max );
	inline float distance( const Vec2& v ) const;
    inline float distanceSq( const Vec2& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline float dot( const Vec2& v ) const;
	inline float angle( void ) const;
	inline void  negate( void );
	inline void  normalize( void );
	inline void  rotate( const Vec2& point, float angle );
	inline void  middle( const Vec2& rhs );

public:
	static const Vec2 ZERO;
};

class Mathv2
{
public:
	static inline Vec2 add( const Vec2& v1, const Vec2& v2 );
	static inline Vec2 add( const Vec2& v1, float rhs );
	static inline Vec2 sub( const Vec2& v1, const Vec2& v2 );
	static inline Vec2 sub( const Vec2& v1, float rhs );
	static inline Vec2 mul( const Vec2& v1, const Vec2& v2 );
	static inline Vec2 mul( const Vec2& v1, float rhs );
	static inline Vec2 div( const Vec2& v1, const Vec2& v2 );
	static inline Vec2 div( const Vec2& v1, float rhs );
	static inline bool equals( const Vec2& v1, const Vec2& v2 );

	static inline Vec2  copy( const Vec2& rhs );
	static inline Vec2  fill( float rx, float ry );
	static inline Vec2  fill( const float* rhs );
	static inline Vec2  fill( const Vec2& rhs );
	static inline Vec2  fillZero( void );
	static inline Vec2  clamp( const Vec2& lhs, const Vec2& min, const Vec2& max );
	static inline float distance( const Vec2& lhs, const Vec2& v );
    static inline float distanceSq( const Vec2& lhs, const Vec2& v );
	static inline float length( const Vec2& lhs );
	static inline float lengthSq( const Vec2& lhs );
	static inline float dot( const Vec2& lhs, const Vec2& v );
	static inline float angle( const Vec2& v );
	static inline Vec2  negate( const Vec2& v );
	static inline Vec2  normalize( const Vec2& v );
	static inline Vec2  rotate( const Vec2& lhs, const Vec2& point, float angle );
	static inline Vec2  middle( const Vec2& lhs, const Vec2& rhs );
};

#include "Vec2.inl"

#endif //__VEC2_HPP__