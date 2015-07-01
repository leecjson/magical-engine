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
#ifndef __SHADER_PROGRAM_H__
#define __SHADER_PROGRAM_H__

#include "magical-macros.h"
#include "Common.h"
#include "Reference.h"

#include "RenderDefine.h"
#include "Shaders.h"

NAMESPACE_MAGICAL

class Shader;

class ShaderProgram : public Reference
{
public:
	ShaderProgram( void );
	virtual ~ShaderProgram( void );
	static Ptr<ShaderProgram> create( void );
	static Ptr<ShaderProgram> create( const char* vert, const char* frag );

public:	
	void setSource( const char* vert, const char* frag );
	bool build( void );
	bool link( void );
	void shutdown( void );
	bool isDone( void ) const;
	void bindAttribLocation( unsigned int index, const char* name );
	unsigned int getId( void ) const { return m_program; }
	int getUniformLocation( const char* name ) const;
	void use( void ) const;
	
public:
	void uniform1i( int location, Shader::int_t x );
	void uniform2i( int location, Shader::int_t x, Shader::int_t y );
	void uniform3i( int location, Shader::int_t x, Shader::int_t y, Shader::int_t z );
	void uniform4i( int location, Shader::int_t x, Shader::int_t y, Shader::int_t z, Shader::int_t w );
	void uniform1iv( int location, size_t count, const Shader::int_t* v );
	void uniform2iv( int location, size_t count, const Shader::int_t* v );
	void uniform3iv( int location, size_t count, const Shader::int_t* v );
	void uniform4iv( int location, size_t count, const Shader::int_t* v );
	void uniform1f( int location, Shader::float_t x );
	void uniform2f( int location,Shader::float_t x, Shader::float_t y );
	void uniform3f( int location, Shader::float_t x, Shader::float_t y, Shader::float_t z );
	void uniform4f( int location, Shader::float_t x, Shader::float_t y, Shader::float_t z, Shader::float_t w );
	void uniform1fv( int location, size_t count, const Shader::float_t* v );
	void uniform2fv( int location, size_t count, const Shader::float_t* v );
	void uniform3fv( int location, size_t count, const Shader::float_t* v );
	void uniform4fv( int location, size_t count, const Shader::float_t* v );
	void uniform2x2f( int location, size_t count, bool transpose, const Shader::float_t* v );
	void uniform2x3f( int location, size_t count, bool transpose, const Shader::float_t* v );
	void uniform3x3f( int location, size_t count, bool transpose, const Shader::float_t* v );
	void uniform3x4f( int location, size_t count, bool transpose, const Shader::float_t* v );
	void uniform4x3f( int location, size_t count, bool transpose, const Shader::float_t* v );
	void uniform4x4f( int location, size_t count, bool transpose, const Shader::float_t* v );

protected: 
	unsigned int m_program;
	std::string m_vert_src;
	std::string m_frag_src;
	bool m_built = false;
	bool m_linked = false;
};

NAMESPACE_END

#endif //__SHADER_PROGRAM_H__