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
#include "Shaders.h"

NAMESPACE_MAGICAL

static ShaderProgram* s_programs[ Shader::Count ] = { nullptr };

const char* Shader::AttribLocation::Vertex = "a_vertex";
const char* Shader::AttribLocation::Color = "a_color";
const char* Shader::AttribLocation::TextureCoord = "a_texture_coord";
const char* Shader::AttribLocation::Normal = "a_normal";

const char* Shader::Uniform::Color = "u_color";
const char* Shader::Uniform::MvpMatrix = "u_mvp_matrix";
const char* Shader::Uniform::MvMatrix = "u_mv_matrix";
const char* Shader::Uniform::PMatrix = "u_p_matrix";
const char* Shader::Uniform::TexUnit0 = "u_tex_unit0";

const char* Shader::Source::SimpleVertex = 
R"(
	attribute vec4 a_vertex;

	void main( void )
	{
		gl_Position = a_vertex;
	}
)";
						
const char* Shader::Source::SimplePiexl = 
R"(
	uniform vec4 u_color;

	void main( void )
	{ 
		gl_FragColor = u_color;
	}
)";

const char* Shader::Source::FlatVertex = 
R"(
	uniform mat4 u_mvp_matrix;
	attribute vec4 a_vertex;
	attribute vec4 a_color;
	varying vec4 v_color;

	void main( void )
	{
		v_color = a_color;
		gl_Position = u_mvp_matrix * a_vertex;
	}
)";
						
const char* Shader::Source::FlatPiexl = 
R"(
	varying vec4 v_color;

	void main( void )
	{ 
		gl_FragColor = v_color;
	}
)";

static void assignProgramSource( int index, ShaderProgram* program )
{
	switch( index )
	{
	case Shader::Simple:
		program->setVertexSource( Shader::Source::SimpleVertex );
		program->setPixelSource( Shader::Source::SimplePiexl );
		break;
	case Shader::Flat:
		program->setVertexSource( Shader::Source::FlatVertex );
		program->setPixelSource( Shader::Source::FlatPiexl );
		break;
	default:
		MAGICAL_ASSERT( false, "Invalid!" );
		break;
	}
}

static void bindAttribLocation( int index, ShaderProgram* program )
{
	switch( index )
	{
	case Shader::Simple:
		program->bindAttribLocation( Shader::AttribLocation::iVertex, Shader::AttribLocation::Vertex );
		break;
	case Shader::Flat:
		program->bindAttribLocation( Shader::AttribLocation::iVertex, Shader::AttribLocation::Vertex );
		program->bindAttribLocation( Shader::AttribLocation::iColor, Shader::AttribLocation::Color );
		break;
	default:
		MAGICAL_ASSERT( false, "Invalid!" );
		break;
	}
}

static ShaderProgram* createProgram( int index )
{
	ShaderProgram* program = new ShaderProgram();

	assignProgramSource( index, program );
	if( !program->build() )
		return nullptr;

	bindAttribLocation( index, program );
	if( !program->link() )
		return nullptr;
	
	if( !program->isDone() )
		return nullptr;

	return program;
}

void Shader::init( void )
{
	ShaderProgram* program;
	for( int index = 0; index < Shader::Count; index ++ )
	{
		program = createProgram( index );
		if( program == nullptr )
			return;

		s_programs[ index ] = program;
	}
}

void Shader::delc( void )
{
	for( int index = 0; index < Shader::Count; index ++ )
	{
		s_programs[ index ]->release();
	}
}

ShaderProgram* Shader::getProgram( int index )
{
	MAGICAL_ASSERT( 0 <= index && index <= Shader::Count, "Invalid index!" );

	return s_programs[ index ];
}

NAMESPACE_END