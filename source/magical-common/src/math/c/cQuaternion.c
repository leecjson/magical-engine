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
#include "cQuaternion.h"
#include "cMacros.h"

cBoolean magicalQuaternionEquals( const cQuaternion q1, const cQuaternion q2 )
{
	return
		magicalFltEqual( q1 _x, q2 _x ) &&
		magicalFltEqual( q1 _y, q2 _y ) &&
		magicalFltEqual( q1 _z, q2 _z ) &&
		magicalFltEqual( q1 _w, q2 _w );
}

cBoolean magicalQuaternionIsZero( const cQuaternion q )
{
	return
		magicalFltIsZero( q _x ) &&
		magicalFltIsZero( q _y ) &&
		magicalFltIsZero( q _z ) &&
		magicalFltIsZero( q _w );
}

cBoolean magicalQuaternionIsIdentity( const cQuaternion q )
{
	return
		magicalFltIsZero( q _x ) &&
		magicalFltIsZero( q _y ) &&
		magicalFltIsZero( q _z ) &&
		magicalFltEqual( q _w, 1.0f );
}

cBoolean magicalQuaternionIsNormalize( const cQuaternion q )
{
	return magicalFltEqual( q _x * q _x + q _y * q _y + q _z * q _z + q _w * q _w, 1.0f );
}

void magicalQuaternionFillScalars( cQuaternion out, const float x, const float y, const float z, const float w )
{
	out _x = x;
	out _y = y;
	out _z = z;
	out _w = w;
}

void magicalQuaternionFillZero( cQuaternion out )
{
	out _x = 0.0f;
	out _y = 0.0f;
	out _z = 0.0f;
	out _w = 0.0f;
}

void magicalQuaternionFillIdentity( cQuaternion out )
{
	out _x = 0.0f;
	out _y = 0.0f;
	out _z = 0.0f;
	out _w = 1.0f;
}

void magicalQuaternionFill( cQuaternion out, const cQuaternion q )
{
	out _x = q _x;
	out _y = q _y;
	out _z = q _z;
	out _w = q _w;
}

void magicalQuaternionFromAxisAngle( cQuaternion out, const cVec3 axis, const float angle )
{
	/*
	 * 填充四元数为轴一角对旋转方式
	 *
	 * [ cos(a/2) (sin(a/2)*n.x  sin(a/2)*n.y  sin(a/2)*n.z) ]
	 */

	cVec3 n;
	float half;
	float s;

	half = angle / 2.0f;
	s = magicalSinf( half );

	magicalVec3Normalize( n, axis );

	out _w = magicalCosf( half );
    out _x = n _x * s;
    out _y = n _y * s;
    out _z = n _z * s;
}

void magicalQuaternionFromEulerAngles( cQuaternion out, const cEulerAngles ea )
{
	cEulerAngles ea_dst;
	float sp, sr, sy;
	float cp, cr, cy;

	magicalEulerAnglesFill( ea_dst, ea );
	magicalEulerAnglesCorrects( ea_dst, ea_dst );

	magicalSinfCosf( &sp, &cp, ea _pitch * 0.5f );
	magicalSinfCosf( &sr, &cr, ea _roll * 0.5f );
	magicalSinfCosf( &sy, &cy, ea _yaw * 0.5f );

	out _w =   cy * cp * cr + sy * sp * sr;
	out _x = - cy * sp * cr - sy * cp * sr;
	out _y =   cy * sp * sr - sy * cr * cp;
	out _z =   sy * sp * cr - cy * cp * sr;
}

void magicalQuaternionFromEulerYawPitchRoll( cQuaternion out, const float yaw, const float pitch, const float roll )
{
	cEulerAngles ea_dst;
	float sp, sr, sy;
	float cp, cr, cy;

	magicalEulerAnglesFillYawPitchRoll( ea_dst, yaw, pitch, roll );
	magicalEulerAnglesCorrects( ea_dst, ea_dst );

	magicalSinfCosf( &sp, &cp, ea_dst _pitch * 0.5f );
	magicalSinfCosf( &sr, &cr, ea_dst _roll * 0.5f );
	magicalSinfCosf( &sy, &cy, ea_dst _yaw * 0.5f );

	out _w =   cy * cp * cr + sy * sp * sr;
	out _x = - cy * sp * cr - sy * cp * sr;
	out _y =   cy * sp * sr - sy * cr * cp;
	out _z =   sy * sp * cr - cy * cp * sr;
}

float magicalQuaternionToAxisAngle( cVec3 out, const cQuaternion q )
{
	float angle;
	float scale;

	angle = magicalAcosf( q _w );
	scale = sqrtf( q _x * q _x + q _y * q _y + q _z * q _z );

	if( magicalFltIsZero( scale ) || magicalFltEqual( scale, MAGICAL_FLT_2PI ) )
	{
		out _x = 0.0f;
		out _y = 0.0f;
		out _z = 1.0f;
		return 0.0f;
	}
	else
	{
		angle = angle * 2.0f;
		out _x = q _x / scale;
		out _y = q _y / scale;
		out _z = q _z / scale;
		magicalVec3Normalize( out, out );
		return angle;
	}
}

