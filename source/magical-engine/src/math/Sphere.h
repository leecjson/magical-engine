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
#ifndef __SPHERE_H__
#define __SPHERE_H__

struct BoundingSphere
{
	union
	{
		struct {
			float x;
			float y;
			float z;
			float r;
		};
		struct { Vector3 center; float r; };
	};

public:
	static const BoundingSphere One;
	static const BoundingSphere Invalid;

public:
	inline BoundingSphere( float x, float y, float z, float r );
	inline BoundingSphere( const Vector3& center, float r );
	inline BoundingSphere( const BoundingSphere& sphere );
	inline BoundingSphere( void );

public:
	inline bool operator==( const BoundingSphere& sphere ) const;
	inline bool operator!=( const BoundingSphere& sphere ) const;
	inline BoundingSphere& operator=( const BoundingSphere& sphere );

public:
	inline bool equals( const BoundingSphere& sphere ) const;
	inline bool isValid( void ) const;
	inline void set( const BoundingSphere& sphere );
	inline void set( const Vector3& center, float r );
	inline void set( float x, float y, float z, float r );

public:
	static void scale( BoundingSphere& out, const BoundingSphere& sphere, float s );
	static void merge( BoundingSphere& out, const BoundingSphere& sphere1, const BoundingSphere& sphere2 );
	static void closest( Vector3& out, const BoundingSphere& sphere, const Vector3& v );
	static inline BoundingSphere scale( const BoundingSphere& sphere, float s );
	static inline BoundingSphere merge( const BoundingSphere& sphere1, const BoundingSphere& sphere2 );
	inline void scale( float s );
	inline void merge( const BoundingSphere& sphere );
	inline Vector3 closest( const Vector3& v );

public:
	inline bool intersects( const BoundingSphere& sphere ) const;
	inline bool intersects( const Box& box ) const;
	inline bool intersects( const Plane& plane ) const;
	inline bool intersects( float& distance, const Ray& ray, bool discard_inside = false ) const;
	inline bool containsPoint( const Vector3& point ) const;
};

#endif //__SPHERE_H__
