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
#include "cFrustum.h"
#include <memory.h>

void magicalFrustumFill( cFrustum* out, const cMatrix4* m )
{
	cPlane p;

	// left
	p.x = m->m14 + m->m11;
	p.y = m->m24 + m->m21;
	p.z = m->m34 + m->m31;
	p.d = m->m44 + m->m41;
	magicalPlaneNormalize( &p, &p );
	magicalFrustumSetPlane( out, &p, kFrustumLeft );

	// right
	p.x = m->m14 - m->m11;
	p.y = m->m24 - m->m21;
	p.z = m->m34 - m->m31;
	p.d = m->m44 - m->m41;
	magicalPlaneNormalize( &p, &p );
	magicalFrustumSetPlane( out, &p, kFrustumRight );

	// bottom
	p.x = m->m14 + m->m12;
	p.y = m->m24 + m->m22;
	p.z = m->m34 + m->m32;
	p.d = m->m44 + m->m42;
	magicalPlaneNormalize( &p, &p );
	magicalFrustumSetPlane( out, &p, kFrustumBottom );

	// top
	p.x = m->m14 - m->m12;
	p.y = m->m24 - m->m22;
	p.z = m->m34 - m->m32;
	p.d = m->m44 - m->m42;
	magicalPlaneNormalize( &p, &p );
	magicalFrustumSetPlane( out, &p, kFrustumBottom );

	// near
	p.x = m->m14 + m->m13;
	p.y = m->m24 + m->m23; 
	p.z = m->m34 + m->m33;
	p.d = m->m44 + m->m43;
	magicalPlaneNormalize( &p, &p );
	magicalFrustumSetPlane( out, &p, kFrustumNear );

	// far
	p.x = m->m14 - m->m13;
	p.y = m->m24 - m->m23; 
	p.z = m->m34 - m->m33;
	p.d = m->m44 - m->m43;
	magicalPlaneNormalize( &p, &p );
	magicalFrustumSetPlane( out, &p, kFrustumFar );
}

void magicalFrustumCopy( cFrustum* out, const cFrustum* frustum )
{
	memcpy( out, frustum, sizeof( cFrustum ) );
}

void magicalFrustumSetPlane( cFrustum* out, const cPlane* p, int which )
{
	out->frustum[which * 4 + 0] = p->x;
	out->frustum[which * 4 + 1] = p->y;
	out->frustum[which * 4 + 2] = p->z;
	out->frustum[which * 4 + 3] = p->d;
}

cBool magicalAABB3InsideFrustum( const cAABB3* aabb, const cFrustum* frustum )
{
	cPlane plane;
	cVector3 nearpoint;
	
	for( int i = 0; i < 6; ++ i )
	{
		plane.x = frustum->frustum[i * 4 + 0];
		plane.y = frustum->frustum[i * 4 + 1];
		plane.z = frustum->frustum[i * 4 + 2];
		plane.d = frustum->frustum[i * 4 + 3];

		nearpoint.x = plane.x < 0 ? aabb->maxx : aabb->minx;
		nearpoint.y = plane.y < 0 ? aabb->maxy : aabb->miny;
		nearpoint.z = plane.z < 0 ? aabb->maxz : aabb->minz;

		if( magicalPlaneClassifyPoint( &plane, &nearpoint ) == 1 )
		{
			return cFalse;
		}
	}

	return cTrue;
}