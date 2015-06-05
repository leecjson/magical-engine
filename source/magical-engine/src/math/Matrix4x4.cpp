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
#include "MathUtils.h"
#include <memory.h>

NAMESPACE_MAGICAL

struct Vector2;
struct Vector3;
struct Vector4;
struct Rotater;
struct Quaternion;
struct Matrix3x3;
struct Matrix4x4;

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Rotater.h"
#include "Quaternion.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"

#include "Vector2.inl"
#include "Vector3.inl"
#include "Vector4.inl"
#include "Rotater.inl"
#include "Quaternion.inl"
#include "Matrix3x3.inl"
#include "Matrix4x4.inl"

const Matrix4x4 Matrix4x4::Identity = Matrix4x4( 1.0f );
const Matrix4x4 Matrix4x4::Zero = Matrix4x4( 0.0f );

void Matrix4x4::mul( Matrix4x4& out, const Matrix4x4& m1, const Matrix4x4& m2 )
{
	Matrix4x4 dst;

	dst.m11 = m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31 + m1.m14 * m2.m41;
	dst.m12 = m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32 + m1.m14 * m2.m42;
	dst.m13 = m1.m11 * m2.m13 + m1.m12 * m2.m23 + m1.m13 * m2.m33 + m1.m14 * m2.m43;
	dst.m14 = m1.m11 * m2.m14 + m1.m12 * m2.m24 + m1.m13 * m2.m34 + m1.m14 * m2.m44;
	dst.m21 = m1.m21 * m2.m11 + m1.m22 * m2.m21 + m1.m23 * m2.m31 + m1.m24 * m2.m41;
	dst.m22 = m1.m21 * m2.m12 + m1.m22 * m2.m22 + m1.m23 * m2.m32 + m1.m24 * m2.m42;
	dst.m23 = m1.m21 * m2.m13 + m1.m22 * m2.m23 + m1.m23 * m2.m33 + m1.m24 * m2.m43;
	dst.m24 = m1.m21 * m2.m14 + m1.m22 * m2.m24 + m1.m23 * m2.m34 + m1.m24 * m2.m44;
	dst.m31 = m1.m31 * m2.m11 + m1.m32 * m2.m21 + m1.m33 * m2.m31 + m1.m34 * m2.m41;
	dst.m32 = m1.m31 * m2.m12 + m1.m32 * m2.m22 + m1.m33 * m2.m32 + m1.m34 * m2.m42;
	dst.m33 = m1.m31 * m2.m13 + m1.m32 * m2.m23 + m1.m33 * m2.m33 + m1.m34 * m2.m43;
	dst.m34 = m1.m31 * m2.m14 + m1.m32 * m2.m24 + m1.m33 * m2.m34 + m1.m34 * m2.m44;
	dst.m41 = m1.m41 * m2.m11 + m1.m42 * m2.m21 + m1.m43 * m2.m31 + m1.m44 * m2.m41;
	dst.m42 = m1.m41 * m2.m12 + m1.m42 * m2.m22 + m1.m43 * m2.m32 + m1.m44 * m2.m42;
	dst.m43 = m1.m41 * m2.m13 + m1.m42 * m2.m23 + m1.m43 * m2.m33 + m1.m44 * m2.m43;
	dst.m44 = m1.m41 * m2.m14 + m1.m42 * m2.m24 + m1.m43 * m2.m34 + m1.m44 * m2.m44;

	memcpy( &out, &dst, sizeof( Matrix4x4 ) );
}

void Matrix4x4::mul3x4( Matrix4x4& out, const Matrix4x4& m1, const Matrix4x4& m2 )
{
	Matrix4x4 dst;

	dst.m11 = m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31;
	dst.m12 = m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32;
	dst.m13 = m1.m11 * m2.m13 + m1.m12 * m2.m23 + m1.m13 * m2.m33;
	dst.m14 = 0.0f;
	dst.m21 = m1.m21 * m2.m11 + m1.m22 * m2.m21 + m1.m23 * m2.m31;
	dst.m22 = m1.m21 * m2.m12 + m1.m22 * m2.m22 + m1.m23 * m2.m32;
	dst.m23 = m1.m21 * m2.m13 + m1.m22 * m2.m23 + m1.m23 * m2.m33;
	dst.m24 = 0.0f;
	dst.m31 = m1.m31 * m2.m11 + m1.m32 * m2.m21 + m1.m33 * m2.m31;
	dst.m32 = m1.m31 * m2.m12 + m1.m32 * m2.m22 + m1.m33 * m2.m32;
	dst.m33 = m1.m31 * m2.m13 + m1.m32 * m2.m23 + m1.m33 * m2.m33;
	dst.m34 = 0.0f;
	dst.m41 = m1.m41 * m2.m11 + m1.m42 * m2.m21 + m1.m43 * m2.m31 + m2.m41;
	dst.m42 = m1.m41 * m2.m12 + m1.m42 * m2.m22 + m1.m43 * m2.m32 + m2.m42;
	dst.m43 = m1.m41 * m2.m13 + m1.m42 * m2.m23 + m1.m43 * m2.m33 + m2.m43;
	dst.m44 = 1.0f;

	memcpy( &out, &dst, sizeof( Matrix4x4 ) );
}

