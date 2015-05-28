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
#ifndef __CIRCLE_H__
#define __CIRCLE_H__

struct Circle
{
	union
	{
		struct {
			float x;
			float y;
			float r;
		};
		struct { Vector2 center; float r; };
	};

public:
	static const Circle One;
	static const Circle Invalid;

public:
	inline Circle( float x, float y, float r );
	inline Circle( const Vector2& center, float r );
	inline Circle( const Circle& circle );
	inline Circle( void );

public:
	inline bool operator==( const Circle& circle ) const;
	inline bool operator!=( const Circle& circle ) const;
	inline Circle& operator=( const Circle& circle );

public:
	inline bool equals( const Circle& circle ) const;
	inline bool isValid( void ) const;
	inline void set( const Circle& circle );
	inline void set( const Vector2& center, float r );
	inline void set( float x, float y, float z, float r );

public:
	static void scale( Circle& out, const Circle& circle, float s );
	static void merge( Circle& out, const Circle& circle1, const Circle& circle2 );
	static void closest( Vector2& out, const Circle& circle, const Vector2& v );
	static inline Circle scale( const Circle& circle, float s );
	static inline Circle merge( const Circle& circle1, const Circle& circle2 );
	inline void scale( float s );
	inline void merge( const Circle& circle );
	inline Vector2 closest( const Vector2& v );

public:
	inline bool containsPoint( const Vector2& point ) const;
};

#endif //__CIRCLE_H__
