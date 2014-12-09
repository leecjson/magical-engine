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
#include "cVector4.h"
#include "cMathMacros.h"

cBool magicalVector4Equals( const cVector4 v1, const cVector4 v2 )
{
	return
		magicalAlmostEqual( v1 _x, v2 _x ) &&
		magicalAlmostEqual( v1 _y, v2 _y ) &&
		magicalAlmostEqual( v1 _z, v2 _z ) &&
		magicalAlmostEqual( v1 _w, v2 _w );
}

cBool magicalVector4IsZero( const cVector4 v )
{
	return
		magicalAlmostZero( v _x ) &&
		magicalAlmostZero( v _y ) &&
		magicalAlmostZero( v _z ) &&
		magicalAlmostZero( v _w );
}

cBool magicalVector4IsOne( const cVector4 v )
{
	return
		magicalAlmostEqual( v _x, 1.0f ) &&
		magicalAlmostEqual( v _y, 1.0f ) &&
		magicalAlmostEqual( v _z, 1.0f ) &&
		magicalAlmostEqual( v _w, 1.0f );
}

cBool magicalVector4IsNormalized( const cVector4 v )
{
	return magicalAlmostEqual( v _x * v _x + v _y * v _y + v _z * v _z + v _w * v _w, 1.0f );
}

void magicalVector4FillScalars( cVector4 out, const float x, const float y, const float z, const float w )
{
	out _x = x;
	out _y = y;
	out _z = z;
	out _w = w;
}

void magicalVector4FillZero( cVector4 out )
{
	out _x = 0.0f;
	out _y = 0.0f;
	out _z = 0.0f;
	out _w = 0.0f;
}

void magicalVector4FillOne( cVector4 out )
{
	out _x = 1.0f;
	out _y = 1.0f;
	out _z = 1.0f;
	out _w = 1.0f;
}

void magicalVector4Fill( cVector4 out, const cVector4 v )
{
	out _x = v _x;
	out _y = v _y;
	out _z = v _z;
	out _w = v _w;
}

void magicalVector4FromVector2( cVector4 out, const cVector2 v )
{
	out _x = v _x;
	out _y = v _y;
	out _z = 0.0f;
	out _w = 0.0f;
}

void magicalVector4FromVector3( cVector4 out, const cVector3 v )
{
	out _x = v _x;
	out _y = v _y;
	out _z = v _z;
	out _w = 0.0f;
}

void magicalVector4AddScalar( cVector4 out, const cVector4 v, const float a )
{
	out _x = v _x + a;
	out _y = v _y + a;
	out _z = v _z + a;
	out _w = v _w + a;
}

void magicalVector4Add( cVector4 out, const cVector4 v1, const cVector4 v2 )
{
	out _x = v1 _x + v2 _x;
	out _y = v1 _y + v2 _y;
	out _z = v1 _z + v2 _z;
	out _w = v1 _w + v2 _w;
}

void magicalVector4SubScalar( cVector4 out, const cVector4 v, const float a )
{
	out _x = v _x - a;
	out _y = v _y - a;
	out _z = v _z - a;
	out _w = v _w - a;
}

void magicalVector4Sub( cVector4 out, const cVector4 v1, const cVector4 v2 )
{
	out _x = v1 _x - v2 _x;
	out _y = v1 _y - v2 _y;
	out _z = v1 _z - v2 _z;
	out _w = v1 _w - v2 _w;
}

void magicalVector4MulScalar( cVector4 out, const cVector4 v, const float a )
{
	out _x = v _x * a;
	out _y = v _y * a;
	out _z = v _z * a;
	out _w = v _w * a;
}

void magicalVector4Mul( cVector4 out, const cVector4 v1, const cVector4 v2 )
{
	out _x = v1 _x * v2 _x;
	out _y = v1 _y * v2 _y;
	out _z = v1 _z * v2 _z;
	out _w = v1 _w * v2 _w;
}

void magicalVector4DivScalar( cVector4 out, const cVector4 v, const float a )
{
	debugassert( !magicalAlmostZero( a ), "division by 0.f" );

	out _x = v _x / a;
	out _y = v _y / a;
	out _z = v _z / a;
	out _w = v _w / a;
}

