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
#include "cVec2.h"
#include "cMacros.h"

cBoolean magicalVec2Equals( const cVec2 v1, const cVec2 v2 )
{
	return magicalFltEqual( v1 _x, v2 _x ) && magicalFltEqual( v1 _y, v2 _y );
}

cBoolean magicalVec2IsZero( const cVec2 v )
{
	return magicalFltIsZero( v _x ) && magicalFltIsZero( v _y );
}

cBoolean magicalVec2IsOne( const cVec2 v )
{
	return magicalFltEqual( v _x, 1.0f ) && magicalFltEqual( v _y, 1.0f );
}

cBoolean magicalVec2IsNormalize( const cVec2 v )
{
	return magicalFltEqual( v _x * v _x + v _y * v _y, 1.0f );
}

void magicalVec2FillScalars( cVec2 out, const float x, const float y )
{
	out _x = x;
	out _y = y;
}

void magicalVec2FillZero( cVec2 out )
{
	out _x = 0.0f;
	out _y = 0.0f;
}

void magicalVec2FillOne( cVec2 out )
{
	out _x = 1.0f;
	out _y = 1.0f;
}

void magicalVec2Fill( cVec2 out, const cVec2 v )
{
	out _x = v _x;
	out _y = v _y;
}

void magicalVec2FromVec3( cVec2 out, const cVec3 v )
{
	out _x = v _x;
	out _y = v _y;
}

void magicalVec2FromVec4( cVec2 out, const cVec4 v )
{
	out _x = v _x;
	out _y = v _y;
}

void magicalVec2AddScalar( cVec2 out, const cVec2 v, const float a )
{
	out _x = v _x + a;
	out _y = v _y + a;
}

void magicalVec2Add( cVec2 out, const cVec2 v1, const cVec2 v2 )
{
	out _x = v1 _x + v2 _x;
	out _y = v1 _y + v2 _y;
}

void magicalVec2SubScalar( cVec2 out, const cVec2 v, const float a )
{
	out _x = v _x - a;
	out _y = v _y - a;
}

void magicalVec2Sub( cVec2 out, const cVec2 v1, const cVec2 v2 )
{
	out _x = v1 _x - v2 _x;
	out _y = v1 _y - v2 _y;
}

void magicalVec2MulScalar( cVec2 out, const cVec2 v, const float a )
{
	out _x = v _x * a;
	out _y = v _y * a;
}

void magicalVec2Mul( cVec2 out, const cVec2 v1, const cVec2 v2 )
{
	out _x = v1 _x * v2 _x;
	out _y = v1 _y * v2 _y;
}

void magicalVec2DivScalar( cVec2 out, const cVec2 v, const float a )
{
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	out _x = v _x / a;
	out _y = v _y / a;
}

void magicalVec2Div( cVec2 out, const cVec2 v1, const cVec2 v2 )
{
	magicalMathAssert( !magicalFltIsZero( v2 _x ) && !magicalFltIsZero( v2 _y ), "division by 0.f" );

	out _x = v1 _x / v2 _x;
	out _y = v1 _y / v2 _y;
}

float magicalVec2Dot( const cVec2 v1, const cVec2 v2 )
{
	/* 
	 * 返回两个向量的点乘运算
	 * 点乘公式：dot = a.x * b.x + a.y * b.y
	 * 点乘结果等于向量长度与向量夹角的cos值的积
	 * 点乘夹角公式：dot = length(a) * length(b) * cos(angle)
	 *
	 * 在3D中两向量的夹角是在包含两向量的平面中定义的
	 *
	 * 结果范围：任意
	 *      > 0 两向量方向即将接近
	 *      = 0 两向量垂直
	 *      < 0 两向量反向即将相反
	 */
	
	return v1 _x * v2 _x + v1 _y * v2 _y;
}

float magicalVec2DistanceBetween( const cVec2 v1, const cVec2 v2 )
{
	/* 
	 * 返回两个点之间的距离(a到b的向量d的长度)
	 * 距离公式：distance = length(b - a)
	 *
	 * 其中b - a为，a到b的向量d
	 *
	 * 结果范围：>= 0
	 *      = 0 两点在同一位置
	 */

	float dx = v2 _x - v1 _x;
	float dy = v2 _y - v1 _y;

	return sqrtf( dx * dx + dy * dy );
}

float magicalVec2DistanceBetweenSq( const cVec2 v1, const cVec2 v2 )
{
	/* 
	 * 返回两个点之间距离的平方
	 *
	 * 结果范围：>= 0
	 *      = 0 两点在同一位置
	 */

	float dx = v2 _x - v1 _x;
	float dy = v2 _y - v1 _y;

	return dx * dx + dy * dy;
}

float magicalVec2Length( const cVec2 v )
{
	/* 
	 * 返回这个向量的长度(大小、模)
	 * 勾股定理： a^2 + b^2 = c^2
	 *
	 * 结果范围：>= 0
	 *      = 0 零向量
	 *      = 1 标准化(单位)向量
	 */

	return sqrtf( v _x * v _x + v _y * v _y );
}

