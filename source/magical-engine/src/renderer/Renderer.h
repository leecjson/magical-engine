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
#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "magical-macros.h"
#include "magical-math.h"
#include "Common.h"
#include "ViewChannel.h"

#include "RenderDefine.h"
#include "ShaderProgram.h"
#include "Shaders.h"
#include "VertexBufferObject.h"
#include "RenderCommand.h"

NAMESPACE_MAGICAL

class Renderer
{
public:
	static void init( void );
	static void delc( void );

public:
	static void setDefault( void );

public:
	static void render( unsigned int index, ViewChannel* channel );
	static void addCommand( RenderCommand* command );

	static VertexBufferObject* newVertexBufferObject( void );
	static void deleteVertexBufferObject( VertexBufferObject* vbo );

private:
	static void processCommands( void );
};

NAMESPACE_END

#endif //__RENDERER_H__
