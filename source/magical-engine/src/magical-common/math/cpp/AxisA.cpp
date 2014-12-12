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
#include "../c/cAxisA.h"
#include "../c/cQuaternion.h"
#include "Vector3.h"
#include "AxisA.h"
#include "Quaternion.h"
#include "AxisA.inl"
#include "MathMacros.h"

const AxisA AxisA::Identity = AxisA( 0.0f, 0.0f, 1.0f, 0.0f );
const AxisA AxisA::Zero = AxisA( 0.0f, 0.0f, 0.0f, 0.0f );

AxisA AxisA::placeholder = AxisA::Identity;
AxisA AxisA::temp = AxisA::Identity;

AxisA::AxisA( const float x, const float y, const float z, const float w )
{
	magicalAxisAFillScalars( tofpointer( this ), x, y, z, w );
}

AxisA::AxisA( const Vector3& axis, const float angle )
{
	magicalAxisASetAxis( tofpointer( this ), tofpointer( &axis ) );
	magicalAxisASetAngle( tofpointer( this ), angle );
}

AxisA::AxisA( const AxisA& aa )
{
	magicalAxisAFill( tofpointer( this ), tofpointer( &aa ) );
}

AxisA::AxisA( void )
: x( 0.0f )
, y( 0.0f )
, z( 1.0f )
, w( 0.0f )
{

}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<AxisA> s_axisa_cached_pool( 32, 32 );
#endif

void* AxisA::operator new( size_t s )
{
	if( s != sizeof( AxisA ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_axisa_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void AxisA::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_axisa_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}