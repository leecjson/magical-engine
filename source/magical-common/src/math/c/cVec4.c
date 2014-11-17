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
#include "cVec4.h"
#include "cMacros.h"

cBoolean magicalVec4Equals( const cVec4 v1, const cVec4 v2 )
{
	return
		magicalFltEqual( v1 _x, v2 _x ) &&
		magicalFltEqual( v1 _y, v2 _y ) &&
		magicalFltEqual( v1 _z, v2 _z ) &&
		magicalFltEqual( v1 _w, v2 _w );
}

cBoolean magicalVec4IsZero( const cVec4 v )
{
	return
		magicalFltIsZero( v _x ) &&
		magicalFltIsZero( v _y ) &&
		magicalFltIsZero( v _z ) &&
		magicalFltIsZero( v _w );
}

cBoolean magicalVec4IsOne( const cVec4 v )
{
	return
		magicalFltEqual( v _x, 1.0f ) &&
		magicalFltEqual( v _y, 1.0f ) &&
		magicalFltEqual( v _z, 1.0f ) &&
		magicalFltEqual( v _w, 1.0f );
}

cBoolean magicalVec4IsNormalize( const cVec4 v )
{
	return magicalFltEqual( v _x * v _x + v _y * v _y + v _z * v _z + v _w * v _w, 1.0f );
}

void magicalVec4FillScalars( cVec4 out, const float x, const float y, const float z, const float w )
{
	out _x = x;
	out _y = y;
	out _z = z;
	out _w = w;
}

void magicalVec4Fill( cVec4 out, const cVec4 v )
{
	out _x = v _x;
	out _y = v _y;
	out _z = v _z;
	out _w = v _w;
}

void magicalVec4FillZero( cVec4 out )
{
	out _x = 0.0f;
	out _y = 0.0f;
	out _z = 0.0f;
	out _w = 0.0f;
}

void magicalVec4FillOne( cVec4 out )
{
	out _x = 1.0f;
	out _y = 1.0f;
	out _z = 1.0f;
	out _w = 1.0f;
}

void magicalVec4AddScalar( cVec4 out, const cVec4 v, const float a )
{
	out _x = v _x + a;
	out _y = v _y + a;
	out _z = v _z + a;
	out _w = v _w + a;
}

void magicalVec4Add( cVec4 out, const cVec4 v1, const cVec4 v2 )
{
	out _x = v1 _x + v2 _x;
	out _y = v1 _y + v2 _y;
	out _z = v1 _z + v2 _z;
	out _w = v1 _w + v2 _w;
}

void magicalVec4SubScalar( cVec4 out, const cVec4 v, const float a )
{
	out _x = v _x - a;
	out _y = v _y - a;
	out _z = v _z - a;
	out _w = v _w - a;
}

void magicalVec4Sub( cVec4 out, const cVec4 v1, const cVec4 v2 )
{
	out _x = v1 _x - v2 _x;
	out _y = v1 _y - v2 _y;
	out _z = v1 _z - v2 _z;
	out _w = v1 _w - v2 _w;
}

void magicalVec4MulScalar( cVec4 out, const cVec4 v, const float a )
{
	out _x = v _x * a;
	out _y = v _y * a;
	out _z = v _z * a;
	out _w = v _w * a;
}

void magicalVec4Mul( cVec4 out, const cVec4 v1, const cVec4 v2 )
{
	out _x = v1 _x * v2 _x;
	out _y = v1 _y * v2 _y;
	out _z = v1 _z * v2 _z;
	out _w = v1 _w * v2 _w;
}

void magicalVec4DivScalar( cVec4 out, const cVec4 v, const float a )
{
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	out _x = v _x / a;
	out _y = v _y / a;
	out _z = v _z / a;
	out _w = v _w / a;
}

void magicalVec4Div( cVec4 out, const cVec4 v1, const cVec4 v2 )
{
	magicalMathAssert( !magicalVec4IsZero( v2 ), "division by 0.f" );

	out _x = v1 _x / v2 _x;
	out _y = v1 _y / v2 _y;
	out _z = v1 _z / v2 _z;
	out _w = v1 _w / v2 _w;
}

float magicalVec4Dot( const cVec4 v1, const cVec4 v2 )
{
	/* 
	 * 返回两个向量的点乘运算
	 * 点乘公式：dot = a.x * b.x + a.y * b.y + a.z * b.z
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
	
	return v1 _x * v2 _x + v1 _y * v2 _y + v1 _z * v2 _z + v1 _w * v2 _w;
}

float magicalVec4DistanceBetween( const cVec4 v1, const cVec4 v2 )
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
	float dz = v2 _z - v1 _z;
	float dw = v2 _w - v1 _w;

	return sqrt( dx * dx + dy * dy + dz * dz + dw * dw );
}

float magicalVec4DistanceBetweenSq( const cVec4 v1, const cVec4 v2 )
{
	/* 
	 * 返回两个点之间距离的平方
	 *
	 * 结果范围：>= 0
	 *      = 0 两点在同一位置
	 */

	float dx = v2 _x - v1 _x;
	float dy = v2 _y - v1 _y;
	float dz = v2 _z - v1 _z;
	float dw = v2 _w - v1 _w;

	return dx * dx + dy * dy + dz * dz + dw * dw;
}

