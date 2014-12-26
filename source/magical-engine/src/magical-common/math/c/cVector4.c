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

cBool magicalVector4Equals( const cVector4* v1, const cVector4* v2 )
{
	return
		magicalAlmostEqual( v1->x, v2->x, kEpsilonVector4 ) &&
		magicalAlmostEqual( v1->y, v2->y, kEpsilonVector4 ) &&
		magicalAlmostEqual( v1->z, v2->z, kEpsilonVector4 ) &&
		magicalAlmostEqual( v1->w, v2->w, kEpsilonVector4 );
}

cBool magicalVector4IsZero( const cVector4* v )
{
	return
		magicalAlmostZero( v->x, kEpsilonVector4 ) &&
		magicalAlmostZero( v->y, kEpsilonVector4 ) &&
		magicalAlmostZero( v->z, kEpsilonVector4 ) &&
		magicalAlmostZero( v->w, kEpsilonVector4 );
}

cBool magicalVector4IsOne( const cVector4* v )
{
	return
		magicalAlmostEqual( v->x, 1.0f, kEpsilonVector4 ) &&
		magicalAlmostEqual( v->y, 1.0f, kEpsilonVector4 ) &&
		magicalAlmostEqual( v->z, 1.0f, kEpsilonVector4 ) &&
		magicalAlmostEqual( v->w, 1.0f, kEpsilonVector4 );
}

cBool magicalVector4IsNormalized( const cVector4* v )
{
	return magicalAlmostEqual( v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w, 1.0f, kEpsilonVector4 );
}

void magicalVector4Fill( cVector4* out, float x, float y, float z, float w )
{
	out->x = x;
	out->y = y;
	out->z = z;
	out->w = w;
}

void magicalVector4Copy( cVector4* out, const cVector4* v )
{
	out->x = v->x;
	out->y = v->y;
	out->z = v->z;
	out->w = v->w;
}

void magicalVector4SetZero( cVector4* out )
{
	out->x = 0.0f;
	out->y = 0.0f;
	out->z = 0.0f;
	out->w = 0.0f;
}

void magicalVector4SetOne( cVector4* out )
{
	out->x = 1.0f;
	out->y = 1.0f;
	out->z = 1.0f;
	out->w = 1.0f;
}

void magicalVector4FromVector2( cVector4* out, const cVector2* v )
{
	out->x = v->x;
	out->y = v->y;
	out->z = 0.0f;
	out->w = 0.0f;
}

void magicalVector4FromVector3( cVector4* out, const cVector3* v )
{
	out->x = v->x;
	out->y = v->y;
	out->z = v->z;
	out->w = 0.0f;
}

void magicalVector4AddScalar( cVector4* out, const cVector4* v, float a )
{
	out->x = v->x + a;
	out->y = v->y + a;
	out->z = v->z + a;
	out->w = v->w + a;
}

void magicalVector4Add( cVector4* out, const cVector4* v1, const cVector4* v2 )
{
	out->x = v1->x + v2->x;
	out->y = v1->y + v2->y;
	out->z = v1->z + v2->z;
	out->w = v1->w + v2->w;
}

void magicalVector4SubScalar( cVector4* out, const cVector4* v, float a )
{
	out->x = v->x - a;
	out->y = v->y - a;
	out->z = v->z - a;
	out->w = v->w - a;
}

void magicalVector4Sub( cVector4* out, const cVector4* v1, const cVector4* v2 )
{
	out->x = v1->x - v2->x;
	out->y = v1->y - v2->y;
	out->z = v1->z - v2->z;
	out->w = v1->w - v2->w;
}

void magicalVector4MulScalar( cVector4* out, const cVector4* v, float a )
{
	out->x = v->x * a;
	out->y = v->y * a;
	out->z = v->z * a;
	out->w = v->w * a;
}

void magicalVector4Mul( cVector4* out, const cVector4* v1, const cVector4* v2 )
{
	out->x = v1->x * v2->x;
	out->y = v1->y * v2->y;
	out->z = v1->z * v2->z;
	out->w = v1->w * v2->w;
}

void magicalVector4DivScalar( cVector4* out, const cVector4* v, float a )
{
	debugassert( !magicalAlmostZero( a, kEpsilonVector4 ), "division by 0.f" );

	out->x = v->x / a;
	out->y = v->y / a;
	out->z = v->z / a;
	out->w = v->w / a;
}

