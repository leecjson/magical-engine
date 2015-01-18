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

const Vector3 Vector3::Zero = Vector3( 0.0f, 0.0f, 0.0f );
const Vector3 Vector3::One = Vector3( 1.0f, 1.0f, 1.0f );
const Vector3 Vector3::Up = Vector3( 0.0f, 1.0f, 0.0f );
const Vector3 Vector3::Down = Vector3( 0.0f, -1.0f, 0.0f );
const Vector3 Vector3::Right = Vector3( 1.0f, 0.0f, 0.0f );
const Vector3 Vector3::Left = Vector3( -1.0f, 0.0f, 0.0f );
const Vector3 Vector3::Forward = Vector3( 0.0f, 0.0f, 1.0f );
const Vector3 Vector3::Back = Vector3( 0.0f, 0.0f, -1.0f );
Vector3 Vector3::var = Vector3::Zero;

Vector3::Vector3( float x, float y, float z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3( const Vector3& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector3::Vector3( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Vector3> s_vector3_cached_pool( 128, 128 );
#endif

void* Vector3::operator new( size_t s )
{
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	if( s != sizeof( Vector3 ) )
		return ::operator new( s );

	return s_vector3_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void Vector3::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_vector3_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}