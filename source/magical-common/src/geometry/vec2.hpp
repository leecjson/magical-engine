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

typedef kmVec2 vec2;

inline float vec2Length( const vec2 )

//
//struct vec2
//{
//public:
//	float x;
//	float y;
//
//public:
//	vec2( void ): x(0.0f), y(0.0f)
//	{
//
//	}
//
//	vec2( const float _x, const float _y )
//	{
//		x = _x;
//		y = _y;
//	}
//	
//	inline const float length( void ) const
//	{
//		return kmVec2Length( (kmVec2*)this );
//	}
//
//	// Returns the square of the length of the vector
//	inline const float lengthSq( void ) const
//	{
//		return kmVec2LengthSq( (kmVec2*)this );
//	}
//
//	// Returns the vector passed in set to unit length
//	inline const vec2 normalize( void ) const
//	{
//		vec2 result;
//		kmVec2Normalize( (kmVec2*)(&result), (kmVec2*)this );
//		return result;
//	}
//
//	// Transform the Vector
//	inline const vec2 transform( const kmMat3& mat ) const
//	{
//		vec2 result;
//		kmVec2Transform( (kmVec2*)(&result), (kmVec2*)this, &mat );
//		return result;
//	}
//
//	// Transforms a 3D vector by a given matrix, projecting the result back into w = 1.
//	inline const vec2 transformCoord( const kmMat3& mat ) const
//	{
//		vec2 result;
//		kmVec2TransformCoord( (kmVec2*)(&result), (kmVec2*)this, &mat );
//		return result;
//	}
//
//	inline const float dot( const vec2& rhs ) const
//	{
//		return kmVec2Dot( (kmVec2*)this, (kmVec2*)&rhs );
//	}
//
//	inline const float cross( const vec2& rhs ) const
//	{
//		return kmVec2Cross( (kmVec2*)this, (kmVec2*)(&rhs) );
//	}
//
//	inline vec2 operator+( const vec2& rhs ) const
//	{
//		return vec2( x + rhs.x, y + rhs.y );
//	}
//
//	inline vec2 operator+( float rhs ) const 
//	{
//		return vec2( x + rhs, y + rhs );
//	}
//
//	inline vec2& operator+=( const vec2& rhs )
//	{
//		x += rhs.x;
//		y += rhs.y;
//		return *this;
//	}
//
//	inline vec2& operator+=( float rhs )
//	{
//		x += rhs;
//		y += rhs;
//		return *this;
//	}
//
//	inline vec2 operator-( const vec2& rhs ) const
//	{
//		return vec2( x - rhs.x, y - rhs.y );
//	}
//
//	inline vec2& operator-=( const vec2& rhs )
//	{
//		x -= rhs.x;
//		y -= rhs.y;
//		return *this;
//	}
//
//	inline vec2& operator-=( float rhs )
//	{
//		x -= rhs;
//		y -= rhs;
//		return *this;
//	}
//
//	inline vec2 operator*( const vec2& rhs ) const
//	{
//		return vec2( x * rhs.x, y * rhs.y );
//	}
//
//	inline vec2 operator*( float rhs ) const
//	{
//		return vec2( x * rhs, y * rhs );
//	}
//
//	inline vec2& operator*=( const vec2& rhs )
//	{
//		x *= rhs.x;
//		y *= rhs.y;
//		return *this;
//	}
//
//	inline vec2& operator*=( float rhs  )
//	{
//		x *= rhs;
//		y *= rhs;
//		return *this;
//	}
//
//	inline vec2 operator/( const vec2& rhs ) const
//	{
//		magicalAssert( rhs.x && rhs.y, "division by 0.f" );
//		return vec2( x / rhs.x, y / rhs.y );
//	}
//
//	inline vec2 operator/( float rhs ) const
//	{
//		magicalAssert( rhs, "division by 0.f" );
//		return vec2( x / rhs, y / rhs );
//	}
//
//	inline vec2& operator/=( const vec2& rhs )
//	{
//		magicalAssert( rhs.x && rhs.y, "division by 0.f" );
//		x /= rhs.x;
//		y /= rhs.y;
//		return *this;
//	}
//
//	inline vec2& operator/=( float rhs  )
//	{
//		magicalAssert( rhs, "division by 0.f" );
//		x /= rhs;
//		y /= rhs;
//		return *this;
//	}
//};
//
//// Multiply with scalar
//inline const vec2 operator*( const float lhs, const vec2& rhs )
//{
//	return rhs * lhs;
//};
//
//// Transform through matrix	
//inline const vec2 operator*( const kmMat3& lhs, const vec2& rhs )
//{
//	vec2 result;
//	kmVec2Transform( (kmVec2*)(&result), (kmVec2*)(&rhs), &lhs );
//	return result;
//};
//
//// Checks for equality (with a small threshold epsilon)
//inline const bool operator==( const vec2& lhs, const vec2& rhs )
//{
//	return (kmVec2AreEqual( (kmVec2*)(&lhs), (kmVec2*)(&rhs) ) != 0 );
//};


#endif //__VEC2_HPP__