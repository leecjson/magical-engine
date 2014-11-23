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
#include "cPlane3.h"

void magicalPlane3FillScalars( cPlane3 out, const float x, const float y, const float z, const float d )
{
	out _x = x;
	out _y = y;
	out _z = z;
	out _d = d;

	magicalVec3Normalize( out, out );
}

/*-----------------------------------------------------------------------------*\
 * 通过法向量与平面到原点距离创建一个平面 done
 *
 * out 结果平面
 * n 表面法向量
 * d 原点到平面的距离
 *-----------------------------------------------------------------------------*/
void magicalPlane3FillNormalAndDistance( cPlane3 out, const cVec3 n, const float d )
{
	out _x = n _x;
	out _y = n _y;
	out _z = n _z;
	out _d = d;

	magicalVec3Normalize( out, out );
}

/*-----------------------------------------------------------------------------*\
 * 通过平面上任意一点表面法向量创建平面 done
 *
 * 平面方程：dot(p, n) = d
 * 
 * out 结果平面
 * p 平面上任意一点
 * n 表面法向量
 *-----------------------------------------------------------------------------*/
void magicalPlane3FillPointAndNormal( cPlane3 out, const cVec3 p, const cVec3 n )
{
	cVec3 nn;
	magicalVec3Normalize( nn, n );

	out _x = nn _x;
	out _y = nn _y;
	out _z = nn _z;
	out _d = p _x * nn _x + p _y * nn _y + p _z * nn _z;
}

/*-----------------------------------------------------------------------------*\
 * 通过三个不在一条直线上的点，组成一个由三角形形成的平面 done
 *
 * 左手坐标系：三个点呈顺时针看到的为正面
 *
 * 计算a到b向量与b到c向量的叉乘，可以获得与a到b、b到c互相垂直表面法向量
 * n = cross( b - a, c - b )
 * 
 * out 结果平面
 * a 第一个点
 * b 第二个点
 * c 第三个点
 *-----------------------------------------------------------------------------*/
void magicalPlane3FillPoints( cPlane3 out, const cVec3 a, const cVec3 b, const cVec3 c )
{
	cVec3 n, e3, e1;
	
	e3 _x = b _x - a _x;
	e3 _y = b _y - a _y;
	e3 _z = b _z - a _z;

	e1 _x = c _x - b _x;
	e1 _y = c _y - b _y;
	e1 _z = c _z - b _z;

	magicalVec3Cross( n, e3, e1 );
	
	debugassert( !magicalVec3IsZero( n ), "invaild operate!" );

	magicalVec3Normalize( n, n );

	out _x = n _x;
	out _y = n _y;
	out _z = n _z;
	out _d = a _x * n _x + a _y * n _y + a _z * n _z;
}

void magicalPlane3Fill( cPlane3 out, const cPlane3 p )
{
	out _x = p _x;
	out _y = p _y;
	out _z = p _z;
	out _d = p _d;
}

/*-----------------------------------------------------------------------------*\
 * 给平面设置法向量 done
 *
 * out 目标平面
 * n 设置的法向量
 *-----------------------------------------------------------------------------*/
void magicalPlane3SetNormal( cPlane3 out, const cVec3 n )
{
	out _x = n _x;
	out _y = n _y;
	out _z = n _z;

	magicalVec3Normalize( out, out );
}

/*-----------------------------------------------------------------------------*\
 * 获取平面的法向量 done
 *
 * out p的法向量
 * p 源平面
 *-----------------------------------------------------------------------------*/
void magicalPlane3GetNormal( cVec3 out, const cPlane3 p )
{
	out _x = p _x;
	out _y = p _y;
	out _z = p _z;
}

/*-----------------------------------------------------------------------------*\
 * 计算一个点到平面的最近点 done
 *
 * 原点到平面最近点的直线距离最短
 *
 * 最近点公式：
 * q` = q + scale( (d - dot(q, n)), n )
 *
 * out 返回最近点
 * p 目标平面
 * point 任意点
 *-----------------------------------------------------------------------------*/
void magicalPlane3NearestPoint( cVec3 out, const cPlane3 p, const cVec3 point )
{
	cVec3 scale_n;
	float distance = p _d - p _x * point _x + p _y * point _y + p _z * point _z;

	magicalVec3Scale( scale_n, p, distance );
	magicalVec3Add( out, point, scale_n );
}

/*-----------------------------------------------------------------------------*\
 * 计算一个点以正交投影的方式投影到平面P后的点
 *-----------------------------------------------------------------------------*/
void magicalPlane3ProjectPoint( cVec3 out, const cPlane3 p, const cVec3 point )
{
	magicalPlane3NearestPoint( out, p , point );
}

/*-----------------------------------------------------------------------------*\
 * 计算平面到3D点的最短距离 done
 *
 * q为目标点，n为平面的法向量，d为原点到平面的距离
 * 计算平面n,d到目标点q的最短距离
 * 公式：d` = dot(q, n) - d
 *
 * out p的法向量
 * p 目标平面
 *-----------------------------------------------------------------------------*/
float magicalPlane3DistanceToPoint( const cPlane3 p, const cVec3 point )
{
	return p _x * point _x + p _y * point _y + p _z * point _z - p _d;
}

/*-----------------------------------------------------------------------------*\
 * 分类3D点与面的关系 done
 *
 * p 目标平面
 * point 目标点
 * return 分类结果
 *        cPointInFrontOfPlane 在平面前方
 *        cPointBehindPlane 在平面后方
 *        cPointOnPlane 刚好在平面上
 *-----------------------------------------------------------------------------*/
cPointClassification magicalPlane3ClassifyPoint( const cPlane3 p, const cVec3 point )
{
   float distance = p _x * point _x + p _y * point _y + p _z * point _z - p _d;

   if( distance > MAGICAL_MATH_EPSILON ) 
	   return cPointInFrontOfPlane;

   if( distance < -MAGICAL_MATH_EPSILON ) 
	   return cPointBehindPlane;

   return cPointOnPlane;
}

/*-----------------------------------------------------------------------------*\
 * 判断平面是否包含3D点 done
 *
 * p 目标平面
 * point 目标点
 * return 是否包含
 *-----------------------------------------------------------------------------*/
cBool magicalPlane3ContainsPoint( const cPlane3 p, const cVec3 point )
{
	return magicalAlmostZero( p _x * point _x + p _y * point _y + p _z * point _z - p _d );
}