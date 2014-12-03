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
#ifndef __RENDERER_MACROS_H__
#define __RENDERER_MACROS_H__

#include "PlatformMacros.h"
#include "Common.h"

#ifdef MAGICAL_USING_GL

#ifdef MAGICAL_WIN32
#include "win32/gl/glew/glew.h"
#endif

#define magicalCheckGLError() \
	do { \
		if( GLenum __err_singnal = glGetError() ) \
		{ \
			magicalFormat( "[GL] Error 0x%04X", __err_singnal ); \
			magicalSetLastErrorInfoAt( magicalBuffer ); \
			magicalLogLastError(); \
		} \
	} while( 0 )

#ifndef MAGICAL_DEBUG
#define magicalDebugCheckGLError() 
#else
#define magicalDebugCheckGLError() magicalCheckGLError()
#endif

MAGICALAPI bool magicalGetShaderInfoLog( GLuint shader );
MAGICALAPI bool magicalGetProgramInfoLog( GLuint program );

#endif

#ifdef MAGICAL_USING_D3DX



#endif


#endif //__RENDERER_MACROS_H__