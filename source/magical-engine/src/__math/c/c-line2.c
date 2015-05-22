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
#include "cLine2.h"
//
//cBool magicalLine2Equals( const cLine2 l1, const cLine2 l2 )
//{
//	return
//		magicalAlmostEqual( l1 _x, l2 _x ) &&
//		magicalAlmostEqual( l1 _y, l2 _y ) &&
//		magicalAlmostEqual( l1 _z, l2 _z );
//}
//
//cBool magicalLine2IsZero( const cLine2 l )
//{
//	return
//		magicalAlmostZero( l _x ) &&
//		magicalAlmostZero( l _y ) &&
//		magicalAlmostZero( l _z );
//}
//
//void magicalLine2FillNormalAndDistance( cLine2 out, const cVector2 n, const float d )
//{
//	out _x = n _x;
//	out _y = n _y;
//	out _z = d;
//
//	magicalVector2Normalize( out, out );
//}
//
//void magicalLine2FillNormalAndPoint( cLine2 out, const cVector2 n, const cVector2 p )
//{
//	cVector2 nn;
//	magicalVector2Normalize( nn, n );
//
//	out _x = nn _x;
//	out _y = nn _y;
//	out _z = p _x * nn _x + p _y * nn _y;
//}
//
//void magicalLine2FillScalars( cLine2 out, const float x, const float y, const float d )
//{
//	out _x = x;
//	out _y = y;
//	out _z = d;
//
//	magicalVector2Normalize( out, out );
//}
//
//void magicalLine2FillZero( cLine2 out )
//{
//	out _x = 0.0f;
//	out _y = 0.0f;
//	out _z = 0.0f;
//}
//
//void magicalLine2Fill( cLine2 out, const cLine2 l )
//{
//	out _x = l _x;
//	out _y = l _y;
//	out _z = l _z;
//}
//
///*-----------------------------------------------------------------------------*\
// * 分类2D点与2D直线的关系 done
// *
// * l 直线
// * point 目标点
// * return 分类结果
// *        +1 在直线前方
// *        -1 在直线后方
// *         0 刚好在直线上
// *-----------------------------------------------------------------------------*/
//int magicalLine2ClassifyPoint( const cLine2 l, const cVector3 point )
//{
//	float distance = l _x * point _x + l _y * point _y - l _z;
//
//	if( distance > kEpsilon )
//		return +1;
//
//	if( distance < -kEpsilon )
//		return -1;
//
//	return 0;
//}
//
///*-----------------------------------------------------------------------------*\
// * 分类两个2D直线的关系 done
// *
// * l1 直线1
// * l2 直线2
// * int 分类结果
// *     +1 平行
// *     -1 垂直
// *      0 相交
// *-----------------------------------------------------------------------------*/
//int magicalLine2ClassifyLine2( const cLine2 l1, const cLine2 l2 )
//{
//	float dot = l1 _x * l2 _x + l1 _y * l2 _y;
//
//	if( magicalAlmostZero( dot ) )
//		return -1;
//
//	if( magicalVector2Equals( l1, l2 ) )
//		return +1;
//
//	return 0;
//}
//
///*-----------------------------------------------------------------------------*\
// * 判断两个直线是否有相交
// *
// * 不平行并且不垂直 就有交点
// *
// * l1 直线1
// * l2 直线2
// * return 是否相交
// *-----------------------------------------------------------------------------*/
//cBool magicalLine2Intersects( const cLine2 l1, const cLine2 l2 )
//{
//	return magicalLine2ClassifyLine2( l1, l2 ) == 0;
//}
//
///*-----------------------------------------------------------------------------*\
// * 判断2D直线是否包含一个2D点 done
// *
// * l 直线
// * point 目标点
// * return 是否包含
// *-----------------------------------------------------------------------------*/
//cBool magicalLine2ContainsPoint( const cLine2 l, const cVector3 point )
//{
//	return magicalAlmostZero( l _x * point _x + l _y * point _y - l _z );
//}
//
