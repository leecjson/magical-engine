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

inline Sphere Sphere::createZero( void )
{
	return Sphere::Zero;
}

inline Sphere Sphere::createOne( void )
{
	return Sphere::One;
}

inline Sphere Sphere::createFromCenterAndRadius( const Vector3& center, float r )
{
	Sphere ret;
	magicalSphereSetCenterAndRadius( &ret, &center, r );
	return ret;
}

inline bool Sphere::equals( const Sphere& sp ) const
{
	return magicalSphereEquals( this, &sp );
}

inline bool Sphere::isZero( void ) const
{
	return magicalSphereIsZero( this );
}

inline bool Sphere::isOne( void ) const
{
	return magicalSphereIsOne( this );
}

inline void Sphere::set( const Sphere& sp )
{
	magicalSphereCopy( this, &sp );
}

inline void Sphere::setZero( void )
{
	magicalSphereSetZero( this );
}

inline void Sphere::setOne( void )
{
	magicalSphereSetOne( this );
}

inline void Sphere::setScalars( float x, float y, float z, float r )
{
	magicalSphereFill( this, x, y, z, r );
}

inline void Sphere::setCenterAndRadius( const Vector3& center, float r )
{
	magicalSphereSetCenterAndRadius( this, &center, r );
}

inline bool Sphere::operator==( const Sphere& sp ) const
{
	return magicalSphereEquals( this, &sp );
}

inline bool Sphere::operator!=( const Sphere& sp ) const
{
	return !magicalSphereEquals( this, &sp );
}

inline Sphere& Sphere::operator=( const Sphere& sp )
{
	magicalSphereCopy( this, &sp );
	return *this;
}

inline bool Sphere::intersects( const Sphere& sp ) const
{
	return magicalSphereIntersects( this, &sp );
}

inline bool Sphere::intersectsAABB3( const AABB3& aabb ) const
{
	return magicalSphereIntersectsAABB3( this, &aabb );
}

inline bool Sphere::intersectsPlane( const Plane& p ) const
{
	return magicalSphereIntersectsPlane( this, &p );
}

inline bool Sphere::intersectsRay3( float& outt, const Ray3& r3, bool discard_inside ) const
{
	return magicalSphereIntersectsRay3( &outt, this, &r3, discard_inside );
}

inline bool Sphere::containsPoint( const Vector3& point ) const
{
	return magicalSphereContainsPoint( this, &point );
}

NS_MAGICAL_END