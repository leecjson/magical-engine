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

const Mat4 Mat4::Identity = Mat4(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
);

const Mat4 Mat4::Zero = Mat4(
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
);

Mat4::Mat4(
	float rm11, float rm12, float rm13, float rm14,
	float rm21, float rm22, float rm23, float rm24,
	float rm31, float rm32, float rm33, float rm34,
	float rm41, float rm42, float rm43, float rm44 )
{
	m11 = rm11; m12 = rm12; m13 = rm13; m14 = rm14;
	m21 = rm21; m22 = rm22; m23 = rm23; m24 = rm24;
	m31 = rm31; m32 = rm32; m33 = rm33; m34 = rm34;
	m41 = rm41; m42 = rm42; m43 = rm43; m44 = rm44;
}

Mat4::Mat4( const float* m )
{
	memcpy( this->m, m, kMatrix4x4Size );
}

Mat4::Mat4( const Mat4& mat )
{
	memcpy( m, mat.m, kMatrix4x4Size );
}

Mat4::Mat4( void )
{
	memcpy( m, Identity.m, kMatrix4x4Size );
}

Mat4::~Mat4( void )
{
	
}