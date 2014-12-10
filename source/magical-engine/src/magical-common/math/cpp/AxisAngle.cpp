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
#include "../c/cAxisAngle.h"
#include "../c/cQuaternion.h"
#include "Vector3.h"
#include "AxisAngle.h"
#include "Quaternion.h"
#include "AxisAngle.inl"
#include "MathMacros.h"

const AxisAngle AxisAngle::Identity = AxisAngle( 0.0f, 0.0f, 1.0f, 0.0f );
const AxisAngle AxisAngle::Zero = AxisAngle( 0.0f, 0.0f, 0.0f, 0.0f );

AxisAngle AxisAngle::placeholder = AxisAngle::Identity;
AxisAngle AxisAngle::temp = AxisAngle::Identity;

AxisAngle::AxisAngle( const float x, const float y, const float z, const float w )
{
	magicalAxisAngleFillScalars( tofpointer( this ), x, y, z, w );
}

AxisAngle::AxisAngle( const Vector3& axis, const float angle )
{
	magicalAxisAngleFillAxisAngleScalars( tofpointer( this ), tofpointer( &axis ), angle );
}

AxisAngle::AxisAngle( const AxisAngle& aa )
{
	magicalAxisAngleFill( tofpointer( this ), tofpointer( &aa ) );
}

AxisAngle::AxisAngle( void )
: x( 0.0f )
, y( 0.0f )
, z( 1.0f )
, w( 0.0f )
{

}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<AxisAngle> s_axisangle_cached_pool( 32, 32 );
#endif

void* AxisAngle::operator new( size_t s )
{
	if( s != sizeof( AxisAngle ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_axisangle_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void AxisAngle::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_axisangle_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}