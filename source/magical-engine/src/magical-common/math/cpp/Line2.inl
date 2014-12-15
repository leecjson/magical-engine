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

inline Line2 Line2::fromZero( void )
{
	return Line2::Zero;
}

inline Line2 Line2::fromNormalAndDistance( const Vector2& n, const float d )
{
	Line2 ret;
	magicalLine2FillNormalAndDistance( tofpointer( &ret ), tofpointer( &n ), d );
	return ret;
}

inline Line2 Line2::fromNormalAndPoint( const Vector2& n, const Vector2& a )
{
	Line2 ret;
	magicalLine2FillNormalAndPoint( tofpointer( &ret ), tofpointer( &n ), tofpointer( &a ) );
	return ret;
}

inline bool Line2::equals( const Line2& l ) const
{
	return magicalLine2Equals( tofpointer( this ), tofpointer( &l ) );
}

inline bool Line2::isZero( void ) const
{
	return magicalLine2IsZero( tofpointer( this ) );
}

inline void Line2::fill( const Line2& l )
{
	magicalLine2Fill( tofpointer( this ), tofpointer( &l ) );
}

inline void Line2::fillZero( void )
{
	magicalLine2FillZero( tofpointer( this ) );
}

inline void Line2::fillScalars( const float x, const float y, const float d )
{
	magicalLine2FillScalars( tofpointer( this ), x, y, d );
}

inline void Line2::fillNormalAndDistance( const Vector2& n, const float d )
{
	magicalLine2FillNormalAndDistance( tofpointer( this ), tofpointer( &n ), d );
}

inline void Line2::fillNormalAndPoint( const Vector2& n, const Vector2& a )
{
	magicalLine2FillNormalAndPoint( tofpointer( this ), tofpointer( &n ), tofpointer( &a ) );
}

inline bool Line2::operator==( const Line2& l ) const
{
	return magicalLine2Equals( tofpointer( this ), tofpointer( &l ) );
}

inline bool Line2::operator!=( const Line2& l ) const
{
	return !magicalLine2Equals( tofpointer( this ), tofpointer( &l ) );
}

inline Line2& Line2::operator=( const Line2& l )
{
	magicalLine2Fill( tofpointer( this ), tofpointer( &l ) );
	return *this;
}

inline Line2Classification Line2::classifyPoint( const Vector2& point ) const
{
	return (Line2Classification)magicalLine2ClassifyPoint( tofpointer( this ), tofpointer( &point ) );
}

inline Line2Classification Line2::classifyLine( const Line2& l ) const
{
	return (Line2Classification)magicalLine2ClassifyLine2( tofpointer( this ), tofpointer( &l ) );
}

inline bool Line2::intersects( const Line2& l ) const
{
	return magicalLine2Intersects( tofpointer( this ), tofpointer( &l ) );
}

inline bool Line2::containsPoint( const Line2& l ) const
{
	return magicalLine2ContainsPoint( tofpointer( this ), tofpointer( &l ) );
}
