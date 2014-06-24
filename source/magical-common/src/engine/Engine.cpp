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
#include "PlatformMacros.h"
#include "Engine.h"
#include "GLFunction.h"
#include "kazmath.h"
#include "GL/matrix.h"
#include "GL/mat4stack.h"
#include "Common.h"
#include "Utils.h"

#include "LuaSystem.h"

static Vec2 s_win_size;
static kmMat4 s_orthographic_projection2d;
static timeval s_last_update_time;
static float s_delta_time;

static void magicalCalcDeltaTime( void )
{
	struct timeval tv_now;

	magicalGetTimeOfDay(&tv_now, nullptr);
	s_delta_time = (tv_now.tv_sec - s_last_update_time.tv_sec) + (tv_now.tv_usec - s_last_update_time.tv_usec) / 1000000.0f;
	s_delta_time = MAX(0, s_delta_time);

	s_last_update_time = tv_now;
}

MAGAPI_USER const Vec2& magicalGetWinSize()
{
	return s_win_size;
}

MAGAPI_USER float magicalGetDeltaTime( void )
{
	return s_delta_time;
}

MAGAPI void magicalEngineInit( void )
{
	s_win_size = Vec2(0, 0);
	s_delta_time = 0.0f;
	
	magicalGetTimeOfDay(&s_last_update_time, nullptr);
	magicalSetGLDefault();
}

MAGAPI void magicalEngineDelc( void )
{
	
}

MAGAPI bool magicalEngineInitSystems( void )
{
	magicalLuaSystemInit();

	return true;
}

MAGAPI bool magicalEngineDelcSystems( void )
{
	magicalLuaSystemDelc();

	return true;
}

MAGAPI void magicalOnReshape( int w, int h )
{
	glViewport(0, 0, w, h);

	kmGLFreeAll();

	kmGLMatrixMode(KM_GL_MODELVIEW);
	kmGLLoadIdentity();

	kmGLMatrixMode(KM_GL_PROJECTION);
	kmGLLoadIdentity();

	kmMat4OrthographicProjection(&s_orthographic_projection2d, 0, w, 0, h, -1.0f, 1.0f);
	
	s_win_size = Vec2(w, h);
}

MAGAPI void magicalOnRender( void )
{
	magicalCalcDeltaTime();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	kmGLMatrixMode(KM_GL_PROJECTION);

#if 0
	// 3d render
	kmGLLoadMatrix(&s_orthographic_projection2d);
	kmGLPushMatrix();
		kmGLMatrixMode(KM_GL_MODELVIEW);
		kmGLPushMatrix();
		
		kmGLPopMatrix();
	kmGLMatrixMode(KM_GL_PROJECTION);
	kmGLPopMatrix();
#endif

	// 2d render
	kmGLLoadMatrix(&s_orthographic_projection2d);
	kmGLPushMatrix();
		kmGLMatrixMode(KM_GL_MODELVIEW);
		kmGLPushMatrix();

		kmGLPopMatrix();
	kmGLMatrixMode(KM_GL_PROJECTION);
	kmGLPopMatrix();

	
}

MAGAPI void magicalSetGLDefault( void )
{
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

	glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}