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
#include "cMatrix4.h"
#include "cMathMacros.h"

#include <memory.h>

static const float IDENTITY[] =
{
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};

static const float ZERO[] =
{
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
};

void magicalMatrix4FillScalars( cMatrix4 out,
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

cBool magicalMatrix4Equals( const cMatrix4 m1, const cMatrix4 m2 )
{
	return memcmp( m1, m2, sizeof( cMatrix4 ) ) == 0;
}

cBool magicalMatrix4IsIdentity( const cMatrix4 m )
{
	return memcmp( m, IDENTITY, sizeof( cMatrix4 ) ) == 0;
}

cBool magicalMatrix4IsZero( const cMatrix4 m )
{
	return memcmp( m, ZERO, sizeof( cMatrix4 ) ) == 0;
}

void magicalMatrix4FillIdentity( cMatrix4 out )
{
	memcpy( out, IDENTITY, sizeof( cMatrix4 ) );
}

void magicalMatrix4FillZero( cMatrix4 out )
{
	memcpy( out, ZERO, sizeof( cMatrix4 ) );
}

void magicalMatrix4Fill( cMatrix4 out, const cMatrix4 m )
{
	memcpy( out, m, sizeof( cMatrix4 ) );
}

/*-----------------------------------------------------------------------------*\
 * 4x4 行优先齐次矩阵与标量相乘 done
 *-----------------------------------------------------------------------------*/
void magicalMatrix4MulScalar( cMatrix4 out, const cMatrix4 m, const float a )
{
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

/*-----------------------------------------------------------------------------*\
 * 4x4 行优先齐次矩阵相乘 m1 左乘 m2 done
 *
 *                         m2-> [ m11  m12  m13  m14 ]
 *                              [ m21  m22  m23  m24 ]
 *                              [ m31  m32  m33  m34 ]
 *                              [ m41  m42  m43  m44 ]
 * m1-> [ m11  m12  m13  m14 ]  [ d11  d12  d13  d14 ]
 *      [ m21  m22  m23  m24 ]  [ d21  d22  d23  d24 ]
 *      [ m31  m32  m33  m34 ]  [ d31  d32  d33  d34 ]
 *      [ m41  m42  m43  m44 ]  [ d41  d42  d43  d44 ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4Mul( cMatrix4 out, const cMatrix4 m1, const cMatrix4 m2 )
{
	cMatrix4 dst;

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

	memcpy( out, dst, sizeof( cMatrix4 ) );
}

/*-----------------------------------------------------------------------------*\
 * 4x4 行优先齐次矩阵相乘 m1 左乘 m2 done
 * 只计算左上角3x3矩阵与平移
 *
 *                       m2-> [ m11  m12  m13  0 ]
 *                            [ m21  m22  m23  0 ]
 *                            [ m31  m32  m33  0 ]
 *                            [ m41  m42  m43  1 ]
 * m1-> [ m11  m12  m13  0 ]  [ d11  d12  d13  0 ]
 *      [ m21  m22  m23  0 ]  [ d21  d22  d23  0 ]
 *      [ m31  m32  m33  0 ]  [ d31  d32  d33  0 ]
 *      [ m41  m42  m43  1 ]  [ d41  d42  d43  1 ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4Mul3x3AndTranslation( cMatrix4 out, const cMatrix4 m1, const cMatrix4 m2 )
{
	cMatrix4 dst;

	dst _m11 = m1 _m11 * m2 _m11 + m1 _m12 * m2 _m21 + m1 _m13 * m2 _m31;
	dst _m12 = m1 _m11 * m2 _m12 + m1 _m12 * m2 _m22 + m1 _m13 * m2 _m32;
	dst _m13 = m1 _m11 * m2 _m13 + m1 _m12 * m2 _m23 + m1 _m13 * m2 _m33;
	dst _m14 = 0.0f;
	dst _m21 = m1 _m21 * m2 _m11 + m1 _m22 * m2 _m21 + m1 _m23 * m2 _m31;
	dst _m22 = m1 _m21 * m2 _m12 + m1 _m22 * m2 _m22 + m1 _m23 * m2 _m32;
	dst _m23 = m1 _m21 * m2 _m13 + m1 _m22 * m2 _m23 + m1 _m23 * m2 _m33;
	dst _m24 = 0.0f;
	dst _m31 = m1 _m31 * m2 _m11 + m1 _m32 * m2 _m21 + m1 _m33 * m2 _m31;
	dst _m32 = m1 _m31 * m2 _m12 + m1 _m32 * m2 _m22 + m1 _m33 * m2 _m32;
	dst _m33 = m1 _m31 * m2 _m13 + m1 _m32 * m2 _m23 + m1 _m33 * m2 _m33;
	dst _m34 = 0.0f;
	dst _m41 = m1 _m41 * m2 _m11 + m1 _m42 * m2 _m21 + m1 _m43 * m2 _m31 + m2 _m41;
	dst _m42 = m1 _m41 * m2 _m12 + m1 _m42 * m2 _m22 + m1 _m43 * m2 _m32 + m2 _m42;
	dst _m43 = m1 _m41 * m2 _m13 + m1 _m42 * m2 _m23 + m1 _m43 * m2 _m33 + m2 _m43;
	dst _m44 = 1.0f;

	memcpy( out, dst, sizeof( cMatrix4 ) );
}

/*-----------------------------------------------------------------------------*\
 * 行向量左乘4x4齐次矩阵 done
 *
 *                       m-> [ m11  m12  m13  m14 ]
 *                           [ m21  m22  m23  m24 ]
 *                           [ m31  m32  m33  m34 ]
 *                           [ m41  m42  m43  m44 ]
 *  v-> [ v.x  v.y  v.z  1 ] [ d.x  d.y  d.z      ]
 *-----------------------------------------------------------------------------*/
void magicalVector3MulMatrix4( cVector3 out, const cVector3 v, const cMatrix4 m )
{
	cVector3 dst;

	dst _x = v _x * m _m11 + v _y * m _m21 + v _z * m _m31 + m _m41;
	dst _y = v _x * m _m12 + v _y * m _m22 + v _z * m _m32 + m _m42;
	dst _z = v _x * m _m13 + v _y * m _m23 + v _z * m _m33 + m _m43;

	out _x = dst _x;
	out _y = dst _y;
	out _z = dst _z;
}

/*-----------------------------------------------------------------------------*\
 * 行向量左乘4x4齐次矩阵 done
 *
 *                         m-> [ m11  m12  m13  m14 ]
 *                             [ m21  m22  m23  m24 ]
 *                             [ m31  m32  m33  m34 ]
 *                             [ m41  m42  m43  m44 ]
 *  v-> [ v.x  v.y  v.z  v.w ] [ d.x  d.y  d.z  d.w ]
 *-----------------------------------------------------------------------------*/
void magicalVector4MulMatrix4( cVector4 out, const cVector4 v, const cMatrix4 m )
{
	cVector4 dst;

	dst _x = v _x * m _m11 + v _y * m _m21 + v _z * m _m31 + v _w * m _m41;
	dst _y = v _x * m _m12 + v _y * m _m22 + v _z * m _m32 + v _w * m _m42;
	dst _z = v _x * m _m13 + v _y * m _m23 + v _z * m _m33 + v _w * m _m43;
	dst _w = v _x * m _m14 + v _y * m _m24 + v _z * m _m34 + v _w * m _m44;

	out _x = dst _x;
	out _y = dst _y;
	out _z = dst _z;
	out _w = dst _w;
}

/*-----------------------------------------------------------------------------*\
 * 填充为位移矩阵 done
 *
 * [ 1   0   0   0 ]
 * [ 0   1   0   0 ]
 * [ 0   0   1   0 ]
 * [ x   y   z   1 ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillTranslation( cMatrix4 out, const float x, const float y, const float z )
{
	out _m11 = 1.0f; out _m12 = 0.0f; out _m13 = 0.0f; out _m14 = 0.0f;
	out _m21 = 0.0f; out _m22 = 1.0f; out _m23 = 0.0f; out _m24 = 0.0f;
	out _m31 = 0.0f; out _m32 = 0.0f; out _m33 = 1.0f; out _m34 = 0.0f;
	out _m41 = x;    out _m42 = y;    out _m43 = z;    out _m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为位移矩阵 done
 *
 * [ 1   0   0   0 ]
 * [ 0   1   0   0 ]
 * [ 0   0   1   0 ]
 * [ x   y   z   1 ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillTranslationVector( cMatrix4 out, const cVector3 t )
{
	out _m11 = 1.0f; out _m12 = 0.0f; out _m13 = 0.0f; out _m14 = 0.0f;
	out _m21 = 0.0f; out _m22 = 1.0f; out _m23 = 0.0f; out _m24 = 0.0f;
	out _m31 = 0.0f; out _m32 = 0.0f; out _m33 = 1.0f; out _m34 = 0.0f;
	out _m41 = t _x; out _m42 = t _y; out _m43 = t _z; out _m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为轴缩放矩阵 done
 *
 * [ x   0   0   0 ]
 * [ 0   y   0   0 ]
 * [ 0   0   z   0 ]
 * [ 0   0   0   1 ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillScale( cMatrix4 out, const float x, const float y, const float z )
{
	out _m11 = x;    out _m12 = 0.0f; out _m13 = 0.0f; out _m14 = 0.0f;
	out _m21 = 0.0f; out _m22 = y;    out _m23 = 0.0f; out _m24 = 0.0f;
	out _m31 = 0.0f; out _m32 = 0.0f; out _m33 = z;    out _m34 = 0.0f;
	out _m41 = 0.0f; out _m42 = 0.0f; out _m43 = 0.0f; out _m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为轴缩放矩阵 done
 *
 * [ x   0   0   0 ]
 * [ 0   y   0   0 ]
 * [ 0   0   z   0 ]
 * [ 0   0   0   1 ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillScaleVector( cMatrix4 out, const cVector3 s )
{
	out _m11 = s _x; out _m12 = 0.0f; out _m13 = 0.0f; out _m14 = 0.0f;
	out _m21 = 0.0f; out _m22 = s _y; out _m23 = 0.0f; out _m24 = 0.0f;
	out _m31 = 0.0f; out _m32 = 0.0f; out _m33 = s _z; out _m34 = 0.0f;
	out _m41 = 0.0f; out _m42 = 0.0f; out _m43 = 0.0f; out _m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为绕X轴旋转矩阵 done
 *
 * [ 1     0       0     0 ]
 * [ 0   cos(a)  sin(a)  0 ]
 * [ 0  -sin(a)  cos(a)  0 ]
 * [ 0     0       0     1 ]
 *
 * out 结果
 * angle 旋转弧度
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillRotationX( cMatrix4 out, const float angle )
{
	float c = cosf( angle );
	float s = sinf( angle );

	out _m11 = 1.0f; out _m12 = 0.0f; out _m13 = 0.0f; out _m14 = 0.0f;
	out _m21 = 0.0f; out _m22 = c;    out _m23 = s;    out _m24 = 0.0f;
	out _m31 = 0.0f; out _m32 = -s;   out _m33 = c;    out _m34 = 0.0f;
	out _m41 = 0.0f; out _m42 = 0.0f; out _m43 = 0.0f; out _m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为绕Y轴旋转矩阵 done
 *
 * [ cos(a)  0  -sin(a)  0 ]
 * [   0     1     0     0 ]
 * [ sin(a)  0   cos(a)  0 ]
 * [   0     0     0     1 ]
 *
 * out 结果
 * angle 旋转弧度
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillRotationY( cMatrix4 out, const float angle )
{
	float c = cosf( angle );
	float s = sinf( angle );

	out _m11 = c;    out _m12 = 0.0f; out _m13 = -s;   out _m14 = 0.0f;
	out _m21 = 0.0f; out _m22 = 1.0f; out _m23 = 0.0f; out _m24 = 0.0f;
	out _m31 = s;    out _m32 = 0.0f; out _m33 = c;    out _m34 = 0.0f;
	out _m41 = 0.0f; out _m42 = 0.0f; out _m43 = 0.0f; out _m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为绕Z轴旋转矩阵 done
 *
 * [  cos(a) sin(a)  0     0  ]
 * [ -sin(a) cos(a)  0     0  ]
 * [    0      0     1     0  ]
 * [    0      0     0     1  ]
 *
 * out 结果
 * angle 旋转弧度
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillRotationZ( cMatrix4 out, const float angle )
{
	float c = cosf( angle );
	float s = sinf( angle );

	out _m11 = c;    out _m12 = s;    out _m13 = 0.0f; out _m14 = 0.0f;
	out _m21 = -s;   out _m22 = c;    out _m23 = 0.0f; out _m24 = 0.0f;
	out _m31 = 0.0f; out _m32 = 0.0f; out _m33 = 1.0f; out _m34 = 0.0f;
	out _m41 = 0.0f; out _m42 = 0.0f; out _m43 = 0.0f; out _m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为任意旋转轴旋转矩阵 done
 *
 * out 结果
 * aa 任意轴
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillRotationAxisA( cMatrix4 out, const cAxisA aa )
{
	float s, c;
	magicalSinCos( &s, &c, aa _w );

	float a = 1.0f - c;
	float ax = a * aa _x;
	float ay = a * aa _y;
	float az = a * aa _z;

	out _m11 = ax * aa _x + c;
	out _m12 = ax * aa _y + aa _z * s;
	out _m13 = ax * aa _z - aa _y * s;
	out _m14 = 0.0f;

	out _m21 = ay * aa _x - aa _z * s;
	out _m22 = ay * aa _y + c;
	out _m23 = ay * aa _z + aa _x * s;
	out _m24 = 0.0f;

	out _m31 = az * aa _x + aa _y * s;
	out _m32 = az * aa _y - aa _x * s;
	out _m33 = az * aa _z + c;
	out _m34 = 0.0f;

	out _m41 = 0.0f;
	out _m42 = 0.0f;
	out _m43 = 0.0f;
	out _m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为欧拉角旋转矩阵 done
 *
 * out 结果
 * ea 欧拉角
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillRotationEulerA( cMatrix4 out, const cEulerA ea )
{
	cEulerA dst;
	magicalEulerACorrects( dst, ea );

	float cr = cosf( dst _pitch );
	float sr = sinf( dst _pitch );
	float cp = cosf( dst _yaw );
	float sp = sinf( dst _yaw );
	float cy = cosf( dst _roll );
	float sy = sinf( dst _roll );
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

/*-----------------------------------------------------------------------------*\
 * 填充为四元数旋转矩阵 done
 *
 * out 结果
 * q 旋转四元数
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillRotationQuaternion( cMatrix4 out, const cQuaternion q )
{
	out _m11 = 1.0f - 2.0f * ( q _y * q _y + q _z * q _z );
	out _m12 = 2.0f * ( q _x * q _y + q _z * q _w );
	out _m13 = 2.0f * ( q _x * q _z - q _y * q _w );
	out _m14 = 0.0f;

	out _m21 = 2.0f * ( q _x * q _y - q _z * q _w );
	out _m22 = 1.0f - 2.0f * ( q _x * q _x + q _z * q _z );
	out _m23 = 2.0f * ( q _z * q _y + q _x * q _w );
	out _m24 = 0.0f;

	out _m31 = 2.0f * ( q _x * q _z + q _y * q _w );
	out _m32 = 2.0f * ( q _y * q _z - q _x * q _w );
	out _m33 = 1.0f - 2.0f * ( q _x * q _x + q _y * q _y );
	out _m34 = 0.0f;

	out _m41 = 0.0f;
	out _m42 = 0.0f;
	out _m43 = 0.0f;
	out _m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为从eye点到target的观察矩阵 done
 *
 * out 结果
 * eye 观察原点
 * target 观察目标点
 * up 倾斜方向
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillLookAt( cMatrix4 out, const cVector3 eye, const cVector3 target, const cVector3 up )
{
	cVector3 up_v;
	cVector3 x_axis;
	cVector3 y_axis;
	cVector3 z_axis;

	magicalVector3Fill( up_v, up );
	magicalVector3Normalize( up_v, up_v );

	magicalVector3Sub( z_axis, eye, target );
	magicalVector3Normalize( z_axis, z_axis );

	magicalVector3Cross( x_axis, up_v, z_axis );
	magicalVector3Normalize( x_axis, x_axis );

	magicalVector3Cross( y_axis, z_axis, x_axis );
	magicalVector3Normalize( y_axis, y_axis );

	out _m11 = x_axis _x;
	out _m12 = y_axis _x;
	out _m13 = z_axis _x;
	out _m14 = 0.0f;

	out _m21 = x_axis _y;
	out _m22 = y_axis _y;
	out _m23 = z_axis _y;
	out _m24 = 0.0f;

	out _m31 = x_axis _z;
	out _m32 = y_axis _z;
	out _m33 = z_axis _z;
	out _m34 = 0.0f;

	out _m41 = - magicalVector3Dot( x_axis, eye );
	out _m42 = - magicalVector3Dot( y_axis, eye );
	out _m43 = - magicalVector3Dot( z_axis, eye );
	out _m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为透视投影矩阵 done
 *
 * [ zoom.x   0       0       0   ]
 * [   0    zoom.y    0       0   ]
 * [   0      0  (f+n)/(f-n)  1   ]
 * [   0      0  (2nf)/(n-f)  0   ]
 *
 * fov 视锥半角
 * aspect 横纵比
 * znear 近处裁剪范围
 * zfar 远处裁剪范围
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillPerspective( cMatrix4 out, const float fov, const float aspect, const float znear, const float zfar )
{
	float zoom_x;
	float zoom_y;
	float factor;

	factor = tanf( magicalDegToRad( fov ) * 0.5f );
	debugassert( !magicalAlmostZero( factor ) && !magicalAlmostZero( aspect ), "division by 0.f" );

	zoom_y = 1.0f / factor;
	zoom_x = zoom_y / aspect;
	debugassert( !magicalAlmostZero( zfar - znear ), "division by 0.f" );

	out _m11 = zoom_x;
	out _m12 = 0.0f;
	out _m13 = 0.0f;
	out _m14 = 0.0f;

	out _m21 = 0.0f;
	out _m22 = zoom_y;
	out _m23 = 0.0f;
	out _m24 = 0.0f;

	out _m31 = 0.0f;
	out _m32 = 0.0f;
	out _m33 = ( zfar + znear ) / ( zfar - znear );
	out _m34 = 1.0f;

	out _m41 = 0.0f;
	out _m42 = 0.0f;
	out _m43 = ( 2.0f * znear * zfar ) / ( znear - zfar );
	out _m44 = 0.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为正交投影矩阵 done
 *
 * [    2/(r-l)         0           0        0   ]
 * [       0         2/(t-b)        0        0   ]
 * [       0            0        -2/(f-n)    0   ]
 * [ -(r+l)/(r-l) -(t+b)/(t-b) -(f+n)/(f-n)  1   ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4FillOrthographic( cMatrix4 out, const float left, const float right, const float bottom, const float top, const float near, const float far )
{
	debugassert( !magicalAlmostZero( right - left ) && !magicalAlmostZero( top - bottom ) && !magicalAlmostZero( far - near ), "division by 0.f" );

	out _m11 = 2.0f / ( right - left );
	out _m12 = 0.0f;
	out _m13 = 0.0f;
	out _m14 = 0.0f;

	out _m21 = 0.0f;
	out _m22 = 2.0f / ( top - bottom );
	out _m23 = 0.0f;
	out _m24 = 0.0f;

	out _m31 = 0.0f;
	out _m32 = 0.0f;
	out _m33 = - 2.0f / ( far - near );
	out _m34 = 0.0f;

	out _m41 = - ( right + left ) / ( right - left );
	out _m42 = - ( top + bottom ) / ( top - bottom );
	out _m43 = - ( far + near ) / ( far - near );
	out _m44 = 1.0f;
}

void magicalMatrix4Translate( cMatrix4 out, const cMatrix4 m, const float x, const float y, const float z )
{
	cMatrix4 dst;
	magicalMatrix4FillTranslation( dst, x, y, z );
	magicalMatrix4Mul( out, m, dst );
}

void magicalMatrix4TranslateVector( cMatrix4 out, const cMatrix4 m, const cVector3 t )
{
	cMatrix4 dst;
	magicalMatrix4FillTranslationVector( dst, t );
	magicalMatrix4Mul( out, m, dst );
}

void magicalMatrix4Scale( cMatrix4 out, const cMatrix4 m, const float x, const float y, const float z )
{
	cMatrix4 dst;
	magicalMatrix4FillScale( dst, x, y, z );
	magicalMatrix4Mul( out, m, dst );
}

void magicalMatrix4ScaleVector( cMatrix4 out, const cMatrix4 m, const cVector3 s )
{
	cMatrix4 dst;
	magicalMatrix4FillScaleVector( dst, s );
	magicalMatrix4Mul( out, m, dst );
}

void magicalMatrix4RotateX( cMatrix4 out, const cMatrix4 m, const float angle )
{
	cMatrix4 dst;
	magicalMatrix4FillRotationX( dst, angle );
	magicalMatrix4Mul( out, m, dst );
}

void magicalMatrix4RotateY( cMatrix4 out, const cMatrix4 m, const float angle )
{
	cMatrix4 dst;
	magicalMatrix4FillRotationY( dst, angle );
	magicalMatrix4Mul( out, m, dst );
}

void magicalMatrix4RotateZ( cMatrix4 out, const cMatrix4 m, const float angle )
{
	cMatrix4 dst;
	magicalMatrix4FillRotationZ( dst, angle );
	magicalMatrix4Mul( out, m, dst );
}

void magicalMatrix4RotateAxisA( cMatrix4 out, const cMatrix4 m, const cAxisA aa )
{
	cMatrix4 dst;
	magicalMatrix4FillRotationAxisA( dst, aa );
	magicalMatrix4Mul( out, m, dst );
}

void magicalMatrix4RotateEulerA( cMatrix4 out, const cMatrix4 m, const cEulerA ea )
{
	cMatrix4 dst;
	magicalMatrix4FillRotationEulerA( dst, ea );
	magicalMatrix4Mul( out, m, dst );
}

void magicalMatrix4RotateQuaternion( cMatrix4 out, const cMatrix4 m, const cQuaternion q )
{
	cMatrix4 dst;
	magicalMatrix4FillRotationQuaternion( dst, q );
	magicalMatrix4Mul( out, m, dst );
}

/*-----------------------------------------------------------------------------*\
 * 求矩阵行列式，结果为0代表奇异矩阵，不可逆 done
 *
 * m 源矩阵
 * return 矩阵行列式
 *-----------------------------------------------------------------------------*/
float magicalMatrix4Determinant( const cMatrix4 m )
{
	return
		( m _m11 * m _m22 - m _m12 * m _m21 ) *
		( m _m33 * m _m44 - m _m34 * m _m43 ) -
		( m _m11 * m _m23 - m _m13 * m _m21 ) *
		( m _m32 * m _m44 - m _m34 * m _m42 ) +
		( m _m11 * m _m24 - m _m14 * m _m21 ) *
		( m _m32 * m _m43 - m _m33 * m _m42 ) +
		( m _m12 * m _m23 - m _m13 * m _m22 ) *
		( m _m31 * m _m44 - m _m34 * m _m41 ) -
		( m _m12 * m _m24 - m _m14 * m _m22 ) *
		( m _m31 * m _m43 - m _m33 * m _m41 ) +
		( m _m13 * m _m24 - m _m14 * m _m23 ) *
		( m _m31 * m _m42 - m _m32 * m _m41 );
}

/*-----------------------------------------------------------------------------*\
 * 求矩阵的逆，当行列式为0时，返回false，矩阵不可逆 done
 *
 * out m的逆
 * m 源矩阵
 * return 是否可逆
 *-----------------------------------------------------------------------------*/
cBool magicalMatrix4Inverse( cMatrix4 out, const cMatrix4 m )
{
	float det;
	cMatrix4 adj;

	float a0 = m _m11 * m _m22 - m _m12 * m _m21;
    float a1 = m _m11 * m _m23 - m _m13 * m _m21;
    float a2 = m _m11 * m _m24 - m _m14 * m _m21;
    float a3 = m _m12 * m _m23 - m _m13 * m _m22;
    float a4 = m _m12 * m _m24 - m _m14 * m _m22;
    float a5 = m _m13 * m _m24 - m _m14 * m _m23;
    float b0 = m _m31 * m _m42 - m _m32 * m _m41;
    float b1 = m _m31 * m _m43 - m _m33 * m _m41;
    float b2 = m _m31 * m _m44 - m _m34 * m _m41;
    float b3 = m _m32 * m _m43 - m _m33 * m _m42;
    float b4 = m _m32 * m _m44 - m _m34 * m _m42;
    float b5 = m _m33 * m _m44 - m _m34 * m _m43;

	det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

	if( magicalAlmostZero( det ) )
		return cFalse;

	adj _m11 =   m _m22 * b5 - m _m23 * b4 + m _m24 * b3;
    adj _m12 = - m _m12 * b5 + m _m13 * b4 - m _m14 * b3;
    adj _m13 =   m _m42 * a5 - m _m43 * a4 + m _m44 * a3;
    adj _m14 = - m _m32 * a5 + m _m33 * a4 - m _m34 * a3;
    adj _m21 = - m _m21 * b5 + m _m23 * b2 - m _m24 * b1;
    adj _m22 =   m _m11 * b5 - m _m13 * b2 + m _m14 * b1;
    adj _m23 = - m _m41 * a5 + m _m43 * a2 - m _m44 * a1;
    adj _m24 =   m _m31 * a5 - m _m33 * a2 + m _m34 * a1;
    adj _m31 =   m _m21 * b4 - m _m22 * b2 + m _m24 * b0;
    adj _m32 = - m _m11 * b4 + m _m12 * b2 - m _m14 * b0;
    adj _m33 =   m _m41 * a4 - m _m42 * a2 + m _m44 * a0;
    adj _m34 = - m _m31 * a4 + m _m32 * a2 - m _m34 * a0;
    adj _m41 = - m _m21 * b3 + m _m22 * b1 - m _m23 * b0;
    adj _m42 =   m _m11 * b3 - m _m12 * b1 + m _m13 * b0;
    adj _m43 = - m _m41 * a3 + m _m42 * a1 - m _m43 * a0;
    adj _m44 =   m _m31 * a3 - m _m32 * a1 + m _m33 * a0;

	magicalMatrix4MulScalar( out, adj, 1.0f / det );
	return cTrue;
}

/*-----------------------------------------------------------------------------*\
 * 求矩阵的转置，正交矩阵的转置等于逆 done
 *
 * out m的转置
 * m 源矩阵
 *-----------------------------------------------------------------------------*/
void magicalMatrix4Transpose( cMatrix4 out, const cMatrix4 m )
{
	float t[16] = {
		m _m11, m _m21, m _m31, m _m41,
		m _m12, m _m22, m _m32, m _m42,
		m _m13, m _m23, m _m33, m _m43,
		m _m14, m _m24, m _m34, m _m44
	};
	memcpy( out, t, sizeof( cMatrix4 ) );
}

/*-----------------------------------------------------------------------------*\
 * 求矩阵的倒数 done
 *
 * out m的倒数
 * m 源矩阵
 *-----------------------------------------------------------------------------*/
void magicalMatrix4Negate( cMatrix4 out, const cMatrix4 m )
{
	out _m11 = -m _m11; out _m12 = -m _m12; out _m13 = -m _m13; out _m14 = -m _m14;
	out _m21 = -m _m21; out _m22 = -m _m22; out _m23 = -m _m23; out _m24 = -m _m24;
	out _m31 = -m _m31; out _m32 = -m _m32; out _m33 = -m _m33; out _m34 = -m _m34;
	out _m41 = -m _m41; out _m42 = -m _m42; out _m43 = -m _m43; out _m44 = -m _m44;
}

void magicalMatrix4GetUpVector( cVector3 out, const cMatrix4 m )
{
	out _x = m _m21;
	out _y = m _m22;
	out _z = m _m23;
}

void magicalMatrix4GetDownVector( cVector3 out, const cMatrix4 m )
{
	out _x = - m _m21;
	out _y = - m _m22;
	out _z = - m _m23;
}

void magicalMatrix4GetLeftVector( cVector3 out, const cMatrix4 m )
{
	out _x = - m _m11;
	out _y = - m _m12;
	out _z = - m _m13;
}

void magicalMatrix4GetRightVector( cVector3 out, const cMatrix4 m )
{
	out _x = m _m11;
	out _y = m _m12;
	out _z = m _m13;
}

void magicalMatrix4GetForwardVector( cVector3 out, const cMatrix4 m )
{
	out _x = - m _m31;
	out _y = - m _m32;
	out _z = - m _m33;
}

void magicalMatrix4GetBackVector( cVector3 out, const cMatrix4 m )
{
	out _x = m _m31;
	out _y = m _m32;
	out _z = m _m33;
}

/*-----------------------------------------------------------------------------*\
 * 设置矩阵的位移量 done
 *
 * [ k   k   k   k ]
 * [ k   k   k   k ]
 * [ k   k   k   k ]
 * [ x   y   z   k ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4SetTranslation( cMatrix4 out, const float x, const float y, const float z )
{
	out _m41 = x;
	out _m42 = y;
	out _m43 = z;
}

void magicalMatrix4GetTranslation( cVector3 out, const cMatrix4 m )
{
	out _x = m _m12;
	out _y = m _m13;
	out _z = m _m14;
}

void magicalMatrix4GetScale( cVector3 out, const cMatrix4 m )
{
	magicalMatrix4Decompose( NULL, out, NULL, m );
}

void magicalMatrix4GetRotationQuaternion( cQuaternion out, const cMatrix4 m )
{
	magicalMatrix4Decompose( NULL, NULL, out, m );
}

/*-----------------------------------------------------------------------------*\
 * 解析4x4的平移、旋转、缩放 done
 *
 * 投影后的矩阵会解析失败
 *
 * out_translation 解析平移
 * out_scaling 解析缩放
 * out_rotation 解析旋转
 * m 源矩阵
 *-----------------------------------------------------------------------------*/
cBool magicalMatrix4Decompose( cVector3 out_translation, cVector3 out_scaling, cQuaternion out_rotation, const cMatrix4 m )
{
	cVector3 xaxis;
	cVector3 yaxis;
	cVector3 zaxis;
	float scale_x;
	float scale_y;
	float scale_z;
	float det;
	float rn;
	float trace;
	float s;

	if( out_translation )
    {
        out_translation _x = m _m12;
        out_translation _y = m _m13;
        out_translation _z = m _m14;
    }

	if( out_scaling == NULL && out_rotation == NULL )
		return cTrue;

	magicalVector3FillScalars( xaxis, m _m11, m _m12, m _m13 );
	scale_x = magicalVector3Length( xaxis );

	magicalVector3FillScalars( yaxis, m _m21, m _m22, m _m23 );
	scale_y = magicalVector3Length( yaxis );

	magicalVector3FillScalars( zaxis, m _m31, m _m32, m _m33 );
	scale_z = magicalVector3Length( zaxis );

	det = magicalMatrix4Determinant( m );
	if( det < 0 )
		scale_z = -scale_z;

	if( out_scaling )
	{
		out_scaling _x = scale_x;
		out_scaling _y = scale_y;
		out_scaling _z = scale_z;
	}

	if( out_rotation == NULL )
		return cTrue;

	if( magicalAlmostZero( scale_x ) || magicalAlmostZero( scale_y ) || magicalAlmostZero( scale_z ) )
		return cFalse;

	rn = 1.0f / scale_x;
	xaxis _x *= rn;
	xaxis _y *= rn;
	xaxis _z *= rn;

	rn = 1.0f / scale_y;
	yaxis _x *= rn;
	yaxis _y *= rn;
	yaxis _z *= rn;

	rn = 1.0f / scale_z;
	zaxis _x *= rn;
	zaxis _y *= rn;
	zaxis _z *= rn;

	trace = xaxis _x + yaxis _y + zaxis _z + 1.0f;

	if( trace > kEpsilon )
	{
		s = 0.5f / sqrt( trace );
		out_rotation _w = 0.25f / s;
		out_rotation _x = ( yaxis _z - zaxis _y ) * s;
		out_rotation _y = ( zaxis _x - xaxis _z ) * s;
		out_rotation _z = ( xaxis _y - yaxis _x ) * s;
	}
	else
	{
		if( xaxis _x > yaxis _x && xaxis _x > zaxis _z )
		{
			s = 2.0f * sqrt( 1.0f + xaxis _x - yaxis _y - zaxis _z );
			out_rotation _w = ( yaxis _z - zaxis _y ) / s;
			out_rotation _x = 0.25f * s;
			out_rotation _y = ( yaxis _x + xaxis _y ) / s;
			out_rotation _z = ( zaxis _x + xaxis _z ) / s;
		}
		else if( yaxis _y > zaxis _z )
		{
			s = 2.0f * sqrt( 1.0f + yaxis _y - xaxis _x - zaxis _z );
			out_rotation _w = ( zaxis _x - xaxis _z ) / s;
			out_rotation _x = ( yaxis _x + xaxis _y ) / s;
			out_rotation _y = 0.25f * s;
			out_rotation _z = ( zaxis _y + yaxis _z ) / s;
		}
		else
		{
			s = 2.0f * sqrt( 1.0f + zaxis _z - xaxis _x - yaxis _y );
			out_rotation _w = ( xaxis _y - yaxis _x ) / s;
			out_rotation _x = ( zaxis _x + xaxis _z ) / s;
			out_rotation _y = ( zaxis _y + yaxis _z ) / s;
			out_rotation _z = 0.25f * s;
		}
	}

	return cTrue;
}