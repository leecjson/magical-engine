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

inline Vector2 Vector2::createZero( void )
{
	return Vector2::Zero;
}

inline Vector2 Vector2::createOne( void )
{
	return Vector2::One;
}

inline Vector2 Vector2::createFromVector3( const Vector3& v )
{
	return Vector2( v.x, v.y );
}

inline Vector2 Vector2::createFromVector4( const Vector4& v )
{
	return Vector2( v.x, v.y );
}

inline void Vector2::addScalar( Vector2& out, const Vector2& v, float a )
{
	magicalVector2AddScalar( &out, &v, a );
}

inline void Vector2::add( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	magicalVector2Add( &out, &v1, &v2 );
}

inline void Vector2::subScalar( Vector2& out, const Vector2& v, float a )
{
	magicalVector2SubScalar( &out, &v, a );
}

inline void Vector2::sub( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	magicalVector2Sub( &out, &v1, &v2 );
}

inline void Vector2::mulScalar( Vector2& out, const Vector2& v, float a )
{
	magicalVector2MulScalar( &out, &v, a );
}

inline void Vector2::mul( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	magicalVector2Mul( &out, &v1, &v2 );
}

inline void Vector2::divScalar( Vector2& out, const Vector2& v, float a )
{
	magicalVector2DivScalar( &out, &v, a );
}

inline void Vector2::div( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	magicalVector2Div( &out, &v1, &v2 );
}

inline void Vector2::clamp( Vector2& out, const Vector2& v, const Vector2& min, const Vector2& max )
{
	magicalVector2Clamp( &out, &v, &min, &max );
}

inline void Vector2::negate( Vector2& out, const Vector2& v )
{
	magicalVector2Negate( &out, &v );
}

inline void Vector2::normalize( Vector2& out, const Vector2& v )
{
	magicalVector2Normalize( &out, &v );
}

inline void Vector2::rotate( Vector2& out, const Vector2& v, float angle )
{
	magicalVector2Rotate( &out, &v, angle );
}

inline void Vector2::scale( Vector2& out, const Vector2& v, float s )
{
	magicalVector2Scale( &out, &v, s );
}

inline void Vector2::midPointBetween( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	magicalVector2MidPointBetween( &out, &v1, &v2 );
}

inline void Vector2::project( Vector2& out, const Vector2& v, const Vector2& n )
{
	magicalVector2Project( &out, &v, &n );
}

inline bool Vector2::equals( const Vector2& v ) const
{
	return magicalVector2Equals( this, &v );
}

inline bool Vector2::isZero( void ) const
{
	return magicalVector2IsZero( this );
}

inline bool Vector2::isOne( void ) const
{
	return magicalVector2IsOne( this );
}

inline bool Vector2::isNormalized( void ) const
{
	return magicalVector2IsNormalized( this );
}

inline bool Vector2::operator==( const Vector2& v ) const
{
	return magicalVector2Equals( this, &v );
}

inline bool Vector2::operator!=( const Vector2& v ) const
{
	return !magicalVector2Equals( this, &v );
}

inline float Vector2::operator[]( const unsigned int i ) const
{
#ifdef MAGICAL_DEBUG
	assert( 0 <= i && i <= 1 && "index out of range" );
#endif
	return ((float*)this)[i];
}

inline Vector2 Vector2::operator+( void ) const
{
	return *this;
}

inline Vector2 Vector2::operator+( float a ) const
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

inline Vector2 Vector2::operator-( float a ) const
{
	return Vector2( x - a, y - a );
}

inline Vector2 Vector2::operator-( const Vector2& v ) const
{
	return Vector2( x - v.x, y - v.y );
}

inline Vector2 Vector2::operator*( float a ) const
{
	return Vector2( x * a, y * a );
}

inline Vector2 Vector2::operator*( const Vector2& v ) const
{
	return Vector2( x * v.x, y * v.y );
}

inline Vector2 Vector2::operator/( float a ) const
{
	Vector2 ret;
	magicalVector2DivScalar( &ret, this, a );
	return ret;
}

inline Vector2 Vector2::operator/( const Vector2& v ) const
{
	Vector2 ret;
	magicalVector2Div( &ret, this, &v );
	return ret;
}

