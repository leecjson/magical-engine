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

#include "../MathMacros.h"

typedef float cQuaternion[4];

#include "cVec3.h"
#include "cEulerAngles.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBoolean magicalQuaternionEquals( const cQuaternion q1, const cQuaternion q2 );
MAGICALAPI_MATH cBoolean magicalQuaternionIsZero( const cQuaternion q );
MAGICALAPI_MATH cBoolean magicalQuaternionIsIdentity( const cQuaternion q );
MAGICALAPI_MATH cBoolean magicalQuaternionIsNormalize( const cQuaternion q );

MAGICALAPI_MATH void magicalQuaternionFillScalars( cQuaternion out, const float x, const float y, const float z, const float w );
MAGICALAPI_MATH void magicalQuaternionFillZero( cQuaternion out );
MAGICALAPI_MATH void magicalQuaternionFillIdentity( cQuaternion out );
MAGICALAPI_MATH void magicalQuaternionFill( cQuaternion out, const cQuaternion q );

MAGICALAPI_MATH void magicalQuaternionFromAxisAngle( cQuaternion out, const cVec3 axis, const float angle );
MAGICALAPI_MATH void magicalQuaternionFromEulerAngles( cQuaternion out, const cEulerAngles ea );
MAGICALAPI_MATH void magicalQuaternionFromEulerYawPitchRoll( cQuaternion out, const float yaw, const float pitch, const float roll );
MAGICALAPI_MATH float magicalQuaternionToAxisAngle( cVec3 out, const cQuaternion q );

MAGICALAPI_MATH void magicalQuaternionMul( cQuaternion out, const cQuaternion q1, const cQuaternion q2 );

MAGICALAPI_MATH float magicalQuaternionDot( const cQuaternion q1, const cQuaternion q2 );
MAGICALAPI_MATH float magicalQuaternionLength( const cQuaternion q );
MAGICALAPI_MATH float magicalQuaternionLengthSq( const cQuaternion q );

MAGICALAPI_MATH void magicalQuaternionNormalize( cQuaternion out, const cQuaternion q );
MAGICALAPI_MATH void magicalQuaternionConjugate( cQuaternion out, const cQuaternion q );
MAGICALAPI_MATH void magicalQuaternionNegate( cQuaternion out, const cQuaternion q );
MAGICALAPI_MATH cBoolean magicalQuaternionInverse( cQuaternion out, const cQuaternion q );

MAGICALAPI_MATH void magicalQuaternionSlerp( cQuaternion out, const cQuaternion q1, const cQuaternion q2, const float t );

#ifdef __cplusplus
}
#endif

#endif //__C_QUATERNION_H__