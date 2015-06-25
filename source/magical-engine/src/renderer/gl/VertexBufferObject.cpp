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
#include "VertexBufferObject.h"

NAMESPACE_MAGICAL

VertexBufferObject::VertexBufferObject( void )
: m_vbo_vertices( 0 )
, m_vbo_indices( 0 )
{
	
}

VertexBufferObject::~VertexBufferObject( void )
{
	if( m_vbo_vertices )
		glDeleteBuffers( 1, &m_vbo_vertices );

	if( m_vbo_indices )
		glDeleteBuffers( 1, &m_vbo_indices );
}

Ptr<VertexBufferObject> VertexBufferObject::create( void )
{
	VertexBufferObject* ret = new VertexBufferObject();
	MAGICAL_ASSERT( ret, "new VertexBufferObject() failed" );
	return Ptr<VertexBufferObject>( Ptrctor<VertexBufferObject>( ret ) );
}

void VertexBufferObject::beginCopyData( size_t vertex_count, size_t indices_count )
{
	MAGICAL_ASSERT( m_copying == false, "Invalid!" );
	MAGICAL_ASSERT( vertex_count > 0, "Invalid count!" );
	m_copying = true;

	if( m_vbo_vertices == 0 )
	{
		glGenBuffers( 1, &m_vbo_vertices );
	}

	if( indices_count == 0 )
	{
		if( m_vbo_indices )
			glDeleteBuffers( 1, &m_vbo_indices );
	}
	else
	{
		
	}
}

void VertexBufferObject::endCopyData( void )
{
	MAGICAL_ASSERT( m_copying == true, "Invalid!" );
	m_copying = false;
	m_empty = false;
}

void VertexBufferObject::enableVertexAttrib( unsigned int index, size_t size, int type, bool normalized )
{
	MAGICAL_ASSERT( m_copying == false, "Invalid!" );
	MAGICAL_ASSERT( size > 0 && Shader::sizeof_id( type ) != 0, "Invalid!" );
	MAGICAL_ASSERT( m_empty, "Invalid!" );

	size_t offset;
	for( auto& itr : m_vertex_attribs )
	{
		offset += Shader::sizeof_id( itr.type ) * itr.size;
	}

	m_vertex_attribs.push_back( VertexAttrib{ index, size, type, normalized, offset } );
}

void VertexBufferObject::clean( void )
{
	MAGICAL_ASSERT( m_copying == false, "Invalid!" );
	m_empty = true;
}

NAMESPACE_END