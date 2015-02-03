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
#include "cRay3.h"

cBool magicalRay3Equals( const cRay3* r31, const cRay3* r32 )
{
	return
		magicalAlmostEqual( r31->ox, r32->ox, kVectorEpsilon ) &&
		magicalAlmostEqual( r31->oy, r32->oy, kVectorEpsilon ) &&
		magicalAlmostEqual( r31->oz, r32->oz, kVectorEpsilon ) &&
		magicalAlmostEqual( r31->dx, r32->dx, kVectorEpsilon ) &&
		magicalAlmostEqual( r31->dy, r32->dy, kVectorEpsilon ) &&
		magicalAlmostEqual( r31->dz, r32->dz, kVectorEpsilon );
}

cBool magicalRay3IsZero( const cRay3* r3 )
{
	return
		magicalAlmostZero( r3->ox, kVectorEpsilon ) &&
		magicalAlmostZero( r3->oy, kVectorEpsilon ) &&
		magicalAlmostZero( r3->oz, kVectorEpsilon ) &&
		magicalAlmostZero( r3->dx, kVectorEpsilon ) &&
		magicalAlmostZero( r3->dy, kVectorEpsilon ) &&
		magicalAlmostZero( r3->dz, kVectorEpsilon );
}

void magicalRay3Fill( cRay3* out, float ox, float oy, float oz, float dx, float dy, float dz )
{
	out->ox = ox;
	out->oy = oy;
	out->oz = oz;
	out->dx = dx;
	out->dy = dy;
	out->dz = dz;
}

void magicalRay3Copy( cRay3* out, const cRay3* r3 )
{
	out->ox = r3->ox;
	out->oy = r3->oy;
	out->oz = r3->oz;
	out->dx = r3->dx;
	out->dy = r3->dy;
	out->dz = r3->dz;
}

void magicalRay3SetOriginToEnd( cRay3* out, const cVector3* origin, const cVector3* end )
{
	cVector3 nd = { end->x - origin->x, end->y - origin->y, end->z - origin->z };
	magicalVector3Normalize( &nd, &nd );

	out->ox = origin->x;
	out->oy = origin->y;
	out->oz = origin->z;
	out->dx = nd.x;
	out->dy = nd.y;
	out->dz = nd.z;
}

void magicalRay3SetOriginAndDirection( cRay3* out, const cVector3* origin, const cVector3* direction )
{
	cVector3 nd;
	magicalVector3Normalize( &nd, direction );

	out->ox = origin->x;
	out->oy = origin->y;
	out->oz = origin->z;
	out->dx = nd.x;
	out->dy = nd.y;
	out->dz = nd.z;
}

void magicalRay3SetZero( cRay3* out )
{
	out->ox = 0.0f;
	out->oy = 0.0f;
	out->oz = 0.0f;
	out->dx = 0.0f;
	out->dy = 0.0f;
	out->dz = 0.0f;
}

void magicalRay3GetOrigin( cVector3* out, const cRay3* r3 )
{
	out->x = r3->ox;
	out->y = r3->oy;
	out->z = r3->oz;
}

void magicalRay3GetDirection( cVector3* out, const cRay3* r3 )
{
	out->x = r3->dx;
	out->y = r3->dy;
	out->z = r3->dz;
}

void magicalRay3SetOrigin( cRay3* out, const cVector3* origin )
{
	out->ox = origin->x;
	out->oy = origin->y;
	out->oz = origin->z;
}

void magicalRay3SetDirection( cRay3* out, const cVector3* direction )
{
	cVector3 nd;
	magicalVector3Normalize( &nd, direction );

	out->dx = nd.x;
	out->dy = nd.y;
	out->dz = nd.z;
}

/*-----------------------------------------------------------------------------*\
 * 检测射线与3D平面的相交关系，并返回原点到相交点的距离 done
 *
 * dist 距离 相交时有效
 * r3 源射线
 * p 平面
 * discard_inside 是否忽略原点在平面内的相交检测
 * return 是否相交
 *-----------------------------------------------------------------------------*/
void magicalRay3IntersectsPlane( cRayIntersectResult* out, const cRay3* r3, const cPlane* p, cBool discard_inside )
{
	int cp;
	float dn;

	cVector3 pn;
	cVector3 o = { r3->ox, r3->oy, r3->oz };
	cVector3 d = { r3->dx, r3->dy, r3->dz };

	cp = magicalPlaneClassifyPoint( p, &o );
	if( cp == 0 )
	{
		out->t = 0.0f;
		out->b = !discard_inside;
		return;
	}

	pn.x = p->x;
	pn.y = p->y;
	pn.z = p->z;

	dn = magicalVector3Dot( &d, &pn );
	if( magicalAlmostZero( dn, kVectorEpsilon ) == cFalse )
	{
		if( ( cp == 1 && dn < -kVectorEpsilon ) || ( cp == -1 && dn > kVectorEpsilon ) )
		{
			out->t = ( p->d - magicalVector3Dot( &o, &pn ) ) / dn; 
			out->b = cTrue;
			return;
		}
	}

	out->t = 0.0f;
	out->b = cFalse;
}

