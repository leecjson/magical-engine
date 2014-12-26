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
#include "cAxisR.h"
#include "cMathMacros.h"

cBool magicalAxisRotationEquals( const cAxisRotation* ar1, const cAxisRotation* ar2 )
{
	return
		magicalAlmostEqual( ar1->x, ar2->x, kEpsilonAxisRotation ) &&
		magicalAlmostEqual( ar1->y, ar2->y, kEpsilonAxisRotation ) &&
		magicalAlmostEqual( ar1->z, ar2->z, kEpsilonAxisRotation ) &&
		magicalAlmostEqual( ar1->w, ar2->w, kEpsilonAxisRotation );
}

cBool magicalAxisRotationIsIdentity( const cAxisRotation* ar )
{
	return
		magicalAlmostZero( ar->x, kEpsilonAxisRotation ) &&
		magicalAlmostZero( ar->y, kEpsilonAxisRotation ) &&
		magicalAlmostEqual( ar->z, 1.0f, kEpsilonAxisRotation ) &&
		magicalAlmostZero( ar->w, kEpsilonAxisRotation );
}

cBool magicalAxisRotationIsZero( const cAxisRotation* ar )
{
	return
		magicalAlmostZero( ar->x, kEpsilonAxisRotation ) &&
		magicalAlmostZero( ar->y, kEpsilonAxisRotation ) &&
		magicalAlmostZero( ar->z, kEpsilonAxisRotation ) &&
		magicalAlmostZero( ar->w, kEpsilonAxisRotation );
}

void magicalAxisRotationFill( cAxisRotation* out, float x, float y, float z, float w )
{
	out->x = x;
	out->y = y;
	out->z = z;
	out->w = w;
}

void magicalAxisRotationCopy( cAxisRotation* out, const cAxisRotation* ar )
{
	out->x = ar->x;
	out->y = ar->y;
	out->z = ar->z;
	out->w = ar->w;
}

void magicalAxisRotationSetIdentity( cAxisRotation* out )
{
	out->x = 0.0f;
	out->y = 0.0f;
	out->z = 1.0f;
	out->w = 0.0f;
}

void magicalAxisRotationSetZero( cAxisRotation* out )
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
void magicalAxisRotationFromQuaternion( cAxisRotation* out, const cQuaternion* q )
{
	float scale = sqrtf( q->x * q->x + q->y * q->y + q->z * q->z );

	if( magicalAlmostZero( scale, kEpsilonQuaternion ) )
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

void magicalAxisRotationToQuaternion( cQuaternion* out, const cAxisRotation* ar )
{
	magicalQuaternionFromAxisRotation( out, ar );
}