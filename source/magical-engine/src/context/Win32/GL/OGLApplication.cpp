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
#include "Director.h"
#include "Input.h"

#include <windows.h>
#include "win32/gl/glew/glew.h"
#include "win32/gl/glfw3/glfw3.h"

NAMESPACE_MAGICAL

static GLFWwindow* _window = nullptr;
static LARGE_INTEGER _interval_win32;
static double _interval;
static bool _window_resizable = true;
static Size _window_size = Size::Zero;
static std::string _window_title = "magical-engine";

static void win32ErrorCallBack( int err_id, const char* error_desc );
static void win32MouseButtonCallBack( GLFWwindow* window, int button, int action, int modify );
static void win32MouseMoveCallBack( GLFWwindow* window, double x, double y );
static void win32MouseScrollCallBack( GLFWwindow* window, double x, double y );
static void win32CharCallBack( GLFWwindow* window, unsigned int character );
static void win32KeyCallBack( GLFWwindow* window, int key, int scancode, int action, int mods );
static void win32WindowPosCallBack( GLFWwindow* windows, int x, int y );
static void win32FrameBufferSizeCallBack( GLFWwindow* window, int w, int h );
static void win32WindowSizeCallBack( GLFWwindow* window, int w, int h );

void Application::run( MainDelegate maindelegate )
{
	maindelegate();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	LARGE_INTEGER freq;
    LARGE_INTEGER last;
    LARGE_INTEGER now;

	QueryPerformanceFrequency( &freq );
	QueryPerformanceCounter( &last );

	while( !glfwWindowShouldClose( _window ) )
	{
		QueryPerformanceCounter( &now );
		if( now.QuadPart - last.QuadPart > _interval_win32.QuadPart )
		{
			last.QuadPart = now.QuadPart;

			Director::mainLoop();
			glfwSwapBuffers( _window );

#ifdef MAGICAL_DEBUG
			MAGICAL_SHOW_LAST_ERROR();
			MAGICAL_RETURN_IF_ERROR();
#endif
			glfwPollEvents();
		}
		else
		{
			Sleep( 0 );
		}
	}
}

void Application::setInterval( double interval )
{
	LARGE_INTEGER freq;
	QueryPerformanceFrequency( &freq );
	_interval_win32.QuadPart = (LONGLONG)( interval * freq.QuadPart );

	_interval = interval;
}

double Application::getInterval( void )
{
	return _interval;
}

void Application::setResizable( bool resizable )
{
	_window_resizable = resizable;
	glfwWindowHint( GLFW_RESIZABLE, resizable );
}

bool Application::isResizable( void )
{
	return _window_resizable;
}

void Application::setWindowSize( int width, int height )
{
	_window_size.w = width;
	_window_size.h = height;
	glfwSetWindowSize( _window, _window_size.w, _window_size.h );
}

void Application::setWindowSize( const Size& size )
{
	_window_size = size;
	glfwSetWindowSize( _window, _window_size.w, _window_size.h );
}

const Size& Application::getWindowSize( void )
{
	return _window_size;
}

void Application::setWindowTitle( const char* title )
{
	_window_title = title;
	glfwSetWindowTitle( _window, title );
}

void Application::swapBuffers( void )
{
	glfwSwapBuffers( _window );
}

void Application::exit( void )
{
	glfwSetWindowShouldClose( _window, 1 );
}

void Application::initWindow( void )
{
	glfwSetErrorCallback( win32ErrorCallBack );
	glfwInit();
	MAGICAL_RETURN_IF_ERROR();

	setInterval( 1.0 / 60 );
	setResizable( true );
	glfwDefaultWindowHints();

	_window_size.w = 1280;
	_window_size.h = 760;

	_window = glfwCreateWindow( _window_size.w, _window_size.h, _window_title.c_str(), nullptr, nullptr );
	MAGICAL_RETURN_IF_ERROR();

	glfwMakeContextCurrent( _window );
	MAGICAL_RETURN_IF_ERROR();

	glfwSetMouseButtonCallback( _window, win32MouseButtonCallBack );
	glfwSetCursorPosCallback( _window, win32MouseMoveCallBack );
	glfwSetScrollCallback( _window, win32MouseScrollCallBack );
	glfwSetCharCallback( _window, win32CharCallBack );
	glfwSetKeyCallback( _window, win32KeyCallBack );
	glfwSetWindowPosCallback( _window, win32WindowPosCallBack );
	glfwSetFramebufferSizeCallback( _window, win32FrameBufferSizeCallBack );
	glfwSetWindowSizeCallback( _window, win32WindowSizeCallBack );

	//Director::resize( _window_size.w, _window_size.h );
}

