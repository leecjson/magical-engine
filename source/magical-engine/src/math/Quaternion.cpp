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

const Quaternion Quaternion::Identity = Quaternion( 0.0f, 0.0f, 0.0f, 1.0f );
const Quaternion Quaternion::Zero = Quaternion( 0.0f, 0.0f, 0.0f, 0.0f );

void Quaternion::mul( Quaternion& out, const Quaternion& q1, const Quaternion& q2 )
{
#if 0
	// 变换顺序由右到左
	float w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	float x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	float y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	float z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
#else
	// 变换顺序由左到右
	float w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	float x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	float y = q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z;
	float z = q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x;
#endif

	out.w = w;
	out.x = x;
	out.y = y;
	out.z = z;
}

void Quaternion::mulVector3( Vector3& out, const Quaternion& q, const Vector3& v )
{
	// nVidia SDK implementation

	Vector3 qvec, uv, uuv;

	qvec.x = q.x;
	qvec.y = q.y;
	qvec.z = q.z;

	Vector3::cross( uv, qvec, v );
	Vector3::cross( uuv, qvec, uv );

	Vector3::scale( uv, uv, 2.0f * q.w );
	Vector3::scale( uuv, uuv, 2.0f );

	Vector3::add( out, v, uv );
	Vector3::add( out, out, uuv );
}

void Quaternion::setRotationX( float a )
{
	float half_angle = a * 0.5f;

	w = cosf( half_angle );
	x = sinf( half_angle );
	y = 0.0f;
	z = 0.0f;
}

void Quaternion::setRotationY( float a )
{
	float half_angle = a * 0.5f;

	w = cosf( half_angle );
	x = 0.0f;
	y = sinf( half_angle );
	z = 0.0f;
}

void Quaternion::setRotationZ( float a )
{
	float half_angle = a * 0.5f;

	w = cosf( half_angle );
	x = 0.0f;
	y = 0.0f;
	z = sinf( half_angle );
}

void Quaternion::setRotation( const Vector3& axis, float angle )
{
	float half_angle = angle * 0.5f;
	float s = sinf( half_angle );

	Vector3 n;
	Vector3::normalize( n, axis );

	w = cosf( half_angle );
    x = n.x * s;
    y = n.y * s;
    z = n.z * s;
}

void Quaternion::setRotation( const Rotater& ea )
{
	Rotater dst( ea );
	dst.limit();

	float sp, sr, sy;
	float cp, cr, cy;

	Math::sinCos( sp, cp, dst.pitch * 0.5f );
	Math::sinCos( sr, cr, dst.roll * 0.5f );
	Math::sinCos( sy, cy, dst.yaw * 0.5f );

	w =   cy * cp * cr + sy * sp * sr;
	x = - cy * sp * cr - sy * cp * sr;
	y =   cy * sp * sr - sy * cr * cp;
	z =   sy * sp * cr - cy * cp * sr;

	Quaternion::normalize( *this, *this );
}

void Quaternion::setRotation( const Matrix3x3& m )
{
	float s, t;
	t = m.m11 + m.m22 + m.m33 + 1.0f;

	if( t > Math::VectorEpsilon )
	{
		s = 0.5f / sqrtf( t );
		w = 0.25f / s;
		x = ( m.m23 - m.m32 ) * s;
		y = ( m.m31 - m.m13 ) * s;
		z = ( m.m12 - m.m21 ) * s;
	}
	else
	{
		if( m.m11 > m.m21 && m.m11 > m.m33 )
		{
			s = 2.0f * sqrtf( 1.0f + m.m11 - m.m22 - m.m33 );
			w = ( m.m23 - m.m32 ) / s;
			x = 0.25f * s;
			y = ( m.m21 + m.m12 ) / s;
			z = ( m.m31 + m.m13 ) / s;
		}
		else if( m.m22 > m.m33 )
		{
			s = 2.0f * sqrtf( 1.0f + m.m22 - m.m11 - m.m33 );
			w = ( m.m31 - m.m13 ) / s;
			x = ( m.m21 + m.m12 ) / s;
			y = 0.25f * s;
			z = ( m.m32 + m.m23 ) / s;
		}
		else
		{
			s = 2.0f * sqrtf( 1.0f + m.m33 - m.m11 - m.m22 );
			w = ( m.m12 - m.m21 ) / s;
			x = ( m.m31 + m.m13 ) / s;
			y = ( m.m32 + m.m23 ) / s;
			z = 0.25f * s;
		}
	}
}

//Vector4 Quaternion::ToAxisAngle( void ) const
//{
//	Vector4 dst;
//	float scale = sqrtf( x * x + y * y + z * z );
//
//	if( Math::IsAlmostZero( scale, Math::VectorEpsilon ) )
//	{
//		dst.x = 0.0f;
//		dst.y = 0.0f;
//		dst.z = 1.0f;
//		dst.a = 0.0f;
//	}
//	else
//	{
//		scale = 1.0f / scale;
//		dst.x = x * scale;
//		dst.y = y * scale;
//		dst.z = z * scale;
//		dst.a = Math::SafeAcos( w ) * 2.0f;
//	}
//	return dst;
//}

void Quaternion::normalize( Quaternion& out, const Quaternion& q )
{
	out.w = q.w;
	out.x = q.x;
	out.y = q.y;
	out.z = q.z;
	
	float n = q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
	if( Math::isAlmostEqual( n, 1.0f, Math::QuaternionEpsilon ) )
		return;

	n = sqrtf( n );
	if( Math::isAlmostZero( n, Math::QuaternionEpsilon ) )
	{
		//debugassert( cFalse, "if( magicalAlmostZero( n, kEpsilonQuaternion ) )" );
		return;
	}

	n = 1.0f / n;
	out.w *= n;
	out.x *= n;
	out.y *= n;
	out.z *= n;
}

void Quaternion::conjugate( Quaternion& out, const Quaternion& q )
{
	out.w = q.w;
	out.x = - q.x;
	out.y = - q.y;
	out.z = - q.z;
}

void Quaternion::negate( Quaternion& out, const Quaternion& q )
{
	out.w = - q.w;
	out.x = - q.x;
	out.y = - q.y;
	out.z = - q.z;
}

void Quaternion::inverse( Quaternion& out, const Quaternion& q )
{
	out.w = q.w;
	out.x = q.x;
	out.y = q.y;
	out.z = q.z;

	float n = q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
	if( Math::isAlmostEqual( n, 1.0f, Math::QuaternionEpsilon ) )
	{
		out.w = q.w;
		out.x = - q.x;
		out.y = - q.y;
		out.z = - q.z;
		return;
	}

	n = sqrtf( n );
	if( Math::isAlmostZero( n, Math::QuaternionEpsilon ) )
	{
		//debugassert( cFalse, "if( magicalAlmostZero( n, kEpsilonQuaternion ) )" );
		return;
	}
		
	n = 1.0f / n;
	out.w = q.w * n;
	out.x = - q.x * n;
	out.y = - q.y * n;
	out.z = - q.z * n;
}
