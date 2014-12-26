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
#ifndef __SPHERE3_H__
#define __SPHERE3_H__

class Vector3;
class Ray3;
class AABB3;
class Plane3;

class Sphere3
{
public:
	float x;
	float y;
	float z;
	float r;

public:
	static const Sphere3 Zero;
	static const Sphere3 One;
	static Sphere3 placeholder;
	static Sphere3 temp;

public:
	Sphere3( float x, float y, float z, float r );
	Sphere3( const Sphere3& sp );
	Sphere3( void );

public:
	static inline Sphere3 fromZero( void );
	static inline Sphere3 fromOne( void );
	static inline Sphere3 fromCenterAndRadius( const Vector3& center, float r );

public:
	inline bool equals( const Sphere3& sp ) const;
	inline bool isZero( void ) const;
	inline bool isOne( void ) const;
	inline void fill( const Sphere3& sp );
	inline void fillZero( void );
	inline void fillOne( void );
	inline void fillScalars( float x, float y, float z, float r );
	inline void fillCenterAndRadius( const Vector3& center, float r );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Sphere3& sp ) const;
	inline bool operator!=( const Sphere3& sp ) const;
	inline Sphere3& operator=( const Sphere3& sp );

public:
	inline bool intersects( const Sphere3& sp ) const;
	inline bool intersectsAABB3( const AABB3& aabb ) const;
	inline bool intersectsPlane3( const Plane3& p ) const;
	inline bool intersectsRay3( const Ray3& r3, bool discard_inside = false ) const;
	inline bool intersectsRay3Distance( float& distance, const Ray3& r3, bool discard_inside = false ) const;

	inline bool containsPoint( const Vector3& point ) const;
};

#endif //__SPHERE3_H__