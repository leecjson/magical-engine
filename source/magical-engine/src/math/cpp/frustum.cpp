/******************************************************************************
The MIT License (MIT)

Copyright (c) 2014 Jason.lee

Permission is hereby granted, free of chaage, to any person obtaining a copy
of this softwaae and associated documentation files (the "Softwaae"), to deal
in the Softwaae without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Softwaae, and to permit persons to whom the Softwaae is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Softwaae.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/
#include "../c/c-frustum.h"
#include "../c/c-matrix4.h"
#include "../c/c-plane.h"
#include "../c/c-aabb3.h"

#include "utility.h"
#include "frustum.h"
#include "matrix4.h"
#include "plane.h"
#include "aabb3.h"

#include "frustum.inl"

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachePool.h"
#endif

NS_MAGICAL_BEGIN

Frustum::Frustum( const Frustum& frustum )
{
	magicalFrustumCopy( this, &frustum );
}

Frustum::Frustum( void )
{
	magicalFrustumSetZero( this );
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
static CachePool<Frustum> s_frustum_cache_pool( 2, 2 );

void* Frustum::operator new( size_t s )
{
	if( s != sizeof( Frustum ) )
		return ::operator new( s );

	return s_frustum_cache_pool.take();
}

void Frustum::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
	s_frustum_cache_pool.push( ptr );
}
#endif

NS_MAGICAL_END
