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
#include "Application.h"
#include "Common.h"
#include "Director.h"

#include "glut/glut.h"


MAGAPI void magicalRun( void )
{
	GLint argc = 0;

	// init custom window
	glutInit(&argc, NULL);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(960, 640);
	glutCreateWindow("Magical Engine");

	// bind call function
	glutReshapeFunc(magicalOnReshape);
	glutDisplayFunc(magicalOnRender);

	// setup gl context
	if( magicalSetupGL() == false )
	{
		MessageBoxA(NULL, magicalGetLastErrorInfo(), "", MB_OK);
		return;
	}

	s_director.setupSystems();

	// engine begin
	maigcalDirectorInit();
	maigcalDirectorSetupSystems();

	maigcalAssetsLoadTexture

	magicalDirectorGetWinSize();

	glutMainLoop();

	EngineDirector.

	// engine end
	maigcalDirectorShutdownSystems();
	maigcalDirectorDelc();

	// shutdown gl context
	magicalShutdownGL();
}

//MAGAPI void magicalApplicationInit( void )
//{
//	
//}
//
//MAGAPI void magicalApplicationDelc( void )
//{
//	
//}

MAGAPI int magicalSetupGL( void )
{
	GLenum result;

	result = glewInit();
	if( result != GLEW_OK )
	{
		magicalSetLastErrorInfo("[magical-error-win32]: glew init error");
		return false;
	}

	return true;
}

MAGAPI int magicalShutdownGL( void )
{
	return true;
}

MAGAPI void magicalOnReshape( int w, int h )
{

}

MAGAPI void magicalOnRender( void )
{


	glutSwapBuffers();
	glutPostRedisplay();
}
