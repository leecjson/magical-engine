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
#ifndef __VEC2_H__
#define __VEC2_H__

#include "kazmath.h"

struct vec2 : public kmVec2
{
public:
	///< Constructors
	vec2(const kmScalar _x, const kmScalar _y)
	{
		x = _x;
		y = _y;
	}

	vec2()
	{
		x = kmScalar(0.0);
		y = kmScalar(0.0);
	}

	///< Returns the length of the vector
	const kmScalar length() const
	{
		return kmVec2Length(this);
	}

	///< Returns the square of the length of the vector
	const kmScalar lengthSq() const
	{
		return kmVec2LengthSq(this);
	}

	///< Returns the vector passed in set to unit length
	const vec2 normalize() const
	{
		vec2 result;
		kmVec2Normalize(&result, this);
		return result;
	}

	///< Transform the Vector
	const vec2 transform(const kmMat3& mat) const
	{
		vec2 result;
		kmVec2Transform(&result, this, &mat);
		return result;
	}

	///< Transforms a 3D vector by a given matrix, projecting the result back into w = 1.
	const vec2 transformCoord(const kmMat3& mat) const
	{
		vec2 result;
		kmVec2TransformCoord(&result, this, &mat);
		return result;
	}

	inline kmScalar dot( const vec2& rhs )
	{
		return kmVec2Dot(this, &rhs);
	}

	inline float cross(const vec2& rhs)
	{
		return kmVec2Cross(this, &rhs);
	}

	inline vec2 operator+(const vec2& rhs) const
	{
		return vec2( x + rhs.x, y + rhs.y );
	}

	inline vec2 operator+( kmScalar rhs ) const 
	{
		return vec2( x + rhs, y + rhs );
	}

	inline vec2& operator+=( const vec2& rhs )
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	inline vec2& operator+=( kmScalar rhs )
	{
		x += rhs;
		y += rhs;
		return *this;
	}

	inline vec2 operator-(const vec2& rhs) const
	{
		return vec2( x - rhs.x, y - rhs.y );
	}

	inline vec2& operator-=( const vec2& rhs )
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	inline vec2& operator-=( kmScalar rhs )
	{
		x -= rhs;
		y -= rhs;
		return *this;
	}

	inline vec2 operator*(const vec2& rhs) const
	{
		return vec2( x * rhs.x, y * rhs.y );
	}

	inline vec2 operator*( kmScalar rhs ) const
	{
		return vec2( x * rhs, y * rhs );
	}

	inline vec2& operator*=( const vec2& rhs )
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}

	inline vec2& operator*=( kmScalar rhs  )
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}

	inline vec2 operator/(const vec2& rhs) const
	{
		return vec2( x / rhs.x, y / rhs.y );
	}

	inline vec2 operator/( kmScalar rhs ) const
	{
		if( rhs ){ 
			return vec2( x / rhs, y / rhs );
		}else{ 
			return *this;
		}
	}

	inline vec2& operator/=( const vec2& rhs )
	{
		if( rhs.x && rhs.y ){ 
			x /= rhs.x;
			y /= rhs.y;
		}
		return *this;
	}

	inline vec2& operator/=( kmScalar rhs  )
	{
		if( rhs ){ 
			x /= rhs;
			y /= rhs;
		}
		return *this;
	}
};

///< Multiply with scalar
inline const vec2 operator*(const kmScalar lhs, const vec2& rhs)
{
	return rhs * lhs;
};

///< Transform through matrix	
inline const vec2 operator*(const kmMat3& lhs, const vec2& rhs)
{
	vec2 result;
	kmVec2Transform(&result, &rhs, &lhs);
	return result;
};

///< Checks for equality (with a small threshold epsilon)
inline const bool operator==(const vec2& lhs, const vec2& rhs)
{
	return (kmVec2AreEqual(&lhs,&rhs) != 0);
};












struct vec4 : public kmVec4
{
public:
	///< Constructors
	vec4(const kmScalar _x, const kmScalar _y, const kmScalar _z, const kmScalar _w)
	{
		x = _x;
		y = _y;
		z = _z;	
		w = _w;		
	}
	vec4()
	{
		x = kmScalar(0.0);
		y = kmScalar(0.0);
		z = kmScalar(0.0);
		w = kmScalar(0.0);
	}

