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

#include "PlatformMacros.h"
#include "Common.h"
#include "kazmath/kazmath.h"

struct Vec4
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	Vec4( float rx, float ry, float rz, float rw );
	Vec4( const float* rhs );
	Vec4( const Vec4& rhs );
	Vec4( void );

	inline Vec4  operator+( float rhs ) const;
	inline Vec4  operator+( const Vec4& rhs ) const;
	inline Vec4  operator-( float rhs ) const;
	inline Vec4  operator-( const Vec4& rhs ) const;
	inline Vec4  operator*( float rhs ) const;
	inline Vec4  operator*( const Vec4& rhs ) const;
	inline Vec4  operator/( float rhs ) const;
	inline Vec4  operator/( const Vec4& rhs ) const;
	inline Vec4& operator+=( const Vec4& rhs );
	inline Vec4& operator+=( float rhs );
	inline Vec4& operator-=( const Vec4& rhs );
	inline Vec4& operator-=( float rhs );
	inline Vec4& operator*=( const Vec4& rhs );
	inline Vec4& operator*=( float rhs  );
	inline Vec4& operator/=( const Vec4& rhs );
	inline Vec4& operator/=( float rhs );
	inline bool  operator==( const Vec4& rhs ) const;
	inline bool  operator!=( const Vec4& rhs ) const;
	inline bool  isZero( void ) const;

public:
	static inline Vec4 fill( float x, float y, float z, float w );
	static inline float dot( const Vec4& v1, const Vec4& v2 );
	static inline float length( const Vec4& v );
	static inline float lengthSq( const Vec4& v );
	static inline Vec4 lerp( const Vec4& v1, const Vec4& v2, const float t );
	static inline Vec4 normalize( const Vec4& v );
	static inline Vec4 scale( const Vec4& v, const float s );
	static inline Vec4 multiplyMat4( const Vec4& v, const Mat4& m );
	static const Vec4 transform( const Vec4& v, const Mat4& m );
};

#include "Vec4.inl"
	
#endif //__VEC4_HPP__