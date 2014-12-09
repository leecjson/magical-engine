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

inline Vector4 Vector4::fromVector2( const Vector2& v )
{
	return Vector4( v );
}

inline Vector4 Vector4::fromVector3( const Vector3& v )
{
	return Vector4( v );
}

inline bool Vector4::equals( const Vector4& v ) const
{
	return magicalVector4Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vector4::isZero( void ) const
{
	return magicalVector4IsZero( tofpointer( this ) );
}

inline bool Vector4::isOne( void ) const
{
	return magicalVector4IsOne( tofpointer( this ) );
}

inline bool Vector4::isNormalized( void ) const
{
	return magicalVector4IsNormalized( tofpointer( this ) );
}

inline void Vector4::fill( const float x, const float y, const float z, const float w )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

inline void Vector4::fill( const Vector4& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void Vector4::fillZero( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

inline void Vector4::fillOne( void )
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
	w = 1.0f;
}

inline void Vector4::fillVector2( const Vector2& v )
{
	x = v.x;
	y = v.y;
	z = 0.0f;
	w = 0.0f;
}

inline void Vector4::fillVector3( const Vector3& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = 0.0f;
}

inline void Vector4::addScalar( Vector4& out, const Vector4& v, const float a )
{
	magicalVector4AddScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector4::add( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	magicalVector4Add( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector4::subScalar( Vector4& out, const Vector4& v, const float a )
{
	magicalVector4SubScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector4::sub( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	magicalVector4Sub( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector4::mulMatrix( Vector4& out, const Vector4& v, const Matrix4& m )
{
	magicalVector4MulMatrix4( tofpointer( &out ), tofpointer( &v ), tofpointer( &m ) );
}

inline void Vector4::mulScalar( Vector4& out, const Vector4& v, const float a )
{
	magicalVector4MulScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector4::mul( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	magicalVector4Mul( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector4::divScalar( Vector4& out, const Vector4& v, const float a )
{
	magicalVector4DivScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector4::div( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	magicalVector4Div( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline bool Vector4::operator==( const Vector4& v ) const
{
	return magicalVector4Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vector4::operator!=( const Vector4& v ) const
{
	return !magicalVector4Equals( tofpointer( this ), tofpointer( &v ) );
}

inline Vector4 Vector4::operator+( const float a ) const
{
	return Vector4( x + a, y + a, z + a, w + a );
}

inline Vector4 Vector4::operator+( const Vector4& v ) const
{
	return Vector4( x + v.x, y + v.y, z + v.z, w + v.w );
}

inline Vector4 Vector4::operator-( const float a ) const
{
	return Vector4( x - a, y - a, z - a, w - a );
}

inline Vector4 Vector4::operator-( const Vector4& v ) const
{
	return Vector4( x - v.x, y - v.y, z - v.z, w - v.w );
}

inline Vector4 Vector4::operator*( const Matrix4& m ) const
{
	Vector4 ret;
	magicalVector4MulMatrix4( tofpointer( &ret ), tofpointer( this ), tofpointer( &m ) );
	return ret;
}

inline Vector4 Vector4::operator*( const float a ) const
{
	return Vector4( x * a, y * a, z * a, w * a );
}

inline Vector4 Vector4::operator*( const Vector4& v ) const
{
	return Vector4( x * v.x, y * v.y, z * v.z, w * v.w );
}

inline Vector4 Vector4::operator/( const float a ) const
{
	Vector4 ret;
	magicalVector4DivScalar( tofpointer( &ret ), tofpointer( this ), a );
	return ret;
}

inline Vector4 Vector4::operator/( const Vector4& v ) const
{
	Vector4 ret;
	magicalVector4Div( tofpointer( &ret ), tofpointer( this ), tofpointer( &v ) );
	return ret;
}

inline Vector4& Vector4::operator+=( const float a )
{
	x += a; y += a; z += a; w += a;
	return *this;
}

inline Vector4& Vector4::operator+=( const Vector4& v )
{
	x += v.x; y += v.y; z += v.z; w += v.w;
	return *this;
}

inline Vector4& Vector4::operator-=( const float a )
{
	x -= a; y -= a; z -= a; w -= a;
	return *this;
}

inline Vector4& Vector4::operator-=( const Vector4& v )
{
	x -= v.x; y -= v.y; z -= v.z; w -= v.w;
	return *this;
}

inline Vector4& Vector4::operator*=( const Matrix4& m )
{
	magicalVector4MulMatrix4( tofpointer( this ), tofpointer( this ), tofpointer( &m ) );
	return *this;
}

inline Vector4& Vector4::operator*=( const float a )
{
	x *= a; y *= a; z *= a; w *= a;
	return *this;
}

inline Vector4& Vector4::operator*=( const Vector4& v )
{
	x *= v.x; y *= v.y; z *= v.z; w *= v.w;
	return *this;
}

inline Vector4& Vector4::operator/=( const float a )
{
	magicalVector4DivScalar( tofpointer( this ), tofpointer( this ), a );
	return *this;
}

inline Vector4& Vector4::operator/=( const Vector4& v )
{
	magicalVector4Div( tofpointer( this ), tofpointer( this ), tofpointer( &v ) );
	return *this;
}

inline Vector4& Vector4::operator=( const Vector4& v )
{
	x = v.x; y = v.y; z = v.z; w = v.w;
}

inline void Vector4::clamp( Vector4& out, const Vector4& v, const Vector4& min, const Vector4& max )
{
	magicalVector4Clamp( tofpointer( &out ), tofpointer( &v ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vector4::negate( Vector4& out, const Vector4& v )
{
	magicalVector4Negate( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vector4::normalize( Vector4& out, const Vector4& v )
{
	magicalVector4Normalize( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vector4::scale( Vector4& out, const Vector4& v, const float s )
{
	magicalVector4Scale( tofpointer( &out ), tofpointer( &v ), s );
}

inline void Vector4::midPointBetween( Vector4& out, const Vector4& v1, const Vector4& v2  )
{
	magicalVector4MidPointBetween( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector4::project( Vector4& out, const Vector4& v, const Vector4& n )
{
	magicalVector4Project( tofpointer( &out ), tofpointer( &v ), tofpointer( &n ) );
}

inline void Vector4::clamp( const Vector4& min, const Vector4& max )
{
	magicalVector4Clamp( tofpointer( this ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vector4::negate( void )
{
	magicalVector4Negate( tofpointer( this ), tofpointer( this ) );
}

inline void Vector4::normalize( void )
{
	magicalVector4Normalize( tofpointer( this ), tofpointer( this ) );
}

inline void Vector4::scale( const float s )
{
	magicalVector4Scale( tofpointer( this ), tofpointer( this ), s );
}

inline Vector4 Vector4::getClamped( const Vector4& min, const Vector4& max ) const
{
	Vector4 ret;
	magicalVector4Clamp( tofpointer( &ret ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
	return ret;
}

inline Vector4 Vector4::getNegated( void ) const
{
	Vector4 ret;
	magicalVector4Negate( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vector4 Vector4::getNormalized( void ) const
{
	Vector4 ret;
	magicalVector4Normalize( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vector4 Vector4::getScaled( const float s ) const
{
	Vector4 ret;
	magicalVector4Scale( tofpointer( &ret ), tofpointer( this ), s );
	return ret;
}

inline float Vector4::dot( const Vector4& v ) const
{
	return magicalVector4Dot( tofpointer( this ), tofpointer( &v ) );
}

inline float Vector4::distanceBetween( const Vector4& v ) const
{
	return magicalVector4DistanceBetween( tofpointer( this ), tofpointer( &v ) );
}

inline float Vector4::distanceBetweenSq( const Vector4& v ) const
{
	return magicalVector4DistanceBetweenSq( tofpointer( this ), tofpointer( &v ) );
}

inline float Vector4::length( void ) const
{
	return magicalVector4Length( tofpointer( this ) );
}

inline float Vector4::lengthSq( void ) const
{
	return magicalVector4LengthSq( tofpointer( this ) );
}

inline float Vector4::angleBetween( const Vector4& v ) const
{
	return magicalVector4AngleBetween( tofpointer( this ), tofpointer( &v ) );
}

inline Vector4 Vector4::midPointBetween( const Vector4& v ) const
{
	Vector4 ret;
	magicalVector4MidPointBetween( tofpointer( &ret ), tofpointer( this ), tofpointer( &v ) );
	return ret;
}

inline Vector4 Vector4::project( const Vector4& n ) const
{
	Vector4 ret;
	magicalVector4Project( tofpointer( &ret ), tofpointer( this ), tofpointer( &n ) );
	return ret;
}