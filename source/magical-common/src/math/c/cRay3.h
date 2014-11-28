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
#ifndef __C_RAY3_H__
#define __C_RAY3_H__

#include "cUtility.h"

typedef float cRay3[6];

#include "cVec3.h"
#include "cAABB3.h"
#include "cSphere3.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH void magicalRay3FillScalars( cRay3 out, const float ox, const float oy, const float oz, const float dx, const float dy, const float dz );
MAGICALAPI_MATH void magicalRay3FillOriginToEnd( cRay3 out, const cVec3 origin, const cVec3 end );
MAGICALAPI_MATH void magicalRay3FillOriginAndDirection( cRay3 out, const cVec3 origin, const cVec3 direction );
MAGICALAPI_MATH void magicalRay3Fill( cRay3 out, const cRay3 r3 );

MAGICALAPI_MATH void magicalRay3GetOrigin( cVec3 out, const cRay3 r3 );
MAGICALAPI_MATH void magicalRay3GetDirection( cVec3 out, const cRay3 r3 );
MAGICALAPI_MATH void magicalRay3SetOrigin( cRay3 out, const cVec3 origin );
MAGICALAPI_MATH void magicalRay3SetDirection( cRay3 out, const cVec3 direction );

MAGICALAPI_MATH void magicalRay3DirectionNormalize( cRay3 out, const cRay3 r3 );

MAGICALAPI_MATH cBool magicalRay3IntersectsPlane3( const cRay3 r3, const cPlane3 p, const cBool discard_inside );
MAGICALAPI_MATH cBool magicalRay3IntersectsAABB3( const cRay3 r3, const cAABB3 aabb, const cBool discard_inside );
MAGICALAPI_MATH cBool magicalRay3IntersectsSphere3( const cRay3 r3, const cSphere3 sp, const cBool discard_inside );

MAGICALAPI_MATH cBool magicalRay3IntersectsPlane3Distance( float* dist, const cRay3 r3, const cPlane3 p, const cBool discard_inside );
MAGICALAPI_MATH cBool magicalRay3IntersectsAABB3Distance( float* dist, const cRay3 r3, const cAABB3 aabb, const cBool discard_inside );
MAGICALAPI_MATH cBool magicalRay3IntersectsSphere3Distance( float* dist, const cRay3 r3, const cSphere3 sp, const cBool discard_inside );

#ifdef __cplusplus
}
#endif

#endif //__C_RAY3_H__