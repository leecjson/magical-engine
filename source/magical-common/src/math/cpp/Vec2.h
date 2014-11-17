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
#ifndef __VEC2_H__
#define __VEC2_H__

struct Vec2
{
public:
	static const Vec2 Zero;
	static const Vec2 One;
	static const Vec2 Right;
	static const Vec2 Left;
	static const Vec2 Up;
	static const Vec2 Down;

	static Vec2 placeholder_1;
	static Vec2 placeholder_2;
	static Vec2 placeholder_3;
	static Vec2 temp;
	static Vec2 temp_1;
	static Vec2 temp_2;
	static Vec2 temp_3;
	static Vec2 temp_4;
	static Vec2 temp_5;
	static Vec2 temp_6;
	static Vec2 temp_7;
	static Vec2 temp_8;
	static Vec2 temp_9;

public:
	float x;
	float y;

	Vec2( const float x, const float y );
	Vec2( const Vec2& v );
	Vec2( void );

	static void* operator new( size_t s );
	static void operator delete( void* ptr );

	inline bool operator==( const Vec2& v ) const;
	inline bool operator!=( const Vec2& v ) const;
	inline bool isEquals( const Vec2& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline bool isNormalize( void ) const;

	inline Vec2 operator+( const float a ) const;
	inline Vec2 operator+( const Vec2& v ) const;
	inline Vec2 operator-( const float a ) const;
	inline Vec2 operator-( const Vec2& v ) const;
	inline Vec2 operator*( const float a ) const;
	inline Vec2 operator*( const Vec2& v ) const;
	inline Vec2 operator/( const float a ) const;
	inline Vec2 operator/( const Vec2& v ) const;
	inline Vec2& operator+=( const float a );
	inline Vec2& operator+=( const Vec2& v );
	inline Vec2& operator-=( const float a );
	inline Vec2& operator-=( const Vec2& v );
	inline Vec2& operator*=( const float a );
	inline Vec2& operator*=( const Vec2& v );
	inline Vec2& operator/=( const float a );
	inline Vec2& operator/=( const Vec2& v );
	inline Vec2& operator=( const Vec2& v );

	inline Vec2 add( const float a ) const;
	inline Vec2 add( const Vec2& v ) const;
	inline Vec2 sub( const float a ) const;
	inline Vec2 sub( const Vec2& v ) const;
	inline Vec2 mul( const float a ) const;
	inline Vec2 mul( const Vec2& v ) const;
	inline Vec2 div( const float a ) const;
	inline Vec2 div( const Vec2& v ) const;
	inline void addfill( const float a );
	inline void addfill( const Vec2& v );
	inline void subfill( const float a );
	inline void subfill( const Vec2& v );
	inline void mulfill( const float a );
	inline void mulfill( const Vec2& v );
	inline void divfill( const float a );
	inline void divfill( const Vec2& v );
	inline void fill( const float x, const float y );
	inline void fill( const Vec2& v );
	inline void fillZero( void );
	inline void fillOne( void );

	inline float dot( const Vec2& v ) const;
	inline float distanceBetween( const Vec2& v ) const;
	inline float distanceBetweenSq( const Vec2& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline float angleBetween( const Vec2& v ) const;

	inline Vec2 clamp( const Vec2& min, const Vec2& max ) const;
	inline void fillClamp( const Vec2& min, const Vec2& max );
	inline Vec2 negate( void ) const;
	inline void fillNegate( void );
	inline Vec2 normalize( void ) const;
	inline void fillNormalize( void );
	inline Vec2 rotate( const Vec2& point, const float angle ) const;
	inline void fillRotate( const Vec2& point, const float angle );
	inline Vec2 scale( const float s ) const;
	inline void fillScale( const float s );
	inline Vec2 midPointBetween( const Vec2& point ) const;
	inline void project( Vec2& h, Vec2& v, const Vec2& n ) const;
};

class MathVec2
{
public:
	static inline void add( Vec2& out, const Vec2& v, const float a );
	static inline void add( Vec2& out, const Vec2& v1, const Vec2& v2 );
	static inline void sub( Vec2& out, const Vec2& v, const float a );
	static inline void sub( Vec2& out, const Vec2& v1, const Vec2& v2 );
	static inline void mul( Vec2& out, const Vec2& v, const float a );
	static inline void mul( Vec2& out, const Vec2& v1, const Vec2& v2 );
	static inline void div( Vec2& out, const Vec2& v, const float a );
	static inline void div( Vec2& out, const Vec2& v1, const Vec2& v2 );

	static inline void clamp( Vec2& out, const Vec2& v, const Vec2& min, const Vec2& max );
	static inline void negate( Vec2& out, const Vec2& v );
	static inline void normalize( Vec2& out, const Vec2& v );
	static inline void rotate( Vec2& out, const Vec2& v, const Vec2& point, const float angle );
	static inline void scale( Vec2& out, const Vec2& v, const float s );
	static inline void midPointBetween( Vec2& out, const Vec2& v1, const Vec2& v2 );
};

#include "../c/cVec2.h"
#include "Vec2.inl"

#endif //__VEC2_H__