inline Vector2& Vector2::operator+=( float a )
{
	x += a; y += a;
	return *this;
}

inline Vector2& Vector2::operator+=( const Vector2& v )
{
	x += v.x; y += v.y;
	return *this;
}

inline Vector2& Vector2::operator-=( float a )
{
	x -= a; y -= a;
	return *this;
}

inline Vector2& Vector2::operator-=( const Vector2& v )
{
	x -= v.x; y -= v.y;
	return *this;
}

inline Vector2& Vector2::operator*=( float a )
{
	x *= a; y *= a;
	return *this;
}

inline Vector2& Vector2::operator*=( const Vector2& v )
{
	x *= v.x; y *= v.y;
	return *this;
}

inline Vector2& Vector2::operator/=( float a )
{
	magicalVector2DivScalar( this, this, a );
	return *this;
}

inline Vector2& Vector2::operator/=( const Vector2& v )
{
	magicalVector2Div( this, this, &v );
	return *this;
}

inline Vector2& Vector2::operator=( const Vector2& v )
{
	x = v.x; y = v.y;
	return *this;
}

inline void Vector2::set( const Vector2& v )
{
	x = v.x;
	y = v.y;
}

inline void Vector2::setZero( void )
{
	x = 0.0f;
	y = 0.0f;
}

inline void Vector2::setOne( void )
{
	x = 1.0f;
	y = 1.0f;
}

inline void Vector2::setScalars( float x, float y )
{
	this->x = x;
	this->y = y;
}

inline void Vector2::setVector3( const Vector3& v )
{
	x = v.x;
	y = v.y;
}

inline void Vector2::setVector4( const Vector3& v )
{
	x = v.x;
	y = v.y;
}

inline void Vector2::clamp( const Vector2& min, const Vector2& max )
{
	magicalVector2Clamp( this, this, &min, &max );
}

inline void Vector2::negate( void )
{
	magicalVector2Negate( this, this );
}

inline void Vector2::normalize( void )
{
	magicalVector2Normalize( this, this );
}

inline void Vector2::rotate( float angle )
{
	magicalVector2Rotate( this, this, angle );
}

inline void Vector2::scale( float s )
{
	magicalVector2Scale( this, this, s );
}

inline Vector2 Vector2::getClamped( const Vector2& min, const Vector2& max ) const
{
	Vector2 ret;
	magicalVector2Clamp( &ret, this, &min, &max );
	return ret;
}

inline Vector2 Vector2::getNegated( void ) const
{
	Vector2 ret;
	magicalVector2Negate( &ret, this );
	return ret;
}

inline Vector2 Vector2::getNormalized( void ) const
{
	Vector2 ret;
	magicalVector2Normalize( &ret, this );
	return ret;
}

inline Vector2 Vector2::getRotated( float angle ) const
{
	Vector2 ret;
	magicalVector2Rotate( &ret, this, angle );
	return ret;
}

inline Vector2 Vector2::getScaled( float s ) const
{
	Vector2 ret;
	magicalVector2Scale( &ret, this, s );
	return ret;
}

inline float Vector2::dot( const Vector2& v ) const
{
	return magicalVector2Dot( this, &v );
}

inline float Vector2::cross( const Vector2& v ) const
{
	return magicalVector2Cross( this, &v );
}

inline float Vector2::distanceBetween( const Vector2& v ) const
{
	return magicalVector2DistanceBetween( this, &v );
}

inline float Vector2::distanceBetweenSq( const Vector2& v ) const
{
	return magicalVector2DistanceBetweenSq( this, &v );
}

inline float Vector2::length( void ) const
{
	return magicalVector2Length( this );
}

inline float Vector2::lengthSq( void ) const
{
	return magicalVector2LengthSq( this );
}

inline float Vector2::angleBetween( const Vector2& v ) const
{
	return magicalVector2AngleBetween( this, &v );
}

inline Vector2 Vector2::midPointBetween( const Vector2& v ) const
{
	Vector2 ret;
	magicalVector2MidPointBetween( &ret, this, &v );
	return ret;
}

inline Vector2 Vector2::project( const Vector2& n ) const
{
	Vector2 ret;
	magicalVector2Project( &ret, this, &n );
	return ret;
}