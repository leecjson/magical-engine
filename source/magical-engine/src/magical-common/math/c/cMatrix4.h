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

typedef float cMatrix4[16];

#include "cVector3.h"
#include "cVector4.h"
#include "cAxisAngle.h"
#include "cQuaternion.h"
#include "cEulerAngles.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH void magicalMatrix4FillScalars( cMatrix4 out,
const float rm11, const float rm12, const float rm13, const float rm14,
const float rm21, const float rm22, const float rm23, const float rm24,
const float rm31, const float rm32, const float rm33, const float rm34,
const float rm41, const float rm42, const float rm43, const float rm44 );

MAGICALAPI_MATH cBool magicalMatrix4Equals( const cMatrix4 m1, const cMatrix4 m2 );
MAGICALAPI_MATH cBool magicalMatrix4IsIdentity( const cMatrix4 m );
MAGICALAPI_MATH cBool magicalMatrix4IsZero( const cMatrix4 m );

MAGICALAPI_MATH void magicalMatrix4FillIdentity( cMatrix4 out );
MAGICALAPI_MATH void magicalMatrix4FillZero( cMatrix4 out );
MAGICALAPI_MATH void magicalMatrix4Fill( cMatrix4 out, const cMatrix4 m );

MAGICALAPI_MATH void magicalMatrix4MulScalar( cMatrix4 out, const cMatrix4 m, const float a );
MAGICALAPI_MATH void magicalMatrix4Mul( cMatrix4 out, const cMatrix4 m1, const cMatrix4 m2 );
MAGICALAPI_MATH void magicalMatrix4Mul3x3AndTranslation( cMatrix4 out, const cMatrix4 m1, const cMatrix4 m2 );
MAGICALAPI_MATH void magicalVector3MulMatrix4( cVector3 out, const cVector3 v, const cMatrix4 m );
MAGICALAPI_MATH void magicalVector4MulMatrix4( cVector4 out, const cVector4 v, const cMatrix4 m );

MAGICALAPI_MATH void magicalMatrix4FillTranslation( cMatrix4 out, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalMatrix4FillTranslationVector( cMatrix4 out, const cVector3 t );
MAGICALAPI_MATH void magicalMatrix4FillScale( cMatrix4 out, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalMatrix4FillScaleVector( cMatrix4 out, const cVector3 s );
MAGICALAPI_MATH void magicalMatrix4FillRotationX( cMatrix4 out, const float angle );
MAGICALAPI_MATH void magicalMatrix4FillRotationY( cMatrix4 out, const float angle );
MAGICALAPI_MATH void magicalMatrix4FillRotationZ( cMatrix4 out, const float angle );
MAGICALAPI_MATH void magicalMatrix4FillRotationEulerAngles( cMatrix4 out, const cEulerAngles ea );
MAGICALAPI_MATH void magicalMatrix4FillRotationEulerYawPitchRoll( cMatrix4 out, const float yaw, const float pitch, const float roll );
MAGICALAPI_MATH void magicalMatrix4FillRotationQuaternion( cMatrix4 out, const cQuaternion q );
MAGICALAPI_MATH void magicalMatrix4FillRotationAxisAngle( cMatrix4 out, const cAxisAngle aa );
MAGICALAPI_MATH void magicalMatrix4FillRotationAxisAngleScalars( cMatrix4 out, const cVector3 axis, const float angle );

MAGICALAPI_MATH void magicalMatrix4FillLookAt( cMatrix4 out, const cVector3 eye, const cVector3 target, const cVector3 up );
MAGICALAPI_MATH void magicalMatrix4FillPerspective( cMatrix4 out, const float fov, const float aspect, const float znear, const float zfar );
MAGICALAPI_MATH void magicalMatrix4FillOrthographic( cMatrix4 out, const float left, const float right, const float bottom, const float top, const float near, const float far );

MAGICALAPI_MATH void magicalMatrix4Translate( cMatrix4 out, const cMatrix4 m, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalMatrix4TranslateVector( cMatrix4 out, const cMatrix4 m, const cVector3 t );
MAGICALAPI_MATH void magicalMatrix4Scale( cMatrix4 out, const cMatrix4 m, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalMatrix4ScaleVector( cMatrix4 out, const cMatrix4 m, const cVector3 s );
MAGICALAPI_MATH void magicalMatrix4RotateX( cMatrix4 out, const cMatrix4 m, const float angle );
MAGICALAPI_MATH void magicalMatrix4RotateY( cMatrix4 out, const cMatrix4 m, const float angle );
MAGICALAPI_MATH void magicalMatrix4RotateZ( cMatrix4 out, const cMatrix4 m, const float angle );
MAGICALAPI_MATH void magicalMatrix4RotateEulerAngles( cMatrix4 out, const cMatrix4 m, const cEulerAngles ea );
MAGICALAPI_MATH void magicalMatrix4RotateEulerYawPitchRoll( cMatrix4 out, const cMatrix4 m, const float yaw, const float pitch, const float roll );
MAGICALAPI_MATH void magicalMatrix4RotateQuaternion( cMatrix4 out, const cMatrix4 m, const cQuaternion q );
MAGICALAPI_MATH void magicalMatrix4RotateAxisAngle( cMatrix4 out, const cMatrix4 m, const cAxisAngle aa );
MAGICALAPI_MATH void magicalMatrix4RotateAxisAngleScalars( cMatrix4 out, const cMatrix4 m, const cVector3 axis, const float angle );

MAGICALAPI_MATH float magicalMatrix4Determinant( const cMatrix4 m );
MAGICALAPI_MATH cBool magicalMatrix4Inverse( cMatrix4 out, const cMatrix4 m );
MAGICALAPI_MATH void magicalMatrix4Transpose( cMatrix4 out, const cMatrix4 m );
MAGICALAPI_MATH void magicalMatrix4Negate( cMatrix4 out, const cMatrix4 m );

MAGICALAPI_MATH void magicalMatrix4GetUpVector( cVector3 out, const cMatrix4 m );
MAGICALAPI_MATH void magicalMatrix4GetDownVector( cVector3 out, const cMatrix4 m );
MAGICALAPI_MATH void magicalMatrix4GetLeftVector( cVector3 out, const cMatrix4 m );
MAGICALAPI_MATH void magicalMatrix4GetRightVector( cVector3 out, const cMatrix4 m );
MAGICALAPI_MATH void magicalMatrix4GetForwardVector( cVector3 out, const cMatrix4 m );
MAGICALAPI_MATH void magicalMatrix4GetBackVector( cVector3 out, const cMatrix4 m );

MAGICALAPI_MATH void magicalMatrix4SetTranslation( cMatrix4 out, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalMatrix4GetTranslation( cVector3 out, const cMatrix4 m );
MAGICALAPI_MATH void magicalMatrix4GetScale( cVector3 out, const cMatrix4 m );
MAGICALAPI_MATH void magicalMatrix4GetRotationQuaternion( cQuaternion out, const cMatrix4 m );

MAGICALAPI_MATH cBool magicalMatrix4Decompose( cVector3 out_translation, cVector3 out_scaling, cQuaternion out_rotation, const cMatrix4 m );

#ifdef __cplusplus
}
#endif

#endif //__C_MATRIX4_H__