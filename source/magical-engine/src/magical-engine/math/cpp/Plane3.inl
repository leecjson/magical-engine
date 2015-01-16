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

inline Plane3 Plane3::createZero( void )
{
	return Plane3::Zero;
}

inline Plane3 Plane3::createFromNormalAndDistance( const Vector3& n, float d )
{
	Plane3 ret;
	magicalPlane3SetNormalAndDistance( &ret, &n, d );
	return ret;
}

inline Plane3 Plane3::createFromNormalAndPoint( const Vector3& n, const Vector3& a )
{
	Plane3 ret;
	magicalPlane3SetNormalAndPoint( &ret, &n, &a );
	return ret;
}

inline Plane3 Plane3::createFromPoints( const Vector3& a, const Vector3& b, const Vector3& c )
{
	Plane3 ret;
	magicalPlane3SetPoints( &ret, &a, &b, &c );
	return ret;
}

inline void Plane3::getNormal( Vector3& out, const Plane3& p )
{
	magicalPlane3GetNormal( &out, &p );
}

inline void Plane3::nearestPoint( Vector3& out, const Plane3& p, const Vector3& point )
{
	magicalPlane3NearestPoint( &out, &p, &point );
}

inline bool Plane3::equals( const Plane3& p ) const
{
	return magicalPlane3Equals( this, &p );
}

inline bool Plane3::isZero( void ) const
{
	return magicalPlane3IsZero( this );
}

inline bool Plane3::operator==( const Plane3& p ) const
{
	return magicalPlane3Equals( this, &p );
}

inline bool Plane3::operator!=( const Plane3& p ) const
{
	return !magicalPlane3Equals( this, &p );
}

inline Plane3& Plane3::operator=( const Plane3& p )
{
	magicalPlane3Copy( this, &p );
	return *this;
}

inline void Plane3::set( const Plane3& p )
{
	magicalPlane3Copy( this, &p );
}

inline void Plane3::setZero( void )
{
	magicalPlane3SetZero( this );
}

inline void Plane3::setScalars( float x, float y, float z, float d )
{
	magicalPlane3Fill( this, x, y, z, d );
}

inline void Plane3::fromNormalAndDistance( const Vector3& n, float d )
{
	magicalPlane3SetNormalAndDistance( this, &n, d );
}

inline void Plane3::fromNormalAndPoint( const Vector3& n, const Vector3& a )
{
	magicalPlane3SetNormalAndPoint( this, &n, &a );
}

inline void Plane3::fromPoints( const Vector3& a, const Vector3& b, const Vector3& c )
{
	magicalPlane3SetPoints( this, &a, &b, &c );
}
	
inline void Plane3::setNormal( const Vector3& n )
{
	magicalPlane3SetNormal( this, &n );
}

inline void Plane3::setDistance( float d )
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
	magicalPlane3NearestPoint( &ret, this, &point );
	return ret;
}

inline float Plane3::distanceToPoint( const Vector3& point ) const
{
	return magicalPlane3DistanceToPoint( this, &point );
}

inline Plane3Classification Plane3::classifyPoint( const Vector3& point ) const
{
	return (Plane3Classification) magicalPlane3ClassifyPoint( this, &point );
}

inline Plane3Classification Plane3::classifyAABB3( const AABB3& aabb ) const
{
	return (Plane3Classification) magicalPlane3ClassifyAABB3( this, &aabb );
}

inline Plane3Classification Plane3::classifySphere3( const Sphere3& sp ) const
{
	return (Plane3Classification) magicalPlane3ClassifySphere3( this, &sp );
}

inline bool Plane3::intersects( const Plane3& p ) const
{
	return magicalPlane3Intersects( this, &p );
}

inline bool Plane3::intersectsAABB3( const AABB3& aabb ) const
{
	return magicalPlane3IntersectsAABB3( this, &aabb );
}

inline bool Plane3::intersectsSphere3( const Sphere3& sp ) const
{
	return magicalPlane3IntersectsSphere3( this, &sp );
}

inline void Plane3::intersectsRay3( RayIntersectResult& out, const Ray3& r3, bool discard_inside ) const
{
	magicalPlane3IntersectsRay3( &out, this, &r3, discard_inside );
}

inline bool Plane3::containsPoint( const Vector3& point ) const
{
	return magicalPlane3ContainsPoint( this, &point );
}