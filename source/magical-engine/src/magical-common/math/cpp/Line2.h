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
#ifndef __LINE2_H__
#define __LINE2_H__

class Vector2;

enum class Line2Classification
{
	Front = 1,
	OnLine = 0,
	Behind = -1,
	Parallel = 1,
	Intersect = 0,
	Vertical = -1,
};

class Line2
{
public:
	float x;
	float y;
	float d;

public:
	static const Line2 Zero;
	static Line2 placeholder;
	static Line2 temp;

public:
	Line2( const float x, const float y, const float d );
	Line2( const Line2& l );
	Line2( void );

public:
	static inline Line2 fromZero( void );
	static inline Line2 fromNormalAndDistance( const Vector2& n, const float d );
	static inline Line2 fromNormalAndPoint( const Vector2& n, const Vector2& a );

public:
	inline bool equals( const Line2& l ) const;
	inline bool isZero( void ) const;
	inline void fill( const Line2& l );
	inline void fillZero( void );
	inline void fillScalars( const float x, const float y, const float d );
	inline void fillNormalAndDistance( const Vector2& n, const float d );
	inline void fillNormalAndPoint( const Vector2& n, const Vector2& a );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Line2& l ) const;
	inline bool operator!=( const Line2& l ) const;
	inline Line2& operator=( const Line2& l );

public:
	inline Line2Classification classifyPoint( const Vector2& point ) const;
	inline Line2Classification classifyLine( const Line2& l ) const;

	inline bool intersects( const Line2& l ) const;
	inline bool containsPoint( const Line2& l ) const;
};

#endif //__LINE2_H__