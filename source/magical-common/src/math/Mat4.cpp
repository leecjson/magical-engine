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
#include "Mat4.h"

const Mat4 Mat4::IDENTITY = Mat4(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
);

const Mat4 Mat4::ZERO = Mat4(
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
);

Mat4::Mat4( float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44 )
{
	mat[0]  = m11; mat[1]  = m21; mat[2]  = m31; mat[3]  = m41;
	mat[4]  = m12; mat[5]  = m22; mat[6]  = m32; mat[7]  = m42;
	mat[8]  = m13; mat[9]  = m23; mat[10] = m33; mat[11] = m43;
	mat[12] = m14; mat[13] = m24; mat[14] = m34; mat[15] = m44;
}

Mat4::Mat4( const float* m )
{
	memcpy( this->mat, m, kMat4Size );
}

Mat4::Mat4( const Mat4& m )
{
	memcpy( this->mat, m.mat, kMat4Size );
}

Mat4::Mat4( void )
{
	memcpy( this, &IDENTITY, kMat4Size );
}

Mat4::~Mat4( void )
{
	
}