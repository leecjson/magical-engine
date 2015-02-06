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
#include "cAABB3.h"

cBool magicalAABB3Equals( const cAABB3* aabb1, const cAABB3* aabb2 )
{
	return
		magicalAlmostEqual( aabb1->minx, aabb2->minx, kVectorEpsilon ) &&
		magicalAlmostEqual( aabb1->miny, aabb2->miny, kVectorEpsilon ) &&
		magicalAlmostEqual( aabb1->minz, aabb2->minz, kVectorEpsilon ) &&
		magicalAlmostEqual( aabb1->maxx, aabb2->maxx, kVectorEpsilon ) &&
		magicalAlmostEqual( aabb1->maxy, aabb2->maxy, kVectorEpsilon ) &&
		magicalAlmostEqual( aabb1->maxz, aabb2->maxz, kVectorEpsilon );
}

cBool magicalAABB3IsZero( const cAABB3* aabb )
{
	return
		magicalAlmostZero( aabb->minx, kVectorEpsilon ) &&
		magicalAlmostZero( aabb->miny, kVectorEpsilon ) &&
		magicalAlmostZero( aabb->minz, kVectorEpsilon ) &&
		magicalAlmostZero( aabb->maxx, kVectorEpsilon ) &&
		magicalAlmostZero( aabb->maxy, kVectorEpsilon ) &&
		magicalAlmostZero( aabb->maxz, kVectorEpsilon );
}

void magicalAABB3Fill( cAABB3* out, float minx, float miny, float minz, float maxx, float maxy, float maxz )
{
	out->minx = minx;
	out->miny = miny;
	out->minz = minz;
	out->maxx = maxx;
	out->maxy = maxy;
	out->maxz = maxz;
}

void magicalAABB3Copy( cAABB3* out, const cAABB3* aabb )
{
	out->minx = aabb->minx;
	out->miny = aabb->miny;
	out->minz = aabb->minz;
	out->maxx = aabb->maxx;
	out->maxy = aabb->maxy;
	out->maxz = aabb->maxz;
}

void magicalAABB3SetBox( cAABB3* out, const cVector3* center, float width, float height, float depth )
{
	float half_width = width / 2;
	float half_height = height / 2;
	float half_depth = depth / 2;

	out->minx = center->x - half_width;
	out->miny = center->y - half_height;
	out->minz = center->z - half_depth;
	out->maxx = center->x + half_width;
	out->maxy = center->y + half_height;
	out->maxz = center->z + half_depth;
}

void magicalAABB3SetPoints( cAABB3* out, const cVector3* min, const cVector3* max )
{
	out->minx = min->x;
	out->miny = min->y;
	out->minz = min->z;
	out->maxx = max->x;
	out->maxy = max->y;
	out->maxz = max->z;
}

void magicalAABB3SetZero( cAABB3* out )
{
	out->minx = 0.0f;
	out->miny = 0.0f;
	out->minz = 0.0f;
	out->maxx = 0.0f;
	out->maxy = 0.0f;
	out->maxz = 0.0f;
}

void magicalAABB3SetMinPoint( cAABB3* out, const cVector3* min )
{
	out->minx = min->x;
	out->miny = min->y;
	out->minz = min->z;
}

void magicalAABB3GetMinPoint( cVector3* out, const cAABB3* aabb )
{
	out->x = aabb->minx;
	out->y = aabb->miny;
	out->z = aabb->minz;
}

void magicalAABB3SetMaxPoint( cAABB3* out, const cVector3* max )
{
	out->maxx = max->x;
	out->maxy = max->y;
	out->maxz = max->z;
}

void magicalAABB3GetMaxPoint( cVector3* out, const cAABB3* aabb )
{
	out->x = aabb->maxx;
	out->y = aabb->maxy;
	out->z = aabb->maxz;
}

/*-----------------------------------------------------------------------------*\
 * 使包围盒根据3D点变化展开 done
 *
 * 当目标点在外围盒之外时，才进行展开计算
 *
 * out 展开后的包围盒
 * aabb 展开前的包围盒
 * v 目标点
 *-----------------------------------------------------------------------------*/
void magicalAABB3AddPoint( cAABB3* out, const cAABB3* aabb, const cVector3* v )
{
	if( v->x < aabb->minx ) out->minx = v->x;
	if( v->y < aabb->miny ) out->miny = v->y;
	if( v->z < aabb->minz ) out->minz = v->z;
	if( v->x > aabb->maxx ) out->maxx = v->x;
	if( v->y > aabb->maxy ) out->maxy = v->y;
	if( v->z > aabb->maxz ) out->maxz = v->z;
}

/*-----------------------------------------------------------------------------*\
 * 合并两个包围盒，用一个更大的盒子包含合并的两个盒子 done
 *
 * out 合并后的包围盒
 * aabb1 aabb2 合并前的盒子
 *-----------------------------------------------------------------------------*/
