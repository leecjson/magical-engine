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

inline Ray3 Ray3::createZero( void )
{
	return Ray3::Zero;
}

inline Ray3 Ray3::createFromOriginToEnd( const Vector3& origin, const Vector3& end )
{
	Ray3 ret;
	magicalRay3SetOriginToEnd( &ret, &origin, &end );
	return ret;
}

inline Ray3 Ray3::createFromOriginAndDirection( const Vector3& origin, const Vector3& direction )
{
	Ray3 ret;
	magicalRay3SetOriginAndDirection( &ret, &origin, &direction );
	return ret;
}

inline void Ray3::getOrigin( Vector3& out, const Ray3& r3 )
{
	magicalRay3GetOrigin( &out, &r3 );
}

inline void Ray3::getDirection( Vector3& out, const Ray3& r3 )
{
	magicalRay3GetDirection( &out, &r3 );
}

inline bool Ray3::equals( const Ray3& r3 ) const
{
	return magicalRay3Equals( this, &r3 );
}

inline bool Ray3::isZero( void ) const
{
	return magicalRay3IsZero( this );
}

inline bool Ray3::operator==( const Ray3& r3 ) const
{
	return magicalRay3Equals( this, &r3 );
}

inline bool Ray3::operator!=( const Ray3& r3 ) const
{
	return !magicalRay3Equals( this, &r3 );
}

inline Ray3& Ray3::operator=( const Ray3& r3 )
{
	magicalRay3Copy( this, &r3 );
	return *this;
}

inline void Ray3::set( const Ray3& r3 )
{
	magicalRay3Copy( this, &r3 );
}

inline void Ray3::setZero( void )
{
	magicalRay3SetZero( this );
}

inline void Ray3::setScalars( float ox, float oy, float oz, float dx, float dy, float dz )
{
	magicalRay3Fill( this, ox, oy, oz, dx, dy, dz );
}

inline void Ray3::fromOriginToEnd( const Vector3& origin, const Vector3& end )
{
	magicalRay3SetOriginToEnd( this, &origin, &end );
}

inline void Ray3::fromOriginAndDirection( const Vector3& origin, const Vector3& direction )
{
	magicalRay3SetOriginAndDirection( this, &origin, &direction );
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
	magicalRay3SetOrigin( this, &origin );
}

inline void Ray3::setDirection( const Vector3& direction )
{
	magicalRay3SetDirection( this, &direction );
}

inline void Ray3::intersectsPlane3( RayIntersectResult& out, const Plane3& p, bool discard_inside ) const
{
	return magicalRay3IntersectsPlane3( &out, this, &p, discard_inside );
}

inline void Ray3::intersectsAABB3( RayIntersectResult& out, const AABB3& aabb, bool discard_inside ) const
{
	return magicalRay3IntersectsAABB3( &out, this, &aabb, discard_inside );
}

inline void Ray3::intersectsSphere3( RayIntersectResult& out, const Sphere3& sp, bool discard_inside ) const
{
	return magicalRay3IntersectsSphere3( &out, this, &sp, discard_inside );
}