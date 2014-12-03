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
#include "MathMacros.h"

const Mat4 Mat4::Identity = Mat4(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
);

Mat4 Mat4::placeholder = Mat4::Identity;
Mat4 Mat4::temp = Mat4::Identity;

Mat4::Mat4( const float* m )
{
	magicalMat4FillVector( tofpointer( this ), m );
}

Mat4::Mat4( const Mat4& m )
{
	magicalMat4Fill( tofpointer( this ), tofpointer( &m ) );
}

Mat4::Mat4( const float rm11, const float rm12, const float rm13, const float rm14,
            const float rm21, const float rm22, const float rm23, const float rm24,
            const float rm31, const float rm32, const float rm33, const float rm34,
            const float rm41, const float rm42, const float rm43, const float rm44 )
{
	magicalMat4FillScalars(
		tofpointer( this ),
		rm11, rm12, rm13, rm14,
		rm21, rm22, rm23, rm24,
		rm31, rm32, rm33, rm34,
		rm41, rm42, rm43, rm44 
		);
}

Mat4::Mat4( void )
{
	magicalMat4FillIdentity( tofpointer( this ) );
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Mat4> s_mat4_cached_pool( 32, 32 );
#endif

void* Mat4::operator new( size_t s )
{
	if( s != sizeof( Mat4 ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_mat4_cached_pool.take();
#else
	void* ptr = malloc( s );

	if( ptr == nullptr )
		throw std::bad_alloc();
	
	return ptr;
#endif
}

void Mat4::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_mat4_cached_pool.add( ptr );
#else
	free( ptr );
#endif
}