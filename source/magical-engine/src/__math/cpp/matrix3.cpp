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
#include "../c/c-matrix3.h"
#include "../c/c-quaternion.h"
#include "../c/c-axis-angle.h"
#include "../c/c-euler-angles.h"

#include "utility.h"
#include "vector3.h"
#include "matrix3.h"
#include "quaternion.h"
#include "axis-angle.h"
#include "euler-angles.h"

#include "matrix3.inl"

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachePool.h"
#endif

NS_MAGICAL_BEGIN

const Matrix3 Matrix3::Identity = Matrix3(
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f );
const Matrix3 Matrix3::Zero = Matrix3(
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f );
Matrix3 Matrix3::var = Matrix3::Identity;

Matrix3::Matrix3( float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33 )
{
	magicalMatrix3Fill( this, m11, m12, m13, m21, m22, m23, m31, m32, m33 );
}

Matrix3::Matrix3( const Matrix3& m )
{
	magicalMatrix3Copy( this, &m );
}

Matrix3::Matrix3( void )
{
	magicalMatrix3SetIdentity( this );
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
static CachePool<Matrix3> s_matrix3_cache_pool( 8, 8 );

void* Matrix3::operator new( size_t s )
{
	if( s != sizeof( Matrix3 ) )
		return ::operator new( s );

	return s_matrix3_cache_pool.take();
}

void Matrix3::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;

	s_matrix3_cache_pool.push( ptr );
}
#endif

NS_MAGICAL_END