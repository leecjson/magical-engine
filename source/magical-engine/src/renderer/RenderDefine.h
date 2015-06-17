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
#ifndef __RENDER_COMMON_H__
#define __RENDER_COMMON_H__

#include "magical-macros.h"
#include "Common.h"

#ifdef MAGICAL_USING_GL
#ifdef MAGICAL_WIN32
#include "win32/gl/glew/glew.h"
#endif

#define MAGICAL_CHECK_GL_ERROR() do {                                              \
	if( GLenum glerror = glGetError() ) {                                          \
		MAGICAL_SET_LAST_ERROR( System::format( "GL 0x%04X", glerror ).c_str() );  \
		MAGICAL_LOG_LAST_ERROR();                                                  \
	}                                                                              \
	} while( 0 )

#ifndef MAGICAL_DEBUG
#define MAGICAL_DEBUG_CHECK_GL_ERROR()
#else
#define MAGICAL_DEBUG_CHECK_GL_ERROR() MAGICAL_CHECK_GL_ERROR()
#endif

MAGICALAPI bool MAGICAL_GET_SHADER_INFO_LOG( GLuint shader );
MAGICALAPI bool MAGICAL_GET_PROGRAM_INFO_LOG( GLuint program );
#endif

#ifdef MAGICAL_USING_D3D11
#endif

NAMESPACE_MAGICAL

struct DrawMode
{
	static const unsigned int Invalid = -1;
#ifdef MAGICAL_USING_GL
	enum : unsigned int
	{
		Triangles = GL_TRIANGLES,
		TrianglesStrip = GL_TRIANGLE_STRIP,
		Polygon = GL_POLYGON,
	};
#endif
#ifdef MAGICAL_USING_D3D11
#endif
};

NAMESPACE_END

#endif //__RENDER_COMMON_H__