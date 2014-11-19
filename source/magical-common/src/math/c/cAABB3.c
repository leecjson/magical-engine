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
#include "cMacros.h"

void magicalAABB3FillScalars( cAABB out,
	const float min_x, const float min_y, const float min_z,
	const float max_x, const float max_y, const float max_z )
{
	out _min_x = min_x;
	out _min_y = min_y;
	out _min_z = min_z;
	out _max_x = max_x;
	out _max_y = max_y;
	out _max_z = max_z;
}

void magicalAABB3Fill( cAABB out, const cAABB aabb )
{
	out _min_x = aabb _min_x;
	out _min_y = aabb _min_y;
	out _min_z = aabb _min_z;
	out _max_x = aabb _max_x;
	out _max_y = aabb _max_y;
	out _max_z = aabb _max_z;
}

void magicalAABB3FillVec3( cAABB out, const cVec3 min, const cVec3 max )
{
	out _min_x = min _x;
	out _min_y = min _y;
	out _min_z = min _z;
	out _max_x = max _x;
	out _max_y = max _y;
	out _max_z = max _z;
}

void magicalAABB3ExpandScalars( cAABB out, const cAABB aabb, const float x, const float y, const float z )
{
	if( x < aabb _min_x ) out _min_x = x;
	if( y < aabb _min_y ) out _min_y = y;
	if( z < aabb _min_z ) out _min_z = z;
	if( x > aabb _max_x ) out _max_x = x;
	if( y > aabb _max_y ) out _max_y = y;
	if( z > aabb _max_z ) out _max_z = z;
}

void magicalAABB3Expand( cAABB out, const cAABB aabb, const cVec3 v )
{
	if( v _x < aabb _min_x ) out _min_x = v _x;
	if( v _y < aabb _min_y ) out _min_y = v _y;
	if( v _z < aabb _min_z ) out _min_z = v _z;
	if( v _x > aabb _max_x ) out _max_x = v _x;
	if( v _y > aabb _max_y ) out _max_y = v _y;
	if( v _z > aabb _max_z ) out _max_z = v _z;
}

void magicalAABB3Merge( cAABB out, const cAABB aabb1, const cAABB aabb2 )
{
	out _min_x = magicalMin( aabb1 _min_x, aabb2 _min_x );
	out _min_y = magicalMin( aabb1 _min_y, aabb2 _min_y );
	out _min_z = magicalMin( aabb1 _min_z, aabb2 _min_z );
	out _max_x = magicalMax( aabb1 _max_x, aabb2 _max_x );
	out _max_y = magicalMax( aabb1 _max_y, aabb2 _max_y );
	out _max_z = magicalMax( aabb1 _max_z, aabb2 _max_z );
}

void magicalAABB3Center( cVec3 out, const cAABB aabb )
{
	out _x = 0.5f * ( aabb _min_x + aabb _max_x );
	out _y = 0.5f * ( aabb _min_y + aabb _max_y );
	out _z = 0.5f * ( aabb _min_z + aabb _max_z );
}

float magicalAABB3Size( const cAABB aabb )
{
	float x, y, z;
	
	x = aabb _max_x - aabb _min_x;
	y = aabb _max_y - aabb _min_y;
	z = aabb _max_z - aabb _min_z;

	return sqrtf( x * x + y * y + z * z );
}

float magicalAABB3DiameterX( const cAABB aabb )
{
	return aabb _max_x - aabb _min_x;
}

float magicalAABB3DiameterY( const cAABB aabb )
{
	return aabb _max_y - aabb _min_y;
}

float magicalAABB3DiameterZ( const cAABB aabb )
{
	return aabb _max_z - aabb _min_z;
}

cBoolean magicalAABB3Intersects( const cAABB aabb1, const cAABB aabb2 )
{
	return
		( ( aabb1 _min_x >= aabb2 _min_x && aabb1 _min_x <= aabb2 _max_x ) || ( aabb2 _min_x >= aabb1 _min_x && aabb2 _min_x <= aabb1 _max_x ) ) &&
		( ( aabb1 _min_y >= aabb2 _min_y && aabb1 _min_y <= aabb2 _max_y ) || ( aabb2 _min_y >= aabb1 _min_y && aabb2 _min_y <= aabb1 _max_y ) ) &&
		( ( aabb1 _min_z >= aabb2 _min_z && aabb1 _min_z <= aabb2 _max_z ) || ( aabb2 _min_z >= aabb1 _min_z && aabb2 _min_z <= aabb1 _max_z ) );
}

cBoolean magicalAABB3ContainsPoint( const cAABB aabb, const cVec3 point )
{
	return 
		point _x >= aabb _min_x &&
		point _x <= aabb _max_x &&
		point _y >= aabb _min_y &&
		point _y <= aabb _max_y &&
		point _z >= aabb _min_z &&
		point _z <= aabb _max_z;
}

