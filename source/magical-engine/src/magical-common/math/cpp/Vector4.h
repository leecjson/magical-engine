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
#ifndef __VECTOR4_H__
#define __VECTOR4_H__

class Vector2;
class Vector3;
class Matrix4;

class Vector4
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	static const Vector4 Zero;
	static const Vector4 One;
	static const Vector4 Up;
	static const Vector4 Down;
	static const Vector4 Right;
	static const Vector4 Left;
	static const Vector4 Forward;
	static const Vector4 Back;
	static const Vector4 Space0;
	static const Vector4 Space1;
	static const Vector4 Space2;
	static Vector4 placeholder;
	static Vector4 temp;

public:
	Vector4( const Vector2& v );
	Vector4( const Vector3& v );
	Vector4( const Vector4& v );
	Vector4( const float x, const float y, const float z, const float w );
	Vector4( void );

public:
	static inline Vector4 fromVector2( const Vector2& v );
	static inline Vector4 fromVector3( const Vector3& v );

	static inline void addScalar( Vector4& out, const Vector4& v, const float a );
	static inline void add( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void subScalar( Vector4& out, const Vector4& v, const float a );
	static inline void sub( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void mulMatrix( Vector4& out, const Vector4& v, const Matrix4& m );
	static inline void mulScalar( Vector4& out, const Vector4& v, const float a );
	static inline void mul( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void divScalar( Vector4& out, const Vector4& v, const float a );
	static inline void div( Vector4& out, const Vector4& v1, const Vector4& v2 );

	static inline void clamp( Vector4& out, const Vector4& v, const Vector4& min, const Vector4& max );
	static inline void negate( Vector4& out, const Vector4& v );
	static inline void normalize( Vector4& out, const Vector4& v );
	static inline void scale( Vector4& out, const Vector4& v, const float s );
	static inline void midPointBetween( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void project( Vector4& out, const Vector4& v, const Vector4& n );

public:
	inline bool equals( const Vector4& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline bool isNormalized( void ) const;
	inline void fill( const float x, const float y, const float z, const float w );
	inline void fill( const Vector4& v );
	inline void fillZero( void );
	inline void fillOne( void );
	inline void fillVector2( const Vector2& v );
	inline void fillVector3( const Vector3& v );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Vector4& v ) const;
	inline bool operator!=( const Vector4& v ) const;
	inline Vector4 operator+( void ) const;
	inline Vector4 operator+( const float a ) const;
	inline Vector4 operator+( const Vector4& v ) const;
	inline Vector4 operator-( void ) const;
	inline Vector4 operator-( const float a ) const;
	inline Vector4 operator-( const Vector4& v ) const;
	inline Vector4 operator*( const Matrix4& m ) const;
	inline Vector4 operator*( const float a ) const;
	inline Vector4 operator*( const Vector4& v ) const;
	inline Vector4 operator/( const float a ) const;
	inline Vector4 operator/( const Vector4& v ) const;
	inline Vector4& operator+=( const float a );
	inline Vector4& operator+=( const Vector4& v );
	inline Vector4& operator-=( const float a );
	inline Vector4& operator-=( const Vector4& v );
	inline Vector4& operator*=( const Matrix4& m );
	inline Vector4& operator*=( const float a );
	inline Vector4& operator*=( const Vector4& v );
	inline Vector4& operator/=( const float a );
	inline Vector4& operator/=( const Vector4& v );
	inline Vector4& operator=( const Vector4& v );
	
public:
	inline void clamp( const Vector4& min, const Vector4& max );
	inline void negate( void );
	inline void normalize( void );
	inline void scale( const float s );
	inline Vector4 getClamped( const Vector4& min, const Vector4& max ) const;
	inline Vector4 getNegated( void ) const;
	inline Vector4 getNormalized( void ) const;
	inline Vector4 getScaled( const float s ) const;
	
	inline float dot( const Vector4& v ) const;
	inline float distanceBetween( const Vector4& v ) const;
	inline float distanceBetweenSq( const Vector4& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline float angleBetween( const Vector4& v ) const;
	inline Vector4 midPointBetween( const Vector4& v ) const;
	inline Vector4 project( const Vector4& n ) const;
};

#include "../c/cVector4.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix4.h"
#include "Vector4.inl"
	
#endif //__VECTOR4_H__