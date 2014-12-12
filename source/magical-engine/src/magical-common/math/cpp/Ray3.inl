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

inline Ray3 Ray3::fromZero( void )
{
	return Ray3::Zero;
}

inline Ray3 Ray3::fromOriginToEnd( const Vector3& origin, const Vector3& end )
{
	Ray3 ret;
	magicalRay3FillOriginToEnd( tofpointer( &ret ), tofpointer( &origin ), tofpointer( &end ) );
	return ret;
}

inline Ray3 Ray3::fromOriginAndDirection( const Vector3& origin, const Vector3& direction )
{
	Ray3 ret;
	magicalRay3FillOriginAndDirection( tofpointer( &ret ), tofpointer( &origin ), tofpointer( &direction ) );
	return ret;
}

inline void Ray3::getOrigin( Vector3& out, const Ray3& r3 )
{
	magicalRay3GetOrigin( tofpointer( &out ), tofpointer( &r3 ) );
}

inline void Ray3::getDirection( Vector3& out, const Ray3& r3 )
{
	magicalRay3GetDirection( tofpointer( &out ), tofpointer( &r3 ) );
}

inline void Ray3::directionNormalize( Ray3& out, const Ray3& r3 )
{
	magicalRay3DirectionNormalize( tofpointer( &out ), tofpointer( &r3 ) );
}

inline bool Ray3::equals( const Ray3& r3 ) const
{
	return magicalRay3Equals( tofpointer( this ), tofpointer( &r3 ) );
}

inline bool Ray3::isZero( void ) const
{
	return magicalRay3IsZero( tofpointer( this ) );
}

inline void Ray3::fill( const Ray3& r3 )
{
	magicalRay3Fill( tofpointer( this ), tofpointer( &r3 ) );
}

inline void Ray3::fillZero( void )
{
	magicalRay3FillZero( tofpointer( this ) );
}

inline void Ray3::fillScalars( const float ox, const float oy, const float oz, const float dx, const float dy, const float dz )
{
	magicalRay3FillScalars( tofpointer( this ), ox, oy, oz, dx, dy, dz );
}

inline void Ray3::fillOriginToEnd( const Vector3& origin, const Vector3& end )
{
	magicalRay3FillOriginToEnd( tofpointer( this ), tofpointer( &origin ), tofpointer( &end ) );
}

inline void Ray3::fillOriginAndDirection( const Vector3& origin, const Vector3& direction )
{
	magicalRay3FillOriginAndDirection( tofpointer( this ), tofpointer( &origin ), tofpointer( &direction ) );
}

inline bool Ray3::operator==( const Ray3& r3 ) const
{
	return magicalRay3Equals( tofpointer( this ), tofpointer( &r3 ) );
}

inline bool Ray3::operator!=( const Ray3& r3 ) const
{
	return !magicalRay3Equals( tofpointer( this ), tofpointer( &r3 ) );
}

inline Ray3& Ray3::operator=( const Ray3& r3 )
{
	magicalRay3Fill( tofpointer( this ), tofpointer( &r3 ) );
	return *this;
}

inline Vector3 Ray3::getOrigin( void ) const
{
	return Vector3( ox, oy, oz );
}

inline Vector3 Ray3::getDirection( void ) const
{
	return Vector3( dx, dy, dz );
}

inline void Ray3::setOrigin( const Vector3& origin )
{
	magicalRay3SetOrigin( tofpointer( this ), tofpointer( &origin ) );
}

inline void Ray3::setDirection( const Vector3& direction )
{
	magicalRay3SetDirection( tofpointer( this ), tofpointer( &direction ) );
}

inline void Ray3::directionNormalize( void )
{
	magicalRay3DirectionNormalize( tofpointer( this ), tofpointer( this ) );
}

inline bool Ray3::intersectsPlane3( const Plane3& p, const bool discard_inside ) const
{
	return magicalRay3IntersectsPlane3( tofpointer( this ), tofpointer( &p ), discard_inside );
}

inline bool Ray3::intersectsAABB3( const AABB3& aabb, const bool discard_inside ) const
{
	return magicalRay3IntersectsAABB3( tofpointer( this ), tofpointer( &aabb ), discard_inside );
}

inline bool Ray3::intersectsSphere3( const Sphere3& sp, const bool discard_inside ) const
{
	return magicalRay3IntersectsSphere3( tofpointer( this ), tofpointer( &sp ), discard_inside );
}

inline bool Ray3::intersectsPlane3Distance( float& distance, const Plane3& p, const bool discard_inside ) const
{
	return magicalRay3IntersectsPlane3Distance( &distance, tofpointer( this ), tofpointer( &p ), discard_inside );
}

inline bool Ray3::intersectsAABB3Distance( float& distance, const AABB3& aabb, const bool discard_inside ) const
{
	return magicalRay3IntersectsAABB3Distance( &distance, tofpointer( this ), tofpointer( &aabb ), discard_inside );
}

inline bool Ray3::intersectsSphere3Distance( float& distance, const Sphere3& sp, const bool discard_inside ) const
{
	return magicalRay3IntersectsSphere3Distance( &distance, tofpointer( this ), tofpointer( &sp ), discard_inside );
}