void magicalVector4Div( cVector4 out, const cVector4 v1, const cVector4 v2 )
{
	debugassert( !magicalVector4IsZero( v2 ), "division by 0.f" );

	out _x = v1 _x / v2 _x;
	out _y = v1 _y / v2 _y;
	out _z = v1 _z / v2 _z;
	out _w = v1 _w / v2 _w;
}

/*-----------------------------------------------------------------------------*\
 * 返回两个向量的点乘运算 done
 * 
 * 点乘公式：dot(a,b) = a.x*b.x + a.y*b.y
 *
 * 点乘结果等于向量长度与向量夹角的cos值的积
 * 点乘夹角公式：dot(a,b) = length(a) * length(b) * cos(theta)
 *
 * 在3D中两向量的夹角是在包含两向量的平面中定义的
 *
 * v1 向量1
 * v2 向量2
 * return 点乘结果
 *        > 0 两向量接近同一方向
 *        = 0 两向量垂直
 *        < 0 两向量接近相反方向
 *-----------------------------------------------------------------------------*/
float magicalVector4Dot( const cVector4 v1, const cVector4 v2 )
{
	return v1 _x * v2 _x + v1 _y * v2 _y + v1 _z * v2 _z + v1 _w * v2 _w;
}

/*-----------------------------------------------------------------------------*\
 * 返回两个点之间的距离(a向量到b向量的距离) done
 * 
 * 距离公式：distance(a,b) = length(d);
 * 其中向量d = b-a
 *
 * v1 向量1
 * v2 向量2
 * return 距离>= 0 当距离=0时 两点在同一位置，或者说两向量大小相同
 *-----------------------------------------------------------------------------*/
float magicalVector4DistanceBetween( const cVector4 v1, const cVector4 v2 )
{
	float dx = v2 _x - v1 _x;
	float dy = v2 _y - v1 _y;
	float dz = v2 _z - v1 _z;
	float dw = v2 _w - v1 _w;

	return sqrtf( dx * dx + dy * dy + dz * dz + dw * dw );
}

/*-----------------------------------------------------------------------------*\
 * 返回两个点之间距离的平方 done
 *
 * v1 向量1
 * v2 向量2
 * return v1到v2的距离 >= 0 
 *        = 0时 两点在同一位置，或者说两向量大小相同
 *-----------------------------------------------------------------------------*/
float magicalVector4DistanceBetweenSq( const cVector4 v1, const cVector4 v2 )
{
	float dx = v2 _x - v1 _x;
	float dy = v2 _y - v1 _y;
	float dz = v2 _z - v1 _z;
	float dw = v2 _w - v1 _w;

	return dx * dx + dy * dy + dz * dz + dw * dw;
}

/*-----------------------------------------------------------------------------*\
 * 返回这个向量的长度(大小、模) done
 *
 * 求模公式 length = sqrt(a^2 + b^2 + ... n^2)
 *
 * v 求模向量
 * return v的模 >= 0
 *        = 0 零向量
 *        = 1 标准化(单位)向量
 *-----------------------------------------------------------------------------*/
float magicalVector4Length( const cVector4 v )
{
	return sqrtf( v _x * v _x + v _y * v _y + v _z * v _z + v _w * v _w );
}

/*-----------------------------------------------------------------------------*\
 * 返回这个向量长度(大小、模)的平方 done
 *
 * v 求模平方向量
 * return v模平方 >= 0
 *         = 0 零向量
 *         = 1 标准化(单位)向量
 *-----------------------------------------------------------------------------*/
float magicalVector4LengthSq( const cVector4 v )
{
	return v _x * v _x + v _y * v _y + v _z * v _z + v _w * v _w;
}

/*-----------------------------------------------------------------------------*\
 * 返回两个向量之间的夹角(弧度单位) done
 * 
 * 参考点乘夹角公式
 * 转换：theta = acos( dot(a,b) / length(a) * length(b) )
 *
 * 两个参与运算的向量都不能为零向量
 *
 * v1 向量1
 * v2 向量2
 * return 夹角弧度 >=0 and <= PI
 *        = 0 两向量方向一致
 *-----------------------------------------------------------------------------*/
