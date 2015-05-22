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
#include "../c/c-vector3.h"
#include "../c/c-axis-angle.h"
#include "../c/c-quaternion.h"
#include "../c/c-matrix3.h"

#include "utility.h"
#include "vector3.h"
#include "axis-angle.h"
#include "quaternion.h"
#include "matrix3.h"

#include "axis-angle.inl"

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachePool.h"
#endif

NS_MAGICAL_BEGIN

const AxisAngle AxisAngle::Identity = AxisAngle( 0.0f, 0.0f, 1.0f, 0.0f );
const AxisAngle AxisAngle::Zero = AxisAngle( 0.0f, 0.0f, 0.0f, 0.0f );
AxisAngle AxisAngle::var = AxisAngle::Identity;

AxisAngle::AxisAngle( float x, float y, float z, float w )
{
	magicalAxisAngleFill( this, x, y, z, w );
}

AxisAngle::AxisAngle( const Vector3& axis, float angle )
{
	magicalAxisAngleFill( this, axis.x, axis.y, axis.z, angle );
}

AxisAngle::AxisAngle( const AxisAngle& aa )
{
	magicalAxisAngleCopy( this, &aa );
}

AxisAngle::AxisAngle( void )
{
	magicalAxisAngleSetIdentity( this );
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
static CachePool<AxisAngle> s_axis_angle_cache_pool( 32, 32 );

void* AxisAngle::operator new( size_t s )
{
	if( s != sizeof( AxisAngle ) )
		return ::operator new( s );

	return s_axis_angle_cache_pool.take();
}

void AxisAngle::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
	s_axis_angle_cache_pool.push( ptr );
}
#endif

NS_MAGICAL_END