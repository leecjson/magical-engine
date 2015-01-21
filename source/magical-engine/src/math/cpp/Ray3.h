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

NS_MAGICAL_BEGIN

FORWARD_DECLARE

struct Ray3 : public cRay3
{
public:
	static const Ray3 Zero;
	static Ray3 var;

public:
	Ray3( float ox, float oy, float oz, float dx, float dy, float dz );
	Ray3( const Ray3& r3 );
	Ray3( void );

public:
	static inline Ray3 createZero( void );
	static inline Ray3 createFromOriginToEnd( const Vector3& origin, const Vector3& end );
	static inline Ray3 createFromOriginAndDirection( const Vector3& origin, const Vector3& direction );
	static inline void getOrigin( Vector3& out, const Ray3& r3 );
	static inline void getDirection( Vector3& out, const Ray3& r3 );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool equals( const Ray3& r3 ) const;
	inline bool isZero( void ) const;
	inline bool operator==( const Ray3& r3 ) const;
	inline bool operator!=( const Ray3& r3 ) const;
	inline Ray3& operator=( const Ray3& r3 );

public:
	inline void set( const Ray3& r3 );
	inline void setZero( void );
	inline void setScalars( float ox, float oy, float oz, float dx, float dy, float dz );
	inline void fromOriginToEnd( const Vector3& origin, const Vector3& end );
	inline void fromOriginAndDirection( const Vector3& origin, const Vector3& direction );
	inline Vector3 getOrigin( void ) const;
	inline Vector3 getDirection( void ) const;
	inline void setOrigin( const Vector3& origin );
	inline void setDirection( const Vector3& direction );

	inline void intersectsPlane3( RayIntersectResult& out, const Plane3& p, bool discard_inside = false ) const;
	inline void intersectsAABB3( RayIntersectResult& out, const AABB3& aabb, bool discard_inside = false ) const;
	inline void intersectsSphere3( RayIntersectResult& out, const Sphere3& sp, bool discard_insid = false ) const;
};

struct RayIntersectResult : public cRayIntersectResult
{
public:
	RayIntersectResult( void );
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
};

NS_MAGICAL_END

#endif //__RAY3_H__