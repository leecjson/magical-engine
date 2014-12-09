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
#include "Plane3.h"
#include "MathMacros.h"

const Plane3 Plane3::NormalX = Plane3( 1.0f, 0.0f, 0.0f, 0.0f );
const Plane3 Plane3::NormalY = Plane3( 0.0f, 1.0f, 0.0f, 0.0f );
const Plane3 Plane3::NormalZ = Plane3( 0.0f, 0.0f, 1.0f, 0.0f );

Plane3 Plane3::placeholder = Plane3::NormalX;
Plane3 Plane3::temp = Plane3::NormalX;

Plane3::Plane3( const float x, const float y, const float z, const float d )
{
	magicalPlane3FillScalars( tofpointer( this ), x, y, z, d );
}

Plane3::Plane3( const Vector3& a, const Vector3& b, const Vector3& c )
{
	fillPoints( a, b, c );
}

Plane3::Plane3( const Vector3& a, const Vector3& n )
{
	fillPointAndNormal( a, n );
}

Plane3::Plane3( const Vector3& n, const float d )
{
	magicalPlane3FillNormalAndDistance( tofpointer( this ), tofpointer( &n ), d );
}

Plane3::Plane3( const Plane3& p )
: x( p.x )
, y( p.y )
, z( p.z )
, d( p.d )
{

}

Plane3::Plane3( void )
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
	void* ptr = malloc( s );

	if( ptr == nullptr )
		throw std::bad_alloc();
	
	return ptr;
#endif
}

void Plane3::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_plane3_cached_pool.add( ptr );
#else
	free( ptr );
#endif
}
