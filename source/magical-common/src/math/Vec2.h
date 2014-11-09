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

#include "Math3D.h"

struct Vec2
{
public:
	static const Vec2 Zero;
	static const Vec2 One;
	static const Vec2 Right;
	static const Vec2 Left;
	static const Vec2 Up;
	static const Vec2 Down;

public:
	float x;
	float y;

	Vec2( float x, float y );
	Vec2( const Vec2& v );
	Vec2( void );

public:
	inline bool operator==( const Vec2& v ) const;
	inline bool operator!=( const Vec2& v ) const;
	inline bool isEquals( const Vec2& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline bool isNormalize( void ) const;

public:
	inline Vec2 operator+( float a ) const;
	inline Vec2 operator+( const Vec2& v ) const;
	inline Vec2 operator-( float a ) const;
	inline Vec2 operator-( const Vec2& v ) const;
	inline Vec2 operator*( float a ) const;
	inline Vec2 operator*( const Vec2& v ) const;
	inline Vec2 operator/( float a ) const;
	inline Vec2 operator/( const Vec2& v ) const;
	inline Vec2& operator+=( float a );
	inline Vec2& operator+=( const Vec2& v );
	inline Vec2& operator-=( float a );
	inline Vec2& operator-=( const Vec2& v );
	inline Vec2& operator*=( float a );
	inline Vec2& operator*=( const Vec2& v );
	inline Vec2& operator/=( float a );
	inline Vec2& operator/=( const Vec2& v );
	inline Vec2& operator=( const Vec2& v );
	
	inline Vec2 add( float a ) const;
	inline Vec2 add( const Vec2& v ) const;
	inline Vec2 sub( float a ) const;
	inline Vec2 sub( const Vec2& v ) const;
	inline Vec2 mul( float a ) const;
	inline Vec2 mul( const Vec2& v ) const;
	inline Vec2 div( float a ) const;
	inline Vec2 div( const Vec2& v ) const;
	inline void addfill( float a );
	inline void addfill( const Vec2& v );
	inline void subfill( float a );
	inline void subfill( const Vec2& v );
	inline void mulfill( float a );
	inline void mulfill( const Vec2& v );
	inline void divfill( float a );
	inline void divfill( const Vec2& v );
	inline void fill( float x, float y );
	inline void fill( const Vec2& v );
	inline void fillZero( void );
	inline void fillOne( void );

public:
	inline float dot( const Vec2& v ) const;
	inline float distanceBetween( const Vec2& v ) const;
    inline float distanceBetweenSq( const Vec2& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline float angle( void ) const;
	inline float angleBetween( const Vec2& v ) const;
	
public:
	inline void clamp( const Vec2& min, const Vec2& max );
	inline void negate( void );
	inline void normalize( void );
	inline void rotate( const Vec2& point, float angle );

	inline Vec2 getClamp( const Vec2& min, const Vec2& max ) const;
	inline Vec2 getNegate( void ) const;
	inline Vec2 getNormalize( void ) const;
	inline Vec2 getRotate( const Vec2& point, float angle ) const;
};

class MathVec2
{
public:
	static inline void add( Vec2& out, const Vec2& v, float a );
	static inline void add( Vec2& out, const Vec2& v1, const Vec2& v2 );
	static inline void sub( Vec2& out, const Vec2& v, float a );
	static inline void sub( Vec2& out, const Vec2& v1, const Vec2& v2 );
	static inline void mul( Vec2& out, const Vec2& v, float a );
	static inline void mul( Vec2& out, const Vec2& v1, const Vec2& v2 );
	static inline void div( Vec2& out, const Vec2& v, float a );
	static inline void div( Vec2& out, const Vec2& v1, const Vec2& v2 );
	static inline void clamp( Vec2& out, const Vec2& v, const Vec2& min, const Vec2& max );
	static inline void negate( Vec2& out, const Vec2& v );
	static inline void normalize( Vec2& out, const Vec2& v );
	static inline void rotate( Vec2& out, const Vec2& v, const Vec2& point, float angle );
};

#include "Vec2.inl"

#endif //__VEC2_HPP__