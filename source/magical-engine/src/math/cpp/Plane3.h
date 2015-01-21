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
#ifndef __PLANE3_H__
#define __PLANE3_H__

NS_MAGICAL_BEGIN

FORWARD_DECLARE

enum class Plane3Classification
{
	Front = 1,
	OnPlane = 0,
	Behind = -1
};

struct Plane3 : public cPlane3
{
public:
	static const Plane3 Zero;
	static const Plane3 NormalX;
	static const Plane3 NormalY;
	static const Plane3 NormalZ;
	static Plane3 var;

public:
	Plane3( float x, float y, float z, float d );
	Plane3( const Plane3& p );
	Plane3( void );

public:
	static inline Plane3 createZero( void );
	static inline Plane3 createFromNormalAndDistance( const Vector3& n, float d );
	static inline Plane3 createFromNormalAndPoint( const Vector3& n, const Vector3& a );
	static inline Plane3 createFromPoints( const Vector3& a, const Vector3& b, const Vector3& c );
	static inline void getNormal( Vector3& out, const Plane3& p );
	static inline void nearestPoint( Vector3& out, const Plane3& p, const Vector3& point );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool equals( const Plane3& p ) const;
	inline bool isZero( void ) const;
	inline bool operator==( const Plane3& p ) const;
	inline bool operator!=( const Plane3& p ) const;
	inline Plane3& operator=( const Plane3& p );

public:
	inline void set( const Plane3& p );
	inline void setZero( void );
	inline void setScalars( float x, float y, float z, float d );
	inline void fromNormalAndDistance( const Vector3& n, float d );
	inline void fromNormalAndPoint( const Vector3& n, const Vector3& a );
	inline void fromPoints( const Vector3& a, const Vector3& b, const Vector3& c );
	inline void setNormal( const Vector3& n );
	inline void setDistance( float d );
	inline Vector3 getNormal( void ) const;
	inline float getDistance( void ) const;
	inline Vector3 nearestPoint( const Vector3& point ) const;
	inline float distanceToPoint( const Vector3& point ) const;

	inline Plane3Classification classifyPoint( const Vector3& point ) const;
	inline Plane3Classification classifyAABB3( const AABB3& aabb ) const;
	inline Plane3Classification classifySphere3( const Sphere3& sp ) const;
	inline bool intersects( const Plane3& p ) const;
	inline bool intersectsAABB3( const AABB3& aabb ) const;
	inline bool intersectsSphere3( const Sphere3& sp ) const;
	inline void intersectsRay3( RayIntersectResult& out, const Ray3& r3, bool discard_inside = false ) const;
	inline bool containsPoint( const Vector3& point ) const;
};

NS_MAGICAL_END

#endif //__PLANE3_H__