/*-----------------------------------------------------------------------------*\
 * 检测射线与轴对齐包围盒的相交关系，并返回原点到相交点的距离 done
 *
 * dist 距离 相交时有效
 * r3 源射线
 * aabb 包围盒
 * discard_inside 是否忽略原点在包围盒内的相交检测
 * return 是否相交
 *-----------------------------------------------------------------------------*/
void magicalRay3IntersectsAABB( cRayIntersectResult* out, const cRay3* r3, const cAABB* aabb, cBool discard_inside )
{
	float t;
	cVector3 p;

	if( r3->ox >= aabb->minx &&
		r3->oy >= aabb->miny &&
		r3->oz >= aabb->minz &&
		r3->ox <= aabb->maxx &&
		r3->oy <= aabb->maxy &&
		r3->oz <= aabb->maxz )
	{
		out->t = 0.0f;
		out->b = !discard_inside;
		return;
	}

	if( magicalAlmostZero( r3->dx, kVectorEpsilon ) == cFalse )
	{
		if( r3->dx > 0.0f )
		{
			t = ( aabb->minx - r3->ox ) / r3->dx;
		}
		else
		{
			t = ( aabb->maxx - r3->ox ) / r3->dx;
		}

		if( t > 0.0f )
		{
			p.x = r3->ox + r3->dx * t;
			p.y = r3->oy + r3->dy * t;
			p.z = r3->oz + r3->dz * t;

			if( p.y >= aabb->miny && p.y <= aabb->maxy &&
				p.z >= aabb->minz && p.z <= aabb->maxz )
			{
				out->t = t;
				out->b = cTrue;
				return;
			}
		}
	}

	if( magicalAlmostZero( r3->dy, kVectorEpsilon ) == cFalse )
	{
		if( r3->dy > 0.0f )
		{
			t = ( aabb->miny - r3->oy ) / r3->dy;
		}
		else
		{
			t = ( aabb->maxy - r3->oy ) / r3->dy;
		}

		if( t > 0.0f )
		{
			p.x = r3->ox + r3->dx * t;
			p.y = r3->oy + r3->dy * t;
			p.z = r3->oz + r3->dz * t;

			if( p.z >= aabb->minz && p.z <= aabb->maxz &&
				p.x >= aabb->minx && p.x <= aabb->maxx )
			{
				out->t = t;
				out->b = cTrue;
				return;
			}
		}
	}

	if( magicalAlmostZero( r3->dz, kVectorEpsilon ) == cFalse )
	{
		if( r3->dz > 0.0f )
		{
			t = ( aabb->minz - r3->oz ) / r3->dz;
		}
		else
		{
			t = ( aabb->maxz - r3->oz ) / r3->dz;
		}

		if( t > 0.0f )
		{
			p.x = r3->ox + r3->dx * t;
			p.y = r3->oy + r3->dy * t;
			p.z = r3->oz + r3->dz * t;

			if( p.x >= aabb->minx && p.x <= aabb->maxx &&
				p.y >= aabb->miny && p.y <= aabb->maxy )
			{
				out->t = t;
				out->b = cTrue;
				return;
			}
				
		}
	}
	
	out->t = 0.0f;
	out->b = cFalse;
}

/*-----------------------------------------------------------------------------*\
 * 检测射线与球体的相交情况，并返回起点到交点的长度 done
 *
 * dist 返回射线到球体相交点的距离 当相交时有效
 *      有可能在原点就已经相交
 * r3 源射线
 * sp 球体
 * discard_inside 是否忽略原点在球体内的相交检测
 * return 是否相交
 *-----------------------------------------------------------------------------*/
void magicalRay3IntersectsSphere( cRayIntersectResult* out, const cRay3* r3, const cSphere* sp, cBool discard_inside )
{
	float a, esq, f, fsq, rsq;
	cVector3 e;
	cVector3 o = { r3->ox, r3->oy, r3->oz };
	cVector3 d = { r3->dx, r3->dy, r3->dz };
	cVector3 c = { sp->x, sp->y, sp->z };

	magicalVector3Sub( &e, &c, &o );

	rsq = sp->r * sp->r;
	esq = magicalVector3LengthSq( &e );
	if( esq < rsq )
	{
		out->t = 0.0f;
		out->b = !discard_inside;
		return;
	}

	a = magicalVector3Dot( &e, &d );
	fsq = rsq - esq + a * a;
	if( fsq <= 0.0f )
	{
		out->t = 0.0f;
		out->b = cFalse;
		return;
	}

	f = sqrtf( fsq );
	out->t = a - f;
	out->b = cTrue;
}