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
#ifndef __MATRIX4_H__
#define __MATRIX4_H__

class Vector3;
class Vector4;
class AxisA;
class EulerA;
class Quaternion;

class Matrix4
{
public:
	float m11, m12, m13, m14;
	float m21, m22, m23, m24;
	float m31, m32, m33, m34;
	float m41, m42, m43, m44;

public:
	static const Matrix4 Identity;
	static const Matrix4 Zero;
	static Matrix4 placeholder;
	static Matrix4 temp;

public:
	Matrix4( const float* m );
	Matrix4( const float m11, const float m12, const float m13, const float m14,
             const float m21, const float m22, const float m23, const float m24,
             const float m31, const float m32, const float m33, const float m34,
             const float m41, const float m42, const float m43, const float m44 );
	Matrix4( const Matrix4& m );
	Matrix4( void );

public:
	static inline Matrix4 fromIdentity( void );
	static inline Matrix4 fromZero( void );

	static inline void mulScalar( Matrix4& out, const Matrix4& m, const float a );
	static inline void mul( Matrix4& out, const Matrix4& m1, const Matrix4& m2 );

	static inline void translate( Matrix4& out, const Matrix4& m, const float x, const float y, const float z );
	static inline void translate( Matrix4& out, const Matrix4& m, const Vector3& t );
	static inline void scale( Matrix4& out, const Matrix4& m, const float x, const float y, const float z );
	static inline void scale( Matrix4& out, const Matrix4& m, const Vector3& s );
	static inline void rotateX( Matrix4& out, const Matrix4& m, const float angle );
	static inline void rotateY( Matrix4& out, const Matrix4& m, const float angle );
	static inline void rotateZ( Matrix4& out, const Matrix4& m, const float angle );
	static inline void rotateAxisA( Matrix4& out, const Matrix4& m, const Vector3& axis, const float angle );
	static inline void rotateAxisA( Matrix4& out, const Matrix4& m, const AxisA& aa );
	static inline void rotateEulerA( Matrix4& out, const Matrix4& m, const float yaw, const float pitch, const float roll );
	static inline void rotateEulerA( Matrix4& out, const Matrix4& m, const EulerA& ea );
	static inline void rotateQuaternion( Matrix4& out, const Matrix4& m, const Quaternion& q );
	
	static inline void getUpVector( Vector3& out, const Matrix4& m );
	static inline void getDownVector( Vector3& out, const Matrix4& m );
	static inline void getLeftVector( Vector3& out, const Matrix4& m );
	static inline void getRightVector( Vector3& out, const Matrix4& m );
	static inline void getForwardVector( Vector3& out, const Matrix4& m );
	static inline void getBackVector( Vector3& out, const Matrix4& m );
	static inline void getTranslation( Vector3& out, const Matrix4& m );
	static inline void getScale( Vector3& out, const Matrix4& m );
	static inline void getRotationQuaternion( Quaternion& out, const Matrix4& m );
	static inline bool inverse( Matrix4& out, const Matrix4& m );
	static inline void transpose( Matrix4& out, const Matrix4& m );
	static inline void negate( Matrix4& out, const Matrix4& m );

public:
	inline bool equals( const Matrix4& m ) const;
	inline bool isZero( void ) const;
	inline bool isIdentity( void ) const;
	inline void fill( const float* m );
	inline void fill( const Matrix4& m );
	inline void fillIdentity( void );
	inline void fillTranslation( const float x, const float y, const float z );
	inline void fillTranslation( const Vector3& t );
	inline void fillScale( const float x, const float y, const float z );
	inline void fillScale( const Vector3& s );
	inline void fillRotationX( const float angle );
	inline void fillRotationY( const float angle );
	inline void fillRotationZ( const float angle );
	inline void fillRotationAxisA( const Vector3& axis, const float angle );
	inline void fillRotationAxisA( const AxisA& aa );
	inline void fillRotationEulerA( const float yaw, const float pitch, const float roll );
	inline void fillRotationEulerA( const EulerA& ea );
	inline void fillRotationQuaternion( const Quaternion& q );
	inline void fillLookAt( const Vector3& eye, const Vector3& target, const Vector3& up );
	inline void fillPerspective( const float fov, const float aspect, const float znear, const float zfar );
	inline void fillOrthographic( const float left, const float right, const float bottom, const float top, const float near, const float far );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Matrix4& m ) const;
	inline bool operator!=( const Matrix4& m ) const;
	inline float operator[]( const unsigned int i ) const;
	inline Matrix4 operator*( const float a ) const;
	inline Matrix4 operator*( const Matrix4& m ) const;
	inline Matrix4& operator*=( const float a );
	inline Matrix4& operator*=( const Matrix4& m );
	inline Matrix4& operator=( const Matrix4& m );

public:
	inline void translate( const float x, const float y, const float z );
	inline void translate( const Vector3& t );
	inline void scale( const float x, const float y, const float z );
	inline void scale( const Vector3& s );
	inline void rotateX( const float angle );
	inline void rotateY( const float angle );
	inline void rotateZ( const float angle );
	inline void rotateAxisA( const Vector3& axis, const float angle );
	inline void rotateAxisA( const AxisA& aa );
	inline void rotateEulerA( const float yaw, const float pitch, const float roll );
	inline void rotateEulerA( const EulerA& ea );
	inline void rotateQuaternion( const Quaternion& q );
	inline Vector3 getUpVector( void ) const;
	inline Vector3 getDownVector( void ) const;
	inline Vector3 getLeftVector( void ) const;
	inline Vector3 getRightVector( void ) const;
	inline Vector3 getForwardVector( void ) const;
	inline Vector3 getBackVector( void ) const;
	inline void setTranslation( const float x, const float y, const float z );
	inline Vector3 getTranslation( void ) const;
	inline Vector3 getScale( void ) const;
	inline Quaternion getRotationQuaternion( void ) const;
	inline bool inverse( void );
	inline void transpose( void );
	inline void negate( void );
	inline bool getInversed( Matrix4& out ) const;
	inline Matrix4 getTransposed( void ) const;
	inline Matrix4 getNegated( void ) const;
	inline float determinant( void ) const;
};

#endif //__MATRIX4_H__