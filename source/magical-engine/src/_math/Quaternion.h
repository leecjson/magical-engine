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
#ifndef __QUATERNION_H__
#define __QUATERNION_H__

struct Quaternion
{
	float x;
	float y;
	float z;
	float w;

public:
	static const Quaternion Identity;
	static const Quaternion Zero;

public:
	inline Quaternion( float x, float y, float z, float w );
	inline explicit Quaternion( const Matrix3x3& m );
	inline explicit Quaternion( const Rotater& ea );
	inline Quaternion( const Vector3& axis, float angle );
	inline Quaternion( const Quaternion& q );
	inline Quaternion( void );

public:
	inline bool operator==( const Quaternion& q ) const;
	inline bool operator!=( const Quaternion& q ) const;
	inline Quaternion& operator=( const Quaternion& q );

public:
	inline Quaternion operator+( void ) const;
	inline Quaternion operator+( const Quaternion& q ) const;
	inline Quaternion operator-( void ) const;
	inline Quaternion operator-( const Quaternion& q ) const;
	inline Quaternion operator*( float a ) const;
	inline Quaternion operator*( const Quaternion& q ) const;
	inline Vector3 operator*( const Vector3& v ) const;

public:
	inline Quaternion& operator+=( const Quaternion& q );
	inline Quaternion& operator-=( const Quaternion& q );
	inline Quaternion& operator*=( float a );
	inline Quaternion& operator*=( const Quaternion& q );

public:
	static inline void add( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );
	static inline void sub( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );
	static inline void mulScalar( Quaternion& out, const Quaternion& q, float a );
	static void mul( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );
	static void mulVector3( Vector3& out, const Quaternion& q, const Vector3& v );

public:
	static inline Quaternion add( const Quaternion& q1, const Quaternion& q2 );
	static inline Quaternion sub( const Quaternion& q1, const Quaternion& q2 );
	static inline Quaternion mul( const Quaternion& q1, const Quaternion& q2 );
	static inline Quaternion mulScalar( const Quaternion& q, float a );
	static inline Vector3 mulVector3( const Quaternion& q, const Vector3& v );

public:
	inline void add( const Quaternion& q );
	inline void sub( const Quaternion& q );
	inline void mul( const Quaternion& q );
	inline void mulScalar( float a );
	inline Vector3 mulVector3( const Vector3& v ) const;
	
public:
	inline bool equals( const Quaternion& q ) const;
	inline bool isZero( void ) const;
	inline bool isIdentity( void ) const;
	inline void setZero( void );
	inline void setIdentity( void );
	inline void set( const Quaternion& q );
	inline void set( float x, float y, float z, float w );

public:
	static inline Quaternion createRotation( const Matrix3x3& m );
	static inline Quaternion createRotation( const Rotater& ea );
	static inline Quaternion createRotation( const Vector3& axis, float angle );
	static inline Quaternion createRotationX( float a );
	static inline Quaternion createRotationY( float a );
	static inline Quaternion createRotationZ( float a );
	
public:
	void setRotation( const Matrix3x3& m );
	void setRotation( const Rotater& ea );
	void setRotation( const Vector3& axis, float angle );
	void setRotationX( float a );
	void setRotationY( float a );
	void setRotationZ( float a );
	//Vector4 toAxisAngle( void ) const;

public:
	static void normalize( Quaternion& out, const Quaternion& q );
	static void conjugate( Quaternion& out, const Quaternion& q );
	static void negate( Quaternion& out, const Quaternion& q );
	static void inverse( Quaternion& out, const Quaternion& q );
	static inline Quaternion normalize( const Quaternion& q );
	static inline Quaternion conjugate( const Quaternion& q );
	static inline Quaternion negate( const Quaternion& q );
	static inline Quaternion inverse( const Quaternion& q );
	inline void normalize( void );
	inline void conjugate( void );
	inline void negate( void );
	inline void inverse( void );

public:
	static inline float dot( const Quaternion& q1, const Quaternion& q2 );
	static inline float length( const Quaternion& q );
	static inline float lengthSq( const Quaternion& q );
	inline float dot( const Quaternion& q ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
};

#endif //__QUATERNION_H__ 