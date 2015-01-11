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
#include "Main.h"
#include "magical-engine.h"

void mainDelegate( void )
{
	LuaState& L = Lua::sharedLuaState();

	//L["_G"] = 5;

	if( L.runScriptFile( "main.lua" ) == LuaCode::OK )
	{
		magicalLuaStateDump( L.cPointer() );

		lua_getglobal( L.cPointer(), "onCreate" );
		lua_pcall( L.cPointer(), 0, 0, 0 );

		/*L["onCreate"]();*/

		/*LuaFunction onCreate = L( "onCreate" );
		onCreate( x, y, z );*/

		//L >> "A";
		//L["go"]();

		//std::string str = L["onCreate"][3]( "haha", 333 ).returnString();
		//int abc = L.returnInt();
		//double bbb = L.returnDouble();
		//magicalDebugLog( str.c_str() );

		magicalLuaStateDump( L.cPointer() );
	}

	//L.clean();
}