void Application::delcWindow( void )
{
	glfwTerminate();
}

void Application::initRenderContext( void )
{
	const GLubyte* gl_version = glGetString( GL_VERSION );
	if( atof( (const char*) gl_version ) < 1.5 )
	{
		MAGICAL_SET_LAST_ERROR( System::format( "OpenGL 1.5 or higher is required (your version is %s). Please upgrade the driver of your video card.", gl_version ).c_str() );
		MAGICAL_LOG_LAST_ERROR();
		return;
	}

	GLenum result = glewInit();
	if( result != GLEW_OK )
	{
		MAGICAL_SET_LAST_ERROR( System::format( "%s %s", "Init glew failed.", (char*)glewGetErrorString( result ) ).c_str() );
		MAGICAL_LOG_LAST_ERROR();
		return;
	}

	if( GLEW_ARB_vertex_shader && GLEW_ARB_fragment_shader )
	{
		//log( "Ready for GLSL" );
	}
	else
	{
		//log( "Not totally ready :(" );
	}

	if( glewIsSupported( "GL_VERSION_2_0" ) )
	{
		//log("Ready for OpenGL 2.0");
	}
	else
	{
		//log("OpenGL 2.0 not supported");
	}
}

void Application::delcRenderContext( void )
{

}

static void win32ErrorCallBack( int err_id, const char* error_desc )
{
	MAGICAL_SET_LAST_ERROR( error_desc );
	MAGICAL_LOG_LAST_ERROR();

	//MAGICAL_LOGD( "win32ErrorCallBack" );
}

static void win32MouseButtonCallBack( GLFWwindow* window, int button, int action, int modify )
{
	Input::onMouseButtonEvent( button, action );

	//stringstream ss;
	//ss << "Button:" << button << "  Action:" << action << "  Modify:" << modify; 

	//MAGICAL_LOGD( ss.str().c_str() );
	//MAGICAL_LOGD( "win32MouseButtonCallBack" );
}

static void win32MouseMoveCallBack( GLFWwindow* window, double x, double y )
{
	Input::onMouseEvent( x, y );
	//MAGICAL_LOGD( "win32MouseMoveCallBack" );
}

static void win32MouseScrollCallBack( GLFWwindow* window, double x, double y )
{
	stringstream ss;
	ss << "Scroll: x=" << x << "  y=" << y;

	//MAGICAL_LOGD( ss.str().c_str() );
	//MAGICAL_LOGD( "win32MouseScrollCallBack" );
}

static void win32CharCallBack( GLFWwindow* window, unsigned int character )
{
	//MAGICAL_LOGD( "win32CharCallBack" );
}

static void win32KeyCallBack( GLFWwindow* window, int key, int scancode, int action, int mods )
{
	Input::onKeyEvent( (KeyCode) key, (KeyAction) action );
	//MAGICAL_LOGD( "win32KeyCallBack" );
}

static void win32WindowPosCallBack( GLFWwindow* windows, int x, int y )
{
	//MAGICAL_LOGD( "win32WindowPosCallBack" );
}

static void win32FrameBufferSizeCallBack( GLFWwindow* window, int w, int h )
{
	//MAGICAL_LOGD( "win32FrameBufferSizeCallBack" );
}

static void win32WindowSizeCallBack( GLFWwindow* window, int w, int h )
{
	if( !w || !h ) return;

	_window_size.w = w;
	_window_size.h = h;

	Director::resize( w, h );
	//MAGICAL_LOGD( "win32WindowSizeCallBack" );
}

NAMESPACE_END