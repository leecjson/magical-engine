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
#ifndef __VEC2_HPP__
#define __VEC2_HPP__

#include "Common.h"
#include "kazmath.h"
#include "mat3.hpp"

struct vec2 : public kmVec2
{
public:
	vec2( const float rx, const float ry )
	{
		x = rx;
		y = ry;
	}

	vec2( void )
	{
		x = y = 0.0f;
	}

	inline vec2 operator+( float rhs ) const 
	{
		return vec2( x + rhs, y + rhs );
	}

	inline vec2 operator+( const vec2& rhs ) const
	{
		return vec2( x + rhs.x, y + rhs.y );
	}

	inline vec2 operator-( float rhs ) const
	{
		return vec2( x - rhs, y - rhs );
	}

	inline vec2 operator-( const vec2& rhs ) const
	{
		return vec2( x - rhs.x, y - rhs.y );
	}

	inline vec2 operator*( float rhs ) const
	{
		return vec2( x * rhs, y * rhs );
	}

	inline vec2 operator*( const vec2& rhs ) const
	{
		return vec2( x * rhs.x, y * rhs.y );
	}

	inline vec2 operator/( float rhs ) const
	{
		magicalAssert( rhs, "division by 0.f" );
		return vec2( x / rhs, y / rhs );
	}

	inline vec2 operator/( const vec2& rhs ) const
	{
		magicalAssert( rhs.x && rhs.y, "division by 0.f" );
		return vec2( x / rhs.x, y / rhs.y );
	}

	inline vec2& operator+=( const vec2& rhs )
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	inline vec2& operator+=( float rhs )
	{
		x += rhs;
		y += rhs;
		return *this;
	}

	inline vec2& operator-=( const vec2& rhs )
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	inline vec2& operator-=( float rhs )
	{
		x -= rhs;
		y -= rhs;
		return *this;
	}

	inline vec2& operator*=( const vec2& rhs )
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}

	inline vec2& operator*=( float rhs  )
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}

	inline vec2& operator/=( const vec2& rhs )
	{
		magicalAssert( rhs.x && rhs.y, "division by 0.f" );
		x /= rhs.x;
		y /= rhs.y;
		return *this;
	}

	inline vec2& operator/=( float rhs )
	{
		magicalAssert( rhs, "division by 0.f" );
		x /= rhs;
		y /= rhs;
		return *this;
	}

	inline bool operator==( const vec2& rhs ) const
	{
		return kmVec2AreEqual( this, &rhs ) != 0;
	}

	inline bool operator!=( const vec2& rhs ) const
	{
		return kmVec2AreEqual( this, &rhs ) == 0;
	}

public:
	static inline vec2 fill( const float x, const float y )
	{
		return vec2( x, y );
	};

	static inline float length( const vec2& v )
	{
		return kmVec2Length( &v );
	}

	static inline float lengthSq( const vec2& v )
	{
		return kmVec2LengthSq( &v );
	}

	static inline vec2 normalize( const vec2& v )
	{
		vec2 result;
		kmVec2Normalize( &result, &v );
		return result;
	}

	static inline vec2 lerp( const vec2& v1, const vec2& v2, float t )
	{
		vec2 result;
		kmVec2Lerp( &result, &v1, &v2, t );
		return result;
	}

	static inline float dot( const vec2& v1, const vec2& v2 )
	{
		return kmVec2Dot( &v1, &v2 );
	}

	static inline float cross( const vec2& v1, const vec2& v2 )
	{
		return kmVec2Cross( &v1, &v2 );
	}

	static inline vec2 transform( const vec2& v, const mat3& m )
	{
		vec2 result;
		kmVec2Transform( &result, &v, &m );
		return result;
	}

	static inline vec2 transformCoord( const vec2& v, const mat3& m )
	{
		vec2 result;
		kmVec2TransformCoord( &result, &v, &m );
		return result;
	}

	static inline vec2 scale( const vec2& v, const float s )
	{
		vec2 result;
		kmVec2Scale( &result, &v, s );
		return result;
	}

	static inline vec2 rotateBy( const vec2& v, const float degrees, const vec2& center )
	{
		vec2 result;
		kmVec2RotateBy( &result, &v, degrees, &center );
		return result;
	}

	static inline float degreesBetween( const vec2& v1, const vec2& v2 )
	{
		return kmVec2DegreesBetween( &v1, &v2 );
	}

	static inline float distanceBetween( const vec2& v1, const vec2& v2 )
	{
		return kmVec2DistanceBetween( &v1, &v2 );
	}

	static inline vec2 midPointBetween( const vec2& v1, const vec2& v2 )
	{
		vec2 result;
		kmVec2MidPointBetween( &result, &v1, &v2 );
		return result;
	}

public:
	static const vec2 ZERO;
};

static inline vec2 operator*( const float lhs, const vec2& rhs )
{
	return rhs * lhs;
};

#endif //__VEC2_HPP__