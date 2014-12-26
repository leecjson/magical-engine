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
#ifndef __C_AXISR_H__
#define __C_AXISR_H__

#include "cUtility.h"

#define kEpsilonAxisRotation 1e-005f

typedef struct cAxisRotation {
	float x;
	float y;
	float z;
	float w;
} cAxisRotation;

#include "cVector3.h"
#include "cQuaternion.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalAxisRotationEquals( const cAxisRotation* ar1, const cAxisRotation* ar2 );
MAGICALAPI_MATH cBool magicalAxisRotationIsIdentity( const cAxisRotation* ar );
MAGICALAPI_MATH cBool magicalAxisRotationIsZero( const cAxisRotation* ar );

MAGICALAPI_MATH void magicalAxisRotationFill( cAxisRotation* out, float x, float y, float z, float w );
MAGICALAPI_MATH void magicalAxisRotationCopy( cAxisRotation* out, const cAxisRotation* ar );
MAGICALAPI_MATH void magicalAxisRotationSetIdentity( cAxisRotation* out );
MAGICALAPI_MATH void magicalAxisRotationSetZero( cAxisRotation* out );

MAGICALAPI_MATH void magicalAxisRotationFromQuaternion( cAxisRotation* out, const cQuaternion* q );
MAGICALAPI_MATH void magicalAxisRotationToQuaternion( cQuaternion* out, const cAxisRotation* ar );

#ifdef __cplusplus
}
#endif

#endif //__C_AXISR_H__