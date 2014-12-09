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

inline Sphere3 Sphere3::fromCenterAndRadius( const Vector3& center, const float r )
{
	Sphere3 ret;
	magicalSphere3FillCenterAndRadius( tofpointer( &ret ), tofpointer( &center ), r );
	return ret;
}

inline bool Sphere3::operator==( const Sphere3& sp ) const
{
	return magicalSphere3Equals( tofpointer( this ), tofpointer( &sp ) );
}

inline bool Sphere3::operator!=( const Sphere3& sp ) const
{
	return !magicalSphere3Equals( tofpointer( this ), tofpointer( &sp ) );
}

inline Sphere3& Sphere3::operator=( const Sphere3& sp )
{
	x = sp.x; y = sp.y; z = sp.z; r = sp.r;
	return *this;
}

inline bool Sphere3::isEquals( const Sphere3& sp ) const
{
	return magicalSphere3Equals( tofpointer( this ), tofpointer( &sp ) );
}

inline void Sphere3::fill( const float x, const float y, const float z, const float r )
{
	this->x = x; this->y = y; this->z = z; this->r = r;
}

inline void Sphere3::fill( const Vector3& center, const float r )
{
	x = center.x; y = center.y; z = center.z; this->r = r;
}

inline void Sphere3::fill( const Sphere3& sp )
{
	x = sp.x; y = sp.y; z = sp.z; r = sp.r;
}

inline bool Sphere3::intersects( const Sphere3& sp ) const
{
	return magicalSphere3Intersects( tofpointer( this ), tofpointer( &sp ) );
}

inline bool Sphere3::intersectsAABB3( const AABB3& aabb ) const
{
	return magicalSphere3IntersectsAABB3( tofpointer( this ), tofpointer( &aabb ) );
}

inline bool Sphere3::intersectsPlane3( const Plane3& p ) const
{
	return magicalSphere3IntersectsPlane3( tofpointer( this ), tofpointer( &p ) );
}

inline bool Sphere3::intersectsRay3( const Ray3& r3, const bool discard_inside ) const
{
	return magicalSphere3IntersectsRay3( tofpointer( this ), tofpointer( &r3 ), discard_inside );
}

inline bool Sphere3::intersectsRay3Distance( float& distance, const Ray3& r3, const bool discard_inside ) const
{
	return magicalSphere3IntersectsRay3Distance( &distance, tofpointer( this ), tofpointer( &r3 ), discard_inside );
}

inline bool Sphere3::containsPoint( const Vector3& point ) const
{
	return magicalSphere3ContainsPoint( tofpointer( this ), tofpointer( &point ) );
}