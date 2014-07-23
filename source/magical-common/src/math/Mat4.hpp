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

#include "Common.h"
#include "kazmath/kazmath.h"

struct Quaternion;
struct Vec2;
struct Vec3;
struct Vec4;
struct Mat3;
struct Mat4;

struct Mat4 : public kmMat4
{
public:
	Mat4( void );
	~Mat4( void );

	inline Mat4 operator*( const Mat4& rhs ) const;
	inline bool operator==( const Mat4& rhs ) const;
	inline bool operator!=( const Mat4& rhs ) const;

	inline void fill( const float* mat );
	inline void fill( float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44 );
	inline void identity( void );
	inline Mat4 copy( void ) const;
	inline bool isIdentity( void ) const;
	inline Mat4 inverse( void ) const;
	inline Mat4 transpose( void ) const;

	inline void rotationX( float radians );
	inline void rotationY( float radians );
	inline void rotationZ( float radians );
	inline void rotationYawPitchRoll( float pitch, float yaw, float roll );
	inline void rotationQuaternion( const Quaternion& q );
	inline void rotationTranslation( const Mat3& rotation, const Vec3& translation );
	inline void rotationAxisAngle( const Vec3& axis, float radians );
	inline void rotationToAxisAngle( Vec3& out_vec, float& out_radians ) const;
	inline void scaling( float x, float y, float z );
	inline void translation( float x, float y, float z );
	inline Vec3 getUpVec3( void ) const;
	inline Vec3 getRightVec3( void ) const;
	inline Vec3 getForwardVec3RH( void ) const;
	inline Vec3 getForwardVec3LH( void ) const;

	inline void setPerspectiveProjection( float foxy, float aspect, float znear, float zfar );
	inline void setOrthographicProjection( float left, float right, float bottom, float top, float znear, float zfar );
	inline void setLookAt( const Vec3& eye, const Vec3& center, const Vec3& up );
	
public:
	static inline Mat4 create( void );
};

#include "Mat4.inl"

#endif //__MAT4_HPP__