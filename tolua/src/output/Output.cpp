#include "Output.h"
#include "Utils.h"

static char _buff[1024 * 50];

void Output::out( const syntax_tree& tree, const char* out_dir, const char* name )
{
	_module_name = name;
	_out_dir = out_dir;
	_syntax_tree = tree;

	writeHeader();
	writeRegistType();
	write();
}

void Output::writeHeader( void )
{
	_out_str += "/*\n";
	_out_str += "* Lua binding: ";
	_out_str += _module_name + ".\n";
	_out_str += "* Generated automatically by magical-lua-binding.\n";
	_out_str += "*/\n\n";

	_out_str += 
"#ifndef __cplusplus\n\
#include \"stdlib.h\"\n\
#endif\n\
#include \"string.h\"\n\
\n\
#include \"PlatformMacros.h\"\n\
#include \"tolua++.h\"\n\
#include \"tolua_ext.h\"\n";
	_out_str += "\n";

	sprintf( _buff, 
"MAGAPI int luaopen_%s( lua_State* L );\n",
_module_name.c_str(), _module_name.c_str() );

	_out_str += _buff;
	_out_str += "\n";
}

void Output::writeRegistType( void )
{
	_out_str += 
"static void tolua_reg_types( lua_State* L )\n\
{\n";
	//begin
	for( const auto& class_ : _syntax_tree.class_list )
	{
		if( class_.type != "static" )
		{
			_out_str += "    tolua_usertype( L, \"";
			_out_str += class_.name;
			_out_str += "\" );\n";
		}
	}
	//end
	_out_str +=
"}\n";
	_out_str += "\n";
}

void Output::write( void )
{
	std::string path;
	if( Utils::isAbsolutePath(_out_dir.c_str()) )
	{
		path = _out_dir;
	}
	else
	{
		path = Utils::getDefaultSearchPath() + _out_dir;
	}

	FILE* fp = fopen( path.c_str(), "wb+" );
	if( fp == nullptr )
	{
		printf( "open file (%s) failed", path.c_str() );
		return;
	}

	fputs( _out_str.c_str(), fp );
	fflush( fp );
	fclose( fp );
}