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

struct Vector2;
struct Vector3;
struct Matrix4;

struct Vector4 : public cVector4
{
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
	static Vector4 var;

public:
	Vector4( float x, float y, float z, float w );
	Vector4( const Vector4& v );
	Vector4( void );

public:
	static inline Vector4 createZero( void );
	static inline Vector4 createOne( void );
	static inline Vector4 createFromVector2( const Vector2& v );
	static inline Vector4 createFromVector3( const Vector3& v );

	static inline void addScalar( Vector4& out, const Vector4& v, float a );
	static inline void add( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void subScalar( Vector4& out, const Vector4& v, float a );
	static inline void sub( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void mulMatrix4( Vector4& out, const Vector4& v, const Matrix4& m );
	static inline void mulScalar( Vector4& out, const Vector4& v, float a );
	static inline void mul( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void divScalar( Vector4& out, const Vector4& v, float a );
	static inline void div( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void clamp( Vector4& out, const Vector4& v, const Vector4& min, const Vector4& max );
	static inline void negate( Vector4& out, const Vector4& v );
	static inline void normalize( Vector4& out, const Vector4& v );
	static inline void scale( Vector4& out, const Vector4& v, float s );
	static inline void midPointBetween( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void project( Vector4& out, const Vector4& v, const Vector4& n );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool equals( const Vector4& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline bool isNormalized( void ) const;
	inline bool operator==( const Vector4& v ) const;
	inline bool operator!=( const Vector4& v ) const;
	inline float& operator[]( const unsigned int i ) const;
	inline Vector4 operator+( void ) const;
	inline Vector4 operator+( float a ) const;
	inline Vector4 operator+( const Vector4& v ) const;
	inline Vector4 operator-( void ) const;
	inline Vector4 operator-( float a ) const;
	inline Vector4 operator-( const Vector4& v ) const;
	inline Vector4 operator*( const Matrix4& m ) const;
	inline Vector4 operator*( float a ) const;
	inline Vector4 operator*( const Vector4& v ) const;
	inline Vector4 operator/( float a ) const;
	inline Vector4 operator/( const Vector4& v ) const;
	inline Vector4& operator+=( float a );
	inline Vector4& operator+=( const Vector4& v );
	inline Vector4& operator-=( float a );
	inline Vector4& operator-=( const Vector4& v );
	inline Vector4& operator*=( const Matrix4& m );
	inline Vector4& operator*=( float a );
	inline Vector4& operator*=( const Vector4& v );
	inline Vector4& operator/=( float a );
	inline Vector4& operator/=( const Vector4& v );
	inline Vector4& operator=( const Vector4& v );

public:
	inline void set( const Vector4& v );
	inline void setZero( void );
	inline void setOne( void );
	inline void setScalars( float x, float y, float z, float w );
	inline void fromVector2( const Vector2& v );
	inline void fromVector3( const Vector3& v );
	
public:
	inline void clamp( const Vector4& min, const Vector4& max );
	inline void negate( void );
	inline void normalize( void );
	inline void scale( float s );
	inline Vector4 getClamped( const Vector4& min, const Vector4& max ) const;
	inline Vector4 getNegated( void ) const;
	inline Vector4 getNormalized( void ) const;
	inline Vector4 getScaled( float s ) const;
	inline float dot( const Vector4& v ) const;
	inline float distanceBetween( const Vector4& v ) const;
	inline float distanceBetweenSq( const Vector4& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline float angleBetween( const Vector4& v ) const;
	inline Vector4 midPointBetween( const Vector4& v ) const;
	inline Vector4 project( const Vector4& n ) const;
};

#endif //__VECTOR4_H__