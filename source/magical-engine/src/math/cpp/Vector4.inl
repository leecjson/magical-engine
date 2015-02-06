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

inline Vector4 Vector4::createZero( void )
{
	return Vector4::Zero;
}

inline Vector4 Vector4::createOne( void )
{
	return Vector4::One;
}

inline Vector4 Vector4::createFromVector2( const Vector2& v )
{
	return Vector4( v.x, v.y, 0.0f, 0.0f );
}

inline Vector4 Vector4::createFromVector3( const Vector3& v )
{
	return Vector4( v.x, v.y, v.z, 0.0f );
}

inline void Vector4::addScalar( Vector4& out, const Vector4& v, float a )
{
	magicalVector4AddScalar( &out, &v, a );
}

inline void Vector4::add( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	magicalVector4Add( &out, &v1, &v2 );
}

inline void Vector4::subScalar( Vector4& out, const Vector4& v, float a )
{
	magicalVector4SubScalar( &out, &v, a );
}

inline void Vector4::sub( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	magicalVector4Sub( &out, &v1, &v2 );
}

inline void Vector4::mulMatrix4( Vector4& out, const Vector4& v, const Matrix4& m )
{
	magicalVector4MulMatrix4( &out, &v, &m );
}

inline void Vector4::mulScalar( Vector4& out, const Vector4& v, float a )
{
	magicalVector4MulScalar( &out, &v, a );
}

inline void Vector4::mul( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	magicalVector4Mul( &out, &v1, &v2 );
}

inline void Vector4::divScalar( Vector4& out, const Vector4& v, float a )
{
	magicalVector4DivScalar( &out, &v, a );
}

inline void Vector4::div( Vector4& out, const Vector4& v1, const Vector4& v2 )
{
	magicalVector4Div( &out, &v1, &v2 );
}

inline void Vector4::clamp( Vector4& out, const Vector4& v, const Vector4& min, const Vector4& max )
{
	magicalVector4Clamp( &out, &v, &min, &max );
}

inline void Vector4::negate( Vector4& out, const Vector4& v )
{
	magicalVector4Negate( &out, &v );
}

inline void Vector4::normalize( Vector4& out, const Vector4& v )
{
	magicalVector4Normalize( &out, &v );
}

inline void Vector4::scale( Vector4& out, const Vector4& v, float s )
{
	magicalVector4Scale( &out, &v, s );
}

inline void Vector4::midPointBetween( Vector4& out, const Vector4& v1, const Vector4& v2  )
{
	magicalVector4MidPointBetween( &out, &v1, &v2 );
}

inline void Vector4::project( Vector4& out, const Vector4& v, const Vector4& n )
{
	magicalVector4Project( &out, &v, &n );
}

inline bool Vector4::equals( const Vector4& v ) const
{
	return magicalVector4Equals( this, &v );
}

inline bool Vector4::isZero( void ) const
{
	return magicalVector4IsZero( this );
}

inline bool Vector4::isOne( void ) const
{
	return magicalVector4IsOne( this );
}

inline bool Vector4::isNormalized( void ) const
{
	return magicalVector4IsNormalized( this );
}

inline bool Vector4::operator==( const Vector4& v ) const
{
	return magicalVector4Equals( this, &v );
}

inline bool Vector4::operator!=( const Vector4& v ) const
{
	return !magicalVector4Equals( this, &v );
}

inline float& Vector4::operator[]( size_t i ) const
{
#ifdef MAGICAL_DEBUG
	assert( 0 <= i && i <= 3 && "index out of range" );
#endif
	return ((float*)this)[i];
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

inline Vector4 Vector4::operator*( const Matrix4& m ) const
{
	Vector4 ret;
	magicalVector4MulMatrix4( &ret, this, &m );
	return ret;
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
	Vector4 ret;
	magicalVector4DivScalar( &ret, this, a );
	return ret;
}

inline Vector4 Vector4::operator/( const Vector4& v ) const
{
	Vector4 ret;
	magicalVector4Div( &ret, this, &v );
	return ret;
}

inline Vector4& Vector4::operator+=( float a )
{
	x += a; y += a; z += a; w += a;
	return *this;
}

inline Vector4& Vector4::operator+=( const Vector4& v )
{
	x += v.x; y += v.y; z += v.z; w += v.w;
	return *this;
}

inline Vector4& Vector4::operator-=( float a )
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
	magicalVector4MulMatrix4( this, this, &m );
	return *this;
}

inline Vector4& Vector4::operator*=( float a )
{
	x *= a; y *= a; z *= a; w *= a;
	return *this;
}

inline Vector4& Vector4::operator*=( const Vector4& v )
{
	x *= v.x; y *= v.y; z *= v.z; w *= v.w;
	return *this;
}

inline Vector4& Vector4::operator/=( float a )
{
	magicalVector4DivScalar( this, this, a );
	return *this;
}

inline Vector4& Vector4::operator/=( const Vector4& v )
{
	magicalVector4Div( this, this, &v );
	return *this;
}

inline Vector4& Vector4::operator=( const Vector4& v )
{
	x = v.x; y = v.y; z = v.z; w = v.w;
	return *this;
}

inline void Vector4::set( const Vector4& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
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

inline void Vector4::setScalars( float x, float y, float z, float w )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

inline void Vector4::fromVector2( const Vector2& v )
{
	x = v.x;
	y = v.y;
	z = 0.0f;
	w = 0.0f;
}

inline void Vector4::fromVector3( const Vector3& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = 0.0f;
}

inline void Vector4::clamp( const Vector4& min, const Vector4& max )
{
	magicalVector4Clamp( this, this, &min, &max );
}

inline void Vector4::negate( void )
{
	magicalVector4Negate( this, this );
}

inline void Vector4::normalize( void )
{
	magicalVector4Normalize( this, this );
}

inline void Vector4::scale( float s )
{
	magicalVector4Scale( this, this, s );
}

inline Vector4 Vector4::getClamped( const Vector4& min, const Vector4& max ) const
{
	Vector4 ret;
	magicalVector4Clamp( &ret, this, &min, &max );
	return ret;
}

inline Vector4 Vector4::getNegated( void ) const
{
	Vector4 ret;
	magicalVector4Negate( &ret, this );
	return ret;
}

inline Vector4 Vector4::getNormalized( void ) const
{
	Vector4 ret;
	magicalVector4Normalize( &ret, this );
	return ret;
}

inline Vector4 Vector4::getScaled( float s ) const
{
	Vector4 ret;
	magicalVector4Scale( &ret, this, s );
	return ret;
}

inline float Vector4::dot( const Vector4& v ) const
{
	return magicalVector4Dot( this, &v );
}

inline float Vector4::distanceBetween( const Vector4& v ) const
{
	return magicalVector4DistanceBetween( this, &v );
}

inline float Vector4::distanceBetweenSq( const Vector4& v ) const
{
	return magicalVector4DistanceBetweenSq( this, &v );
}

inline float Vector4::length( void ) const
{
	return magicalVector4Length( this );
}

inline float Vector4::lengthSq( void ) const
{
	return magicalVector4LengthSq( this );
}

inline float Vector4::angleBetween( const Vector4& v ) const
{
	return magicalVector4AngleBetween( this, &v );
}

inline Vector4 Vector4::midPointBetween( const Vector4& v ) const
{
	Vector4 ret;
	magicalVector4MidPointBetween( &ret, this, &v );
	return ret;
}

inline Vector4 Vector4::project( const Vector4& n ) const
{
	Vector4 ret;
	magicalVector4Project( &ret, this, &n );
	return ret;
}

NS_MAGICAL_END