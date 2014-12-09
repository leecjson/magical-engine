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
#ifndef __RAY3_H__
#define __RAY3_H__

class Vector3;
class AABB3;
class Plane3;
class Sphere3;

class Ray3
{
public:
	float ox;
	float oy;
	float oz;
	float dx;
	float dy;
	float dz;

public:
	static const Ray3 Zero;
	static Ray3 placeholder;
	static Ray3 temp;

public:
	Ray3( const float ox, const float oy, const float oz, const float dx, const float dy, const float dz );
	Ray3( const Ray3& r3 );
	Ray3( void );

public:
	static inline Ray3 fromOriginToEnd( const Vector3& origin, const Vector3& end );
	static inline Ray3 fromOriginAndDirection( const Vector3& origin, const Vector3& direction );
	static inline void getOrigin( Vector3& out, const Ray3& r3 );
	static inline void getDirection( Vector3& out, const Ray3& r3 );
	static inline void directionNormalize( Ray3& out, const Ray3& r3 );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Ray3& r3 ) const;
	inline bool operator!=( const Ray3& r3 ) const;
	inline Ray3& operator=( const Ray3& r3 );

public:
	inline bool isZero( void ) const;
	inline bool isEquals( const Ray3& r3 ) const;
	inline void fill( const float ox, const float oy, const float oz, const float dx, const float dy, const float dz );
	inline void fill( const Ray3& r3 );
	inline void fillOriginToEnd( const Vector3& origin, const Vector3& end );
	inline void fillOriginAndDirection( const Vector3& origin, const Vector3& direction );

	inline Vector3 getOrigin( void ) const;
	inline Vector3 getDirection( void ) const;
	inline void setOrigin( const Vector3& origin );
	inline void setDirection( const Vector3& direction );

	inline void directionNormalize( void );

	inline bool intersectsPlane3( const Plane3& p, const bool discard_inside = false ) const;
	inline bool intersectsAABB3( const AABB3& aabb, const bool discard_inside = false ) const;
	inline bool intersectsSphere3( const Sphere3& sp, const bool discard_insid = false ) const;

	inline bool intersectsPlane3Distance( float& distance, const Plane3& p, const bool discard_inside = false ) const;
	inline bool intersectsAABB3Distance( float& distance, const AABB3& aabb, const bool discard_inside = false ) const;
	inline bool intersectsSphere3Distance( float& distance, const Sphere3& sp, const bool discard_inside = false ) const;

};

#include "../c/cRay3.h"
#include "Vector3.h"
#include "AABB3.h"
#include "Plane3.h"
#include "Sphere3.h"
#include "Ray3.inl"

#endif //__RAY3_H__