float magicalVector4AngleBetween( const cVector4 v1, const cVector4 v2 )
{
	debugassert( !magicalVector4IsZero( v1 ) && !magicalVector4IsZero( v2 ), "invaild operate!" );

	return magicalSafeAcos( magicalVector4Dot( v1, v2 ) / ( magicalVector4Length( v1 ) * magicalVector4Length( v2 ) ) );
}

/*-----------------------------------------------------------------------------*\
 * 使点参照min与max的位置进行收缩 done
 *
 * out 结果 min <= out <= max
 * v 源向量
 * min 小值
 * max 大值
 *-----------------------------------------------------------------------------*/
void magicalVector4Clamp( cVector4 out, const cVector4 v, const cVector4 min, const cVector4 max )
{
	debugassert( min _x <= max _x && min _y <= max _y && min _z <= max _z && min _w <= max _w, "invaild operate!" );

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

/*-----------------------------------------------------------------------------*\
 * 计算向量的倒数形式 done
 *
 * out 结果 v = -v
 * v 源向量
 *-----------------------------------------------------------------------------*/
void magicalVector4Negate( cVector4 out, const cVector4 v )
{
	out _x = -v _x;
	out _y = -v _y;
	out _z = -v _z;
	out _w = -v _w;
}

/*-----------------------------------------------------------------------------*\
 * 计算向量的标准化 done
 * 
 * 向量标准化公式：normalize(a) = a / length(a)
 *
 * 当向量已经标准化或模接近0，则标准化失败
 *
 * out 结果 out = normalize(v)
 * v 源向量
 *-----------------------------------------------------------------------------*/
void magicalVector4Normalize( cVector4 out, const cVector4 v )
{
	out _x = v _x;
	out _y = v _y;
	out _z = v _z;
	out _w = v _w;

	float n = v _x * v _x + v _y * v _y + v _z * v _z + v _w * v _w;
	if( magicalAlmostEqual( n, 1.0f ) )
		return;

	n = sqrtf( n );
	if( magicalAlmostZero( n ) )
		return;

	n = 1.0f / n;
	out _x *= n;
	out _y *= n;
	out _z *= n;
	out _w *= n;
}

/*-----------------------------------------------------------------------------*\
 * 计算向量的缩放 done
 *
 * out 缩放后的向量
 * v 源向量
 * s 缩放系数
 *-----------------------------------------------------------------------------*/
void magicalVector4Scale( cVector4 out, const cVector4 v, const float s )
{
	out _x = v _x * s;
	out _y = v _y * s;
	out _z = v _z * s;
	out _w = v _w * s;
}

/*-----------------------------------------------------------------------------*\
 * 返回由两个点组成的线段的中点 done
 *
 * out 返回中点 当两点相等时中点也等于原点
 * v1 向量1
 * v2 向量2
 *-----------------------------------------------------------------------------*/
void magicalVector4MidPointBetween( cVector4 out, const cVector4 v1, const cVector4 v2 )
{
	out _x = ( v1 _x + v2 _x ) * 0.5f;
	out _y = ( v1 _y + v2 _y ) * 0.5f;
	out _z = ( v1 _z + v2 _z ) * 0.5f;
	out _w = ( v1 _w + v2 _w ) * 0.5f;
}

/*-----------------------------------------------------------------------------*\
 * 计算向量p到向量n的投影，结果由向量out(平行于n)返回 done
 * 
 * 投影结果满足 p = h + v
 *
 * 平行投影向量公式：h = n * ( dot(p,n) / lengthSq(n) )
 * 如果n为单位向量 ：h = n * ( dot(p,n) )
 * 垂直投影向量公式：v = p - h;
 *
 * 向量p或向量n为零向量时投影无意义
 *
 * 如果向量p与向量n方向一致，则 h = p, v = 0
 * 
 * out 平行与n的投影分量
 * p 源向量
 * n 投影目标向量
 *-----------------------------------------------------------------------------*/
void magicalVector4Project( cVector4 out, const cVector4 p, const cVector4 n )
{
	float d;
	cVector4 normalize;

	debugassert( !magicalVector4IsZero( n ), "invaild operate!" );
	
	magicalVector4Normalize( normalize, n );
	d = magicalVector4Dot( p, normalize );

	out _x = normalize _x * d;
	out _y = normalize _y * d;
	out _z = normalize _z * d;
	out _w = normalize _w * d;
}