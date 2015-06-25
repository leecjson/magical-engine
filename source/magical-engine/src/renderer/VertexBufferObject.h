/******************************************************************************
The MIT License (MIT)

Copyright (c) 2014 Jason.lee

Permission is hereby granted, free of charge, to any person obtaining a vertex
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, vertex, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above vertexright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/
#ifndef __VERTEX_BUFFER_OBJECT_H__
#define __VERTEX_BUFFER_OBJECT_H__

#include "magical-macros.h"
#include "Common.h"
#include "Reference.h"

#include "RenderDefine.h"
#include "Shaders.h"
#include <vector>

NAMESPACE_MAGICAL

class VertexBufferObject : public Reference
{
public:
	VertexBufferObject( void );
	virtual ~VertexBufferObject( void );
	static Ptr<VertexBufferObject> create( void );

public:
	void beginCopyData( size_t vertex_count, size_t indices_count = 0 );
	void endCopyData( void );
	void enableVertexAttrib( unsigned int index, size_t size, int type, bool normalized );
	void clean( void );

public:
	inline void vertex1b( Shader::bool_t x );
	inline void vertex2b( Shader::bool_t x, Shader::bool_t y );
	inline void vertex3b( Shader::bool_t x, Shader::bool_t y, Shader::bool_t z );
	inline void vertex4b( Shader::bool_t x, Shader::bool_t y, Shader::bool_t z, Shader::bool_t w );
	inline void vertex2bv( const Shader::bool_t* v );
	inline void vertex3bv( const Shader::bool_t* v );
	inline void vertex4bv( const Shader::bool_t* v );
	inline void vertex1i( Shader::int_t x );
	inline void vertex2i( Shader::int_t x, Shader::int_t y );
	inline void vertex3i( Shader::int_t x, Shader::int_t y, Shader::int_t z );
	inline void vertex4i( Shader::int_t x, Shader::int_t y, Shader::int_t z, Shader::int_t w );
	inline void vertex2iv( const Shader::int_t* v );
	inline void vertex3iv( const Shader::int_t* v );
	inline void vertex4iv( const Shader::int_t* v );
	inline void vertex1f( Shader::float_t x );
	inline void vertex2f( Shader::float_t x, Shader::float_t y );
	inline void vertex3f( Shader::float_t x, Shader::float_t y, Shader::float_t z );
	inline void vertex4f( Shader::float_t x, Shader::float_t y, Shader::float_t z, Shader::float_t w );
	inline void vertex2fv( const Shader::float_t* v );
	inline void vertex3fv( const Shader::float_t* v );
	inline void vertex4fv( const Shader::float_t* v );
	inline void vertexIndex( Shader::uint_t i );

protected:
	friend class Renderer;
	bool m_copying = false;
	bool m_empty = true;
	size_t m_vertices_count = 0;
	size_t m_indices_count = 0;

protected:
	struct VertexAttrib {
		unsigned int index;
		size_t size;
		int type;
		bool normalized;
		size_t offset;
	};
	std::vector<VertexAttrib> m_vertex_attribs;
	
protected:
#ifdef MAGICAL_USING_GL
	GLuint m_vbo_vertices;
	GLuint m_vbo_indices;
#endif
};

NAMESPACE_END


#endif //__VERTEX_BUFFER_OBJECT_H__