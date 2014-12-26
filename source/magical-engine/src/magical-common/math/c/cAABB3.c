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
#include "cMathMacros.h"

cBool magicalAABB3Equals( const cAABB3 aabb1, const cAABB3 aabb2 )
{
	return
		magicalAlmostEqual( aabb1 _min_x, aabb2 _min_x, kEpsilon ) &&
		magicalAlmostEqual( aabb1 _min_y, aabb2 _min_y, kEpsilon ) &&
		magicalAlmostEqual( aabb1 _min_z, aabb2 _min_z, kEpsilon ) &&
		magicalAlmostEqual( aabb1 _max_x, aabb2 _max_x, kEpsilon ) &&
		magicalAlmostEqual( aabb1 _max_y, aabb2 _max_y, kEpsilon ) &&
		magicalAlmostEqual( aabb1 _max_z, aabb2 _max_z, kEpsilon );
}

cBool magicalAABB3IsZero( const cAABB3 aabb )
{
	return
		magicalAlmostZero( aabb _min_x, kEpsilon ) &&
		magicalAlmostZero( aabb _min_y, kEpsilon ) &&
		magicalAlmostZero( aabb _min_z, kEpsilon ) &&
		magicalAlmostZero( aabb _max_x, kEpsilon ) &&
		magicalAlmostZero( aabb _max_y, kEpsilon ) &&
		magicalAlmostZero( aabb _max_z, kEpsilon );
}

void magicalAABB3SetScalars( cAABB3 out, float min_x, float min_y, float min_z, float max_x, float max_y, float max_z )
{
	out _min_x = min_x;
	out _min_y = min_y;
	out _min_z = min_z;
	out _max_x = max_x;
	out _max_y = max_y;
	out _max_z = max_z;
}

void magicalAABB3SetCenterAround( cAABB3 out, const cVector3 center, float width, float height, float depth )
{
	float half_width = width / 2;
	float half_height = height / 2;
	float half_depth = depth / 2;

	out _min_x = center _x - half_width;
	out _min_y = center _y - half_height;
	out _min_z = center _z - half_depth;
	out _max_x = center _x + half_width;
	out _max_y = center _y + half_height;
	out _max_z = center _z + half_depth;
}

void magicalAABB3SetPoints( cAABB3 out, const cVector3 min, const cVector3 max )
{
	out _min_x = min _x;
	out _min_y = min _y;
	out _min_z = min _z;
	out _max_x = max _x;
	out _max_y = max _y;
	out _max_z = max _z;
}

void magicalAABB3SetZero( cAABB3 out )
{
	out _min_x = 0.0f;
	out _min_y = 0.0f;
	out _min_z = 0.0f;
	out _max_x = 0.0f;
	out _max_y = 0.0f;
	out _max_z = 0.0f;
}

void magicalAABB3Set( cAABB3 out, const cAABB3 aabb )
{
	out _min_x = aabb _min_x;
	out _min_y = aabb _min_y;
	out _min_z = aabb _min_z;
	out _max_x = aabb _max_x;
	out _max_y = aabb _max_y;
	out _max_z = aabb _max_z;
}

void magicalAABB3GetMin( cVector3 out, const cAABB3 aabb )
{
	out _x = aabb _min_x;
	out _y = aabb _min_y;
	out _z = aabb _min_z;
}

void magicalAABB3GetMax( cVector3 out, const cAABB3 aabb )
{
	out _x = aabb _max_x;
	out _y = aabb _max_y;
	out _z = aabb _max_z;
}

void magicalAABB3SetMin( cAABB3 out, const cVector3 min )
{
	out _min_x = min _x;
	out _min_y = min _y;
	out _min_z = min _z;
}

