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

NAMESPACE_END

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

NAMESPACE_MAGICAL

const Matrix3x3 Matrix3x3::Identity = Matrix3x3( 1.0f );
const Matrix3x3 Matrix3x3::Zero = Matrix3x3( 0.0f );

void Matrix3x3::mul( Matrix3x3& out, const Matrix3x3& m1, const Matrix3x3& m2 )
{
	Matrix3x3 dst;

	dst.m11 = m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31;
	dst.m12 = m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32;
	dst.m13 = m1.m11 * m2.m13 + m1.m12 * m2.m23 + m1.m13 * m2.m33;
	dst.m21 = m1.m21 * m2.m11 + m1.m22 * m2.m21 + m1.m23 * m2.m31;
	dst.m22 = m1.m21 * m2.m12 + m1.m22 * m2.m22 + m1.m23 * m2.m32;
	dst.m23 = m1.m21 * m2.m13 + m1.m22 * m2.m23 + m1.m23 * m2.m33;
	dst.m31 = m1.m31 * m2.m11 + m1.m32 * m2.m21 + m1.m33 * m2.m31;
	dst.m32 = m1.m31 * m2.m12 + m1.m32 * m2.m22 + m1.m33 * m2.m32;
	dst.m33 = m1.m31 * m2.m13 + m1.m32 * m2.m23 + m1.m33 * m2.m33;

	memcpy( &out, &dst, sizeof( Matrix3x3 ) );
}

inline bool Matrix3x3::equals( const Matrix3x3& m ) const
{
	if( !Math::isAlmostEqual( m11, m.m11, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m12, m.m12, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m13, m.m13, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m21, m.m21, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m22, m.m22, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m23, m.m23, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m31, m.m31, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m32, m.m32, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m33, m.m33, Math::VectorEpsilon ) ) return false;

	return true;
}

inline bool Matrix3x3::isZero( void ) const
{
	if( !Math::isAlmostZero( m11, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m12, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m13, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m21, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m22, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m23, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m31, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m32, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostZero( m33, Math::VectorEpsilon ) ) return false;

	return true;
}

inline bool Matrix3x3::isIdentity( void ) const
{
	if( !Math::isAlmostEqual( m11, 1.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m12, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m13, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m21, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m22, 1.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m23, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m31, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m32, 0.0f, Math::VectorEpsilon ) ) return false;
	if( !Math::isAlmostEqual( m33, 1.0f, Math::VectorEpsilon ) ) return false;

	return true;
}

void Matrix3x3::setLookAt( const Vector3& eye, const Vector3& target, const Vector3& up )
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

	m11 = x_axis.x; m12 = y_axis.x; m13 = z_axis.x;
	m21 = x_axis.y; m22 = y_axis.y; m23 = z_axis.y;
	m31 = x_axis.z; m32 = y_axis.z; m33 = z_axis.z;
}

void Matrix3x3::setRotationX( float a )
{
	float s, c;
	Math::sinCos( s, c, a );

	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 =    c; m23 =    s;
	m31 = 0.0f; m32 =  - s; m33 =    c;
}

void Matrix3x3::setRotationY( float a )
{
	float s, c;
	Math::sinCos( s, c, a );

	m11 =    c; m12 = 0.0f; m13 =  - s;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
	m31 =    s; m32 = 0.0f; m33 =    c;
}

void Matrix3x3::setRotationZ( float a )
{
	float s, c;
	Math::sinCos( s, c, a );

	m11 =    c; m12 =    s; m13 = 0.0f;
	m21 =  - s; m22 =    c; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
}

void Matrix3x3::setRotation( const Vector3& axis, float angle )
{
	float s, c;
	Math::sinCos( s, c, angle );

	float at = 1.0f - c;
	float ax = at * axis.x;
	float ay = at * axis.y;
	float az = at * axis.z;

	m11 = ax * axis.x + c;
	m12 = ax * axis.y + axis.z * s;
	m13 = ax * axis.z - axis.y * s;
	m21 = ay * axis.x - axis.z * s;
	m22 = ay * axis.y + c;
	m23 = ay * axis.z + axis.x * s;
	m31 = az * axis.x + axis.y * s;
	m32 = az * axis.y - axis.x * s;
	m33 = az * axis.z + c;
}

