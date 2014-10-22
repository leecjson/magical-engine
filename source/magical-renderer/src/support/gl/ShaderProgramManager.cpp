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
#include "ShaderProgramManager.h"
#include "ShaderProgram.h"
#include "AssetsSystem.h"

enum
{
	kAttribVertex = 0,
	kAttribColor = 1,
	kAttribTexCoord = 2,
	kAttribNormal = 3,
};

#define kAttribNameVertex                 "a_vertex"
#define kAttribNameColor                  "a_color"
#define kAttribNameTexCoord               "a_tex_coord"
#define kAttribNameNormal                 "a_normal"

#define kUniformNameColor                 "u_color"
#define kUniformNameMvpMatrix             "u_mvp_matrix"
#define kUniformNameMvMatrix              "u_mv_matrix"
#define kUniformNamePMatrix               "u_p_matrix"
#define kUniformNameTexUnit               "u_tex_unit0"

static bool buildProgram( ShaderProgramIndex index, ShaderProgram* program );
static bool bindAttribute( ShaderProgramIndex index, ShaderProgram* program );

static ShaderProgram* s_programs[ kShaderProgramCount ] = { nullptr };

void ShaderProgramManager::init( void )
{
	initPrograms();
	magicalReturnIfError();
}

void ShaderProgramManager::delc( void )
{
	delcPrograms();
	magicalReturnIfError();
}

void ShaderProgramManager::initPrograms( void )
{
	ShaderProgram* program = nullptr;
	ShaderProgramIndex index;
	
	for( uint32_t i = kShaderProgramColor; i < kShaderProgramCount; ++i )
	{
		index = (ShaderProgramIndex) i;
		program = new ShaderProgram();

		if( !buildProgram( index, program ) )
			return;

		if( !bindAttribute( index, program ) )
			return;

		if( !program->link() )
			return;

		if( !program->isReady() )
			return;

		s_programs[ i ] = program;
	}
}

void ShaderProgramManager::delcPrograms( void )
{
	for( uint32_t i = kShaderProgramColor; i < kShaderProgramCount; ++i )
	{
		magicalSafeReleaseNull( s_programs[ i ] );
	}
}

const Shared<ShaderProgram> ShaderProgramManager::getProgram( ShaderProgramIndex index )
{
	return s_programs[ index ];
}

static bool buildProgram( ShaderProgramIndex index, ShaderProgram* program )
{
	Shared<Data> vertex_data;
	Shared<Data> fragment_data;

	switch( index )
	{
	case kShaderProgramColor:
		{
			vertex_data = Assets::getAssetsFileData( "standard/shaders/test_vertex.glsl" );
			fragment_data = Assets::getAssetsFileData( "standard/shaders/test_fragment.glsl" );
		}
		break;
	default:
		break;
	}

	if( vertex_data == nullptr || fragment_data == nullptr )
		return false;

	program->setVertexSource( vertex_data->ptr() );
	program->setFragmentSource( fragment_data->ptr() );
	
	return program->build();
}

static bool bindAttribute( ShaderProgramIndex index, ShaderProgram* program )
{
	switch( index )
	{
	case kShaderProgramColor:
		{
			glBindAttribLocation( program->getId(), kAttribVertex, kAttribNameVertex );
		}
		break;
	default:
		break;
	}	

	magicalCheckGLError();
	return !magicalIsError();
}

MAGAPI GLvoid magicalSetShaderColorUniform(const GLfloat* mvp_matrix, const GLfloat* color)
{
	GLuint program = magicalGetShaderProgram(kShaderColor);

	GLint location = glGetUniformLocation(program, kUniformNameMvpMatrix);
	glUniformMatrix4fv(location, 1, GL_FALSE, mvp_matrix);
	
	location = glGetUniformLocation(program, kUniformNameColor);
	glUniform4fv(location, 1, color);
}