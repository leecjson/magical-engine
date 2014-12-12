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

inline Plane3 Plane3::fromZero( void )
{
	return Plane3::Zero;
}

inline Plane3 Plane3::fromNormalAndDistance( const Vector3& n, const float d )
{
	Plane3 ret;
	magicalPlane3FillNormalAndDistance( tofpointer( &ret ), tofpointer( &n ), d );
	return ret;
}

inline Plane3 Plane3::fromNormalAndPoint( const Vector3& n, const Vector3& a )
{
	Plane3 ret;
	magicalPlane3FillNormalAndPoint( tofpointer( &ret ), tofpointer( &n ), tofpointer( &a ) );
	return ret;
}

inline Plane3 Plane3::fromPoints( const Vector3& a, const Vector3& b, const Vector3& c )
{
	Plane3 ret;
	magicalPlane3FillPoints( tofpointer( &ret ), tofpointer( &a ), tofpointer( &b ), tofpointer( &c ) );
	return ret;
}

inline void Plane3::getNormal( Vector3& out, const Plane3& p )
{
	magicalPlane3GetNormal( tofpointer( &out ), tofpointer( &p ) );
}

inline void Plane3::nearestPoint( Vector3& out, const Plane3& p, const Vector3& point )
{
	magicalPlane3NearestPoint( tofpointer( &out ), tofpointer( &p ), tofpointer( &point ) );
}

inline void Plane3::projectPoint( Vector3& out, const Plane3& p, const Vector3& point )
{
	magicalPlane3ProjectPoint( tofpointer( &out ), tofpointer( &p ), tofpointer( &point ) );
}

inline bool Plane3::equals( const Plane3& p ) const
{
	return magicalPlane3Equals( tofpointer( this ), tofpointer( &p ) );
}

inline bool Plane3::isZero( void ) const
{
	return magicalPlane3IsZero( tofpointer( this ) );
}

inline void Plane3::fill( const Plane3& p )
{
	magicalPlane3Fill( tofpointer( this ), tofpointer( &p ) );
}

inline void Plane3::fillZero( void )
{
	magicalPlane3FillZero( tofpointer( this ) );
}

inline void Plane3::fillScalars( const float x, const float y, const float z, const float d )
{
	magicalPlane3FillScalars( tofpointer( this ), x, y, z, d );
}

inline void Plane3::fillNormalAndDistance( const Vector3& n, const float d )
{
	magicalPlane3FillNormalAndDistance( tofpointer( this ), tofpointer( &n ), d );
}

inline void Plane3::fillNormalAndPoint( const Vector3& n, const Vector3& a )
{
	magicalPlane3FillNormalAndPoint( tofpointer( this ), tofpointer( &n ), tofpointer( &a ) );
}

inline void Plane3::fillPoints( const Vector3& a, const Vector3& b, const Vector3& c )
{
	magicalPlane3FillPoints( tofpointer( this ), tofpointer( &a ), tofpointer( &b ), tofpointer( &c ) );
}

inline bool Plane3::operator==( const Plane3& p ) const
{
	return magicalPlane3Equals( tofpointer( this ), tofpointer( &p ) );
}

inline bool Plane3::operator!=( const Plane3& p ) const
{
	return !magicalPlane3Equals( tofpointer( this ), tofpointer( &p ) );
}

inline Plane3& Plane3::operator=( const Plane3& p )
{
	magicalPlane3Fill( tofpointer( this ), tofpointer( &p ) );
	return *this;
}
	
inline void Plane3::setNormal( const Vector3& n )
{
	magicalPlane3SetNormal( tofpointer( this ), tofpointer( &n ) );
}

inline void Plane3::setDistance( const float d )
{
	this->d = d;
}

inline Vector3 Plane3::getNormal( void ) const
{
	return Vector3( x, y, z );
}

inline float Plane3::getDistance( void ) const
{
	return d;
}

inline Vector3 Plane3::nearestPoint( const Vector3& point ) const
{
	Vector3 ret;
	magicalPlane3NearestPoint( tofpointer( &ret ), tofpointer( this ), tofpointer( &point ) );
	return ret;
}

inline Vector3 Plane3::projectPoint( const Vector3& point ) const
{
	Vector3 ret;
	magicalPlane3ProjectPoint( tofpointer( &ret ), tofpointer( this ), tofpointer( &point ) );
	return ret;
}

inline float Plane3::distanceToPoint( const Vector3& point ) const
{
	return magicalPlane3DistanceToPoint( tofpointer( this ), tofpointer( &point ) );
}

inline Plane3Classification Plane3::classifyPoint( const Vector3& point ) const
{
	return (Plane3Classification) magicalPlane3ClassifyPoint( tofpointer( this ), tofpointer( &point ) );
}

inline Plane3Classification Plane3::classifyAABB3( const AABB3& aabb ) const
{
	return (Plane3Classification) magicalPlane3ClassifyAABB3( tofpointer( this ), tofpointer( &aabb ) );
}

inline Plane3Classification Plane3::classifySphere3( const Sphere3& sp ) const
{
	return (Plane3Classification) magicalPlane3ClassifySphere3( tofpointer( this ), tofpointer( &sp ) );
}

inline bool Plane3::intersects( const Plane3& p ) const
{
	return magicalPlane3Intersects( tofpointer( this ), tofpointer( &p ) );
}

inline bool Plane3::intersectsAABB3( const AABB3& aabb ) const
{
	return magicalPlane3IntersectsAABB3( tofpointer( this ), tofpointer( &aabb ) );
}

inline bool Plane3::intersectsSphere3( const Sphere3& sp ) const
{
	return magicalPlane3IntersectsSphere3( tofpointer( this ), tofpointer( &sp ) );
}

inline bool Plane3::intersectsRay3( const Ray3& r3, const bool discard_inside ) const
{
	return magicalPlane3IntersectsRay3( tofpointer( this ), tofpointer( &r3 ), discard_inside );
}

inline bool Plane3::intersectsRay3Distance( float& distance, const Ray3& r3, const bool discard_inside ) const
{
	return magicalPlane3IntersectsRay3Distance( &distance, tofpointer( this ), tofpointer( &r3 ), discard_inside );
}

inline bool Plane3::containsPoint( const Vector3& point ) const
{
	return magicalPlane3ContainsPoint( tofpointer( this ), tofpointer( &point ) );
}