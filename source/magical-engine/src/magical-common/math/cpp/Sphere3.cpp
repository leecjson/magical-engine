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
#include "../c/cSphere3.h"
#include "../c/cPlane3.h"
#include "../c/cRay3.h"
#include "Vector3.h"
#include "AABB3.h"
#include "Sphere3.h"
#include "Plane3.h"
#include "Ray3.h"
#include "Sphere3.inl"
#include "MathMacros.h"

const Sphere3 Sphere3::Zero = Sphere3( 0.0f, 0.0f, 0.0f, 0.0f );
const Sphere3 Sphere3::One = Sphere3( 0.0f, 0.0f, 0.0f, 1.0f );
Sphere3 Sphere3::var = Sphere3::Zero;

Sphere3::Sphere3( float x, float y, float z, float r )
{
	magicalSphere3Fill( this, x, y, z, r );
}

Sphere3::Sphere3( const Sphere3& sp )
{
	magicalSphere3Copy( this, &sp );
}

Sphere3::Sphere3( void )
{
	magicalSphere3SetZero( this );
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Sphere3> s_sphere3_cached_pool( 16, 16 );
#endif

void* Sphere3::operator new( size_t s )
{
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	if( s != sizeof( Sphere3 ) )
		return ::operator new( s );

	return s_sphere3_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void Sphere3::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_sphere3_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}
