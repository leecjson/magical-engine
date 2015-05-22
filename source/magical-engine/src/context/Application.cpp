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
#include "Log.h"
#include "Assets.h"
#include "Input.h"
//#include "LuaSystem.h"
#include "Renderer.h"

NAMESPACE_MAGICAL

void Application::init( void )
{
	//magicalStartObjectsListener( kEngineObjectsListener );

	Log::init();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	Assets::init();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	Input::init();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	/*Lua::init();
	magicalShowLastError();
	magicalReturnIfError();*/

	initWindow();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	initRenderContext();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	Engine::init();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	Renderer::init();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	/*std::string msg;
	msg += "<init>\n";

#ifdef MAGICAL_DEBUG
	msg += "  [debug model]: true\n";
#else
	msg += "  [debug model]: false\n";
#endif

	msg += "<init>\n";
	magicalLog( msg.c_str() );*/
}

void Application::delc( void )
{
	Renderer::delc();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	Engine::delc();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	delcRenderContext();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	delcWindow();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	/*Lua::delc();
	magicalShowLastError();
	magicalReturnIfError();*/

	Input::delc();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	Assets::delc();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();

	//std::stringstream ss;
	//ss << "C: " << magicalGetObjectsConstructCount( kEngineObjectsListener ) << "  ";
	//ss << "D: " << magicalGetObjectsDestructCount( kEngineObjectsListener ) << "\n";
	//magicalLog( ss.str().c_str() );

	//magicalEndObjectsListener( kEngineObjectsListener );

	Log::delc();
	MAGICAL_SHOW_LAST_ERROR();
	MAGICAL_RETURN_IF_ERROR();
}

NAMESPACE_END