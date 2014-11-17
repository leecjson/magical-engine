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

#include "Vec3.h"
#include "Vec4.h"
#include "Quaternion.h"

struct Vec3;
struct Vec4;
struct Quaternion;

struct Mat4
{
public:
	static const Mat4 Identity;
	static const Mat4 Zero;

public:
	float m[16];

	Mat4( const float* mat );
	Mat4( const Mat4& mat );
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
	~Mat4( void );

	static void* operator new( size_t s );
	static void operator delete( void* ptr );

	inline bool operator==( const Mat4& mat ) const;
	inline bool operator!=( const Mat4& mat ) const;
	inline bool isIdentity( void ) const;
	inline bool isEquals( const Mat4& mat ) const;
	inline Mat4 operator*( const float a ) const;
	inline Mat4 operator*( const Mat4& mat ) const;
	inline Mat4& operator*=( const float a );
	inline Mat4& operator*=( const Mat4& mat );
	inline Mat4& operator=( const Mat4& mat );

	inline Mat4 mul( const float a ) const;
	inline Mat4 mul( const Mat4& mat ) const;
	inline void mulfill( const float a );
	inline void mulfill( const Mat4& mat );
	inline Vec3 transformVec3( const Vec3& v ) const;
	inline Vec4 transformVec4( const Vec4& v ) const;

	inline void fill( const float* mat );
	inline void fill( const Mat4& mat );
	inline void fillIdentity( void );
	inline void fillTranslation( const float x, const float y, const float z );
	inline void fillTranslation( const Vec3& t );
	inline void fillScaling( const float x, const float y, const float z );
	inline void fillScaling( const Vec3& s );
	inline void fillRotationX( const float angle );
	inline void fillRotationY( const float angle );
	inline void fillRotationZ( const float angle );
	inline void fillRotationPitchYawRoll( const float pitch, const float yaw, const float roll );
	inline void fillRotationQuaternion( const Quaternion& r );
	inline void fillRotationAxisAngle( const Vec3& axis, const float angle );
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
	inline void rotatePitchYawRoll( const float pitch, const float yaw, const float roll );
	inline void rotateQuaternion( const Quaternion& r );
	inline void rotateAxisAngle( const Vec3& axis, const float angle );

	inline float determinant( void ) const;
	inline bool inverse( Mat4& out ) const;
	inline Mat4 transpose( void ) const;
	inline void fillTranspose( void );
	inline Mat4 negate( void ) const;
	inline void fillNegate( void );
	
	inline Vec3 getUpVector( void ) const;
	inline Vec3 getDownVector( void ) const;
	inline Vec3 getLeftVector( void ) const;
	inline Vec3 getRightVector( void ) const;
	inline Vec3 getForwardVector( void ) const;
	inline Vec3 getBackVector( void ) const;

	/*bool decompose( Vec3* translation, Quaternion* rotation, Vec3* scale ) const;
	inline Vec3 getTranslation( void ) const;
	inline Quaternion getRotation( void ) const;
	inline Vec3 getScale( void ) const;*/
};

class MathMat4
{
public:
	static inline void mul( Mat4& out, const Mat4& mat, const float a );
	static inline void mul( Mat4& out, const Mat4& mat1, const Mat4& mat2 );
	static inline void transformVec3( Vec3& out, const Mat4& mat, const Vec3& v );
	static inline void transformVec4( Vec4& out, const Mat4& mat, const Vec4& v );

	static inline void transpose( Mat4& out, const Mat4& mat );
	static inline void negate( Mat4& out, const Mat4& mat );
	static inline bool inverse( Mat4& out, const Mat4& mat );
	static inline void translate( Mat4& out, const Mat4& mat, const float x, const float y, const float z );
	static inline void translate( Mat4& out, const Mat4& mat, const Vec3& t );
	static inline void scale( Mat4& out, const Mat4& mat, const float x, const float y, const float z );
	static inline void scale( Mat4& out, const Mat4& mat, const Vec3& s );

	static inline void rotateX( Mat4& out, const Mat4& mat, const float angle );
	static inline void rotateY( Mat4& out, const Mat4& mat, const float angle );
	static inline void rotateZ( Mat4& out, const Mat4& mat, const float angle );
	static inline void rotatePitchYawRoll( Mat4& out, const Mat4& mat, const float pitch, const float yaw, const float roll );
	static inline void rotateQuaternion( Mat4& out, const Mat4& mat, const Quaternion& r );
	static inline void rotateAxisAngle( Mat4& out, const Mat4& mat, const Vec3& axis, const float angle );

	static inline void getUpVector( Vec3& out, const Mat4& mat );
	static inline void getDownVector( Vec3& out, const Mat4& mat );
	static inline void getLeftVector( Vec3& out, const Mat4& mat );
	static inline void getRightVector( Vec3& out, const Mat4& mat );
	static inline void getForwardVector( Vec3& out, const Mat4& mat );
	static inline void getBackVector( Vec3& out, const Mat4& mat );
};

#include "../c/cMat4.h"
#include "Mat4.inl"

#endif //__MAT4_H__