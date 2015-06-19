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
#include "Batch.h"

NAMESPACE_MAGICAL

Batch::Batch( void )
{
	memset( m_vertex_arrays, 0, sizeof( VertexArray* ) * Shader::Attribute::Count );
	//Batch batch;
	//batch.draw( DrawMode::Triangles, 8, 36 );

	//batch.enableVertexAttrib( Shader::Attribute::iVertex3f, Shader::Sizeof_float3_t );
	//batch.copy3f( 1, 1, 1 );
	//batch.copy3f( 4, 5, 6 );
	//batch.copy3f( 2, 2, 2 );

	//batch.enableVertexAttrib( Shader::Attribute::iColor4f, Shader::Sizeof_float4_t );
	//batch.copy4f( 1, 1, 1, 1 );
	//batch.copy4f( 1, 1, 1, 1 );
	//batch.copy4f( 1, 1, 1, 1 );

	//batch.enableVertexAttrib( Shader::Attribute::iTexCoord, Shader::Sizeof_float2_t );
	////batch.bindVertexAttrib( Shader::Attribute::iTexCoord );
	//batch.copy2f( 1, 1 );
	//batch.copy2f( 1, 1 );
	//batch.copy2f( 1, 1 );

	//batch.copyIndex( 0 );
	//batch.copyIndex( 1 );
	//batch.copyIndex( 2 );

	//RenderCommand comand;
	//command.setBatch( batch );
	//Renderer::addCommand( command );
}

Batch::~Batch( void )
{
	for( auto& arr : m_vertex_arrays )
		if( arr ){ ::free( arr->data ); delete arr; }

	if( m_indices )
		::free( m_indices );
}

Ptr<Batch> Batch::create( void )
{
	Batch* ret = new Batch();
	MAGICAL_ASSERT( ret, "new Batch() failed" );
	return Ptr<Batch>( Ptrctor<Batch>( ret ) );
}

void Batch::draw( unsigned int draw_mode, size_t vertex_count, size_t indices_count = 0 )
{
	MAGICAL_ASSERT( draw_mode != DrawMode::Invalid, "Invalid mode!" );
	MAGICAL_ASSERT( vertex_count > 0, "Invalid count!" );

	m_draw_mode = draw_mode;
	if( vertex_count != m_vertex_count )
	{
		for( auto& arr : m_vertex_arrays )
		{
			if( arr != nullptr )
			{
				size_t new_size = vertex_count * arr->sizeof_vertex;
				if( arr->cursor > new_size )
					arr->cursor = new_size;

				arr->capacity = new_size;
				arr->data = (char*) ::realloc( arr->data, new_size );
				MAGICAL_ASSERT( arr->data, "Invalid realloc!" );
			}
		}
		m_vertex_count = vertex_count;
	}

	if( indices_count != m_indices_count )
	{
		if( indices_count == 0 && m_indices )
		{
			::free( m_indices );
			m_indices = nullptr;
			m_indices_cursor = 0;
		}
		else
		{
			size_t new_size = indices_count * sizeof( unsigned int );
			if( m_indices_cursor > new_size )
				m_indices_cursor = new_size;

			if( m_indices )
			{
				m_indices = (unsigned int*) ::realloc( m_indices, new_size );
				MAGICAL_ASSERT( m_indices, "Invalid realloc!" );
			}
			else
			{
				m_indices = (unsigned int*) ::malloc( new_size );
				MAGICAL_ASSERT( m_indices, "Invalid malloc!" );
			}
		}
		m_indices_count = indices_count;
	}

	bindVertexAttrib( Shader::Attribute::Invalid );
}

void Batch::enableVertexAttrib( unsigned int vertex_index, size_t sizeof_vertex )
{
	MAGICAL_ASSERT( m_vertex_count > 0, "Invalid! m_vertex_count should > 0." );
	MAGICAL_ASSERT( 0 <= vertex_index && vertex_index < Shader::Attribute::Count, "Invalid index!" );
	MAGICAL_ASSERT( sizeof_vertex > 0, "Invalid sizeof!" );

	VertexArray* arr = m_vertex_arrays[ vertex_index ];
	if( arr != nullptr )
	{
		::free( arr->data );
		arr->capacity = sizeof_vertex * m_vertex_count;
		arr->data = (char*) ::malloc( arr->capacity );
		MAGICAL_ASSERT( arr->data, "Invalid malloc!" );
		arr->sizeof_vertex = sizeof_vertex;
		arr->cursor = 0;
		arr->vertex_index = vertex_index;

		m_bind_vertex_index = vertex_index;
		m_bind_vertex_array = arr;
	}
	else
	{
		arr = new VertexArray();
		arr->capacity = sizeof_vertex * m_vertex_count;
		arr->data = (char*) ::malloc( arr->capacity );
		MAGICAL_ASSERT( arr->data, "Invalid malloc!" );
		arr->sizeof_vertex = sizeof_vertex;
		arr->cursor = 0;
		arr->vertex_index = vertex_index;
		m_vertex_arrays[ vertex_index ] = arr;

		m_bind_vertex_index = vertex_index;
		m_bind_vertex_array = arr;
	}
}

void Batch::disableVertexAttrib( unsigned int vertex_index )
{
	MAGICAL_ASSERT( 0 <= vertex_index && vertex_index < Shader::Attribute::Count, "Invalid index!" );

	VertexArray* arr = m_vertex_arrays[ vertex_index ];
	if( arr != nullptr )
	{
		::free( arr->data );
		delete arr;
		m_vertex_arrays[ vertex_index ] = nullptr;
	}

	if( vertex_index == m_bind_vertex_index )
	{
		m_bind_vertex_index = Shader::Attribute::Invalid;
		m_bind_vertex_array = nullptr;
	}
}

void Batch::bindVertexAttrib( unsigned int vertex_index )
{
	if( vertex_index == m_bind_vertex_index )
		return;

	m_bind_vertex_index = vertex_index;
	if( vertex_index == Shader::Attribute::Invalid )
	{
		m_bind_vertex_array = nullptr;
		return;
	}

	VertexArray* arr = m_vertex_arrays[ vertex_index ];
	MAGICAL_ASSERT( arr, "Invalid bind index!" );

	m_bind_vertex_array = arr;
}

NAMESPACE_END