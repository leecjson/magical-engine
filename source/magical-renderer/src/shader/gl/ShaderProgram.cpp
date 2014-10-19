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
#include "gl/glew.h"

ShaderProgram::ShaderProgram( void )
: _program_id( GL_ZERO )
, _has_built( false )
, _has_linked( false )
{

}

ShaderProgram::~ShaderProgram( void )
{
	cleanup();
}

Shared<ShaderProgram> ShaderProgram::create( void )
{
	ShaderProgram* ret = new ShaderProgram();
	magicalAssert( ret, "New ShaderProgram() failed" );
	return Shared<ShaderProgram>( Initializer<ShaderProgram>( ret ) );
}

void ShaderProgram::setVertexSource( const char* vertex_src )
{
	_vertex_src = vertex_src;
}

void ShaderProgram::setFragmentSource( const char* fragment_src )
{
	_fragment_src = fragment_src;
}

void ShaderProgram::cleanup( void )
{
	if( _program_id != GL_ZERO )
	{
		if( glIsProgram( _program_id ) )
		{
			glDeleteProgram( _program_id );
		}
		_has_built = false;
		_has_linked = false;
		_program_id = GL_ZERO;
	}
}

void ShaderProgram::build( void )
{
	magicalAssert( !_vertex_src.empty() && !_fragment_src.empty(), "should not empty!" );
	if( _has_built )
	{
		cleanup();
	}

	GLchar* buffer[1];
	GLuint  program = GL_ZERO;
	GLint   err_signal = GL_FALSE;
	GLuint  vertex_shader = GL_ZERO;
	GLuint  fragment_shader = GL_ZERO;

	//创建顶点与片段着色器对象
	vertex_shader = glCreateShader( GL_VERTEX_SHADER );
	fragment_shader = glCreateShader( GL_FRAGMENT_SHADER );

	//检测着色器程序创建是否成功
	if( !( vertex_shader && fragment_shader ) )
	{
		magicalCheckGLError();
		glDeleteShader( vertex_shader );
		glDeleteShader( fragment_shader );
		return GL_FALSE;
	}

	//传递着色器源代码
	buffer[0] = (GLchar*) vertex_shader_src;
	glShaderSource( vertex_shader, 1, (const GLchar**) buffer, NULL );
	buffer[0] = (GLchar*) fragment_shader_src;
	glShaderSource( fragment_shader, 1, (const GLchar**) buffer, NULL );

	//编译顶点着色器对象
	glCompileShader( vertex_shader );
	//编译片段着色器对象
	glCompileShader( fragment_shader );

	//查询顶点着色器编译错误
	glGetShaderiv( vertex_shader, GL_COMPILE_STATUS, &err_signal );
	if( err_signal == GL_FALSE )
	{
		magicalPrintShaderInfoLog( vertex_shader );
		glDeleteShader( vertex_shader );
		glDeleteShader( fragment_shader );
		return GL_FALSE;
	}

	//查询片段着色器编译错误
	glGetShaderiv( fragment_shader, GL_COMPILE_STATUS, &err_signal );
	if( err_signal == GL_FALSE )
	{
		magicalPrintShaderInfoLog( fragment_shader );
		glDeleteShader( vertex_shader );
		glDeleteShader( fragment_shader );
		return GL_FALSE;
	}

	//创建着色程序
	program = glCreateProgram();
	if( program == GL_ZERO )
	{
		magicalCheckGLError();
		glDeleteShader( vertex_shader );
		glDeleteShader( fragment_shader );
		return GL_FALSE;
	}

	//给着色程序添加着色器
	glAttachShader( program, vertex_shader );
	glAttachShader( program, fragment_shader );

	//把着色器对象置为删除状态
	glDeleteShader( vertex_shader );
	glDeleteShader( fragment_shader );


	_has_built = true;
}

void ShaderProgram::link( void )
{
	magicalAssert( _has_built == true, "build first!" );
	magicalAssert( _has_linked == false, "already linked!" );


	_has_linked = true;
}

uint32_t ShaderProgram::getId( void ) const
{
	return _program_id;
}