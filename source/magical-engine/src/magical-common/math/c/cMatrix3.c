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
#include "cMatrix3.h"
#include <memory.h>

static const float IDENTITY[] =
{
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};

cBool magicalMatrix3Equals( const cMatrix3* m1, const cMatrix3* m2 )
{
	const float* v1 = (const float*) m1;
	const float* v2 = (const float*) m2;

	for( int i = 0; i < 9; ++i )
	{
		if( magicalAlmostEqual( v1[i], v2[i], kVectorEpsilon ) == cFalse )
		{
			return cFalse;
		}
	}
	return cTrue;
}

cBool magicalMatrix3IsIdentity( const cMatrix3* m )
{
	const float* v = (const float*) m;

	for( int i = 0; i < 9; ++i )
	{
		if( magicalAlmostEqual( v[i], IDENTITY[i], kVectorEpsilon ) == cFalse )
		{
			return cFalse;
		}
	}
	return cTrue;
}

cBool magicalMatrix3IsZero( const cMatrix3* m )
{
	const float* v = (const float*) m;

	for( int i = 0; i < 9; ++i )
	{
		if( magicalAlmostZero( v[i], kVectorEpsilon ) == cFalse )
		{
			return cFalse;
		}
	}
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
	memcpy( out, m, sizeof( cMatrix3 ) );
}

void magicalMatrix3SetIdentity( cMatrix3* out )
{
	memcpy( out, IDENTITY, sizeof( cMatrix3 ) );
}

void magicalMatrix3SetZero( cMatrix3* out )
{
	memset( out, 0, sizeof( cMatrix3 ) );
}

void magicalMatrix3SetLookAt( cMatrix3* out, const cVector3* eye, const cVector3* target, const cVector3* up )
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

	out->m21 = x_axis.y;
	out->m22 = y_axis.y;
	out->m23 = z_axis.y;

	out->m31 = x_axis.z;
	out->m32 = y_axis.z;
	out->m33 = z_axis.z;
}