void Matrix3x3::setRotation( const Rotater& ea )
{
	Rotater dst;
	Rotater::limit( dst, ea );

	float sp, sr, sy;
	float cp, cr, cy;

	Math::sinCos( sy, cy, dst.yaw );
	Math::sinCos( sp, cp, dst.pitch );
	Math::sinCos( sr, cr, dst.roll );

	m11 =   cy * cr + sy * sp * sr;
	m12 = - cy * sr + sy * sp * cr;
	m13 =   sy * cp;
	m21 =   sr * cp;
	m22 =   cr * cp;
	m23 = - sp;
	m31 = - sy * cr + cy * sp * sr;
	m32 =   sr * sy + cy * sp * cr;
	m33 =   cy * cp;
}

void Matrix3x3::setRotation( const Quaternion& q )
{
	m11 = 1.0f - 2.0f * ( q.y * q.y + q.z * q.z );
	m12 = 2.0f * ( q.x * q.y + q.z * q.w );
	m13 = 2.0f * ( q.x * q.z - q.y * q.w );
	m21 = 2.0f * ( q.x * q.y - q.z * q.w );
	m22 = 1.0f - 2.0f * ( q.x * q.x + q.z * q.z );
	m23 = 2.0f * ( q.z * q.y + q.x * q.w );
	m31 = 2.0f * ( q.x * q.z + q.y * q.w );
	m32 = 2.0f * ( q.y * q.z - q.x * q.w );
	m33 = 1.0f - 2.0f * ( q.x * q.x + q.y * q.y );
}

void Matrix3x3::inverse( Matrix3x3& out, const Matrix3x3& m )
{
	float det =
		m.m11 * ( m.m22 * m.m33 - m.m23 * m.m32 ) + 
		m.m12 * ( m.m23 * m.m31 - m.m21 * m.m33 ) +
		m.m13 * ( m.m21 * m.m32 - m.m22 * m.m31 );

	Matrix3x3 adj;
	
	if( Math::isAlmostZero( det, Math::VectorEpsilon ) )
	{
		if( m != out )
			memcpy( &out, &m, sizeof( Matrix3x3 ) );

		return;
	}
		
	adj.m11 =   m.m22 * m.m33 - m.m23 * m.m32;
	adj.m21 = - m.m21 * m.m33 - m.m23 * m.m31;
	adj.m31 =   m.m21 * m.m32 - m.m22 * m.m31;
	adj.m12 = - m.m12 * m.m33 - m.m13 * m.m32;
	adj.m22 =   m.m11 * m.m33 - m.m13 * m.m31;
	adj.m32 = - m.m11 * m.m32 - m.m12 * m.m31;
	adj.m13 =   m.m12 * m.m23 - m.m13 * m.m22;
	adj.m23 = - m.m11 * m.m23 - m.m13 * m.m21;
	adj.m33 =   m.m11 * m.m22 - m.m12 * m.m21;

	Matrix3x3::mulScalar( out, adj, 1.0f / det );
}

void Matrix3x3::transpose( Matrix3x3& out, const Matrix3x3& m )
{
	float t[9];

	t[0] = m.m11; t[1] = m.m21; t[2] = m.m31;
	t[3] = m.m12; t[4] = m.m22; t[5] = m.m32;
	t[6] = m.m13; t[7] = m.m23; t[8] = m.m33;

	out.m11 = t[0]; out.m12 = t[1]; out.m13 = t[2];
	out.m21 = t[2]; out.m22 = t[3]; out.m23 = t[4];
	out.m31 = t[5]; out.m32 = t[6]; out.m33 = t[7];
}

void Matrix3x3::negate( Matrix3x3& out, const Matrix3x3& m )
{
	out.m11 = -m.m11; out.m12 = -m.m12; out.m13 = -m.m13;
	out.m21 = -m.m21; out.m22 = -m.m22; out.m23 = -m.m23;
	out.m31 = -m.m31; out.m32 = -m.m32; out.m33 = -m.m33;
}

NAMESPACE_END