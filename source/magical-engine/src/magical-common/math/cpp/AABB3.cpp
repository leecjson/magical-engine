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
#include "AABB3.h"
#include "MathMacros.h"

const AABB3 AABB3::Zero = AABB3( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );

AABB3::AABB3( const float min_x, const float min_y, const float min_z, const float max_x, const float max_y, const float max_z )
: min_x( min_x )
, min_y( min_y )
, min_z( min_z )
, max_x( max_x )
, max_y( max_y )
, max_z( max_z )
{

}

AABB3::AABB3( const Vector3& min, const Vector3& max )
: min_x( min.x )
, min_y( min.y )
, min_z( min.z )
, max_x( max.x )
, max_y( max.y )
, max_z( max.z )
{

}

AABB3::AABB3( const Vector3& center, const float width, const float height, const float depth )
{
	magicalAABB3FillBox( tofpointer( this ), tofpointer( &center ), width, height, depth );
}

AABB3::AABB3( const AABB3& aabb )
: min_x( aabb.min_x )
, min_y( aabb.min_y )
, min_z( aabb.min_z )
, max_x( aabb.max_x )
, max_y( aabb.max_y )
, max_z( aabb.max_z )
{

}


AABB3::AABB3( void )
: min_x( 0.0f )
, min_y( 0.0f )
, min_z( 0.0f )
, max_x( 0.0f )
, max_y( 0.0f )
, max_z( 0.0f )
{

}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<AABB3> s_aabb3_cached_pool( 16, 16 );
#endif

void* AABB3::operator new( size_t s )
{
	if( s != sizeof( AABB3 ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_aabb3_cached_pool.take();
#else
	void* ptr = malloc( s );

	if( ptr == nullptr )
		throw std::bad_alloc();
	
	return ptr;
#endif
}

void AABB3::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_aabb3_cached_pool.add( ptr );
#else
	free( ptr );
#endif
}