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

struct Vector3;
struct AxisRotation;
struct EulerA;

struct Quaternion : public cQuaternion
{
public:
	static const float Epsilon;
	static const Quaternion Identity;
	static const Quaternion Zero;
	static Quaternion var;

public:
	Quaternion( float x, float y, float z, float w );
	Quaternion( const Quaternion& q );
	Quaternion( void );

public:
	static inline Quaternion createIdentity( void );
	static inline Quaternion createZero( void );
	static inline Quaternion createAxisRotationX( float angle );
	static inline Quaternion createAxisRotationY( float angle );
	static inline Quaternion createAxisRotationZ( float angle );
	static inline Quaternion createAxisRotation( const AxisRotation& ar );
	static inline Quaternion createAxisRotation( const Vector3& axis, float angle );
	static inline Quaternion createFromEulerA( const EulerA& ea );
	static inline Quaternion createFromEulerA( float yaw, float pitch, float roll );

	static inline void add( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );
	static inline void sub( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );
	static inline void mul( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );
	static inline void mulVector3( Vector3& out, const Quaternion& q, const Vector3& v );
	static inline void mulScalar( Quaternion& out, const Quaternion& q, float a );
	static inline void normalize( Quaternion& out, const Quaternion& q );
	static inline void conjugate( Quaternion& out, const Quaternion& q );
	static inline void negate( Quaternion& out, const Quaternion& q );
	static inline void inverse( Quaternion& out, const Quaternion& q );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool equals( const Quaternion& q ) const;
	inline bool isIdentity( void ) const;
	inline bool isZero( void ) const;
	inline bool isNormalized( void ) const;
	inline bool operator==( const Quaternion& q ) const;
	inline bool operator!=( const Quaternion& q ) const;
	inline float operator[]( const unsigned int i ) const;
	inline Quaternion operator+( const Quaternion& q ) const;
	inline Quaternion operator-( const Quaternion& q ) const;
	inline Quaternion operator*( float a ) const;
	inline Quaternion operator*( const Quaternion& q ) const;
	inline Quaternion& operator+=( const Quaternion& q );
	inline Quaternion& operator-=( const Quaternion& q );
	inline Quaternion& operator*=( float a );
	inline Quaternion& operator*=( const Quaternion& q );
	inline Quaternion& operator=( const Quaternion& q );

public:
	inline void set( const Quaternion& q );
	inline void setIdentity( void );
	inline void setZero( void );
	inline void setScalars( float x, float y, float z, float w );
	inline void setAxisRotationX( float angle );
	inline void setAxisRotationY( float angle );
	inline void setAxisRotationZ( float angle );
	inline void setAxisRotation( const AxisRotation& ar );
	inline void setAxisRotation( const Vector3& axis, float angle );
	inline void setEulerA( const EulerA& ea );
	inline void setEulerA( float yaw, float pitch, float roll );

public:
	inline void normalize( void );
	inline void conjugate( void );
	inline void negate( void );
	inline void inverse( void );
	inline Quaternion getNormalized( void ) const;
	inline Quaternion getConjugated( void ) const;
	inline Quaternion getNegated( void ) const;
	inline Quaternion getInversed( void ) const;
	inline float dot( const Quaternion& q ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	inline AxisRotation toAxisRotation( void ) const;
	inline EulerA toEulerA( void ) const;
};
	
#endif //__QUATERNION_H__