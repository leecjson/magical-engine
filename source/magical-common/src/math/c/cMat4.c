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
#include "cMat4.h"
#include "cMacros.h"

static const float IDENTITY[] =
{
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};

void magicalMat4FillScalars( cMat4 out,
	const float rm11, const float rm12, const float rm13, const float rm14,
	const float rm21, const float rm22, const float rm23, const float rm24,
	const float rm31, const float rm32, const float rm33, const float rm34,
	const float rm41, const float rm42, const float rm43, const float rm44 )
{
	out _m11 = rm11; out _m12 = rm12; out _m13 = rm13; out _m14 = rm14;
	out _m21 = rm21; out _m22 = rm22; out _m23 = rm23; out _m24 = rm24;
	out _m31 = rm31; out _m32 = rm32; out _m33 = rm33; out _m34 = rm34;
	out _m41 = rm41; out _m42 = rm42; out _m43 = rm43; out _m44 = rm44;
}

void magicalMat4FillVector( cMat4 out, const float* m )
{
	memcpy( out, m, MAGICAL_MAT4_SIZE );
}

void magicalMat4Fill( cMat4 out, const cMat4 m )
{
	memcpy( out, m, MAGICAL_MAT4_SIZE );
}

void magicalMat4FillIdentity( cMat4 out )
{
	memcpy( out, IDENTITY, MAGICAL_MAT4_SIZE );
}

cBoolean magicalMat4Equals( const cMat4 m1, const cMat4 m2 )
{
	return memcmp( m1, m2, MAGICAL_MAT4_SIZE ) == 0;
}

cBoolean magicalMat4IsIdentity( const cMat4 m )
{
	return memcmp( m, IDENTITY, MAGICAL_MAT4_SIZE ) == 0;
}

void magicalMat4MulScalar( cMat4 out, const cMat4 m, const float a )
{
	/*
	 * 4x4 行优先齐次矩阵与标量相乘
	 */

	out _m11 = m _m11 * a;
	out _m12 = m _m12 * a;
	out _m13 = m _m13 * a;
	out _m14 = m _m14 * a;

	out _m21 = m _m21 * a;
	out _m22 = m _m22 * a;
	out _m23 = m _m23 * a;
	out _m24 = m _m24 * a;

	out _m31 = m _m31 * a;
	out _m32 = m _m32 * a;
	out _m33 = m _m33 * a;
	out _m34 = m _m34 * a;

	out _m41 = m _m41 * a;
	out _m42 = m _m42 * a;
	out _m43 = m _m43 * a;
	out _m44 = m _m44 * a;
}

void magicalMat4Mul( cMat4 out, const cMat4 m1, const cMat4 m2 )
{
	/*
	 * 4x4 行优先齐次矩阵相乘 m1 左乘 m2
	 *
	 *                         m2-> [ m11, m12, m13, m14 ]
	 *                              [ m21, m22, m23, m24 ]
	 *                              [ m31, m32, m33, m34 ]
	 *                              [ m41, m42, m43, m44 ]
	 * m1-> [ m11, m12, m13, m14 ]  [ d11, d12, d13, d14 ]
	 *      [ m21, m22, m23, m24 ]  [ d21, d22, d23, d24 ]
	 *      [ m31, m32, m33, m34 ]  [ d31, d32, d33, d34 ]
	 *      [ m41, m42, m43, m44 ]  [ d41, d42, d43, d44 ]
	 */

	cMat4 dst;

	dst _m11 = m1 _m11 * m2 _m11 + m1 _m12 * m2 _m21 + m1 _m13 * m2 _m31 + m1 _m14 * m2 _m41;
	dst _m12 = m1 _m11 * m2 _m12 + m1 _m12 * m2 _m22 + m1 _m13 * m2 _m32 + m1 _m14 * m2 _m42;
	dst _m13 = m1 _m11 * m2 _m13 + m1 _m12 * m2 _m23 + m1 _m13 * m2 _m33 + m1 _m14 * m2 _m43;
	dst _m14 = m1 _m11 * m2 _m14 + m1 _m12 * m2 _m24 + m1 _m13 * m2 _m34 + m1 _m14 * m2 _m44;
	dst _m21 = m1 _m21 * m2 _m11 + m1 _m22 * m2 _m21 + m1 _m23 * m2 _m31 + m1 _m24 * m2 _m41;
	dst _m22 = m1 _m21 * m2 _m12 + m1 _m22 * m2 _m22 + m1 _m23 * m2 _m32 + m1 _m24 * m2 _m42;
	dst _m23 = m1 _m21 * m2 _m13 + m1 _m22 * m2 _m23 + m1 _m23 * m2 _m33 + m1 _m24 * m2 _m43;
	dst _m24 = m1 _m21 * m2 _m14 + m1 _m22 * m2 _m24 + m1 _m23 * m2 _m34 + m1 _m24 * m2 _m44;
	dst _m31 = m1 _m31 * m2 _m11 + m1 _m32 * m2 _m21 + m1 _m33 * m2 _m31 + m1 _m34 * m2 _m41;
	dst _m32 = m1 _m31 * m2 _m12 + m1 _m32 * m2 _m22 + m1 _m33 * m2 _m32 + m1 _m34 * m2 _m42;
	dst _m33 = m1 _m31 * m2 _m13 + m1 _m32 * m2 _m23 + m1 _m33 * m2 _m33 + m1 _m34 * m2 _m43;
	dst _m34 = m1 _m31 * m2 _m14 + m1 _m32 * m2 _m24 + m1 _m33 * m2 _m34 + m1 _m34 * m2 _m44;
	dst _m41 = m1 _m41 * m2 _m11 + m1 _m42 * m2 _m21 + m1 _m43 * m2 _m31 + m1 _m44 * m2 _m41;
	dst _m42 = m1 _m41 * m2 _m12 + m1 _m42 * m2 _m22 + m1 _m43 * m2 _m32 + m1 _m44 * m2 _m42;
	dst _m43 = m1 _m41 * m2 _m13 + m1 _m42 * m2 _m23 + m1 _m43 * m2 _m33 + m1 _m44 * m2 _m43;
	dst _m44 = m1 _m41 * m2 _m14 + m1 _m42 * m2 _m24 + m1 _m43 * m2 _m34 + m1 _m44 * m2 _m44;

	memcpy( out, dst, MAGICAL_MAT4_SIZE );
}

