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
		vbo->commit( data );

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

	if( m_combine_vertex_buf )
	{
		if( m_combine_vertex_buf->vbo )
			glDeleteBuffers( 1, &m_combine_vertex_buf->vbo );

		delete m_combine_vertex_buf;
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

	switch( m_structure )
	{
		case None: default:
			m_vertex_count = count;
			m_structure = structure;
			break;
		case Separate:
			for( auto& itr : m_vertex_bufs )
			{
				if( itr.second->vbo )
					glDeleteBuffers( 1, &itr.second->vbo );

				delete itr.second;
			}
			m_vertex_bufs.clear();
			m_bound_vertex_buf = nullptr;
			break;
		case Combine:
			if( m_combine_vertex_buf )
			{
				if( m_combine_vertex_buf->vbo )
					glDeleteBuffers( 1, &m_combine_vertex_buf->vbo );

				delete m_combine_vertex_buf;
			}

			for( auto& itr : m_vertex_bufs )
				delete itr.second;

			m_vertex_bufs.clear();
			m_combine_vertex_buf = nullptr;
			break;
	}
}

void VertexBufferObject::enable( unsigned int index, size_t size, int type, bool normalized, void* data, VboUsage usage )
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
				glBufferData( GL_ARRAY_BUFFER, total_bytesize, data, (GLenum) usage );

				VertexBuffer* buf = new VertexBuffer();
				buf->vbo = vbo;
				buf->index = index;
				buf->usage = usage;
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
				buf->finish = data ? true : false;

				m_vertex_bufs.push_back_unique( std::make_pair( index, buf ) );
				m_bound_vertex_buf = buf;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf == nullptr, "Invalid!" );
				MAGICAL_ASSERT( data == nullptr, "Invalid!" );

				size_t offset = 0;
				for( auto& itr : m_vertex_bufs )
				{
					offset += itr.second->bytesize;
				}

				size_t sizeof_type = Shader::sizeof_id( type );
				size_t bytesize = sizeof_type * size;
				size_t total_bytesize = bytesize * m_vertex_count;

				VertexBuffer* buf = new VertexBuffer();
				buf->vbo = 0;
				buf->index = index;
				buf->usage = usage;
				buf->size = size;
				buf->total_size = m_vertex_count * size;
				buf->bytesize = bytesize;
				buf->total_bytesize = total_bytesize;
				buf->type = type;
				buf->sizeof_type = sizeof_type;
				buf->normalized = normalized;
				buf->offset = offset;
				buf->data = nullptr;
				buf->cursor = 0;
				buf->bytecursor = 0;
				buf->edit = false;
				buf->finish = false;

				m_vertex_bufs.push_back_unique( std::make_pair( index, buf ) );
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
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit == false, "Invalid!" );

				glBindBuffer( GL_ARRAY_BUFFER, m_bound_vertex_buf->vbo );
				m_bound_vertex_buf->data = glMapBuffer( GL_ARRAY_BUFFER, GL_WRITE_ONLY );
				m_bound_vertex_buf->cursor = 0;
				m_bound_vertex_buf->edit = true;
				m_bound_vertex_buf->finish = false;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit == false, "Invalid!" );

				glBindBuffer( GL_ARRAY_BUFFER, m_combine_vertex_buf->vbo );
				m_combine_vertex_buf->data = glMapBuffer( GL_ARRAY_BUFFER, GL_WRITE_ONLY );
				m_combine_vertex_buf->bytecursor = 0;
				m_combine_vertex_buf->edit = true;
				m_combine_vertex_buf->finish = false;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

void VertexBufferObject::commit( void )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor == m_bound_vertex_buf->total_size, "Invalid! not finish" );

				glBindBuffer( GL_ARRAY_BUFFER, m_bound_vertex_buf->vbo );
				glUnmapBuffer( GL_ARRAY_BUFFER );
				m_bound_vertex_buf->data = nullptr;
				m_bound_vertex_buf->cursor = 0;
				m_bound_vertex_buf->edit = false;
				m_bound_vertex_buf->finish = true;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor == m_combine_vertex_buf->total_bytesize, "Invalid! not finish" );

				glBindBuffer( GL_ARRAY_BUFFER, m_combine_vertex_buf->vbo );
				glUnmapBuffer( GL_ARRAY_BUFFER );
				m_combine_vertex_buf->data = nullptr;
				m_combine_vertex_buf->bytecursor = 0;
				m_combine_vertex_buf->edit = false;
				m_combine_vertex_buf->finish = true;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

