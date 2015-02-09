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
#ifndef __C_AXIS_ANGLE_H__
#define __C_AXIS_ANGLE_H__

#include "cUtility.h"

#pragma pack( push )
#pragma pack( 4 )
typedef struct cAxisAngle {
	float x;
	float y;
	float z;
	float w;
} cAxisAngle;
#pragma pack( pop )

#include "cMatrix3.h"
#include "cQuaternion.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalAxisAngleEquals( const cAxisAngle* aa1, const cAxisAngle* aa2 );
MAGICALAPI_MATH cBool magicalAxisAngleIsIdentity( const cAxisAngle* aa );
MAGICALAPI_MATH cBool magicalAxisAngleIsZero( const cAxisAngle* aa );

MAGICALAPI_MATH void magicalAxisAngleFill( cAxisAngle* out, float x, float y, float z, float w );
MAGICALAPI_MATH void magicalAxisAngleCopy( cAxisAngle* out, const cAxisAngle* aa );
MAGICALAPI_MATH void magicalAxisAngleSetIdentity( cAxisAngle* out );
MAGICALAPI_MATH void magicalAxisAngleSetZero( cAxisAngle* out );

MAGICALAPI_MATH void magicalAxisAngleFromQuaternion( cAxisAngle* out, const cQuaternion* q );
MAGICALAPI_MATH void magicalAxisAngleToQuaternion( cQuaternion* out, const cAxisAngle* aa );
MAGICALAPI_MATH void magicalAxisAngleToMatrix3( cMatrix3* out, const cAxisAngle* aa );

#ifdef __cplusplus
}
#endif

#endif //__C_AXIS_ANGLE_H__