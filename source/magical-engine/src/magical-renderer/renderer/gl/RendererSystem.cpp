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
#include "ShaderProgramManager.h"

void Renderer::init( void )
{
	setDefault();
	magicalReturnIfError();

	ShaderProgramManager::init();
	magicalReturnIfError();
}

void Renderer::delc( void )
{
	ShaderProgramManager::delc();
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

	magicalCheckGLError();
}

void Renderer::setDefault( void )
{
	glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );

	glEnable( GL_DEPTH_TEST );
	glEnable( GL_CULL_FACE );

	magicalCheckGLError();
}

void Renderer::useProgram( uint32_t program_id )
{
	glUseProgram( program_id );
}