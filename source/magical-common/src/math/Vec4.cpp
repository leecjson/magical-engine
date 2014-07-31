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
#include "Vec4.h"

const Vec4 Vec4::ZERO = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );

Vec4::Vec4( float rx, float ry, float rz, float rw )
: x(rx)
, y(ry)
, z(rz)
, w(rw)
{
	
}

Vec4::Vec4( const float* rhs )
: x(rhs[0])
, y(rhs[1])
, z(rhs[2])
, w(rhs[3])
{

}

Vec4::Vec4( const Vec4& rhs )
: x(rhs.x)
, y(rhs.y)
, z(rhs.z)
, w(rhs.w)
{

}

Vec4::Vec4( void )
: x(0.0f)
, y(0.0f)
, z(0.0f)
, w(0.0f)
{
	
}