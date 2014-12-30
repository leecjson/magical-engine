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

#include "cUtility.h"

typedef struct cEulerAngles {
	float yaw;
	float pitch;
	float roll;
} cEulerAngles;

#include "cQuaternion.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalEulerAnglesEqulas( const cEulerAngles* ea1, const cEulerAngles* ea2 );
MAGICALAPI_MATH cBool magicalEulerAnglesIsZero( const cEulerAngles* ea );

MAGICALAPI_MATH void magicalEulerAnglesFill( cEulerAngles* out, float yaw, float pitch, float roll );
MAGICALAPI_MATH void magicalEulerAnglesCopy( cEulerAngles* out, const cEulerAngles* ea );
MAGICALAPI_MATH void magicalEulerAnglesSetZero( cEulerAngles* out );
MAGICALAPI_MATH void magicalEulerAnglesSetLookAt( cEulerAngles* out, const cVector3* eye, const cVector3* target, const cVector3* up );

MAGICALAPI_MATH void magicalEulerAnglesFromQuaternion( cEulerAngles* out, const cQuaternion* q );
MAGICALAPI_MATH void magicalEulerAnglesToQuaternion( cQuaternion* out, const cEulerAngles* ea );

MAGICALAPI_MATH void magicalEulerAnglesAdd( cEulerAngles* out, const cEulerAngles* ea1, const cEulerAngles* ea2 );
MAGICALAPI_MATH void magicalEulerAnglesSub( cEulerAngles* out, const cEulerAngles* ea1, const cEulerAngles* ea2 );
MAGICALAPI_MATH void magicalEulerAnglesMul( cEulerAngles* out, const cEulerAngles* ea1, const cEulerAngles* ea2 );
MAGICALAPI_MATH void magicalEulerAnglesMulScalar( cEulerAngles* out, const cEulerAngles* ea, float a );

MAGICALAPI_MATH void magicalEulerAnglesLimit( cEulerAngles* out, const cEulerAngles* ea );

#ifdef __cplusplus
}
#endif

#endif //__C_EULER_ANGLES_H__