float magicalVec2LengthSq( const cVec2 v )
{
	/* 
	 * 返回这个向量长度(大小、模)的平方
	 *
	 * 结果范围：>= 0
	 *      = 0 零向量
	 *      = 1 标准化(单位)向量
	 */

	return v _x * v _x + v _y * v _y;
}

float magicalVec2AngleBetween( const cVec2 v1, const cVec2 v2 )
{
	/* 
	 * 返回两个向量之间的夹角(弧度单位)
	 * 点乘夹角公式：a.dot(b) = length(a) * length(b) * cos(angle)
	 * 转换：angle = acos((a.dot(b)) / length(a) * length(b))
	 * 
	 * 两个参与运算的向量都不能为零向量
	 *
	 * 结果范围：0 <= 结果 <= PI 两向量的夹角(弧度单位)
	 *      = 0 两向量方向一致
	 */

	magicalMathAssert( !magicalVec2IsZero( v1 ) && !magicalVec2IsZero( v2 ), "invaild operate!" );

	return magicalAcosf( magicalVec2Dot( v1, v2 ) / ( magicalVec2Length( v1 ) * magicalVec2Length( v2 ) ) );
}

void magicalVec2Clamp( cVec2 out, const cVec2 v, const cVec2 min, const cVec2 max )
{
	/* 
	 * 使点参照min与max的位置进行收缩
	 */

	magicalMathAssert( min _x <= max _x && min _y <= max _y, "invaild operate!" );

	out _x = v _x;
	out _y = v _y;

	if( out _x < min _x ) out _x = min _x;
	if( out _x > max _x ) out _x = max _x;
	if( out _y < min _y ) out _y = min _y;
	if( out _y > max _y ) out _y = max _y;
}

void magicalVec2Negate( cVec2 out, const cVec2 v )
{
	/* 
	 * 计算向量倒数形式
	 */

	out _x = -v _x;
	out _y = -v _y;
}

void magicalVec2Normalize( cVec2 out, const cVec2 v )
{
	/* 
	 * 计算标准化向量
	 * 标准化向量公式：normalize = v / length(v)
	 * 
	 * 当向量已经标准化或模接近0，则标准化失败
	 */

	out _x = v _x;
	out _y = v _y;

	float n = v _x * v _x + v _y * v _y;
	if( magicalFltEqual( n, 1.0f ) )
		return;

	n = sqrtf( n );
	if( magicalFltIsZero( n ) )
		return;

	n = 1.0f / n;
	out _x *= n;
	out _y *= n;
}

void magicalVec2Rotate( cVec2 out, const cVec2 v, const cVec2 point, const float angle )
{
	/* 
	 * 计算以point为中心点旋转angle(弧度)之后的向量
	 */

	float rx;
	float ry;
	float sin_angle = magicalSinf( angle );
	float cos_angle = magicalCosf( angle );

	if( magicalVec2IsOne( point ) )
	{
		rx = v _x * cos_angle - v _y * sin_angle;
		ry = v _y * cos_angle + v _x * sin_angle;
		out _x = rx;
		out _y = ry;
	}
	else
	{
		rx = v _x - point _x;
		ry = v _y - point _y;
		out _x = rx * cos_angle - ry * sin_angle + point _x;
		out _y = ry * cos_angle + rx * sin_angle + point _y;
	}
}

void magicalVec2Scale( cVec2 out, const cVec2 v, const float s )
{
	/* 
	 * 计算与缩放因子的乘积
	 */

	out _x = v _x * s;
	out _y = v _y * s;
}

void magicalVec2MidPointBetween( cVec2 out, const cVec2 v1, const cVec2 v2 )
{
	/* 
	 * 返回由两个点组成的线段的中点
	 * 
	 * 结果范围：任意
	 *     当两点相等时结果也等于原点
	 */

	out _x = ( v1 _x + v2 _x ) * 0.5f;
	out _y = ( v1 _y + v2 _y ) * 0.5f;
}

void magicalVec2Project( cVec2 out_h, cVec2 out_v, const cVec2 p, const cVec2 n )
{
	/* 
	 * 计算向量p到向量n的投影，结果由向量h(平行于n)和向量v(垂直于n)返回
	 * 投影结果满足 p = h + v
	 *
	 * 平行投影向量公式：h = n * (p.dot(n) / lengthSq(n))
	 * 如果n为单位向量 ：h = n * (p.dot(n))
	 * 垂直投影向量公式：v = p - h;
	 *
	 * 向量p或向量n为零向量时投影无意义
	 *
	 * 如果向量p与向量n方向一致，则 h = p, v = 0
	 */

	float d;
	cVec2 normalize;

	magicalMathAssert( !magicalVec2IsZero( n ), "invaild operate!" );
	
	magicalVec2Normalize( normalize, n );
	d = magicalVec2Dot( p, normalize );

	out_h _x = normalize _x * d;
	out_h _y = normalize _y * d;

	if( magicalVec2Equals( out_h, p ) )
	{
		out_v _x = 0.0f;
		out_v _y = 0.0f;
	}
	else
	{
		out_v _x = p _x - out_h _x;
		out_v _y = p _y - out_h _y;
	}
}