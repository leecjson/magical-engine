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
#include "Plane3.inl"
#include "MathMacros.h"

const Plane3 Plane3::Zero = Plane3( 0.0f, 0.0f, 0.0f, 0.0f );
const Plane3 Plane3::NormalX = Plane3( 1.0f, 0.0f, 0.0f, 0.0f );
const Plane3 Plane3::NormalY = Plane3( 0.0f, 1.0f, 0.0f, 0.0f );
const Plane3 Plane3::NormalZ = Plane3( 0.0f, 0.0f, 1.0f, 0.0f );

Plane3 Plane3::placeholder = Plane3::Zero;
Plane3 Plane3::temp = Plane3::Zero;

Plane3::Plane3( float x, float y, float z, float d )
{
	magicalPlane3FillScalars( tofpointer( this ), x, y, z, d );
}

Plane3::Plane3( const Plane3& p )
{
	magicalPlane3Fill( tofpointer( this ), tofpointer( &p ) );
}

Plane3::Plane3( void )
: x( 0.0f )
, y( 0.0f )
, z( 0.0f )
, d( 0.0f )
{

}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Plane3> s_plane3_cached_pool( 8, 8 );
#endif

void* Plane3::operator new( size_t s )
{
	if( s != sizeof( Plane3 ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_plane3_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void Plane3::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_plane3_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}