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
#ifndef __C_MATRIX3_H__
#define __C_MATRIX3_H__

#include "cUtility.h"

#pragma pack( push )
#pragma pack( 4 )
typedef struct cMatrix3 {
	float m11; float m12; float m13;
	float m21; float m22; float m23;
	float m31; float m32; float m33;
} cMatrix3;
#pragma pack( pop )

#include "cVector3.h"
#include "cAxisAngle.h"
#include "cEulerAngles.h"
#include "cQuaternion.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalMatrix3Equals( const cMatrix3* m1, const cMatrix3* m2 );
MAGICALAPI_MATH cBool magicalMatrix3IsIdentity( const cMatrix3* m );
MAGICALAPI_MATH cBool magicalMatrix3IsZero( const cMatrix3* m );

MAGICALAPI_MATH void magicalMatrix3Fill( cMatrix3* out, float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33 );
MAGICALAPI_MATH void magicalMatrix3Copy( cMatrix3* out, const cMatrix3* m );
MAGICALAPI_MATH void magicalMatrix3SetIdentity( cMatrix3* out );
MAGICALAPI_MATH void magicalMatrix3SetZero( cMatrix3* out );

MAGICALAPI_MATH void magicalMatrix3SetLookAt( cMatrix3* out, const cVector3* eye, const cVector3* target, const cVector3* up );

#ifdef __cplusplus
}
#endif

#endif //__C_MATRIX3_H__