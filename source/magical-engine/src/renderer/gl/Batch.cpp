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

}

Batch::~Batch( void )
{
	if( m_vertexes )
		::free( m_vertexes );

	if( m_indices )
		::free( m_indices );
}

void Batch::beginCopyData( unsigned short attr, size_t size )
{
	m_attr = attr;
	m_size = size;

	if( m_vertexes )
		::free( m_vertexes );

	if( m_indices )
		::free( m_indices );

	m_data = (char*) ::malloc( size );
	MAGICAL_ASSERT( m_data, "Invalid! ::malloc( size )" );
}

void Batch::copyVector2( const Vector2& v )
{

}

void Batch::copyVector3( const Vector3& v )
{

}

void Batch::copyVector4( const Vector4& v )
{

}

NAMESPACE_END