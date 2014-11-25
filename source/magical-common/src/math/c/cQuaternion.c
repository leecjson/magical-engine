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

cBool magicalQuaternionEquals( const cQuaternion q1, const cQuaternion q2 )
{
	return
		magicalAlmostEqual( q1 _x, q2 _x ) &&
		magicalAlmostEqual( q1 _y, q2 _y ) &&
		magicalAlmostEqual( q1 _z, q2 _z ) &&
		magicalAlmostEqual( q1 _w, q2 _w );
}

cBool magicalQuaternionIsZero( const cQuaternion q )
{
	return
		magicalAlmostZero( q _x ) &&
		magicalAlmostZero( q _y ) &&
		magicalAlmostZero( q _z ) &&
		magicalAlmostZero( q _w );
}

cBool magicalQuaternionIsIdentity( const cQuaternion q )
{
	return
		magicalAlmostZero( q _x ) &&
		magicalAlmostZero( q _y ) &&
		magicalAlmostZero( q _z ) &&
		magicalAlmostEqual( q _w, 1.0f );
}

cBool magicalQuaternionIsNormalize( const cQuaternion q )
{
	return magicalAlmostEqual( q _x * q _x + q _y * q _y + q _z * q _z + q _w * q _w, 1.0f );
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

/*-----------------------------------------------------------------------------*\
 * 填充为以绕X轴旋转的四元数 done
 *
 * [ cos(a/2) ( sin(a/2)  0  0 ) ]
 *
 * out 结果
 * angle 旋转弧度
 *-----------------------------------------------------------------------------*/
void magicalQuaternionFillRotationX( cQuaternion out, const float angle )
{
	float half_angle = angle * 0.5f;

	out _w = cosf( half_angle );
	out _x = sinf( half_angle );
	out _y = 0.0f;
	out _z = 0.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为以绕Y轴旋转的四元数 done
 *
 * [ cos(a/2) ( 0  sin(a/2)  0 ) ]
 *
 * out 结果
 * angle 旋转弧度
 *-----------------------------------------------------------------------------*/
void magicalQuaternionFillRotationY( cQuaternion out, const float angle )
{
	float half_angle = angle * 0.5f;

	out _w = cosf( half_angle );
	out _x = 0.0f;
	out _y = sinf( half_angle );
	out _z = 0.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为以绕Z轴旋转的四元数 done
 *
 * [ cos(a/2) ( 0  0  sin(a/2) ) ]
 *
 * out 结果
 * angle 旋转弧度
 *-----------------------------------------------------------------------------*/
void magicalQuaternionFillRotationZ( cQuaternion out, const float angle )
{
	float half_angle = angle * 0.5f;

	out _w = cosf( half_angle );
	out _x = 0.0f;
	out _y = 0.0f;
	out _z = sinf( half_angle );
}

/*-----------------------------------------------------------------------------*\
 * 填充为以轴一角对旋转的四元数 done
 *
 * [ cos(a/2) ( sin(a/2)*n.x  sin(a/2)*n.y  sin(a/2)*n.z ) ]
 *
 * out 结果
 * axis 旋转轴
 * angle 绕旋转轴所旋转的弧度
 *-----------------------------------------------------------------------------*/
void magicalQuaternionFromAxisAngle( cQuaternion out, const cVec3 axis, const float angle )
{
	cVec3 n;
	float half_angle, s;

	half_angle = angle * 0.5f;
	s = sinf( half_angle );

	magicalVec3Normalize( n, axis );

	out _w = cosf( half_angle );
    out _x = n _x * s;
    out _y = n _y * s;
    out _z = n _z * s;
}

/*-----------------------------------------------------------------------------*\
 * 将一组欧拉角旋转转换为四元数 done
 *
 * out 结果
 * ea 转换所需要的欧拉角 参考欧拉角定义
 *-----------------------------------------------------------------------------*/
void magicalQuaternionFromEulerAngles( cQuaternion out, const cEulerAngles ea )
{
	cEulerAngles ea_dst;
	float sp, sr, sy;
	float cp, cr, cy;

	magicalEulerAnglesCorrects( ea_dst, ea );

	magicalSinCos( &sp, &cp, ea_dst _pitch * 0.5f );
	magicalSinCos( &sr, &cr, ea_dst _roll * 0.5f );
	magicalSinCos( &sy, &cy, ea_dst _yaw * 0.5f );

	out _w =   cy * cp * cr + sy * sp * sr;
	out _x = - cy * sp * cr - sy * cp * sr;
	out _y =   cy * sp * sr - sy * cr * cp;
	out _z =   sy * sp * cr - cy * cp * sr;

#if 1
	magicalQuaternionNormalize( out, out );
#endif
}

/*-----------------------------------------------------------------------------*\
 * 将欧拉角yaw pitch roll旋转转换为四元数 done
 *
 * out 结果
 * yaw pitch roll 参考欧拉角的定义
 *-----------------------------------------------------------------------------*/
void magicalQuaternionFromEulerYawPitchRoll( cQuaternion out, const float yaw, const float pitch, const float roll )
{
	cEulerAngles ea_dst;
	float sp, sr, sy;
	float cp, cr, cy;

	magicalEulerAnglesFillYawPitchRoll( ea_dst, yaw, pitch, roll );
	magicalEulerAnglesCorrects( ea_dst, ea_dst );

	magicalSinCos( &sp, &cp, ea_dst _pitch * 0.5f );
	magicalSinCos( &sr, &cr, ea_dst _roll * 0.5f );
	magicalSinCos( &sy, &cy, ea_dst _yaw * 0.5f );

	out _w =   cy * cp * cr + sy * sp * sr;
	out _x = - cy * sp * cr - sy * cp * sr;
	out _y =   cy * sp * sr - sy * cr * cp;
	out _z =   sy * sp * cr - cy * cp * sr;

#if 1
	magicalQuaternionNormalize( out, out );
#endif
}

void magicalQuaternionFromMat4( cQuaternion out, const cMat4 m )
{

}

/*-----------------------------------------------------------------------------*\
 * 将四元数转换为轴一角对旋转 done
 * 
 * out 旋转轴
 * q 源四元数
 * return 绕旋转轴的所旋转的弧度
 *-----------------------------------------------------------------------------*/
float magicalQuaternionToAxisAngle( cVec3 out, const cQuaternion q )
{
	float scale = sqrtf( q _x * q _x + q _y * q _y + q _z * q _z );

	if( magicalAlmostZero( scale ) )
	{
		out _x = 0.0f;
		out _y = 0.0f;
		out _z = 1.0f;
		return 0.0f;
	}
	else
	{
		scale = 1.0f / scale;
		out _x = q _x * scale;
		out _y = q _y * scale;
		out _z = q _z * scale;
		return magicalSafeAcos( q _w ) * 2.0f;
	}
}

void magicalQuaternionToEulerAngels( cEulerAngles out, const cQuaternion q )
{
	magicalEulerAnglesFromQuaternion( out, q );
}

void magicalQuaternionToMat4( cMat4 out, const cQuaternion q )
{
	
}

void magicalQuaternionRotateX( cQuaternion out, const cQuaternion q, const float angle )
{
	cQuaternion dst;
	magicalQuaternionFillRotationX( dst, angle );
	magicalQuaternionMul( out, q, dst );
}

void magicalQuaternionRotateY( cQuaternion out, const cQuaternion q, const float angle )
{
	cQuaternion dst;
	magicalQuaternionFillRotationY( dst, angle );
	magicalQuaternionMul( out, q, dst );
}

void magicalQuaternionRotateZ( cQuaternion out, const cQuaternion q, const float angle )
{
	cQuaternion dst;
	magicalQuaternionFillRotationZ( dst, angle );
	magicalQuaternionMul( out, q, dst );
}

void magicalQuaternionRotateAxisAngle( cQuaternion out, const cQuaternion q, const cVec3 axis, const float angle )
{
	cQuaternion dst;
	magicalQuaternionFromAxisAngle( dst, axis, angle );
	magicalQuaternionMul( out, q, dst );
}

void magicalQuaternionRotateEulerAngles( cQuaternion out, const cQuaternion q, const cEulerAngles ea )
{
	cQuaternion dst;
	magicalQuaternionFromEulerAngles( dst, ea );
	magicalQuaternionMul( out, q, dst );
}

void magicalQuaternionRotateEulerYawPitchRoll( cQuaternion out, const cQuaternion q, const float yaw, const float pitch, const float roll )
{
	cQuaternion dst;
	magicalQuaternionFromEulerYawPitchRoll( dst, yaw, pitch, roll );
	magicalQuaternionMul( out, q, dst );
}

void magicalQuaternionAdd( cQuaternion out, const cQuaternion q1, const cQuaternion q2 )
{
	out _w = q1 _w + q2 _w;
	out _x = q1 _x + q2 _x;
	out _y = q1 _y + q2 _y;
	out _z = q1 _z + q2 _z;
}

void magicalQuaternionSub( cQuaternion out, const cQuaternion q1, const cQuaternion q2 )
{
	out _w = q1 _w - q2 _w;
	out _x = q1 _x - q2 _x;
	out _y = q1 _y - q2 _y;
	out _z = q1 _z - q2 _z;
}

/*-----------------------------------------------------------------------------*\
 * 四元数乘法 q1左乘q2 done
 *
 * 四元数乘积的模等于模的乘积
 *
 * 满足结合律 但不满足交换律
 * (q1 * q2) * q3 = q1 * (q2 * q3)
 *  q1 * q2 != q2 * q1
 *
 * 四元数乘积的逆等于各个四元数的逆以相反的顺序相乘
 * (q1 * q2)^-1 = (q2^-1) * (q1^-1)
 * (q1 * q2 * q3)^-1 = (q3^-1) * (q2^-1) * (q1^-1)
 *
 * out 结果
 * q1 第一个四元数
 * q2 第二个四元数
 *-----------------------------------------------------------------------------*/
void magicalQuaternionMul( cQuaternion out, const cQuaternion q1, const cQuaternion q2 )
{
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

/*-----------------------------------------------------------------------------*\
 * 四元数乘以3D向量 done
 *
 * out 旋转后的向量
 * q 四元数
 * v 源向量
 *-----------------------------------------------------------------------------*/
void magicalQuaternionMulVec3( cVec3 out, const cQuaternion q, const cVec3 v )
{
	// nVidia SDK implementation

	cVec3 uv, uuv, qvec;

	qvec _x = q _x;
	qvec _y = q _y;
	qvec _z = q _z;

	magicalVec3Cross( uv, qvec, v );
	magicalVec3Cross( uuv, qvec, uv );

	magicalVec3Scale( uv, uv, 2.0f * q _w );
	magicalVec3Scale( uuv, uuv, 2.0f );

	magicalVec3Add( out, v, uv );
	magicalVec3Add( out, out, uuv );
}

void magicalQuaternionMulScalar( cQuaternion out, const cQuaternion q, const float a )
{
	out _w = q _w * a;
	out _x = q _x * a;
	out _y = q _y * a;
	out _z = q _z * a;
}

/*-----------------------------------------------------------------------------*\
 * 计算两个四元数的点乘结果 done
 * 
 * q1 第一个四元数
 * q2 第二个四元数
 * return 点乘结果
 *-----------------------------------------------------------------------------*/
float magicalQuaternionDot( const cQuaternion q1, const cQuaternion q2 )
{
	return q1 _w * q2 _w + q1 _x * q2 _x + q1 _y * q2 _y + q1 _z * q2 _z;
}

/*-----------------------------------------------------------------------------*\
 * 计算四元数的模 done
 * 
 * q 目标四元数
 * return 四元数的模
 *-----------------------------------------------------------------------------*/
float magicalQuaternionLength( const cQuaternion q )
{
	return sqrtf( q _x * q _x + q _y * q _y + q _z * q _z + q _w * q _w );
}

/*-----------------------------------------------------------------------------*\
 * 计算四元数模的平方 done
 * 
 * q 目标四元数
 * return 四元数模的平方
 *-----------------------------------------------------------------------------*/
float magicalQuaternionLengthSq( const cQuaternion q )
{
	return q _x * q _x + q _y * q _y + q _z * q _z + q _w * q _w;
}

/*-----------------------------------------------------------------------------*\
 * 计算四元数的标准化 done
 * 
 * out q的标准化四元数
 * q 源四元数
 *-----------------------------------------------------------------------------*/
void magicalQuaternionNormalize( cQuaternion out, const cQuaternion q )
{
	out _x = q _x;
	out _y = q _y;
	out _z = q _z;
	out _w = q _w;

	float n = q _x * q _x + q _y * q _y + q _z * q _z + q _w * q _w;
	if( magicalAlmostEqual( n, 1.0f ) )
		return;

	n = sqrt( n );
	if( magicalAlmostZero( n ) )
	{
		debugassert( cFalse, "if( magicalAlmostZero( n ) )" );
		return;
	}

	n = 1.0f / n;
	out _x *= n;
	out _y *= n;
	out _z *= n;
	out _w *= n;
}

/*-----------------------------------------------------------------------------*\
 * 计算四元数共轭 done
 * 
 * out q的共轭
 * q 源四元数
 *-----------------------------------------------------------------------------*/
void magicalQuaternionConjugate( cQuaternion out, const cQuaternion q )
{
	out _w = q _w;
	out _x = - q _x;
	out _y = - q _y;
	out _z = - q _z;
}

/*-----------------------------------------------------------------------------*\
 * 计算四元数的倒数 done
 * 
 * out q的倒数
 * q 源标四元数
 *-----------------------------------------------------------------------------*/
void magicalQuaternionNegate( cQuaternion out, const cQuaternion q )
{
	out _w = - q _w;
	out _x = - q _x;
	out _y = - q _y;
	out _z = - q _z;
}

/*-----------------------------------------------------------------------------*\
 * 计算四元数的逆 done
 * 
 * q^-1 = q^* / length(q)
 *
 * out q的逆
 * q 源四元数
 * return 是否成功
 *-----------------------------------------------------------------------------*/
void magicalQuaternionInverse( cQuaternion out, const cQuaternion q )
{
	out _w = q _w;
	out _x = q _x;
	out _y = q _y;
	out _z = q _z;

	float n = q _x * q _x + q _y * q _y + q _z * q _z + q _w * q _w;
	if( magicalAlmostEqual( n, 1.0f ) )
	{
		out _w = q _w;
		out _x = - q _x;
		out _y = - q _y;
		out _z = - q _z;
		return;
	}

	n = sqrt( n );
	if( magicalAlmostZero( n ) )
	{
		debugassert( cFalse, "if( magicalAlmostZero( n ) )" );
		return;
	}
		
	n = 1.0f / n;
	out _w = q _w * n;
	out _x = -q _x * n;
	out _y = -q _y * n;
	out _z = -q _z * n;
}

/*-----------------------------------------------------------------------------*\
 * 四元数差值
 *-----------------------------------------------------------------------------*/
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

	if( t <= MAGICAL_MATH_EPSILON ) 
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