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
#include "../c/cMatrix4.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"
#include "Vector3.inl"
#include "MathMacros.h"

const Vector4 Vector4::Zero = Vector4( 0.0f, 0.0f, 0.0f, 0.0f );
const Vector4 Vector4::One = Vector4( 1.0f, 1.0f, 1.0f, 1.0f );
const Vector4 Vector4::Up = Vector4( 0.0f, 1.0f, 0.0f, 0.0f );
const Vector4 Vector4::Down = Vector4( 0.0f, -1.0f, 0.0f, 0.0f );
const Vector4 Vector4::Right = Vector4( 1.0f, 0.0f, 0.0f, 0.0f );
const Vector4 Vector4::Left = Vector4( -1.0f, 0.0f, 0.0f, 0.0f );
const Vector4 Vector4::Forward = Vector4( 0.0f, 0.0f, 1.0f, 0.0f );
const Vector4 Vector4::Back = Vector4( 0.0f, 0.0f, -1.0f, 0.0f );
const Vector4 Vector4::Space0 = Vector4( 0.0f, 0.0f, 0.0f, 0.0f );
const Vector4 Vector4::Space1 = Vector4( 0.0f, 0.0f, 0.0f, 1.0f );
const Vector4 Vector4::Space2 = Vector4( 0.0f, 0.0f, 0.0f, 2.0f );

Vector4 Vector4::placeholder = Vector4::Zero;
Vector4 Vector4::temp = Vector4::Zero;

Vector4::Vector4( const float x, const float y, const float z, const float w )
: x( x )
, y( y )
, z( z )
, w( w )
{

}

Vector4::Vector4( const Vector4& v )
: x( v.x )
, y( v.y )
, z( v.z )
, w( v.w )
{

}

Vector4::Vector4( void )
: x( 0.0f )
, y( 0.0f )
, z( 0.0f )
, w( 0.0f )
{

}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Vector4> s_vector4_cached_pool( 32, 32 );
#endif

void* Vector4::operator new( size_t s )
{
	if( s != sizeof( Vector4 ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_vector4_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void Vector4::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_vector4_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}