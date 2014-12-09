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
#include "cStraight2.h"
#include "cMathMacros.h"

cBool magicalStraight2Equals( const cStraight2 st1, const cStraight2 st2 )
{
	return
		magicalAlmostEqual( st1 _x, st2 _x ) &&
		magicalAlmostEqual( st1 _y, st2 _y ) &&
		magicalAlmostEqual( st1 _z, st2 _z );
}

cBool magicalStraight2IsZero( const cStraight2 st )
{
	return
		magicalAlmostZero( st _x ) &&
		magicalAlmostZero( st _y ) &&
		magicalAlmostZero( st _z );
}

void magicalStraight2FillPointAndNormal( cStraight2 out, const cVector2 p, const cVector2 n )
{
	cVector2 nn;
	magicalVector2Normalize( nn, n );

	out _x = nn _x;
	out _y = nn _y;
	out _z = p _x * nn _x + p _y * nn _y;
}

void magicalStraight2FillNormalAndDistance( cStraight2 out, const cVector2 n, const float d )
{
	out _x = n _x;
	out _y = n _y;
	out _z = d;

	magicalVector2Normalize( out, out );
}

void magicalStraight2FillScalars( cStraight2 out, const float x, const float y, const float d )
{
	out _x = x;
	out _y = y;
	out _z = d;

	magicalVector2Normalize( out, out );
}

void magicalStraight2FillZero( cStraight2 out )
{
	out _x = 0.0f;
	out _y = 0.0f;
	out _z = 0.0f;
}

void magicalStraight2Fill( cStraight2 out, const cStraight2 st )
{
	out _x = st _x;
	out _y = st _y;
	out _z = st _z;
}

/*-----------------------------------------------------------------------------*\
 * 分类2D点与2D直线的关系 done
 *
 * st 直线
 * point 目标点
 * return 分类结果
 *        +1 在直线前方
 *        -1 在直线后方
 *         0 刚好在直线上
 *-----------------------------------------------------------------------------*/
int magicalStraight2ClassifyPoint( const cStraight2 st, const cVec3 point )
{
	float distance = st _x * point _x + st _y * point _y - st _z;

	if( distance > kEpsilon )
		return +1;

	if( distance < -kEpsilon )
		return -1;

	return 0;
}

/*-----------------------------------------------------------------------------*\
 * 分类两个2D直线的关系 done
 *
 * st1 直线1
 * st2 直线2
 * int 分类结果
 *     +1 平行
 *     -1 垂直
 *      0 相交
 *-----------------------------------------------------------------------------*/
int magicalStraight2ClassifyStraight2( const cStraight2 st1, const cStraight2 st2 )
{
	float dot = st1 _x * st2 _x + st1 _y * st2 _y;

	if( magicalAlmostZero( dot ) )
		return -1;

	if( magicalVector2Equals( st1, st2 ) )
		return +1;

	return 0;
}

/*-----------------------------------------------------------------------------*\
 * 判断两个直线是否有相交
 *
 * 不平行并且不垂直 就有交点
 *
 * st1 直线1
 * st2 直线2
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalStraight2Intersects( const cStraight2 st1, const cStraight2 st2 )
{
	return magicalStraight2ClassifyStraight2( st1, st2 ) == 0;
}

/*-----------------------------------------------------------------------------*\
 * 判断2D直线是否包含一个2D点 done
 *
 * st 直线
 * point 目标点
 * return 是否包含
 *-----------------------------------------------------------------------------*/
cBool magicalStraight2ContainsPoint( const cStraight2 st, const cVec3 point )
{
	return magicalAlmostZero( st _x * point _x + st _y * point _y - st _z );
}

