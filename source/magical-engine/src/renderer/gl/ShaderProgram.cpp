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
#include "RendererMacros.h"

NS_MAGICAL_BEGIN

ShaderProgram::ShaderProgram( void )
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
	return Ptr<ShaderProgram>( Initializer<ShaderProgram>( ret ) );
}

void ShaderProgram::setVertexSource( const char* vertex_src )
{
	_vertex_src = vertex_src;
}

void ShaderProgram::setFragmentSource( const char* fragment_src )
{
	_fragment_src = fragment_src;
}

void ShaderProgram::shutdown( void )
{
	if( _program_id != GL_ZERO )
	{
		if( glIsProgram( _program_id ) )
		{
			glDeleteProgram( _program_id );
			magicalCheckGLError();
		}
		_is_built = false;
		_is_linked = false;
		_program_id = GL_ZERO;
	}
}

bool ShaderProgram::build( void )
{
	magicalAssert( !_vertex_src.empty() && !_fragment_src.empty(), "should not be empty!" );

	GLchar* buffer[1];
	GLuint program = GL_ZERO;
	GLint err_signal = GL_FALSE;
	GLuint vertex_shader = GL_ZERO;
	GLuint fragment_shader = GL_ZERO;

	if( _is_built )
	{
		shutdown();
	}

	vertex_shader = glCreateShader( GL_VERTEX_SHADER );
	fragment_shader = glCreateShader( GL_FRAGMENT_SHADER );

	if( !( vertex_shader && fragment_shader ) )
	{
		magicalCheckGLError();
		glDeleteShader( vertex_shader );
		glDeleteShader( fragment_shader );
		return false;
	}

	buffer[0] = (GLchar*)_vertex_src.c_str();
	glShaderSource( vertex_shader, 1, (const GLchar**)buffer, NULL );
	buffer[0] = (GLchar*)_fragment_src.c_str();
	glShaderSource( fragment_shader, 1, (const GLchar**)buffer, NULL );

	glCompileShader( vertex_shader );
	glCompileShader( fragment_shader );

	glGetShaderiv( vertex_shader, GL_COMPILE_STATUS, &err_signal );
	if( err_signal == GL_FALSE )
	{
		if( magicalGetShaderInfoLog( vertex_shader ) )
		{
			magicalSetLastErrorA( magicalBuffer );
			magicalLogLastError();
		}
		else
		{
			magicalCheckGLError();
		}

		glDeleteShader( vertex_shader );
		glDeleteShader( fragment_shader );
		return false;
	}

	glGetShaderiv( fragment_shader, GL_COMPILE_STATUS, &err_signal );
	if( err_signal == GL_FALSE )
	{
		if( magicalGetShaderInfoLog( fragment_shader ) )
		{
			magicalSetLastErrorA( magicalBuffer );
			magicalLogLastError();
		}
		else
		{
			magicalCheckGLError();
		}

		glDeleteShader( vertex_shader );
		glDeleteShader( fragment_shader );
		return false;
	}

	program = glCreateProgram();
	if( program == GL_ZERO )
	{
		magicalCheckGLError();
		glDeleteShader( vertex_shader );
		glDeleteShader( fragment_shader );
		return false;
	}

	glAttachShader( program, vertex_shader );
	glAttachShader( program, fragment_shader );
	glDeleteShader( vertex_shader );
	glDeleteShader( fragment_shader );

	magicalCheckGLError();
	magicalReturnVarIfError( false );

	_program_id = program;
	_is_built = true;
	return true;
}

bool ShaderProgram::link( void )
{
	magicalAssert( _is_built, "build first!" );
	magicalAssert( !_is_linked, "already linked!" );

	GLint err_signal = GL_FALSE;

	if( glIsProgram( _program_id ) == GL_FALSE )
	{
		magicalCheckGLError();
		return false;
	}

	glLinkProgram( _program_id );
	glGetProgramiv( _program_id, GL_LINK_STATUS, &err_signal );
	if( err_signal == GL_FALSE )
	{
		if( magicalGetProgramInfoLog( _program_id ) )
		{
			magicalSetLastErrorA( magicalBuffer );
			magicalLogLastError();
		}
		else
		{
			magicalCheckGLError();
		}

		glDeleteProgram( _program_id );
		return false;
	}

	glValidateProgram( _program_id );
	glGetProgramiv( _program_id, GL_VALIDATE_STATUS, &err_signal );
	if( err_signal == GL_FALSE )
	{
		if( magicalGetProgramInfoLog( _program_id ) )
		{
			magicalSetLastErrorA( magicalBuffer );
			magicalLogLastError();
		}
		else
		{
			magicalCheckGLError();
		}

		glDeleteProgram( _program_id );
		return false;
	}

	_is_linked = true;
	return true;
}

bool ShaderProgram::isReady( void ) const
{
	return _is_built && _is_linked && _program_id;
}

void ShaderProgram::bindAttribLocation( uint32_t index, const char* name ) const
{
	glBindAttribLocation( _program_id, index, name );
	magicalDebugCheckGLError();
}

int ShaderProgram::getUniformLocation( const char* name ) const
{
	int location = glGetUniformLocation( _program_id, name );
	magicalDebugCheckGLError();
	return location;
}

NS_MAGICAL_END