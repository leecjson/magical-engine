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
#include "kazmath/kazmath.h"
#include "Mat3.hpp"

struct Mat3;

struct Vec2 : public kmVec2
{
public:
	Vec2( float rx, float ry );
	Vec2( void );

	inline Vec2 operator+( float rhs ) const;
	inline Vec2 operator+( const Vec2& rhs ) const;
	inline Vec2 operator-( float rhs ) const;
	inline Vec2 operator-( const Vec2& rhs ) const;
	inline Vec2 operator*( float rhs ) const;
	inline Vec2 operator*( const Vec2& rhs ) const;
	inline Vec2 operator/( float rhs ) const;
	inline Vec2 operator/( const Vec2& rhs ) const;

	inline Vec2& operator+=( const Vec2& rhs );
	inline Vec2& operator+=( float rhs );
	inline Vec2& operator-=( const Vec2& rhs );
	inline Vec2& operator-=( float rhs );
	inline Vec2& operator*=( const Vec2& rhs );
	inline Vec2& operator*=( float rhs );
	inline Vec2& operator/=( const Vec2& rhs );
	inline Vec2& operator/=( float rhs );

	inline bool operator==( const Vec2& rhs ) const;
	inline bool operator!=( const Vec2& rhs ) const;

	inline bool isZero( void ) const;

public:
	static inline Vec2  fill( float x, float y );
	static inline float length( const Vec2& v );
	static inline float lengthSq( const Vec2& v );
	static inline Vec2  normalize( const Vec2& v );
	static inline Vec2  lerp( const Vec2& v1, const Vec2& v2, float t );
	static inline float dot( const Vec2& v1, const Vec2& v2 );
	static inline float cross( const Vec2& v1, const Vec2& v2 );
	static inline Vec2  transform( const Vec2& v, const Mat3& m );
	static inline Vec2  transformCoord( const Vec2& v, const Mat3& m );
	static inline Vec2  scale( const Vec2& v, const float s );
	static inline Vec2  rotateBy( const Vec2& v, const float degrees, const Vec2& center );
	static inline float degreesBetween( const Vec2& v1, const Vec2& v2 );
	static inline float distanceBetween( const Vec2& v1, const Vec2& v2 );
	static inline Vec2  midPointBetween( const Vec2& v1, const Vec2& v2 );

public:
	static const Vec2 ZERO;
};

#include "Vec2.inl"

#endif //__VEC2_HPP__