bool Matrix4x4::equals( const Matrix4x4& m ) const
{
	if( !Math::isAlmostEqual( m11, m.m11, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m12, m.m12, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m13, m.m13, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m14, m.m14, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m21, m.m21, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m22, m.m22, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m23, m.m23, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m24, m.m24, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m31, m.m31, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m32, m.m32, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m33, m.m33, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m34, m.m34, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m41, m.m41, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m42, m.m42, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m43, m.m43, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m44, m.m44, Math::VectorEpsilon ) ) return false;

	return true;
}

bool Matrix4x4::isZero( void ) const
{
	if( !Math::isAlmostZero( m11, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m12, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m13, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m14, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m21, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m22, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m23, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m24, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m31, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m32, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m33, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m34, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m41, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m42, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m43, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m44, Math::VectorEpsilon ) ) return false;

	return true;
}

bool Matrix4x4::isIdentity( void ) const
{
	if( !Math::isAlmostEqual( m11, 1.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m12, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m13, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m14, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m21, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m22, 1.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m23, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m24, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m31, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m32, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m33, 1.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m34, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m41, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m42, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m43, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m44, 1.0f, Math::VectorEpsilon ) ) return false;

	return true;
}

void Matrix4x4::setLookAt( const Vector3& eye, const Vector3& target, const Vector3& up )
{
	Vector3 up_v = up;
	Vector3 x_axis, y_axis, z_axis;

	Vector3::normalize( up_v, up_v );

	Vector3::sub( z_axis, eye, target );
	Vector3::normalize( z_axis, z_axis );

	Vector3::cross( x_axis, up_v, z_axis );
	Vector3::normalize( x_axis, x_axis );

	Vector3::cross( y_axis, z_axis, x_axis );
	Vector3::normalize( y_axis, y_axis );

	m11 = x_axis.x; m12 = y_axis.x; m13 = z_axis.x; m14 = 0.0f;
	m21 = x_axis.y; m22 = y_axis.y; m23 = z_axis.y; m24 = 0.0f;
	m31 = x_axis.z; m32 = y_axis.z; m33 = z_axis.z; m34 = 0.0f;

	m41 = - Vector3::dot( x_axis, eye );
	m42 = - Vector3::dot( y_axis, eye );
	m43 = - Vector3::dot( z_axis, eye );
	m44 = 1.0f;
}

void Matrix4x4::setPerspective( float fov, float aspect, float znear, float zfar )
{
	float zoom_x;
	float zoom_y;
	float factor;

	factor = tanf( Math::rad( fov ) * 0.5f );
	debugassert( !Math::isAlmostZero( factor, Math::VectorEpsilon ) && !Math::isAlmostZero( aspect, Math::VectorEpsilon ), "division by 0.f" );

	zoom_y = 1.0f / factor;
	zoom_x = zoom_y / aspect;
	debugassert( !Math::isAlmostZero( zfar - znear, Math::VectorEpsilon ), "division by 0.f" );

	m11 = zoom_x;
	m12 = 0.0f;
	m13 = 0.0f;
	m14 = 0.0f;

	m21 = 0.0f;
	m22 = zoom_y;
	m23 = 0.0f;
	m24 = 0.0f;

	m31 = 0.0f;
	m32 = 0.0f;
	m33 = ( zfar + znear ) / ( zfar - znear );
	m34 = 1.0f;

	m41 = 0.0f;
	m42 = 0.0f;
	m43 = ( 2.0f * znear * zfar ) / ( znear - zfar );
	m44 = 0.0f;
}

