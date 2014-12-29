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
#ifndef __C_QUATERNION_H__
#define __C_QUATERNION_H__

#include "cUtility.h"

typedef struct cQuaternion {
	float x;
	float y;
	float z;
	float w;
} cQuaternion;

#include "cVector3.h"
#include "cAxisAngle.h"
#include "cEulerAngles.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalQuaternionEquals( const cQuaternion* q1, const cQuaternion* q2 );
MAGICALAPI_MATH cBool magicalQuaternionIsIdentity( const cQuaternion* q );
MAGICALAPI_MATH cBool magicalQuaternionIsZero( const cQuaternion* q );
MAGICALAPI_MATH cBool magicalQuaternionIsNormalized( const cQuaternion* q );

MAGICALAPI_MATH void magicalQuaternionFill( cQuaternion* out, float x, float y, float z, float w );
MAGICALAPI_MATH void magicalQuaternionCopy( cQuaternion* out, const cQuaternion* q );
MAGICALAPI_MATH void magicalQuaternionSetIdentity( cQuaternion* out );
MAGICALAPI_MATH void magicalQuaternionSetZero( cQuaternion* out );

MAGICALAPI_MATH void magicalQuaternionSetRotationX( cQuaternion* out, float angle );
MAGICALAPI_MATH void magicalQuaternionSetRotationY( cQuaternion* out, float angle );
MAGICALAPI_MATH void magicalQuaternionSetRotationZ( cQuaternion* out, float angle );

MAGICALAPI_MATH void magicalQuaternionFromAxisAngle( cQuaternion* out, const cAxisAngle* aa );
MAGICALAPI_MATH void magicalQuaternionFromEulerAngles( cQuaternion* out, const cEulerAngles* ea );
MAGICALAPI_MATH void magicalQuaternionToAxisAngle( cAxisAngle* out, const cQuaternion* q );
MAGICALAPI_MATH void magicalQuaternionToEulerAngles( cEulerAngles* out, const cQuaternion* q );

MAGICALAPI_MATH void magicalQuaternionAdd( cQuaternion* out, const cQuaternion* q1, const cQuaternion* q2 );
MAGICALAPI_MATH void magicalQuaternionSub( cQuaternion* out, const cQuaternion* q1, const cQuaternion* q2 );
MAGICALAPI_MATH void magicalQuaternionMulScalar( cQuaternion* out, const cQuaternion* q, float a );
MAGICALAPI_MATH void magicalQuaternionMul( cQuaternion* out, const cQuaternion* q1, const cQuaternion* q2 );
MAGICALAPI_MATH void magicalQuaternionMulVector3( cVector3* out, const cQuaternion* q, const cVector3* v );

MAGICALAPI_MATH float magicalQuaternionDot( const cQuaternion* q1, const cQuaternion* q2 );
MAGICALAPI_MATH float magicalQuaternionLength( const cQuaternion* q );
MAGICALAPI_MATH float magicalQuaternionLengthSq( const cQuaternion* q );

MAGICALAPI_MATH void magicalQuaternionNormalize( cQuaternion* out, const cQuaternion* q );
MAGICALAPI_MATH void magicalQuaternionConjugate( cQuaternion* out, const cQuaternion* q );
MAGICALAPI_MATH void magicalQuaternionNegate( cQuaternion* out, const cQuaternion* q );
MAGICALAPI_MATH void magicalQuaternionInverse( cQuaternion* out, const cQuaternion* q );

MAGICALAPI_MATH void magicalQuaternionSlerp( cQuaternion* out, const cQuaternion* q1, const cQuaternion* q2, float t );

#ifdef __cplusplus
}
#endif

#endif //__C_QUATERNION_H__