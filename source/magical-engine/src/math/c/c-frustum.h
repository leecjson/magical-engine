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
#ifndef __C_FRUSTUM_H__
#define __C_FRUSTUM_H__

#include "c-utility.h"

#define kFrustumLeft        0
#define kFrustumRight       1
#define kFrustumTop         2
#define kFrustumBottom      3
#define kFrustumNear        4
#define kFrustumFar         5

#pragma pack( push )
#pragma pack( 4 )
typedef struct cFrustum {
	float frustum[24];
} cFrustum;
#pragma pack( pop )

#include "c-vector3.h"
#include "c-matrix4.h"
#include "c-aabb3.h"
#include "c-plane.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH void magicalFrustumFill( cFrustum* out, const cMatrix4* m );
MAGICALAPI_MATH void magicalFrustumCopy( cFrustum* out, const cFrustum* frustum );

MAGICALAPI_MATH void magicalFrustumSetPlane( cFrustum* out, const cPlane* p, int which );

MAGICALAPI_MATH cBool magicalAABB3InsideFrustum( const cAABB3* aabb, const cFrustum* frustum );


#ifdef __cplusplus
}
#endif

#endif //__C_FRUSTUM_H__