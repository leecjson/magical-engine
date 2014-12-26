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

const Matrix4 Matrix4::Zero = Matrix4(
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
);

Matrix4 Matrix4::var = Matrix4::Identity;

Matrix4::Matrix4( const float* m )
{
	magicalMatrix4Copy( this, (Matrix4*)m );
}

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
#include "CachedPool.h"
static CachedPool<Matrix4> s_matrix4_cached_pool( 8, 8 );
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