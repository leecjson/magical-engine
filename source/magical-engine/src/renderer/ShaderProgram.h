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
#include "RenderCommon.h"
#include "Reference.h"

NAMESPACE_MAGICAL

class ShaderProgram : public Reference
{
public:
	ShaderProgram( void );
	virtual ~ShaderProgram( void );
	static Ptr<ShaderProgram> create( void );
	static Ptr<ShaderProgram> create( const char* vertex_src, const char* pixel_src );

public:	 
	void setVertexSource( const char* vertex_src );
	void setPixelSource( const char* pixel_src );
	uint32_t getId( void ) const { return m_program; }
	bool build( void );
	bool link( void );
	void shutdown( void );
	bool isDone( void ) const;

public:
	void bindAttribLocation( uint32_t index, const char* name ) const;
	int32_t getUniformLocation( const char* name ) const;

protected: 
	uint32_t m_program;
	std::string m_vertex_src;
	std::string m_pixel_src;
	bool m_built = false;
	bool m_linked = false;
};

NAMESPACE_END

#endif //__SHADER_PROGRAM_H__