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
#include "../c/cVector3.h"
#include "../c/cAxisAngle.h"
#include "../c/cQuaternion.h"
#include "Vector3.h"
#include "AxisAngle.h"
#include "Quaternion.h"
#include "AxisAngle.inl"
#include "MathMacros.h"

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
#include "CachedPool.h"
static CachedPool<AxisAngle> s_axisag_cached_pool( 32, 32 );
#endif

void* AxisAngle::operator new( size_t s )
{
	if( s != sizeof( AxisAngle ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_axisag_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void AxisAngle::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_axisag_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}