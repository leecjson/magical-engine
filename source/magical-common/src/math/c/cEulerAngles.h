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
#ifndef __C_EULER_ANGLES_H__
#define __C_EULER_ANGLES_H__

#include "cMathMacros.h"

typedef float cEulerAngles[3];

#include "cQuaternion.h"
#include "cMat4.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH void magicalEulerAnglesFillYawPitchRoll( cEulerAngles out, const float yaw, const float pitch, const float roll );
MAGICALAPI_MATH void magicalEulerAnglesFillIdentity( cEulerAngles out );
MAGICALAPI_MATH void magicalEulerAnglesFill( cEulerAngles out, const cEulerAngles ea );

MAGICALAPI_MATH void magicalEulerAnglesFillFromQuaternion( cEulerAngles out, const cQuaternion q );
MAGICALAPI_MATH void magicalEulerAnglesFillFromRotationMat4( cEulerAngles out, const cMat4 m );

MAGICALAPI_MATH void magicalEulerAnglesCorrects( cEulerAngles out, const cEulerAngles ea );

#ifdef __cplusplus
}
#endif

#endif //__C_EULER_ANGLES_H__