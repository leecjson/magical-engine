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
#ifndef __QUATERNION_H__
#define __QUATERNION_H__

class Vec3;
class Mat4;
class AxisAngle;
class EulerAngles;

class Quaternion
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	static const Quaternion Identity;
	static Quaternion placeholder;
	static Quaternion temp;

public:
	Quaternion( const float x, const float y, const float z, const float w );
	Quaternion( const Mat4& m );
	Quaternion( const AxisAngle& aa );
	Quaternion( const EulerAngles& ea );
	Quaternion( const Quaternion& q );
	Quaternion( void );

public:
	static inline Quaternion fromMat4( const Mat4& m );
	static inline Quaternion fromAxisAngle( const AxisAngle& aa );
	static inline Quaternion fromAxisAngle( const Vec3& axis, const float angle );
	static inline Quaternion fromEuler( const EulerAngles& ea );
	static inline Quaternion fromEuler( const float yaw, const float pitch, const float roll );
	static inline Quaternion fromRotationX( const float angle );
	static inline Quaternion fromRotationY( const float angle );
	static inline Quaternion fromRotationZ( const float angle );

	static inline void add( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );
	static inline void sub( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );
	static inline void mul( Quaternion& out, const Quaternion& q, const float a );
	static inline void mul( Quaternion& out, const Quaternion& q1, const Quaternion& q2 );
	static inline void normalize( Quaternion& out, const Quaternion& q );
	static inline void conjugate( Quaternion& out, const Quaternion& q );
	static inline void negate( Quaternion& out, const Quaternion& q );
	static inline void inverse( Quaternion& out, const Quaternion& q );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Quaternion& q ) const;
	inline bool operator!=( const Quaternion& q ) const;
	inline Quaternion operator+( const Quaternion& q ) const;
	inline Quaternion operator-( const Quaternion& q ) const;
	inline Quaternion operator*( const float a ) const;
	inline Quaternion operator*( const Quaternion& q ) const;
	inline Quaternion& operator+=( const Quaternion& q );
	inline Quaternion& operator-=( const Quaternion& q );
	inline Quaternion& operator*=( const float a );
	inline Quaternion& operator*=( const Quaternion& q );
	inline Quaternion& operator=( const Quaternion& q );

public:
	inline bool isEquals( const Quaternion& q ) const;
	inline bool isIdentity( void ) const;
	inline bool isNormalize( void ) const;
	inline void fill( const Quaternion& q );
	inline void fill( float x, float y, float z, float w );
	inline void fillIdentity( void );
	inline void fillMat4( const Mat4& m );
	inline void fillAxisAngle( const AxisAngle& aa );
	inline void fillAxisAngle( const Vec3& axis, const float angle );
	inline void fillEuler( const EulerAngles& ea );
	inline void fillEuler( const float yaw, const float pitch, const float roll );
	inline void fillRotationX( const float angle );
	inline void fillRotationY( const float angle );
	inline void fillRotationZ( const float angle );

	inline void normalize( void );
	inline void conjugate( void );
	inline void negate( void );
	inline void inverse( void );

	inline Quaternion getNormalize( void ) const;
	inline Quaternion getConjugate( void ) const;
	inline Quaternion getNegate( void ) const;
	inline Quaternion getInverse( void ) const;

	inline float dot( const Quaternion& q ) const;
	inline float length( void ) const;
	inline float lengthSq( void ) const;
	//inline AxisAngle toAxisAngle( void ) const;
};

#include "../c/cQuaternion.h"
#include "Vec3.h"
#include "Mat4.h"
#include "EulerAngles.h"
#include "Quaternion.inl"
	
#endif //__QUATERNION_H__