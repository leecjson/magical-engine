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
#include "../c/cVector2.h"

#include "Utility.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include "Vector2.inl"

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachePool.h"
#endif

NS_MAGICAL_BEGIN

const Vector2 Vector2::Zero = Vector2( 0.0f, 0.0f );
const Vector2 Vector2::One = Vector2( 1.0f, 1.0f );
const Vector2 Vector2::Right = Vector2( 1.0f, 0.0f );
const Vector2 Vector2::Left = Vector2( -1.0f, 0.0f );
const Vector2 Vector2::Up = Vector2( 0.0f, 1.0f );
const Vector2 Vector2::Down = Vector2( 0.0f, -1.0f );
Vector2 Vector2::var = Vector2::Zero;

Vector2::Vector2( float x, float y )
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2( const Vector2& v )
{
	x = v.x;
	y = v.y;
}

Vector2::Vector2( void )
{
	x = 0.0f;
	y = 0.0f;
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
static CachePool<Vector2> s_vector2_cache_pool( 128, 128 );
#endif

void* Vector2::operator new( size_t s )
{
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	if( s != sizeof( Vector2 ) )
		return ::operator new( s );

	return s_vector2_cache_pool.take();
#else
	return ::operator new( s );
#endif
}

void Vector2::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_vector2_cache_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}

NS_MAGICAL_END