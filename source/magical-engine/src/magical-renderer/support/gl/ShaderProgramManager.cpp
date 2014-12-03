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
#include "AssetsSystem.h"

enum
{
	kAttribIndex_Vertex = 0,
	kAttribIndex_Color,
	kAttribIndex_TextureCoord,
	kAttribIndex_Normal,
};

#define kAttribName_Vertex                 "a_vertex"
#define kAttribName_Color                  "a_color"
#define kAttribName_TextureCoord           "a_texture_coord"
#define kAttribName_Normal                 "a_normal"

#define kUniformName_Color                 "u_color"
#define kUniformName_MvpMatrix             "u_mvp_matrix"
#define kUniformName_MvMatrix              "u_mv_matrix"
#define kUniformName_PMatrix               "u_p_matrix"
#define kUniformName_TexUnit               "u_tex_unit0"

//static bool createProgram( ShaderProgramIndex index, ShaderProgram* program );

static ShaderProgram* s_programs[ kShaderProgram_Count ] = { nullptr };

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
	//ShaderProgram* program = nullptr;
	//ShaderProgramIndex index;
	//
	//for( uint32_t i = 0; i < kShaderProgram_Count; ++i )
	//{
	//	index = (ShaderProgramIndex) i;
	//	program = new ShaderProgram();

	//	if( !buildProgram( index, program ) )
	//		return;

	//	if( !program->bind( index, program ) )
	//		return;

	//	if( !program->link() )
	//		return;

	//	if( !program->isReady() )
	//		return;

	//	s_programs[ i ] = program;
	//}
}

void ShaderProgramManager::delcPrograms( void )
{
	//for( uint32_t i = 0; i < kShaderProgram_Count; ++i )
	//{
	//	magicalSafeReleaseNull( s_programs[ i ] );
	//}
}

const Shared<ShaderProgram> ShaderProgramManager::getProgram( ShaderProgramIndex index )
{
	return s_programs[ index ];
}

//static ShaderProgram* createProgram( ShaderProgramIndex index, ShaderProgram* program )
//{
//	ShaderProgram* program = nullptr;
//	Shared<Data> vertex_data;
//	Shared<Data> fragment_data;
//
//	switch( index )
//	{
//	case kShaderProgram_Color:
//		{
//			program = new ShaderProgramColor();
//			vertex_data = Assets::getAssetsFileData( "standard/shaders/test_vertex.glsl" );
//			fragment_data = Assets::getAssetsFileData( "standard/shaders/test_fragment.glsl" );
//		}
//		break;
//	default:
//		break;
//	}
//
//	if( vertex_data == nullptr || fragment_data == nullptr )
//		return nullptr;
//
//	program->setVertexSource( vertex_data->ptr() );
//	program->setFragmentSource( fragment_data->ptr() );
//	
//	if( !program->build() )
//		return nullptr;
//
//	if( !program-> )
//
//
//	return program;
//}


//MAGICALAPI GLvoid magicalSetShaderColorUniform(const GLfloat* mvp_matrix, const GLfloat* color)
//{
//	GLuint program = magicalGetShaderProgram(kShaderColor);
//
//	GLint location = glGetUniformLocation(program, kUniformNameMvpMatrix);
//	glUniformMatrix4fv(location, 1, GL_FALSE, mvp_matrix);
//	
//	location = glGetUniformLocation(program, kUniformNameColor);
//	glUniform4fv(location, 1, color);
//
//	glBinbAttr
//}




//ShaderProgramColor::ShaderProgramColor( void )
//: _uniform_mvp_matrix_location( GL_ZERO )
//, _uniform_color_location( GL_ZERO )
//{
//
//}
//
//ShaderProgramColor::~ShaderProgramColor( void )
//{
//
//}
//
//bool ShaderProgramColor::bindAttribLocation( void ) const
//{
//	if( !_has_built || !_has_linked || !isReady() )
//		return false;
//
//	glBindAttribLocation( _program_id, kAttribIndex_Vertex, kAttribName_Vertex );
//
//	magicalCheckGLError();
//	return !magicalIsError();
//}
//
//bool ShaderProgramColor::bindUniformLocation( void )
//{
//	_uniform_mvp_matrix_location = glGetUniformLocation( _program_id, kUniformName_MvpMatrix );
//}
//
//int ShaderProgramColor::getUniformLocation( const char* name ) const
//{
//
//}