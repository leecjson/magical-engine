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

struct Vector2
{
	float x;
	float y;

public:
	static const Vector2 Zero;
	static const Vector2 One;
	static const Vector2 UnitX;
	static const Vector2 UnitY;
	static const Vector2 Right;
	static const Vector2 Left;
	static const Vector2 Up;
	static const Vector2 Down;

public:
	inline explicit Vector2( float v );
	inline Vector2( float x, float y );
	inline Vector2( const Vector2& v );
	inline Vector2( void );

public:
	inline operator float*( void );
	inline operator const float*( void ) const;
	inline bool operator==( const Vector2& v ) const;
	inline bool operator!=( const Vector2& v ) const;
	inline float& operator[]( size_t i ) const;
	inline Vector2& operator=( float v );
	inline Vector2& operator=( const Vector2& v );

public:
	inline Vector2 operator+( void ) const;
	inline Vector2 operator+( float a ) const;
	inline Vector2 operator+( const Vector2& v ) const;
	inline Vector2 operator-( void ) const;
	inline Vector2 operator-( float a ) const;
	inline Vector2 operator-( const Vector2& v ) const;
	inline Vector2 operator*( float a ) const;
	inline Vector2 operator*( const Vector2& v ) const;
	inline Vector2 operator/( float a ) const;
	inline Vector2 operator/( const Vector2& v ) const;
	
public:
	inline Vector2& operator+=( float a );
	inline Vector2& operator+=( const Vector2& v );
	inline Vector2& operator-=( float a );
	inline Vector2& operator-=( const Vector2& v );
	inline Vector2& operator*=( float a );
	inline Vector2& operator*=( const Vector2& v );
	inline Vector2& operator/=( float a );
	inline Vector2& operator/=( const Vector2& v );

public:
	static inline void add( Vector2& out, const Vector2& v1, const Vector2& v2 );
	static inline void sub( Vector2& out, const Vector2& v1, const Vector2& v2 );
	static inline void mul( Vector2& out, const Vector2& v1, const Vector2& v2 );
	static inline void div( Vector2& out, const Vector2& v1, const Vector2& v2 );
	static inline void addScalar( Vector2& out, const Vector2& v, float a );
	static inline void subScalar( Vector2& out, const Vector2& v, float a );
	static inline void mulScalar( Vector2& out, const Vector2& v, float a );
	static inline void divScalar( Vector2& out, const Vector2& v, float a );

public:
	static inline Vector2 add( const Vector2& v1, const Vector2& v2 );
	static inline Vector2 sub( const Vector2& v1, const Vector2& v2 );
	static inline Vector2 mul( const Vector2& v1, const Vector2& v2 );
	static inline Vector2 div( const Vector2& v1, const Vector2& v2 );
	static inline Vector2 addScalar( const Vector2& v, float a );
	static inline Vector2 subScalar( const Vector2& v, float a );
	static inline Vector2 mulScalar( const Vector2& v, float a );
	static inline Vector2 divScalar( const Vector2& v, float a );

public:
	inline void add( const Vector2& v );
	inline void sub( const Vector2& v );
	inline void mul( const Vector2& v );
	inline void div( const Vector2& v );
	inline void addScalar( float a );
	inline void subScalar( float a );
	inline void mulScalar( float a );
	inline void divScalar( float a );

public:
	inline bool equals( const Vector2& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline void setZero( void );
	inline void setOne( void );
	inline void set( const Vector2& v );
	inline void set( float x, float y );

public:
	static void clamp( Vector2& out, const Vector2& v, const Vector2& min, const Vector2& max );
	static void negate( Vector2& out, const Vector2& v );
	static void normalize( Vector2& out, const Vector2& v );
	static void rotate( Vector2& out, const Vector2& v, float a );
	static void scale( Vector2& out, const Vector2& v, float s );
	static void midPointBetween( Vector2& out, const Vector2& v1, const Vector2& v2 );
	static void project( Vector2& out, const Vector2& v, const Vector2& n );
	static void lerp( Vector2& out, const Vector2& v1, const Vector2& v2, float t );

public:
	static inline Vector2 clamp( const Vector2& v, const Vector2& min, const Vector2& max );
	static inline Vector2 negate( const Vector2& v );
	static inline Vector2 normalize( const Vector2& v );
	static inline Vector2 rotate( const Vector2& v, float a );
	static inline Vector2 scale( const Vector2& v, float s );
	static inline Vector2 midPointBetween( const Vector2& v1, const Vector2& v2 );
	static inline Vector2 project( const Vector2& v, const Vector2& n );
	static inline Vector2 lerp( const Vector2& v1, const Vector2& v2, float t );

public:
	inline void clamp( const Vector2& min, const Vector2& max );
	inline void negate( void );
	inline void normalize( void );
	inline void rotate( float a );
	inline void scale( float s );
	inline Vector2 midPointBetween( const Vector2& v ) const;
	inline Vector2 project( const Vector2& n ) const;
	inline Vector2 lerp( const Vector2& v, float t ) const;

public:
	static inline float dot( const Vector2& v1, const Vector2& v2 );
	static inline float cross( const Vector2& v1, const Vector2& v2 );
	static inline float distance( const Vector2& v1, const Vector2& v2 );
	static inline float distanceSq( const Vector2& v1, const Vector2& v2 );
	static inline float length( const Vector2& v );
	static inline float lengthSq( const Vector2& v );
	static inline float angle( const Vector2& v1, const Vector2& v2 );

public:
	inline float dot( const Vector2& v ) const;
	inline float cross( const Vector2& v ) const;
	inline float distance( const Vector2& v ) const;
	inline float distanceSq( const Vector2& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline float angle( const Vector2& v ) const;
};

#endif //__VECTOR2_H__