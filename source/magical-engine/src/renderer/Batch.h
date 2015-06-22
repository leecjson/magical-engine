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
#ifndef __BATCH_H__
#define __BATCH_H__

#include "magical-macros.h"
#include "Common.h"
#include "Reference.h"

#include "RenderDefine.h"
#include "Shaders.h"

NAMESPACE_MAGICAL

class Batch : public Reference
{
public:
	Batch( void );
	virtual ~Batch( void );
	static Ptr<Batch> create( void );

public:
	void draw( unsigned int draw_mode, size_t vertex_count, size_t indices_count = 0 );
	void enableVertexAttrib( unsigned int vertex_index, size_t sizeof_vertex );
	void disableVertexAttrib( unsigned int vertex_index );
	void bindVertexAttrib( unsigned int vertex_index );

public:
	inline void copy1b( Shader::bool_t x );
	inline void copy2b( Shader::bool_t x, Shader::bool_t y );
	inline void copy3b( Shader::bool_t x, Shader::bool_t y, Shader::bool_t z );
	inline void copy4b( Shader::bool_t x, Shader::bool_t y, Shader::bool_t z, Shader::bool_t w );
	inline void copy2bv( const Shader::bool2_t v );
	inline void copy3bv( const Shader::bool3_t v );
	inline void copy4bv( const Shader::bool4_t v );
	inline void copy1i( Shader::int_t x );
	inline void copy2i( Shader::int_t x, Shader::int_t y );
	inline void copy3i( Shader::int_t x, Shader::int_t y, Shader::int_t z );
	inline void copy4i( Shader::int_t x, Shader::int_t y, Shader::int_t z, Shader::int_t w );
	inline void copy2iv( const Shader::int2_t v );
	inline void copy3iv( const Shader::int3_t v );
	inline void copy4iv( const Shader::int4_t v );
	inline void copy1f( Shader::float_t x );
	inline void copy2f( Shader::float_t x, Shader::float_t y );
	inline void copy3f( Shader::float_t x, Shader::float_t y, Shader::float_t z );
	inline void copy4f( Shader::float_t x, Shader::float_t y, Shader::float_t z, Shader::float_t w );
	inline void copy2fv( const Shader::float2_t v );
	inline void copy3fv( const Shader::float3_t v );
	inline void copy4fv( const Shader::float4_t v );
	inline void copyIndex( unsigned int index );
	
protected:
	friend class Renderer;
	unsigned int m_draw_mode = DrawMode::Invalid;

protected:
	unsigned int m_bind_vertex_index = Shader::Attribute::Invalid;
	VertexArray* m_bind_vertex_array = nullptr;
	VertexArray* m_vertex_arrays[ Shader::Attribute::Count ];
	size_t m_vertex_count = 0;

protected:
	unsigned int* m_indices = nullptr;
	size_t m_indices_cursor = 0;
	size_t m_indices_count = 0;
	size_t m_indices_capacity = 0;
};

NAMESPACE_END

#include "Batch.inl"

#endif //__BATCH_H__