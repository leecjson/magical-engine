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

cBool magicalMatrix4Equals( const cMatrix4* m1, const cMatrix4* m2 )
{
	const float* v1 = (const float*) m1;
	const float* v2 = (const float*) m2;

	for( int i = 0; i < 16; ++i )
	{
		if( magicalAlmostEqual( v1[i], v2[i], kVectorEpsilon ) == cFalse )
		{
			return cFalse;
		}
	}
	return cTrue;
}

cBool magicalMatrix4IsIdentity( const cMatrix4* m )
{
	const float* v = (const float*) m;

	for( int i = 0; i < 16; ++i )
	{
		if( magicalAlmostEqual( v[i], IDENTITY[i], kVectorEpsilon ) == cFalse )
		{
			return cFalse;
		}
	}
	return cTrue;
}

cBool magicalMatrix4IsZero( const cMatrix4* m )
{
	const float* v = (const float*) m;

	for( int i = 0; i < 16; ++i )
	{
		if( magicalAlmostEqual( v[i], ZERO[i], kVectorEpsilon ) == cFalse )
		{
			return cFalse;
		}
	}
	return cTrue;
}

void magicalMatrix4Fill( cMatrix4* out,
	float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44 )
{
	out->m11 = m11; out->m12 = m12; out->m13 = m13; out->m14 = m14;
	out->m21 = m21; out->m22 = m22; out->m23 = m23; out->m24 = m24;
	out->m31 = m31; out->m32 = m32; out->m33 = m33; out->m34 = m34;
	out->m41 = m41; out->m42 = m42; out->m43 = m43; out->m44 = m44;
}

void magicalMatrix4Copy( cMatrix4* out, const cMatrix4* m )
{
	memcpy( out, m, sizeof( cMatrix4 ) );
}

void magicalMatrix4SetIdentity( cMatrix4* out )
{
	memcpy( out, IDENTITY, sizeof( cMatrix4 ) );
}

void magicalMatrix4SetZero( cMatrix4* out )
{
	memcpy( out, ZERO, sizeof( cMatrix4 ) );
}

/*-----------------------------------------------------------------------------*\
 * 填充为从eye点到target的观察矩阵 done
 *
 * out 结果
 * eye 观察原点
 * target 观察目标点
 * up 倾斜方向
 *-----------------------------------------------------------------------------*/
