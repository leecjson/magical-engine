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

inline Box::Box( const Vector3& min, const Vector3& max ) 
: min( min ), max( max )
{
	
}

inline Box::Box( const Box& box ) 
: min( box.min ), max( box.max )
{
	
}

inline Box::Box( void ) 
{
	
}

inline bool Box::operator==( const Box& box ) const
{
	return equals( box );
}

inline bool Box::operator!=( const Box& box ) const
{
	return equals( box ) == false;
}

inline Box& Box::operator=( const Box& box )
{
	min = box.min;
	max = box.max;
	return *this;
}

inline void Box::set( const Vector3& min, const Vector3& max )
{
	this->min = min;
	this->max = max;
}

inline void Box::set( const Box& box )
{
	min = box.min;
	max = box.max;
}

inline Box Box::createOriginBox( const Vector3& origin, float w, float h, float d )
{
	Box dst;
	dst.setOriginBox( origin, w, h, d );
	return dst;
}

inline Box Box::createCenterBox( const Vector3& center, float w, float h, float d )
{
	Box dst;
	dst.setCenterBox( center, w, h, d );
	return dst;
}

inline Box Box::scale( const Box& box, float s )
{
	Box dst;
	Box::scale( dst, box, s );
	return dst;
}

inline Box Box::merge( const Box& box1, const Box& box2 )
{
	Box dst;
	Box::merge( dst, box1, box2 );
	return dst;
}

inline Box Box::transform( const Box& box, const Matrix4x4& m )
{
	Box dst;
	Box::transform( dst, box, m );
	return dst;
}

inline void Box::scale( float s )
{
	Box::scale( *this, *this, s );
}

inline void Box::merge( const Box& box )
{
	Box::merge( *this, *this, box );
}

inline Vector3 Box::center( void ) const
{
	Vector3 dst;
	Box::center( dst, *this );
	return dst;
}

inline Vector3 Box::closest( const Vector3& v ) const
{
	Vector3 dst;
	Box::closest( dst, *this, v );
	return dst;
}

inline void Box::transform( const Matrix4x4& m )
{
	Box::transform( *this, *this, m );
}

inline void Box::shrink( float w, float h, float d )
{
	Vector3 amount( w, h, d );
	amount.scale( 0.5f );

	max -= amount;
	min += amount;
}

inline void Box::shrink( float a )
{
	max -= a * 0.5f;
	min += a * 0.5f;
}

inline void Box::expand( float w, float h, float d )
{
	Vector3 amount( w, h, d );
	amount.scale( 0.5f );

	max += amount;
	min -= amount;
}

inline void Box::expand( float a )
{
	max += a * 0.5f;
	min -= a * 0.5f;
}

inline void Box::expandBy( const Vector3& v )
{
	if( v.x < min.x ) min.x = v.x;
	if( v.y < min.y ) min.y = v.y;
	if( v.z < min.z ) min.z = v.z;
	if( v.x > max.x ) max.x = v.x;
	if( v.y > max.y ) max.y = v.y;
	if( v.z > max.z ) max.z = v.z;
} 

inline float Box::size( void ) const
{
	float x = max.x - min.x;
	float y = max.y - min.y;
	float z = max.z - min.z;

	return sqrtf( x * x + y * y + z * z );
}

inline float Box::width( void ) const
{
	return max.x - min.x;
}

inline float Box::height( void ) const
{
	return max.y - min.y;
}

inline float Box::depth( void ) const
{
	return max.z - min.z;
}

inline bool Box::intersects( const Plane& plane ) const
{
	return plane.classify( *this ) == Plane::Classification::OnPlane;
}

inline bool Box::intersects( float& distance, const Ray& ray, bool discard_inside ) const
{
	return ray.intersects( distance, *this, discard_inside );
}

NAMESPACE_END