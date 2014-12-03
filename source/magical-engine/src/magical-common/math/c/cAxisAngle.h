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
#ifndef __C_AXIS_ANGLE_H__
#define __C_AXIS_ANGLE_H__

#include "cUtility.h"

typedef float cAxisAngle[4];

#include "cVec3.h"
#include "cQuaternion.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalAxisAngleEquals( const cAxisAngle aa1, const cAxisAngle aa2 );
MAGICALAPI_MATH cBool magicalAxisAngleIsIdentity( const cAxisAngle aa );

MAGICALAPI_MATH void magicalAxisAngleFillScalars( cAxisAngle out, const float x, const float y, const float z, const float w );
MAGICALAPI_MATH void magicalAxisAngleFillAxisAngleScalars( cAxisAngle out, const cVec3 axis, const float angle );
MAGICALAPI_MATH void magicalAxisAngleFillIdentity( cAxisAngle out );
MAGICALAPI_MATH void magicalAxisAngleFill( cAxisAngle out, const cAxisAngle aa );

MAGICALAPI_MATH void magicalAxisAngleFromQuaternion( cAxisAngle out, const cQuaternion q );

MAGICALAPI_MATH void magicalAxisAngleSetAxis( cAxisAngle out, const cVec3 axis );
MAGICALAPI_MATH void magicalAxisAngleSetAngle( cAxisAngle out, const float angle );

MAGICALAPI_MATH void magicalAxisAngleGetAxis( cVec3 out, const cAxisAngle aa );
MAGICALAPI_MATH float magicalAxisAngleGetAngle( const cAxisAngle aa );

#ifdef __cplusplus
}
#endif

#endif //__C_AXIS_ANGLE_H__