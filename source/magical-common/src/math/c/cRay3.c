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
#include "cRay3.h"

void magicalRay3FillScalars( cRay3 out, const float ox, const float oy, const float oz, const float dx, const float dy, const float dz )
{
	out _o_x = ox;
	out _o_y = oy;
	out _o_z = oz;
	out _d_x = dx;
	out _d_y = dy;
	out _d_z = dz;

	magicalRay3DirectionNormalize( out, out );
}

void magicalRay3FillOriginToEnd( cRay3 out, const cVec3 origin, const cVec3 end )
{
	out _o_x = origin _x;
	out _o_y = origin _y;
	out _o_z = origin _z;
	out _d_x = end _x - origin _x;
	out _d_y = end _y - origin _y;
	out _d_z = end _z - origin _z;

	magicalRay3DirectionNormalize( out, out );
}

void magicalRay3FillOriginAndDirection( cRay3 out, const cVec3 origin, const cVec3 direction )
{
	out _o_x = origin _x;
	out _o_y = origin _y;
	out _o_z = origin _z;
	out _d_x = direction _x;
	out _d_y = direction _y;
	out _d_z = direction _z;

	magicalRay3DirectionNormalize( out, out );
}

void magicalRay3Fill( cRay3 out, const cRay3 r3 )
{
	out _o_x = r3 _o_x;
	out _o_y = r3 _o_y;
	out _o_z = r3 _o_z;
	out _d_x = r3 _d_x;
	out _d_y = r3 _d_y;
	out _d_z = r3 _d_z;
}

void magicalRay3GetOrigin( cVec3 out, const cRay3 r3 )
{
	out _x = r3 _o_x;
	out _y = r3 _o_y;
	out _z = r3 _o_z;
}

void magicalRay3GetDirection( cVec3 out, const cRay3 r3 )
{
	out _x = r3 _d_x;
	out _y = r3 _d_y;
	out _z = r3 _d_z;
}

void magicalRay3SetOrigin( cRay3 out, const cVec3 origin )
{
	out _o_x = origin _x;
	out _o_y = origin _y;
	out _o_z = origin _z;
}

void magicalRay3SetDirection( cRay3 out, const cVec3 direction )
{
	out _d_x = direction _x;
	out _d_y = direction _y;
	out _d_z = direction _z;

	magicalRay3DirectionNormalize( out, out );
}

/*-----------------------------------------------------------------------------*\
 * 标准化射线的方向部分 done
 *
 * out 结果
 * r3 源射线
 *-----------------------------------------------------------------------------*/
void magicalRay3DirectionNormalize( cRay3 out, const cRay3 r3 )
{
	out _d_x = r3 _d_x;
	out _d_y = r3 _d_y;
	out _d_z = r3 _d_z;

	float n = r3 _d_x * r3 _d_x + r3 _d_y * r3 _d_y + r3 _d_z * r3 _d_z;
	if( magicalAlmostEqual( n, 1.0f ) )
		return;

	n = sqrtf( n );
	if( magicalAlmostZero( n ) )
		return;

	n = 1.0f / n;
	out _d_x *= n;
	out _d_y *= n;
	out _d_z *= n;
}

