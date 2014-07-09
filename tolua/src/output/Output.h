#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include "SyntaxTree.h"

class Output
{
public:
	void out( const syntax_tree& tree, const char* out_dir, const char* module_name );
	void writeHeader( void );
	void writeRegistType( void );
	void write( void );

private:

	
private:
	std::string _module_name;
	std::string _out_dir;
	std::string _out_str;
	syntax_tree _syntax_tree;
};

#endif //__OUTPUT_H__