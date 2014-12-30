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

#include "cUtility.h"

typedef struct cPlane3 {
	float x;
	float y;
	float z;
	float d;
} cPlane3;

#include "cAABB3.h"
#include "cVector3.h"
#include "cSphere3.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalPlane3Equals( const cPlane3* p1, const cPlane3* p2 );
MAGICALAPI_MATH cBool magicalPlane3IsZero( const cPlane3* p );

MAGICALAPI_MATH void magicalPlane3SetScalars( cPlane3* out, float x, float y, float z, float d );
MAGICALAPI_MATH void magicalPlane3SetNormalAndDistance( cPlane3* out, const cVector3* n, float d );
MAGICALAPI_MATH void magicalPlane3SetNormalAndPoint( cPlane3* out, const cVector3* n, const cVector3* p );
MAGICALAPI_MATH void magicalPlane3SetPoints( cPlane3* out, const cVector3* a, const cVector3* b, const cVector3* c );
MAGICALAPI_MATH void magicalPlane3SetZero( cPlane3* out );
MAGICALAPI_MATH void magicalPlane3Set( cPlane3* out, const cPlane3* p );

MAGICALAPI_MATH void magicalPlane3SetNormal( cPlane3* out, const cVector3* n );
MAGICALAPI_MATH void magicalPlane3GetNormal( cVector3* out, const cPlane3* p );

MAGICALAPI_MATH void magicalPlane3NearestPoint( cVector3* out, const cPlane3* p, const cVector3* point );
MAGICALAPI_MATH void magicalPlane3ProjectPoint( cVector3* out, const cPlane3* p, const cVector3* point );
MAGICALAPI_MATH float magicalPlane3DistanceToPoint( const cPlane3* p, const cVector3* point );

MAGICALAPI_MATH int magicalPlane3ClassifyPoint( const cPlane3* p, const cVector3* point );
MAGICALAPI_MATH int magicalPlane3ClassifyAABB3( const cPlane3* p, const cAABB3* aabb );
MAGICALAPI_MATH int magicalPlane3ClassifySphere3( const cPlane3* p, const cSphere3* sp );

MAGICALAPI_MATH cBool magicalPlane3Intersects( const cPlane3* p1, const cPlane3* p2 );
MAGICALAPI_MATH cBool magicalPlane3IntersectsAABB3( const cPlane3* p, const cAABB3* aabb );
MAGICALAPI_MATH cBool magicalPlane3IntersectsSphere3( const cPlane3* p, const cSphere3* sp );
MAGICALAPI_MATH void magicalPlane3IntersectsRay3( cRayIntersectResult* out, const cPlane3* p, const cRay3* r3, cBool discard_inside );

MAGICALAPI_MATH cBool magicalPlane3ContainsPoint( const cPlane3* p, const cVector3* point );

#ifdef __cplusplus
}
#endif

#endif //__C_PLANE3_H__