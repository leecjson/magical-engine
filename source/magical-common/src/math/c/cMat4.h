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
#ifndef __C_MAT4_H__
#define __C_MAT4_H__

#include "../MathMacros.h"

typedef float cMat4[16];

#include "cVec3.h"
#include "cVec4.h"
#include "cQuaternion.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBoolean magicalMat4Equals( const cMat4 m1, const cMat4 m2 );
MAGICALAPI_MATH cBoolean magicalMat4IsIdentity( const cMat4 m );

MAGICALAPI_MATH void magicalMat4FillScalars( cMat4 out,
	const float rm11, const float rm12, const float rm13, const float rm14,
	const float rm21, const float rm22, const float rm23, const float rm24,
	const float rm31, const float rm32, const float rm33, const float rm34,
	const float rm41, const float rm42, const float rm43, const float rm44 );

MAGICALAPI_MATH void magicalMat4FillVector( cMat4 out, const float* m );
MAGICALAPI_MATH void magicalMat4FillIdentity( cMat4 out );
MAGICALAPI_MATH void magicalMat4Fill( cMat4 out, const cMat4 m );

MAGICALAPI_MATH void magicalMat4MulScalar( cMat4 out, const cMat4 m, const float a );
MAGICALAPI_MATH void magicalMat4Mul( cMat4 out, const cMat4 m1, const cMat4 m2 );
MAGICALAPI_MATH void magicalMat4Mul3x3AndTranslation( cMat4 out, const cMat4 m1, const cMat4 m2 );
MAGICALAPI_MATH void magicalVec3MulMat4( cVec3 out, const cVec3 v, const cMat4 m );
MAGICALAPI_MATH void magicalVec4MulMat4( cVec4 out, const cVec4 v, const cMat4 m );

MAGICALAPI_MATH void magicalMat4FillTranslation( cMat4 out, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalMat4FillTranslationVector( cMat4 out, const cVec3 t );
MAGICALAPI_MATH void magicalMat4FillScaling( cMat4 out, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalMat4FillScalingVector( cMat4 out, const cVec3 s );
MAGICALAPI_MATH void magicalMat4FillRotationX( cMat4 out, const float angle );
MAGICALAPI_MATH void magicalMat4FillRotationY( cMat4 out, const float angle );
MAGICALAPI_MATH void magicalMat4FillRotationZ( cMat4 out, const float angle );
MAGICALAPI_MATH void magicalMat4FillRotationYawPitchRoll( cMat4 out, const float yaw, const float pitch, const float roll );
MAGICALAPI_MATH void magicalMat4FillRotationQuaternion( cMat4 out, const cQuaternion r );
MAGICALAPI_MATH void magicalMat4FillRotationAxisAngle( cMat4 out, const cVec3 axis, const float angle );

MAGICALAPI_MATH void magicalMat4FillLookAt( cMat4 out, const cVec3 eye, const cVec3 target, const cVec3 up );
MAGICALAPI_MATH void magicalMat4FillPerspective( cMat4 out, const float fov, const float aspect, const float znear, const float zfar );
MAGICALAPI_MATH void magicalMat4FillOrthographic( cMat4 out, const float left, const float right, const float bottom, const float top, const float near, const float far );

MAGICALAPI_MATH void magicalMat4Translate( cMat4 out, const cMat4 m, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalMat4TranslateVector( cMat4 out, const cMat4 m, const cVec3 t );
MAGICALAPI_MATH void magicalMat4Scale( cMat4 out, const cMat4 m, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalMat4ScaleVector( cMat4 out, const cMat4 m, const cVec3 s );
MAGICALAPI_MATH void magicalMat4RotateX( cMat4 out, const cMat4 m, const float angle );
MAGICALAPI_MATH void magicalMat4RotateY( cMat4 out, const cMat4 m, const float angle );
MAGICALAPI_MATH void magicalMat4RotateZ( cMat4 out, const cMat4 m, const float angle );
MAGICALAPI_MATH void magicalMat4RotateYawPitchRoll( cMat4 out, const cMat4 m, const float yaw, const float pitch, const float roll );
MAGICALAPI_MATH void magicalMat4RotateQuaternion( cMat4 out, const cMat4 m, const cQuaternion r );
MAGICALAPI_MATH void magicalMat4RotateAxisAngle( cMat4 out, const cMat4 m, const cVec3 axis, const float angle );

MAGICALAPI_MATH float magicalMat4Determinant( const cMat4 m );
MAGICALAPI_MATH cBoolean magicalMat4Inverse( cMat4 out, const cMat4 m );
MAGICALAPI_MATH void magicalMat4Transpose( cMat4 out, const cMat4 m );
MAGICALAPI_MATH void magicalMat4Negate( cMat4 out, const cMat4 m );

MAGICALAPI_MATH void magicalMat4GetUpVector( cVec3 out, const cMat4 m );
MAGICALAPI_MATH void magicalMat4GetDownVector( cVec3 out, const cMat4 m );
MAGICALAPI_MATH void magicalMat4GetLeftVector( cVec3 out, const cMat4 m );
MAGICALAPI_MATH void magicalMat4GetRightVector( cVec3 out, const cMat4 m );
MAGICALAPI_MATH void magicalMat4GetForwardVector( cVec3 out, const cMat4 m );
MAGICALAPI_MATH void magicalMat4GetBackVector( cVec3 out, const cMat4 m );

MAGICALAPI_MATH void magicalMat4SetTranslation( cMat4 out, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalMat4GetTranslation( cVec3 out, const cMat4 m );


#ifdef __cplusplus
}
#endif

#endif //__C_MAT4_H__