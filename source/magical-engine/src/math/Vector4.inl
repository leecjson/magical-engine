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

inline Vector4::Vector4( const Vector3& v ) 
: x( v.x ), y( v.y ), z( v.z ), w( 0.0f )
{

}

inline Vector4::Vector4( float v ) 
: x( v ), y( v ), z( v ), w( v )
{
	
}

inline Vector4::Vector4( float x, float y, float z, float w ) 
: x( x ), y( y ), z( z ), w( w )
{
	
}

inline Vector4::Vector4( const Vector4& v ) 
: x( v.x ), y( v.y ), z( v.z ), w( v.w )
{
	
}

inline Vector4::Vector4( void )
{

}

inline bool Vector4::operator==( const Vector4& v ) const
{
	return equals( v );
}

inline bool Vector4::operator!=( const Vector4& v ) const
{
	return equals( v ) == false;
}

inline float& Vector4::operator[]( size_t i ) const
{
	debugassert( 0 <= i && i <= 3, "index out of range" );
	
	return ((float*)this)[i];
}

inline Vector4& Vector4::operator=( float v )
{
	x = v;
	y = v;
	z = v;
	w = v;
	return *this;
}

inline Vector4& Vector4::operator=( const Vector4& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}

inline Vector4 Vector4::operator+( void ) const
{
	return *this;
}

inline Vector4 Vector4::operator+( float a ) const
{
	return Vector4( x + a, y + a, z + a, w + a );
}

inline Vector4 Vector4::operator+( const Vector4& v ) const
{
	return Vector4( x + v.x, y + v.y, z + v.z, w + v.w );
}

inline Vector4 Vector4::operator-( void ) const
{
	return Vector4( -x, -y, -z, -w );
}

inline Vector4 Vector4::operator-( float a ) const
{
	return Vector4( x - a, y - a, z - a, w - a );
}

inline Vector4 Vector4::operator-( const Vector4& v ) const
{
	return Vector4( x - v.x, y - v.y, z - v.z, w - v.w );
}

inline Vector4 Vector4::operator*( const Matrix4x4& m ) const
{
	Vector4 dst;
	Vector4::mulMatrix4x4( dst, *this, m );
	return dst;
}

inline Vector4 Vector4::operator*( float a ) const
{
	return Vector4( x * a, y * a, z * a, w * a );
}

inline Vector4 Vector4::operator*( const Vector4& v ) const
{
	return Vector4( x * v.x, y * v.y, z * v.z, w * v.w );
}

inline Vector4 Vector4::operator/( float a ) const
{
	return Vector4( x / a, y / a, z / a, w / a );
}

inline Vector4 Vector4::operator/( const Vector4& v ) const
{
	return Vector4( x / v.x, y / v.y, z / v.z, w / v.w );
}

inline Vector4& Vector4::operator+=( float a )
{
	x += a;
	y += a;
	z += a;
	w += a;
	return *this;
}

inline Vector4& Vector4::operator+=( const Vector4& v )
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

inline Vector4& Vector4::operator-=( float a )
{
	x -= a;
	y -= a;
	z -= a;
	w -= a;
	return *this;
}

inline Vector4& Vector4::operator-=( const Vector4& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

inline Vector4& Vector4::operator*=( const Matrix4x4& m )
{
	Vector4::mulMatrix4x4( *this, *this, m );
	return *this;
}

inline Vector4& Vector4::operator*=( float a )
{
	x *= a;
	y *= a;
	z *= a;
	w *= a;
	return *this;
}

inline Vector4& Vector4::operator*=( const Vector4& v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
	return *this;
}

inline Vector4& Vector4::operator/=( float a )
{
	x /= a;
	y /= a;
	z /= a;
	w /= a;
	return *this;
}

inline Vector4& Vector4::operator/=( const Vector4& v )
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;
	return *this;
}

inline void Vector4::add( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	out.x = v1.x + v2.x;
	out.y = v1.y + v2.y;
	out.z = v1.z + v2.z;
	out.w = v1.w + v2.w;
}

inline void Vector4::sub( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	out.x = v1.x - v2.x;
	out.y = v1.y - v2.y;
	out.z = v1.z - v2.z;
	out.w = v1.w - v2.w;
}

inline void Vector4::mul( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	out.x = v1.x * v2.x;
	out.y = v1.y * v2.y;
	out.z = v1.z * v2.z;
	out.w = v1.w * v2.w;
}

