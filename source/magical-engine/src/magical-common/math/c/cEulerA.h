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
#ifndef __C_EULERA_H__
#define __C_EULERA_H__

#include "cUtility.h"

typedef float cEulerA[3];

#include "cMatrix4.h"
#include "cQuaternion.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalEulerAEqulas( const cEulerA ea1, const cEulerA ea2 );
MAGICALAPI_MATH cBool magicalEulerAIsIdentity( const cEulerA ea );

MAGICALAPI_MATH void magicalEulerAFillYawPitchRoll( cEulerA out, const float yaw, const float pitch, const float roll );
MAGICALAPI_MATH void magicalEulerAFillIdentity( cEulerA out );
MAGICALAPI_MATH void magicalEulerAFill( cEulerA out, const cEulerA ea );

MAGICALAPI_MATH void magicalEulerAAdd( cEulerA out, const cEulerA ea1, const cEulerA ea2 );
MAGICALAPI_MATH void magicalEulerASub( cEulerA out, const cEulerA ea1, const cEulerA ea2 );
MAGICALAPI_MATH void magicalEulerAMul( cEulerA out, const cEulerA ea1, const cEulerA ea2 );
MAGICALAPI_MATH void magicalEulerAMulScalar( cEulerA out, const cEulerA ea, const float a );

MAGICALAPI_MATH void magicalEulerAFromQuaternion( cEulerA out, const cQuaternion q );
MAGICALAPI_MATH void magicalEulerAFromMatrix4( cEulerA out, const cMatrix4 m );

MAGICALAPI_MATH void magicalEulerAToQuaternion( cQuaternion out, const cEulerA ea );
MAGICALAPI_MATH void magicalEulerAToMatrix4( cMatrix4 out, const cEulerA ea );

MAGICALAPI_MATH void magicalEulerACorrects( cEulerA out, const cEulerA ea );

#ifdef __cplusplus
}
#endif

#endif //__C_EULERA_H__