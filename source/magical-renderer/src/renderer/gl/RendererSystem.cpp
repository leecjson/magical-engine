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
#include "RendererSystem.h"
#include "Application.h"
#include "RendererMacros.h"
#include "ShaderProgram.h"
#include "AssetsSystem.h"

void Renderer::init( void )
{
	setDefault();
	magicalReturnIfError();

	initPrograms();
	magicalReturnIfError();
}

void Renderer::delc( void )
{
	delcPrograms();
	magicalReturnIfError();
}

void Renderer::render( void )
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	//Renderer::useProgram( kShaderProgramColor );


	Application::swapBuffers();
	magicalDebugCheckGLError();
}

void Renderer::resize( int w, int h )
{
	glViewport( 0, 0, w, h );
}

void Renderer::setDefault( void )
{
	glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );

	glEnable( GL_DEPTH_TEST );
	glEnable( GL_CULL_FACE );

	magicalCheckGLError();
}

static ShaderProgram* s_programs[ kShaderProgramCount ] = { nullptr };
static GLuint s_programs_id[ kShaderProgramCount ] = { 0 };

void Renderer::initPrograms( void )
{
	ShaderProgram* program = nullptr;
	std::string vertex_src;
	std::string fragment_src;

	for( size_t i = kShaderProgramColor; i < kShaderProgramCount; ++i )
	{
		program = new ShaderProgram();
		switch( (ShaderProgramIndex) i )
		{
		case kShaderProgramColor:
			{
				vertex_src = Assets::getAssetsFileData( "standard/shaders/test_vertex.glsl" )->ptr();
				fragment_src = Assets::getAssetsFileData( "standard/shaders/test_fragment.glsl" )->ptr();
			}
			break;
		default:
			break;
		}

		program->setVertexSource( vertex_src.c_str() );
		program->setFragmentSource( fragment_src.c_str() );
		if( !program->build() || !program->link() || !program->isReady() )
		{
			return;
		}

		s_programs_id[ i ] = program->getId();
		s_programs[ i ] = program;
	}
}

void Renderer::delcPrograms( void )
{
	for( size_t i = kShaderProgramColor; i < kShaderProgramCount; ++i )
	{
		magicalSafeReleaseNull( s_programs[ i ] );
		s_programs_id[ i ] = 0;
	}
}

void Renderer::useProgram( ShaderProgramIndex idx )
{
	glUseProgram( s_programs_id[ idx ] );
}

void Renderer::useCustomProgram( uint32_t program_id )
{
	glUseProgram( program_id );
}