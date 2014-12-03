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

inline Plane3 Plane3::fromPoints( const Vec3& a, const Vec3& b, const Vec3& c )
{
	Plane3 ret;
	magicalPlane3FillPoints( tofpointer( &ret ), tofpointer( &a ), tofpointer( &b ), tofpointer( &c ) );
	return ret;
}

inline Plane3 Plane3::fromPointAndNormal( const Vec3& a, const Vec3& n )
{
	Plane3 ret;
	magicalPlane3FillPointAndNormal( tofpointer( &ret ), tofpointer( &a ), tofpointer( &n ) );
	return ret;
}

inline Plane3 Plane3::fromNormalAndDistance( const Vec3& n, const float d )
{
	Plane3 ret;
	magicalPlane3FillNormalAndDistance( tofpointer( &ret ), tofpointer( &n ), d );
	return ret;
}

inline void Plane3::getNormal( Vec3& out, const Plane3& p )
{
	magicalPlane3GetNormal( tofpointer( &out ), tofpointer( &p ) );
}

inline void Plane3::nearestPoint( Vec3& out, const Plane3& p, const Vec3& point )
{
	magicalPlane3NearestPoint( tofpointer( &out ), tofpointer( &p ), tofpointer( &point ) );
}

inline void Plane3::projectPoint( Vec3& out, const Plane3& p, const Vec3& point )
{
	magicalPlane3ProjectPoint( tofpointer( &out ), tofpointer( &p ), tofpointer( &point ) );
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
	x = p.x; y = p.y; z = p.z; d = p.d;
	return *this;
}

inline bool Plane3::isEquals( const Plane3& p ) const
{
	return magicalPlane3Equals( tofpointer( this ), tofpointer( &p ) );
}

inline void Plane3::fill( const float x, const float y, const float z, const float d )
{
	magicalPlane3FillScalars( tofpointer( this ), x, y, z, d );
}

inline void Plane3::fill( const Plane3& p )
{
	x = p.x; y = p.y; z = p.z; d = p.d;
}

inline void Plane3::fillPoints( const Vec3& a, const Vec3& b, const Vec3& c )
{
	magicalPlane3FillPoints( tofpointer( this ), tofpointer( &a ), tofpointer( &b ), tofpointer( &c ) );
}

inline void Plane3::fillPointAndNormal( const Vec3& a, const Vec3& n )
{
	magicalPlane3FillPointAndNormal( tofpointer( this ), tofpointer( &a ), tofpointer( &n ) );
}

inline void Plane3::fillNormalAndDistance( const Vec3& n, const float d )
{
	magicalPlane3FillNormalAndDistance( tofpointer( this ), tofpointer( &n ), d );
}
	
inline void Plane3::setNormal( const Vec3& n )
{
	magicalPlane3SetNormal( tofpointer( this ), tofpointer( &n ) );
}

inline void Plane3::setDistance( const float d )
{
	this->d = d;
}

inline Vec3 Plane3::getNormal( void ) const
{
	return Vec3( x, y, z );
}

inline float Plane3::getDistance( void ) const
{
	return d;
}

inline Vec3 Plane3::nearestPoint( const Vec3& point ) const
{
	Vec3 ret;
	magicalPlane3NearestPoint( tofpointer( &ret ), tofpointer( this ), tofpointer( &point ) );
	return ret;
}

inline Vec3 Plane3::projectPoint( const Vec3& point ) const
{
	Vec3 ret;
	magicalPlane3ProjectPoint( tofpointer( &ret ), tofpointer( this ), tofpointer( &point ) );
	return ret;
}

inline float Plane3::distanceToPoint( const Vec3& point ) const
{
	return magicalPlane3DistanceToPoint( tofpointer( this ), tofpointer( &point ) );
}

inline Plane3Classification Plane3::classifyPoint( const Vec3& point ) const
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

inline bool Plane3::containsPoint( const Vec3& point ) const
{
	return magicalPlane3ContainsPoint( tofpointer( this ), tofpointer( &point ) );
}