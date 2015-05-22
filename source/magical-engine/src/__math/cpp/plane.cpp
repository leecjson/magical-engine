﻿/******************************************************************************
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
#include "../c/c-aabb3.h"
#include "../c/c-plane.h"
#include "../c/c-sphere.h"
#include "../c/c-ray3.h"

#include "utility.h"
#include "vector3.h"
#include "aabb3.h"
#include "plane.h"
#include "sphere.h"
#include "ray3.h"

#include "plane.inl"

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachePool.h"
#endif

NS_MAGICAL_BEGIN

const Plane Plane::Zero = Plane( 0.0f, 0.0f, 0.0f, 0.0f );
const Plane Plane::NormalX = Plane( 1.0f, 0.0f, 0.0f, 0.0f );
const Plane Plane::NormalY = Plane( 0.0f, 1.0f, 0.0f, 0.0f );
const Plane Plane::NormalZ = Plane( 0.0f, 0.0f, 1.0f, 0.0f );
Plane Plane::var = Plane::Zero;

Plane::Plane( float x, float y, float z, float d )
{
	magicalPlaneFill( this, x, y, z, d );
}

Plane::Plane( const Plane& p )
{
	magicalPlaneCopy( this, &p );
}

Plane::Plane( void )
{
	magicalPlaneSetZero( this );
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
static CachePool<Plane> s_plane_cache_pool( 8, 8 );

void* Plane::operator new( size_t s )
{
	if( s != sizeof( Plane ) )
		return ::operator new( s );

	return s_plane_cache_pool.take();
}

void Plane::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
	s_plane_cache_pool.push( ptr );
}
#endif

NS_MAGICAL_END