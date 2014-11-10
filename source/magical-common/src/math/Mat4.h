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
#ifndef __MAT4_HPP__
#define __MAT4_HPP__

#include "Math3D.h"
#include "Quaternion.h"
#include "Vec3.h"
#include "Vec4.h"

struct Quaternion;
struct Vec3;
struct Vec4;
class MathQuaternion;
class MathVec3;
class MathVec4;

struct Mat4
{
public:
	static const Mat4 Identity;
	static const Mat4 Zero;

public:
	float m[16];

	Mat4( const float* m );
	Mat4( const Mat4& mat );
	Mat4( void );
	Mat4( float rm11, float rm12, float rm13, float rm14,
          float rm21, float rm22, float rm23, float rm24,
          float rm31, float rm32, float rm33, float rm34,
          float rm41, float rm42, float rm43, float rm44 );
	inline void fill(
          float rm11, float rm12, float rm13, float rm14,
          float rm21, float rm22, float rm23, float rm24,
          float rm31, float rm32, float rm33, float rm34,
          float rm41, float rm42, float rm43, float rm44 );
	~Mat4( void );

public:
	inline bool operator==( const Mat4& mat ) const;
	inline bool operator!=( const Mat4& mat ) const;
	inline bool isIdentity( void ) const;
	inline bool isEquals( const Mat4& mat ) const;

	inline Mat4 operator+( float a ) const;
	inline Mat4 operator+( const Mat4& mat ) const;
	inline Mat4 operator-( float a ) const;
	inline Mat4 operator-( const Mat4& mat ) const;
	inline Mat4 operator*( float a ) const;
	inline Mat4 operator*( const Mat4& mat ) const;
	inline Mat4& operator+=( float a );
	inline Mat4& operator+=( const Mat4& mat );
	inline Mat4& operator-=( float a );
	inline Mat4& operator-=( const Mat4& mat );
	inline Mat4& operator*=( float a );
	inline Mat4& operator*=( const Mat4& mat );
	inline Mat4& operator=( const Mat4& mat );

	Mat4 add( float a ) const;
	Mat4 add( const Mat4& mat ) const;
	Mat4 sub( float a ) const;
	Mat4 sub( const Mat4& mat ) const;
	Mat4 mul( float a ) const;
	Mat4 mul( const Mat4& mat ) const;
	void addfill( float a );
	void addfill( const Mat4& mat );
	void subfill( float a );
	void subfill( const Mat4& mat );
	void mulfill( float a );
	void mulfill( const Mat4& mat );
	inline void fill( const float* m );
	inline void fill( const Mat4& mat );
	inline void fillZero( void );
	inline void fillIdentity( void );
	inline void fillTranslation( float x, float y, float z );
	inline void fillTranslation( const Vec3& t );
	inline void fillRotationX( float angle );
	inline void fillRotationY( float angle );
	inline void fillRotationZ( float angle );
	void fillRotation( const Quaternion& r );
	void fillRotation( const Vec3& axis, float angle );
	inline void fillScale( float x, float y, float z );
	inline void fillScale( const Vec3& s );
	void fillLookAt( const Vec3& eye, const Vec3& target, const Vec3& up );
	void fillPerspective( float fov, float aspect, float znear, float zfar );
	void fillOrthographic( float left, float right, float bottom, float top, float near, float far );
	
public:
	float determinant( void ) const;

public:
	void transpose( void );
	void negate( void );
	inline void translate( float x, float y, float z );
	inline void translate( const Vec3& t );
	inline void rotateX( float angle );
	inline void rotateY( float angle );
	inline void rotateZ( float angle );
	inline void rotate( const Quaternion& r );
	inline void rotate( const Vec3& axis, float angle );
	inline void scale( float s );
	inline void scale( float x, float y, float z );
	inline void scale( const Vec3& s );

	inline Mat4 getTranspose( void ) const;
	inline Mat4 getNegate( void ) const;
	inline bool getInverse( Mat4& out ) const;
	inline Mat4 getTranslate( float x, float y, float z ) const;
	inline Mat4 getTranslate( const Vec3& t ) const;
	inline Mat4 getRotateX( float angle ) const;
	inline Mat4 getRotateY( float angle ) const;
	inline Mat4 getRotateZ( float angle ) const;
	inline Mat4 getRotate( const Quaternion& r ) const;
	inline Mat4 getRotate( const Vec3& axis, float angle ) const;
	inline Mat4 getScale( float s ) const;
	inline Mat4 getScale( float x, float y, float z ) const;
	inline Mat4 getScale( const Vec3& s ) const;

	inline Vec3 getUpVector( void ) const;
	inline Vec3 getDownVector( void ) const;
	inline Vec3 getLeftVector( void ) const;
	inline Vec3 getRightVector( void ) const;
	inline Vec3 getForwardVector( void ) const;
	inline Vec3 getBackVector( void ) const;
	inline Vec3 transformPoint( const Vec3& point ) const;
	Vec3 transformVec3( const Vec3& v ) const;
	Vec4 transformVec4( const Vec4& v ) const;

	bool decompose( Vec3* translation, Quaternion* rotation, Vec3* scale ) const;
	inline Vec3 getTranslation( void ) const;
	inline Quaternion getRotation( void ) const;
	inline Vec3 getScale( void ) const;
};

class MathMat4
{
public:
	static void add( Mat4& out, const Mat4& mat, float a );
	static void add( Mat4& out, const Mat4& mat1, const Mat4& mat2 );
	static void sub( Mat4& out, const Mat4& mat, float a );
	static void sub( Mat4& out, const Mat4& mat1, const Mat4& mat2 );
	static void mul( Mat4& out, const Mat4& mat, float a );
	static void mul( Mat4& out, const Mat4& mat1, const Mat4& mat2 );
	static void transpose( Mat4& out, const Mat4& mat );
	static void negate( Mat4& out, const Mat4& mat );
	static inline bool getInverse( Mat4& out, const Mat4& mat );
	static inline void translate( Mat4& out, const Mat4& mat, float x, float y, float z );
	static inline void translate( Mat4& out, const Mat4& mat, const Vec3& t );
	static inline void rotateX( Mat4& out, const Mat4& mat, float angle );
	static inline void rotateY( Mat4& out, const Mat4& mat, float angle );
	static inline void rotateZ( Mat4& out, const Mat4& mat, float angle );
	static inline void rotate( Mat4& out, const Mat4& mat, const Quaternion& r );
	static inline void rotate( Mat4& out, const Mat4& mat, const Vec3& axis, float angle );
	static inline void scale( Mat4& out, const Mat4& mat, float s );
	static inline void scale( Mat4& out, const Mat4& mat, float x, float y, float z );
	static inline void scale( Mat4& out, const Mat4& mat, const Vec3& s );
	static inline void getUpVector( Vec3& out, const Mat4& mat );
	static inline void getDownVector( Vec3& out, const Mat4& mat );
	static inline void getLeftVector( Vec3& out, const Mat4& mat );
	static inline void getRightVector( Vec3& out, const Mat4& mat );
	static inline void getForwardVector( Vec3& out, const Mat4& mat );
	static inline void getBackVector( Vec3& out, const Mat4& mat );
	static inline void transformPoint( Vec3& out, const Mat4& mat, const Vec3& point );
	static inline void transformVec3( Vec3& out, const Mat4& mat, const Vec3& v );
	static inline void transformVec4( Vec4& out, const Mat4& mat, const Vec4& v );
};

#include "Mat4.inl"

#endif //__MAT4_HPP__