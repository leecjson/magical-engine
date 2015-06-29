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
{
	/*
		// init
		VertexBufferObject* vbo = Renderer::createVertexBufferObject();

		vbo->alloc( 4, VertexBufferObject::Combine );
		vbo->enable( Shader::Attribute::iVertex, 3, Shader::TFloat, false );
		vbo->enable( Shader::Attribute::iColor, 4, Shader::TUbyte, true );
		vbo->enable( Shader::Attribute::iTexCoord, 2, Shader::TFloat, false );
		vbo->combine();

		vbo->edit();
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->commit();

		// update
		vbo->clear();

		vbo->edit();
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->commit();

		// delete
		vbo->free();
	*/

	/*
		VertexBufferObject* vbo = Renderer::createVertexBufferObject();

		vbo->alloc( 4, VertexBufferObject::Separate );
		vbo->enable( Shader::Attribute::iVertex, 3, Shader::TFloat, false );
		vbo->enable( Shader::Attribute::iColor, 4, Shader::TUbyte, true );
		vbo->enable( Shader::Attribute::iTexCoord, 2, Shader::TFloat, false );

		vbo->bind( Shader::Attribute::iVertex );
		vbo->edit();
		vbo->vertex3f( 1, 1, 1 );
		vbo->vertex3f( 1, 1, 1 );
		vbo->vertex3f( 1, 1, 1 );
		vbo->vertex3f( 1, 1, 1 );
		vbo->commit();

		vbo->bind( Shader::Attribute::iColor );
		vbo->edit();
		vbo->vertex4ub( 255, 255, 255, 255 );
		vbo->vertex4ub( 255, 255, 255, 255 );
		vbo->vertex4ub( 255, 255, 255, 255 );
		vbo->vertex4ub( 255, 255, 255, 255 );
		vbo->commit();

		vbo->bind( Shader::Attribute::iTexCoord );
		vbo->commit( data );

		// update
		vbo->bind( Shader::Attribute::iVertex );
		vbo->disable();
		vbo->enable( Shader::Attribute::iVertex, 3, Shader::TFloat, false );
		vbo->commit( data );
		or 
		vbo->bind( Shader::Attribute::iVertex );
		vbo->commit( nullptr );

		// delete
		vbo->free();
	*/
}

VertexBufferObject::~VertexBufferObject( void )
{
	for( auto& itr : m_vertex_bufs )
	{
		if( itr.second->vbo )
			glDeleteBuffers( 1, &itr.second->vbo );
		delete itr.second;
	}
}

Ptr<VertexBufferObject> VertexBufferObject::create( void )
{
	VertexBufferObject* ret = new VertexBufferObject();
	MAGICAL_ASSERT( ret, "new VertexBufferObject() failed" );
	return Ptr<VertexBufferObject>( Ptrctor<VertexBufferObject>( ret ) );
}

void VertexBufferObject::alloc( size_t count, int structure )
{
	MAGICAL_ASSERT( count > 0, "Invalid count!" );
	MAGICAL_ASSERT( structure != VertexBufferObject::None, "Invalid structure!" );

	m_vertex_count = count;
	m_structure = structure;
}

