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
#include "cMacros.h"

void magicalPlane3FillScalars( cPlane3 out, const float x, const float y, const float z, const float d )
{
	out _x = x;
	out _y = y;
	out _z = z;
	out _d = d;
}

void magicalPlane3Fill( cPlane3 out, const cPlane3 p )
{
	out _x = p _x;
	out _y = p _y;
	out _z = p _z;
	out _d = p _d;
}

void magicalPlane3FillNormalAndDistance( cPlane3 out, const cVec3 n, const float d )
{
	out _x = n _x;
	out _y = n _y;
	out _z = n _z;
	out _d = d;
}

void magicalPlane3FillPointAndNormal( cPlane3 out, const cVec3 p, const cVec3 n )
{
	out _x = n _x;
	out _y = n _y;
	out _z = n _z;
	out _d = p _x * n _x + p _y * n _y + p _z * n _z;
}

void magicalPlane3FillPoints( cPlane3 out, const cVec3 a, const cVec3 b, const cVec3 c )
{
	cVec3 n, v1, v2;
	
	v1 _x = b _x - a _x;
	v1 _y = b _y - a _y;
	v1 _z = b _z - a _z;

	v2 _x = c _x - b _x;
	v2 _y = c _y - b _y;
	v2 _z = c _z - b _z;

	magicalVec3Cross( n, v1, v2 );
	magicalVec3Normalize( n, n );

	out _x = n _x;
	out _y = n _y;
	out _z = n _z;
	out _d = a _x * n _x + a _y * n _y + a _z * n _z;
}

void magicalPlane3SetNormal( cPlane3 out, const cVec3 n )
{
	out _x = n _x;
	out _y = n _y;
	out _z = n _z;
}

void magicalPlane3GetNormal( cVec3 out, const cPlane3 p )
{
	out _x = p _x;
	out _y = p _y;
	out _z = p _z;
}

void magicalPlane3ClassifyPoint( const cPlane3 p, const cVec3 v )
{

}