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
#include "c-matrix3.h"
#include <memory.h>

static const float IDENTITY[] =
{
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f
};

cBool magicalMatrix3Equals( const cMatrix3* m1, const cMatrix3* m2 )
{
	if( !magicalAlmostEqual( m1->m11, m2->m11, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m1->m12, m2->m12, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m1->m13, m2->m13, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m1->m21, m2->m21, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m1->m22, m2->m22, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m1->m23, m2->m23, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m1->m31, m2->m31, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m1->m32, m2->m32, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m1->m33, m2->m33, kVectorEpsilon ) ) return cFalse;

	return cTrue;
}

cBool magicalMatrix3IsIdentity( const cMatrix3* m )
{
	if( !magicalAlmostEqual( m->m11, 1.0f, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m->m12, 0.0f, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m->m13, 0.0f, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m->m21, 0.0f, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m->m22, 1.0f, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m->m23, 0.0f, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m->m31, 0.0f, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m->m32, 0.0f, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostEqual( m->m33, 1.0f, kVectorEpsilon ) ) return cFalse;

	return cTrue;
}

cBool magicalMatrix3IsZero( const cMatrix3* m )
{
	if( !magicalAlmostZero( m->m11, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostZero( m->m12, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostZero( m->m13, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostZero( m->m21, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostZero( m->m22, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostZero( m->m23, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostZero( m->m31, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostZero( m->m32, kVectorEpsilon ) ) return cFalse;
	if( !magicalAlmostZero( m->m33, kVectorEpsilon ) ) return cFalse;

	return cTrue;
}

void magicalMatrix3Fill( cMatrix3* out, float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33 )
{
	out->m11 = m11; out->m12 = m12; out->m13 = m13;
	out->m21 = m21; out->m22 = m22; out->m23 = m23;
	out->m31 = m31; out->m32 = m32; out->m33 = m33;
}

void magicalMatrix3Copy( cMatrix3* out, const cMatrix3* m )
{
	memcpy( out, &m, sizeof( cMatrix3 ) );
}

void magicalMatrix3SetIdentity( cMatrix3* out )
{
	out->m11 = 1.0f; out->m12 = 0.0f; out->m13 = 0.0f;
	out->m21 = 0.0f; out->m22 = 1.0f; out->m23 = 0.0f;
	out->m31 = 0.0f; out->m32 = 0.0f; out->m33 = 1.0f;
}

void magicalMatrix3SetZero( cMatrix3* out )
{
	memset( out, 0, sizeof( cMatrix3 ) );
}

void magicalMatrix3SetLookAt( cMatrix3* out, const cVector3* eye, const cVector3* target, const cVector3* up )
{
	cVector3 up_v;
	cVector3 x_axis, y_axis, z_axis;

	magicalVector3Copy( &up_v, up );
	magicalVector3Normalize( &up_v, &up_v );

	magicalVector3Sub( &z_axis, eye, target );
	magicalVector3Normalize( &z_axis, &z_axis );

	magicalVector3Cross( &x_axis, &up_v, &z_axis );
	magicalVector3Normalize( &x_axis, &x_axis );

	magicalVector3Cross( &y_axis, &z_axis, &x_axis );
	magicalVector3Normalize( &y_axis, &y_axis );

	out->m11 = x_axis.x; out->m12 = y_axis.x; out->m13 = z_axis.x;
	out->m21 = x_axis.y; out->m22 = y_axis.y; out->m23 = z_axis.y;
	out->m31 = x_axis.z; out->m32 = y_axis.z; out->m33 = z_axis.z;
}

void magicalMatrix3SetRotationX( cMatrix3* out, float angle )
{
	float c = cosf( angle );
	float s = sinf( angle );

	out->m11 = 1.0f; out->m12 = 0.0f; out->m13 = 0.0f;
	out->m21 = 0.0f; out->m22 =    c; out->m23 =    s;
	out->m31 = 0.0f; out->m32 =  - s; out->m33 =    c;
}

void magicalMatrix3SetRotationY( cMatrix3* out, float angle )
{
	float c = cosf( angle );
	float s = sinf( angle );

	out->m11 =    c; out->m12 = 0.0f; out->m13 =  - s;
	out->m21 = 0.0f; out->m22 = 1.0f; out->m23 = 0.0f;
	out->m31 =    s; out->m32 = 0.0f; out->m33 =    c;
}

void magicalMatrix3SetRotationZ( cMatrix3* out, float angle )
{
	float c = cosf( angle );
	float s = sinf( angle );

	out->m11 =    c;  out->m12 =   s; out->m13 = 0.0f;
	out->m21 =  - s;  out->m22 =   c; out->m23 = 0.0f;
	out->m31 = 0.0f; out->m32 = 0.0f; out->m33 = 1.0f;
}

void magicalMatrix3FromQuaternion( cMatrix3* out, const cQuaternion* q )
{
	out->m11 = 1.0f - 2.0f * ( q->y * q->y + q->z * q->z );
	out->m12 = 2.0f * ( q->x * q->y + q->z * q->w );
	out->m13 = 2.0f * ( q->x * q->z - q->y * q->w );
	out->m21 = 2.0f * ( q->x * q->y - q->z * q->w );
	out->m22 = 1.0f - 2.0f * ( q->x * q->x + q->z * q->z );
	out->m23 = 2.0f * ( q->z * q->y + q->x * q->w );
	out->m31 = 2.0f * ( q->x * q->z + q->y * q->w );
	out->m32 = 2.0f * ( q->y * q->z - q->x * q->w );
	out->m33 = 1.0f - 2.0f * ( q->x * q->x + q->y * q->y );
}

void magicalMatrix3FromAxisAngle( cMatrix3* out, const cAxisAngle* aa )
{
	float s, c;
	magicalSinCos( &s, &c, aa->w );

	float at = 1.0f - c;
	float ax = at * aa->x;
	float ay = at * aa->y;
	float az = at * aa->z;

	out->m11 = ax * aa->x + c;
	out->m12 = ax * aa->y + aa->z * s;
	out->m13 = ax * aa->z - aa->y * s;
	out->m21 = ay * aa->x - aa->z * s;
	out->m22 = ay * aa->y + c;
	out->m23 = ay * aa->z + aa->x * s;
	out->m31 = az * aa->x + aa->y * s;
	out->m32 = az * aa->y - aa->x * s;
	out->m33 = az * aa->z + c;
}

void magicalMatrix3FromEulerAngles( cMatrix3* out, const cEulerAngles* ea )
{
	cEulerAngles dst;
	magicalEulerAnglesLimit( &dst, ea );

	float sp, sr, sy;
	float cp, cr, cy;

	magicalSinCos( &sy, &cy, dst.yaw );
	magicalSinCos( &sp, &cp, dst.pitch );
	magicalSinCos( &sr, &cr, dst.roll );

	out->m11 =   cy * cr + sy * sp * sr;
	out->m12 = - cy * sr + sy * sp * cr;
	out->m13 =   sy * cp;
	out->m21 =   sr * cp;
	out->m22 =   cr * cp;
	out->m23 = - sp;
	out->m31 = - sy * cr + cy * sp * sr;
	out->m32 =   sr * sy + cy * sp * cr;
	out->m33 =   cy * cp;
}

void magicalMatrix3ToQuaternion( cQuaternion* out, const cMatrix3* m )
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

void magicalMatrix3MulScalar( cMatrix3* out, const cMatrix3* m, float a )
{
	out->m11 = m->m11 * a;
	out->m12 = m->m12 * a;
	out->m13 = m->m13 * a;

	out->m21 = m->m21 * a;
	out->m22 = m->m22 * a;
	out->m23 = m->m23 * a;

	out->m31 = m->m31 * a;
	out->m32 = m->m32 * a;
	out->m33 = m->m33 * a;
}

void magicalMatrix3Mul( cMatrix3* out, const cMatrix3* m1, const cMatrix3* m2 )
{
	cMatrix3 dst;

	dst.m11 = m1->m11 * m2->m11 + m1->m12 * m2->m21 + m1->m13 * m2->m31;
	dst.m12 = m1->m11 * m2->m12 + m1->m12 * m2->m22 + m1->m13 * m2->m32;
	dst.m13 = m1->m11 * m2->m13 + m1->m12 * m2->m23 + m1->m13 * m2->m33;
	dst.m21 = m1->m21 * m2->m11 + m1->m22 * m2->m21 + m1->m23 * m2->m31;
	dst.m22 = m1->m21 * m2->m12 + m1->m22 * m2->m22 + m1->m23 * m2->m32;
	dst.m23 = m1->m21 * m2->m13 + m1->m22 * m2->m23 + m1->m23 * m2->m33;
	dst.m31 = m1->m31 * m2->m11 + m1->m32 * m2->m21 + m1->m33 * m2->m31;
	dst.m32 = m1->m31 * m2->m12 + m1->m32 * m2->m22 + m1->m33 * m2->m32;
	dst.m33 = m1->m31 * m2->m13 + m1->m32 * m2->m23 + m1->m33 * m2->m33;

	memcpy( out, &dst, sizeof( cMatrix3 ) );
}

void magicalVector3MulMatrix3( cVector3* out, const cVector3* v, const cMatrix3* m )
{
	cVector3 dst;

	dst.x = v->x * m->m11 + v->y * m->m21 + v->z * m->m31;
	dst.y = v->x * m->m12 + v->y * m->m22 + v->z * m->m32;
	dst.z = v->x * m->m13 + v->y * m->m23 + v->z * m->m33;

	out->x = dst.x;
	out->y = dst.y;
	out->z = dst.z;
}

void magicalMatrix3GetUpVector( cVector3* out, const cMatrix3* m )
{
	out->x = m->m21;
	out->y = m->m22;
	out->z = m->m23;
}

void magicalMatrix3GetDownVector( cVector3* out, const cMatrix3* m )
{
	out->x = - m->m21;
	out->y = - m->m22;
	out->z = - m->m23;
}

void magicalMatrix3GetLeftVector( cVector3* out, const cMatrix3* m )
{
	out->x = - m->m11;
	out->y = - m->m12;
	out->z = - m->m13;
}

void magicalMatrix3GetRightVector( cVector3* out, const cMatrix3* m )
{
	out->x = m->m11;
	out->y = m->m12;
	out->z = m->m13;
}

void magicalMatrix3GetForwardVector( cVector3* out, const cMatrix3* m )
{
	out->x = - m->m31;
	out->y = - m->m32;
	out->z = - m->m33;
}

void magicalMatrix3GetBackVector( cVector3* out, const cMatrix3* m )
{
	out->x = m->m31;
	out->y = m->m32;
	out->z = m->m33;
}

void magicalMatrix3Transpose( cMatrix3* out, const cMatrix3* m )
{
	float t[9];

	t[0] = m->m11; t[1] = m->m21; t[2] = m->m31;
	t[3] = m->m12; t[4] = m->m22; t[5] = m->m32;
	t[6] = m->m13; t[7] = m->m23; t[8] = m->m33;

	out->m11 = t[0]; out->m12 = t[1]; out->m13 = t[2];
	out->m21 = t[2]; out->m22 = t[3]; out->m23 = t[4];
	out->m31 = t[5]; out->m32 = t[6]; out->m33 = t[7];
}

void magicalMatrix3Negate( cMatrix3* out, const cMatrix3* m )
{
	out->m11 = -m->m11; out->m12 = -m->m12; out->m13 = -m->m13;
	out->m21 = -m->m21; out->m22 = -m->m22; out->m23 = -m->m23;
	out->m31 = -m->m31; out->m32 = -m->m32; out->m33 = -m->m33;
}

void magicalMatrix3Inverse( cMatrix3* out, const cMatrix3* m )
{
	float det =
		m->m11 * ( m->m22 * m->m33 - m->m23 * m->m32 ) +
		m->m12 * ( m->m23 * m->m31 - m->m21 * m->m33 ) +
		m->m13 * ( m->m21 * m->m32 - m->m22 * m->m31 );

	cMatrix3 adj;
	
	if( magicalAlmostZero( det, kVectorEpsilon ) )
	{
		if( m != out )
			memcpy( out, m, sizeof( cMatrix3 ) );

		return;
	}
		
	adj.m11 =   m->m22 * m->m33 - m->m23 * m->m32;
	adj.m21 = - m->m21 * m->m33 - m->m23 * m->m31;
	adj.m31 =   m->m21 * m->m32 - m->m22 * m->m31;
	adj.m12 = - m->m12 * m->m33 - m->m13 * m->m32;
	adj.m22 =   m->m11 * m->m33 - m->m13 * m->m31;
	adj.m32 = - m->m11 * m->m32 - m->m12 * m->m31;
	adj.m13 =   m->m12 * m->m23 - m->m13 * m->m22;
	adj.m23 = - m->m11 * m->m23 - m->m13 * m->m21;
	adj.m33 =   m->m11 * m->m22 - m->m12 * m->m21;

	magicalMatrix3MulScalar( out, &adj, 1.0f / det );
}

float magicalMatrix3Determinant( const cMatrix3* m )
{
	return 
		m->m11 * ( m->m22 * m->m33 - m->m23 * m->m32 ) + 
		m->m12 * ( m->m23 * m->m31 - m->m21 * m->m33 ) +
		m->m13 * ( m->m21 * m->m32 - m->m22 * m->m31 );
}