/*-----------------------------------------------------------------------------*\
 * 检测射线与3D平面的相交关系 done
 *
 * r3 源射线
 * p 平面
 * discard_inside 是否忽略原点在平面内的相交检测
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalRay3IntersectsPlane3( const cRay3 r3, const cPlane3 p, const cBool discard_inside )
{
	int cp;
	float dn;
	cVec3 d;

	cp = magicalPlane3ClassifyPoint( p, r3 );
	if( cp == 0 )
	{
		return !discard_inside;
	}

	d _x = r3 _d_x;
	d _y = r3 _d_y;
	d _z = r3 _d_z;

	dn = magicalVec3Dot( d, p );
	if( magicalAlmostZero( dn ) == cFalse )
	{
		if( ( cp == 1 && dn < -MAGICAL_MATH_EPSILON ) || ( cp == -1 && dn > MAGICAL_MATH_EPSILON ) )
		{
			return cTrue;
		}
	}

	return cFalse;
}

/*-----------------------------------------------------------------------------*\
 * 检测射线与轴对齐包围盒的相交关系 done
 *
 * r3 源射线
 * aabb 包围盒
 * discard_inside 是否忽略原点在包围盒内的相交检测
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalRay3IntersectsAABB3( const cRay3 r3, const cAABB3 aabb, const cBool discard_inside )
{
	float t;
	cVec3 p;

	if( r3 _o_x >= aabb _min_x &&
		r3 _o_y >= aabb _min_y &&
		r3 _o_z >= aabb _min_z &&
		r3 _o_x <= aabb _max_x &&
		r3 _o_y <= aabb _max_y &&
		r3 _o_z <= aabb _max_z )
		return !discard_inside;

	if( magicalAlmostZero( r3 _d_x ) == cFalse )
	{
		if( r3 _d_x > 0.0f )
		{
			t = ( aabb _min_x - r3 _o_x ) / r3 _d_x;
		}
		else
		{
			t = ( aabb _max_x - r3 _o_x ) / r3 _d_x;
		}

		if( t > 0.0f )
		{
			p _x = r3 _o_x + r3 _d_x * t;
			p _y = r3 _o_y + r3 _d_y * t;
			p _z = r3 _o_z + r3 _d_z * t;

			if( p _y >= aabb _min_y &&
				p _y <= aabb _max_y &&
				p _z >= aabb _min_z &&
				p _z <= aabb _max_z )
				return cTrue;
		}
	}

	if( magicalAlmostZero( r3 _d_y ) == cFalse )
	{
		if( r3 _d_y > 0.0f )
		{
			t = ( aabb _min_y - r3 _o_y ) / r3 _d_y;
		}
		else
		{
			t = ( aabb _max_y - r3 _o_y ) / r3 _d_y;
		}

		if( t > 0.0f )
		{
			p _x = r3 _o_x + r3 _d_x * t;
			p _y = r3 _o_y + r3 _d_y * t;
			p _z = r3 _o_z + r3 _d_z * t;

			if( p _z >= aabb _min_z &&
				p _z <= aabb _max_z &&
				p _x >= aabb _min_x &&
				p _x <= aabb _max_x )
				return cTrue;
		}
	}

	if( magicalAlmostZero( r3 _d_z ) == cFalse )
	{
		if( r3 _d_z > 0.0f )
		{
			t = ( aabb _min_z - r3 _o_z ) / r3 _d_z;
		}
		else
		{
			t = ( aabb _max_z - r3 _o_z ) / r3 _d_z;
		}

		if( t > 0.0f )
		{
			p _x = r3 _o_x + r3 _d_x * t;
			p _y = r3 _o_y + r3 _d_y * t;
			p _z = r3 _o_z + r3 _d_z * t;

			if( p _x >= aabb _min_x &&
				p _x <= aabb _max_x &&
				p _y >= aabb _min_y &&
				p _y <= aabb _max_y )
				return cTrue;
		}
	}
	
	return cFalse;
}

/*-----------------------------------------------------------------------------*\
 * 检测射线与球体的相交情况 done
 *
 * r3 源射线
 * sp 球体
 * discard_inside 是否忽略原点在球体内的相交检测
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalRay3IntersectsSphere3( const cRay3 r3, const cSphere3 sp, const cBool discard_inside )
{
	cVec3 ve, vd;
	float a, esq, f, fsq;

	magicalRay3GetDirection( vd, r3 );
	magicalVec3Sub( ve, sp, r3 );

	esq = magicalVec3LengthSq( ve );
	if( esq <= sp _r * sp _r )
	{
		return !discard_inside;
	}

	a = magicalVec3Dot( ve, vd );
	fsq = sp _r * sp _r - esq + a * a;

	if( fsq < 0.0f )
	{
		return cFalse;
	}
	else
	{
		return cTrue;
	}
}

/*-----------------------------------------------------------------------------*\
 * 检测射线与3D平面的相交关系，并返回原点到相交点的距离 done
 *
 * dist 距离 相交时有效
 * r3 源射线
 * p 平面
 * discard_inside 是否忽略原点在平面内的相交检测
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalRay3IntersectsPlane3Distance( float* dist, const cRay3 r3, const cPlane3 p, const cBool discard_inside )
{
	int cp;
	float dn;
	cVec3 d;

	cp = magicalPlane3ClassifyPoint( p, r3 );
	if( cp == 0 )
	{
		*dist = 0.0f;
		return !discard_inside;
	}

	d _x = r3 _d_x;
	d _y = r3 _d_y;
	d _z = r3 _d_z;

	dn = magicalVec3Dot( d, p );
	if( magicalAlmostZero( dn ) == cFalse )
	{
		if( ( cp == 1 && dn < -MAGICAL_MATH_EPSILON ) || ( cp == -1 && dn > MAGICAL_MATH_EPSILON ) )
		{
			*dist = ( p _d - magicalVec3Dot( r3, p ) ) / dn;
			return cTrue;
		}
	}

	*dist = 0.0f;
	return cFalse;
}

/*-----------------------------------------------------------------------------*\
 * 检测射线与轴对齐包围盒的相交关系，并返回原点到相交点的距离 done
 *
 * dist 距离 相交时有效
 * r3 源射线
 * aabb 包围盒
 * discard_inside 是否忽略原点在包围盒内的相交检测
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalRay3IntersectsAABB3Distance( float* dist, const cRay3 r3, const cAABB3 aabb, const cBool discard_inside )
{
	float t;
	cVec3 p;

	if( r3 _o_x >= aabb _min_x &&
		r3 _o_y >= aabb _min_y &&
		r3 _o_z >= aabb _min_z &&
		r3 _o_x <= aabb _max_x &&
		r3 _o_y <= aabb _max_y &&
		r3 _o_z <= aabb _max_z )
	{
		*dist = 0.0f;
		return !discard_inside;
	}

	if( magicalAlmostZero( r3 _d_x ) == cFalse )
	{
		if( r3 _d_x > 0.0f )
		{
			t = ( aabb _min_x - r3 _o_x ) / r3 _d_x;
		}
		else
		{
			t = ( aabb _max_x - r3 _o_x ) / r3 _d_x;
		}

		if( t > 0.0f )
		{
			p _x = r3 _o_x + r3 _d_x * t;
			p _y = r3 _o_y + r3 _d_y * t;
			p _z = r3 _o_z + r3 _d_z * t;

			if( p _y >= aabb _min_y &&
				p _y <= aabb _max_y &&
				p _z >= aabb _min_z &&
				p _z <= aabb _max_z )
			{
				*dist = t;
				return cTrue;
			}
		}
	}

	if( magicalAlmostZero( r3 _d_y ) == cFalse )
	{
		if( r3 _d_y > 0.0f )
		{
			t = ( aabb _min_y - r3 _o_y ) / r3 _d_y;
		}
		else
		{
			t = ( aabb _max_y - r3 _o_y ) / r3 _d_y;
		}

		if( t > 0.0f )
		{
			p _x = r3 _o_x + r3 _d_x * t;
			p _y = r3 _o_y + r3 _d_y * t;
			p _z = r3 _o_z + r3 _d_z * t;

			if( p _z >= aabb _min_z &&
				p _z <= aabb _max_z &&
				p _x >= aabb _min_x &&
				p _x <= aabb _max_x )
			{
				*dist = t;
				return cTrue;
			}
		}
	}

	if( magicalAlmostZero( r3 _d_z ) == cFalse )
	{
		if( r3 _d_z > 0.0f )
		{
			t = ( aabb _min_z - r3 _o_z ) / r3 _d_z;
		}
		else
		{
			t = ( aabb _max_z - r3 _o_z ) / r3 _d_z;
		}

		if( t > 0.0f )
		{
			p _x = r3 _o_x + r3 _d_x * t;
			p _y = r3 _o_y + r3 _d_y * t;
			p _z = r3 _o_z + r3 _d_z * t;

			if( p _x >= aabb _min_x &&
				p _x <= aabb _max_x &&
				p _y >= aabb _min_y &&
				p _y <= aabb _max_y )
			{
				*dist = t;
				return cTrue;
			}
				
		}
	}
	
	*dist = 0.0f;
	return cFalse;
}

/*-----------------------------------------------------------------------------*\
 * 检测射线与球体的相交情况，并返回起点到交点的长度 done
 *
 * dist 返回射线到球体相交点的距离 当相交时有效
 *      有可能在原点就已经相交
 * r3 源射线
 * sp 球体
 * discard_inside 是否忽略原点在球体内的相交检测
 * return 是否相交
 *-----------------------------------------------------------------------------*/
cBool magicalRay3IntersectsSphere3Distance( float* dist, const cRay3 r3, const cSphere3 sp, const cBool discard_inside )
{
	cVec3 ve, vd;
	float a, esq, f, fsq;

	magicalRay3GetDirection( vd, r3 );
	magicalVec3Sub( ve, sp, r3 );

	esq = magicalVec3LengthSq( ve );
	if( esq <= sp _r * sp _r )
	{
		*dist = 0.0f;
		return !discard_inside;
	}

	a = magicalVec3Dot( ve, vd );
	fsq = sp _r * sp _r - esq + a * a;

	if( fsq < 0.0f )
	{
		*dist = 0.0f;
		return cFalse;
	}

	f = sqrtf( fsq );
	*dist = a - f;
	return cTrue;
}