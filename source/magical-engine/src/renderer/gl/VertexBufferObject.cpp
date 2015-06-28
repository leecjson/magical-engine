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
: m_combine_vbo( 0 )
{
	/*
		// init
		VertexBufferObject* vbo = Renderer::createVertexBufferObject();

		vbo->alloc( 4, VertexBufferObject::Combine );
		vbo->enable( Shader::Attribute::iVertex, 3, Shader::TFloat, false );
		vbo->enable( Shader::Attribute::iColor, 4, Shader::TUbyte, true );
		vbo->enable( Shader::Attribute::iTexCoord, 2, Shader::TFloat, false );
		vbo->combine();

		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );

		// update
		vbo->clear();
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );
		vbo->vertex3f( 1, 1, 1 ); vbo->vertex4ub( 255, 255, 255, 255 ); vbo->vertex2f( 0, 1 );

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
		vbo->vertex3f( 1, 1, 1 );
		vbo->vertex3f( 1, 1, 1 );
		vbo->vertex3f( 1, 1, 1 );
		vbo->vertex3f( 1, 1, 1 );

		vbo->bind( Shader::Attribute::iColor );
		vbo->vertex4ub( 255, 255, 255, 255 );
		vbo->vertex4ub( 255, 255, 255, 255 );
		vbo->vertex4ub( 255, 255, 255, 255 );
		vbo->vertex4ub( 255, 255, 255, 255 );

		vbo->bind( Shader::Attribute::iTexCoord );
		vbo->vertex2f( 0, 1 );
		vbo->vertex2f( 0, 1 );
		vbo->vertex2f( 0, 1 );
		vbo->vertex2f( 0, 1 );

		// update
		vbo->disable( Shader::Attribute::iVertex );
		vbo->enable( Shader::Attribute::iVertex, 3, Shader::TFloat, false );
		or 
		vbo->clear( Shader::Attribute::iVertex );
		vbo->clear();

		// delete
		vbo->free();
	*/
}

VertexBufferObject::~VertexBufferObject( void )
{
	//if( m_vbo_vertices )
	//	glDeleteBuffers( 1, &m_vbo_vertices );
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
	MAGICAL_ASSERT( structure != None, "Invalid structure!" );

	m_count = count;
	m_structure = structure;
	m_alloc = true;
}

void VertexBufferObject::free( void )
{
	
}

void VertexBufferObject::enable( unsigned int index, size_t size, int type, bool normalized )
{
	MAGICAL_ASSERT( m_alloc, "Invalid! call enable after alloc" );

	switch( m_structure )
	{
		case Separate:
			{
				GLuint vbo = 0;
				glGenBuffers( 1, &vbo );
				glBindBuffer( GL_ARRAY_BUFFER, vbo );

				size_t bytesize = Shader::sizeof_id( type ) * size;
				glBufferData( GL_ARRAY_BUFFER, Shader::sizeof_id( type ) * size, nullptr, GL_DYNAMIC_DRAW );

				Pair<unsigned int, VertexAttrib*> kv;
				kv.first = index;
				kv.second = new VertexAttrib{ vbo, index, size, bytesize, type, normalized, 0 };

				m_vertex_attribs.push_back_unique( std::move( kv ) );
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
	MAGICAL_ASSERT( m_alloc, "Invalid! call bind after alloc and enable" );
	MAGICAL_ASSERT( m_structure == Separate, "Invalid!" );

	auto itr = m_vertex_attribs.find( index );
	MAGICAL_ASSERT( itr != m_vertex_attribs.end(), "Invalid bind!" );
	m_bind_vertex_attrib = itr->second;
}

void VertexBufferObject::disable( void )
{

}

void VertexBufferObject::disable( unsigned int index )
{
	MAGICAL_ASSERT( m_alloc, "Invalid! call disable after alloc" );
	MAGICAL_ASSERT( m_structure == Separate, "Invalid!" );

	auto itr = m_vertex_attribs.find( index );
	MAGICAL_ASSERT( itr != m_vertex_attribs.end(), "Invalid disable!" );

	if( m_bind_vertex_attrib == itr->second )
		m_bind_vertex_attrib = nullptr;

	m_vertex_attribs.erase( itr );
	glDeleteBuffers( 1, &itr->second->vbo );
	delete itr->second;
}

void VertexBufferObject::clear( void )
{

}

void VertexBufferObject::clear( unsigned int index )
{

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