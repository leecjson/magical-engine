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
#ifndef __VECTOR3_H__
#define __VECTOR3_H__

class Vector2;
class Vector4;
class Matrix4;

class Vector3
{
public:
	float x;
	float y;
	float z;

public:
	static const Vector3 Zero;
	static const Vector3 One;
	static const Vector3 Up;
	static const Vector3 Down;
	static const Vector3 Right;
	static const Vector3 Left;
	static const Vector3 Forward;
	static const Vector3 Back;
	static Vector3 placeholder;
	static Vector3 temp;

public:
	Vector3( const Vector4& v );
	Vector3( const Vector2& v );
	Vector3( const Vector3& v );
	Vector3( const float x, const float y, const float z );
	Vector3( void );
	static inline Vector3 fromVector2( const Vector2& v );
	static inline Vector3 fromVector4( const Vector4& v );

public:
	inline bool equals( const Vector3& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline bool isNormalized( void ) const;
	inline void fill( const Vector3& v );
	inline void fill( const float x, const float y, const float z );
	inline void fillZero( void );
	inline void fillOne( void );
	inline void fillVector2( const Vector2& v );
	inline void fillVector4( const Vector4& v );

public:
	static inline void addScalar( Vector3& out, const Vector3& v, const float a );
	static inline void add( Vector3& out, const Vector3& v1, const Vector3& v2 );
	static inline void subScalar( Vector3& out, const Vector3& v, const float a );
	static inline void sub( Vector3& out, const Vector3& v1, const Vector3& v2 );
	static inline void mulMatrix( Vector3& out, const Vector3& v, const Matrix4& m );
	static inline void mulScalar( Vector3& out, const Vector3& v, const float a );
	static inline void mul( Vector3& out, const Vector3& v1, const Vector3& v2 );
	static inline void divScalar( Vector3& out, const Vector3& v, const float a );
	static inline void div( Vector3& out, const Vector3& v1, const Vector3& v2 );

	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Vector3& v ) const;
	inline bool operator!=( const Vector3& v ) const;
	inline Vector3 operator+( const float a ) const;
	inline Vector3 operator+( const Vector3& v ) const;
	inline Vector3 operator-( const float a ) const;
	inline Vector3 operator-( const Vector3& v ) const;
	inline Vector3 operator*( const Matrix4& m ) const;
	inline Vector3 operator*( const float a ) const;
	inline Vector3 operator*( const Vector3& v ) const;
	inline Vector3 operator/( const float a ) const;
	inline Vector3 operator/( const Vector3& v ) const;
	inline Vector3& operator+=( const float a );
	inline Vector3& operator+=( const Vector3& v );
	inline Vector3& operator-=( const float a );
	inline Vector3& operator-=( const Vector3& v );
	inline Vector3& operator*=( const Matrix4& m );
	inline Vector3& operator*=( const float a );
	inline Vector3& operator*=( const Vector3& v );
	inline Vector3& operator/=( const float a );
	inline Vector3& operator/=( const Vector3& v );
	inline Vector3& operator=( const Vector3& v );

public:
	static inline void cross( Vector3& out, const Vector3& v1, const Vector3& v2 );
	static inline void clamp( Vector3& out, const Vector3& v, const Vector3& min, const Vector3& max );
	static inline void negate( Vector3& out, const Vector3& v );
	static inline void normalize( Vector3& out, const Vector3& v );
	static inline void scale( Vector3& out, const Vector3& v, const float s );
	static inline void midPointBetween( Vector3& out, const Vector3& v1, const Vector3& v2 );
	static inline void project( Vector3& out, const Vector3& v, const Vector3& n );

public:
	inline void clamp( const Vector3& min, const Vector3& max );
	inline void negate( void );
	inline void normalize( void );
	inline void scale( const float s );
	inline Vector3 getClamped( const Vector3& min, const Vector3& max ) const;
	inline Vector3 getNegated( void ) const;
	inline Vector3 getNormalized( void ) const;
	inline Vector3 getScaled( const float s ) const;

	inline float dot( const Vector3& v ) const;
	inline float distanceBetween( const Vector3& v ) const;
	inline float distanceBetweenSq( const Vector3& v ) const;
	inline float length( void ) const;
    inline float lengthSq( void ) const;
	inline float angleBetween( const Vector3& v ) const;
	inline Vector3 cross( const Vector3& v ) const;
	inline Vector3 midPointBetween( const Vector3& v ) const;
	inline Vector3 project( const Vector3& n ) const;
};

#include "../c/cVector3.h"
#include "Vector2.h"
#include "Vector4.h"
#include "Matrix4.h"
#include "Vector3.inl"

#endif //__VECTOR3_H__