void Matrix4x4::setOrtho( float left, float right, float bottom, float top, float znear, float zfar )
{
	debugassert( !Math::isAlmostZero( right - left, Math::VectorEpsilon ) && !Math::isAlmostZero( top - bottom, Math::VectorEpsilon ) && !Math::isAlmostZero( zfar - znear, Math::VectorEpsilon ), "division by 0.f" );

	m11 = 2.0f / ( right - left );
	m12 = 0.0f;
	m13 = 0.0f;
	m14 = 0.0f;

	m21 = 0.0f;
	m22 = 2.0f / ( top - bottom );
	m23 = 0.0f;
	m24 = 0.0f;

	m31 = 0.0f;
	m32 = 0.0f;
	m33 = - 2.0f / ( zfar - znear );
	m34 = 0.0f;

	m41 = - ( right + left ) / ( right - left );
	m42 = - ( top + bottom ) / ( top - bottom );
	m43 = - ( zfar + znear ) / ( zfar - znear );
	m44 = 1.0f;
}

void Matrix4x4::setTrs( const Vector3& t, const Quaternion& r, const Vector3& s )
{
	Matrix3x3 dst;

	dst.m11 = 1.0f - 2.0f * ( r.y * r.y + r.z * r.z );
	dst.m12 = 2.0f * ( r.x * r.y + r.z * r.w );
	dst.m13 = 2.0f * ( r.x * r.z - r.y * r.w );

	dst.m21 = 2.0f * ( r.x * r.y - r.z * r.w );
	dst.m22 = 1.0f - 2.0f * ( r.x * r.x + r.z * r.z );
	dst.m23 = 2.0f * ( r.z * r.y + r.x * r.w );

	dst.m31 = 2.0f * ( r.x * r.z + r.y * r.w );
	dst.m32 = 2.0f * ( r.y * r.z - r.x * r.w );
	dst.m33 = 1.0f - 2.0f * ( r.x * r.x + r.y * r.y );

	m11 = dst.m11 * s.x; m12 = dst.m12 * s.y; m13 = dst.m13 * s.z; m14 = 0.0f;
	m21 = dst.m21 * s.x; m22 = dst.m22 * s.y; m23 = dst.m23 * s.z; m24 = 0.0f;
	m31 = dst.m31 * s.x; m32 = dst.m32 * s.y; m33 = dst.m33 * s.z; m34 = 0.0f;
	m41 = t.x;           m42 = t.y;           m43 = t.z;           m44 = 1.0f;
}

void Matrix4x4::setTranslation( const Vector3& t )
{
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f; m24 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f; m34 = 0.0f;
	m41 = t.x ; m42 = t.y ; m43 = t.z ; m44 = 1.0f;
}

void Matrix4x4::setScale( const Vector3& s )
{
	m11 = s.x ; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
	m21 = 0.0f; m22 = s.y ; m23 = 0.0f; m24 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = s.z ; m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = 1.0f;
}

void Matrix4x4::setRotation( const Quaternion& q )
{
	m11 = 1.0f - 2.0f * ( q.y * q.y + q.z * q.z );
	m12 = 2.0f * ( q.x * q.y + q.z * q.w );
	m13 = 2.0f * ( q.x * q.z - q.y * q.w );
	m14 = 0.0f;

	m21 = 2.0f * ( q.x * q.y - q.z * q.w );
	m22 = 1.0f - 2.0f * ( q.x * q.x + q.z * q.z );
	m23 = 2.0f * ( q.z * q.y + q.x * q.w );
	m24 = 0.0f;

	m31 = 2.0f * ( q.x * q.z + q.y * q.w );
	m32 = 2.0f * ( q.y * q.z - q.x * q.w );
	m33 = 1.0f - 2.0f * ( q.x * q.x + q.y * q.y );
	m34 = 0.0f;

	m41 = 0.0f;
	m42 = 0.0f;
	m43 = 0.0f;
	m44 = 1.0f;
}

void Matrix4x4::setRotationX( float a )
{
	float s, c;
	Math::sinCos( s, c, a );

	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
	m21 = 0.0f; m22 =    c; m23 =    s; m24 = 0.0f;
	m31 = 0.0f; m32 =  - s; m33 =    c; m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = 1.0f;
}

void Matrix4x4::setRotationY( float a )
{
	float s, c;
	Math::sinCos( s, c, a );

	m11 =    c; m12 = 0.0f; m13 =  - s; m14 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f; m24 = 0.0f;
	m31 =    s; m32 = 0.0f; m33 =    c; m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = 1.0f;
}

