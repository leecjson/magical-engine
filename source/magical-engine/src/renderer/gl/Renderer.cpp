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
#include "Renderer.h"
#include "magical-math.h"
#include "Engine.h"
#include "Application.h"
#include "ShaderProgram.h"
#include "Color.h"
#include <vector>

NAMESPACE_MAGICAL


static char* s_vbo[ Renderer::VboSize ];

void Renderer::init( void )
{
	setDefault();
	MAGICAL_RETURN_IF_ERROR();

	Shader::init();
	MAGICAL_RETURN_IF_ERROR();
}

void Renderer::delc( void )
{
	Shader::delc();
	MAGICAL_RETURN_IF_ERROR();
}

void Renderer::setDefault( void )
{
	glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );

	glEnable( GL_DEPTH_TEST );
	glEnable( GL_CULL_FACE );

	MAGICAL_CHECK_GL_ERROR();
}

void Renderer::render( const ViewChannel* channel )
{
	const Area& area = channel->getArea();
	const Size& win_size = Application::getWindowSize();

	glViewport( area.x * win_size.w, area.y * win_size.h, area.w * win_size.w, area.h * win_size.h );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	MAGICAL_DEBUG_CHECK_GL_ERROR();
}

void Renderer::addCommand( const RenderCommand* command )
{
	m_queue.push_back( std::make_pair( local_to_world, view_projection ) );
}

NAMESPACE_END







/*
Vector3 rect[4];
Vector3 rect_triangle[4];
Vector3 cube[24];

// 2D Rect Vertex
	rect[0].set( -0.5f, -0.5f, 0 );
	rect[1].set( 0.5f, -0.5f, 0 );
	rect[2].set( 0.5f, 0.5f, 0 );
	rect[3].set( -0.5f, 0.5f, 0 );

	// 2D Rect Vertex Triangle strip
	rect_triangle[0].set( -0.5f, -0.5f, 2.0f );
	rect_triangle[1].set( 0.5f, -0.5f, 2.0f );
	rect_triangle[2].set( -0.5f, 0.5f, 2.0f );
	rect_triangle[3].set( 0.5f, 0.5f, 2.0f );

	// font
	cube[0].set( -0.5f, -0.5f, -0.5f );
	cube[1].set( 0.5f, -0.5f, -0.5f );
	cube[2].set( 0.5f, 0.5f, -0.5f );
	cube[3].set( -0.5f, 0.5f, -0.5f );

	// top
	cube[4].set( -0.5f, 0.5f, -0.5f );
	cube[5].set( 0.5f, 0.5f, -0.5f );
	cube[6].set( 0.5f, 0.5f, 0.5f );
	cube[7].set( -0.5f, 0.5f, 0.5f );

	// back
	cube[8].set( -0.5f, -0.5f, 0.5f );
	cube[9].set( -0.5f, 0.5f, 0.5f );
	cube[10].set( 0.5f, 0.5f, 0.5f );
	cube[11].set( 0.5f, -0.5f, 0.5f );

	// bottom
	cube[12].set( -0.5f, -0.5f, -0.5f );
	cube[13].set( -0.5f, -0.5f, 0.5f );
	cube[14].set( 0.5f, -0.5f, 0.5f );
	cube[15].set( 0.5f, -0.5f, -0.5f );

	// left
	cube[16].set( -0.5f, -0.5f, 0.5f );
	cube[17].set( -0.5f, -0.5f, -0.5f );
	cube[18].set( -0.5f, 0.5f, -0.5f );
	cube[19].set( -0.5f, 0.5f, 0.5f );

	// right
	cube[20].set( 0.5f, -0.5f, 0.5f );
	cube[21].set( 0.5f, 0.5f, 0.5f );
	cube[22].set( 0.5f, 0.5f, -0.5f );
	cube[23].set( 0.5f, -0.5f, -0.5f );

	ShaderProgram* program = Shader::getProgram( Shader::Flat );

	for( const auto& itr : m_queue )
	{
		glUseProgram( program->getId() );

		Matrix4x4 mvp_matrix = itr.first * itr.second;

		GLint u_mvp_matrix = program->getUniformLocation( "u_mvp_matrix" );
		glUniformMatrix4fv( u_mvp_matrix, 1, GL_FALSE, (GLfloat*)&mvp_matrix );

		/*Color4f colors[4] = {
			Color4f::Pink,
			Color4f::Yello,
			Color4f::Green,
			Color4f::Red };

		glEnableVertexAttribArray( kAttrVertexIndex );
		glEnableVertexAttribArray( kAttrColorIndex );
		glVertexAttribPointer( kAttrVertexIndex, 3, GL_FLOAT, GL_FALSE, 0, &rect_triangle );
		glVertexAttribPointer( kAttrColorIndex, 4, GL_FLOAT, GL_FALSE, 0, colors );
		glDrawArrays( GL_TRIANGLE_STRIP, 0, 4 );

		Color4f colors[24] = { 
			Color4f::Red, Color4f::Red, Color4f::Red, Color4f::Red, //font
			Color4f::Black, Color4f::Black, Color4f::Black, Color4f::Black, //top
			Color4f::Pink, Color4f::Pink, Color4f::Pink, Color4f::Pink,  //back
			Color4f::Blue, Color4f::Blue, Color4f::Blue, Color4f::Blue, //bottom
			Color4f::Brown, Color4f::Brown, Color4f::Brown, Color4f::Brown, //left
			Color4f::Cyan, Color4f::Cyan, Color4f::Cyan, Color4f::Cyan //right
		};

		glEnableVertexAttribArray( Shader::AttribLocation::iVertex );
		glEnableVertexAttribArray( Shader::AttribLocation::iColor );
		glVertexAttribPointer( Shader::AttribLocation::iVertex, 3, GL_FLOAT, GL_FALSE, 0, cube );
		glVertexAttribPointer( Shader::AttribLocation::iColor, 4, GL_FLOAT, GL_FALSE, 0, colors );
		glDrawArrays( GL_QUADS, 0, 24 );
	}
	m_queue.clear();
*/
