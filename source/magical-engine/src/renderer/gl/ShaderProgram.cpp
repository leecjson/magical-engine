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

NAMESPACE_MAGICAL

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
	MAGICAL_ASSERT( ret, "new ShaderProgram() failed" );
	return Ptr<ShaderProgram>( Ptrctor<ShaderProgram>( ret ) );
}

Ptr<ShaderProgram> ShaderProgram::create( const char* vert, const char* frag )
{
	ShaderProgram* ret = new ShaderProgram();
	MAGICAL_ASSERT( ret, "new ShaderProgram() failed" );
	ret->setSource( vert, frag );
	return Ptr<ShaderProgram>( Ptrctor<ShaderProgram>( ret ) );
}

void ShaderProgram::setSource( const char* vert, const char* frag )
{
	m_vert_src = vert;
	m_frag_src = frag;
}

void ShaderProgram::shutdown( void )
{
	if( m_program != GL_ZERO )
	{
		if( glIsProgram( m_program ) )
			glDeleteProgram( m_program );

		m_built = false;
		m_linked = false;
		m_program = GL_ZERO;
		m_vertex_index_array.clear();

		MAGICAL_CHECK_GL_ERROR();
	}
}

bool ShaderProgram::build( void )
{
	MAGICAL_ASSERT( !m_vert_src.empty() && !m_frag_src.empty(), "Invalid! should not empty!" );
	MAGICAL_ASSERT( !m_built, "Invalid! already built!" );

	GLint success = GL_FALSE;
	GLuint program = GL_ZERO;
	GLuint vert_shader = glCreateShader( GL_VERTEX_SHADER );
	GLuint frag_shader = glCreateShader( GL_FRAGMENT_SHADER );

	if( vert_shader == GL_ZERO ||
		frag_shader == GL_ZERO )
	{
		MAGICAL_CHECK_GL_ERROR();
		glDeleteShader( vert_shader );
		glDeleteShader( frag_shader );
		return false;
	}

	GLchar* buffer[1];
	buffer[0] = (GLchar*) m_vert_src.c_str();
	glShaderSource( vert_shader, 1, (const GLchar**)buffer, NULL );
	buffer[0] = (GLchar*) m_frag_src.c_str();
	glShaderSource( frag_shader, 1, (const GLchar**)buffer, NULL );

	glCompileShader( vert_shader );
	glCompileShader( frag_shader );

	glGetShaderiv( vert_shader, GL_COMPILE_STATUS, &success );
	if( success == GL_FALSE )
	{
		char* info = nullptr;
		MAGICAL_GET_SHADER_INFO_LOG( vert_shader, info );
		MAGICAL_LOGE( info );
		::free( info );

		MAGICAL_CHECK_GL_ERROR();
		glDeleteShader( vert_shader );
		glDeleteShader( frag_shader );
		return false;
	}

	glGetShaderiv( frag_shader, GL_COMPILE_STATUS, &success );
	if( success == GL_FALSE )
	{
		char* info = nullptr;
		MAGICAL_GET_SHADER_INFO_LOG( frag_shader, info );
		MAGICAL_LOGE( info );
		::free( info );

		MAGICAL_CHECK_GL_ERROR();
		glDeleteShader( vert_shader );
		glDeleteShader( frag_shader );
		return false;
	}

	program = glCreateProgram();
	if( program == GL_ZERO )
	{
		MAGICAL_CHECK_GL_ERROR();
		glDeleteShader( vert_shader );
		glDeleteShader( frag_shader );
		return false;
	}

	glAttachShader( program, vert_shader );
	glAttachShader( program, frag_shader );
	glDeleteShader( vert_shader );
	glDeleteShader( frag_shader );

	MAGICAL_CHECK_GL_ERROR();
	MAGICAL_RETURN_EXP_IF_ERROR( false );

	m_built = true;
	m_program = program;
	return true;
}

bool ShaderProgram::link( void )
{
	MAGICAL_ASSERT( m_built, "Invalid! build first!" );
	MAGICAL_ASSERT( m_linked == false, "Invalid! already linked!" );
	MAGICAL_ASSERT( m_program && glIsProgram( m_program ), "Invalid!" );

	GLint success = GL_FALSE;

	glLinkProgram( m_program );
	glGetProgramiv( m_program, GL_LINK_STATUS, &success );
	if( success == GL_FALSE )
	{
		char* info = nullptr;
		MAGICAL_GET_PROGRAM_INFO_LOG( m_program, info );
		MAGICAL_LOGE( info );
		::free( info );

		MAGICAL_CHECK_GL_ERROR();
		glDeleteProgram( m_program );
		return false;
	}

	glValidateProgram( m_program );
	glGetProgramiv( m_program, GL_VALIDATE_STATUS, &success );
	if( success == GL_FALSE )
	{
		char* info = nullptr;
		MAGICAL_GET_PROGRAM_INFO_LOG( m_program, info );
		MAGICAL_LOGE( info );
		::free( info );

		MAGICAL_CHECK_GL_ERROR();
		glDeleteProgram( m_program );
		return false;
	}

	MAGICAL_CHECK_GL_ERROR();
	MAGICAL_RETURN_EXP_IF_ERROR( false );

	m_linked = true;
	return true;
}

