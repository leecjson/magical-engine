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
#ifndef __VEC3_H__
#define __VEC3_H__

struct Mat4;

struct Vec3
{
public:
	static const Vec3 Zero;
	static const Vec3 One;
	static const Vec3 Up;
	static const Vec3 Down;
	static const Vec3 Right;
	static const Vec3 Left;
	static const Vec3 Forward;
	static const Vec3 Back;

	static Vec3 placeholder;
	static Vec3 temp;

public:
	float x;
	float y;
	float z;

	Vec3( const float x, const float y, const float z );
	Vec3( const Vec3& v );
	Vec3( void );

	static void* operator new( size_t s );
	static void operator delete( void* ptr );

	inline bool operator==( const Vec3& v ) const;
	inline bool operator!=( const Vec3& v ) const;
	inline bool isEquals( const Vec3& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline bool isNormalize( void ) const;

	inline Vec3 operator+( const float a ) const;
	inline Vec3 operator+( const Vec3& v ) const;
	inline Vec3 operator-( const float a ) const;
	inline Vec3 operator-( const Vec3& v ) const;
	inline Vec3 operator*( const Mat4& m ) const;
	inline Vec3 operator*( const float a ) const;
	inline Vec3 operator*( const Vec3& v ) const;
	inline Vec3 operator/( const float a ) const;
	inline Vec3 operator/( const Vec3& v ) const;
	inline Vec3& operator+=( const float a );
	inline Vec3& operator+=( const Vec3& v );
	inline Vec3& operator-=( const float a );
	inline Vec3& operator-=( const Vec3& v );
	inline Vec3& operator*=( const Mat4& m );
	inline Vec3& operator*=( const float a );
	inline Vec3& operator*=( const Vec3& v );
	inline Vec3& operator/=( const float a );
	inline Vec3& operator/=( const Vec3& v );
	inline Vec3& operator=( const Vec3& v );
	
	inline Vec3 add( const float a ) const;
	inline Vec3 add( const Vec3& v ) const;
	inline Vec3 sub( const float a ) const;
	inline Vec3 sub( const Vec3& v ) const;
	inline Vec3 mul( const Mat4& m ) const;
	inline Vec3 mul( const float a ) const;
	inline Vec3 mul( const Vec3& v ) const;
	inline Vec3 div( const float a ) const;
	inline Vec3 div( const Vec3& v ) const;
	inline void addfill( const float a );
	inline void addfill( const Vec3& v );
	inline void subfill( const float a );
	inline void subfill( const Vec3& v );
	inline void mulfill( const Mat4& m );
	inline void mulfill( const float a );
	inline void mulfill( const Vec3& v );
	inline void divfill( const float a );
	inline void divfill( const Vec3& v );

	inline void fill( const float x, const float y, const float z );
	inline void fill( const Vec3& v );
	inline void fillZero( void );
	inline void fillOne( void );
	
	inline float dot( const Vec3& v ) const;
	inline float distanceBetween( const Vec3& v ) const;
	inline float distanceBetweenSq( const Vec3& v ) const;
	inline float length( void ) const;
    inline float lengthSq( void ) const;
	inline float angleBetween( const Vec3& v ) const;

	inline Vec3 cross( const Vec3& v ) const;
	inline void fillCross( const Vec3& v );
	inline Vec3 clamp( const Vec3& min, const Vec3& max ) const;
	inline void fillClamp( const Vec3& min, const Vec3& max );
	inline Vec3 negate( void ) const;
	inline void fillNegate( void );
	inline Vec3 normalize( void ) const;
	inline void fillNormalize( void );
	inline Vec3 scale( const float s ) const;
	inline void fillScale( const float s );
	inline Vec3 midPointBetween( const Vec3& point ) const;
	inline void project( Vec3& h, Vec3& v, const Vec3& n ) const;
};

class MathVec3
{
public:
	static inline void add( Vec3& out, const Vec3& v, const float a );
	static inline void add( Vec3& out, const Vec3& v1, const Vec3& v2 );
	static inline void sub( Vec3& out, const Vec3& v, const float a );
	static inline void sub( Vec3& out, const Vec3& v1, const Vec3& v2 );
	static inline void mul( Vec3& out, const Vec3& v, const Mat4& m );
	static inline void mul( Vec3& out, const Vec3& v, const float a );
	static inline void mul( Vec3& out, const Vec3& v1, const Vec3& v2 );
	static inline void div( Vec3& out, const Vec3& v, const float a );
	static inline void div( Vec3& out, const Vec3& v1, const Vec3& v2 );

	static inline void cross( Vec3& out, const Vec3& v1, const Vec3& v2 );
	static inline void clamp( Vec3& out, const Vec3& v, const Vec3& min, const Vec3& max );
	static inline void negate( Vec3& out, const Vec3& v );
	static inline void normalize( Vec3& out, const Vec3& v );
	static inline void scale( Vec3& out, const Vec3& v, const float s );
	static inline void midPointBetween( Vec3& out, const Vec3& v1, const Vec3& v2 );
};

#include "../c/cVec3.h"
#include "../c/cMat4.h"
#include "Vec3.inl"

#endif //__VEC3_H__