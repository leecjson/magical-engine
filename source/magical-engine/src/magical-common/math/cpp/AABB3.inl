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

inline AABB3 AABB3::createFromCenterAround( const Vector3& center, float width, float height, float depth )
{
	AABB3 ret;
	magicalAABB3SetCenterAround( &ret, &center, width, height, depth );
	return ret;
}

inline void AABB3::mul( AABB3& out, const AABB3& aabb, const Matrix4& m )
{
	magicalAABB3Transform( &out, &aabb, &m );
}

inline void AABB3::getMin( Vector3& out, const AABB3& aabb )
{
	magicalAABB3GetMin( &out, &aabb );
}

inline void AABB3::getMax( Vector3& out, const AABB3& aabb )
{
	magicalAABB3GetMax( &out, &aabb );
}

inline void AABB3::merge( AABB3& out, const AABB3& aabb1, const AABB3& aabb2 )
{
	magicalAABB3Merge( &out, &aabb1, &aabb2 );
}

inline void AABB3::getCenter( Vector3& out, const AABB3& aabb )
{
	magicalAABB3Center( &out, &aabb );
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

inline AABB3 AABB3::operator*( const Matrix4& m ) const
{
	AABB3 ret;
	magicalAABB3Transform( &ret, this, &m );
	return ret;
}

inline AABB3& AABB3::operator*=( const Matrix4& m )
{
	magicalAABB3Transform( this, this, &m );
	return *this;
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

inline void AABB3::setScalars( float min_x, float min_y, float min_z, float max_x, float max_y, float max_z )
{
	magicalAABB3Fill( this, min_x, min_y, min_z, max_x, max_y, max_z );
}

inline void AABB3::fromPoints( const Vector3& min, const Vector3& max )
{
	magicalAABB3SetPoints( this, &min, &max );
}

inline void AABB3::fromCenterAround( const Vector3& center, float width, float height, float depth )
{
	magicalAABB3SetCenterAround( this, &center, width, height, depth );
}

inline void AABB3::setMin( const Vector3& min )
{
	magicalAABB3SetMin( this, &min );
}

inline void AABB3::setMax( const Vector3& max )
{
	magicalAABB3SetMax( this, &max );
}

inline void AABB3::addPoint( float x, float y, float z )
{
	magicalAABB3AddPointScalars( this, this, x, y, z );
}

inline void AABB3::addPoint( const Vector3& v )
{
	magicalAABB3AddPoint( this, this, &v );
}

inline void AABB3::merge( const AABB3& aabb )
{
	magicalAABB3Merge( this, this, &aabb );
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

inline Vector3 AABB3::center( void ) const
{
	Vector3 ret;
	magicalAABB3Center( &ret, this );
	return ret;
}

inline Vector3 AABB3::nearestPoint( const Vector3& point ) const
{
	Vector3 ret;
	magicalAABB3NearestPoint( &ret, this, &point );
	return ret;
}

inline Vector3 AABB3::getMin( void ) const
{
	return Vector3( min_x, min_y, min_z );
}

inline Vector3 AABB3::getMax( void ) const
{
	return Vector3( max_x, max_y, max_z );
}

inline AABB3 AABB3::getMerged( const AABB3& aabb ) const
{
	AABB3 ret;
	magicalAABB3Merge( &ret, this, &aabb );
	return ret;
}

inline bool AABB3::intersects( const AABB3& aabb ) const
{
	return magicalAABB3Intersects( this, &aabb );
}

inline bool AABB3::intersectsPlane3( const Plane3& p ) const
{
	return magicalAABB3IntersectsPlane3( this, ( &p ) );
}

inline bool AABB3::intersectsSphere3( const Sphere3& sp ) const
{
	return magicalAABB3IntersectsSphere3( this, ( &sp ) );
}

inline bool AABB3::intersectsRay3( const Ray3& r3, bool discard_inside ) const
{
	return magicalAABB3IntersectsRay3( this, ( &r3 ), discard_inside );
}

inline bool AABB3::intersectsRay3Distance( float& distance, const Ray3& r3, bool discard_inside ) const
{
	return magicalAABB3IntersectsRay3Distance( &distance, this, ( &r3 ), discard_inside );
}

inline bool AABB3::intersectsPart( AABB3& out, const AABB3& aabb ) const
{
	return magicalAABB3IntersectsPart( &out, this, &aabb );
}

inline bool AABB3::containsPoint( const Vector3& point ) const
{
	return magicalAABB3ContainsPoint( this, ( &point ) );
}