void magicalMat4TransformVec3( cVec3 out, const cMat4 m, const cVec3 v )
{
	/*
	 * 行向量左乘4x4齐次矩阵
	 *
	 *                       m-> [ m11, m12, m13, m14 ]
	 *                           [ m21, m22, m23, m24 ]
	 *                           [ m31, m32, m33, m34 ]
	 *                           [ m41, m42, m43, m44 ]
	 * m1-> [ v.x, v.y, v.z, 1 ] [  dx,  dy,  dz, nil ]
	 */

	cVec3 dst;

	dst _x = v _x * m _m11 + v _y * m _m21 + v _z * m _m31 + m _m41;
	dst _y = v _x * m _m12 + v _y * m _m22 + v _z * m _m32 + m _m42;
	dst _z = v _x * m _m13 + v _y * m _m23 + v _z * m _m33 + m _m43;

	out _x = dst _x;
	out _y = dst _y;
	out _z = dst _z;
}

void magicalMat4TransformVec4( cVec4 out, const cMat4 m, const cVec4 v )
{
	/*
	 * 行向量左乘4x4齐次矩阵
	 *
	 *                         m-> [ m11, m12, m13, m14 ]
	 *                             [ m21, m22, m23, m24 ]
	 *                             [ m31, m32, m33, m34 ]
	 *                             [ m41, m42, m43, m44 ]
	 * m1-> [ v.x, v.y, v.z, v.w ] [  dx,  dy,  dz,  dw ]
	 */

	cVec4 dst;

	dst _x = v _x * m _m11 + v _y * m _m21 + v _z * m _m31 + v _w * m _m41;
	dst _y = v _x * m _m12 + v _y * m _m22 + v _z * m _m32 + v _w * m _m42;
	dst _z = v _x * m _m13 + v _y * m _m23 + v _z * m _m33 + v _w * m _m43;
	dst _w = v _x * m _m14 + v _y * m _m24 + v _z * m _m34 + v _w * m _m44;

	out _x = dst _x;
	out _y = dst _y;
	out _z = dst _z;
	out _w = dst _w;
}

void magicalMat4FillTranslation( cMat4 out, const float x, const float y, const float z )
{
	/*
	 * 填充为位移矩阵
	 *
	 * [ 1,  0,  0,  0 ]
	 * [ 0,  1,  0,  0 ]
	 * [ 0,  0,  1,  0 ]
	 * [ x,  y,  z,  1 ]
	 */

	memset( out, 0, MAGICAL_MAT4_SIZE );

	out _m11 = 1.0f;
	out _m22 = 1.0f;
	out _m33 = 1.0f;
	out _m44 = 1.0f;

	out _m41 = x;
	out _m42 = y;
	out _m43 = z;
}

