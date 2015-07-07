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
NAMESPACE_MAGICAL

inline Ray::Ray( const Vector3& origin, const Vector3& direction ) 
: origin( origin ), direction( direction )
{
	
}

inline Ray::Ray( const Ray& ray ) 
: origin( ray.origin ), direction( ray.direction )
{
	
}

inline Ray::Ray( void )
{
	
}

inline bool Ray::operator==( const Ray& ray ) const
{
	return equals( ray );
}

inline bool Ray::operator!=( const Ray& ray ) const
{
	return equals( ray ) == false;
}

inline Ray& Ray::operator=( const Ray& ray )
{
	origin = ray.origin;
	direction = ray.direction;
	return *this;
}

inline bool Ray::equals( const Ray& ray ) const
{
	return
		Math::isAlmostEqual( ox, ray.ox, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( oy, ray.oy, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( oz, ray.oz, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( dx, ray.dx, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( dy, ray.dy, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( dz, ray.dz, Math::VectorEpsilon );
}

inline bool Ray::isValid( void ) const
{
	return !(
		Math::isAlmostZero( dx, Math::VectorEpsilon ) &&
		Math::isAlmostZero( dy, Math::VectorEpsilon ) &&
		Math::isAlmostZero( dz, Math::VectorEpsilon ) );
}

inline void Ray::set( const Vector3& origin, const Vector3& direction )
{
	this->origin = origin;
	this->direction = direction;
}

inline void Ray::set( const Ray& ray )
{
	origin = ray.origin;
	direction = ray.direction;
}

inline void Ray::setOriginToEnd( const Vector3& origin, const Vector3& end )
{
	Vector3 nd = end - origin;
	nd.normalize();

	this->origin = origin;
	this->direction = nd;
}

inline Ray Ray::createOriginToEnd( const Vector3& origin, const Vector3& end )
{
	Ray dst;
	dst.setOriginToEnd( origin, end );
	return dst;
}

NAMESPACE_END