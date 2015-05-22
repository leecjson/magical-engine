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
#include "../c/c-matrix4.h"
#include "../c/c-aabb3.h"
#include "../c/c-ray3.h"
#include "../c/c-plane.h"
#include "../c/c-sphere.h"
#include "../c/c-frustum.h"

#include "utility.h"
#include "vector3.h"
#include "matrix4.h"
#include "aabb3.h"
#include "ray3.h"
#include "plane.h"
#include "sphere.h"
//#include "frustum.h"

#include "AABB3.inl"

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachePool.h"
#endif

NS_MAGICAL_BEGIN

const AABB3 AABB3::Zero = AABB3( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
AABB3 AABB3::var = AABB3::Zero;

AABB3::AABB3( float minx, float miny, float minz, float maxx, float maxy, float maxz )
{
	magicalAABB3Fill( this, minx, miny, minz, maxx, maxy, maxz );
}

AABB3::AABB3( const Vector3& min, const Vector3& max )
{
	magicalAABB3Fill( this, min.x, min.y, min.z, max.x, max.y, max.z );
}

AABB3::AABB3( const AABB3& aabb )
{
	magicalAABB3Copy( this, &aabb );
}

AABB3::AABB3( void )
{
	magicalAABB3SetZero( this );
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
static CachePool<AABB3> s_aabb3_cache_pool( 16, 16 );

void* AABB3::operator new( size_t s )
{
	if( s != sizeof( AABB3 ) )
		return ::operator new( s );

	return s_aabb3_cache_pool.take();
}

void AABB3::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
	s_aabb3_cache_pool.push( ptr );
}
#endif



NS_MAGICAL_END