bool ShaderProgram::isDone( void ) const
{
	return m_built && m_linked && m_program;
}

void ShaderProgram::bindAttribLocation( unsigned int index, const char* name )
{
	glBindAttribLocation( m_program, index, name );
	MAGICAL_DEBUG_CHECK_GL_ERROR();

	m_vertex_index_array.push_back( index );
}

int ShaderProgram::getUniformLocation( const char* name ) const
{
	int location = glGetUniformLocation( m_program, name );
	MAGICAL_DEBUG_CHECK_GL_ERROR();
	return location;
}

void ShaderProgram::uniform1i( int location, Shader::int_t x )
{
	glUniform1i( location, x );
}

void ShaderProgram::uniform2i( int location, Shader::int_t x, Shader::int_t y )
{
	glUniform2i( location, x, y );
}

void ShaderProgram::uniform3i( int location, Shader::int_t x, Shader::int_t y, Shader::int_t z )
{
	glUniform3i( location, x, y, z );
}

void ShaderProgram::uniform4i( int location, Shader::int_t x, Shader::int_t y, Shader::int_t z, Shader::int_t w )
{
	glUniform4i( location, x, y, z, w );
}

void ShaderProgram::uniform1iv( int location, size_t count, const Shader::int_t* v )
{
	glUniform1iv( location, count, v );
}

void ShaderProgram::uniform2iv( int location, size_t count, const Shader::int_t* v )
{
	glUniform2iv( location, count, v );
}

void ShaderProgram::uniform3iv( int location, size_t count, const Shader::int_t* v )
{
	glUniform3iv( location, count, v );
}

void ShaderProgram::uniform4iv( int location, size_t count, const Shader::int_t* v )
{
	glUniform4iv( location, count, v );
}

void ShaderProgram::uniform1f( int location, Shader::float_t x )
{
	glUniform1f( location, x );
}

void ShaderProgram::uniform2f( int location, Shader::float_t x, Shader::float_t y )
{
	glUniform2f( location, x, y );
}

void ShaderProgram::uniform3f( int location, Shader::float_t x, Shader::float_t y, Shader::float_t z )
{
	glUniform3f( location, x, y, z );
}

void ShaderProgram::uniform4f( int location, Shader::float_t x, Shader::float_t y, Shader::float_t z, Shader::float_t w )
{
	glUniform4f( location, x, y, z, w );
}

void ShaderProgram::uniform1fv( int location, size_t count, const Shader::float_t* v )
{
	glUniform1fv( location, count, v );
}

void ShaderProgram::uniform2fv( int location, size_t count, const Shader::float_t* v )
{
	glUniform2fv( location, count, v );
}

void ShaderProgram::uniform3fv( int location, size_t count, const Shader::float_t* v )
{
	glUniform3fv( location, count, v );
}

void ShaderProgram::uniform4fv( int location, size_t count, const Shader::float_t* v )
{ 
	glUniform4fv( location, count, v );
}

void ShaderProgram::uniform2x2f( int location, size_t count, bool transpose, const Shader::float_t* v )
{
	glUniformMatrix2fv( location, count, transpose, v );
}

void ShaderProgram::uniform2x3f( int location, size_t count, bool transpose, const Shader::float_t* v )
{
	glUniformMatrix2x3fv( location, count, transpose, v );
}

void ShaderProgram::uniform3x3f( int location, size_t count, bool transpose, const Shader::float_t* v )
{
	glUniformMatrix3fv( location, count, transpose, v );
}

void ShaderProgram::uniform3x4f( int location, size_t count, bool transpose, const Shader::float_t* v )
{
	glUniformMatrix3x4fv( location, count, transpose, v );
}

void ShaderProgram::uniform4x3f( int location, size_t count, bool transpose, const Shader::float_t* v )
{
	glUniformMatrix4x3fv( location, count, transpose, v );
}

void ShaderProgram::uniform4x4f( int location, size_t count, bool transpose, const Shader::float_t* v )
{
	glUniformMatrix4fv( location, count, transpose, v );
}

NAMESPACE_END