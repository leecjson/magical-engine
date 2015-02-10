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
#ifndef __C_PLANE_H__
#define __C_PLANE_H__

#include "c-utility.h"

#define kPlaneFront 1
#define kPlaneOnPlane 0
#define kPlaneBehind -1

#pragma pack( push )
#pragma pack( 4 )
typedef struct cPlane {
	float x;
	float y;
	float z;
	float d;
} cPlane;
#pragma pack( pop )

#include "c-vector3.h"
#include "c-aabb3.h"
#include "c-sphere.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalPlaneEquals( const cPlane* p1, const cPlane* p2 );
MAGICALAPI_MATH cBool magicalPlaneIsZero( const cPlane* p );

MAGICALAPI_MATH void magicalPlaneFill( cPlane* out, float x, float y, float z, float d );
MAGICALAPI_MATH void magicalPlaneCopy( cPlane* out, const cPlane* p );
MAGICALAPI_MATH void magicalPlaneSetNormalAndDistance( cPlane* out, const cVector3* n, float d );
MAGICALAPI_MATH void magicalPlaneSetNormalAndPoint( cPlane* out, const cVector3* n, const cVector3* p );
MAGICALAPI_MATH void magicalPlaneSetPoints( cPlane* out, const cVector3* a, const cVector3* b, const cVector3* c );
MAGICALAPI_MATH void magicalPlaneSetZero( cPlane* out );

MAGICALAPI_MATH void magicalPlaneSetNormal( cPlane* out, const cVector3* n );
MAGICALAPI_MATH void magicalPlaneGetNormal( cVector3* out, const cPlane* p );
MAGICALAPI_MATH void magicalPlaneNormalize( cPlane* out, const cPlane* p );
MAGICALAPI_MATH void magicalPlaneNearestPoint( cVector3* out, const cPlane* p, const cVector3* point );
MAGICALAPI_MATH float magicalPlaneDistanceToPoint( const cPlane* p, const cVector3* point );

MAGICALAPI_MATH int magicalPlaneClassifyPoint( const cPlane* p, const cVector3* point );
MAGICALAPI_MATH int magicalPlaneClassifyAABB3( const cPlane* p, const cAABB3* aabb );
MAGICALAPI_MATH int magicalPlaneClassifySphere( const cPlane* p, const cSphere* sp );

MAGICALAPI_MATH cBool magicalPlaneIntersects( const cPlane* p1, const cPlane* p2 );
MAGICALAPI_MATH cBool magicalPlaneIntersectsAABB3( const cPlane* p, const cAABB3* aabb );
MAGICALAPI_MATH cBool magicalPlaneIntersectsSphere( const cPlane* p, const cSphere* sp );
MAGICALAPI_MATH cBool magicalPlaneIntersectsRay3( float* outt, const cPlane* p, const cRay3* r3, cBool discard_inside );

MAGICALAPI_MATH cBool magicalPlaneContainsPoint( const cPlane* p, const cVector3* point );

#ifdef __cplusplus
}
#endif

#endif //__C_PLANE_H__


//MAGICALAPI_MATH cBool plane_equals( const cPlane* p1, const cPlane* p2 );
//MAGICALAPI_MATH cBool plane_is_zero( const cPlane* p );
//
//MAGICALAPI_MATH void plane_fill( cPlane* out, float x, float y, float z, float d );
//MAGICALAPI_MATH void plane_copy( cPlane* out, const cPlane* p );
//MAGICALAPI_MATH void plane_set_normal_and_distance( cPlane* out, const cVector3* n, float d );
//MAGICALAPI_MATH void plane_set_normal_and_point( cPlane* out, const cVector3* n, const cVector3* p );
//MAGICALAPI_MATH void plane_set_points( cPlane* out, const cVector3* a, const cVector3* b, const cVector3* c );
//MAGICALAPI_MATH void plane_set_zero( cPlane* out );
//
//MAGICALAPI_MATH void plane_set_normal( cPlane* out, const cVector3* n );
//MAGICALAPI_MATH void plane_get_normal( cVector3* out, const cPlane* p );
//MAGICALAPI_MATH void plane_normalize( cPlane* out, const cPlane* p );
//MAGICALAPI_MATH void plane_nearest_point( cVector3* out, const cPlane* p, const cVector3* point );
//MAGICALAPI_MATH float plane_distance_to_point( const cPlane* p, const cVector3* point );
//
//MAGICALAPI_MATH int plane_classify_point( const cPlane* p, const cVector3* point );
//MAGICALAPI_MATH int plane_classify_AABB3( const cPlane* p, const cAABB3* aabb );
//MAGICALAPI_MATH int plane_classify_sphere( const cPlane* p, const cSphere* sp );
//
//MAGICALAPI_MATH cBool plane_intersects( const cPlane* p1, const cPlane* p2 );
//MAGICALAPI_MATH cBool plane_intersects_aabb3( const cPlane* p, const cAABB3* aabb );
//MAGICALAPI_MATH cBool plane_intersects_sphere( const cPlane* p, const cSphere* sp );
//MAGICALAPI_MATH cBool plane_intersects_ray3( cRayIntersectResult* out, const cPlane* p, const cRay3* r3, cBool discard_inside );
//
//MAGICALAPI_MATH cBool plane_contains_point( const cPlane* p, const cVector3* point );