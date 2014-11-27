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
#ifndef __C_PLANE3_H__
#define __C_PLANE3_H__

#include "cMathMacros.h"

typedef float cPlane3[4];

#include "cVec3.h"
#include "cAABB3.h"
#include "cSphere3.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH void magicalPlane3FillScalars( cPlane3 out, const float x, const float y, const float z, const float d );
MAGICALAPI_MATH void magicalPlane3FillNormalAndDistance( cPlane3 out, const cVec3 n, const float d );
MAGICALAPI_MATH void magicalPlane3FillPointAndNormal( cPlane3 out, const cVec3 p, const cVec3 n );
MAGICALAPI_MATH void magicalPlane3FillPoints( cPlane3 out, const cVec3 a, const cVec3 b, const cVec3 c );
MAGICALAPI_MATH void magicalPlane3Fill( cPlane3 out, const cPlane3 p );

MAGICALAPI_MATH void magicalPlane3SetNormal( cPlane3 out, const cVec3 n );
MAGICALAPI_MATH void magicalPlane3GetNormal( cVec3 out, const cPlane3 p );

MAGICALAPI_MATH void magicalPlane3NearestPoint( cVec3 out, const cPlane3 p, const cVec3 point );
MAGICALAPI_MATH void magicalPlane3ProjectPoint( cVec3 out, const cPlane3 p, const cVec3 point );
MAGICALAPI_MATH float magicalPlane3DistanceToPoint( const cPlane3 p, const cVec3 point );

MAGICALAPI_MATH int magicalPlane3ClassifyPoint( const cPlane3 p, const cVec3 point );
MAGICALAPI_MATH int magicalPlane3ClassifyAABB3( const cPlane3 p, const cAABB3 aabb );
MAGICALAPI_MATH int magicalPlane3ClassifySphere3( const cPlane3 p, const cSphere3 sp );

MAGICALAPI_MATH cBool magicalPlane3Intersects( const cPlane3 p1, const cPlane3 p2 );
MAGICALAPI_MATH cBool magicalPlane3IntersectsAABB3( const cPlane3 p, const cAABB3 aabb );
MAGICALAPI_MATH cBool magicalPlane3IntersectsSphere3( const cPlane3 p, const cSphere3 sp );
MAGICALAPI_MATH cBool magicalPlane3IntersectsRay3( const cPlane3 p, const cRay3 r3, const cBool discard_inside );

MAGICALAPI_MATH cBool magicalPlane3IntersectsRay3Distance( float* dist, const cPlane3 p, const cRay3 r3, const cBool discard_inside );

MAGICALAPI_MATH cBool magicalPlane3ContainsPoint( const cPlane3 p, const cVec3 point );

#ifdef __cplusplus
}
#endif

#endif //__C_PLANE3_H__