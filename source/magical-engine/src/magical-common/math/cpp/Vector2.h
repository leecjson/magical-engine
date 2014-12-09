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
#ifndef __VECTOR2_H__
#define __VECTOR2_H__

class Vector3;
class Vector4;

class Vector2
{
public:
	float x;
	float y;

public:
	static const Vector2 Zero;
	static const Vector2 One;
	static const Vector2 Right;
	static const Vector2 Left;
	static const Vector2 Up;
	static const Vector2 Down;
	static Vector2 placeholder;
	static Vector2 temp;

public:
	Vector2( const Vector4& v );
	Vector2( const Vector3& v );
	Vector2( const Vector2& v );
	Vector2( const float x, const float y );
	Vector2( void );

public:
	static inline Vector2 fromVector3( const Vector3& v );
	static inline Vector2 fromVector4( const Vector4& v );

	static inline void addScalar( Vector2& out, const Vector2& v, const float a );
	static inline void add( Vector2& out, const Vector2& v1, const Vector2& v2 );
	static inline void subScalar( Vector2& out, const Vector2& v, const float a );
	static inline void sub( Vector2& out, const Vector2& v1, const Vector2& v2 );
	static inline void mulScalar( Vector2& out, const Vector2& v, const float a );
	static inline void mul( Vector2& out, const Vector2& v1, const Vector2& v2 );
	static inline void divScalar( Vector2& out, const Vector2& v, const float a );
	static inline void div( Vector2& out, const Vector2& v1, const Vector2& v2 );

	static inline void clamp( Vector2& out, const Vector2& v, const Vector2& min, const Vector2& max );
	static inline void negate( Vector2& out, const Vector2& v );
	static inline void normalize( Vector2& out, const Vector2& v );
	static inline void rotate( Vector2& out, const Vector2& v, const float angle );
	static inline void scale( Vector2& out, const Vector2& v, const float s );
	static inline void midPointBetween( Vector2& out, const Vector2& v1, const Vector2& v2 );
	static inline void project( Vector2& out, const Vector2& v, const Vector2& n );

public:
	inline bool equals( const Vector2& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline bool isNormalized( void ) const;
	inline void fill( const Vector2& v );
	inline void fill( const float x, const float y );
	inline void fillZero( void );
	inline void fillOne( void );
	inline void fillVector3( const Vector3& v );
	inline void fillVector4( const Vector3& v );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Vector2& v ) const;
	inline bool operator!=( const Vector2& v ) const;
	inline Vector2 operator+( void ) const;
	inline Vector2 operator+( const float a ) const;
	inline Vector2 operator+( const Vector2& v ) const;
	inline Vector2 operator-( void ) const;
	inline Vector2 operator-( const float a ) const;
	inline Vector2 operator-( const Vector2& v ) const;
	inline Vector2 operator*( const float a ) const;
	inline Vector2 operator*( const Vector2& v ) const;
	inline Vector2 operator/( const float a ) const;
	inline Vector2 operator/( const Vector2& v ) const;
	inline Vector2& operator+=( const float a );
	inline Vector2& operator+=( const Vector2& v );
	inline Vector2& operator-=( const float a );
	inline Vector2& operator-=( const Vector2& v );
	inline Vector2& operator*=( const float a );
	inline Vector2& operator*=( const Vector2& v );
	inline Vector2& operator/=( const float a );
	inline Vector2& operator/=( const Vector2& v );
	inline Vector2& operator=( const Vector2& v );

public:
	inline void clamp( const Vector2& min, const Vector2& max );
	inline void negate( void );
	inline void normalize( void );
	inline void rotate( const float angle );
	inline void scale( const float s );
	inline Vector2 getClamped( const Vector2& min, const Vector2& max ) const;
	inline Vector2 getNegated( void ) const;
	inline Vector2 getNormalized( void ) const;
	inline Vector2 getRotated( const float angle ) const;
	inline Vector2 getScaled( const float s ) const;

	inline float dot( const Vector2& v ) const;
	inline float cross( const Vector2& v ) const;
	inline float distanceBetween( const Vector2& v ) const;
	inline float distanceBetweenSq( const Vector2& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline float angleBetween( const Vector2& v ) const;
	inline Vector2 midPointBetween( const Vector2& v ) const;
	inline Vector2 project( const Vector2& n ) const;
};

#include "../c/cVector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Vector2.inl"

#endif //__VECTOR2_H__