void magicalQuaternionMul( cQuaternion out, const cQuaternion q1, const cQuaternion q2 )
{
	/*
	 * 四元数乘法 q1 左乘 q2
	 *
	 * 四元数乘积的模等于模的乘积
	 * 满足结合律 但不满足交换律
	 * (q1 * q2) * q3 = q1 * (q2 * q3)
	 * q1 * q2 != q2 * q1
	 *
	 * 四元数乘积的逆等于各个四元数的逆以相反的顺序相乘
	 * (q1 * q2)^-1 = (q2^-1) * (q1^-1)
	 * (q1 * q2 * q3)^-1 = (q3^-1) * (q2^-1) * (q1^-1)
	 *
	 */
#if 0
	// 变换顺序由右到左
	float w = q1 _w * q2 _w - q1 _x * q2 _x - q1 _y * q2 _y - q1 _z * q2 _z;
	float x = q1 _w * q2 _x + q1 _x * q2 _w + q1 _y * q2 _z - q1 _z * q2 _y;
	float y = q1 _w * q2 _y - q1 _x * q2 _z + q1 _y * q2 _w + q1 _z * q2 _x;
	float z = q1 _w * q2 _z + q1 _x * q2 _y - q1 _y * q2 _x + q1 _z * q2 _w;
#else
	// 变换顺序由左到右
	float w = q1 _w * q2 _w - q1 _x * q2 _x - q1 _y * q2 _y - q1 _z * q2 _z;
	float x = q1 _w * q2 _x + q1 _x * q2 _w + q1 _y * q2 _z - q1 _z * q2 _y;
	float y = q1 _w * q2 _y + q1 _y * q2 _w + q1 _z * q2 _x - q1 _x * q2 _z;
	float z = q1 _w * q2 _z + q1 _z * q2 _w + q1 _x * q2 _y - q1 _y * q2 _x;
#endif

	out _x = x;
	out _y = y;
	out _z = z;
	out _w = w;
}

float magicalQuaternionDot( const cQuaternion q1, const cQuaternion q2 )
{
	return q1 _w * q2 _w + q1 _x * q2 _x + q1 _y * q2 _y + q1 _z * q2 _z;
}

float magicalQuaternionLength( const cQuaternion q )
{
	return sqrtf( q _x * q _x + q _y * q _y + q _z * q _z + q _w * q _w );
}

float magicalQuaternionLengthSq( const cQuaternion q )
{
	return q _x * q _x + q _y * q _y + q _z * q _z + q _w * q _w;
}

void magicalQuaternionNormalize( cQuaternion out, const cQuaternion q )
{
	/*
	 * 标准化四元数
	 */

	out _x = q _x;
	out _y = q _y;
	out _z = q _z;
	out _w = q _w;

	float n = q _x * q _x + q _y * q _y + q _z * q _z + q _w * q _w;
	if( magicalFltEqual( n, 1.0f ) )
		return;

	n = sqrt( n );
	if( magicalFltIsZero( n ) )
		return;

	n = 1.0f / n;
	out _x *= n;
	out _y *= n;
	out _z *= n;
	out _w *= n;
}

void magicalQuaternionConjugate( cQuaternion out, const cQuaternion q )
{
	/*
	 * 计算四元数共轭
	 */

	out _w = q _w;
	out _x = - q _x;
	out _y = - q _y;
	out _z = - q _z;
}

void magicalQuaternionNegate( cQuaternion out, const cQuaternion q )
{
	/*
	 * 计算四元数的倒数
	 */

	out _w = - q _w;
	out _x = - q _x;
	out _y = - q _y;
	out _z = - q _z;
}

cBoolean magicalQuaternionInverse( cQuaternion out, const cQuaternion q )
{
	/*
	 * 计算四元数的逆
	 *
	 * q^-1 = q^* / length(q)
	 */

	out _w = q _w;
	out _x = q _x;
	out _y = q _y;
	out _z = q _z;

	float n = q _x * q _x + q _y * q _y + q _z * q _z + q _w * q _w;
	if( magicalFltEqual( n, 1.0f ) )
	{
		out _w = q _w;
		out _x = - q _x;
		out _y = - q _y;
		out _z = - q _z;
		return cTrue;
	}

	n = sqrt( n );
	if( magicalFltIsZero( n ) )
		return cFalse;
		
	n = 1.0f / n;
	out _w = q _w * n;
	out _x = -q _x * n;
	out _y = -q _y * n;
	out _z = -q _z * n;
	return cTrue;
}

void magicalQuaternionSlerp( cQuaternion out, const cQuaternion q1, const cQuaternion q2, const float t )
{
	float cos_omega;
	float sin_omega;
	float omega;
	float one_over_sin_omega;
	float q2w;
	float q2x;
	float q2y;
	float q2z;
	float k1, k2;

	if( t <= MAGICAL_FLT_EPSILON ) 
	{
		magicalQuaternionFill( out, q1 );
		return;
	}
	else if( t >= 1.0f ) 
	{
		magicalQuaternionFill( out, q2 );
		return;
	}

	cos_omega = magicalQuaternionDot( q1, q2 );

	q2w = q2 _w;
	q2x = q2 _x;
	q2y = q2 _y;
	q2z = q2 _z;
	if( cos_omega < 0.0f ) 
	{
		q2w = -q2w;
		q2x = -q2x;
		q2y = -q2y;
		q2z = -q2z;
		cos_omega = -cos_omega;
	}

	assert( cos_omega < 1.1f );

	if( cos_omega > 0.9999f )
	{
		k1 = 1.0f - t;
		k2 = t;
	}
	else
	{
		sin_omega = sqrt( 1.0f - cos_omega * cos_omega );
		omega = atan2( sin_omega, cos_omega );
		one_over_sin_omega = 1.0f / sin_omega;

		k1 = sin( ( 1.0f - t ) * omega ) * one_over_sin_omega;
		k2 = sin( t * omega ) * one_over_sin_omega;
	}

	out _x = k1 * q1 _x + k2 * q2x;
	out _y = k1 * q1 _y + k2 * q2y;
	out _z = k1 * q1 _z + k2 * q2z;
	out _w = k1 * q1 _w + k2 * q2w;
}