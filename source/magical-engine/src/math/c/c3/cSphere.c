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
#include "cSphere.h"

cBool magicalSphereEquals( const cSphere* sp1, const cSphere* sp2 )
{
	return
		magicalAlmostEqual( sp1->x, sp2->x, kVectorEpsilon ) &&
		magicalAlmostEqual( sp1->y, sp2->y, kVectorEpsilon ) &&
		magicalAlmostEqual( sp1->z, sp2->z, kVectorEpsilon ) &&
		magicalAlmostEqual( sp1->r, sp2->r, kVectorEpsilon );
}

cBool magicalSphereIsZero( const cSphere* sp )
{
	return
		magicalAlmostZero( sp->x, kVectorEpsilon ) &&
		magicalAlmostZero( sp->y, kVectorEpsilon ) &&
		magicalAlmostZero( sp->z, kVectorEpsilon ) &&
		magicalAlmostZero( sp->r, kVectorEpsilon );
}

cBool magicalSphereIsOne( const cSphere* sp )
{
	return
		magicalAlmostZero( sp->x, kVectorEpsilon ) &&
		magicalAlmostZero( sp->y, kVectorEpsilon ) &&
		magicalAlmostZero( sp->z, kVectorEpsilon ) &&
		magicalAlmostEqual( sp->r, 1.0f, kVectorEpsilon );
}

void magicalSphereFill( cSphere* out, float x, float y, float z, float r )
{
	out->x = x;
	out->y = y;
	out->z = z;
	out->r = r;
}

void magicalSphereCopy( cSphere* out, const cSphere* sp )
{
	out->x = sp->x;
	out->y = sp->y;
	out->z = sp->z;
	out->r = sp->r;
}

void magicalSphereSetCenterAndRadius( cSphere* out, const cVector3* center, float r )
{
	out->x = center->x;
	out->y = center->y;
	out->z = center->z;
	out->r = r;
}

void magicalSphereSetZero( cSphere* out )
{
	out->x = 0.0f;
	out->y = 0.0f;
	out->z = 0.0f;
	out->r = 0.0f;
}

void magicalSphereSetOne( cSphere* out )
{
	out->x = 0.0f;
	out->y = 0.0f;
	out->z = 0.0f;
	out->r = 1.0f;
}

cBool magicalSphereIntersects( const cSphere* sp1, const cSphere* sp2 )
{
	cVector3 c1 = { sp1->x, sp1->y, sp1->z };
	cVector3 c2 = { sp2->x, sp2->y, sp2->z };

	return magicalVector3DistanceBetweenSq( &c1, &c2 ) <= ( sp1->r + sp2->r ) * ( sp1->r + sp2->r );
}

cBool magicalSphereIntersectsAABB( const cSphere* sp, const cAABB* aabb )
{
	return magicalAABBIntersectsSphere( aabb, sp );
}

cBool magicalSphereIntersectsPlane( const cSphere* sp, const cPlane* p )
{
	return magicalPlaneIntersectsSphere( p, sp );
}

void magicalSphereIntersectsRay3( cRayIntersectResult* out, const cSphere* sp, const cRay3* r3, cBool discard_inside )
{
	magicalRay3IntersectsSphere( out, r3, sp, discard_inside );
}

cBool magicalSphereContainsPoint( const cSphere* sp, const cVector3* point )
{
	float dx = point->x - sp->x;
	float dy = point->y - sp->y;
	float dz = point->z - sp->z;

	return dx * dx + dy * dy + dz * dz <= sp->r;
}