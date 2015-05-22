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
#ifndef __BOX_H__
#define __BOX_H__

struct Box
{
	Vector3 min;
	Vector3 max;

public:
	static const Box Invalid;

public:
	inline Box( const Vector3& min, const Vector3& max );
	inline Box( const Box& box );
	inline Box( void );

public:
	inline bool operator==( const Box& box ) const;
	inline bool operator!=( const Box& box ) const;
	inline Box& operator=( const Box& box );

public:
	bool equals( const Box& box ) const;
	bool isValid( void ) const;
	inline void set( const Vector3& min, const Vector3& max );
	inline void set( const Box& box );
	void setOriginBox( const Vector3& origin, float w, float h, float d );
	void setCenterBox( const Vector3& center, float w, float h, float d );
	static inline Box createOriginBox( const Vector3& origin, float w, float h, float d );
	static inline Box createCenterBox( const Vector3& center, float w, float h, float d );
	
public:
	static void scale( Box& out, const Box& box, float s );
	static void merge( Box& out, const Box& box1, const Box& box2 );
	static void center( Vector3& out, const Box& box );
	static void closest( Vector3& out, const Box& box, const Vector3& v );
	static void transform( Box& out, const Box& box, const Matrix4x4& m );
	static inline Box scale( const Box& box, float s );
	static inline Box merge( const Box& box1, const Box& box2 );
	static inline Box transform( const Box& box, const Matrix4x4& m );
	inline void scale( float s );
	inline void merge( const Box& box );
	inline Vector3 center( void ) const;
	inline Vector3 closest( const Vector3& v ) const;
	inline void transform( const Matrix4x4& m );

public:
	inline void shrink( float w, float h, float d );
	inline void shrink( float a );
	inline void expand( float w, float h, float d );
	inline void expand( float a );
	inline void expandBy( const Vector3& v );
	inline float size( void ) const;
	inline float width( void ) const;
	inline float height( void ) const;
	inline float depth( void ) const;

public:
	bool intersects( const Box& box ) const;
	inline bool intersects( const Plane& plane ) const;
	bool intersects( const Sphere& sphere ) const;
	inline bool intersects( float& distance, const Ray& ray, bool discard_inside = false ) const;
	bool containsPoint( const Vector3& point ) const;
};

#endif //__BOX_H__