void magicalAABB3Merge( cAABB3* out, const cAABB3* aabb1, const cAABB3* aabb2 )
{
	out->minx = min( aabb1->minx, aabb2->minx );
	out->miny = min( aabb1->miny, aabb2->miny );
	out->minz = min( aabb1->minz, aabb2->minz );
	out->maxx = min( aabb1->maxx, aabb2->maxx );
	out->maxy = min( aabb1->maxy, aabb2->maxy );
	out->maxz = min( aabb1->maxz, aabb2->maxz );
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒的中心点 done
 *
 * out 中心点
 * aabb 目标包围盒
 *-----------------------------------------------------------------------------*/
void magicalAABB3CenterPoint( cVector3* out, const cAABB3* aabb )
{
	out->x = 0.5f * ( aabb->minx + aabb->maxx );
	out->y = 0.5f * ( aabb->miny + aabb->maxy );
	out->z = 0.5f * ( aabb->minz + aabb->maxz );
}

/*-----------------------------------------------------------------------------*\
 * 计算任意点到包围盒上的最近点 done
 *
 * 任意点到包围盒上的最近点 直线距离最短
 *
 * out 包围盒上的最近点
 * aabb 包围盒
 * point 任意点
 *-----------------------------------------------------------------------------*/
void magicalAABB3NearestPoint( cVector3* out, const cAABB3* aabb, const cVector3* point )
{
	cVector3 dst;

	if( point->x < aabb->minx )
	{
		dst.x = aabb->minx;
	}
	else if( point->x > aabb->maxx )
	{
		dst.x = aabb->maxx;
	}
	else
	{
		dst.x = point->x;
	}

	if( point->y < aabb->miny )
	{
		dst.y = aabb->miny;
	}
	else if( point->y > aabb->maxy )
	{
		dst.y = aabb->maxy;
	}
	else
	{
		dst.y = point->y;
	}

	if( point->z < aabb->minz )
	{
		dst.z = aabb->minz;
	}
	else if( point->z > aabb->maxz )
	{
		dst.z = aabb->maxz;
	}
	else
	{
		dst.z = point->z;
	}

	out->x = dst.x;
	out->y = dst.y;
	out->z = dst.z;
}

/*-----------------------------------------------------------------------------*\
 * 使包围盒做旋转与缩放的变换 done
 *
 * out 变换后的包围盒
 * aabb 源包围盒
 * m 变换矩阵
 *-----------------------------------------------------------------------------*/
void magicalAABB3Transform( cAABB3* out, const cAABB3* aabb, const cMatrix4* m )
{
	cVector3 left_top_front;
	cVector3 left_bottom_front;
	cVector3 right_top_front;
	cVector3 right_bottom_front;
	cVector3 left_top_back;
	cVector3 left_bottom_back;
	cVector3 right_top_back;
	cVector3 right_bottom_back;

	magicalVector3Fill( &left_top_front, aabb->minx, aabb->maxy, aabb->maxz );
	magicalVector3Fill( &left_bottom_front, aabb->minx, aabb->miny, aabb->maxz );
	magicalVector3Fill( &right_top_front, aabb->maxx, aabb->maxy, aabb->maxz );
	magicalVector3Fill( &right_bottom_front, aabb->maxx, aabb->miny, aabb->maxz );
	magicalVector3Fill( &left_top_back, aabb->minx, aabb->maxy, aabb->minz );
	magicalVector3Fill( &left_bottom_back, aabb->minx, aabb->miny, aabb->minz );
	magicalVector3Fill( &right_top_back, aabb->maxx, aabb->maxy, aabb->minz );
	magicalVector3Fill( &right_bottom_back, aabb->maxx, aabb->miny, aabb->minz );

	magicalVector3MulMatrix4( &left_top_front, &left_top_front, m );
	magicalVector3MulMatrix4( &left_bottom_front, &left_bottom_front, m );
	magicalVector3MulMatrix4( &right_top_front, &right_top_front, m );
	magicalVector3MulMatrix4( &right_bottom_front, &right_bottom_front, m );
	magicalVector3MulMatrix4( &left_top_back, &left_top_back, m );
	magicalVector3MulMatrix4( &left_bottom_back, &left_bottom_back, m );
	magicalVector3MulMatrix4( &right_top_back, &right_top_back, m );
	magicalVector3MulMatrix4( &right_bottom_back, &right_bottom_back, m );

	magicalAABB3SetZero( out );

	magicalAABB3AddPoint( out, aabb, &left_top_front );
	magicalAABB3AddPoint( out, aabb, &left_bottom_front );
	magicalAABB3AddPoint( out, aabb, &right_top_front );
	magicalAABB3AddPoint( out, aabb, &right_bottom_front );
	magicalAABB3AddPoint( out, aabb, &left_top_back );
	magicalAABB3AddPoint( out, aabb, &left_bottom_back );
	magicalAABB3AddPoint( out, aabb, &right_top_back );
	magicalAABB3AddPoint( out, aabb, &right_bottom_back );
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒尺寸(大小) done
 *
 * aabb 目标包围盒
 * return 包围盒尺寸，对称顶点线段的长度
 *-----------------------------------------------------------------------------*/
float magicalAABB3Size( const cAABB3* aabb )
{
	float x, y, z;
	
	x = aabb->maxx - aabb->minx;
	y = aabb->maxy - aabb->miny;
	z = aabb->maxz - aabb->minz;

	return sqrtf( x * x + y * y + z * z );
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒的长 done
 *
 * aabb 目标包围盒
 * return 包围盒的长，x轴
 *-----------------------------------------------------------------------------*/
float magicalAABB3DiameterX( const cAABB3* aabb )
{
	return aabb->maxx - aabb->minx;
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒的高 done
 *
 * aabb 目标包围盒
 * return 包围盒的高，y轴
 *-----------------------------------------------------------------------------*/
float magicalAABB3DiameterY( const cAABB3* aabb )
{
	return aabb->maxy - aabb->miny;
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒的深 done
 *
 * aabb 目标包围盒
 * return 包围盒的深，z轴
 *-----------------------------------------------------------------------------*/
float magicalAABB3DiameterZ( const cAABB3* aabb )
{
	return aabb->maxz - aabb->minz;
}

/*-----------------------------------------------------------------------------*\
 * 判断包围盒是否相交 done
 *
 * aabb1 aabb2 目标包围盒
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalAABB3Intersects( const cAABB3* aabb1, const cAABB3* aabb2 )
{
	if( aabb1->minx > aabb2->maxx ) return cFalse;
	if( aabb1->maxx < aabb2->minx ) return cFalse;
	if( aabb1->miny > aabb2->maxy ) return cFalse;
	if( aabb1->maxy < aabb2->miny ) return cFalse;
	if( aabb1->minz > aabb2->maxz ) return cFalse;
	if( aabb1->maxz < aabb2->minz ) return cFalse;

	return cTrue;
}

/*-----------------------------------------------------------------------------*\
 * 判断包围盒是否相交。并得到相交部分的包围盒 done
 *
 * out 相交部分的包围盒
 * aabb1 aabb2 目标包围盒
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalAABB3IntersectsPart( cAABB3* out, const cAABB3* aabb1, const cAABB3* aabb2 )
{
	if( aabb1->minx > aabb2->maxx ) return cFalse;
	if( aabb1->maxx < aabb2->minx ) return cFalse;
	if( aabb1->miny > aabb2->maxy ) return cFalse;
	if( aabb1->maxy < aabb2->miny ) return cFalse;
	if( aabb1->minz > aabb2->maxz ) return cFalse;
	if( aabb1->maxz < aabb2->minz ) return cFalse;

	out->minx = max( aabb1->minx, aabb2->minx );
	out->maxx = min( aabb1->maxx, aabb2->maxx );
	out->miny = max( aabb1->miny, aabb2->miny );
	out->maxy = min( aabb1->maxy, aabb2->maxy );
	out->minz = max( aabb1->minz, aabb2->minz );
	out->maxz = min( aabb1->maxz, aabb2->maxz );

	return cTrue;
}

/*-----------------------------------------------------------------------------*\
 * 判断包围盒是否与平面相交 done
 *
 * aabb 包围盒
 * p 平面
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalAABB3IntersectsPlane( const cAABB3* aabb, const cPlane* p )
{
	return magicalPlaneClassifyAABB3( p, aabb ) == 0;
}

/*-----------------------------------------------------------------------------*\
 * 判断包围盒与球体是否相交
 *
 * aabb 包围盒
 * sp 球体
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalAABB3IntersectsSphere( const cAABB3* aabb, const cSphere* sp )
{
	float distance;
	cVector3 nearest;
	cVector3 center = { sp->x, sp->y, sp->z };

	magicalAABB3NearestPoint( &nearest, aabb, &center );
	distance = magicalVector3DistanceBetweenSq( &nearest, &center );

	return distance <= ( sp->r * sp->r );
}

void magicalAABB3IntersectsRay3( cRayIntersectResult* out, const cAABB3* aabb, const cRay3* r3, cBool discard_inside )
{
	magicalRay3IntersectsAABB3( out, r3, aabb, discard_inside );
}

/*-----------------------------------------------------------------------------*\
 * 判断包围盒是否包含一个点 done
 *
 * aabb 目标包围盒
 * point 目标点
 * return 是否包含
 *-----------------------------------------------------------------------------*/
cBool magicalAABB3ContainsPoint( const cAABB3* aabb, const cVector3* point )
{
	return 
		point->x >= aabb->minx &&
		point->x <= aabb->maxx &&
		point->y >= aabb->miny &&
		point->y <= aabb->maxy &&
		point->z >= aabb->minz &&
		point->z <= aabb->maxz;
}