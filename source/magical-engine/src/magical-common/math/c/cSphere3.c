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
#include "cSphere3.h"
#include "cMathMacros.h"

cBool magicalSphere3Equals( const cSphere3 sp1, const cSphere3 sp2 )
{
	return
		magicalAlmostEqual( sp1 _x, sp2 _x, kEpsilon ) &&
		magicalAlmostEqual( sp1 _y, sp2 _y, kEpsilon ) &&
		magicalAlmostEqual( sp1 _z, sp2 _z, kEpsilon ) &&
		magicalAlmostEqual( sp1 _r, sp2 _r, kEpsilon );
}

cBool magicalSphere3IsZero( const cSphere3 sp )
{
	return
		magicalAlmostZero( sp _x, kEpsilon ) &&
		magicalAlmostZero( sp _y, kEpsilon ) &&
		magicalAlmostZero( sp _z, kEpsilon ) &&
		magicalAlmostZero( sp _r, kEpsilon );
}

cBool magicalSphere3IsOne( const cSphere3 sp )
{
	return
		magicalAlmostZero( sp _x, kEpsilon ) &&
		magicalAlmostZero( sp _y, kEpsilon ) &&
		magicalAlmostZero( sp _z, kEpsilon ) &&
		magicalAlmostEqual( sp _r, 1.0f, kEpsilon );
}

void magicalSphere3SetScalars( cSphere3 out, float x, float y, float z, float r )
{
	out _x = x;
	out _y = y;
	out _z = z;
	out _r = r;
}

void magicalSphere3SetCenterAndRadius( cSphere3 out, const cVector3 center, float r )
{
	out _x = center _x;
	out _y = center _y;
	out _z = center _z;
	out _r = r;
}

void magicalSphere3SetZero( cSphere3 out )
{
	out _x = 0.0f;
	out _y = 0.0f;
	out _z = 0.0f;
	out _r = 0.0f;
}

void magicalSphere3SetOne( cSphere3 out )
{
	out _x = 0.0f;
	out _y = 0.0f;
	out _z = 0.0f;
	out _r = 1.0f;
}

void magicalSphere3Set( cSphere3 out, const cSphere3 sp )
{
	out _x = sp _x;
	out _y = sp _y;
	out _z = sp _z;
	out _r = sp _r;
}

cBool magicalSphere3Intersects( const cSphere3 sp1, const cSphere3 sp2 )
{
	return magicalVector3DistanceBetweenSq( sp1, sp2 ) <= ( sp1 _r + sp2 _r ) * ( sp1 _r + sp2 _r );
}

cBool magicalSphere3IntersectsAABB3( const cSphere3 sp, const cAABB3 aabb )
{
	return magicalAABB3IntersectsSphere3( aabb, sp );
}

cBool magicalSphere3IntersectsPlane3( const cSphere3 sp, const cPlane3 p )
{
	return magicalPlane3IntersectsSphere3( p, sp );
}

void magicalSphere3IntersectsRay3( cRayIntersectResult out, const cSphere3 sp, const cRay3 r3, const cBool discard_inside )
{
	magicalRay3IntersectsSphere3( out, r3, sp, discard_inside );
}

cBool magicalSphere3ContainsPoint( const cSphere3 sp, const cVector3 point )
{
	float dx = point _x - sp _x;
	float dy = point _y - sp _y;
	float dz = point _z - sp _z;

	return dx * dx + dy * dy + dz * dz <= sp _r;
}