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

inline AABB3 fromMinMax( const Vec3& min, const Vec3& max )
{
	AABB3 ret;
	magicalAABB3FillMinMax( tofpointer( &ret ), tofpointer( &min ), tofpointer( &max ) );
	return ret;
}

inline AABB3 fromBox( const Vec3& center, const float width, const float height, const float depth )
{
	AABB3 ret;
	magicalAABB3FillBox( tofpointer( &ret ), tofpointer( &center ), width, height, depth );
	return ret;
}

inline void AABB3::mul( AABB3& out, const AABB3& aabb, const Mat4& m )
{
	magicalAABB3Transform( tofpointer( &out ), tofpointer( &aabb ), tofpointer( &m ) );
}

inline void AABB3::getMin( Vec3& out, const AABB3& aabb )
{
	magicalAABB3GetMin( tofpointer( &out ), tofpointer( &aabb ) );
}

inline void AABB3::getMax( Vec3& out, const AABB3& aabb )
{
	magicalAABB3GetMax( tofpointer( &out ), tofpointer( &aabb ) );
}

inline void AABB3::extend( Vec3& out, const AABB3& aabb, const float x, const float y, const float z )
{
	magicalAABB3ExtendScalars( tofpointer( &out ), tofpointer( &aabb ), x, y, z );
}

inline void AABB3::extend( Vec3& out, const AABB3& aabb, const Vec3& v )
{
	magicalAABB3Extend( tofpointer( &out ), tofpointer( &aabb ), tofpointer( &v ) );
}

inline void AABB3::merge( AABB3& out, const AABB3& aabb1, const AABB3& aabb2 )
{
	magicalAABB3Merge( tofpointer( &out ), tofpointer( &aabb1 ), tofpointer( &aabb2 ) );
}

inline void AABB3::getCenter( Vec3& out, const AABB3& aabb )
{
	magicalAABB3Center( tofpointer( &out ), tofpointer( &aabb ) );
}

inline void AABB3::nearestPoint( Vec3& out, const AABB3& aabb, const Vec3& point )
{
	magicalAABB3NearestPoint( tofpointer( &out ), tofpointer( &aabb ), tofpointer( &point ) );
}

inline bool AABB3::operator==( const AABB3& aabb ) const
{
	return magicalAABB3Equals( tofpointer( this ), tofpointer( &aabb ) );
}

inline bool AABB3::operator!=( const AABB3& aabb ) const
{
	return !magicalAABB3Equals( tofpointer( this ), tofpointer( &aabb ) );
}

inline AABB3 AABB3::operator*( const Mat4& m ) const
{
	AABB3 ret;
	magicalAABB3Transform( tofpointer( &ret ), tofpointer( this ), tofpointer( &m ) );
	return ret;
}

inline AABB3& AABB3::operator*=( const Mat4& m )
{
	magicalAABB3Transform( tofpointer( this ), tofpointer( this ), tofpointer( &m ) );
	return *this;
}

inline AABB3& AABB3::operator=( const AABB3& aabb )
{
	magicalAABB3Fill( tofpointer( this ), tofpointer( &aabb ) );
	return *this;
}

inline bool AABB3::isIdentity( void ) const
{
	return magicalAABB3IsIdentity( tofpointer( this ) );
}

inline bool AABB3::isEquals( const AABB3& aabb ) const
{
	return magicalAABB3Equals( tofpointer( this ), tofpointer( &aabb ) );
}

inline void AABB3::fill( const AABB3& aabb )
{
	magicalAABB3Fill( tofpointer( this ), tofpointer( &aabb ) );
}

inline void AABB3::fill( const float min_x, const float min_y, const float min_z, const float max_x, const float max_y, const float max_z )
{
	magicalAABB3FillScalars( tofpointer( this ), min_x, min_y, min_z, max_x, max_y, max_z );
}

inline void AABB3::fillIdentity( void )
{
	magicalAABB3FillIdentity( tofpointer( this ) );
}

