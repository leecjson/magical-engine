/******************************************************************************
The MIT License (MIT)

Copyright (c) 2014 Jason.lee

Permission is hereby granted, free of chaage, to any person obtaining a copy
of this softwaae and associated documentation files (the "Softwaae"), to deal
in the Softwaae without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Softwaae, and to permit persons to whom the Softwaae is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Softwaae.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/
#include "cQuaternion.h"

cBool magicalQuaternionEquals( const cQuaternion* q1, const cQuaternion* q2 )
{
	return
		magicalAlmostEqual( q1->x, q2->x, kQuaternionEpsilon ) &&
		magicalAlmostEqual( q1->y, q2->y, kQuaternionEpsilon ) &&
		magicalAlmostEqual( q1->z, q2->z, kQuaternionEpsilon ) &&
		magicalAlmostEqual( q1->w, q2->w, kQuaternionEpsilon );
}

cBool magicalQuaternionIsIdentity( const cQuaternion* q )
{
	return
		magicalAlmostZero( q->x, kQuaternionEpsilon ) &&
		magicalAlmostZero( q->y, kQuaternionEpsilon ) &&
		magicalAlmostZero( q->z, kQuaternionEpsilon ) &&
		magicalAlmostEqual( q->w, 1.0f, kQuaternionEpsilon );
}

cBool magicalQuaternionIsZero( const cQuaternion* q )
{
	return
		magicalAlmostZero( q->x, kQuaternionEpsilon ) &&
		magicalAlmostZero( q->y, kQuaternionEpsilon ) &&
		magicalAlmostZero( q->z, kQuaternionEpsilon ) &&
		magicalAlmostZero( q->w, kQuaternionEpsilon );
}

cBool magicalQuaternionIsNormalized( const cQuaternion* q )
{
	return magicalAlmostEqual( q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w, 1.0f, kQuaternionEpsilon );
}

void magicalQuaternionFill( cQuaternion* out, float x, float y, float z, float w )
{
	out->x = x;
	out->y = y;
	out->z = z;
	out->w = w;
}

void magicalQuaternionCopy( cQuaternion* out, const cQuaternion* q )
{
	out->x = q->x;
	out->y = q->y;
	out->z = q->z;
	out->w = q->w;
}

void magicalQuaternionSetIdentity( cQuaternion* out )
{
	out->x = 0.0f;
	out->y = 0.0f;
	out->z = 0.0f;
	out->w = 1.0f;
}

void magicalQuaternionSetZero( cQuaternion* out )
{
	out->x = 0.0f;
	out->y = 0.0f;
	out->z = 0.0f;
	out->w = 0.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为以绕X轴旋转的四元数 done
 *
 * [ cos(a/2) ( sin(a/2)  0  0 ) ]
 *
 * out 结果
 * angle 旋转弧度
 *-----------------------------------------------------------------------------*/