void magicalMat4FillTranslationVector( cMat4 out, const cVec3 t )
{
	/*
	 * 填充为位移矩阵
	 *
	 * [ 1,  0,  0,  0 ]
	 * [ 0,  1,  0,  0 ]
	 * [ 0,  0,  1,  0 ]
	 * [ x,  y,  z,  1 ]
	 */

	memset( out, 0, MAGICAL_MAT4_SIZE );

	out _m11 = 1.0f;
	out _m22 = 1.0f;
	out _m33 = 1.0f;
	out _m44 = 1.0f;

	out _m41 = t _x;
	out _m42 = t _y;
	out _m43 = t _z;
}

void magicalMat4FillScaling( cMat4 out, const float x, const float y, const float z )
{
	/*
	 * 填充为缩放矩阵
	 *
	 * [ x,  0,  0,  0 ]
	 * [ 0,  y,  0,  0 ]
	 * [ 0,  0,  z,  0 ]
	 * [ 0,  0,  0,  1 ]
	 */

	memset( out, 0, MAGICAL_MAT4_SIZE );

	out _m11 = x;
	out _m22 = y;
	out _m33 = z;
	out _m44 = 1.0f;
}

void magicalMat4FillScalingVector( cMat4 out, const cVec3 s )
{
	/*
	 * 填充为缩放矩阵
	 */

	memset( out, 0, MAGICAL_MAT4_SIZE );

	out _m11 = s _x;
	out _m22 = s _y;
	out _m33 = s _z;
	out _m44 = 1.0f;
}

void magicalMat4FillRotationX( cMat4 out, const float angle )
{
	/*
	 * 填充为绕X轴旋转矩阵
	 *
	 * [ 1,   0,      0,    0 ]
	 * [ 0, cos(A),-sin(A), 0 ]
	 * [ 0, sin(A), cos(A), 0 ]
	 * [ 0,   0,      0,    1 ]
	 */

	float c = magicalCosf( angle );
	float s = magicalSinf( angle );

	out _m11 = 1.0f;
	out _m12 = 0.0f;
	out _m13 = 0.0f;
	out _m14 = 0.0f;

	out _m21 = 0.0f;
	out _m22 = c;
	out _m23 = s;
	out _m24 = 0.0f;

	out _m31 = 0.0f;
	out _m32 = -s;
	out _m33 = c;
	out _m34 = 0.0f;

	out _m41 = 0.0f;
	out _m42 = 0.0f;
	out _m43 = 0.0f;
	out _m44 = 1.0f;
}

void magicalMat4FillRotationY( cMat4 out, const float angle )
{

}

void magicalMat4FillRotationZ( cMat4 out, const float angle )
{

}

void magicalMat4FillRotationPitchYawRoll( cMat4 out, const float pitch, const float yaw, const float roll )
{
	float cr = magicalCosf( pitch );
	float sr = magicalSinf( pitch );
	float cp = magicalCosf( yaw );
	float sp = magicalSinf( yaw );
	float cy = magicalCosf( roll );
	float sy = magicalSinf( roll );
	float srsp = sr * sp;
	float crsp = cr * sp;

    out _m11 = cp * cy;
    out _m21 = cp * sy;
    out _m31 = -    sp;
	out _m41 = 0.0f;

	out _m12 = srsp * cy - cr * sy;
	out _m22 = srsp * sy + cr * cy;
	out _m32 = sr * cp;
	out _m42 = 0.0f;

	out _m13 = crsp * cy + sr * sy;
	out _m23 = crsp * sy - sr * cy;
	out _m33 = cr * cp;
	out _m43 = 0.0f;

	out _m14 = 0.0f;
	out _m24 = 0.0f;
	out _m34 = 0.0f;
	out _m44 = 1.0f;
}

void magicalMat4FillRotationQuaternion( cMat4 out, const cQuaternion r )
{
	out _m11 = 1.0f - 2.0f * ( r _y * r _y + r _z * r _z );
	out _m12 = 2.0f * ( r _x * r _y + r _z * r _w );
	out _m13 = 2.0f * ( r _x * r _z - r _y * r _w );
	out _m14 = 0.0f;

	out _m21 = 2.0f * ( r _x * r _y - r _z * r _w );
	out _m22 = 1.0f - 2.0f * ( r _x * r _x + r _z * r _z );
	out _m23 = 2.0f * ( r _z * r _y + r _x * r _w );
	out _m24 = 0.0f;

	out _m31 = 2.0f * ( r _x * r _z + r _y * r _w );
	out _m32 = 2.0f * ( r _y * r _z - r _x * r _w );
	out _m33 = 1.0f - 2.0f * ( r _x * r _x + r _y * r _y );
	out _m34 = 0.0f;

	out _m41 = 0.0f;
	out _m42 = 0.0f;
	out _m43 = 0.0f;
	out _m44 = 1.0f;
}

