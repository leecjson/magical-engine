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

#include "magical-macros.h"

NAMESPACE_MAGICAL

struct Sphere
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
	static const Sphere One;
	static const Sphere Invalid;

public:
	inline Sphere( float x, float y, float z, float r );
	inline Sphere( const Vector3& center, float r );
	inline Sphere( const Sphere& sphere );
	inline Sphere( void );

public:
	inline bool operator==( const Sphere& sphere ) const;
	inline bool operator!=( const Sphere& sphere ) const;
	inline Sphere& operator=( const Sphere& sphere );

public:
	inline bool equals( const Sphere& sphere ) const;
	inline bool isValid( void ) const;
	inline void set( const Sphere& sphere );
	inline void set( const Vector3& center, float r );
	inline void set( float x, float y, float z, float r );

public:
	static void scale( Sphere& out, const Sphere& sphere, float s );
	static void merge( Sphere& out, const Sphere& sphere1, const Sphere& sphere2 );
	static void closest( Vector3& out, const Sphere& sphere, const Vector3& v );
	static inline Sphere scale( const Sphere& sphere, float s );
	static inline Sphere merge( const Sphere& sphere1, const Sphere& sphere2 );
	inline void scale( float s );
	inline void merge( const Sphere& sphere );
	inline Vector3 closest( const Vector3& v );

public:
	inline bool intersects( const Sphere& sphere ) const;
	inline bool intersects( const Box& box ) const;
	inline bool intersects( const Plane& plane ) const;
	inline bool intersects( float& distance, const Ray& ray, bool discard_inside = false ) const;
	inline bool containsPoint( const Vector3& point ) const;
};

NAMESPACE_END

#endif //__SPHERE_H__