void Matrix4x4::setRotationZ( float a )
{
	float s, c;
	Math::sinCos( s, c, a );

	m11 =    c; m12 =    s; m13 = 0.0f; m14 = 0.0f;
	m21 =  - s; m22 =    c; m23 = 0.0f; m24 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f; m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = 1.0f;
}

void Matrix4x4::inverse( Matrix4x4& out, const Matrix4x4& m )
{
	float det;

	float a0 = m.m11 * m.m22 - m.m12 * m.m21;
    float a1 = m.m11 * m.m23 - m.m13 * m.m21;
    float a2 = m.m11 * m.m24 - m.m14 * m.m21;
    float a3 = m.m12 * m.m23 - m.m13 * m.m22;
    float a4 = m.m12 * m.m24 - m.m14 * m.m22;
    float a5 = m.m13 * m.m24 - m.m14 * m.m23;
    float b0 = m.m31 * m.m42 - m.m32 * m.m41;
    float b1 = m.m31 * m.m43 - m.m33 * m.m41;
    float b2 = m.m31 * m.m44 - m.m34 * m.m41;
    float b3 = m.m32 * m.m43 - m.m33 * m.m42;
    float b4 = m.m32 * m.m44 - m.m34 * m.m42;
    float b5 = m.m33 * m.m44 - m.m34 * m.m43;

	det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

	if( Math::isAlmostZero( det, Math::VectorEpsilon ) )
	{
		if( m != out )
			memcpy( &out, &m, sizeof( Matrix4x4 ) );

		return;
	}

	Matrix4x4 adj;

	adj.m11 =   m.m22 * b5 - m.m23 * b4 + m.m24 * b3;
    adj.m12 = - m.m12 * b5 + m.m13 * b4 - m.m14 * b3;
    adj.m13 =   m.m42 * a5 - m.m43 * a4 + m.m44 * a3;
    adj.m14 = - m.m32 * a5 + m.m33 * a4 - m.m34 * a3;
    adj.m21 = - m.m21 * b5 + m.m23 * b2 - m.m24 * b1;
    adj.m22 =   m.m11 * b5 - m.m13 * b2 + m.m14 * b1;
    adj.m23 = - m.m41 * a5 + m.m43 * a2 - m.m44 * a1;
    adj.m24 =   m.m31 * a5 - m.m33 * a2 + m.m34 * a1;
    adj.m31 =   m.m21 * b4 - m.m22 * b2 + m.m24 * b0;
    adj.m32 = - m.m11 * b4 + m.m12 * b2 - m.m14 * b0;
    adj.m33 =   m.m41 * a4 - m.m42 * a2 + m.m44 * a0;
    adj.m34 = - m.m31 * a4 + m.m32 * a2 - m.m34 * a0;
    adj.m41 = - m.m21 * b3 + m.m22 * b1 - m.m23 * b0;
    adj.m42 =   m.m11 * b3 - m.m12 * b1 + m.m13 * b0;
    adj.m43 = - m.m41 * a3 + m.m42 * a1 - m.m43 * a0;
    adj.m44 =   m.m31 * a3 - m.m32 * a1 + m.m33 * a0;

	Matrix4x4::mulScalar( out, adj, 1.0f / det );
}

void Matrix4x4::transpose( Matrix4x4& out, const Matrix4x4& m )
{
	float t[16];

	t[0]  = m.m11; t[1]  = m.m21; t[2]  = m.m31; t[3]  = m.m41;
	t[4]  = m.m12; t[5]  = m.m22; t[6]  = m.m32; t[7]  = m.m42;
	t[8]  = m.m13; t[9]  = m.m23; t[10] = m.m33; t[11] = m.m43;
	t[12] = m.m14; t[13] = m.m24; t[14] = m.m34; t[15] = m.m44;

	memcpy( &out, t, sizeof( Matrix4x4 ) );
}

void Matrix4x4::negate( Matrix4x4& out, const Matrix4x4& m )
{
	out.m11 = -m.m11; out.m12 = -m.m12; out.m13 = -m.m13; out.m14 = -m.m14;
	out.m21 = -m.m21; out.m22 = -m.m22; out.m23 = -m.m23; out.m24 = -m.m24;
	out.m31 = -m.m31; out.m32 = -m.m32; out.m33 = -m.m33; out.m34 = -m.m34;
	out.m41 = -m.m41; out.m42 = -m.m42; out.m43 = -m.m43; out.m44 = -m.m44;
}

NAMESPACE_END