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
		magicalAlmostEqual( aabb1->min_x, aabb2->min_x, kVectorEpsilon ) &&
		magicalAlmostEqual( aabb1->min_y, aabb2->min_y, kVectorEpsilon ) &&
		magicalAlmostEqual( aabb1->min_z, aabb2->min_z, kVectorEpsilon ) &&
		magicalAlmostEqual( aabb1->max_x, aabb2->max_x, kVectorEpsilon ) &&
		magicalAlmostEqual( aabb1->max_y, aabb2->max_y, kVectorEpsilon ) &&
		magicalAlmostEqual( aabb1->max_z, aabb2->max_z, kVectorEpsilon );
}

cBool magicalAABB3IsZero( const cAABB3* aabb )
{
	return
		magicalAlmostZero( aabb->min_x, kVectorEpsilon ) &&
		magicalAlmostZero( aabb->min_y, kVectorEpsilon ) &&
		magicalAlmostZero( aabb->min_z, kVectorEpsilon ) &&
		magicalAlmostZero( aabb->max_x, kVectorEpsilon ) &&
		magicalAlmostZero( aabb->max_y, kVectorEpsilon ) &&
		magicalAlmostZero( aabb->max_z, kVectorEpsilon );
}

void magicalAABB3Fill( cAABB3* out, float min_x, float min_y, float min_z, float max_x, float max_y, float max_z )
{
	out->min_x = min_x;
	out->min_y = min_y;
	out->min_z = min_z;
	out->max_x = max_x;
	out->max_y = max_y;
	out->max_z = max_z;
}

void magicalAABB3Copy( cAABB3* out, const cAABB3* aabb )
{
	out->min_x = aabb->min_x;
	out->min_y = aabb->min_y;
	out->min_z = aabb->min_z;
	out->max_x = aabb->max_x;
	out->max_y = aabb->max_y;
	out->max_z = aabb->max_z;
}

void magicalAABB3SetCenterAround( cAABB3* out, const cVector3* center, float width, float height, float depth )
{
	float half_width = width / 2;
	float half_height = height / 2;
	float half_depth = depth / 2;

	out->min_x = center->x - half_width;
	out->min_y = center->y - half_height;
	out->min_z = center->z - half_depth;
	out->max_x = center->x + half_width;
	out->max_y = center->y + half_height;
	out->max_z = center->z + half_depth;
}

void magicalAABB3SetPoints( cAABB3* out, const cVector3* min, const cVector3* max )
{
	out->min_x = min->x;
	out->min_y = min->y;
	out->min_z = min->z;
	out->max_x = max->x;
	out->max_y = max->y;
	out->max_z = max->z;
}

void magicalAABB3SetZero( cAABB3* out )
{
	out->min_x = 0.0f;
	out->min_y = 0.0f;
	out->min_z = 0.0f;
	out->max_x = 0.0f;
	out->max_y = 0.0f;
	out->max_z = 0.0f;
}

void magicalAABB3GetMin( cVector3* out, const cAABB3* aabb )
{
	out->x = aabb->min_x;
	out->y = aabb->min_y;
	out->z = aabb->min_z;
}

void magicalAABB3GetMax( cVector3* out, const cAABB3* aabb )
{
	out->x = aabb->max_x;
	out->y = aabb->max_y;
	out->z = aabb->max_z;
}

void magicalAABB3SetMin( cAABB3* out, const cVector3* min )
{
	out->min_x = min->x;
	out->min_y = min->y;
	out->min_z = min->z;
}

void magicalAABB3SetMax( cAABB3* out, const cVector3* max )
{
	out->max_x = max->x;
	out->max_y = max->y;
	out->max_z = max->z;
}

/*-----------------------------------------------------------------------------*\
 * 使包围盒根据3D点变化展开 done
 *
 * 当目标点在外围盒之外时，才进行展开计算
 *
 * out 展开后的包围盒
 * aabb 展开前的包围盒
 * x y z 目标点
 *-----------------------------------------------------------------------------*/
void magicalAABB3AddPointScalars( cAABB3* out, const cAABB3* aabb, float x, float y, float z )
{
	if( x < aabb->min_x ) out->min_x = x;
	if( y < aabb->min_y ) out->min_y = y;
	if( z < aabb->min_z ) out->min_z = z;
	if( x > aabb->max_x ) out->max_x = x;
	if( y > aabb->max_y ) out->max_y = y;
	if( z > aabb->max_z ) out->max_z = z;
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
	if( v->x < aabb->min_x ) out->min_x = v->x;
	if( v->y < aabb->min_y ) out->min_y = v->y;
	if( v->z < aabb->min_z ) out->min_z = v->z;
	if( v->x > aabb->max_x ) out->max_x = v->x;
	if( v->y > aabb->max_y ) out->max_y = v->y;
	if( v->z > aabb->max_z ) out->max_z = v->z;
}

/*-----------------------------------------------------------------------------*\
 * 合并两个包围盒，用一个更大的盒子包含合并的两个盒子 done
 *
 * out 合并后的包围盒
 * aabb1 aabb2 合并前的盒子
 *-----------------------------------------------------------------------------*/
