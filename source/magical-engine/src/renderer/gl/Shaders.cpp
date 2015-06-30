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

const char* Shader::Attribute::Vertex = "a_vertex";
const char* Shader::Attribute::Color = "a_color";
const char* Shader::Attribute::TexCoord = "a_tex_coord";
const char* Shader::Attribute::Normal = "a_normal";

const char* Shader::Uniform::Color = "u_color";
const char* Shader::Uniform::MvpMatrix = "u_mvp_matrix";
const char* Shader::Uniform::MvMatrix = "u_mv_matrix";
const char* Shader::Uniform::PMatrix = "u_p_matrix";
const char* Shader::Uniform::TexUnit0 = "u_tex_unit0";

const char* Shader::Source::DiffuseVert = 
R"(
	uniform mat4 u_mvp_matrix;
	attribute vec4 a_vertex;
	attribute vec4 a_color;
	varying vec4 v_color;

	void main( void ) {
		v_color = a_color;
		gl_Position = u_mvp_matrix * a_vertex;
	}
)";
						
const char* Shader::Source::DiffuseFrag = 
R"(
	varying vec4 v_color;

	void main( void ) {
		gl_FragColor = v_color;
	}
)";

static ShaderProgram* createPrograms( void )
{
#define PROGRAM_NEW( var, vert, frag ) var = new ShaderProgram(); var->setSource( vert, frag )
#define PROGRAM_BUILD( var ) if( !var->build() ) return nullptr
#define PROGRAM_LINK( var ) if( !var->link() ) return nullptr;

	PROGRAM_NEW( Shader::Diffuse, Shader::Source::DiffuseVert, Shader::Source::DiffuseFrag );
	PROGRAM_BUILD( Shader::Diffuse );
	Shader::Diffuse->bindAttribLocation( Shader::Attribute::iVertex, Shader::Attribute::Vertex );
	Shader::Diffuse->bindAttribLocation( Shader::Attribute::iColor, Shader::Attribute::Color );
	PROGRAM_LINK( Shader::Diffuse );
}

static void deletePrograms( void )
{
	Shader::FlatColor->release();
}

void Shader::init( void )
{
	createPrograms();
}

void Shader::delc( void )
{
	deletePrograms();
}


NAMESPACE_END