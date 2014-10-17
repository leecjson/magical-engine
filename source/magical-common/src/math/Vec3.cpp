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
#include "Vec3.h"

const Vec3 Vec3::Zero = Vec3( 0.0f, 0.0f, 0.0f );
const Vec3 Vec3::One = Vec3( 1.0f, 1.0f, 1.0f );
const Vec3 Vec3::Up = Vec3( 0.0f, 1.0f, 0.0f );
const Vec3 Vec3::Down = Vec3( 0.0f, -1.0f, 0.0f );
const Vec3 Vec3::Right = Vec3( 1.0f, 0.0f, 0.0f );
const Vec3 Vec3::Left = Vec3( -1.0f, 0.0f, 0.0f );
const Vec3 Vec3::Forward = Vec3( 0.0f, 0.0f, 1.0f );
const Vec3 Vec3::Back = Vec3( 0.0f, 0.0f, -1.0f );

Vec3::Vec3( float rx, float ry, float rz )
: x( rx )
, y( ry )
, z( rz )
{
	
}

Vec3::Vec3( const Vec3& rhs )
: x( rhs.x )
, y( rhs.y )
, z( rhs.z )
{

}

Vec3::Vec3( void )
: x( 0.0f )
, y( 0.0f )
, z( 0.0f )
{

}


