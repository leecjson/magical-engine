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
#include "cAxisAngle.h"

cBool magicalAxisAngleEquals( const cAxisAngle* aa1, const cAxisAngle* aa2 )
{
	return
		magicalAlmostEqual( aa1->x, aa2->x, kVectorEpsilon ) &&
		magicalAlmostEqual( aa1->y, aa2->y, kVectorEpsilon ) &&
		magicalAlmostEqual( aa1->z, aa2->z, kVectorEpsilon ) &&
		magicalAlmostEqual( aa1->w, aa2->w, kRadianEpsilon );
}

cBool magicalAxisAngleIsIdentity( const cAxisAngle* aa )
{
	return
		magicalAlmostZero( aa->x, kVectorEpsilon ) &&
		magicalAlmostZero( aa->y, kVectorEpsilon ) &&
		magicalAlmostEqual( aa->z, 1.0f, kVectorEpsilon ) &&
		magicalAlmostZero( aa->w, kRadianEpsilon );
}

cBool magicalAxisAngleIsZero( const cAxisAngle* aa )
{
	return
		magicalAlmostZero( aa->x, kVectorEpsilon ) &&
		magicalAlmostZero( aa->y, kVectorEpsilon ) &&
		magicalAlmostZero( aa->z, kVectorEpsilon ) &&
		magicalAlmostZero( aa->w, kRadianEpsilon );
}

void magicalAxisAngleFill( cAxisAngle* out, float x, float y, float z, float w )
{
	out->x = x;
	out->y = y;
	out->z = z;
	out->w = w;
}

void magicalAxisAngleCopy( cAxisAngle* out, const cAxisAngle* aa )
{
	out->x = aa->x;
	out->y = aa->y;
	out->z = aa->z;
	out->w = aa->w;
}

void magicalAxisAngleSetIdentity( cAxisAngle* out )
{
	out->x = 0.0f;
	out->y = 0.0f;
	out->z = 1.0f;
	out->w = 0.0f;
}

void magicalAxisAngleSetZero( cAxisAngle* out )
{
	out->x = 0.0f;
	out->y = 0.0f;
	out->z = 0.0f;
	out->w = 0.0f;
}

/*-----------------------------------------------------------------------------*\
 * 将四元数转换为轴一角对旋转 done
 * 
 * out 轴一角对
 * q 源四元数
 *-----------------------------------------------------------------------------*/
void magicalAxisAngleFromQuaternion( cAxisAngle* out, const cQuaternion* q )
{
	float scale = sqrtf( q->x * q->x + q->y * q->y + q->z * q->z );

	if( magicalAlmostZero( scale, kVectorEpsilon ) )
	{
		out->x = 0.0f;
		out->y = 0.0f;
		out->z = 1.0f;
		out->w = 0.0f;
	}
	else
	{
		scale = 1.0f / scale;
		out->x = q->x * scale;
		out->y = q->y * scale;
		out->z = q->z * scale;
		out->w = magicalSafeAcos( q->w ) * 2.0f;
	}
}

void magicalAxisAngleToQuaternion( cQuaternion* out, const cAxisAngle* aa )
{
	magicalQuaternionFromAxisAngle( out, aa );
}

void magicalAxisAngleToMatrix3( cMatrix3* out, const cAxisAngle* aa )
{
	magicalMatrix3RotationAxisAngle( out, aa );
}