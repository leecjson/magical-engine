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
#ifndef __C_MATRIX4_H__
#define __C_MATRIX4_H__

#include "cUtility.h"

#pragma pack( push )
#pragma pack( 4 )
typedef struct cMatrix4 {
	float m11; float m12; float m13; float m14;
	float m21; float m22; float m23; float m24;
	float m31; float m32; float m33; float m34;
	float m41; float m42; float m43; float m44;
} cMatrix4;
#pragma pack( pop )

#include "cVector3.h"
#include "cVector4.h"
#include "cMatrix3.h"
#include "cAxisAngle.h"
#include "cEulerAngles.h"
#include "cQuaternion.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalMatrix4Equals( const cMatrix4* m1, const cMatrix4* m2 );
MAGICALAPI_MATH cBool magicalMatrix4IsIdentity( const cMatrix4* m );
MAGICALAPI_MATH cBool magicalMatrix4IsZero( const cMatrix4* m );

MAGICALAPI_MATH void magicalMatrix4Fill( cMatrix4* out, float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44 );
MAGICALAPI_MATH void magicalMatrix4Copy( cMatrix4* out, const cMatrix4* m );
MAGICALAPI_MATH void magicalMatrix4SetIdentity( cMatrix4* out );
MAGICALAPI_MATH void magicalMatrix4SetZero( cMatrix4* out );
MAGICALAPI_MATH void magicalMatrix4SetLookAt( cMatrix4* out, const cVector3* eye, const cVector3* target, const cVector3* up );
MAGICALAPI_MATH void magicalMatrix4SetPerspective( cMatrix4* out, float fov, float aspect, float znear, float zfar );
MAGICALAPI_MATH void magicalMatrix4SetOrth( cMatrix4* out, float left, float right, float bottom, float top, float znear, float zfar );
MAGICALAPI_MATH void magicalMatrix4SetTRS( cMatrix4* out, const cVector3* t, const cQuaternion* r, const cVector3* s );

MAGICALAPI_MATH void magicalMatrix4Translation( cMatrix4* out, const cVector3* t );
MAGICALAPI_MATH void magicalMatrix4TranslationScalars( cMatrix4* out, float x, float y, float z );
MAGICALAPI_MATH void magicalMatrix4Scale( cMatrix4* out, const cVector3* s );
MAGICALAPI_MATH void magicalMatrix4ScaleScalars( cMatrix4* out, float x, float y, float z );
MAGICALAPI_MATH void magicalMatrix4RotationX( cMatrix4* out, float angle );
MAGICALAPI_MATH void magicalMatrix4RotationY( cMatrix4* out, float angle );
MAGICALAPI_MATH void magicalMatrix4RotationZ( cMatrix4* out, float angle );
MAGICALAPI_MATH void magicalMatrix4RotationQuaternion( cMatrix4* out, const cQuaternion* q );
MAGICALAPI_MATH void magicalMatrix4RotationAxisAngle( cMatrix4* out, const cAxisAngle* aa );
MAGICALAPI_MATH void magicalMatrix4RotationEulerAngles( cMatrix4* out, const cEulerAngles* ea );

MAGICALAPI_MATH void magicalMatrix4MulScalar( cMatrix4* out, const cMatrix4* m, float a );
MAGICALAPI_MATH void magicalMatrix4Mul( cMatrix4* out, const cMatrix4* m1, const cMatrix4* m2 );
MAGICALAPI_MATH void magicalMatrix4Mul3x3AndTranslation( cMatrix4* out, const cMatrix4* m1, const cMatrix4* m2 );
MAGICALAPI_MATH void magicalVector3MulMatrix4( cVector3* out, const cVector3* v, const cMatrix4* m );
MAGICALAPI_MATH void magicalVector4MulMatrix4( cVector4* out, const cVector4* v, const cMatrix4* m );

MAGICALAPI_MATH void magicalMatrix4GetUpVector( cVector3* out, const cMatrix4* m );
MAGICALAPI_MATH void magicalMatrix4GetDownVector( cVector3* out, const cMatrix4* m );
MAGICALAPI_MATH void magicalMatrix4GetLeftVector( cVector3* out, const cMatrix4* m );
MAGICALAPI_MATH void magicalMatrix4GetRightVector( cVector3* out, const cMatrix4* m );
MAGICALAPI_MATH void magicalMatrix4GetForwardVector( cVector3* out, const cMatrix4* m );
MAGICALAPI_MATH void magicalMatrix4GetBackVector( cVector3* out, const cMatrix4* m );

MAGICALAPI_MATH void magicalMatrix4Transpose( cMatrix4* out, const cMatrix4* m );
MAGICALAPI_MATH void magicalMatrix4Negate( cMatrix4* out, const cMatrix4* m );
MAGICALAPI_MATH void magicalMatrix4Inverse( cMatrix4* out, const cMatrix4* m );
MAGICALAPI_MATH float magicalMatrix4Determinant( const cMatrix4* m );

#ifdef __cplusplus
}
#endif

#endif //__C_MATRIX4_H__