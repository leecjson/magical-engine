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
#include "RendererSystem.h"

void Renderer::init( void )
{

}

void Renderer::delc( void )
{
	
}

void Renderer::render( void )
{
}

void Renderer::reshape( int w, int h )
{

}

//static void setGLDefault( void )
//{
//	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
//
//	glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
//}

//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//kmGLMatrixMode(KM_GL_PROJECTION);

//#if 0
//	// 3d render
//	kmGLLoadMatrix(&s_orthographic_projection2d);
//	kmGLPushMatrix();
//		kmGLMatrixMode(KM_GL_MODELVIEW);
//		kmGLPushMatrix();
//		
//		kmGLPopMatrix();
//	kmGLMatrixMode(KM_GL_PROJECTION);
//	kmGLPopMatrix();
//#endif
//
//#if 0
//	// 2d render
//	kmGLLoadMatrix(&s_orthographic_projection2d);
//	kmGLPushMatrix();
//		kmGLMatrixMode(KM_GL_MODELVIEW);
//		kmGLPushMatrix();
//
//		kmGLPopMatrix();
//	kmGLMatrixMode(KM_GL_PROJECTION);
//	kmGLPopMatrix();
//#endif

/*glViewport(0, 0, w, h);

	kmGLFreeAll();

	kmGLMatrixMode(KM_GL_MODELVIEW);
	kmGLLoadIdentity();

	kmGLMatrixMode(KM_GL_PROJECTION);
	kmGLLoadIdentity();*/

	//kmMat4OrthographicProjection(&s_orthographic_projection2d, 0, w, 0, h, -1.0f, 1.0f);