void magicalMatrix4SetLookAt( cMatrix4* out, const cVector3* eye, const cVector3* target, const cVector3* up )
{
	cVector3 up_v;
	cVector3 x_axis;
	cVector3 y_axis;
	cVector3 z_axis;

	magicalVector3Copy( &up_v, up );
	magicalVector3Normalize( &up_v, &up_v );

	magicalVector3Sub( &z_axis, eye, target );
	magicalVector3Normalize( &z_axis, &z_axis );

	magicalVector3Cross( &x_axis, &up_v, &z_axis );
	magicalVector3Normalize( &x_axis, &x_axis );

	magicalVector3Cross( &y_axis, &z_axis, &x_axis );
	magicalVector3Normalize( &y_axis, &y_axis );

	out->m11 = x_axis.x;
	out->m12 = y_axis.x;
	out->m13 = z_axis.x;
	out->m14 = 0.0f;

	out->m21 = x_axis.y;
	out->m22 = y_axis.y;
	out->m23 = z_axis.y;
	out->m24 = 0.0f;

	out->m31 = x_axis.z;
	out->m32 = y_axis.z;
	out->m33 = z_axis.z;
	out->m34 = 0.0f;

	out->m41 = - magicalVector3Dot( &x_axis, eye );
	out->m42 = - magicalVector3Dot( &y_axis, eye );
	out->m43 = - magicalVector3Dot( &z_axis, eye );
	out->m44 = 1.0f;
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
void magicalMatrix4SetPerspective( cMatrix4* out, float fov, float aspect, float znear, float zfar )
{
	float zoom_x;
	float zoom_y;
	float factor;

	factor = tanf( magicalDegToRad( fov ) * 0.5f );
	debugassert( !magicalAlmostZero( factor, kVectorEpsilon ) && !magicalAlmostZero( aspect, kVectorEpsilon ), "division by 0.f" );

	zoom_y = 1.0f / factor;
	zoom_x = zoom_y / aspect;
	debugassert( !magicalAlmostZero( zfar - znear, kVectorEpsilon ), "division by 0.f" );

	out->m11 = zoom_x;
	out->m12 = 0.0f;
	out->m13 = 0.0f;
	out->m14 = 0.0f;

	out->m21 = 0.0f;
	out->m22 = zoom_y;
	out->m23 = 0.0f;
	out->m24 = 0.0f;

	out->m31 = 0.0f;
	out->m32 = 0.0f;
	out->m33 = ( zfar + znear ) / ( zfar - znear );
	out->m34 = 1.0f;

	out->m41 = 0.0f;
	out->m42 = 0.0f;
	out->m43 = ( 2.0f * znear * zfar ) / ( znear - zfar );
	out->m44 = 0.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为正交投影矩阵 done
 *
 * [    2/(r-l)         0           0        0   ]
 * [       0         2/(t-b)        0        0   ]
 * [       0            0        -2/(f-n)    0   ]
 * [ -(r+l)/(r-l) -(t+b)/(t-b) -(f+n)/(f-n)  1   ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4SetOrth( cMatrix4* out, float left, float right, float bottom, float top, float near, float far )
{
	debugassert( !magicalAlmostZero( right - left, kVectorEpsilon ) && !magicalAlmostZero( top - bottom, kVectorEpsilon ) && !magicalAlmostZero( far - near, kVectorEpsilon ), "division by 0.f" );

	out->m11 = 2.0f / ( right - left );
	out->m12 = 0.0f;
	out->m13 = 0.0f;
	out->m14 = 0.0f;

	out->m21 = 0.0f;
	out->m22 = 2.0f / ( top - bottom );
	out->m23 = 0.0f;
	out->m24 = 0.0f;

	out->m31 = 0.0f;
	out->m32 = 0.0f;
	out->m33 = - 2.0f / ( far - near );
	out->m34 = 0.0f;

	out->m41 = - ( right + left ) / ( right - left );
	out->m42 = - ( top + bottom ) / ( top - bottom );
	out->m43 = - ( far + near ) / ( far - near );
	out->m44 = 1.0f;
}

void magicalMatrix4SetTRS( cMatrix4* out, const cVector3* t, const cQuaternion* r, const cVector3* s )
{
	cMatrix3 rm3;

	rm3.m11 = 1.0f - 2.0f * ( r->y * r->y + r->z * r->z );
	rm3.m12 = 2.0f * ( r->x * r->y + r->z * r->w );
	rm3.m13 = 2.0f * ( r->x * r->z - r->y * r->w );

	rm3.m21 = 2.0f * ( r->x * r->y - r->z * r->w );
	rm3.m22 = 1.0f - 2.0f * ( r->x * r->x + r->z * r->z );
	rm3.m23 = 2.0f * ( r->z * r->y + r->x * r->w );

	rm3.m31 = 2.0f * ( r->x * r->z + r->y * r->w );
	rm3.m32 = 2.0f * ( r->y * r->z - r->x * r->w );
	rm3.m33 = 1.0f - 2.0f * ( r->x * r->x + r->y * r->y );

	out->m11 = rm3.m11 * s->x; out->m12 = rm3.m12 * s->y; out->m13 = rm3.m13 * s->z; out->m14 = 0.0f;
	out->m21 = rm3.m21 * s->x; out->m22 = rm3.m22 * s->y; out->m23 = rm3.m23 * s->z; out->m24 = 0.0f;
	out->m31 = rm3.m31 * s->x; out->m32 = rm3.m32 * s->y; out->m33 = rm3.m33 * s->z; out->m34 = 0.0f;
	out->m41 = t->x;           out->m42 = t->y;           out->m43 = t->z;           out->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为位移矩阵 done
 *
 * [ 1   0   0   0 ]
 * [ 0   1   0   0 ]
 * [ 0   0   1   0 ]
 * [ x   y   z   1 ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4MakeTranslationScalars( cMatrix4* out, float x, float y, float z )
{
	out->m11 = 1.0f; out->m12 = 0.0f; out->m13 = 0.0f; out->m14 = 0.0f;
	out->m21 = 0.0f; out->m22 = 1.0f; out->m23 = 0.0f; out->m24 = 0.0f;
	out->m31 = 0.0f; out->m32 = 0.0f; out->m33 = 1.0f; out->m34 = 0.0f;
	out->m41 = x;    out->m42 = y;    out->m43 = z;    out->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为位移矩阵 done
 *
 * [ 1   0   0   0 ]
 * [ 0   1   0   0 ]
 * [ 0   0   1   0 ]
 * [ x   y   z   1 ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4MakeTranslation( cMatrix4* out, const cVector3* t )
{
	out->m11 = 1.0f; out->m12 = 0.0f; out->m13 = 0.0f; out->m14 = 0.0f;
	out->m21 = 0.0f; out->m22 = 1.0f; out->m23 = 0.0f; out->m24 = 0.0f;
	out->m31 = 0.0f; out->m32 = 0.0f; out->m33 = 1.0f; out->m34 = 0.0f;
	out->m41 = t->x; out->m42 = t->y; out->m43 = t->z; out->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为轴缩放矩阵 done
 *
 * [ x   0   0   0 ]
 * [ 0   y   0   0 ]
 * [ 0   0   z   0 ]
 * [ 0   0   0   1 ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4MakeScaleScalars( cMatrix4* out, float x, float y, float z )
{
	out->m11 = x;    out->m12 = 0.0f; out->m13 = 0.0f; out->m14 = 0.0f;
	out->m21 = 0.0f; out->m22 = y;    out->m23 = 0.0f; out->m24 = 0.0f;
	out->m31 = 0.0f; out->m32 = 0.0f; out->m33 = z;    out->m34 = 0.0f;
	out->m41 = 0.0f; out->m42 = 0.0f; out->m43 = 0.0f; out->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为轴缩放矩阵 done
 *
 * [ x   0   0   0 ]
 * [ 0   y   0   0 ]
 * [ 0   0   z   0 ]
 * [ 0   0   0   1 ]
 *-----------------------------------------------------------------------------*/
void magicalMatrix4MakeScale( cMatrix4* out, const cVector3* s )
{
	out->m11 = s->x; out->m12 = 0.0f; out->m13 = 0.0f; out->m14 = 0.0f;
	out->m21 = 0.0f; out->m22 = s->y; out->m23 = 0.0f; out->m24 = 0.0f;
	out->m31 = 0.0f; out->m32 = 0.0f; out->m33 = s->z; out->m34 = 0.0f;
	out->m41 = 0.0f; out->m42 = 0.0f; out->m43 = 0.0f; out->m44 = 1.0f;
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
void magicalMatrix4MakeRotationX( cMatrix4* out, float angle )
{
	float c = cosf( angle );
	float s = sinf( angle );

	out->m11 = 1.0f; out->m12 = 0.0f; out->m13 = 0.0f; out->m14 = 0.0f;
	out->m21 = 0.0f; out->m22 = c;    out->m23 = s;    out->m24 = 0.0f;
	out->m31 = 0.0f; out->m32 = -s;   out->m33 = c;    out->m34 = 0.0f;
	out->m41 = 0.0f; out->m42 = 0.0f; out->m43 = 0.0f; out->m44 = 1.0f;
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
void magicalMatrix4MakeRotationY( cMatrix4* out, float angle )
{
	float c = cosf( angle );
	float s = sinf( angle );

	out->m11 = c;    out->m12 = 0.0f; out->m13 = -s;   out->m14 = 0.0f;
	out->m21 = 0.0f; out->m22 = 1.0f; out->m23 = 0.0f; out->m24 = 0.0f;
	out->m31 = s;    out->m32 = 0.0f; out->m33 = c;    out->m34 = 0.0f;
	out->m41 = 0.0f; out->m42 = 0.0f; out->m43 = 0.0f; out->m44 = 1.0f;
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
void magicalMatrix4MakeRotationZ( cMatrix4* out, float angle )
{
	float c = cosf( angle );
	float s = sinf( angle );

	out->m11 = c;    out->m12 = s;    out->m13 = 0.0f; out->m14 = 0.0f;
	out->m21 = -s;   out->m22 = c;    out->m23 = 0.0f; out->m24 = 0.0f;
	out->m31 = 0.0f; out->m32 = 0.0f; out->m33 = 1.0f; out->m34 = 0.0f;
	out->m41 = 0.0f; out->m42 = 0.0f; out->m43 = 0.0f; out->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为任意旋转轴旋转矩阵 done
 *
 * out 结果
 * aa 任意轴
 *-----------------------------------------------------------------------------*/
void magicalMatrix4MakeRotationAxisAngle( cMatrix4* out, const cAxisAngle* aa )
{
	float s, c;
	magicalSinCos( &s, &c, aa->w );

	float a = 1.0f - c;
	float ax = a * aa->x;
	float ay = a * aa->y;
	float az = a * aa->z;

	out->m11 = ax * aa->x + c;
	out->m12 = ax * aa->y + aa->z * s;
	out->m13 = ax * aa->z - aa->y * s;
	out->m14 = 0.0f;

	out->m21 = ay * aa->x - aa->z * s;
	out->m22 = ay * aa->y + c;
	out->m23 = ay * aa->z + aa->x * s;
	out->m24 = 0.0f;

	out->m31 = az * aa->x + aa->y * s;
	out->m32 = az * aa->y - aa->x * s;
	out->m33 = az * aa->z + c;
	out->m34 = 0.0f;

	out->m41 = 0.0f;
	out->m42 = 0.0f;
	out->m43 = 0.0f;
	out->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为欧拉角旋转矩阵 done
 *
 * out 结果
 * ea 欧拉角
 *-----------------------------------------------------------------------------*/
void magicalMatrix4MakeRotationEulerAngles( cMatrix4* out, const cEulerAngles* ea )
{
	float yaw, pitch, roll;

#if 1
	cEulerAngles dst;
	magicalEulerAnglesLimit( &dst, ea );
	yaw   = magicalDegToRad( dst.yaw );
	pitch = magicalDegToRad( dst.pitch );
	roll  = magicalDegToRad( dst.roll );
#else
	yaw   = ea.yaw;
	pitch = ea.pitch;
	roll  = ea.roll;
#endif

	float cr = cosf( dst.pitch );
	float sr = sinf( dst.pitch );
	float cp = cosf( dst.yaw );
	float sp = sinf( dst.yaw );
	float cy = cosf( dst.roll );
	float sy = sinf( dst.roll );
	float srsp = sr * sp;
	float crsp = cr * sp;

    out->m11 = cp * cy;
    out->m21 = cp * sy;
    out->m31 = -    sp;
	out->m41 = 0.0f;

	out->m12 = srsp * cy - cr * sy;
	out->m22 = srsp * sy + cr * cy;
	out->m32 = sr * cp;
	out->m42 = 0.0f;

	out->m13 = crsp * cy + sr * sy;
	out->m23 = crsp * sy - sr * cy;
	out->m33 = cr * cp;
	out->m43 = 0.0f;

	out->m14 = 0.0f;
	out->m24 = 0.0f;
	out->m34 = 0.0f;
	out->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 填充为四元数旋转矩阵 done
 *
 * out 结果
 * q 旋转四元数
 *-----------------------------------------------------------------------------*/
void magicalMatrix4MakeRotationQuaternion( cMatrix4* out, const cQuaternion* q )
{
	out->m11 = 1.0f - 2.0f * ( q->y * q->y + q->z * q->z );
	out->m12 = 2.0f * ( q->x * q->y + q->z * q->w );
	out->m13 = 2.0f * ( q->x * q->z - q->y * q->w );
	out->m14 = 0.0f;

	out->m21 = 2.0f * ( q->x * q->y - q->z * q->w );
	out->m22 = 1.0f - 2.0f * ( q->x * q->x + q->z * q->z );
	out->m23 = 2.0f * ( q->z * q->y + q->x * q->w );
	out->m24 = 0.0f;

	out->m31 = 2.0f * ( q->x * q->z + q->y * q->w );
	out->m32 = 2.0f * ( q->y * q->z - q->x * q->w );
	out->m33 = 1.0f - 2.0f * ( q->x * q->x + q->y * q->y );
	out->m34 = 0.0f;

	out->m41 = 0.0f;
	out->m42 = 0.0f;
	out->m43 = 0.0f;
	out->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------*\
 * 4x4 行优先齐次矩阵与标量相乘 done
 *-----------------------------------------------------------------------------*/
void magicalMatrix4MulScalar( cMatrix4* out, const cMatrix4* m, float a )
{
	out->m11 = m->m11 * a;
	out->m12 = m->m12 * a;
	out->m13 = m->m13 * a;
	out->m14 = m->m14 * a;

	out->m21 = m->m21 * a;
	out->m22 = m->m22 * a;
	out->m23 = m->m23 * a;
	out->m24 = m->m24 * a;

	out->m31 = m->m31 * a;
	out->m32 = m->m32 * a;
	out->m33 = m->m33 * a;
	out->m34 = m->m34 * a;

	out->m41 = m->m41 * a;
	out->m42 = m->m42 * a;
	out->m43 = m->m43 * a;
	out->m44 = m->m44 * a;
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
void magicalMatrix4Mul( cMatrix4* out, const cMatrix4* m1, const cMatrix4* m2 )
{
	cMatrix4 dst;

	dst.m11 = m1->m11 * m2->m11 + m1->m12 * m2->m21 + m1->m13 * m2->m31 + m1->m14 * m2->m41;
	dst.m12 = m1->m11 * m2->m12 + m1->m12 * m2->m22 + m1->m13 * m2->m32 + m1->m14 * m2->m42;
	dst.m13 = m1->m11 * m2->m13 + m1->m12 * m2->m23 + m1->m13 * m2->m33 + m1->m14 * m2->m43;
	dst.m14 = m1->m11 * m2->m14 + m1->m12 * m2->m24 + m1->m13 * m2->m34 + m1->m14 * m2->m44;
	dst.m21 = m1->m21 * m2->m11 + m1->m22 * m2->m21 + m1->m23 * m2->m31 + m1->m24 * m2->m41;
	dst.m22 = m1->m21 * m2->m12 + m1->m22 * m2->m22 + m1->m23 * m2->m32 + m1->m24 * m2->m42;
	dst.m23 = m1->m21 * m2->m13 + m1->m22 * m2->m23 + m1->m23 * m2->m33 + m1->m24 * m2->m43;
	dst.m24 = m1->m21 * m2->m14 + m1->m22 * m2->m24 + m1->m23 * m2->m34 + m1->m24 * m2->m44;
	dst.m31 = m1->m31 * m2->m11 + m1->m32 * m2->m21 + m1->m33 * m2->m31 + m1->m34 * m2->m41;
	dst.m32 = m1->m31 * m2->m12 + m1->m32 * m2->m22 + m1->m33 * m2->m32 + m1->m34 * m2->m42;
	dst.m33 = m1->m31 * m2->m13 + m1->m32 * m2->m23 + m1->m33 * m2->m33 + m1->m34 * m2->m43;
	dst.m34 = m1->m31 * m2->m14 + m1->m32 * m2->m24 + m1->m33 * m2->m34 + m1->m34 * m2->m44;
	dst.m41 = m1->m41 * m2->m11 + m1->m42 * m2->m21 + m1->m43 * m2->m31 + m1->m44 * m2->m41;
	dst.m42 = m1->m41 * m2->m12 + m1->m42 * m2->m22 + m1->m43 * m2->m32 + m1->m44 * m2->m42;
	dst.m43 = m1->m41 * m2->m13 + m1->m42 * m2->m23 + m1->m43 * m2->m33 + m1->m44 * m2->m43;
	dst.m44 = m1->m41 * m2->m14 + m1->m42 * m2->m24 + m1->m43 * m2->m34 + m1->m44 * m2->m44;

	memcpy( out, &dst, sizeof( cMatrix4 ) );
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
void magicalMatrix4Mul3x3AndTranslation( cMatrix4* out, const cMatrix4* m1, const cMatrix4* m2 )
{
	cMatrix4 dst;

	dst.m11 = m1->m11 * m2->m11 + m1->m12 * m2->m21 + m1->m13 * m2->m31;
	dst.m12 = m1->m11 * m2->m12 + m1->m12 * m2->m22 + m1->m13 * m2->m32;
	dst.m13 = m1->m11 * m2->m13 + m1->m12 * m2->m23 + m1->m13 * m2->m33;
	dst.m14 = 0.0f;
	dst.m21 = m1->m21 * m2->m11 + m1->m22 * m2->m21 + m1->m23 * m2->m31;
	dst.m22 = m1->m21 * m2->m12 + m1->m22 * m2->m22 + m1->m23 * m2->m32;
	dst.m23 = m1->m21 * m2->m13 + m1->m22 * m2->m23 + m1->m23 * m2->m33;
	dst.m24 = 0.0f;
	dst.m31 = m1->m31 * m2->m11 + m1->m32 * m2->m21 + m1->m33 * m2->m31;
	dst.m32 = m1->m31 * m2->m12 + m1->m32 * m2->m22 + m1->m33 * m2->m32;
	dst.m33 = m1->m31 * m2->m13 + m1->m32 * m2->m23 + m1->m33 * m2->m33;
	dst.m34 = 0.0f;
	dst.m41 = m1->m41 * m2->m11 + m1->m42 * m2->m21 + m1->m43 * m2->m31 + m2->m41;
	dst.m42 = m1->m41 * m2->m12 + m1->m42 * m2->m22 + m1->m43 * m2->m32 + m2->m42;
	dst.m43 = m1->m41 * m2->m13 + m1->m42 * m2->m23 + m1->m43 * m2->m33 + m2->m43;
	dst.m44 = 1.0f;

	memcpy( out, &dst, sizeof( cMatrix4 ) );
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
void magicalVector3MulMatrix4( cVector3* out, const cVector3* v, const cMatrix4* m )
{
	cVector3 dst;

	dst.x = v->x * m->m11 + v->y * m->m21 + v->z * m->m31 + m->m41;
	dst.y = v->x * m->m12 + v->y * m->m22 + v->z * m->m32 + m->m42;
	dst.z = v->x * m->m13 + v->y * m->m23 + v->z * m->m33 + m->m43;

	out->x = dst.x;
	out->y = dst.y;
	out->z = dst.z;
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
void magicalVector4MulMatrix4( cVector4* out, const cVector4* v, const cMatrix4* m )
{
	cVector4 dst;

	dst.x = v->x * m->m11 + v->y * m->m21 + v->z * m->m31 + v->w * m->m41;
	dst.y = v->x * m->m12 + v->y * m->m22 + v->z * m->m32 + v->w * m->m42;
	dst.z = v->x * m->m13 + v->y * m->m23 + v->z * m->m33 + v->w * m->m43;
	dst.w = v->x * m->m14 + v->y * m->m24 + v->z * m->m34 + v->w * m->m44;

	out->x = dst.x;
	out->y = dst.y;
	out->z = dst.z;
	out->w = dst.w;
}

/*-----------------------------------------------------------------------------*\
 * 求矩阵的转置，正交矩阵的转置等于逆 done
 *
 * out m的转置
 * m 源矩阵
 *-----------------------------------------------------------------------------*/
void magicalMatrix4Transpose( cMatrix4* out, const cMatrix4* m )
{
	float t[16] = {
		m->m11, m->m21, m->m31, m->m41,
		m->m12, m->m22, m->m32, m->m42,
		m->m13, m->m23, m->m33, m->m43,
		m->m14, m->m24, m->m34, m->m44
	};
	memcpy( out, t, sizeof( cMatrix4 ) );
}

/*-----------------------------------------------------------------------------*\
 * 求矩阵的倒数 done
 *
 * out m的倒数
 * m 源矩阵
 *-----------------------------------------------------------------------------*/
void magicalMatrix4Negate( cMatrix4* out, const cMatrix4* m )
{
	out->m11 = -m->m11; out->m12 = -m->m12; out->m13 = -m->m13; out->m14 = -m->m14;
	out->m21 = -m->m21; out->m22 = -m->m22; out->m23 = -m->m23; out->m24 = -m->m24;
	out->m31 = -m->m31; out->m32 = -m->m32; out->m33 = -m->m33; out->m34 = -m->m34;
	out->m41 = -m->m41; out->m42 = -m->m42; out->m43 = -m->m43; out->m44 = -m->m44;
}

void magicalMatrix4GetUpVector( cVector3* out, const cMatrix4* m )
{
	out->x = m->m21;
	out->y = m->m22;
	out->z = m->m23;
}

void magicalMatrix4GetDownVector( cVector3* out, const cMatrix4* m )
{
	out->x = - m->m21;
	out->y = - m->m22;
	out->z = - m->m23;
}

void magicalMatrix4GetLeftVector( cVector3* out, const cMatrix4* m )
{
	out->x = - m->m11;
	out->y = - m->m12;
	out->z = - m->m13;
}

void magicalMatrix4GetRightVector( cVector3* out, const cMatrix4* m )
{
	out->x = m->m11;
	out->y = m->m12;
	out->z = m->m13;
}

void magicalMatrix4GetForwardVector( cVector3* out, const cMatrix4* m )
{
	out->x = - m->m31;
	out->y = - m->m32;
	out->z = - m->m33;
}

void magicalMatrix4GetBackVector( cVector3* out, const cMatrix4* m )
{
	out->x = m->m31;
	out->y = m->m32;
	out->z = m->m33;
}

void magicalMatrix4SetTranslation( cMatrix4* out, const cVector3* m )
{
	out->m41 = m->x;
	out->m42 = m->y;
	out->m43 = m->z;
}

void magicalMatrix4GetTranslation( cVector3* out, const cMatrix4* m )
{
	out->x = m->m41;
	out->y = m->m42;
	out->z = m->m43;
}

void magicalMatrix4GetScale( cVector3* out, const cMatrix4* m )
{
	magicalMatrix4Decompose( NULL, out, NULL, m );
}

void magicalMatrix4GetRotationQuaternion( cQuaternion* out, const cMatrix4* m )
{
	magicalMatrix4Decompose( NULL, NULL, out, m );
}

/*-----------------------------------------------------------------------------*\
 * 求矩阵行列式，结果为0代表奇异矩阵，不可逆 done
 *
 * m 源矩阵
 * return 矩阵行列式
 *-----------------------------------------------------------------------------*/
float magicalMatrix4Determinant( const cMatrix4* m )
{
	return
		( m->m11 * m->m22 - m->m12 * m->m21 ) *
		( m->m33 * m->m44 - m->m34 * m->m43 ) -
		( m->m11 * m->m23 - m->m13 * m->m21 ) *
		( m->m32 * m->m44 - m->m34 * m->m42 ) +
		( m->m11 * m->m24 - m->m14 * m->m21 ) *
		( m->m32 * m->m43 - m->m33 * m->m42 ) +
		( m->m12 * m->m23 - m->m13 * m->m22 ) *
		( m->m31 * m->m44 - m->m34 * m->m41 ) -
		( m->m12 * m->m24 - m->m14 * m->m22 ) *
		( m->m31 * m->m43 - m->m33 * m->m41 ) +
		( m->m13 * m->m24 - m->m14 * m->m23 ) *
		( m->m31 * m->m42 - m->m32 * m->m41 );
}

/*-----------------------------------------------------------------------------*\
 * 求矩阵的逆，当行列式为0时，矩阵不可逆 done
 *
 * out m的逆
 * m 源矩阵
 * return 是否可逆
 *-----------------------------------------------------------------------------*/
cBool magicalMatrix4Inverse( cMatrix4* out, const cMatrix4* m )
{
	float det;
	cMatrix4 adj;

	float a0 = m->m11 * m->m22 - m->m12 * m->m21;
    float a1 = m->m11 * m->m23 - m->m13 * m->m21;
    float a2 = m->m11 * m->m24 - m->m14 * m->m21;
    float a3 = m->m12 * m->m23 - m->m13 * m->m22;
    float a4 = m->m12 * m->m24 - m->m14 * m->m22;
    float a5 = m->m13 * m->m24 - m->m14 * m->m23;
    float b0 = m->m31 * m->m42 - m->m32 * m->m41;
    float b1 = m->m31 * m->m43 - m->m33 * m->m41;
    float b2 = m->m31 * m->m44 - m->m34 * m->m41;
    float b3 = m->m32 * m->m43 - m->m33 * m->m42;
    float b4 = m->m32 * m->m44 - m->m34 * m->m42;
    float b5 = m->m33 * m->m44 - m->m34 * m->m43;

	det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

	if( magicalAlmostZero( det, kVectorEpsilon ) )
	{
		debugassert( cFalse, "matrix4 can't be inversed" );
		return cFalse;
	}

	adj.m11 =   m->m22 * b5 - m->m23 * b4 + m->m24 * b3;
    adj.m12 = - m->m12 * b5 + m->m13 * b4 - m->m14 * b3;
    adj.m13 =   m->m42 * a5 - m->m43 * a4 + m->m44 * a3;
    adj.m14 = - m->m32 * a5 + m->m33 * a4 - m->m34 * a3;
    adj.m21 = - m->m21 * b5 + m->m23 * b2 - m->m24 * b1;
    adj.m22 =   m->m11 * b5 - m->m13 * b2 + m->m14 * b1;
    adj.m23 = - m->m41 * a5 + m->m43 * a2 - m->m44 * a1;
    adj.m24 =   m->m31 * a5 - m->m33 * a2 + m->m34 * a1;
    adj.m31 =   m->m21 * b4 - m->m22 * b2 + m->m24 * b0;
    adj.m32 = - m->m11 * b4 + m->m12 * b2 - m->m14 * b0;
    adj.m33 =   m->m41 * a4 - m->m42 * a2 + m->m44 * a0;
    adj.m34 = - m->m31 * a4 + m->m32 * a2 - m->m34 * a0;
    adj.m41 = - m->m21 * b3 + m->m22 * b1 - m->m23 * b0;
    adj.m42 =   m->m11 * b3 - m->m12 * b1 + m->m13 * b0;
    adj.m43 = - m->m41 * a3 + m->m42 * a1 - m->m43 * a0;
    adj.m44 =   m->m31 * a3 - m->m32 * a1 + m->m33 * a0;

	magicalMatrix4MulScalar( out, &adj, 1.0f / det );
	return cTrue;
}

/*-----------------------------------------------------------------------------*\
 * 解析4x4的平移、旋转、缩放 done
 *
 * 投影后的矩阵会解析失败
 *
 * out_t 解析平移
 * out_r 解析旋转
 * out_s 解析缩放
 * m 源矩阵
 *-----------------------------------------------------------------------------*/
cBool magicalMatrix4Decompose( cVector3* out_t, cQuaternion* out_r, cVector3* out_s, const cMatrix4* m )
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

	if( out_t )
    {
        out_t->x = m->m12;
        out_t->y = m->m13;
        out_t->z = m->m14;
    }

	if( out_s == NULL && out_r == NULL )
		return cTrue;

	magicalVector3Fill( &xaxis, m->m11, m->m12, m->m13 );
	scale_x = magicalVector3Length( &xaxis );

	magicalVector3Fill( &yaxis, m->m21, m->m22, m->m23 );
	scale_y = magicalVector3Length( &yaxis );

	magicalVector3Fill( &zaxis, m->m31, m->m32, m->m33 );
	scale_z = magicalVector3Length( &zaxis );

	det = magicalMatrix4Determinant( m );
	if( det < 0 )
		scale_z = -scale_z;

	if( out_s )
	{
		out_s->x = scale_x;
		out_s->y = scale_y;
		out_s->z = scale_z;
	}

	if( out_r == NULL )
		return cTrue;

	if( magicalAlmostZero( scale_x, kVectorEpsilon ) || magicalAlmostZero( scale_y, kVectorEpsilon ) || magicalAlmostZero( scale_z, kVectorEpsilon ) )
		return cFalse;

	rn = 1.0f / scale_x;
	xaxis.x *= rn;
	xaxis.y *= rn;
	xaxis.z *= rn;

	rn = 1.0f / scale_y;
	yaxis.x *= rn;
	yaxis.y *= rn;
	yaxis.z *= rn;

	rn = 1.0f / scale_z;
	zaxis.x *= rn;
	zaxis.y *= rn;
	zaxis.z *= rn;

	trace = xaxis.x + yaxis.y + zaxis.z + 1.0f;

	if( trace > kVectorEpsilon )
	{
		s = 0.5f / sqrt( trace );
		out_r->w = 0.25f / s;
		out_r->x = ( yaxis.z - zaxis.y ) * s;
		out_r->y = ( zaxis.x - xaxis.z ) * s;
		out_r->z = ( xaxis.y - yaxis.x ) * s;
	}
	else
	{
		if( xaxis.x > yaxis.x && xaxis.x > zaxis.z )
		{
			s = 2.0f * sqrt( 1.0f + xaxis.x - yaxis.y - zaxis.z );
			out_r->w = ( yaxis.z - zaxis.y ) / s;
			out_r->x = 0.25f * s;
			out_r->y = ( yaxis.x + xaxis.y ) / s;
			out_r->z = ( zaxis.x + xaxis.z ) / s;
		}
		else if( yaxis.y > zaxis.z )
		{
			s = 2.0f * sqrt( 1.0f + yaxis.y - xaxis.x - zaxis.z );
			out_r->w = ( zaxis.x - xaxis.z ) / s;
			out_r->x = ( yaxis.x + xaxis.y ) / s;
			out_r->y = 0.25f * s;
			out_r->z = ( zaxis.y + yaxis.z ) / s;
		}
		else
		{
			s = 2.0f * sqrt( 1.0f + zaxis.z - xaxis.x - yaxis.y );
			out_r->w = ( xaxis.y - yaxis.x ) / s;
			out_r->x = ( zaxis.x + xaxis.z ) / s;
			out_r->y = ( zaxis.y + yaxis.z ) / s;
			out_r->z = 0.25f * s;
		}
	}

	return cTrue;
}