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
#include "ShaderProgram.h"

NS_MAGICAL_BEGIN

ShaderProgram::ShaderProgram( void )
: m_program( GL_ZERO )
{

}

ShaderProgram::~ShaderProgram( void )
{
	shutdown();
}

Ptr<ShaderProgram> ShaderProgram::create( void )
{
	ShaderProgram* ret = new ShaderProgram();
	magicalAssert( ret, "New ShaderProgram() failed" );
	return Ptr<ShaderProgram>( PtrCtor<ShaderProgram>( ret ) );
}

Ptr<ShaderProgram> ShaderProgram::create( const char* vertex_src, const char* pixel_src )
{
	ShaderProgram* ret = new ShaderProgram();
	magicalAssert( ret, "New ShaderProgram() failed" );
	ret->setVertexSource( vertex_src );
	ret->setPixelSource( pixel_src );
	return Ptr<ShaderProgram>( PtrCtor<ShaderProgram>( ret ) );
}

void ShaderProgram::setVertexSource( const char* vertex_src )
{
	m_vertex_src = vertex_src;
}

void ShaderProgram::setPixelSource( const char* pixel_src )
{
	m_pixel_src = pixel_src;
}

void ShaderProgram::shutdown( void )
{
	if( m_program == GL_ZERO )
		return;

	if( glIsProgram( m_program ) )
		glDeleteProgram( m_program );

	m_built = false;
	m_linked = false;
	m_program = GL_ZERO;
	magicalCheckGLError();
}

bool ShaderProgram::build( void )
{
	magicalAssert( !m_vertex_src.empty() && !m_pixel_src.empty(), "Invalid! should not empty!" );
	magicalAssert( !m_built, "Invalid! already built!" );

	GLint succeed = GL_FALSE;
	GLuint program = GL_ZERO;
	GLuint vertex_shader = glCreateShader( GL_VERTEX_SHADER );
	GLuint pixel_shader = glCreateShader( GL_FRAGMENT_SHADER );

	if( !vertex_shader || !pixel_shader )
	{
		magicalCheckGLError();
		glDeleteShader( vertex_shader );
		glDeleteShader( pixel_shader );
		return false;
	}

	GLchar* buffer[1];
	buffer[0] = (GLchar*) m_vertex_src.c_str();
	glShaderSource( vertex_shader, 1, (const GLchar**)buffer, NULL );
	buffer[0] = (GLchar*) m_pixel_src.c_str();
	glShaderSource( pixel_shader, 1, (const GLchar**)buffer, NULL );

	glCompileShader( vertex_shader );
	glCompileShader( pixel_shader );

	glGetShaderiv( vertex_shader, GL_COMPILE_STATUS, &succeed );
	if( succeed == GL_FALSE )
	{
		if( magicalGetShaderInfoLog( vertex_shader ) )
		{
			magicalSetLastError( magicalGetBuffer() );
			magicalLogLastErrorWithoutNewLine();
		}

		magicalCheckGLError();
		glDeleteShader( vertex_shader );
		glDeleteShader( pixel_shader );
		return false;
	}

	glGetShaderiv( pixel_shader, GL_COMPILE_STATUS, &succeed );
	if( succeed == GL_FALSE )
	{
		if( magicalGetShaderInfoLog( pixel_shader ) )
		{
			magicalSetLastError( magicalGetBuffer() );
			magicalLogLastErrorWithoutNewLine();
		}

		magicalCheckGLError();
		glDeleteShader( vertex_shader );
		glDeleteShader( pixel_shader );
		return false;
	}

	program = glCreateProgram();
	if( program == GL_ZERO )
	{
		magicalCheckGLError();
		glDeleteShader( vertex_shader );
		glDeleteShader( pixel_shader );
		return false;
	}

	glAttachShader( program, vertex_shader );
	glAttachShader( program, pixel_shader );
	glDeleteShader( vertex_shader );
	glDeleteShader( pixel_shader );

	magicalCheckGLError();
	magicalReturnVarIfError( false );

	m_program = program;
	m_built = true;
	return true;
}

bool ShaderProgram::link( void )
{
	magicalAssert( m_built, "Invalid! build first!" );
	magicalAssert( m_linked == false, "Invalid! already linked!" );
	magicalAssert( m_program && glIsProgram( m_program ), "Invalid!" );

	GLint succeed = GL_FALSE;

	glLinkProgram( m_program );
	glGetProgramiv( m_program, GL_LINK_STATUS, &succeed );
	if( succeed == GL_FALSE )
	{
		if( magicalGetProgramInfoLog( m_program ) )
		{
			magicalSetLastError( magicalGetBuffer() );
			magicalLogLastErrorWithoutNewLine();
		}

		magicalCheckGLError();
		glDeleteProgram( m_program );
		return false;
	}

	glValidateProgram( m_program );
	glGetProgramiv( m_program, GL_VALIDATE_STATUS, &succeed );
	if( succeed == GL_FALSE )
	{
		if( magicalGetProgramInfoLog( m_program ) )
		{
			magicalSetLastError( magicalGetBuffer() );
			magicalLogLastErrorWithoutNewLine();
		}

		magicalCheckGLError();
		glDeleteProgram( m_program );
		return false;
	}

	m_linked = true;
	return true;
}

bool ShaderProgram::isDone( void ) const
{
	return m_built && m_linked && m_program;
}

void ShaderProgram::bindAttribLocation( uint32_t index, const char* name ) const
{
	glBindAttribLocation( m_program, index, name );
	magicalDebugCheckGLError();
}

int32_t ShaderProgram::getUniformLocation( const char* name ) const
{
	int32_t location = glGetUniformLocation( m_program, name );
	magicalDebugCheckGLError();
	return location;
}

NS_MAGICAL_END