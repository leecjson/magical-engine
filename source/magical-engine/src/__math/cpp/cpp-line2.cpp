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
#include "../c/cVector2.h"
#include "../c/cLine2.h"
#include "Vector2.h"
#include "Line2.h"
#include "Line2.inl"
#include "MathMacros.h"

const Line2 Line2::Zero = Line2( 0.0f, 0.0f, 0.0f );

Line2 Line2::placeholder = Line2::Zero;
Line2 Line2::temp = Line2::Zero;

Line2::Line2( float x, float y, float d )
{
	magicalLine2FillScalars( tofpointer( this ), x, y, d );
}

Line2::Line2( const Line2& l )
{
	magicalLine2Fill( tofpointer( this ), tofpointer( &l ) );
}

Line2::Line2( void )
: x( 0.0f )
, y( 0.0f )
, d( 0.0f )
{

}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Line2> s_line2_cached_pool( 16, 16 );
#endif

void* Line2::operator new( size_t s )
{
	if( s != sizeof( Line2 ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_line2_cached_pool.take();
#else
	return ::operator new( s );
#endif
}

void Line2::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_line2_cached_pool.push( ptr );
#else
	return ::operator delete( ptr );
#endif
}