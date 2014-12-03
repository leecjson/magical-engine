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
#ifndef __MAT4_H__
#define __MAT4_H__

class Vec3;
class Vec4;
class AxisAngle;
class Quaternion;
class EulerAngles;

class Mat4
{
public:
	float m11, m12, m13, m14;
	float m21, m22, m23, m24;
	float m31, m32, m33, m34;
	float m41, m42, m43, m44;

public:
	static const Mat4 Identity;
	static Mat4 placeholder;
	static Mat4 temp;

public:
	Mat4( const float* m );
	Mat4( const Mat4& m );
	Mat4( void );
	Mat4( const float rm11, const float rm12, const float rm13, const float rm14,
          const float rm21, const float rm22, const float rm23, const float rm24,
          const float rm31, const float rm32, const float rm33, const float rm34,
          const float rm41, const float rm42, const float rm43, const float rm44 );
	inline void fill(
          const float rm11, const float rm12, const float rm13, const float rm14,
          const float rm21, const float rm22, const float rm23, const float rm24,
          const float rm31, const float rm32, const float rm33, const float rm34,
          const float rm41, const float rm42, const float rm43, const float rm44 );

public:
	static inline void mul( Mat4& out, const Mat4& m, const float a );
	static inline void mul( Mat4& out, const Mat4& m1, const Mat4& m2 );

	static inline void translate( Mat4& out, const Mat4& m, const float x, const float y, const float z );
	static inline void translate( Mat4& out, const Mat4& m, const Vec3& t );
	static inline void scale( Mat4& out, const Mat4& m, const float x, const float y, const float z );
	static inline void scale( Mat4& out, const Mat4& m, const Vec3& s );
	static inline void rotateX( Mat4& out, const Mat4& m, const float angle );
	static inline void rotateY( Mat4& out, const Mat4& m, const float angle );
	static inline void rotateZ( Mat4& out, const Mat4& m, const float angle );
	static inline void rotateQuaternion( Mat4& out, const Mat4& m, const Quaternion& q );
	static inline void rotateEulerAngles( Mat4& out, const Mat4& m, const float yaw, const float pitch, const float roll );
	static inline void rotateEulerAngles( Mat4& out, const Mat4& m, const EulerAngles& ea );
	static inline void rotateAxisAngle( Mat4& out, const Mat4& m, const Vec3& axis, const float angle );
	static inline void rotateAxisAngle( Mat4& out, const Mat4& m, const AxisAngle& aa );

	static inline void getUpVector( Vec3& out, const Mat4& m );
	static inline void getDownVector( Vec3& out, const Mat4& m );
	static inline void getLeftVector( Vec3& out, const Mat4& m );
	static inline void getRightVector( Vec3& out, const Mat4& m );
	static inline void getForwardVector( Vec3& out, const Mat4& m );
	static inline void getBackVector( Vec3& out, const Mat4& m );
	static inline void getTranslation( Vec3& out, const Mat4& m );
	static inline void getScale( Vec3& out, const Mat4& m );
	static inline void getRotationQuaternion( Quaternion& out, const Mat4& m );

	static inline bool inverse( Mat4& out, const Mat4& m );
	static inline void transpose( Mat4& out, const Mat4& m );
	static inline void negate( Mat4& out, const Mat4& m );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Mat4& m ) const;
	inline bool operator!=( const Mat4& m ) const;
	inline Mat4 operator*( const float a ) const;
	inline Mat4 operator*( const Mat4& m ) const;
	inline Mat4& operator*=( const float a );
	inline Mat4& operator*=( const Mat4& m );
	inline Mat4& operator=( const Mat4& m );

public:
	inline bool isEquals( const Mat4& m ) const;
	inline bool isIdentity( void ) const;
	inline void fill( const float* m );
	inline void fill( const Mat4& m );
	inline void fillIdentity( void );
	inline void fillTranslation( const float x, const float y, const float z );
	inline void fillTranslation( const Vec3& t );
	inline void fillScale( const float x, const float y, const float z );
	inline void fillScale( const Vec3& s );
	inline void fillRotationX( const float angle );
	inline void fillRotationY( const float angle );
	inline void fillRotationZ( const float angle );
	inline void fillRotationQuaternion( const Quaternion& q );
	inline void fillRotationEulerAngles( const float yaw, const float pitch, const float roll );
	inline void fillRotationEulerAngles( const EulerAngles& ea );
	inline void fillRotationAxisAngle( const Vec3& axis, const float angle );
	inline void fillRotationAxisAngle( const AxisAngle& aa );
	inline void fillLookAt( const Vec3& eye, const Vec3& target, const Vec3& up );
	inline void fillPerspective( const float fov, const float aspect, const float znear, const float zfar );
	inline void fillOrthographic( const float left, const float right, const float bottom, const float top, const float near, const float far );
	
	inline void translate( const float x, const float y, const float z );
	inline void translate( const Vec3& t );
	inline void scale( const float x, const float y, const float z );
	inline void scale( const Vec3& s );
	inline void rotateX( const float angle );
	inline void rotateY( const float angle );
	inline void rotateZ( const float angle );
	inline void rotateQuaternion( const Quaternion& q );
	inline void rotateEulerAngles( const float yaw, const float pitch, const float roll );
	inline void rotateEulerAngles( const EulerAngles& ea );
	inline void rotateAxisAngle( const Vec3& axis, const float angle );
	inline void rotateAxisAngle( const AxisAngle& aa );

	inline Vec3 getUpVector( void ) const;
	inline Vec3 getDownVector( void ) const;
	inline Vec3 getLeftVector( void ) const;
	inline Vec3 getRightVector( void ) const;
	inline Vec3 getForwardVector( void ) const;
	inline Vec3 getBackVector( void ) const;
	inline void setTranslation( const float x, const float y, const float z );
	inline Vec3 getTranslation( void ) const;
	inline Vec3 getScale( void ) const;
	inline Quaternion getRotationQuaternion( void ) const;
	
	inline bool inverse( void );
	inline void transpose( void );
	inline void negate( void );

	inline bool getInverse( Mat4& out ) const;
	inline Mat4 getTanspose( void ) const;
	inline Mat4 getNegate( void ) const;
	
	inline float determinant( void ) const;
};

#include "../c/cMat4.h"
#include "Vec3.h"
#include "Vec4.h"
#include "AxisAngle.h"
#include "Quaternion.h"
#include "EulerAngles.h"
#include "Mat4.inl"


#endif //__MAT4_H__