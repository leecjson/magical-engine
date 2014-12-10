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

class Vector3;
class Matrix4;
class AxisAngle;
class EulerAngles;

class Quaternion
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	static const Quaternion Identity;
	static const Quaternion Zero;
	static Quaternion placeholder;
	static Quaternion temp;

public:
	Quaternion( const float x, const float y, const float z, const float w );
	Quaternion( const Matrix4& m );
	Quaternion( const AxisAngle& aa );
	Quaternion( const EulerAngles& ea );
	Quaternion( const Quaternion& q );
	Quaternion( void );

public:
	static inline Quaternion fromIdentity( void );
	static inline Quaternion fromZero( void );

	static inline Quaternion fromAxisAngle( const AxisAngle& aa );
	static inline Quaternion fromAxisAngle( const Vector3& axis, const float angle );
	static inline Quaternion fromEulerAngles( const EulerAngles& ea );
	static inline Quaternion fromEulerAngles( const float yaw, const float pitch, const float roll );
	static inline Quaternion fromRotationX( const float angle );
	static inline Quaternion fromRotationY( const float angle );
	static inline Quaternion fromRotationZ( const float angle );
	static inline Quaternion fromMatrix4( const Matrix4& m );

	static inline void add( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );
	static inline void sub( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );
	static inline void mulScalar( Quaternion& out, const Quaternion& q, const float a );
	static inline void mul( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );

	static inline void rotateX( Quaternion& out, const Quaternion& q, const float angle );
	static inline void rotateY( Quaternion& out, const Quaternion& q, const float angle );
	static inline void rotateZ( Quaternion& out, const Quaternion& q, const float angle );
	static inline void rotateAxisAngle( Quaternion& out, const Quaternion& q, const AxisAngle& aa );
	static inline void rotateAxisAngle( Quaternion& out, const Quaternion& q, const Vector3& axis, const float angle );
	static inline void rotateEuler( Quaternion& out, const Quaternion& q, const EulerAngles& ea );
	static inline void rotateEuler( Quaternion& out, const Quaternion& q, const float yaw, const float pitch, const float roll );
	static inline void normalize( Quaternion& out, const Quaternion& q );
	static inline void conjugate( Quaternion& out, const Quaternion& q );
	static inline void negate( Quaternion& out, const Quaternion& q );
	static inline void inverse( Quaternion& out, const Quaternion& q );

public:
	inline bool equals( const Quaternion& q ) const;
	inline bool isIdentity( void ) const;
	inline bool isZero( void ) const;
	inline bool isNormalized( void ) const;
	inline void fill( const Quaternion& q );
	inline void fill( float x, float y, float z, float w );
	inline void fillIdentity( void );
	inline void fillZero( void );
	inline void fillMatrix4( const Matrix4& m );
	inline void fillAxisAngle( const AxisAngle& aa );
	inline void fillAxisAngle( const Vector3& axis, const float angle );
	inline void fillEuler( const EulerAngles& ea );
	inline void fillEuler( const float yaw, const float pitch, const float roll );
	inline void fillRotationX( const float angle );
	inline void fillRotationY( const float angle );
	inline void fillRotationZ( const float angle );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Quaternion& q ) const;
	inline bool operator!=( const Quaternion& q ) const;
	inline float operator[]( const unsigned int i ) const;
	inline Quaternion operator+( const Quaternion& q ) const;
	inline Quaternion operator-( const Quaternion& q ) const;
	inline Quaternion operator*( const float a ) const;
	inline Quaternion operator*( const Quaternion& q ) const;
	inline Quaternion& operator+=( const Quaternion& q );
	inline Quaternion& operator-=( const Quaternion& q );
	inline Quaternion& operator*=( const float a );
	inline Quaternion& operator*=( const Quaternion& q );
	inline Quaternion& operator=( const Quaternion& q );

public:
	inline void rotateX( const float angle );
	inline void rotateY( const float angle );
	inline void rotateZ( const float angle );
	inline void rotateAxisAngle( const AxisAngle& aa );
	inline void rotateAxisAngle( const Vector3& axis, const float angle );
	inline void rotateEuler( const EulerAngles& ea );
	inline void rotateEuler( const float yaw, const float pitch, const float roll );
	inline void normalize( void );
	inline void conjugate( void );
	inline void negate( void );
	inline void inverse( void );

	inline Quaternion getRotatedX( const float angle );
	inline Quaternion getRotatedY( const float angle );
	inline Quaternion getRotatedZ( const float angle );
	inline Quaternion getRotatedAxisAngle( const AxisAngle& aa );
	inline Quaternion getRotatedAxisAngle( const Vector3& axis, const float angle );
	inline Quaternion getRotatedEuler( const EulerAngles& ea );
	inline Quaternion getRotatedEuler( const float yaw, const float pitch, const float roll );
	inline Quaternion getNormalized( void ) const;
	inline Quaternion getConjugated( void ) const;
	inline Quaternion getNegated( void ) const;
	inline Quaternion getInversed( void ) const;

	inline float dot( const Quaternion& q ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
};
	
#endif //__QUATERNION_H__