void magicalAABB3Merge( cAABB3* out, const cAABB3* aabb1, const cAABB3* aabb2 )
{
	out->min_x = min( aabb1->min_x, aabb2->min_x );
	out->min_y = min( aabb1->min_y, aabb2->min_y );
	out->min_z = min( aabb1->min_z, aabb2->min_z );
	out->max_x = min( aabb1->max_x, aabb2->max_x );
	out->max_y = min( aabb1->max_y, aabb2->max_y );
	out->max_z = min( aabb1->max_z, aabb2->max_z );
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒的中心点 done
 *
 * out 中心点
 * aabb 目标包围盒
 *-----------------------------------------------------------------------------*/
void magicalAABB3Center( cVector3* out, const cAABB3* aabb )
{
	out->x = 0.5f * ( aabb->min_x + aabb->max_x );
	out->y = 0.5f * ( aabb->min_y + aabb->max_y );
	out->z = 0.5f * ( aabb->min_z + aabb->max_z );
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
	
	x = aabb->max_x - aabb->min_x;
	y = aabb->max_y - aabb->min_y;
	z = aabb->max_z - aabb->min_z;

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
	return aabb->max_x - aabb->min_x;
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒的高 done
 *
 * aabb 目标包围盒
 * return 包围盒的高，y轴
 *-----------------------------------------------------------------------------*/
float magicalAABB3DiameterY( const cAABB3* aabb )
{
	return aabb->max_y - aabb->min_y;
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒的宽 done
 *
 * aabb 目标包围盒
 * return 包围盒的宽，z轴
 *-----------------------------------------------------------------------------*/
float magicalAABB3DiameterZ( const cAABB3* aabb )
{
	return aabb->max_z - aabb->min_z;
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

	if( point->x < aabb->min_x )
	{
		dst.x = aabb->min_x;
	}
	else if( point->x > aabb->max_x )
	{
		dst.x = aabb->max_x;
	}
	else
	{
		dst.x = point->x;
	}

	if( point->y < aabb->min_y )
	{
		dst.y = aabb->min_y;
	}
	else if( point->y > aabb->max_y )
	{
		dst.y = aabb->max_y;
	}
	else
	{
		dst.y = point->y;
	}

	if( point->z < aabb->min_z )
	{
		dst.z = aabb->min_z;
	}
	else if( point->z > aabb->max_z )
	{
		dst.z = aabb->max_z;
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

	magicalVector3Fill( &left_top_front, aabb->min_x, aabb->max_y, aabb->max_z );
	magicalVector3Fill( &left_bottom_front, aabb->min_x, aabb->min_y, aabb->max_z );
	magicalVector3Fill( &right_top_front, aabb->max_x, aabb->max_y, aabb->max_z );
	magicalVector3Fill( &right_bottom_front, aabb->max_x, aabb->min_y, aabb->max_z );
	magicalVector3Fill( &left_top_back, aabb->min_x, aabb->max_y, aabb->min_z );
	magicalVector3Fill( &left_bottom_back, aabb->min_x, aabb->min_y, aabb->min_z );
	magicalVector3Fill( &right_top_back, aabb->max_x, aabb->max_y, aabb->min_z );
	magicalVector3Fill( &right_bottom_back, aabb->max_x, aabb->min_y, aabb->min_z );

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
 * 判断包围盒是否相交 done
 *
 * aabb1 aabb2 目标包围盒
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalAABB3Intersects( const cAABB3* aabb1, const cAABB3* aabb2 )
{
	if( aabb1->min_x > aabb2->max_x ) return cFalse;
	if( aabb1->max_x < aabb2->min_x ) return cFalse;
	if( aabb1->min_y > aabb2->max_y ) return cFalse;
	if( aabb1->max_y < aabb2->min_y ) return cFalse;
	if( aabb1->min_z > aabb2->max_z ) return cFalse;
	if( aabb1->max_z < aabb2->min_z ) return cFalse;

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
	if( aabb1->min_x > aabb2->max_x ) return cFalse;
	if( aabb1->max_x < aabb2->min_x ) return cFalse;
	if( aabb1->min_y > aabb2->max_y ) return cFalse;
	if( aabb1->max_y < aabb2->min_y ) return cFalse;
	if( aabb1->min_z > aabb2->max_z ) return cFalse;
	if( aabb1->max_z < aabb2->min_z ) return cFalse;

	out->min_x = max( aabb1->min_x, aabb2->min_x );
	out->max_x = min( aabb1->max_x, aabb2->max_x );
	out->min_y = max( aabb1->min_y, aabb2->min_y );
	out->max_y = min( aabb1->max_y, aabb2->max_y );
	out->min_z = max( aabb1->min_z, aabb2->min_z );
	out->max_z = min( aabb1->max_z, aabb2->max_z );

	return cTrue;
}

/*-----------------------------------------------------------------------------*\
 * 判断包围盒是否与平面相交 done
 *
 * aabb 包围盒
 * p 平面
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalAABB3IntersectsPlane3( const cAABB3* aabb, const cPlane3* p )
{
	return magicalPlane3ClassifyAABB3( p, aabb ) == 0;
}

/*-----------------------------------------------------------------------------*\
 * 判断包围盒与球体是否相交
 *
 * aabb 包围盒
 * sp 球体
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalAABB3IntersectsSphere3( const cAABB3* aabb, const cSphere3* sp )
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
		point->x >= aabb->min_x &&
		point->x <= aabb->max_x &&
		point->y >= aabb->min_y &&
		point->y <= aabb->max_y &&
		point->z >= aabb->min_z &&
		point->z <= aabb->max_z;
}