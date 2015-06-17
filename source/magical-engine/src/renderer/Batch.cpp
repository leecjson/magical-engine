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
	/*Batch batch;
	batch.beginCopyData( 
		Shader::Attribute::iVertex | Shader::Attribute::iColor | Shader::Attribute::iTextureCoord, 
		Shader::Inner::Sizeof_float3_t + Shader::Inner::Sizeof_float4_t + Shader::Inner::Sizeof_float2_t,
		8, 36 );
	batch.endCopyData();*/

	Ptr<Batch> batch = Batch::create();

	RenderCommand command;
	command.setShape( Shape::Triangles );
	command.setBatch( batch );
	command.
}

Batch::~Batch( void )
{
	if( m_vertexes )
		::free( m_vertexes );

	if( m_indices )
		::free( m_indices );
}

void Batch::beginCopyData( unsigned short location, size_t sizeof_vertex, size_t vertex_count, size_t indices_count )
{
	MAGICAL_ASSERT( location != 0, "Invalid location!" );
	MAGICAL_ASSERT( sizeof_vertex != 0 && vertex_count != 0, "Invalid size!" );

	m_location = location;
	m_vertexes_count = vertex_count;
	m_vertexes_cursor = 0;
	
	if( m_vertexes )
		::free( m_vertexes );

	m_vertexes = (char*) ::malloc( sizeof_vertex * vertex_count );
	MAGICAL_ASSERT( m_vertexes, "Invalid! ::malloc( sizeof_vertex * count )" );

	m_indices_count = indices_count;
	m_indices_cursor = 0;

	if( m_indices )
	{
		::free( m_indices );
		m_indices = nullptr;
	}

	if( indices_count )
	{
		m_indices = (unsigned int*) ::malloc( sizeof( unsigned int ) * indices_count );
		MAGICAL_ASSERT( m_indices, "Invalid! ::malloc( sizeof( unsigned int ) * indices_count )" );
	}
}

void Batch::endCopyData( void )
{
	MAGICAL_ASSERT( m_vertexes_cursor == m_vertexes_count - 1, "Invalid! didn't finished copy" );
	MAGICAL_ASSERT( m_indices ? m_indices_cursor == m_indices_count - 1 : true, "Invalid! didn't finished copy" );
}

NAMESPACE_END