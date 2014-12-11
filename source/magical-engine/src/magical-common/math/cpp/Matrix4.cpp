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
#include "../c/cVector3.h"
#include "../c/cVector4.h"
#include "../c/cAxisA.h"
#include "../c/cEulerA.h"
#include "../c/cQuaternion.h"
#include "../c/cMatrix4.h"
#include "Vector3.h"
#include "Vector4.h"
#include "AxisA.h"
#include "EulerA.h"
#include "Quaternion.h"
#include "Matrix4.h"
#include "Matrix4.inl"
#include "MathMacros.h"

const Matrix4 Matrix4::Identity = Matrix4(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
);

static const Matrix4 Zero = Matrix4(
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
);

Matrix4 Matrix4::placeholder = Matrix4::Identity;
Matrix4 Matrix4::temp = Matrix4::Identity;

Matrix4::Matrix4( const float* m )
{
	magicalMatrix4Fill( tofpointer( this ), m );
}

Matrix4::Matrix4(
const float rm11, const float rm12, const float rm13, const float rm14,
const float rm21, const float rm22, const float rm23, const float rm24,
const float rm31, const float rm32, const float rm33, const float rm34,
const float rm41, const float rm42, const float rm43, const float rm44 )
{
	magicalMatrix4FillScalars( tofpointer( this ), rm11, rm12, rm13, rm14, rm21, rm22, rm23, rm24, rm31, rm32, rm33, rm34, rm41, rm42, rm43, rm44 );
}

Matrix4::Matrix4( const Matrix4& m )
{
	magicalMatrix4Fill( tofpointer( this ), tofpointer( &m ) );
}

Matrix4::Matrix4( void )
{
	magicalMatrix4FillIdentity( tofpointer( this ) );
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Matrix4> s_matrix4_cached_pool( 32, 32 );
#endif

void* Matrix4::operator new( size_t s )
{
	if( s != sizeof( Matrix4 ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_matrix4_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void Matrix4::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_matrix4_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}