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
#ifndef __PLANE_H__
#define __PLANE_H__

struct Plane
{
	union
	{
		struct {
			float x;
			float y;
			float z;
			float d;
		};
		struct { Vector3 normal; float d; };
	};

	enum class Classification : int
	{
		Front = 1,
		OnPlane = 0,
		Behind = -1
	};

public:
	static const Plane Invalid;
	static const Plane NormalX;
	static const Plane NormalY;
	static const Plane NormalZ;

public:
	inline Plane( float x, float y, float z, float d );
	inline Plane( const Vector3& a, const Vector3& b, const Vector3& c );
	inline Plane( const Vector3& normal, const Vector3& a );
	inline Plane( const Vector3& normal, float d );
	inline Plane( const Plane& plane );
	inline Plane( void );

public:
	inline bool operator==( const Plane& plane ) const;
	inline bool operator!=( const Plane& plane ) const;
	inline Plane& operator=( const Plane& plane );

public:
	inline bool equals( const Plane& plane ) const;
	inline bool isValid( void ) const;
	inline void set( const Plane& plane );
	void setPoints( const Vector3& a, const Vector3& b, const Vector3& c );
	void setNormalPoint( const Vector3& normal, const Vector3& a );
	void setNormalDistance( const Vector3& normal, float d );
	static inline Plane createFromPoints( const Vector3& a, const Vector3& b, const Vector3& c );
	static inline Plane createFromNormalPoint( const Vector3& normal, const Vector3& a );
	static inline Plane createFromNormalDistance( const Vector3& normal, float d );
	
public:
	static void normalize( Plane& out, const Plane& plane );
	static void closest( Vector3& out, const Plane& plane, const Vector3& point );
	static inline Plane normalize( const Plane& plane );
	inline void normalize( void );
	inline Vector3 closest( const Vector3& point ) const;
	inline float distance( const Vector3& point ) const;

public:
	Classification classify( const Vector3& point ) const;
	Classification classify( const Box& box ) const;
	Classification classify( const Sphere& sphere ) const;

public:
	bool intersects( const Plane& plane ) const;
	inline bool intersects( const Box& box ) const;
	inline bool intersects( const Sphere& sphere ) const;
	inline bool intersects( float& distance, const Ray& ray, bool discard_inside = false ) const;
	inline bool containsPoint( const Vector3& point ) const;
};

#endif //__PLANE_H__



