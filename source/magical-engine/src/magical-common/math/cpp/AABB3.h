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
#ifndef __AABB3_H__
#define __AABB3_H__

class Vec3;
class Mat4;
class Ray3;
class Plane3;
class Sphere3;

class AABB3
{
public:
	float min_x;
	float min_y;
	float min_z;
	float max_x;
	float max_y;
	float max_z;

public:
	static const AABB3 Identity;
	static AABB3 placeholder;
	static AABB3 temp;

public:
	AABB3( const float min_x, const float min_y, const float min_z, const float max_x, const float max_y, const float max_z );
	AABB3( const Vec3& min, const Vec3& max );
	AABB3( const Vec3& center, const float width, const float height, const float depth );
	AABB3( const AABB3& aabb );
	AABB3( void );

public:
	static inline AABB3 fromMinMax( const Vec3& min, const Vec3& max );
	static inline AABB3 fromBox( const Vec3& center, const float width, const float height, const float depth );

	static inline void mul( AABB3& out, const AABB3& aabb, const Mat4& m );
	static inline void getMin( Vec3& out, const AABB3& aabb );
	static inline void getMax( Vec3& out, const AABB3& aabb );
	static inline void extend( Vec3& out, const AABB3& aabb, const float x, const float y, const float z );
	static inline void extend( Vec3& out, const AABB3& aabb, const Vec3& v );
	static inline void merge( AABB3& out, const AABB3& aabb1, const AABB3& aabb2 );
	static inline void getCenter( Vec3& out, const AABB3& aabb );
	static inline void nearestPoint( Vec3& out, const AABB3& aabb, const Vec3& point );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const AABB3& aabb ) const;
	inline bool operator!=( const AABB3& aabb ) const;
	inline AABB3 operator*( const Mat4& m ) const;
	inline AABB3& operator*=( const Mat4& m );
	inline AABB3& operator=( const AABB3& m );

public:
	inline bool isIdentity( void ) const;
	inline bool isEquals( const AABB3& aabb ) const;
	inline void fill( const AABB3& aabb );
	inline void fill( const float min_x, const float min_y, const float min_z, const float max_x, const float max_y, const float max_z );
	inline void fillIdentity( void );
	inline void fillMinMax( const Vec3& min, const Vec3& max );
	inline void fillBox( const Vec3& center, const float width, const float height, const float depth );
	
	inline Vec3 getMin( void ) const;
	inline Vec3 getMax( void ) const;
	inline void setMin( const Vec3& min );
	inline void setMax( const Vec3& max );
	inline void extend( const float x, const float y, const float z );
	inline void extend( const Vec3& v );
	inline void merge( const AABB3& aabb );
	inline Vec3 nearestPoint( const Vec3& point ) const;
	inline float size( void ) const;
	inline float diameterX( void ) const;
	inline float diameterY( void ) const;
	inline float diameterZ( void ) const;
	inline AABB3 getMerge( const AABB3& aabb ) const;
	inline Vec3 getCenter( void ) const;

	inline bool intersects( const AABB3& aabb ) const;
	inline bool intersectsPlane3( const Plane3& p ) const;
	inline bool intersectsSphere3( const Sphere3& sp ) const;
	inline bool intersectsRay3( const Ray3& r3, const bool discard_inside = false ) const;
	inline bool intersectsRay3Distance( float& distance, const Ray3& r3, const bool discard_inside = false ) const;
	inline bool intersectsPart( AABB3& out, const AABB3& aabb ) const;

	inline bool containsPoint( const Vec3& point ) const;
};

#include "../c/cAABB3.h"
#include "Vec3.h"
#include "Mat4.h"
#include "Ray3.h"
#include "Plane3.h"
#include "AABB3.inl"

#endif //__AABB3_H__