void VertexBufferObject::commit( void* data )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit == false, "Invalid!" );

				glBindBuffer( GL_ARRAY_BUFFER, m_bound_vertex_buf->vbo );
				glBufferSubData( GL_ARRAY_BUFFER, 0, m_bound_vertex_buf->total_bytesize, data );
				m_bound_vertex_buf->finish = data ? true : false;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit == false, "Invalid!" );

				glBindBuffer( GL_ARRAY_BUFFER, m_combine_vertex_buf->vbo );
				glBufferSubData( GL_ARRAY_BUFFER, 0, m_combine_vertex_buf->total_bytesize, data );
				m_combine_vertex_buf->finish = data ? true : false;
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
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit == false, "Invalid!" );

				glDeleteBuffers( 1, &m_combine_vertex_buf->vbo );
				delete m_combine_vertex_buf;
				m_combine_vertex_buf = nullptr;

				for( auto& itr : m_vertex_bufs )
					delete itr.second;

				m_vertex_bufs.clear();
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
	MAGICAL_ASSERT( m_structure == Combine, "Invalid!" );
	MAGICAL_ASSERT( m_vertex_bufs.size() > 1, "Invalid! size should > 1" );
	MAGICAL_ASSERT( m_combine_vertex_buf == nullptr, "Invalid!" );

	GLuint vbo = 0;
	glGenBuffers( 1, &vbo );

	m_combine_vertex_buf = new VertexBuffer();
	m_combine_vertex_buf->vbo = vbo;
	m_combine_vertex_buf->data = nullptr;
	m_combine_vertex_buf->bytecursor = 0;
	m_combine_vertex_buf->edit = false;
	m_combine_vertex_buf->finish = false;

	m_combine_vertex_buf->usage = m_vertex_bufs[0].second->usage;
	m_combine_vertex_buf->size = 0;
	m_combine_vertex_buf->total_size = 0;
	m_combine_vertex_buf->bytesize = 0;
	m_combine_vertex_buf->total_bytesize = 0;

	for( auto& itr : m_vertex_bufs )
	{
		MAGICAL_ASSERT( m_combine_vertex_buf->usage == itr.second->usage, "Invalid! usage are not equal" );

		m_combine_vertex_buf->size += itr.second->size;
		m_combine_vertex_buf->total_size += itr.second->total_size;
		m_combine_vertex_buf->bytesize += itr.second->bytesize;
		m_combine_vertex_buf->total_bytesize += itr.second->total_bytesize;
	}

	glBindBuffer( GL_ARRAY_BUFFER, vbo );
	glBufferData( GL_ARRAY_BUFFER, m_combine_vertex_buf->total_bytesize, nullptr, (GLenum) m_combine_vertex_buf->usage );
}

void VertexBufferObject::combine( void* data )
{
	MAGICAL_ASSERT( m_structure == Combine, "Invalid!" );
	MAGICAL_ASSERT( m_vertex_bufs.size() > 1, "Invalid! size should > 1" );
	MAGICAL_ASSERT( m_combine_vertex_buf == nullptr, "Invalid!" );

	GLuint vbo = 0;
	glGenBuffers( 1, &vbo );

	m_combine_vertex_buf = new VertexBuffer();
	m_combine_vertex_buf->vbo = vbo;
	m_combine_vertex_buf->data = nullptr;
	m_combine_vertex_buf->bytecursor = 0;
	m_combine_vertex_buf->edit = false;
	m_combine_vertex_buf->finish = data ? true : false;
	
	m_combine_vertex_buf->usage = m_vertex_bufs[0].second->usage;
	m_combine_vertex_buf->size = 0;
	m_combine_vertex_buf->total_size = 0;
	m_combine_vertex_buf->bytesize = 0;
	m_combine_vertex_buf->total_bytesize = 0;

	for( auto& itr : m_vertex_bufs )
	{
		MAGICAL_ASSERT( m_combine_vertex_buf->usage == itr.second->usage, "Invalid! usage are not equal" );

		m_combine_vertex_buf->size += itr.second->size;
		m_combine_vertex_buf->total_size += itr.second->total_size;
		m_combine_vertex_buf->bytesize += itr.second->bytesize;
		m_combine_vertex_buf->total_bytesize += itr.second->total_bytesize;
	}

	glBindBuffer( GL_ARRAY_BUFFER, vbo );
	glBufferData( GL_ARRAY_BUFFER, m_combine_vertex_buf->total_bytesize, data, (GLenum) m_combine_vertex_buf->usage );
}

void VertexBufferObject::use( void )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( !m_vertex_bufs.empty(), "Invalid! not enable any buffer yet!" );
				for( auto& itr : m_vertex_bufs )
				{
					MAGICAL_ASSERT( itr.second->finish, "Invalid! not finish" );
					glBindBuffer( GL_ARRAY_BUFFER, itr.second->vbo );
					glEnableVertexAttribArray( itr.second->index );
					glVertexAttribPointer( (GLuint)itr.second->index, (GLint)itr.second->size, (GLenum)itr.second->type, (GLboolean)itr.second->normalized, 0, 0 );
				}
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( !m_vertex_bufs.empty(), "Invalid! not enable any buffer yet!" );
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->finish, "Invalid! not finish" );

				glBindBuffer( GL_ARRAY_BUFFER, m_combine_vertex_buf->vbo );
				for( auto& itr : m_vertex_bufs )
				{
					glEnableVertexAttribArray( itr.second->index );
					glVertexAttribPointer( (GLuint)itr.second->index, (GLint)itr.second->size, (GLenum)itr.second->type, (GLboolean)itr.second->normalized, (GLsizei)m_combine_vertex_buf->bytesize, (GLvoid*)itr.second->offset );
				}
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

void VertexBufferObject::unuse( void )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( !m_vertex_bufs.empty(), "Invalid! not enable any buffer yet!" );
				for( auto& itr : m_vertex_bufs )
				{
					glDisableVertexAttribArray( itr.second->index );
				}
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( !m_vertex_bufs.empty(), "Invalid! not enable any buffer yet!" );
				for( auto& itr : m_vertex_bufs )
				{
					glDisableVertexAttribArray( itr.second->index );
				}
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

NAMESPACE_END