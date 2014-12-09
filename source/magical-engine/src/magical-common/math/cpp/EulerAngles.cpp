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
#include "EulerAngles.h"
#include "MathMacros.h"

const EulerAngles EulerAngles::Identity = EulerAngles( 0.0f, 0.0f, 0.0f );

EulerAngles EulerAngles::placeholder = EulerAngles::Identity;
EulerAngles EulerAngles::temp = EulerAngles::Identity;

EulerAngles::EulerAngles( const Matrix4& m )
{
	magicalEulerAnglesFromMatrix4( tofpointer( this ), tofpointer( &m ) );
}

EulerAngles::EulerAngles( const Quaternion& q )
{
	magicalEulerAnglesFromQuaternion( tofpointer( this ), tofpointer( &q ) );
}

EulerAngles::EulerAngles( const EulerAngles& ea )
{
	magicalEulerAnglesFill( tofpointer( this ), tofpointer( &ea ) );
}

EulerAngles::EulerAngles( const float yaw, const float pitch, const float roll )
{
	magicalEulerAnglesFillYawPitchRoll( tofpointer( this ), yaw, pitch, roll );
}

EulerAngles::EulerAngles( void )
: yaw( 0.0f )
, pitch( 0.0f )
, roll( 0.0f )
{

}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<EulerAngles> s_eulerangles_cached_pool( 32, 32 );
#endif

void* EulerAngles::operator new( size_t s )
{
	if( s != sizeof( EulerAngles ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_eulerangles_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void EulerAngles::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_eulerangles_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}