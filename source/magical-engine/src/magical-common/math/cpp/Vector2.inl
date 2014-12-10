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

inline Vector2 Vector2::fromZero( void )
{
	return Vector2::Zero;
}

inline Vector2 Vector2::fromOne( void )
{
	return Vector2::One;
}

inline Vector2 Vector2::fromVector3( const Vector3& v )
{
	return Vector2( v.x, v.y );
}

inline Vector2 Vector2::fromVector4( const Vector4& v )
{
	return Vector2( v.x, v.y );
}

inline void Vector2::addScalar( Vector2& out, const Vector2& v, const float a )
{
	magicalVector2AddScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector2::add( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	magicalVector2Add( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector2::subScalar( Vector2& out, const Vector2& v, const float a )
{
	magicalVector2SubScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector2::sub( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	magicalVector2Sub( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector2::mulScalar( Vector2& out, const Vector2& v, const float a )
{
	magicalVector2MulScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector2::mul( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	magicalVector2Mul( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector2::divScalar( Vector2& out, const Vector2& v, const float a )
{
	magicalVector2DivScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vector2::div( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	magicalVector2Div( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector2::clamp( Vector2& out, const Vector2& v, const Vector2& min, const Vector2& max )
{
	magicalVector2Clamp( tofpointer( &out ), tofpointer( &v ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vector2::negate( Vector2& out, const Vector2& v )
{
	magicalVector2Negate( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vector2::normalize( Vector2& out, const Vector2& v )
{
	magicalVector2Normalize( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vector2::rotate( Vector2& out, const Vector2& v, const float angle )
{
	magicalVector2Rotate( tofpointer( &out ), tofpointer( &v ), angle );
}

inline void Vector2::scale( Vector2& out, const Vector2& v, const float s )
{
	magicalVector2Scale( tofpointer( &out ), tofpointer( &v ), s );
}

inline void Vector2::midPointBetween( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	magicalVector2MidPointBetween( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vector2::project( Vector2& out, const Vector2& v, const Vector2& n )
{
	magicalVector2Project( tofpointer( &out ), tofpointer( &v ), tofpointer( &n ) );
}

inline bool Vector2::equals( const Vector2& v ) const
{
	return magicalVector2Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vector2::isZero( void ) const
{
	return magicalVector2IsZero( tofpointer( this ) );
}

inline bool Vector2::isOne( void ) const
{
	return magicalVector2IsOne( tofpointer( this ) );
}

inline bool Vector2::isNormalized( void ) const
{
	return magicalVector2IsNormalized( tofpointer( this ) );
}

inline void Vector2::fill( const Vector2& v )
{
	x = v.x; y = v.y;
}

inline void Vector2::fillZero( void )
{
	x = 0.0f; y = 0.0f;
}

inline void Vector2::fillOne( void )
{
	x = 1.0f; y = 1.0f;
}

inline void Vector2::fillScalars( const float x, const float y )
{
	this->x = x; this->y = y;
}

inline void Vector2::fillVector3( const Vector3& v )
{
	x = v.x; y = v.y;
}

inline void Vector2::fillVector4( const Vector3& v )
{
	x = v.x; y = v.y;
}

inline bool Vector2::operator==( const Vector2& v ) const
{
	return magicalVector2Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vector2::operator!=( const Vector2& v ) const
{
	return !magicalVector2Equals( tofpointer( this ), tofpointer( &v ) );
}

inline float Vector2::operator[]( const unsigned int i ) const
{
#if MAGICAL_DEBUG
	assert( 0 <= i && i <= 1 && "index out of range" );
#endif
	return ((float*)this)[i];
}

inline Vector2 Vector2::operator+( void ) const
{
	return *this;
}

inline Vector2 Vector2::operator+( const float a ) const
{
	return Vector2( x + a, y + a );
}

inline Vector2 Vector2::operator+( const Vector2& v ) const
{
	return Vector2( x + v.x, y + v.y );
}

inline Vector2 Vector2::operator-( void ) const
{
	return Vector2( -x, -y );
}

inline Vector2 Vector2::operator-( const float a ) const
{
	return Vector2( x - a, y - a );
}

inline Vector2 Vector2::operator-( const Vector2& v ) const
{
	return Vector2( x - v.x, y - v.y );
}

inline Vector2 Vector2::operator*( const float a ) const
{
	return Vector2( x * a, y * a );
}

inline Vector2 Vector2::operator*( const Vector2& v ) const
{
	return Vector2( x * v.x, y * v.y );
}

inline Vector2 Vector2::operator/( const float a ) const
{
	Vector2 ret;
	magicalVector2DivScalar( tofpointer( &ret ), tofpointer( this ), a );
	return ret;
}

inline Vector2 Vector2::operator/( const Vector2& v ) const
{
	Vector2 ret;
	magicalVector2Div( tofpointer( &ret ), tofpointer( this ), tofpointer( &v ) );
	return ret;
}

inline Vector2& Vector2::operator+=( const float a )
{
	x += a; y += a;
	return *this;
}

inline Vector2& Vector2::operator+=( const Vector2& v )
{
	x += v.x; y += v.y;
	return *this;
}

inline Vector2& Vector2::operator-=( const float a )
{
	x -= a; y -= a;
	return *this;
}

inline Vector2& Vector2::operator-=( const Vector2& v )
{
	x -= v.x; y -= v.y;
	return *this;
}

inline Vector2& Vector2::operator*=( const float a )
{
	x *= a; y *= a;
	return *this;
}

inline Vector2& Vector2::operator*=( const Vector2& v )
{
	x *= v.x; y *= v.y;
	return *this;
}

inline Vector2& Vector2::operator/=( const float a )
{
	magicalVector2DivScalar( tofpointer( this ), tofpointer( this ), a );
	return *this;
}

inline Vector2& Vector2::operator/=( const Vector2& v )
{
	magicalVector2Div( tofpointer( this ), tofpointer( this ), tofpointer( &v ) );
	return *this;
}

inline Vector2& Vector2::operator=( const Vector2& v )
{
	x = v.x; y = v.y;
	return *this;
}

inline void Vector2::clamp( const Vector2& min, const Vector2& max )
{
	magicalVector2Clamp( tofpointer( this ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vector2::negate( void )
{
	magicalVector2Negate( tofpointer( this ), tofpointer( this ) );
}

inline void Vector2::normalize( void )
{
	magicalVector2Normalize( tofpointer( this ), tofpointer( this ) );
}

inline void Vector2::rotate( const float angle )
{
	magicalVector2Rotate( tofpointer( this ), tofpointer( this ), angle );
}

inline void Vector2::scale( const float s )
{
	magicalVector2Scale( tofpointer( this ), tofpointer( this ), s );
}

inline Vector2 Vector2::getClamped( const Vector2& min, const Vector2& max ) const
{
	Vector2 ret;
	magicalVector2Clamp( tofpointer( &ret ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
	return ret;
}

inline Vector2 Vector2::getNegated( void ) const
{
	Vector2 ret;
	magicalVector2Negate( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vector2 Vector2::getNormalized( void ) const
{
	Vector2 ret;
	magicalVector2Normalize( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vector2 Vector2::getRotated( const float angle ) const
{
	Vector2 ret;
	magicalVector2Rotate( tofpointer( &ret ), tofpointer( this ), angle );
	return ret;
}

inline Vector2 Vector2::getScaled( const float s ) const
{
	Vector2 ret;
	magicalVector2Scale( tofpointer( &ret ), tofpointer( this ), s );
	return ret;
}

inline float Vector2::dot( const Vector2& v ) const
{
	return magicalVector2Dot( tofpointer( this ), tofpointer( &v ) );
}

inline float Vector2::cross( const Vector2& v ) const
{
	return magicalVector2Cross( tofpointer( this ), tofpointer( &v ) );
}

inline float Vector2::distanceBetween( const Vector2& v ) const
{
	return magicalVector2DistanceBetween( tofpointer( this ), tofpointer( &v ) );
}

inline float Vector2::distanceBetweenSq( const Vector2& v ) const
{
	return magicalVector2DistanceBetweenSq( tofpointer( this ), tofpointer( &v ) );
}

inline float Vector2::length( void ) const
{
	return magicalVector2Length( tofpointer( this ) );
}

inline float Vector2::lengthSq( void ) const
{
	return magicalVector2LengthSq( tofpointer( this ) );
}

inline float Vector2::angleBetween( const Vector2& v ) const
{
	return magicalVector2AngleBetween( tofpointer( this ), tofpointer( &v ) );
}

inline Vector2 Vector2::midPointBetween( const Vector2& v ) const
{
	Vector2 ret;
	magicalVector2MidPointBetween( tofpointer( &ret ), tofpointer( this ), tofpointer( &v ) );
	return ret;
}

inline Vector2 Vector2::project( const Vector2& n ) const
{
	Vector2 ret;
	magicalVector2Project( tofpointer( &ret ), tofpointer( this ), tofpointer( &n ) );
	return ret;
}