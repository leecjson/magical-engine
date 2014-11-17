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
#include <exception>

const Vec4 Vec4::Zero = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
const Vec4 Vec4::One = Vec4( 1.0f, 1.0f, 1.0f, 1.0f );
const Vec4 Vec4::Up = Vec4( 0.0f, 1.0f, 0.0f, 0.0f );
const Vec4 Vec4::Down = Vec4( 0.0f, -1.0f, 0.0f, 0.0f );
const Vec4 Vec4::Right = Vec4( 1.0f, 0.0f, 0.0f, 0.0f );
const Vec4 Vec4::Left = Vec4( -1.0f, 0.0f, 0.0f, 0.0f );
const Vec4 Vec4::Forward = Vec4( 0.0f, 0.0f, 1.0f, 0.0f );
const Vec4 Vec4::Back = Vec4( 0.0f, 0.0f, -1.0f, 0.0f );
const Vec4 Vec4::Space1 = Vec4( 0.0f, 0.0f, 0.0f, 1.0f );

Vec4 Vec4::placeholder_1 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::placeholder_2 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::placeholder_3 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::temp = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::temp_1 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::temp_2 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::temp_3 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::temp_4 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::temp_5 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::temp_6 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::temp_7 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::temp_8 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );
Vec4 Vec4::temp_9 = Vec4( 0.0f, 0.0f, 0.0f, 0.0f );

Vec4::Vec4( const float x, const float y, const float z, const float w )
: x( x )
, y( y )
, z( z )
, w( w )
{

}

Vec4::Vec4( const Vec4& v )
: x( v.x )
, y( v.y )
, z( v.z )
, w( v.w )
{

}

Vec4::Vec4( void )
: x( 0.0f )
, y( 0.0f )
, z( 0.0f )
, w( 0.0f )
{

}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Vec4> s_vec4_cached_pool( 1024, 1024 );
#endif

void* Vec4::operator new( size_t s )
{
	if( s != sizeof( Vec4 ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_vec4_cached_pool.take();
#else
	void* ptr = malloc( s );

	if( ptr == nullptr )
		throw std::bad_alloc();
	
	return ptr;
#endif
}

void Vec4::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_vec4_cached_pool.add( ptr );
#else
	free( ptr );
#endif
}