	///< Returns the length of the vector
	const kmScalar length() const
	{
		return kmVec4Length(this);
	}

	///< Returns the square of the length of the vector
	const kmScalar lengthSq() const
	{
		return kmVec4LengthSq(this);
	}


	///< Returns the vector passed in set to unit length
	const vec4 normalize() const
	{
		vec4 result;
		kmVec4Normalize(&result,this);
		return result;
	}

	///< Transform the Vector
	const vec4 transform(const kmMat4& mat)
	{
		vec4 result;
		kmVec4Transform(&result,this, &mat);
		return result;
	}

	static const vec4 lerp(const kmVec4& pV1, const kmVec4& pV2, kmScalar t)
	{
		vec4 result;
		kmVec4Lerp(&result, &pV1, &pV2, t);
		return result;
	}

	inline vec4 operator+( const vec4& rhs ) const
	{
		return vec4( x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w );
	}

	inline vec4 operator+( kmScalar rhs ) const
	{
		return vec4( x + rhs, y + rhs, z + rhs, w + rhs );
	}

	inline vec4& operator+=( const vec4& rhs )
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	}

	inline vec4& operator+=( kmScalar rhs )
	{
		x += rhs;
		y += rhs;
		z += rhs;
		w += rhs;
		return *this;
	}

	inline vec4 operator-( const vec4& rhs ) const
	{
		return vec4( x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w );
	}

	inline vec4 operator-( kmScalar rhs ) const
	{
		return vec4( x - rhs, y - rhs, z - rhs, w - rhs );
	}

	inline vec4& operator-=( const vec4& rhs )
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return *this;
	}

	inline vec4& operator-=( kmScalar rhs )
	{
		x -= rhs;
		y -= rhs;
		z -= rhs;
		w -= rhs;
		return *this;
	}

	inline vec4 operator*( const vec4& rhs ) const
	{
		return vec4( x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w );
	}

	inline vec4 operator*( kmScalar rhs ) const
	{
		return vec4( x * rhs, y * rhs, z * rhs, w * rhs );
	}

	inline vec4& operator*=( const vec4& rhs )
	{
		this->x *= rhs.x;
		this->y *= rhs.y;
		this->z *= rhs.z;
		this->w *= rhs.w;
		return *this;
	}

	inline vec4& operator*=( kmScalar rhs  )
	{
		this->x *= rhs;
		this->y *= rhs;
		this->z *= rhs;
		this->w *= rhs;
		return *this;
	}

	inline vec4 operator/( const vec4& rhs ) const
	{
		if( rhs.x && rhs.y && rhs.z && rhs.w ){
			return vec4( x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w );
		}else{
			return vec4( x, y, z, w );
		}
	}

	inline vec4 operator/( kmScalar rhs ) const
	{
		if( rhs != 0.0 ){
			return vec4( x / rhs, y / rhs, z / rhs, w / rhs );
		}else{
			return vec4( x, y, z, w );
		}
	}

	inline vec4& operator/=( const vec4& rhs )
	{
		if( rhs.x && rhs.y && rhs.z && rhs.w ){
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
		}
		return *this;
	}

	inline vec4& operator/=( kmScalar rhs  )
	{
		if( rhs ){
			x /= rhs;
			y /= rhs;
			z /= rhs;
			w /= rhs;
		}
		return *this;
	}

	inline kmScalar dot( const vec4& rhs )
	{
		return kmVec4Dot(this, &rhs);
	}
};

///< Multiply with scalar
inline const vec4 operator*(const kmScalar lhs, const vec4& rhs)
{
	return rhs * lhs;
}


///< Transform through matrix	
inline const vec4 operator*(const kmMat4& lhs, const vec4& rhs)
{
	vec4 result;
	kmVec4Transform(&result, &rhs, &lhs);
	return result;
}

///< Checks for equality (with a small threshold epsilon)
inline const bool operator==(const vec4& lhs, const vec4& rhs)
{
	return (kmVec4AreEqual(&lhs,&rhs) != 0);
}


#endif //__VEC2_H__