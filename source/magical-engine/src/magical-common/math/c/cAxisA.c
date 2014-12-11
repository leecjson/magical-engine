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
#include "cAxisA.h"
#include "cMathMacros.h"

cBool magicalAxisAEquals( const cAxisA aa1, const cAxisA aa2 )
{
	return
		magicalAlmostEqual( aa1 _x, aa2 _x ) &&
		magicalAlmostEqual( aa1 _y, aa2 _y ) &&
		magicalAlmostEqual( aa1 _z, aa2 _z ) &&
		magicalAlmostEqual( aa1 _w, aa2 _w );
}

cBool magicalAxisAIsIdentity( const cAxisA aa )
{
	return
		magicalAlmostZero( aa _x ) &&
		magicalAlmostZero( aa _y ) &&
		magicalAlmostEqual( aa _z, 1.0f ) &&
		magicalAlmostZero( aa _w );
}

cBool magicalAxisAIsZero( const cAxisA aa )
{
	return
		magicalAlmostZero( aa _x ) &&
		magicalAlmostZero( aa _y ) &&
		magicalAlmostZero( aa _z ) &&
		magicalAlmostZero( aa _w );
}

void magicalAxisAFillScalars( cAxisA out, const float x, const float y, const float z, const float w )
{
	out _x = x;
	out _y = y;
	out _z = z;
	out _w = w;
}

void magicalAxisAFillIdentity( cAxisA out )
{
	out _x = 0.0f;
	out _y = 0.0f;
	out _z = 1.0f;
	out _w = 0.0f;
}

void magicalAxisAFillZero( cAxisA out )
{
	out _x = 0.0f;
	out _y = 0.0f;
	out _z = 0.0f;
	out _w = 0.0f;
}

void magicalAxisAFill( cAxisA out, const cAxisA aa )
{
	out _x = aa _x;
	out _y = aa _y;
	out _z = aa _z;
	out _w = aa _w;
}

/*-----------------------------------------------------------------------------*\
 * 将四元数转换为轴一角对旋转 done
 * 
 * out 轴一角对
 * q 源四元数
 *-----------------------------------------------------------------------------*/
void magicalAxisAFromQuaternion( cAxisA out, const cQuaternion q )
{
	float scale = sqrtf( q _x * q _x + q _y * q _y + q _z * q _z );

	if( magicalAlmostZero( scale ) )
	{
		out _x = 0.0f;
		out _y = 0.0f;
		out _z = 1.0f;
		out _w = 0.0f;
	}
	else
	{
		scale = 1.0f / scale;
		out _x = q _x * scale;
		out _y = q _y * scale;
		out _z = q _z * scale;
		out _w = magicalSafeAcos( q _w ) * 2.0f;
	}
}

void magicalAxisASetAxis( cAxisA out, const cVector3 axis )
{
	out _x = axis _x;
	out _y = axis _y;
	out _z = axis _z;
}

void magicalAxisASetAngle( cAxisA out, const float angle )
{
	out _w = angle;
}

void magicalAxisAGetAxis( cVector3 out, const cAxisA aa )
{
	out _x = aa _x;
	out _y = aa _y;
	out _z = aa _z;
}

float magicalAxisAGetAngle( const cAxisA aa )
{
	return aa _w;
}