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
#include "Vec2.h"
#include <exception>

const Vec2 Vec2::Zero = Vec2( 0.0f, 0.0f );
const Vec2 Vec2::One = Vec2( 1.0f, 1.0f );
const Vec2 Vec2::Right = Vec2( 1.0f, 0.0f );
const Vec2 Vec2::Left = Vec2( -1.0f, 0.0f );
const Vec2 Vec2::Up = Vec2( 0.0f, 1.0f );
const Vec2 Vec2::Down = Vec2( 0.0f, -1.0f );

Vec2 Vec2::placeholder_1 = Vec2( 0.0f, 0.0f );
Vec2 Vec2::placeholder_2 = Vec2( 0.0f, 0.0f );
Vec2 Vec2::placeholder_3 = Vec2( 0.0f, 0.0f );
Vec2 Vec2::temp = Vec2( 0.0f, 0.0f );
Vec2 Vec2::temp_1 = Vec2( 0.0f, 0.0f );
Vec2 Vec2::temp_2 = Vec2( 0.0f, 0.0f );
Vec2 Vec2::temp_3 = Vec2( 0.0f, 0.0f );
Vec2 Vec2::temp_4 = Vec2( 0.0f, 0.0f );
Vec2 Vec2::temp_5 = Vec2( 0.0f, 0.0f );
Vec2 Vec2::temp_6 = Vec2( 0.0f, 0.0f );
Vec2 Vec2::temp_7 = Vec2( 0.0f, 0.0f );
Vec2 Vec2::temp_8 = Vec2( 0.0f, 0.0f );
Vec2 Vec2::temp_9 = Vec2( 0.0f, 0.0f );

Vec2::Vec2( const float x, const float y )
: x( x )
, y( y )
{

}

Vec2::Vec2( const Vec2& v )
: x( v.x )
, y( v.y )
{
	
}

Vec2::Vec2( void )
: x( 0.0f )
, y( 0.0f )
{
	
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Vec2> s_vec2_cached_pool( 1024, 1024 );
#endif

void* Vec2::operator new( size_t s )
{
	if( s != sizeof( Vec2 ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_vec2_cached_pool.take();
#else
	void* ptr = malloc( s );

	if( ptr == nullptr )
		throw std::bad_alloc();
	
	return ptr;
#endif
}

void Vec2::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_vec2_cached_pool.add( ptr );
#else
	free( ptr );
#endif
}

