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

inline Plane::Plane( float x, float y, float z, float d ) 
: x( x ), y( y ), z( z ), d( d )
{
	
}

inline Plane::Plane( const Vector3& a, const Vector3& b, const Vector3& c )
{
	setPoints( a, b, c );
}

inline Plane::Plane( const Vector3& normal, const Vector3& a )
{
	setNormalPoint( normal, a );
}

inline Plane::Plane( const Vector3& normal, float d )
{
	setNormalDistance( normal, d );
}

inline Plane::Plane( const Plane& plane ) 
: x( plane.x ), y( plane.y ), z( plane.z ), d( plane.d )
{
	
}

inline Plane::Plane( void )
{
	
}

inline bool Plane::operator==( const Plane& plane ) const
{
	return equals( plane );
}

inline bool Plane::operator!=( const Plane& plane ) const
{
	return equals( plane ) == false;
}

inline Plane& Plane::operator=( const Plane& plane )
{
	x = plane.x;
	y = plane.y;
	z = plane.z;
	d = plane.d;
	return *this;
}

inline bool Plane::equals( const Plane& plane ) const
{ 
	return
		Math::isAlmostEqual( x, plane.x, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( y, plane.y, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( z, plane.z, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( d, plane.d, Math::VectorEpsilon );
}

inline bool Plane::isValid( void ) const
{
	return !(
		Math::isAlmostZero( x, Math::VectorEpsilon ) &&
		Math::isAlmostZero( y, Math::VectorEpsilon ) &&
		Math::isAlmostZero( z, Math::VectorEpsilon ) );
}

inline void Plane::set( const Plane& plane )
{
	x = plane.x;
	y = plane.y;
	z = plane.z;
	d = plane.d;
}

inline Plane Plane::createFromPoints( const Vector3& a, const Vector3& b, const Vector3& c )
{
	return Plane( a, b, c );
}

inline Plane Plane::createFromNormalPoint( const Vector3& normal, const Vector3& a )
{
	return Plane( normal, a );
}

inline Plane Plane::createFromNormalDistance( const Vector3& normal, float d )
{
	return Plane( normal, d );
}

inline Plane Plane::normalize( const Plane& plane )
{
	Plane dst;
	Plane::normalize( dst, plane );
	return dst;
}

inline void Plane::normalize( void )
{
	Plane::normalize( *this, *this );
}

inline Vector3 Plane::closest( const Vector3& point ) const
{
	Vector3 dst;
	Plane::closest( dst, *this, point );
	return dst;
}

inline float Plane::distance( const Vector3& point ) const
{
	return x * point.x + y * point.y + z * point.z - d;
}

inline bool Plane::intersects( const Box& box ) const
{
	return classify( box ) == Plane::Classification::OnPlane;
}

inline bool Plane::intersects( const Sphere& sphere ) const
{
	return classify( sphere ) == Plane::Classification::OnPlane;
}

inline bool Plane::intersects( float& distance, const Ray& ray, bool discard_inside ) const
{
	return ray.intersects( distance, *this, discard_inside );
}

inline bool Plane::containsPoint( const Vector3& point ) const
{
	return Math::isAlmostZero( x * point.x + y * point.y + z * point.z - d, Math::VectorEpsilon );
}