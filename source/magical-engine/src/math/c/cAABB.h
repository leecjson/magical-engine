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
#ifndef __C_AABB_H__
#define __C_AABB_H__

#include "cUtility.h"

#pragma pack( push )
#pragma pack( 4 )
typedef struct cAABB {
	float minx;
	float miny;
	float minz;
	float maxx;
	float maxy;
	float maxz;
} cAABB;
#pragma pack( pop )

#include "cVector3.h"
#include "cMatrix4.h"
#include "cRay3.h"
#include "cPlane.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalAABBEquals( const cAABB* aabb1, const cAABB* aabb2 );
MAGICALAPI_MATH cBool magicalAABBIsZero( const cAABB* aabb );

MAGICALAPI_MATH void magicalAABBFill( cAABB* out, float minx, float miny, float minz, float maxx, float maxy, float maxz );
MAGICALAPI_MATH void magicalAABBCopy( cAABB* out, const cAABB* aabb );
MAGICALAPI_MATH void magicalAABBSetBox( cAABB* out, const cVector3* center, float width, float height, float depth );
MAGICALAPI_MATH void magicalAABBSetPoints( cAABB* out, const cVector3* min, const cVector3* max );
MAGICALAPI_MATH void magicalAABBSetZero( cAABB* out );

MAGICALAPI_MATH void magicalAABBSetMinPoint( cAABB* out, const cVector3* min );
MAGICALAPI_MATH void magicalAABBGetMinPoint( cVector3* out, const cAABB* aabb );
MAGICALAPI_MATH void magicalAABBSetMaxPoint( cAABB* out, const cVector3* max );
MAGICALAPI_MATH void magicalAABBGetMaxPoint( cVector3* out, const cAABB* aabb );
MAGICALAPI_MATH void magicalAABBAddPoint( cAABB* out, const cAABB* aabb, const cVector3* v );
MAGICALAPI_MATH void magicalAABBMerge( cAABB* out, const cAABB* aabb1, const cAABB* aabb2 );
MAGICALAPI_MATH void magicalAABBCenterPoint( cVector3* out, const cAABB* aabb );
MAGICALAPI_MATH void magicalAABBNearestPoint( cVector3* out, const cAABB* aabb, const cVector3* point );
MAGICALAPI_MATH void magicalAABBTransform( cAABB* out, const cAABB* aabb, const cMatrix4* m );

MAGICALAPI_MATH float magicalAABBSize( const cAABB* aabb );
MAGICALAPI_MATH float magicalAABBDiameterX( const cAABB* aabb );
MAGICALAPI_MATH float magicalAABBDiameterY( const cAABB* aabb );
MAGICALAPI_MATH float magicalAABBDiameterZ( const cAABB* aabb );

MAGICALAPI_MATH cBool magicalAABBIntersects( const cAABB* aabb1, const cAABB* aabb2 );
MAGICALAPI_MATH cBool magicalAABBIntersectsPart( cAABB* out, const cAABB* aabb1, const cAABB* aabb2 );
MAGICALAPI_MATH cBool magicalAABBIntersectsPlane( const cAABB* aabb, const cPlane* p );
MAGICALAPI_MATH cBool magicalAABBIntersectsSphere( const cAABB* aabb, const cSphere* sp );
MAGICALAPI_MATH void magicalAABBIntersectsRay3( cRayIntersectResult* out, const cAABB* aabb, const cRay3* r3, cBool discard_inside );

MAGICALAPI_MATH cBool magicalAABBContainsPoint( const cAABB* aabb, const cVector3* point );

#ifdef __cplusplus
}
#endif

#endif //__C_AABB_H__