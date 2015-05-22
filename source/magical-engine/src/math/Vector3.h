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

struct Vector3
{
	union 
	{
		struct {
			float x;
			float y;
			float z;
		};
		struct { Vector2 xy; float z; };
	};

public:
	static const Vector3 Zero;
	static const Vector3 One;
	static const Vector3 UnitX;
	static const Vector3 UnitY;
	static const Vector3 UnitZ;
	static const Vector3 Up;
	static const Vector3 Down;
	static const Vector3 Right;
	static const Vector3 Left;
	static const Vector3 Forward;
	static const Vector3 Back;

public:
	inline explicit Vector3( const Vector2& v );
	inline explicit Vector3( float v );
	inline Vector3( float x, float y, float z );
	inline Vector3( const Vector3& v );
	inline Vector3( void );

public:
	inline bool operator==( const Vector3& v ) const;
	inline bool operator!=( const Vector3& v ) const;
	inline float& operator[]( size_t i ) const;
	inline Vector3& operator=( float v );
	inline Vector3& operator=( const Vector3& v );

public:
	inline Vector3 operator+( void ) const;
	inline Vector3 operator+( float a ) const;
	inline Vector3 operator+( const Vector3& v ) const;
	inline Vector3 operator-( void ) const;
	inline Vector3 operator-( float a ) const;
	inline Vector3 operator-( const Vector3& v ) const;
	inline Vector3 operator*( const Matrix3x3& m ) const;
	inline Vector3 operator*( const Matrix4x4& m ) const;
	inline Vector3 operator*( float a ) const;
	inline Vector3 operator*( const Vector3& v ) const;
	inline Vector3 operator/( float a ) const;
	inline Vector3 operator/( const Vector3& v ) const;

public:
	inline Vector3& operator+=( float a );
	inline Vector3& operator+=( const Vector3& v );
	inline Vector3& operator-=( float a );
	inline Vector3& operator-=( const Vector3& v );
	inline Vector3& operator*=( const Matrix3x3& m );
	inline Vector3& operator*=( const Matrix4x4& m );
	inline Vector3& operator*=( float a );
	inline Vector3& operator*=( const Vector3& v );
	inline Vector3& operator/=( float a );
	inline Vector3& operator/=( const Vector3& v );

public:
	static inline void add( Vector3& out, const Vector3& v1, const Vector3& v2 );
	static inline void sub( Vector3& out, const Vector3& v1, const Vector3& v2 );
	static inline void mul( Vector3& out, const Vector3& v1, const Vector3& v2 );
	static inline void div( Vector3& out, const Vector3& v1, const Vector3& v2 );
	static inline void addScalar( Vector3& out, const Vector3& v, float a );
	static inline void subScalar( Vector3& out, const Vector3& v, float a );
	static inline void mulScalar( Vector3& out, const Vector3& v, float a );
	static inline void divScalar( Vector3& out, const Vector3& v, float a );
	static void mulMatrix3x3( Vector3& out, const Vector3& v, const Matrix3x3& m );
	static void mulMatrix4x4( Vector3& out, const Vector3& v, const Matrix4x4& m );

public:
	static inline Vector3 add( const Vector3& v1, const Vector3& v2 );
	static inline Vector3 sub( const Vector3& v1, const Vector3& v2 );
	static inline Vector3 mul( const Vector3& v1, const Vector3& v2 );
	static inline Vector3 div( const Vector3& v1, const Vector3& v2 );
	static inline Vector3 addScalar( const Vector3& v, float a );
	static inline Vector3 subScalar( const Vector3& v, float a );
	static inline Vector3 mulScalar( const Vector3& v, float a );
	static inline Vector3 divScalar( const Vector3& v, float a );
	static inline Vector3 mulMatrix3x3( const Vector3& v, const Matrix3x3& m );
	static inline Vector3 mulMatrix4x4( const Vector3& v, const Matrix4x4& m );

public:
	inline void add( const Vector3& v );
	inline void sub( const Vector3& v );
	inline void mul( const Vector3& v );
	inline void div( const Vector3& v );
	inline void addScalar( float a );
	inline void subScalar( float a );
	inline void mulScalar( float a );
	inline void divScalar( float a );
	inline void mulMatrix3x3( const Matrix3x3& m );
	inline void mulMatrix4x4( const Matrix4x4& m );
	
public:
	inline bool equals( const Vector3& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline void setZero( void );
	inline void setOne( void );
	inline void set( const Vector2& v );
	inline void set( const Vector3& v );
	inline void set( float x, float y, float z );

public:
	static void clamp( Vector3& out, const Vector3& v, const Vector3& min, const Vector3& max );
	static void negate( Vector3& out, const Vector3& v );
	static void normalize( Vector3& out, const Vector3& v );
	static void scale( Vector3& out, const Vector3& v, float s );
	static void cross( Vector3& out, const Vector3& v1, const Vector3& v2 );
	static void midPointBetween( Vector3& out, const Vector3& v1, const Vector3& v2 );
	static void project( Vector3& out, const Vector3& v, const Vector3& n );

public:
	static inline Vector3 clamp( const Vector3& v, const Vector3& min, const Vector3& max );
	static inline Vector3 negate( const Vector3& v );
	static inline Vector3 normalize( const Vector3& v );
	static inline Vector3 scale( const Vector3& v, float s );
	static inline Vector3 cross( const Vector3& v1, const Vector3& v2 );
	static inline Vector3 midPointBetween( const Vector3& v1, const Vector3& v2 );
	static inline Vector3 project( const Vector3& v, const Vector3& n );

public:
	inline void clamp( const Vector3& min, const Vector3& max );
	inline void negate( void );
	inline void normalize( void );
	inline void scale( float s );
	inline Vector3 cross( const Vector3& v );
	inline Vector3 midPointBetween( const Vector3& v ) const;
	inline Vector3 project( const Vector3& n ) const;

public:
	static inline float dot( const Vector3& v1, const Vector3& v2 );
	static inline float distance( const Vector3& v1, const Vector3& v2 );
	static inline float distanceSq( const Vector3& v1, const Vector3& v2 );
	static inline float length( const Vector3& v );
	static inline float lengthSq( const Vector3& v );
	static inline float angle( const Vector3& v1, const Vector3& v2 );

public:
	inline float dot( const Vector3& v ) const;	
	inline float distance( const Vector3& v ) const;
	inline float distanceSq( const Vector3& v ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline float angle( const Vector3& v ) const;
};

#endif //__VECTOR3_H__