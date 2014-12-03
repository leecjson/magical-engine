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

class Vec3;
class Vec4;

class Vec2
{
public:
	float x;
	float y;

public:
	static const Vec2 Zero;
	static const Vec2 One;
	static const Vec2 Right;
	static const Vec2 Left;
	static const Vec2 Up;
	static const Vec2 Down;
	static Vec2 placeholder;
	static Vec2 temp;

public:
	Vec2( const Vec4& v );
	Vec2( const Vec3& v );
	Vec2( const Vec2& v );
	Vec2( const float x, const float y );
	Vec2( void );

public:
	static inline Vec2 fromVec3( const Vec3& v );
	static inline Vec2 fromVec4( const Vec4& v );

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
	static inline void rotate( Vec2& out, const Vec2& v, const float angle );
	static inline void scale( Vec2& out, const Vec2& v, const float s );
	static inline void midPointBetween( Vec2& out, const Vec2& v1, const Vec2& v2 );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Vec2& v ) const;
	inline bool operator!=( const Vec2& v ) const;
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

public:
	inline bool isEquals( const Vec2& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline bool isNormalize( void ) const;
	inline void fill( const Vec2& v );
	inline void fill( const float x, const float y );
	inline void fillZero( void );
	inline void fillOne( void );
	inline void fillVec3( const Vec3& v );
	inline void fillVec4( const Vec3& v );

	inline void clamp( const Vec2& min, const Vec2& max );
	inline void negate( void );
	inline void normalize( void );
	inline void rotate( const float angle );
	inline void scale( const float s );
	inline void midPointBetween( const Vec2& point );
	inline void project( Vec2& h, Vec2& v, const Vec2& n ) const;

	inline Vec2 getClamp( const Vec2& min, const Vec2& max ) const;
	inline Vec2 getNegate( void ) const;
	inline Vec2 getNormalize( void ) const;
	inline Vec2 getRotate( const float angle ) const;
	inline Vec2 getScale( const float s ) const;
	inline Vec2 getMidPointBetween( const Vec2& point ) const;

	inline float dot( const Vec2& v ) const;
	inline float distanceBetween( const Vec2& v ) const;
	inline float distanceBetweenSq( const Vec2& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline float angleBetween( const Vec2& v ) const;
};

#include "../c/cVec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Vec2.inl"

#endif //__VEC2_H__