inline void AABB3::fillMinMax( const Vec3& min, const Vec3& max )
{
	magicalAABB3FillMinMax( tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
}

inline void AABB3::fillBox( const Vec3& center, const float width, const float height, const float depth )
{
	magicalAABB3FillBox( tofpointer( this ), tofpointer( &center ), width, height, depth );
}
	
inline Vec3 AABB3::getMin( void ) const
{
	return Vec3( min_x, min_y, min_z );
}

inline Vec3 AABB3::getMax( void ) const
{
	return Vec3( max_x, max_y, max_z );
}

inline void AABB3::setMin( const Vec3& min )
{
	magicalAABB3SetMin( tofpointer( this ), tofpointer( &min ) );
}

inline void AABB3::setMax( const Vec3& max )
{
	magicalAABB3SetMax( tofpointer( this ), tofpointer( &max ) );
}

inline void AABB3::extend( const float x, const float y, const float z )
{
	magicalAABB3ExtendScalars( tofpointer( this ), tofpointer( this ), x, y, z );
}

inline void AABB3::extend( const Vec3& v )
{
	magicalAABB3Extend( tofpointer( this ), tofpointer( this ), tofpointer( &v ) );
}

inline void AABB3::merge( const AABB3& aabb )
{
	magicalAABB3Merge( tofpointer( this ), tofpointer( this ), tofpointer( &aabb ) );
}

inline Vec3 AABB3::nearestPoint( const Vec3& point ) const
{
	Vec3 ret;
	magicalAABB3NearestPoint( tofpointer( &ret ), tofpointer( this ), tofpointer( &point ) );
	return ret;
}

inline float AABB3::size( void ) const
{
	return magicalAABB3Size( tofpointer( this ) );
}

inline float AABB3::diameterX( void ) const
{
	return magicalAABB3DiameterX( tofpointer( this ) );
}

inline float AABB3::diameterY( void ) const
{
	return magicalAABB3DiameterY( tofpointer( this ) );
}

inline float AABB3::diameterZ( void ) const
{
	return magicalAABB3DiameterZ( tofpointer( this ) );
}

inline AABB3 AABB3::getMerge( const AABB3& aabb ) const
{
	AABB3 ret;
	magicalAABB3Merge( tofpointer( &ret ), tofpointer( this ), tofpointer( &aabb ) );
	return ret;
}

inline Vec3 AABB3::getCenter( void ) const
{
	Vec3 ret;
	magicalAABB3Center( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline bool AABB3::intersects( const AABB3& aabb ) const
{
	return magicalAABB3Intersects( tofpointer( this ), tofpointer( &aabb ) );
}

inline bool AABB3::intersectsPlane3( const Plane3& p ) const
{
	return magicalAABB3IntersectsPlane3( tofpointer( this ), tofpointer( &p ) );
}

inline bool AABB3::intersectsSphere3( const Sphere3& sp ) const
{
	return magicalAABB3IntersectsSphere3( tofpointer( this ), tofpointer( &sp ) );
}

inline bool AABB3::intersectsRay3( const Ray3& r3, const bool discard_inside ) const
{
	return magicalAABB3IntersectsRay3( tofpointer( this ), tofpointer( &r3 ), discard_inside );
}

inline bool AABB3::intersectsRay3Distance( float& distance, const Ray3& r3, const bool discard_inside ) const
{
	return magicalAABB3IntersectsRay3Distance( &distance, tofpointer( this ), tofpointer( &r3 ), discard_inside );
}

inline bool AABB3::intersectsPart( AABB3& out, const AABB3& aabb ) const
{
	return magicalAABB3IntersectsPart( tofpointer( &out ), tofpointer( this ), tofpointer( &aabb ) );
}

inline bool AABB3::containsPoint( const Vec3& point ) const
{
	return magicalAABB3ContainsPoint( tofpointer( this ), tofpointer( &point ) );
}