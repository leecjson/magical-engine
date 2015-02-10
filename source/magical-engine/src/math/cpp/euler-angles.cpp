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
#include "../c/c-euler-angles.h"
#include "../c/c-quaternion.h"
#include "../c/c-matrix3.h"

#include "utility.h"
#include "vector3.h"
#include "euler-angles.h"
#include "quaternion.h"
#include "matrix3.h"

#include "euler-angles.inl"

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "cache-pool.h"
#endif

NS_MAGICAL_BEGIN

const EulerAngles EulerAngles::Zero = EulerAngles( 0.0f, 0.0f, 0.0f );
EulerAngles EulerAngles::var = EulerAngles::Zero;

EulerAngles::EulerAngles( float yaw, float pitch, float roll )
{
	this->yaw = yaw;
	this->pitch = pitch;
	this->roll = roll;
}

EulerAngles::EulerAngles( const EulerAngles& ea )
{
	yaw = ea.yaw;
	pitch = ea.pitch;
	roll = ea.roll;
}

EulerAngles::EulerAngles( void )
{
	yaw = 0.0f;
	pitch = 0.0f;
	roll = 0.0f;
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
static CachePool<EulerAngles> s_eulerangles_cache_pool( 64, 64 );

void* EulerAngles::operator new( size_t s )
{
	if( s != sizeof( EulerAngles ) )
		return ::operator new( s );

	return s_eulerangles_cache_pool.take();
}

void EulerAngles::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
	s_eulerangles_cache_pool.push( ptr );
}
#endif

NS_MAGICAL_END