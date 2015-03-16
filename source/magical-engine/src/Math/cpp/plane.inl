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

NS_MAGICAL_BEGIN

inline Plane Plane::createZero( void )
{
	return Plane::Zero;
}

inline Plane Plane::createFromNormalAndDistance( const Vector3& n, float d )
{
	Plane ret;
	magicalPlaneSetNormalAndDistance( &ret, &n, d );
	return ret;
}

inline Plane Plane::createFromNormalAndPoint( const Vector3& n, const Vector3& a )
{
	Plane ret;
	magicalPlaneSetNormalAndPoint( &ret, &n, &a );
	return ret;
}

inline Plane Plane::createFromPoints( const Vector3& a, const Vector3& b, const Vector3& c )
{
	Plane ret;
	magicalPlaneSetPoints( &ret, &a, &b, &c );
	return ret;
}

inline bool Plane::equals( const Plane& p ) const
{
	return magicalPlaneEquals( this, &p );
}

inline bool Plane::isZero( void ) const
{
	return magicalPlaneIsZero( this );
}

inline bool Plane::operator==( const Plane& p ) const
{
	return magicalPlaneEquals( this, &p );
}

inline bool Plane::operator!=( const Plane& p ) const
{
	return !magicalPlaneEquals( this, &p );
}

inline Plane& Plane::operator=( const Plane& p )
{
	magicalPlaneCopy( this, &p );
	return *this;
}

inline void Plane::set( const Plane& p )
{
	magicalPlaneCopy( this, &p );
}

inline void Plane::setZero( void )
{
	magicalPlaneSetZero( this );
}

inline void Plane::setScalars( float x, float y, float z, float d )
{
	magicalPlaneFill( this, x, y, z, d );
}

inline void Plane::fromNormalAndDistance( const Vector3& n, float d )
{
	magicalPlaneSetNormalAndDistance( this, &n, d );
}

inline void Plane::fromNormalAndPoint( const Vector3& n, const Vector3& a )
{
	magicalPlaneSetNormalAndPoint( this, &n, &a );
}

inline void Plane::fromPoints( const Vector3& a, const Vector3& b, const Vector3& c )
{
	magicalPlaneSetPoints( this, &a, &b, &c );
}
	
inline void Plane::setNormal( const Vector3& n )
{
	magicalPlaneSetNormal( this, &n );
}

inline void Plane::setDistance( float d )
{
	this->d = d;
}

inline Vector3 Plane::getNormal( void ) const
{
	return Vector3( x, y, z );
}

inline float Plane::getDistance( void ) const
{
	return d;
}

inline void Plane::normalize( void )
{
	magicalPlaneNormalize( this, this );
}

inline Plane Plane::getNormalized( void ) const
{
	Plane ret;
	magicalPlaneNormalize( &ret, this );
	return ret;
}

inline Vector3 Plane::nearestPoint( const Vector3& point ) const
{
	Vector3 ret;
	magicalPlaneNearestPoint( &ret, this, &point );
	return ret;
}

inline float Plane::distanceToPoint( const Vector3& point ) const
{
	return magicalPlaneDistanceToPoint( this, &point );
}

inline PlaneClassification Plane::classifyPoint( const Vector3& point ) const
{
	return (PlaneClassification) magicalPlaneClassifyPoint( this, &point );
}

inline PlaneClassification Plane::classifyAABB3( const AABB3& aabb ) const
{
	return (PlaneClassification) magicalPlaneClassifyAABB3( this, &aabb );
}

inline PlaneClassification Plane::classifySphere( const Sphere& sp ) const
{
	return (PlaneClassification) magicalPlaneClassifySphere( this, &sp );
}

inline bool Plane::intersects( const Plane& p ) const
{
	return magicalPlaneIntersects( this, &p );
}

inline bool Plane::intersectsAABB3( const AABB3& aabb ) const
{
	return magicalPlaneIntersectsAABB3( this, &aabb );
}

inline bool Plane::intersectsSphere( const Sphere& sp ) const
{
	return magicalPlaneIntersectsSphere( this, &sp );
}

inline bool Plane::intersectsRay3( float& outt, const Ray3& r3, bool discard_inside ) const
{
	return magicalPlaneIntersectsRay3( &outt, this, &r3, discard_inside );
}

inline bool Plane::containsPoint( const Vector3& point ) const
{
	return magicalPlaneContainsPoint( this, &point );
}



inline void MathPlane::getNormal( Vector3& out, const Plane& p )
{
	magicalPlaneGetNormal( &out, &p );
}

inline void MathPlane::nearestPoint( Vector3& out, const Plane& p, const Vector3& point )
{
	magicalPlaneNearestPoint( &out, &p, &point );
}

NS_MAGICAL_END