void magicalMat4FillRotationAxisAngle( cMat4 out, const cVec3 axis, const float angle )
{

}

void magicalMat4Translate( cMat4 out, const cMat4 m, const float x, const float y, const float z )
{
	cMat4 dst;
	magicalMat4FillTranslation( dst, x, y, z );
	magicalMat4Mul( out, m, dst );
}

void magicalMat4TranslateVector( cMat4 out, const cMat4 m, const cVec3 t )
{
	cMat4 dst;
	magicalMat4FillTranslationVector( dst, t );
	magicalMat4Mul( out, m, dst );
}

void magicalMat4Scale( cMat4 out, const cMat4 m, const float x, const float y, const float z )
{
	cMat4 dst;
	magicalMat4FillScaling( dst, x, y, z );
	magicalMat4Mul( out, m, dst );
}

void magicalMat4ScaleVector( cMat4 out, const cMat4 m, const cVec3 s )
{
	cMat4 dst;
	magicalMat4FillScalingVector( dst, s );
	magicalMat4Mul( out, m, dst );
}

void magicalMat4RotateX( cMat4 out, const cMat4 m, const float angle )
{
	cMat4 dst;
	magicalMat4FillRotationX( dst, angle );
	magicalMat4Mul( out, m, dst );
}

void magicalMat4RotateY( cMat4 out, const cMat4 m, const float angle )
{
	cMat4 dst;
	magicalMat4FillRotationY( dst, angle );
	magicalMat4Mul( out, m, dst );
}

void magicalMat4RotateZ( cMat4 out, const cMat4 m, const float angle )
{
	cMat4 dst;
	magicalMat4FillRotationZ( dst, angle );
	magicalMat4Mul( out, m, dst );
}

void magicalMat4RotatePitchYawRoll( cMat4 out, const cMat4 m, const float pitch, const float yaw, const float roll )
{
	cMat4 dst;
	magicalMat4FillRotationPitchYawRoll( dst, pitch, yaw, roll );
	magicalMat4Mul( out, m, dst );
}

void magicalMat4RotateQuaternion( cMat4 out, const cMat4 m, const cQuaternion r )
{
	cMat4 dst;
	magicalMat4FillRotationQuaternion( dst, r );
	magicalMat4Mul( out, m, dst );
}

void magicalMat4RotateAxisAngle( cMat4 out, const cMat4 m, const cVec3 axis, const float angle )
{
	cMat4 dst;
	magicalMat4FillRotationAxisAngle( dst, axis, angle );
	magicalMat4Mul( out, m, dst );
}

void magicalMat4FillLookAt( cMat4 out, const cVec3 eye, const cVec3 target, const cVec3 up )
{

}

void magicalMat4FillPerspective( cMat4 out, const float fov, const float aspect, const float znear, const float zfar )
{

}

void magicalMat4FillOrthographic( cMat4 out, const float left, const float right, const float bottom, const float top, const float near, const float far )
{

}

float magicalMat4Determinant( const cMat4 m )
{
	return 0.0f;
}

cBoolean magicalMat4Inverse( cMat4 out, const cMat4 m )
{

}

void magicalMat4Transpose( cMat4 out, const cMat4 m )
{

}

void magicalMat4Negate( cMat4 out, const cMat4 m )
{

}

MAGICALAPI_MATH void magicalMat4GetUpVector( cVec3 out, const cMat4 m )
{
	out _x = m _m21;
	out _y = m _m22;
	out _z = m _m23;
}

MAGICALAPI_MATH void magicalMat4GetDownVector( cVec3 out, const cMat4 m )
{
	out _x = - m _m21;
	out _y = - m _m22;
	out _z = - m _m23;
}

MAGICALAPI_MATH void magicalMat4GetLeftVector( cVec3 out, const cMat4 m )
{
	out _x = - m _m11;
	out _y = - m _m12;
	out _z = - m _m13;
}

MAGICALAPI_MATH void magicalMat4GetRightVector( cVec3 out, const cMat4 m )
{
	out _x = m _m11;
	out _y = m _m12;
	out _z = m _m13;
}

MAGICALAPI_MATH void magicalMat4GetForwardVector( cVec3 out, const cMat4 m )
{
	out _x = - m _m31;
	out _y = - m _m32;
	out _z = - m _m33;
}

MAGICALAPI_MATH void magicalMat4GetBackVector( cVec3 out, const cMat4 m )
{
	out _x = m _m31;
	out _y = m _m32;
	out _z = m _m33;
}