void magicalAABB3SetMax( cAABB3 out, const cVector3 max )
{
	out _max_x = max _x;
	out _max_y = max _y;
	out _max_z = max _z;
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
void magicalAABB3ExtendScalars( cAABB3 out, const cAABB3 aabb, float x, float y, float z )
{
	if( x < aabb _min_x ) out _min_x = x;
	if( y < aabb _min_y ) out _min_y = y;
	if( z < aabb _min_z ) out _min_z = z;
	if( x > aabb _max_x ) out _max_x = x;
	if( y > aabb _max_y ) out _max_y = y;
	if( z > aabb _max_z ) out _max_z = z;
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
void magicalAABB3Extend( cAABB3 out, const cAABB3 aabb, const cVector3 v )
{
	if( v _x < aabb _min_x ) out _min_x = v _x;
	if( v _y < aabb _min_y ) out _min_y = v _y;
	if( v _z < aabb _min_z ) out _min_z = v _z;
	if( v _x > aabb _max_x ) out _max_x = v _x;
	if( v _y > aabb _max_y ) out _max_y = v _y;
	if( v _z > aabb _max_z ) out _max_z = v _z;
}

/*-----------------------------------------------------------------------------*\
 * 合并两个包围盒，用一个更大的盒子包含合并的两个盒子 done
 *
 * out 合并后的包围盒
 * aabb1 aabb2 合并前的盒子
 *-----------------------------------------------------------------------------*/
void magicalAABB3Merge( cAABB3 out, const cAABB3 aabb1, const cAABB3 aabb2 )
{
	out _min_x = min( aabb1 _min_x, aabb2 _min_x );
	out _min_y = min( aabb1 _min_y, aabb2 _min_y );
	out _min_z = min( aabb1 _min_z, aabb2 _min_z );
	out _max_x = min( aabb1 _max_x, aabb2 _max_x );
	out _max_y = min( aabb1 _max_y, aabb2 _max_y );
	out _max_z = min( aabb1 _max_z, aabb2 _max_z );
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒的中心点 done
 *
 * out 中心点
 * aabb 目标包围盒
 *-----------------------------------------------------------------------------*/
void magicalAABB3Center( cVector3 out, const cAABB3 aabb )
{
	out _x = 0.5f * ( aabb _min_x + aabb _max_x );
	out _y = 0.5f * ( aabb _min_y + aabb _max_y );
	out _z = 0.5f * ( aabb _min_z + aabb _max_z );
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒尺寸(大小) done
 *
 * aabb 目标包围盒
 * return 包围盒尺寸，对称顶点线段的长度
 *-----------------------------------------------------------------------------*/
float magicalAABB3Size( const cAABB3 aabb )
{
	float x, y, z;
	
	x = aabb _max_x - aabb _min_x;
	y = aabb _max_y - aabb _min_y;
	z = aabb _max_z - aabb _min_z;

	return sqrtf( x * x + y * y + z * z );
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒的长 done
 *
 * aabb 目标包围盒
 * return 包围盒的长，x轴
 *-----------------------------------------------------------------------------*/
float magicalAABB3DiameterX( const cAABB3 aabb )
{
	return aabb _max_x - aabb _min_x;
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒的高 done
 *
 * aabb 目标包围盒
 * return 包围盒的高，y轴
 *-----------------------------------------------------------------------------*/
float magicalAABB3DiameterY( const cAABB3 aabb )
{
	return aabb _max_y - aabb _min_y;
}

/*-----------------------------------------------------------------------------*\
 * 计算包围盒的宽 done
 *
 * aabb 目标包围盒
 * return 包围盒的宽，z轴
 *-----------------------------------------------------------------------------*/
float magicalAABB3DiameterZ( const cAABB3 aabb )
{
	return aabb _max_z - aabb _min_z;
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
void magicalAABB3NearestPoint( cVector3 out, const cAABB3 aabb, const cVector3 point )
{
	cVector3 dst;

	if( point _x < aabb _min_x )
	{
		dst _x = aabb _min_x;
	}
	else if( point _x > aabb _max_x )
	{
		dst _x = aabb _max_x;
	}
	else
	{
		dst _x = point _x;
	}

	if( point _y < aabb _min_y )
	{
		dst _y = aabb _min_y;
	}
	else if( point _y > aabb _max_y )
	{
		dst _y = aabb _max_y;
	}
	else
	{
		dst _y = point _y;
	}

	if( point _z < aabb _min_z )
	{
		dst _z = aabb _min_z;
	}
	else if( point _z > aabb _max_z )
	{
		dst _z = aabb _max_z;
	}
	else
	{
		dst _z = point _z;
	}

	out _x = dst _x;
	out _y = dst _y;
	out _z = dst _z;
}

/*-----------------------------------------------------------------------------*\
 * 使包围盒做旋转与缩放的变换 done
 *
 * out 变换后的包围盒
 * aabb 源包围盒
 * m 变换矩阵
 *-----------------------------------------------------------------------------*/
void magicalAABB3Transform( cAABB3 out, const cAABB3 aabb, const cMatrix4 m )
{
	cVector3 left_top_front;
	cVector3 left_bottom_front;
	cVector3 right_top_front;
	cVector3 right_bottom_front;
	cVector3 left_top_back;
	cVector3 left_bottom_back;
	cVector3 right_top_back;
	cVector3 right_bottom_back;

	magicalVector3SetScalars( left_top_front, aabb _min_x, aabb _max_y, aabb _max_z );
	magicalVector3SetScalars( left_bottom_front, aabb _min_x, aabb _min_y, aabb _max_z );
	magicalVector3SetScalars( right_top_front, aabb _max_x, aabb _max_y, aabb _max_z );
	magicalVector3SetScalars( right_bottom_front, aabb _max_x, aabb _min_y, aabb _max_z );
	magicalVector3SetScalars( left_top_back, aabb _min_x, aabb _max_y, aabb _min_z );
	magicalVector3SetScalars( left_bottom_back, aabb _min_x, aabb _min_y, aabb _min_z );
	magicalVector3SetScalars( right_top_back, aabb _max_x, aabb _max_y, aabb _min_z );
	magicalVector3SetScalars( right_bottom_back, aabb _max_x, aabb _min_y, aabb _min_z );

	magicalVector3MulMatrix4( left_top_front, left_top_front, m );
	magicalVector3MulMatrix4( left_bottom_front, left_bottom_front, m );
	magicalVector3MulMatrix4( right_top_front, right_top_front, m );
	magicalVector3MulMatrix4( right_bottom_front, right_bottom_front, m );
	magicalVector3MulMatrix4( left_top_back, left_top_back, m );
	magicalVector3MulMatrix4( left_bottom_back, left_bottom_back, m );
	magicalVector3MulMatrix4( right_top_back, right_top_back, m );
	magicalVector3MulMatrix4( right_bottom_back, right_bottom_back, m );

	magicalAABB3SetZero( out );

	magicalAABB3Extend( out, aabb, left_top_front );
	magicalAABB3Extend( out, aabb, left_bottom_front );
	magicalAABB3Extend( out, aabb, right_top_front );
	magicalAABB3Extend( out, aabb, right_bottom_front );
	magicalAABB3Extend( out, aabb, left_top_back );
	magicalAABB3Extend( out, aabb, left_bottom_back );
	magicalAABB3Extend( out, aabb, right_top_back );
	magicalAABB3Extend( out, aabb, right_bottom_back );
}

/*-----------------------------------------------------------------------------*\
 * 判断包围盒是否相交 done
 *
 * aabb1 aabb2 目标包围盒
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalAABB3Intersects( const cAABB3 aabb1, const cAABB3 aabb2 )
{
	if( aabb1 _min_x > aabb2 _max_x ) return cFalse;
	if( aabb1 _max_x < aabb2 _min_x ) return cFalse;
	if( aabb1 _min_y > aabb2 _max_y ) return cFalse;
	if( aabb1 _max_y < aabb2 _min_y ) return cFalse;
	if( aabb1 _min_z > aabb2 _max_z ) return cFalse;
	if( aabb1 _max_z < aabb2 _min_z ) return cFalse;

	return cTrue;
}

/*-----------------------------------------------------------------------------*\
 * 判断包围盒是否相交。并得到相交部分的包围盒 done
 *
 * out 相交部分的包围盒
 * aabb1 aabb2 目标包围盒
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalAABB3IntersectsPart( cAABB3 out, const cAABB3 aabb1, const cAABB3 aabb2 )
{
	if( aabb1 _min_x > aabb2 _max_x ) return cFalse;
	if( aabb1 _max_x < aabb2 _min_x ) return cFalse;
	if( aabb1 _min_y > aabb2 _max_y ) return cFalse;
	if( aabb1 _max_y < aabb2 _min_y ) return cFalse;
	if( aabb1 _min_z > aabb2 _max_z ) return cFalse;
	if( aabb1 _max_z < aabb2 _min_z ) return cFalse;

	out _min_x = max( aabb1 _min_x, aabb2 _min_x );
	out _max_x = min( aabb1 _max_x, aabb2 _max_x );
	out _min_y = max( aabb1 _min_y, aabb2 _min_y );
	out _max_y = min( aabb1 _max_y, aabb2 _max_y );
	out _min_z = max( aabb1 _min_z, aabb2 _min_z );
	out _max_z = min( aabb1 _max_z, aabb2 _max_z );

	return cTrue;
}

/*-----------------------------------------------------------------------------*\
 * 判断包围盒是否与平面相交 done
 *
 * aabb 包围盒
 * p 平面
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalAABB3IntersectsPlane3( const cAABB3 aabb, const cPlane3 p )
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
cBool magicalAABB3IntersectsSphere3( const cAABB3 aabb, const cSphere3 sp )
{
	cVector3 nearest;
	float distance;

	magicalAABB3NearestPoint( nearest, aabb, sp );
	distance = magicalVector3DistanceBetweenSq( nearest, sp );

	return distance <= ( sp _r * sp _r );
}

void magicalAABB3IntersectsRay3( cRayIntersectResult out, const cAABB3 aabb, const cRay3 r3, const cBool discard_inside )
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
cBool magicalAABB3ContainsPoint( const cAABB3 aabb, const cVector3 point )
{
	return 
		point _x >= aabb _min_x &&
		point _x <= aabb _max_x &&
		point _y >= aabb _min_y &&
		point _y <= aabb _max_y &&
		point _z >= aabb _min_z &&
		point _z <= aabb _max_z;
}