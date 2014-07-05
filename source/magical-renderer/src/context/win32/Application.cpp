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
#include "Application.h"

#include "GLFunction.h"
#include "glut/glut.h"

#include "Common.h"
#include "Engine.h"
#include "LuaSystem.h"

#define magicalWin32ReturnIfError() \
if( magicalIsError() == true ) \
{ \
	MessageBoxA(nullptr, magicalGetLastErrorInfo(), "Error", MB_OK); \
	return; \
}

static FinishLaunchingEvent s_on_finish_launching = nullptr;

static void win32SetupWindow( void );
static void win32ShutdownWindow( void );
static void win32SetupGL( void );
static void win32ShutdownGL( void );
static void win32GlutReshape( int w, int h );
static void win32GlutDisplay( void );

static void win32SetupWindow( void )
{
	GLint argc = 0;

	glutInit(&argc, nullptr);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(960, 640);
	glutCreateWindow("Magical Engine");

	glutReshapeFunc(win32GlutReshape);
	glutDisplayFunc(win32GlutDisplay);
}

static void win32ShutdownWindow( void )
{
	
}

static void win32SetupGL( void )
{
	GLenum result = glewInit();
	if( result != GLEW_OK )
	{
		magicalSetLastErrorInfo("init glew error");
		magicalLogLastError();
	}
}

static void win32ShutdownGL( void )
{
}

static void win32GlutReshape( int w, int h )
{ 
	Engine::reshape(w, h);
}

static void win32GlutDisplay( void )
{
	Engine::mainLoop();

	glutSwapBuffers();
	glutPostRedisplay();
}

void Application::setOnFinishLaunching( FinishLaunchingEvent callback )
{
	s_on_finish_launching = callback;
}

void Application::run( void )
{
	win32SetupWindow();
	magicalWin32ReturnIfError();

	win32SetupGL();
	magicalWin32ReturnIfError();

	Engine::init();
	magicalWin32ReturnIfError();

	Engine::initSystems();
	magicalWin32ReturnIfError();

	s_on_finish_launching();

	glutMainLoop();

	Engine::delcSystems();
	magicalWin32ReturnIfError();

	Engine::delc();
	magicalWin32ReturnIfError();

	win32ShutdownGL();
	magicalWin32ReturnIfError();

	win32ShutdownWindow();
	magicalWin32ReturnIfError();
}


