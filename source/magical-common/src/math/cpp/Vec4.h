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

#include "MathMacros.h"

struct Vec4
{
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

	static Vec4 placeholder_1;
	static Vec4 placeholder_2;
	static Vec4 placeholder_3;
	static Vec4 temp_1;
	static Vec4 temp_2;
	static Vec4 temp_3;
	static Vec4 temp_4;
	static Vec4 temp_5;
	static Vec4 temp_6;
	static Vec4 temp_7;
	static Vec4 temp_8;
	static Vec4 temp_9;

public:
	float x;
	float y;
	float z;
	float w;

	Vec4( float x, float y, float z, float w );
	Vec4( const Vec4& v );
	Vec4( void );

public:
	inline bool operator==( const Vec4& v ) const;
	inline bool operator!=( const Vec4& v ) const;
	inline bool isEquals( const Vec4& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline bool isNormalize( void ) const;

	inline Vec4 operator+( float a ) const;
	inline Vec4 operator+( const Vec4& v ) const;
	inline Vec4 operator-( float a ) const;
	inline Vec4 operator-( const Vec4& v ) const;
	inline Vec4 operator*( float a ) const;
	inline Vec4 operator*( const Vec4& v ) const;
	inline Vec4 operator/( float a ) const;
	inline Vec4 operator/( const Vec4& v ) const;
	inline Vec4& operator+=( float a );
	inline Vec4& operator+=( const Vec4& v );
	inline Vec4& operator-=( float a );
	inline Vec4& operator-=( const Vec4& v );
	inline Vec4& operator*=( float a  );
	inline Vec4& operator*=( const Vec4& v );
	inline Vec4& operator/=( float a );
	inline Vec4& operator/=( const Vec4& v );
	inline Vec4& operator=( const Vec4& v );

	inline Vec4 add( float a ) const;
	inline Vec4 add( const Vec4& v ) const;
	inline Vec4 sub( float a ) const;
	inline Vec4 sub( const Vec4& v ) const;
	inline Vec4 mul( float a ) const;
	inline Vec4 mul( const Vec4& v ) const;
	inline Vec4 div( float a ) const;
	inline Vec4 div( const Vec4& v ) const;
	inline void addfill( float a );
	inline void addfill( const Vec4& v );
	inline void subfill( float a );
	inline void subfill( const Vec4& v );
	inline void mulfill( float a );
	inline void mulfill( const Vec4& v );
	inline void divfill( float a );
	inline void divfill( const Vec4& v );
	inline void fill( float x, float y, float z, float w );
	inline void fill( const Vec4& v );
	inline void fillZero( void );
	inline void fillOne( void );
	
public:
	inline float dot( const Vec4& v ) const;
	inline float distance( const Vec4& v ) const;
	inline float distanceSq( const Vec4& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline float angleBetween( const Vec4& v ) const;

public:
	inline Vec4 clamp( const Vec4& min, const Vec4& max ) const;
	inline void fillClamp( const Vec4& min, const Vec4& max );
	inline Vec4 negate( void ) const;
	inline void fillNegate( void );
	inline Vec4 normalize( void ) const;
	inline void fillNormalize( void );
	inline Vec4 scale( float s ) const;
	inline void fillScale( float s );
	inline Vec4 midPointBetween( const Vec4& point ) const;
	inline void project( Vec4& h, Vec4& v, const Vec4& n ) const;
};

class MathVec4
{
public:
	static inline void add( Vec4& out, const Vec4& v, float a );
	static inline void add( Vec4& out, const Vec4& v1, const Vec4& v2 );
	static inline void sub( Vec4& out, const Vec4& v, float a );
	static inline void sub( Vec4& out, const Vec4& v1, const Vec4& v2 );
	static inline void mul( Vec4& out, const Vec4& v, float a );
	static inline void mul( Vec4& out, const Vec4& v1, const Vec4& v2 );
	static inline void div( Vec4& out, const Vec4& v, float a );
	static inline void div( Vec4& out, const Vec4& v1, const Vec4& v2 );

	static inline void clamp( Vec4& out, const Vec4& v, const Vec4& min, const Vec4& max );
	static inline void negate( Vec4& out, const Vec4& v );
	static inline void normalize( Vec4& out, const Vec4& v );
	static inline void scale( Vec4& out, const Vec4& v, float s );
	static inline void midPointBetween( Vec4& out, const Vec4& v1, const Vec4& v2 );
};

#include "Vec4.inl"
	
#endif //__VEC4_HPP__