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
	SAFE_RELEASE( m_program );
}

void RenderCommand::setProgram( ShaderProgram* program )
{
	SAFE_ASSIGN( m_program, program );
}

void RenderCommand::setPreDrawProcess( const std::function<void (ShaderProgram*)> process )
{
	m_pre_draw_process = process;
}

void RenderCommand::callPreDrawProcess( void )
{
	//MAGICAL_ASSERT( m_pre_draw_process, "Invalid! nullptr" );
	if( m_pre_draw_process )
	{
		m_pre_draw_process( m_program );
	}
}


BatchCommand::BatchCommand( void )
{
	m_feature = BatchCommand::Feature;
}

BatchCommand::~BatchCommand( void )
{
	SAFE_RELEASE( m_vbo );
}

void BatchCommand::setShape( const Shapes shape )
{
	m_shape = shape;
}

void BatchCommand::setVertexBufferObject( VertexBufferObject* vbo )
{
	SAFE_ASSIGN( m_vbo, vbo );
}

NAMESPACE_END