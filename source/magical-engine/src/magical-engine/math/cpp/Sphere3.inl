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

inline Sphere3 Sphere3::createZero( void )
{
	return Sphere3::Zero;
}

inline Sphere3 Sphere3::createOne( void )
{
	return Sphere3::One;
}

inline Sphere3 Sphere3::createFromCenterAndRadius( const Vector3& center, float r )
{
	Sphere3 ret;
	magicalSphere3SetCenterAndRadius( &ret, &center, r );
	return ret;
}

inline bool Sphere3::equals( const Sphere3& sp ) const
{
	return magicalSphere3Equals( this, &sp );
}

inline bool Sphere3::isZero( void ) const
{
	return magicalSphere3IsZero( this );
}

inline bool Sphere3::isOne( void ) const
{
	return magicalSphere3IsOne( this );
}

inline void Sphere3::set( const Sphere3& sp )
{
	magicalSphere3Copy( this, &sp );
}

inline void Sphere3::setZero( void )
{
	magicalSphere3SetZero( this );
}

inline void Sphere3::setOne( void )
{
	magicalSphere3SetOne( this );
}

inline void Sphere3::setScalars( float x, float y, float z, float r )
{
	magicalSphere3Fill( this, x, y, z, r );
}

inline void Sphere3::setCenterAndRadius( const Vector3& center, float r )
{
	magicalSphere3SetCenterAndRadius( this, &center, r );
}

inline bool Sphere3::operator==( const Sphere3& sp ) const
{
	return magicalSphere3Equals( this, &sp );
}

inline bool Sphere3::operator!=( const Sphere3& sp ) const
{
	return !magicalSphere3Equals( this, &sp );
}

inline Sphere3& Sphere3::operator=( const Sphere3& sp )
{
	magicalSphere3Copy( this, &sp );
	return *this;
}

inline bool Sphere3::intersects( const Sphere3& sp ) const
{
	return magicalSphere3Intersects( this, &sp );
}

inline bool Sphere3::intersectsAABB3( const AABB3& aabb ) const
{
	return magicalSphere3IntersectsAABB3( this, &aabb );
}

inline bool Sphere3::intersectsPlane3( const Plane3& p ) const
{
	return magicalSphere3IntersectsPlane3( this, &p );
}

inline void Sphere3::intersectsRay3( RayIntersectResult& out, const Ray3& r3, bool discard_inside ) const
{
	magicalSphere3IntersectsRay3( &out, this, &r3, discard_inside );
}

inline bool Sphere3::containsPoint( const Vector3& point ) const
{
	return magicalSphere3ContainsPoint( this, &point );
}