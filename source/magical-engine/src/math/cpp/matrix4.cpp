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
#include "../c/c-vector3.h"
#include "../c/c-vector4.h"
#include "../c/c-axis-angle.h"
#include "../c/c-euler-angles.h"
#include "../c/c-quaternion.h"
#include "../c/c-matrix3.h"
#include "../c/c-matrix4.h"

#include "utility.h"
#include "vector3.h"
#include "vector4.h"
#include "axis-angle.h"
#include "euler-angles.h"
#include "quaternion.h"
#include "matrix4.h"

#include "matrix4.inl"

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "cache-pool.h"
#endif

NS_MAGICAL_BEGIN

const Matrix4 Matrix4::Identity = Matrix4(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
);

const Matrix4 Matrix4::Zero = Matrix4(
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
);

Matrix4 Matrix4::var = Matrix4::Identity;

Matrix4::Matrix4(
	float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44 )
{
	magicalMatrix4Fill( this, m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44 );
}

Matrix4::Matrix4( const Matrix4& m )
{
	magicalMatrix4Copy( this, &m );
}

Matrix4::Matrix4( void )
{
	magicalMatrix4SetIdentity( this );
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
static CachePool<Matrix4> s_matrix4_cache_pool( 8, 8 );

void* Matrix4::operator new( size_t s )
{
	if( s != sizeof( Matrix4 ) )
		return ::operator new( s );

	return s_matrix4_cache_pool.take();
}

void Matrix4::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
	s_matrix4_cache_pool.push( ptr );
}
#endif

NS_MAGICAL_END