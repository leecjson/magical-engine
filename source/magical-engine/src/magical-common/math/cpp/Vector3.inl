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

inline Vector3 Vector3::fromVector2( const Vector2& v )
{
	return Vector3( v );
}

inline Vector3 Vector3::fromVector4( const Vector4& v )
{
	return Vector3( v );
}

inline bool Vector3::equals( const Vector3& v ) const
{
	return magicalVector3Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vector3::isZero( void ) const
{
	return magicalVector3IsZero( tofpointer( this ) );
}

inline bool Vector3::isOne( void ) const
{
	return magicalVector3IsOne( tofpointer( this ) );
}

inline bool Vector3::isNormalized( void ) const
{
	return magicalVector3IsNormalized( tofpointer( this ) );
}

inline void Vector3::fill( const Vector3& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
}

inline void Vector3::fill( const float x, const float y, const float z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

inline void Vector3::fillZero( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

inline void Vector3::fillOne( void )
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
}

inline void Vector3::fillVector2( const Vector2& v )
{
	x = v.x;
	y = v.y;
	z = 0.0f;
}

inline void Vector3::fillVector4( const Vector4& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
}

inline void Vector3::addScalar( Vector3& out, const Vector3& v, const float a )
{
	magicalVector3AddScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector3::add( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3Add( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector3::subScalar( Vector3& out, const Vector3& v, const float a )
{
	magicalVector3SubScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector3::sub( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3Sub( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector3::mulMatrix( Vector3& out, const Vector3& v, const Matrix4& m )
{
	magicalVector3MulMatrix4( tofpointer( &out ), tofpointer( &v ), tofpointer( &m ) );
}

inline void Vector3::mulScalar( Vector3& out, const Vector3& v, const float a )
{
	magicalVector3MulScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector3::mul( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3Mul( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector3::divScalar( Vector3& out, const Vector3& v, const float a )
{
	magicalVector3DivScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector3::div( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3Div( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline bool Vector3::operator==( const Vector3& v ) const
{
	return magicalVector3Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vector3::operator!=( const Vector3& v ) const
{
	return !magicalVector3Equals( tofpointer( this ), tofpointer( &v ) );
}

inline Vector3 Vector3::operator+( const float a ) const
{
	return Vector3( x + a, y + a, z + a );
}

inline Vector3 Vector3::operator+( const Vector3& v ) const
{
	return Vector3( x + v.x, y + v.y, z + v.z );
}

inline Vector3 Vector3::operator-( const float a ) const
{
	return Vector3( x - a, y - a, z - a );
}

inline Vector3 Vector3::operator-( const Vector3& v ) const
{
	return Vector3( x - v.x, y - v.y, z - v.z );
}

inline Vector3 Vector3::operator*( const Matrix4& m ) const
{
	Vector3 ret;
	magicalVector3MulMatrix4( tofpointer( &ret ), tofpointer( this ), tofpointer( &m ) );
	return ret;
}

inline Vector3 Vector3::operator*( const float a ) const
{
	return Vector3( x * a, y * a, z * a );
}

inline Vector3 Vector3::operator*( const Vector3& v ) const
{
	return Vector3( x * v.x, y * v.y, z * v.z );
}

inline Vector3 Vector3::operator/( const float a ) const
{
	Vector3 ret;
	magicalVector3DivScalar( tofpointer( &ret ), tofpointer( this ), a );
	return ret;
}

inline Vector3 Vector3::operator/( const Vector3& v ) const
{
	Vector3 ret;
	magicalVector3Div( tofpointer( &ret ), tofpointer( this ), tofpointer( &v ) );
	return ret;
}

inline Vector3& Vector3::operator+=( const float a )
{
	x += a; y += a; z += a;
	return *this;
}

inline Vector3& Vector3::operator+=( const Vector3& v )
{
	x += v.x; y += v.y; z += v.z;
	return *this;
}

inline Vector3& Vector3::operator-=( const float a )
{
	x -= a; y -= a; z -= a;
	return *this;
}

inline Vector3& Vector3::operator-=( const Vector3& v )
{
	x -= v.x; y -= v.y; z -= v.z;
	return *this;
}

inline Vector3& Vector3::operator*=( const Matrix4& m )
{
	magicalVector3MulMatrix4( tofpointer( this ), tofpointer( this ), tofpointer( &m ) );
	return *this;
}

inline Vector3& Vector3::operator*=( const float a )
{
	x *= a; y *= a; z *= a;
	return *this;
}

inline Vector3& Vector3::operator*=( const Vector3& v )
{
	x *= v.x; y *= v.y; z *= v.z;
	return *this;
}

inline Vector3& Vector3::operator/=( const float a )
{
	magicalVector3DivScalar( tofpointer( this ), tofpointer( this ), a );
	return *this;
}

inline Vector3& Vector3::operator/=( const Vector3& v )
{
	magicalVector3Div( tofpointer( this ), tofpointer( this ), tofpointer( &v ) );
	return *this;
}

inline Vector3& Vector3::operator=( const Vector3& v )
{
	x = v.x; y = v.y; z = v.z;
	return *this;
}

inline void Vector3::cross( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3Cross( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector3::clamp( Vector3& out, const Vector3& v, const Vector3& min, const Vector3& max )
{
	magicalVector3Clamp( tofpointer( &out ), tofpointer( &v ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vector3::negate( Vector3& out, const Vector3& v )
{
	magicalVector3Negate( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vector3::normalize( Vector3& out, const Vector3& v )
{
	magicalVector3Normalize( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vector3::scale( Vector3& out, const Vector3& v, const float s )
{
	magicalVector3Scale( tofpointer( &out ), tofpointer( &v ), s );
}

inline void Vector3::midPointBetween( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3MidPointBetween( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector3::project( Vector3& out, const Vector3& v, const Vector3& n )
{
	magicalVector3Project( tofpointer( &out ), tofpointer( &v ), tofpointer( &n ) );
}

inline void Vector3::clamp( const Vector3& min, const Vector3& max )
{
	magicalVector3Clamp( tofpointer( this ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vector3::negate( void )
{
	magicalVector3Negate( tofpointer( this ), tofpointer( this ) );
}

inline void Vector3::normalize( void )
{
	magicalVector3Normalize( tofpointer( this ), tofpointer( this ) );
}

inline void Vector3::scale( const float s )
{
	magicalVector3Scale( tofpointer( this ), tofpointer( this ), s );
}

inline Vector3 Vector3::getClamped( const Vector3& min, const Vector3& max ) const
{
	Vector3 ret;
	magicalVector3Clamp( tofpointer( &ret ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
	return ret;
}

inline Vector3 Vector3::getNegated( void ) const
{
	Vector3 ret;
	magicalVector3Negate( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vector3 Vector3::getNormalized( void ) const
{
	Vector3 ret;
	magicalVector3Normalize( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vector3 Vector3::getScaled( const float s ) const
{
	Vector3 ret;
	magicalVector3Scale( tofpointer( &ret ), tofpointer( this ), s );
	return ret;
}

inline float Vector3::dot( const Vector3& v ) const
{
	return magicalVector3Dot( tofpointer( this ), tofpointer( &v ) );
}

inline float Vector3::distanceBetween( const Vector3& v ) const
{
	return magicalVector3DistanceBetween( tofpointer( this ), tofpointer( &v ) );
}

inline float Vector3::distanceBetweenSq( const Vector3& v ) const
{
	return magicalVector3DistanceBetweenSq( tofpointer( this ), tofpointer( &v ) );
}

inline float Vector3::length( void ) const
{
	return magicalVector3Length( tofpointer( this ) );
}

inline float Vector3::lengthSq( void ) const
{
	return magicalVector3LengthSq( tofpointer( this ) );
}

inline float Vector3::angleBetween( const Vector3& v ) const
{
	return magicalVector3AngleBetween( tofpointer( this ), tofpointer( &v ) );
}

inline Vector3 Vector3::cross( const Vector3& v ) const
{
	Vector3 ret;
	magicalVector3Cross( tofpointer( &ret ), tofpointer( this ), tofpointer( &v ) );
	return ret;
}

inline Vector3 Vector3::midPointBetween( const Vector3& v ) const
{
	Vector3 ret;
	magicalVector3MidPointBetween( tofpointer( &ret ), tofpointer( this ), tofpointer( &v ) );
	return ret;
}

inline Vector3 Vector3::project( const Vector3& n ) const
{
	Vector3 ret;
	magicalVector3Project( tofpointer( &ret ), tofpointer( this ), tofpointer( &n ) );
	return ret;
}