inline void Vector4::div( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	out.x = v1.x / v2.x;
	out.y = v1.y / v2.y;
	out.z = v1.z / v2.z;
	out.w = v1.w / v2.w;
}

inline void Vector4::addScalar( Vector4& out, const Vector4& v, float a )
{
	out.x = v.x + a;
	out.y = v.y + a;
	out.z = v.z + a;
	out.w = v.w + a;
}

inline void Vector4::subScalar( Vector4& out, const Vector4& v, float a )
{
	out.x = v.x - a;
	out.y = v.y - a;
	out.z = v.z - a;
	out.w = v.w - a;
}

inline void Vector4::mulScalar( Vector4& out, const Vector4& v, float a )
{
	out.x = v.x * a;
	out.y = v.y * a;
	out.z = v.z * a;
	out.w = v.w * a;
}

inline void Vector4::divScalar( Vector4& out, const Vector4& v, float a )
{
	out.x = v.x / a;
	out.y = v.y / a;
	out.z = v.z / a;
	out.w = v.w / a;
}

inline Vector4 Vector4::add( const Vector4& v1, const Vector4& v2 )
{
	return Vector4( v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w );
}

inline Vector4 Vector4::sub( const Vector4& v1, const Vector4& v2 )
{
	return Vector4( v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w );
}

inline Vector4 Vector4::mul( const Vector4& v1, const Vector4& v2 )
{
	return Vector4( v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w );
}

inline Vector4 Vector4::div( const Vector4& v1, const Vector4& v2 )
{
	return Vector4( v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w );
}

inline Vector4 Vector4::addScalar( const Vector4& v, float a )
{
	return Vector4( v.x + a, v.y + a, v.z + a, v.w + a );
}

inline Vector4 Vector4::subScalar( const Vector4& v, float a )
{
	return Vector4( v.x - a, v.y - a, v.z - a, v.w - a );
}

inline Vector4 Vector4::mulScalar( const Vector4& v, float a )
{
	return Vector4( v.x * a, v.y * a, v.z * a, v.w * a );
}

inline Vector4 Vector4::divScalar( const Vector4& v, float a )
{
	return Vector4( v.x / a, v.y / a, v.z / a, v.w / a );
}

inline Vector4 Vector4::mulMatrix4x4( const Vector4& v, const Matrix4x4& m )
{
	Vector4 dst;
	Vector4::mulMatrix4x4( dst, v, m );
	return dst;
}

inline void Vector4::add( const Vector4& v )
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

inline void Vector4::sub( const Vector4& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}

inline void Vector4::mul( const Vector4& v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
}

inline void Vector4::div( const Vector4& v )
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;
}

inline void Vector4::addScalar( float a )
{
	x += a;
	y += a;
	z += a;
	w += a;
}

inline void Vector4::subScalar( float a )
{
	x -= a;
	y -= a;
	z -= a;
	w -= a;
}

inline void Vector4::mulScalar( float a )
{
	x *= a;
	y *= a;
	z *= a;
	w *= a;
}

inline void Vector4::divScalar( float a )
{
	x /= a;
	y /= a;
	z /= a;
	w /= a;
}

inline void Vector4::mulMatrix4x4( const Matrix4x4& m )
{
	Vector4::mulMatrix4x4( *this, *this, m );
}

inline bool Vector4::equals( const Vector4& v ) const
{
	return
		Math::isAlmostEqual( x, v.x, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( y, v.y, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( z, v.z, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( w, v.w, Math::VectorEpsilon );
}

inline bool Vector4::isZero( void ) const
{
	return
		Math::isAlmostZero( x, Math::VectorEpsilon ) &&
		Math::isAlmostZero( y, Math::VectorEpsilon ) &&
		Math::isAlmostZero( z, Math::VectorEpsilon ) &&
		Math::isAlmostZero( w, Math::VectorEpsilon );
}

inline bool Vector4::isOne( void ) const
{
	return
		Math::isAlmostEqual( x, 1.0f, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( y, 1.0f, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( z, 1.0f, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( w, 1.0f, Math::VectorEpsilon );
}

inline void Vector4::setZero( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

inline void Vector4::setOne( void )
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
	w = 1.0f;
}

inline void Vector4::set( const Vector3& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = 0.0f;
}

inline void Vector4::set( const Vector4& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void Vector4::set( float x, float y, float z, float w )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}