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
#ifndef __C_AXISA_H__
#define __C_AXISA_H__

#include "cUtility.h"

typedef float cAxisA[4];

#include "cVector3.h"
#include "cQuaternion.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalAxisAEquals( const cAxisA aa1, const cAxisA aa2 );
MAGICALAPI_MATH cBool magicalAxisAIsIdentity( const cAxisA aa );
MAGICALAPI_MATH cBool magicalAxisAIsZero( const cAxisA aa );

MAGICALAPI_MATH void magicalAxisAFillScalars( cAxisA out, const float x, const float y, const float z, const float w );
MAGICALAPI_MATH void magicalAxisAFillIdentity( cAxisA out );
MAGICALAPI_MATH void magicalAxisAFillZero( cAxisA out );
MAGICALAPI_MATH void magicalAxisAFill( cAxisA out, const cAxisA aa );

MAGICALAPI_MATH void magicalAxisAFromQuaternion( cAxisA out, const cQuaternion q );

MAGICALAPI_MATH void magicalAxisASetAxis( cAxisA out, const cVector3 axis );
MAGICALAPI_MATH void magicalAxisASetAngle( cAxisA out, const float angle );

MAGICALAPI_MATH void magicalAxisAGetAxis( cVector3 out, const cAxisA aa );
MAGICALAPI_MATH float magicalAxisAGetAngle( const cAxisA aa );

#ifdef __cplusplus
}
#endif

#endif //__C_AXISA_H__