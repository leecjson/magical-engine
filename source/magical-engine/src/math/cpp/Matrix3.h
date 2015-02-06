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
#ifndef __MATRIX3_H__
#define __MATRIX3_H__

NS_MAGICAL_BEGIN

FORWARD_DECLARE

struct Matrix3 : public cMatrix3
{
public:
	static const Matrix3 Identity;
	static const Matrix3 Zero;
	static Matrix3 var;

public:
	Matrix3( float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33 );
	Matrix3( const Matrix3& m );
	Matrix3( void );

public:
	static inline Matrix3 createIdentity( void );
	static inline Matrix3 createZero( void );
	static inline Matrix3 createRotationX( float angle );
	static inline Matrix3 createRotationY( float angle );
	static inline Matrix3 createRotationZ( float angle );
	static inline Matrix3 createRotationQuaternion( const Quaternion& q );
	static inline Matrix3 createRotationAxisAngle( const Vector3& axis, float angle );
	static inline Matrix3 createRotationAxisAngle( const AxisAngle& aa );
	static inline Matrix3 createRotationEulerAngles( float yaw, float pitch, float roll );
	static inline Matrix3 createRotationEulerAngles( const EulerAngles& ea );

	static inline void mulScalar( Matrix3& out, const Matrix3& m, float a );
	static inline void mul( Matrix3& out, const Matrix3& m1, const Matrix3& m2 );
	static inline void getUpVector( Vector3& out, const Matrix3& m );
	static inline void getDownVector( Vector3& out, const Matrix3& m );
	static inline void getLeftVector( Vector3& out, const Matrix3& m );
	static inline void getRightVector( Vector3& out, const Matrix3& m );
	static inline void getForwardVector( Vector3& out, const Matrix3& m );
	static inline void getBackVector( Vector3& out, const Matrix3& m );
	static inline void inverse( Matrix3& out, const Matrix3& m );
	static inline void transpose( Matrix3& out, const Matrix3& m );
	static inline void negate( Matrix3& out, const Matrix3& m );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool equals( const Matrix3& m ) const;
	inline bool isZero( void ) const;
	inline bool isIdentity( void ) const;
	inline bool operator==( const Matrix3& m ) const;
	inline bool operator!=( const Matrix3& m ) const;
	inline float& operator[]( size_t i ) const;
	inline Matrix3 operator*( float a ) const;
	inline Matrix3 operator*( const Matrix3& m ) const;
	inline Matrix3& operator*=( float a );
	inline Matrix3& operator*=( const Matrix3& m );
	inline Matrix3& operator=( const Matrix3& m );

public:
	inline void set( const Matrix3& m );
	inline void setIdentity( void );
	inline void setZero( void );
	inline void lookAt( const Vector3& eye, const Vector3& target, const Vector3& up );
	inline void rotationX( float angle );
	inline void rotationY( float angle );
	inline void rotationZ( float angle );
	inline void rotationQuaternion( const Quaternion& q );
	inline void rotationAxisAngle( const Vector3& axis, float angle );
	inline void rotationAxisAngle( const AxisAngle& aa );
	inline void rotationEulerAngles( float yaw, float pitch, float roll );
	inline void rotationEulerAngles( const EulerAngles& ea );
	inline Quaternion toQuaternion( void );

public:
	inline Vector3 getUpVector( void ) const;
	inline Vector3 getDownVector( void ) const;
	inline Vector3 getLeftVector( void ) const;
	inline Vector3 getRightVector( void ) const;
	inline Vector3 getForwardVector( void ) const;
	inline Vector3 getBackVector( void ) const;
	inline void inverse( void );
	inline void transpose( void );
	inline void negate( void );
	inline Matrix3 getInversed( void ) const;
	inline Matrix3 getTransposed( void ) const;
	inline Matrix3 getNegated( void ) const;
	inline float determinant( void ) const;
};

NS_MAGICAL_END

#endif //__MATRIX3_H__