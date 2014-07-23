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
#ifndef __MAT3_HPP__
#define __MAT3_HPP__

#include "Common.h"
#include "kazmath/kazmath.h"
#include "Vec3.hpp"

struct Vec3;

struct Mat3 : public kmMat3
{
public:
	Mat3( const float* in );
	Mat3( void );

	inline Mat3 operator*( const Mat3& m ) const;
	inline bool operator==( const Mat3& m ) const;
	inline bool operator!=( const Mat3& m ) const;

public:
	static inline Mat3 fill( const float* in );
	static inline Mat3 adjugate( const Mat3& m );
	static inline void identity( Mat3& m );
	static inline Mat3 inverse( const Mat3& m );
	static inline bool isIdentity( const Mat3& m );
	static inline Mat3 transpose( const Mat3& m );
	static inline float determinant( const Mat3& m );
	static inline Mat3 scalarMultiply( const Mat3& m, const float f );
	static inline Vec3 getUpVec3( const Mat3& m );
	static inline Vec3 getRightVec3( const Mat3& m );
	static inline Vec3 getForwardVec3( const Mat3& m );
	static inline Mat3 rotationX( const float radians );
	static inline Mat3 rotationY( const float radians );
	static inline Mat3 rotationZ( const float radians );
	static inline Mat3 rotation( const float radians );
	static inline Mat3 scaling( const float x, const float y );
	static inline Mat3 translation( const float x, const float y );
	static inline Mat3 rotationAxisAngle( const Vec3& v, const float radians );
	static inline Vec3 rotationToAxisAngle( float* radians, const Mat3& m );
};

#include "Mat3.inl"

#endif //__MAT3_HPP__