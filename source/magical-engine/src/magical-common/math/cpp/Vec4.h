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
#ifndef __VEC4_H__
#define __VEC4_H__

class Vec2;
class Vec3;
class Mat4;

class Vec4
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	static const Vec4 Zero;
	static const Vec4 One;
	static const Vec4 Up;
	static const Vec4 Down;
	static const Vec4 Right;
	static const Vec4 Left;
	static const Vec4 Forward;
	static const Vec4 Back;
	static const Vec4 Space1;
	static Vec4 placeholder;
	static Vec4 temp;

public:
	Vec4( const Vec2& v );
	Vec4( const Vec3& v );
	Vec4( const Vec4& v );
	Vec4( const float x, const float y, const float z, const float w );
	Vec4( void );

public:
	static inline Vec4 fromVec2( const Vec2& v );
	static inline Vec4 fromVec3( const Vec3& v );

	static inline void add( Vec4& out, const Vec4& v, const float a );
	static inline void add( Vec4& out, const Vec4& v1, const Vec4& v2 );
	static inline void sub( Vec4& out, const Vec4& v, const float a );
	static inline void sub( Vec4& out, const Vec4& v1, const Vec4& v2 );
	static inline void mul( Vec4& out, const Vec4& v, const Mat4& m );
	static inline void mul( Vec4& out, const Vec4& v, const float a );
	static inline void mul( Vec4& out, const Vec4& v1, const Vec4& v2 );
	static inline void div( Vec4& out, const Vec4& v, const float a );
	static inline void div( Vec4& out, const Vec4& v1, const Vec4& v2 );

	static inline void clamp( Vec4& out, const Vec4& v, const Vec4& min, const Vec4& max );
	static inline void negate( Vec4& out, const Vec4& v );
	static inline void normalize( Vec4& out, const Vec4& v );
	static inline void scale( Vec4& out, const Vec4& v, const float s );
	static inline void midPointBetween( Vec4& out, const Vec4& v1, const Vec4& v2 );
	
public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Vec4& v ) const;
	inline bool operator!=( const Vec4& v ) const;
	inline Vec4 operator+( const float a ) const;
	inline Vec4 operator+( const Vec4& v ) const;
	inline Vec4 operator-( const float a ) const;
	inline Vec4 operator-( const Vec4& v ) const;
	inline Vec4 operator*( const Mat4& m ) const;
	inline Vec4 operator*( const float a ) const;
	inline Vec4 operator*( const Vec4& v ) const;
	inline Vec4 operator/( const float a ) const;
	inline Vec4 operator/( const Vec4& v ) const;
	inline Vec4& operator+=( const float a );
	inline Vec4& operator+=( const Vec4& v );
	inline Vec4& operator-=( const float a );
	inline Vec4& operator-=( const Vec4& v );
	inline Vec4& operator*=( const Mat4& m );
	inline Vec4& operator*=( const float a );
	inline Vec4& operator*=( const Vec4& v );
	inline Vec4& operator/=( const float a );
	inline Vec4& operator/=( const Vec4& v );
	inline Vec4& operator=( const Vec4& v );

public:
	inline bool isEquals( const Vec4& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline bool isNormalize( void ) const;
	inline void fill( const float x, const float y, const float z, const float w );
	inline void fill( const Vec4& v );
	inline void fillZero( void );
	inline void fillOne( void );
	inline void fillVec2( const Vec2& v );
	inline void fillVec3( const Vec3& v );

	inline void clamp( const Vec4& min, const Vec4& max );
	inline void negate( void );
	inline void normalize( void );
	inline void scale( const float s );
	inline void midPointBetween( const Vec4& point );
	inline void project( Vec4& h, Vec4& v, const Vec4& n ) const;

	inline Vec4 getClamp( const Vec4& min, const Vec4& max ) const;
	inline Vec4 getNegate( void ) const;
	inline Vec4 getNormalize( void ) const;
	inline Vec4 getScale( const float s ) const;
	inline Vec4 getMidPointBetween( const Vec4& point ) const;
	
	inline float dot( const Vec4& v ) const;
	inline float distanceBetween( const Vec4& v ) const;
	inline float distanceBetweenSq( const Vec4& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline float angleBetween( const Vec4& v ) const;
};

#include "../c/cVec4.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Mat4.h"
#include "Vec4.inl"
	
#endif //__VEC4_H__