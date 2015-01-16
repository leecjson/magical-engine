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
#include "../c/cAABB3.h"
#include "../c/cPlane3.h"
#include "../c/cSphere3.h"
#include "../c/cRay3.h"
#include "Vector3.h"
#include "AABB3.h"
#include "Plane3.h"
#include "Sphere3.h"
#include "Ray3.h"
#include "Ray3.inl"
#include "MathMacros.h"

const Ray3 Ray3::Zero = Ray3( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
Ray3 Ray3::var = Ray3::Zero;

Ray3::Ray3( float ox, float oy, float oz, float dx, float dy, float dz )
{
	magicalRay3Fill( this, ox, oy, oz, dx, dy, dz );
}

Ray3::Ray3( const Ray3& r3 )
{
	magicalRay3Copy( this, &r3 );
}

Ray3::Ray3( void )
{
	magicalRay3SetZero( this );
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Ray3> s_ray3_cached_pool( 32, 32 );
#endif

void* Ray3::operator new( size_t s )
{
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	if( s != sizeof( Ray3 ) )
		return ::operator new( s );

	return s_ray3_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void Ray3::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_ray3_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}

RayIntersectResult::RayIntersectResult( void )
{
	b = false;
	t = 0.0f;
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<RayIntersectResult> s_ray_intersect_result_cached_pool( 32, 32 );
#endif

void* RayIntersectResult::operator new( size_t s )
{
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	if( s != sizeof( RayIntersectResult ) )
		return ::operator new( s );

	return s_ray_intersect_result_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void RayIntersectResult::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_ray_intersect_result_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}