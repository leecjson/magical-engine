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
#include "Engine.h"
#include "AssetsSystem.h"
#include "LuaSystem.h"
#include "RendererSystem.h"
#include "LogSystem.h"

void Application::init( void )
{
	initStart();

	Assets::init();
	magicalShowLastError();
	magicalReturnIfError();

	Lua::init();
	magicalShowLastError();
	magicalReturnIfError();

	initWindow();
	magicalShowLastError();
	magicalReturnIfError();

	initRenderContext();
	magicalShowLastError();
	magicalReturnIfError();

	Engine::init();
	magicalShowLastError();
	magicalReturnIfError();

	Renderer::init();
	magicalShowLastError();
	magicalReturnIfError();

	initEnded();
}

void Application::delc( void )
{
	delcStart();

	Renderer::delc();
	magicalShowLastError();
	magicalReturnIfError();

	Engine::delc();
	magicalShowLastError();
	magicalReturnIfError();

	delcRenderContext();
	magicalShowLastError();
	magicalReturnIfError();

	delcWindow();
	magicalShowLastError();
	magicalReturnIfError();

	Lua::delc();
	magicalShowLastError();
	magicalReturnIfError();

	Assets::delc();
	magicalShowLastError();
	magicalReturnIfError();

	delcEnded();
}

void Application::initStart( void )
{
	Log::init();
	magicalShowLastError();
	magicalReturnIfError();

#ifdef MAGICAL_DEBUG
	magicalStartObjectsListener( kEngineObjectsListener );
#endif
}

void Application::initEnded( void )
{
	std::string msg;
	msg += "<init>\n";

#ifdef MAGICAL_DEBUG
	msg += "  [debug model]: Yes\n";
#else
	msg += "  [debug model]: No\n";
#endif
	
#ifdef MAGICAL_DEBUG
	msg += "  [objects listener]: Yes\n";
#else
	msg += "  [objects listener]: No\n";
#endif

	msg += "<init>\n";
	magicalLog( msg.c_str() );
}

void Application::delcStart( void )
{

}

void Application::delcEnded( void )
{
	std::string msg;
	msg += "\n<delc>\n";

#ifdef MAGICAL_DEBUG
	int c = magicalGetObjectsConstructCount( kEngineObjectsListener );
	int d = magicalGetObjectsDestructCount( kEngineObjectsListener );
	magicalFormat( "  [objects listener]: construct = %d destruct = %d\n", c, d );
	msg += magicalBuffer;
#else
	msg += "  [objects listener]: No\n";
#endif

	msg += "<delc>\n";
	magicalLog( msg.c_str() );

	Log::delc();
	magicalShowLastError();
	magicalReturnIfError();
}