void magicalQuaternionSetRotationX( cQuaternion* out, float angle )
{
	float half_angle = angle * 0.5f;

	out->w = cosf( half_angle );
	out->x = sinf( half_angle );
	out->y = 0.0f;
	out->z = 0.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为以绕Y轴旋转的四元数 done
 *
 * [ cos(a/2) ( 0  sin(a/2)  0 ) ]
 *
 * out 结果
 * angle 旋转弧度
 *-----------------------------------------------------------------------------*/
void magicalQuaternionSetRotationY( cQuaternion* out, float angle )
{
	float half_angle = angle * 0.5f;

	out->w = cosf( half_angle );
	out->x = 0.0f;
	out->y = sinf( half_angle );
	out->z = 0.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为以绕Z轴旋转的四元数 done
 *
 * [ cos(a/2) ( 0  0  sin(a/2) ) ]
 *
 * out 结果
 * angle 旋转弧度
 *-----------------------------------------------------------------------------*/
void magicalQuaternionSetRotationZ( cQuaternion* out, float angle )
{
	float half_angle = angle * 0.5f;

	out->w = cosf( half_angle );
	out->x = 0.0f;
	out->y = 0.0f;
	out->z = sinf( half_angle );
}

/*-----------------------------------------------------------------------------*\
 * 填充为绕任意轴和旋转角度分量四元数 done
 *
 * [ cos(a/2) ( sin(a/2)*n.x  sin(a/2)*n.y  sin(a/2)*n.z ) ]
 *
 * out 结果
 * aa 轴一角对
 *-----------------------------------------------------------------------------*/
void magicalQuaternionFromAxisAngle( cQuaternion* out, const cAxisAngle* aa )
{
	cVector3 n, axis;
	float half_angle, s;

	axis.x = aa->x;
	axis.y = aa->y;
	axis.z = aa->z;

	half_angle = aa->w * 0.5f;
	s = sinf( half_angle );

	magicalVector3Normalize( &n, &axis );

	out->w = cosf( half_angle );
    out->x = n.x * s;
    out->y = n.y * s;
    out->z = n.z * s;
}

/*-----------------------------------------------------------------------------*\
 * 将一组欧拉角旋转转换为四元数 done
 *
 * out 结果
 * ea 转换所需要的欧拉角 参考欧拉角定义
 *-----------------------------------------------------------------------------*/
void magicalQuaternionFromEulerAngles( cQuaternion* out, const cEulerAngles* ea )
{
	cEulerAngles dst;
	magicalEulerAnglesLimit( &dst, ea );

	float sp, sr, sy;
	float cp, cr, cy;

	magicalSinCos( &sp, &cp, dst.pitch * 0.5f );
	magicalSinCos( &sr, &cr, dst.roll * 0.5f );
	magicalSinCos( &sy, &cy, dst.yaw * 0.5f );

	out->w =   cy * cp * cr + sy * sp * sr;
	out->x = - cy * sp * cr - sy * cp * sr;
	out->y =   cy * sp * sr - sy * cr * cp;
	out->z =   sy * sp * cr - cy * cp * sr;

	magicalQuaternionNormalize( out, out );
}

void magicalQuaternionFromMatrix3( cQuaternion* out, const cMatrix3* m )
{
	float s, t;
	t = m->m11 + m->m22 + m->m33 + 1.0f;

	if( t > kVectorEpsilon )
	{
		s = 0.5f / sqrtf( t );
		out->w = 0.25f / s;
		out->x = ( m->m23 - m->m32 ) * s;
		out->y = ( m->m31 - m->m13 ) * s;
		out->z = ( m->m12 - m->m21 ) * s;
	}
	else
	{
		if( m->m11 > m->m21 && m->m11 > m->m33 )
		{
			s = 2.0f * sqrtf( 1.0f + m->m11 - m->m22 - m->m33 );
			out->w = ( m->m23 - m->m32 ) / s;
			out->x = 0.25f * s;
			out->y = ( m->m21 + m->m12 ) / s;
			out->z = ( m->m31 + m->m13 ) / s;
		}
		else if( m->m22 > m->m33 )
		{
			s = 2.0f * sqrtf( 1.0f + m->m22 - m->m11 - m->m33 );
			out->w = ( m->m31 - m->m13 ) / s;
			out->x = ( m->m21 + m->m12 ) / s;
			out->y = 0.25f * s;
			out->z = ( m->m32 + m->m23 ) / s;
		}
		else
		{
			s = 2.0f * sqrtf( 1.0f + m->m33 - m->m11 - m->m22 );
			out->w = ( m->m12 - m->m21 ) / s;
			out->x = ( m->m31 + m->m13 ) / s;
			out->y = ( m->m32 + m->m23 ) / s;
			out->z = 0.25f * s;
		}
	}
}

void magicalQuaternionToAxisAngle( cAxisAngle* out, const cQuaternion* q )
{
	magicalAxisAngleFromQuaternion( out, q );
}

void magicalQuaternionToEulerAngles( cEulerAngles* out, const cQuaternion* q )
{
	magicalEulerAnglesFromQuaternion( out, q );
}

void magicalQuaternionToMatrix3( cMatrix3* out, const cQuaternion* q )
{
	magicalMatrix3RotationQuaternion( out, q );
}

void magicalQuaternionAdd( cQuaternion* out, const cQuaternion* q1, const cQuaternion* q2 )
{
	out->w = q1->w + q2->w;
	out->x = q1->x + q2->x;
	out->y = q1->y + q2->y;
	out->z = q1->z + q2->z;
}

void magicalQuaternionSub( cQuaternion* out, const cQuaternion* q1, const cQuaternion* q2 )
{
	out->w = q1->w - q2->w;
	out->x = q1->x - q2->x;
	out->y = q1->y - q2->y;
	out->z = q1->z - q2->z;
}

void magicalQuaternionMulScalar( cQuaternion* out, const cQuaternion* q, float a )
{
	out->w = q->w * a;
	out->x = q->x * a;
	out->y = q->y * a;
	out->z = q->z * a;
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
void magicalQuaternionMul( cQuaternion* out, const cQuaternion* q1, const cQuaternion* q2 )
{
#if 0
	// 变换顺序由右到左
	float w = q1->w * q2->w - q1->x * q2->x - q1->y * q2->y - q1->z * q2->z;
	float x = q1->w * q2->x + q1->x * q2->w + q1->y * q2->z - q1->z * q2->y;
	float y = q1->w * q2->y - q1->x * q2->z + q1->y * q2->w + q1->z * q2->x;
	float z = q1->w * q2->z + q1->x * q2->y - q1->y * q2->x + q1->z * q2->w;
#else
	// 变换顺序由左到右
	float w = q1->w * q2->w - q1->x * q2->x - q1->y * q2->y - q1->z * q2->z;
	float x = q1->w * q2->x + q1->x * q2->w + q1->y * q2->z - q1->z * q2->y;
	float y = q1->w * q2->y + q1->y * q2->w + q1->z * q2->x - q1->x * q2->z;
	float z = q1->w * q2->z + q1->z * q2->w + q1->x * q2->y - q1->y * q2->x;
#endif

	out->w = w;
	out->x = x;
	out->y = y;
	out->z = z;
}

/*-----------------------------------------------------------------------------*\
 * 四元数乘以3D向量 done
 *
 * out 旋转后的向量
 * q 四元数
 * v 源向量
 *-----------------------------------------------------------------------------*/
void magicalQuaternionMulVector3( cVector3* out, const cQuaternion* q, const cVector3* v )
{
	// nVidia SDK implementation

	cVector3 uv, uuv;
	cVector3 qvec = { q->x, q->y, q->z };

	magicalVector3Cross( &uv, &qvec, v );
	magicalVector3Cross( &uuv, &qvec, &uv );

	magicalVector3Scale( &uv, &uv, 2.0f * q->w );
	magicalVector3Scale( &uuv, &uuv, 2.0f );

	magicalVector3Add( out, v, &uv );
	magicalVector3Add( out, out, &uuv );
}

/*-----------------------------------------------------------------------------*\
 * 计算两个四元数的点乘结果 done
 * 
 * q1 第一个四元数
 * q2 第二个四元数
 * return 点乘结果
 *-----------------------------------------------------------------------------*/
float magicalQuaternionDot( const cQuaternion* q1, const cQuaternion* q2 )
{
	return q1->w * q2->w + q1->x * q2->x + q1->y * q2->y + q1->z * q2->z;
}

/*-----------------------------------------------------------------------------*\
 * 计算四元数的模 done
 * 
 * q 目标四元数
 * return 四元数的模
 *-----------------------------------------------------------------------------*/
float magicalQuaternionLength( const cQuaternion* q )
{
	return sqrtf( q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w );
}

/*-----------------------------------------------------------------------------*\
 * 计算四元数模的平方 done
 * 
 * q 目标四元数
 * return 四元数模的平方
 *-----------------------------------------------------------------------------*/
float magicalQuaternionLengthSq( const cQuaternion* q )
{
	return q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w;
}

/*-----------------------------------------------------------------------------*\
 * 计算四元数的标准化 done
 * 
 * out q的标准化四元数
 * q 源四元数
 *-----------------------------------------------------------------------------*/
void magicalQuaternionNormalize( cQuaternion* out, const cQuaternion* q )
{
	out->w = q->w;
	out->x = q->x;
	out->y = q->y;
	out->z = q->z;
	
	float n = q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w;
	if( magicalAlmostEqual( n, 1.0f, kQuaternionEpsilon ) )
		return;

	n = sqrtf( n );
	if( magicalAlmostZero( n, kQuaternionEpsilon ) )
	{
		//debugassert( cFalse, "if( magicalAlmostZero( n, kEpsilonQuaternion ) )" );
		return;
	}

	n = 1.0f / n;
	out->w *= n;
	out->x *= n;
	out->y *= n;
	out->z *= n;
}

/*-----------------------------------------------------------------------------*\
 * 计算四元数共轭 done
 * 
 * out q的共轭
 * q 源四元数
 *-----------------------------------------------------------------------------*/
void magicalQuaternionConjugate( cQuaternion* out, const cQuaternion* q )
{
	out->w = q->w;
	out->x = - q->x;
	out->y = - q->y;
	out->z = - q->z;
}

/*-----------------------------------------------------------------------------*\
 * 计算四元数的倒数 done
 * 
 * out q的倒数
 * q 源标四元数
 *-----------------------------------------------------------------------------*/
void magicalQuaternionNegate( cQuaternion* out, const cQuaternion* q )
{
	out->w = - q->w;
	out->x = - q->x;
	out->y = - q->y;
	out->z = - q->z;
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
void magicalQuaternionInverse( cQuaternion* out, const cQuaternion* q )
{
	out->w = q->w;
	out->x = q->x;
	out->y = q->y;
	out->z = q->z;

	float n = q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w;
	if( magicalAlmostEqual( n, 1.0f, kQuaternionEpsilon ) )
	{
		out->w = q->w;
		out->x = - q->x;
		out->y = - q->y;
		out->z = - q->z;
		return;
	}

	n = sqrtf( n );
	if( magicalAlmostZero( n, kQuaternionEpsilon ) )
	{
		//debugassert( cFalse, "if( magicalAlmostZero( n, kEpsilonQuaternion ) )" );
		return;
	}
		
	n = 1.0f / n;
	out->w = q->w * n;
	out->x = -q->x * n;
	out->y = -q->y * n;
	out->z = -q->z * n;
}

/*-----------------------------------------------------------------------------*\
 * 四元数差值
 *-----------------------------------------------------------------------------*/
//void magicalQuaternionSlerp( cQuaternion* out, const cQuaternion* q1, const cQuaternion* q2, float t )
//{
//	float cos_omega;
//	float sin_omega;
//	float omega;
//	float one_over_sin_omega;
//	float q2w;
//	float q2x;
//	float q2y;
//	float q2z;
//	float k1, k2;
//
//	if( t <= kNumberEpsilon ) 
//	{
//		magicalQuaternionCopy( out, q1 );
//		return;
//	}
//	else if( t >= 1.0f ) 
//	{
//		magicalQuaternionCopy( out, q2 );
//		return;
//	}
//
//	cos_omega = magicalQuaternionDot( q1, q2 );
//
//	q2w = q2->w;
//	q2x = q2->x;
//	q2y = q2->y;
//	q2z = q2->z;
//	if( cos_omega < 0.0f ) 
//	{
//		q2w = -q2w;
//		q2x = -q2x;
//		q2y = -q2y;
//		q2z = -q2z;
//		cos_omega = -cos_omega;
//	}
//
//	assert( cos_omega < 1.1f );
//
//	if( cos_omega > 0.9999f )
//	{
//		k1 = 1.0f - t;
//		k2 = t;
//	}
//	else
//	{
//		sin_omega = sqrtf( 1.0f - cos_omega * cos_omega );
//		omega = atan2f( sin_omega, cos_omega );
//		one_over_sin_omega = 1.0f / sin_omega;
//
//		k1 = sinf( ( 1.0f - t ) * omega ) * one_over_sin_omega;
//		k2 = sinf( t * omega ) * one_over_sin_omega;
//	}
//
//	out->x = k1 * q1->x + k2 * q2x;
//	out->y = k1 * q1->y + k2 * q2y;
//	out->z = k1 * q1->z + k2 * q2z;
//	out->w = k1 * q1->w + k2 * q2w;
//}