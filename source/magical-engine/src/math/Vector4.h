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

struct Vector4
{
	union
	{
		struct {
			float x;
			float y;
			float z;
			float w;
		};
		struct { Vector2 xy;  float z; float w; };
		struct { Vector3 xyz; float w; };
		struct { Vector3 axis; float a; };
	};
	
public:
	static const Vector4 Zero;
	static const Vector4 One;
	static const Vector4 UnitX;
	static const Vector4 UnitY;
	static const Vector4 UnitZ;
	static const Vector4 UnitW;
	static const Vector4 Up;
	static const Vector4 Down;
	static const Vector4 Right;
	static const Vector4 Left;
	static const Vector4 Forward;
	static const Vector4 Back;
	static const Vector4 Space0;
	static const Vector4 Space1;
	static const Vector4 Space2;

public:
	inline explicit Vector4( const Vector3& v );
	inline explicit Vector4( float v );
	inline Vector4( float x, float y, float z, float w );
	inline Vector4( const Vector4& v );
	inline Vector4( void );

public:
	inline bool operator==( const Vector4& v ) const;
	inline bool operator!=( const Vector4& v ) const;
	inline float& operator[]( size_t i ) const;
	inline Vector4& operator=( float v );
	inline Vector4& operator=( const Vector4& v );

public:
	inline Vector4 operator+( void ) const;
	inline Vector4 operator+( float a ) const;
	inline Vector4 operator+( const Vector4& v ) const;
	inline Vector4 operator-( void ) const;
	inline Vector4 operator-( float a ) const;
	inline Vector4 operator-( const Vector4& v ) const;
	inline Vector4 operator*( const Matrix4x4& m ) const;
	inline Vector4 operator*( float a ) const;
	inline Vector4 operator*( const Vector4& v ) const;
	inline Vector4 operator/( float a ) const;
	inline Vector4 operator/( const Vector4& v ) const;

public:
	inline Vector4& operator+=( float a );
	inline Vector4& operator+=( const Vector4& v );
	inline Vector4& operator-=( float a );
	inline Vector4& operator-=( const Vector4& v );
	inline Vector4& operator*=( const Matrix4x4& m );
	inline Vector4& operator*=( float a );
	inline Vector4& operator*=( const Vector4& v );
	inline Vector4& operator/=( float a );
	inline Vector4& operator/=( const Vector4& v );

public:
	static inline void add( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void sub( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void mul( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void div( Vector4& out, const Vector4& v1, const Vector4& v2 );
	static inline void addScalar( Vector4& out, const Vector4& v, float a );
	static inline void subScalar( Vector4& out, const Vector4& v, float a );
	static inline void mulScalar( Vector4& out, const Vector4& v, float a );
	static inline void divScalar( Vector4& out, const Vector4& v, float a );
	static void mulMatrix4x4( Vector4& out, const Vector4& v, const Matrix4x4& m );

public:
	static inline Vector4 add( const Vector4& v1, const Vector4& v2 );
	static inline Vector4 sub( const Vector4& v1, const Vector4& v2 );
	static inline Vector4 mul( const Vector4& v1, const Vector4& v2 );
	static inline Vector4 div( const Vector4& v1, const Vector4& v2 );
	static inline Vector4 addScalar( const Vector4& v, float a );
	static inline Vector4 subScalar( const Vector4& v, float a );
	static inline Vector4 mulScalar( const Vector4& v, float a );
	static inline Vector4 divScalar( const Vector4& v, float a );
	static inline Vector4 mulMatrix4x4( const Vector4& v, const Matrix4x4& m );

public:
	inline void add( const Vector4& v );
	inline void sub( const Vector4& v );
	inline void mul( const Vector4& v );
	inline void div( const Vector4& v );
	inline void addScalar( float a );
	inline void subScalar( float a );
	inline void mulScalar( float a );
	inline void divScalar( float a );
	inline void mulMatrix4x4( const Matrix4x4& m );
	
public:
	inline bool equals( const Vector4& v ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline void setZero( void );
	inline void setOne( void );
	inline void set( const Vector3& v );
	inline void set( const Vector4& v );
	inline void set( float x, float y, float z, float w );

//public:
//	static inline void Clamp( Vector4& out, const Vector4& v, const Vector4& min, const Vector4& max );
//	static inline void Negate( Vector4& out, const Vector4& v );
//	static inline void Normalize( Vector4& out, const Vector4& v );
//	static inline void Scale( Vector4& out, const Vector4& v, float s );
//	static inline void MidPointBetween( Vector4& out, const Vector4& v1, const Vector4& v2 );
//	static inline void Project( Vector4& out, const Vector4& v, const Vector4& n );
//
//	static inline Vector4 Clamp( const Vector4& v, const Vector4& min, const Vector4& max );
//	static inline Vector4 Negate( const Vector4& v );
//	static inline Vector4 Normalize( const Vector4& v );
//	static inline Vector4 Scale( const Vector4& v, float s );
//	static inline Vector4 MidPointBetween( const Vector4& v1, const Vector4& v2 );
//	static inline Vector4 Project( const Vector4& v, const Vector4& n );
//
//	inline void Clamp( const Vector4& min, const Vector4& max );
//	inline void Negate( void );
//	inline void Normalize( void );
//	inline void Scale( float s );
//	inline Vector4 MidPointBetween( const Vector4& v ) const;
//	inline Vector4 Project( const Vector4& n ) const;
//
//public:
//	static inline float Dot( const Vector4& v1, const Vector4& v2 );
//	static inline float Distance( const Vector4& v1, const Vector4& v2 );
//	static inline float DistanceSq( const Vector4& v1, const Vector4& v2 );
//	static inline float Length( const Vector4& v );
//	static inline float LengthSq( const Vector4& v );
//	static inline float AngleBetween( const Vector4& v1, const Vector4& v2 );
//
//	inline float Dot( const Vector4& v ) const;
//	inline float Distance( const Vector4& v ) const;
//	inline float DistanceSq( const Vector4& v ) const;
//	inline float Length( void ) const;
//	inline float LengthSq( void ) const;
//	inline float AngleBetween( const Vector4& v ) const;
};

#endif //__VECTOR4_H__