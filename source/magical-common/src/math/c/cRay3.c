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