float magicalVec4Length( const cVec4 v )
{
	/* 
	 * 返回这个向量的长度(大小、模)
	 * 勾股定理： a^2 + b^2 = c^2
	 *
	 * 结果范围：>= 0
	 *      = 0 零向量
	 *      = 1 标准化(单位)向量
	 */

	return sqrt( v _x * v _x + v _y * v _y + v _z * v _z + v _w * v _w );
}

float magicalVec4LengthSq( const cVec4 v )
{
	/* 
	 * 返回这个向量长度(大小、模)的平方
	 *
	 * 结果范围：>= 0
	 *      = 0 零向量
	 *      = 1 标准化(单位)向量
	 */

	return v _x * v _x + v _y * v _y + v _z * v _z + v _w * v _w;
}

float magicalVec4AngleBetween( const cVec4 v1, const cVec4 v2 )
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

	magicalMathAssert( !magicalVec4IsZero( v1 ) && !magicalVec4IsZero( v2 ), "invaild operate!" );

	return magicalAcosf( magicalVec4Dot( v1, v2 ) / ( magicalVec4Length( v1 ) * magicalVec4Length( v2 ) ) );
}

void magicalVec4Clamp( cVec4 out, const cVec4 v, const cVec4 min, const cVec4 max )
{
	/* 
	 * 使点参照min与max的位置进行收缩
	 */

	magicalMathAssert( min _x <= max _x && min _y <= max _y && min _z <= max _z && min _w <= max _w, "invaild operate!" );

	out _x = v _x;
	out _y = v _y;
	out _z = v _z;
	out _w = v _w;

	if( out _x < min _x ) out _x = min _x;
	if( out _x > max _x ) out _x = max _x;
	if( out _y < min _y ) out _y = min _y;
	if( out _y > max _y ) out _y = max _y;
	if( out _z < min _z ) out _z = min _z;
	if( out _z > max _z ) out _z = max _z;
	if( out _w < min _w ) out _w = min _w;
	if( out _w > max _w ) out _w = max _w;
}

void magicalVec4Negate( cVec4 out, const cVec4 v )
{
	/* 
	 * 计算向量倒数形式
	 */

	out _x = -v _x;
	out _y = -v _y;
	out _z = -v _z;
	out _w = -v _w;
}

void magicalVec4Normalize( cVec4 out, const cVec4 v )
{
	/* 
	 * 计算标准化向量
	 * 标准化向量公式：normalize = v / length(v)
	 * 
	 * 当向量已经标准化或模接近0，则标准化失败
	 */

	out _x = v _x;
	out _y = v _y;
	out _z = v _z;
	out _w = v _w;

	float n = v _x * v _x + v _y * v _y + v _z * v _z + v _w * v _w;
	if( magicalFltEqual( n, 1.0f ) )
		return;

	n = sqrt( n );
	if( magicalFltIsZero( n ) )
		return;

	n = 1.0f / n;
	out _x *= n;
	out _y *= n;
	out _z *= n;
	out _w *= n;
}

void magicalVec4Scale( cVec4 out, const cVec4 v, const float s )
{
	/* 
	 * 计算与缩放因子的乘积
	 */

	out _x = v _x * s;
	out _y = v _y * s;
	out _z = v _z * s;
	out _w = v _w * s;
}

void magicalVec4MidPointBetween( cVec4 out, const cVec4 v1, const cVec4 v2 )
{
	/* 
	 * 返回由两个点组成的线段的中点
	 * 
	 * 结果范围：任意
	 *     当两点相等时结果也等于原点
	 */

	out _x = ( v1 _x + v2 _x ) * 0.5f;
	out _y = ( v1 _y + v2 _y ) * 0.5f;
	out _z = ( v1 _z + v2 _z ) * 0.5f;
	out _w = ( v1 _w + v2 _w ) * 0.5f;
}

void magicalVec4Project( cVec4 out_h, cVec4 out_v, const cVec4 p, const cVec4 n )
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
	cVec4 normalize;

	magicalMathAssert( !magicalVec4IsZero( n ), "invaild operate!" );
	
	magicalVec4Normalize( normalize, n );
	d = magicalVec4Dot( p, normalize );

	out_h _x = normalize _x * d;
	out_h _y = normalize _y * d;
	out_h _z = normalize _z * d;
	out_h _w = normalize _w * d;

	if( magicalVec4Equals( out_h, p ) )
	{
		out_v _x = 0.0f;
		out_v _y = 0.0f;
		out_v _z = 0.0f;
		out_v _w = 0.0f;
	}
	else
	{
		out_v _x = p _x - out_h _x;
		out_v _y = p _y - out_h _y;
		out_v _z = p _z - out_h _z;
		out_v _w = p _w - out_h _w;
	}
}