void magicalVector4Div( cVector4* out, const cVector4* v1, const cVector4* v2 )
{
	debugassert( !magicalVector4IsZero( v2 ), "division by 0.f" );

	out->x = v1->x / v2->x;
	out->y = v1->y / v2->y;
	out->z = v1->z / v2->z;
	out->w = v1->w / v2->w;
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
float magicalVector4Dot( const cVector4* v1, const cVector4* v2 )
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z + v1->w * v2->w;
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
float magicalVector4DistanceBetween( const cVector4* v1, const cVector4* v2 )
{
	float dx = v2->x - v1->x;
	float dy = v2->y - v1->y;
	float dz = v2->z - v1->z;
	float dw = v2->w - v1->w;

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
float magicalVector4DistanceBetweenSq( const cVector4* v1, const cVector4* v2 )
{
	float dx = v2->x - v1->x;
	float dy = v2->y - v1->y;
	float dz = v2->z - v1->z;
	float dw = v2->w - v1->w;

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
float magicalVector4Length( const cVector4* v )
{
	return sqrtf( v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w );
}

/*-----------------------------------------------------------------------------*\
 * 返回这个向量长度(大小、模)的平方 done
 *
 * v 求模平方向量
 * return v模平方 >= 0
 *         = 0 零向量
 *         = 1 标准化(单位)向量
 *-----------------------------------------------------------------------------*/
float magicalVector4LengthSq( const cVector4* v )
{
	return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
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
float magicalVector4AngleBetween( const cVector4* v1, const cVector4* v2 )
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
void magicalVector4Clamp( cVector4* out, const cVector4* v, const cVector4* min, const cVector4* max )
{
	debugassert( min->x <= max->x && min->y <= max->y && min->z <= max->z && min->w <= max->w, "invaild operate!" );

	out->x = v->x;
	out->y = v->y;
	out->z = v->z;
	out->w = v->w;

	if( out->x < min->x ) out->x = min->x;
	if( out->x > max->x ) out->x = max->x;
	if( out->y < min->y ) out->y = min->y;
	if( out->y > max->y ) out->y = max->y;
	if( out->z < min->z ) out->z = min->z;
	if( out->z > max->z ) out->z = max->z;
	if( out->w < min->w ) out->w = min->w;
	if( out->w > max->w ) out->w = max->w;
}

/*-----------------------------------------------------------------------------*\
 * 计算向量的倒数形式 done
 *
 * out 结果 v = -v
 * v 源向量
 *-----------------------------------------------------------------------------*/
void magicalVector4Negate( cVector4* out, const cVector4* v )
{
	out->x = -v->x;
	out->y = -v->y;
	out->z = -v->z;
	out->w = -v->w;
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
void magicalVector4Normalize( cVector4* out, const cVector4* v )
{
	out->x = v->x;
	out->y = v->y;
	out->z = v->z;
	out->w = v->w;

	float n = v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
	if( magicalAlmostEqual( n, 1.0f, kEpsilonVector4 ) )
		return;

	n = sqrtf( n );
	if( magicalAlmostZero( n, kEpsilonVector4 ) )
		return;

	n = 1.0f / n;
	out->x *= n;
	out->y *= n;
	out->z *= n;
	out->w *= n;
}

/*-----------------------------------------------------------------------------*\
 * 计算向量的缩放 done
 *
 * out 缩放后的向量
 * v 源向量
 * s 缩放系数
 *-----------------------------------------------------------------------------*/
void magicalVector4Scale( cVector4* out, const cVector4* v, float s )
{
	out->x = v->x * s;
	out->y = v->y * s;
	out->z = v->z * s;
	out->w = v->w * s;
}

/*-----------------------------------------------------------------------------*\
 * 返回由两个点组成的线段的中点 done
 *
 * out 返回中点 当两点相等时中点也等于原点
 * v1 向量1
 * v2 向量2
 *-----------------------------------------------------------------------------*/
void magicalVector4MidPointBetween( cVector4* out, const cVector4* v1, const cVector4* v2 )
{
	out->x = ( v1->x + v2->x ) * 0.5f;
	out->y = ( v1->y + v2->y ) * 0.5f;
	out->z = ( v1->z + v2->z ) * 0.5f;
	out->w = ( v1->w + v2->w ) * 0.5f;
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
void magicalVector4Project( cVector4* out, const cVector4* p, const cVector4* n )
{
	float d;
	cVector4 normalize;

	debugassert( !magicalVector4IsZero( n ), "invaild operate!" );
	
	magicalVector4Normalize( &normalize, n );
	d = magicalVector4Dot( p, &normalize );

	out->x = normalize.x * d;
	out->y = normalize.y * d;
	out->z = normalize.z * d;
	out->w = normalize.w * d;
}