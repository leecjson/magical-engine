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

inline Sphere::Sphere( float x, float y, float z, float r ) 
: x( x ), y( y ), z( z ), r( r )
{
	
}

inline Sphere::Sphere( const Vector3& center, float r ) 
: center( center ), r( r )
{
	
}

inline Sphere::Sphere( const Sphere& sphere ) 
: x( sphere.x ), y( sphere.y ), z( sphere.z ), r( r )
{
	
}

inline Sphere::Sphere( void )
{
	
}

inline bool Sphere::operator==( const Sphere& sphere ) const
{
	return equals( sphere );
}

inline bool Sphere::operator!=( const Sphere& sphere ) const
{
	return equals( sphere ) == false;
}

inline Sphere& Sphere::operator=( const Sphere& sphere )
{
	x = sphere.x;
	y = sphere.y;
	z = sphere.z;
	r = sphere.r;
	return *this;
}

inline bool Sphere::equals( const Sphere& sphere ) const
{
	return
		Math::isAlmostEqual( x, sphere.x, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( y, sphere.y, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( z, sphere.z, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( r, sphere.r, Math::VectorEpsilon );
}

inline bool Sphere::isValid( void ) const
{
	return r >= Math::VectorEpsilon;
}

inline void Sphere::set( const Sphere& sphere )
{
	x = sphere.x;
	y = sphere.y;
	z = sphere.z;
	r = sphere.r;
}

inline void Sphere::set( const Vector3& center, float r )
{
	this->center = center;
	this->r = r;
}

inline void Sphere::set( float x, float y, float z, float r )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->r = r;
}

inline Sphere Sphere::scale( const Sphere& sphere, float s )
{
	return Sphere( sphere.x, sphere.y, sphere.z, sphere.r * s );
}

inline Sphere Sphere::merge( const Sphere& sphere1, const Sphere& sphere2 )
{
	Sphere dst;
	Sphere::merge( dst, sphere1, sphere2 );
	return dst;
}

inline void Sphere::scale( float s )
{
	r *= s;
}

inline void Sphere::merge( const Sphere& sphere )
{
	Sphere::merge( *this, *this, sphere );
}

inline Vector3 Sphere::closest( const Vector3& v )
{
	Vector3 dst;
	Sphere::closest( dst, *this, v );
	return dst;
}

inline bool Sphere::intersects( const Sphere& sphere ) const
{
	return Vector3::distanceSq( center, sphere.center ) <= ( r + sphere.r ) * ( r + sphere.r );
}

inline bool Sphere::intersects( const Box& box ) const
{
	return box.intersects( *this );
}

inline bool Sphere::intersects( const Plane& plane ) const
{
	return plane.intersects( *this );
}

inline bool Sphere::intersects( float& distance, const Ray& ray, bool discard_inside ) const
{
	return ray.intersects( distance, *this, discard_inside );
}

inline bool Sphere::containsPoint( const Vector3& point ) const
{
	float dx = point.x - x;
	float dy = point.y - y;
	float dz = point.z - z;

	return dx * dx + dy * dy + dz * dz <= r;
}