void VertexBufferObject::enable( unsigned int index, size_t size, int type, bool normalized, void* data )
{
	MAGICAL_ASSERT( m_vertex_count > 0, "Invalid count!" );
	MAGICAL_ASSERT( size > 0, "Invalid size!" );

	switch( m_structure )
	{
		case Separate:
			{
				GLuint vbo = 0;
				glGenBuffers( 1, &vbo );
				glBindBuffer( GL_ARRAY_BUFFER, vbo );

				size_t sizeof_type = Shader::sizeof_id( type );
				size_t bytesize = sizeof_type * size;
				size_t total_bytesize = bytesize * m_vertex_count;
				glBufferData( GL_ARRAY_BUFFER, total_bytesize, data, GL_DYNAMIC_DRAW );

				VertexBuffer* buf = new VertexBuffer();
				buf->vbo = vbo;
				buf->index = index;
				buf->vertex_count = m_vertex_count;
				buf->size = size;
				buf->total_size = m_vertex_count * size;
				buf->bytesize = bytesize;
				buf->total_bytesize = total_bytesize;
				buf->type = type;
				buf->sizeof_type = sizeof_type;
				buf->normalized = normalized;
				buf->offset = 0;
				buf->data = nullptr;
				buf->cursor = 0;
				buf->bytecursor = 0;
				buf->edit = false;

				m_vertex_bufs.push_back_unique( std::make_pair( index, buf ) );
				m_bound_vertex_buf = buf;
			}
			break;
		case Combine:
			{

			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

void VertexBufferObject::bind( unsigned int index )
{
	MAGICAL_ASSERT( m_structure == Separate, "Invalid!" );

	auto itr = m_vertex_bufs.find( index );
	MAGICAL_ASSERT( itr != m_vertex_bufs.end(), "Invalid bind!" );
	m_bound_vertex_buf = itr->second;
}

void VertexBufferObject::edit( void )
{
	MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
	MAGICAL_ASSERT( m_bound_vertex_buf->edit == false, "Invalid!" );

	switch( m_structure )
	{
		case Separate:
			{
				glBindBuffer( GL_ARRAY_BUFFER, m_bound_vertex_buf->vbo );
				m_bound_vertex_buf->data = glMapBuffer( GL_ARRAY_BUFFER, GL_WRITE_ONLY );
				m_bound_vertex_buf->cursor = 0;
				m_bound_vertex_buf->edit = true;
			}
			break;
		case Combine:
			{

			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

void VertexBufferObject::commit( void )
{
	MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
	MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid!" );

	switch( m_structure )
	{
		case Separate:
			{
				glBindBuffer( GL_ARRAY_BUFFER, m_bound_vertex_buf->vbo );
				glUnmapBuffer( GL_ARRAY_BUFFER );
				m_bound_vertex_buf->data = nullptr;
				m_bound_vertex_buf->cursor = 0;
				m_bound_vertex_buf->edit = false;
			}
			break;
		case Combine:
			{

			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

void VertexBufferObject::commit( void* data )
{
	MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
	MAGICAL_ASSERT( m_bound_vertex_buf->edit == false, "Invalid!" );

	switch( m_structure )
	{
		case Separate:
			{
				glBindBuffer( GL_ARRAY_BUFFER, m_bound_vertex_buf->vbo );
				glBufferSubData( GL_ARRAY_BUFFER, 0, m_bound_vertex_buf->total_bytesize, data );
			}
			break;
		case Combine:
			{

			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

void VertexBufferObject::disable( void )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit == false, "Invalid!" );

				auto itr = m_vertex_bufs.find( m_bound_vertex_buf->index );
				m_vertex_bufs.erase( itr );

				glDeleteBuffers( 1, &m_bound_vertex_buf->vbo );
				delete m_bound_vertex_buf;
				m_bound_vertex_buf = nullptr;
			}
			break;
		case Combine:
			{

			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

void VertexBufferObject::clear( void )
{
	commit( nullptr );
}

void VertexBufferObject::combine( void )
{

}

//void VertexBufferObject::beginCopyData( size_t vertex_count, size_t indices_count )
//{
//	MAGICAL_ASSERT( m_copying == false, "Invalid!" );
//	MAGICAL_ASSERT( vertex_count > 0, "Invalid count!" );
//	m_copying = true;
//
//	if( m_vbo_vertices == 0 )
//	{
//		glGenBuffers( 1, &m_vbo_vertices );
//	}
//
//	if( indices_count == 0 )
//	{
//		if( m_vbo_indices )
//			glDeleteBuffers( 1, &m_vbo_indices );
//	}
//	else
//	{
//		
//	}
//}
//
//void VertexBufferObject::endCopyData( void )
//{
//	MAGICAL_ASSERT( m_copying == true, "Invalid!" );
//	m_copying = false;
//	m_empty = false;
//}
//
//void VertexBufferObject::enableVertexAttrib( unsigned int index, size_t size, int type, bool normalized )
//{
//	MAGICAL_ASSERT( m_copying == false, "Invalid!" );
//	MAGICAL_ASSERT( size > 0 && Shader::sizeof_id( type ) != 0, "Invalid!" );
//	MAGICAL_ASSERT( m_empty, "Invalid!" );
//
//	size_t offset;
//	for( auto& itr : m_vertex_attribs )
//	{
//		offset += Shader::sizeof_id( itr.type ) * itr.size;
//	}
//
//	m_vertex_attribs.push_back( VertexAttrib{ index, size, type, normalized, offset } );
//}

NAMESPACE_END