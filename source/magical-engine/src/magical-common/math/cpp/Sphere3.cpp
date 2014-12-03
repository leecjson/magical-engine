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
#include "Sphere3.h"
#include "MathMacros.h"

const Sphere3 Sphere3::One = Sphere3( 0.0f, 0.0f, 0.0f, 1.0f );

Sphere3 Sphere3::placeholder = Sphere3::One;
Sphere3 Sphere3::temp = Sphere3::One;

Sphere3::Sphere3( const float x, const float y, const float z, const float r )
: x( x )
, y( y )
, z( z )
, r( r )
{

}

Sphere3::Sphere3( const Vec3& center, const float r )
: x( center.x )
, y( center.y )
, z( center.z )
, r( r )
{

}

Sphere3::Sphere3( const Sphere3& sp )
: x( sp.x )
, y( sp.y )
, z( sp.z )
, r( sp.r )
{

}

Sphere3::Sphere3( void )
{

}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Sphere3> s_sphere3_cached_pool( 16, 16 );
#endif

void* Sphere3::operator new( size_t s )
{
	if( s != sizeof( Sphere3 ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_sphere3_cached_pool.take();
#else
	void* ptr = malloc( s );

	if( ptr == nullptr )
		throw std::bad_alloc();
	
	return ptr;
#endif
}

void Sphere3::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_sphere3_cached_pool.add( ptr );
#else
	free( ptr );
#endif
}
