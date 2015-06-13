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
#include "RenderCommand.h"

NAMESPACE_MAGICAL

RenderCommand::RenderCommand( void )
{

}

RenderCommand::~RenderCommand( void )
{

}

TriangleCommand::TriangleCommand( void )
{

}

TriangleCommand::~TriangleCommand( void )
{
	if( m_vertexes )
		::free( m_vertexes );

	if( m_indices )
		::free( m_indices );
}

void TriangleCommand::beginCopyData( size_t vertexes_size, size_t indices_size )
{
	MAGICAL_ASSERT( vertexes_size != 0 && indices_size != 0, "Invalid size!" );

	if( m_vertexes )
		::free( m_vertexes );

	if( m_indices )
		::free( m_indices );

	m_vertexes = (V3f_C4b_T2f*) ::malloc( vertexes_size * sizeof( V3f_C4b_T2f ) );
	m_vertexes_index = 0;
	m_vertexes_size = vertexes_size;
	
	m_indices = (uint32_t*) ::malloc( indices_size * sizeof( uint32_t ) );
	m_indices_index = 0;
	m_indices_size = indices_size;

	TriangleCommand triangle;
	triangle.beginCopyData( 4, 6 );
	triangle.copyData( Vector3::One, Color4b::Black, Vector2::One );
	triangle.copyData( Vector3::One, Color4b::Black, Vector2::One );
	triangle.copyData( Vector3::One, Color4b::Black, Vector2::One );
	triangle.copyData( Vector3::One, Color4b::Black, Vector2::One );

	triangle.copyIndex( 0 );
	triangle.copyIndex( 1 );
	triangle.copyIndex( 2 );
	triangle.copyIndex( 1 );
	triangle.copyIndex( 2 );
	triangle.copyIndex( 3 );
	triangle.endCopyData();
}

void TriangleCommand::copyData( const Vector3& vertex, const Color4b& color, const Vector2& texcoord )
{
	MAGICAL_ASSERT( m_vertexes && m_indices && m_vertexes_size > 0 && m_indices_size > 0, "Invalid!" );
	MAGICAL_ASSERT( m_vertexes_index < m_vertexes_size, "Invalid!" );

	m_vertexes[ m_vertexes_index ] = V3f_C4b_T2f{ vertex, color, texcoord };
	m_vertexes_index ++;
}

void TriangleCommand::copyIndex( uint32_t index )
{
	MAGICAL_ASSERT( m_vertexes && m_indices && m_vertexes_size > 0 && m_indices_size > 0, "Invalid!" );
	MAGICAL_ASSERT( m_indices_index < m_indices_size, "Invalid!" );

	m_indices[ m_indices_index ] = index;
	m_indices_index ++;
}

void TriangleCommand::endCopyData( void )
{
	MAGICAL_ASSERT( m_vertexes_index + 1 == m_vertexes_size && m_indices_index + 1 == m_indices_size, "Invalid!" );
}

NAMESPACE_END