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

class Vector3;
class Matrix4;
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
	static const AABB3 Zero;
	static AABB3 placeholder;
	static AABB3 temp;

public:
	AABB3( const float min_x, const float min_y, const float min_z, const float max_x, const float max_y, const float max_z );
	AABB3( const AABB3& aabb );
	AABB3( void );

public:
	static inline AABB3 fromZero( void );
	static inline AABB3 fromPoints( const Vector3& min, const Vector3& max );
	static inline AABB3 fromCenterAround( const Vector3& center, const float width, const float height, const float depth );

	static inline void mul( AABB3& out, const AABB3& aabb, const Matrix4& m );
	static inline void getMin( Vector3& out, const AABB3& aabb );
	static inline void getMax( Vector3& out, const AABB3& aabb );
	static inline void extend( Vector3& out, const AABB3& aabb, const float x, const float y, const float z );
	static inline void extend( Vector3& out, const AABB3& aabb, const Vector3& v );
	static inline void merge( AABB3& out, const AABB3& aabb1, const AABB3& aabb2 );
	static inline void getCenter( Vector3& out, const AABB3& aabb );
	static inline void nearestPoint( Vector3& out, const AABB3& aabb, const Vector3& point );

public:
	inline bool equals( const AABB3& aabb ) const;
	inline bool isZero( void ) const;
	inline void fill( const AABB3& aabb );
	inline void fillZero( void );
	inline void fillScalars( const float min_x, const float min_y, const float min_z, const float max_x, const float max_y, const float max_z );
	inline void fillPoints( const Vector3& min, const Vector3& max );
	inline void fillCenterAround( const Vector3& center, const float width, const float height, const float depth );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const AABB3& aabb ) const;
	inline bool operator!=( const AABB3& aabb ) const;
	inline AABB3 operator*( const Matrix4& m ) const;
	inline AABB3& operator*=( const Matrix4& m );
	inline AABB3& operator=( const AABB3& m );

public:
	inline void setMin( const Vector3& min );
	inline void setMax( const Vector3& max );
	inline void extend( const float x, const float y, const float z );
	inline void extend( const Vector3& v );
	inline void merge( const AABB3& aabb );
	inline float size( void ) const;
	inline float diameterX( void ) const;
	inline float diameterY( void ) const;
	inline float diameterZ( void ) const;
	inline Vector3 center( void ) const;
	inline Vector3 nearestPoint( const Vector3& point ) const;
	inline Vector3 getMin( void ) const;
	inline Vector3 getMax( void ) const;
	inline AABB3 getMerged( const AABB3& aabb ) const;
	
	inline bool intersects( const AABB3& aabb ) const;
	inline bool intersectsPlane3( const Plane3& p ) const;
	inline bool intersectsSphere3( const Sphere3& sp ) const;
	inline bool intersectsRay3( const Ray3& r3, const bool discard_inside = false ) const;
	inline bool intersectsRay3Distance( float& distance, const Ray3& r3, const bool discard_inside = false ) const;
	inline bool intersectsPart( AABB3& out, const AABB3& aabb ) const;

	inline bool containsPoint( const Vector3& point ) const;
};

#endif //__AABB3_H__