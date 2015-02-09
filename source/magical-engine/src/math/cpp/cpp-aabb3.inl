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

inline AABB3 AABB3::createZero( void )
{
	return AABB3::Zero;
}

inline AABB3 AABB3::createFromPoints( const Vector3& min, const Vector3& max )
{
	AABB3 ret;
	magicalAABB3SetPoints( &ret, &min, &max );
	return ret;
}

inline AABB3 AABB3::createFromBox( const Vector3& center, float width, float height, float depth )
{
	AABB3 ret;
	magicalAABB3SetBox( &ret, &center, width, height, depth );
	return ret;
}

inline void AABB3::merge( AABB3& out, const AABB3& aabb1, const AABB3& aabb2 )
{
	magicalAABB3Merge( &out, &aabb1, &aabb2 );
}

inline void AABB3::transform( AABB3& out, const AABB3& aabb, const Matrix4& m )
{
	magicalAABB3Transform( &out, &aabb, &m );
}

inline void AABB3::centerPoint( Vector3& out, const AABB3& aabb )
{
	magicalAABB3CenterPoint( &out, &aabb );
}

inline void AABB3::nearestPoint( Vector3& out, const AABB3& aabb, const Vector3& point )
{
	magicalAABB3NearestPoint( &out, &aabb, &point );
}

inline bool AABB3::equals( const AABB3& aabb ) const
{
	return magicalAABB3Equals( this, &aabb );
}

inline bool AABB3::isZero( void ) const
{
	return magicalAABB3IsZero( this );
}

inline bool AABB3::operator==( const AABB3& aabb ) const
{
	return magicalAABB3Equals( this, &aabb );
}

inline bool AABB3::operator!=( const AABB3& aabb ) const
{
	return !magicalAABB3Equals( this, &aabb );
}

inline AABB3& AABB3::operator=( const AABB3& aabb )
{
	magicalAABB3Copy( this, &aabb );
	return *this;
}

inline void AABB3::set( const AABB3& aabb )
{
	magicalAABB3Copy( this, &aabb );
}

inline void AABB3::setZero( void )
{
	magicalAABB3SetZero( this );
}

inline void AABB3::setScalars( float minx, float miny, float minz, float maxx, float maxy, float maxz )
{
	magicalAABB3Fill( this, minx, miny, minz, maxx, maxy, maxz );
}

inline void AABB3::fromPoints( const Vector3& min, const Vector3& max )
{
	magicalAABB3SetPoints( this, &min, &max );
}

inline void AABB3::fromBox( const Vector3& center, float width, float height, float depth )
{
	magicalAABB3SetBox( this, &center, width, height, depth );
}

inline void AABB3::addPoint( float x, float y, float z )
{
	magicalAABB3AddPoint( this, this, &Vector3( x, y, z ) );
}

inline void AABB3::addPoint( const Vector3& v )
{
	magicalAABB3AddPoint( this, this, &v );
}

inline void AABB3::merge( const AABB3& aabb )
{
	magicalAABB3Merge( this, this, &aabb );
}

inline void AABB3::transform( const Matrix4& m )
{
	magicalAABB3Transform( this, this, &m );
}

inline AABB3 AABB3::getMerged( const AABB3& aabb ) const
{
	AABB3 ret;
	magicalAABB3Merge( &ret, this, &aabb );
	return ret;
}

inline float AABB3::size( void ) const
{
	return magicalAABB3Size( this );
}

inline float AABB3::diameterX( void ) const
{
	return magicalAABB3DiameterX( this );
}

inline float AABB3::diameterY( void ) const
{
	return magicalAABB3DiameterY( this );
}

inline float AABB3::diameterZ( void ) const
{
	return magicalAABB3DiameterZ( this );
}

inline Vector3 AABB3::centerPoint( void ) const
{
	Vector3 ret;
	magicalAABB3CenterPoint( &ret, this );
	return ret;
}

inline Vector3 AABB3::nearestPoint( const Vector3& point ) const
{
	Vector3 ret;
	magicalAABB3NearestPoint( &ret, this, &point );
	return ret;
}

inline void AABB3::setMinPoint( const Vector3& min )
{
	magicalAABB3SetMinPoint( this, &min );
}

inline Vector3 AABB3::getMinPoint( void ) const
{
	return Vector3( minx, miny, minz );
}

inline void AABB3::setMaxPoint( const Vector3& max )
{
	magicalAABB3SetMaxPoint( this, &max );
}

inline Vector3 AABB3::getMaxPoint( void ) const
{
	return Vector3( maxx, maxy, maxz );
}

inline bool AABB3::intersects( const AABB3& aabb ) const
{
	return magicalAABB3Intersects( this, &aabb );
}

inline bool AABB3::intersectsPart( AABB3& out, const AABB3& aabb ) const
{
	return magicalAABB3IntersectsPart( &out, this, &aabb );
}

inline bool AABB3::intersectsPlane( const Plane& p ) const
{
	return magicalAABB3IntersectsPlane( this, &p );
}

inline bool AABB3::intersectsSphere( const Sphere& sp ) const
{
	return magicalAABB3IntersectsSphere( this, &sp );
}

inline void AABB3::intersectsRay3( RayIntersectResult& out, const Ray3& r3, bool discard_inside ) const
{
	magicalAABB3IntersectsRay3( &out, this, &r3, discard_inside );
}

inline bool AABB3::containsPoint( const Vector3& point ) const
{
	return magicalAABB3ContainsPoint( this, &point );
}

inline bool AABB3::insideFrustum( const Frustum& frustum ) const
{
	return magicalAABB3InsideFrustum( this, &frustum );
}

NS_MAGICAL_END