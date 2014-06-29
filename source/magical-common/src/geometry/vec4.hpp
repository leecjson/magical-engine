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
#ifndef __VEC4_HPP__
#define __VEC4_HPP__

#include "Common.h"
#include "kazmath.h"

class vec4 : public kmVec4
{
public:
	vec4( const float rx, const float ry, const float rz, const float rw )
	{
		x = rx;
		y = ry;
		z = rz;	
		w = rw;		
	}
	vec4( void )
	{
		x = y = z = w = 0.0f;
	}

	inline float length( void ) const
	{
		return kmVec4Length( this );
	}

	inline float lengthSq( void ) const
	{
		return kmVec4LengthSq( this );
	}

	inline vec4 normalize( void ) const
	{
		vec4 result;
		kmVec4Normalize( &result, this );
		return result;
	}

	/*const vec4 transform(const kmMat4& mat)
	{
		vec4 result;
		kmVec4Transform(&result,this, &mat);
		return result;
	}

	static const vec4 lerp(const kmVec4& pV1, const kmVec4& pV2, float t)
	{
		vec4 result;
		kmVec4Lerp(&result, &pV1, &pV2, t);
		return result;
	}*/

	inline float dot( const vec4& rhs )
	{
		return kmVec4Dot( this, &rhs );
	}

	inline vec4 operator+( float rhs ) const
	{
		return vec4( x + rhs, y + rhs, z + rhs, w + rhs );
	}

	inline vec4 operator+( const vec4& rhs ) const
	{
		return vec4( x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w );
	}

	inline vec4& operator+=( const vec4& rhs )
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	}

	inline vec4& operator+=( float rhs )
	{
		x += rhs;
		y += rhs;
		z += rhs;
		w += rhs;
		return *this;
	}

	inline vec4 operator-( float rhs ) const
	{
		return vec4( x - rhs, y - rhs, z - rhs, w - rhs );
	}

	inline vec4 operator-( const vec4& rhs ) const
	{
		return vec4( x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w );
	}

	inline vec4& operator-=( const vec4& rhs )
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return *this;
	}

	inline vec4& operator-=( float rhs )
	{
		x -= rhs;
		y -= rhs;
		z -= rhs;
		w -= rhs;
		return *this;
	}

	inline vec4 operator*( float rhs ) const
	{
		return vec4( x * rhs, y * rhs, z * rhs, w * rhs );
	}

	inline vec4 operator*( const vec4& rhs ) const
	{
		return vec4( x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w );
	}

	inline vec4& operator*=( const vec4& rhs )
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		w *= rhs.w;
		return *this;
	}

	inline vec4& operator*=( float rhs  )
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		w *= rhs;
		return *this;
	}

	inline vec4 operator/( float rhs ) const
	{
		magicalAssert( rhs, "division by 0.f" );
		return vec4( x / rhs, y / rhs, z / rhs, w / rhs );
	}

	inline vec4 operator/( const vec4& rhs ) const
	{
		magicalAssert( rhs.x && rhs.y && rhs.z && rhs.w, "division by 0.f" );
		return vec4( x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w );
	}

	inline vec4& operator/=( const vec4& rhs )
	{
		magicalAssert( rhs.x && rhs.y && rhs.z && rhs.w, "division by 0.f" );
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		w /= rhs.w;
		return *this;
	}

	inline vec4& operator/=( float rhs  )
	{
		magicalAssert( rhs, "division by 0.f" );
		x /= rhs;
		y /= rhs;
		z /= rhs;
		w /= rhs;
		return *this;
	}

	inline bool operator==( const vec4& rhs )
	{
		return kmVec4AreEqual( this, &rhs ) != 0;
	}

	inline bool operator!=( const vec4& rhs )
	{
		return kmVec4AreEqual( this, &rhs ) == 0;
	}
};

inline vec4 operator*( const float lhs, const vec4& rhs )
{
	return rhs * lhs;
}


///< Transform through matrix	
//inline const vec4 operator*(const kmMat4& lhs, const vec4& rhs)
//{
//	vec4 result;
//	kmVec4Transform(&result, &rhs, &lhs);
//	return result;
//}

	




#endif //__VEC4_HPP__