#include "SyntaxTree.h"
#include "Utils.h"
#include "rapidxml.hpp"
#include "Output.h"

const char* const kName = "name";
const char* const kType = "type";
const char* const kOp = "op";
const char* const kReturn = "return";
const char* const kClass = "class";
const char* const kGlobal = "global";
const char* const kVariable = "variable";
const char* const kFunction = "function";
const char* const kInclude = "include";
const char* const kHead = "head";
const char* const kXml = "xml";
const char* const kPath = "path";
const char* const kRoot = "magical-binding";
const char* const kTypedef = "typedef";
const char* const kOperator = "operator";
const char* const kExtend = "extend";

static syntax_tree s_syntax_tree;

bool syntaxTreeParse( std::unordered_map<std::string, std::string> params )
{
	std::string module_name;
	std::string src_xml;
	std::string out_dir;

	auto itr = params.find("-s");
	if( itr == params.end() )
	{
		printf("Invalidate parameter! -s not exist \n");
		return false;
	}
	src_xml = itr->second;

	itr = params.find("-o");
	if( itr == params.end() )
	{
		printf("Invalidate parameter! -o not exist \n");
		return false;
	}
	out_dir = itr->second;

	itr = params.find("-m");
	if( itr == params.end() )
	{
		printf("Invalidate parameter! -m not exist \n");
		return false;
	}
	module_name = itr->second;

	if( Utils::isFileExist(src_xml.c_str()) == false )
	{
		printf( "%s\n", "file does not exist!" );
		return false;
	}

	if( syntaxTreeFile( src_xml.c_str() ) == false )
		return false;

	Output output;
	output.out( s_syntax_tree, out_dir.c_str(), module_name.c_str() );

	return true;
}

bool syntaxTreeFile( const char* path )
{
	char* data = nullptr;
	data = Utils::getFileData( path );

	if( data == nullptr )
		return false;

	rapidxml::xml_document<char> doc;
	doc.parse<0>(data);

	rapidxml::xml_node<char>* root = doc.first_node(kRoot);
	if( root == nullptr )
	{
		printf("<magical-binding> not exist\n");
		return false;
	}

	if( syntaxTreeStart( root ) == false )
		return false;

	free( data );
	return true;
}

bool syntaxTreeStart( rapidxml::xml_node<char>* node )
{
	// root
	if( strcmp( node->name(), kRoot ) == 0 )
	{
		if( !handleRoot( node ) )
			return false;
	}
	// xml
	else if( strcmp( node->name(), kXml ) == 0 )
	{
		syntax_xml xml;

		if( !handleXml( node, xml ) )
			return false;

		s_syntax_tree.xml_list.push_back( xml );

		if( !syntaxTreeFile( xml.path.c_str() ) )
			return false;
	}
	// include
	else if( strcmp( node->name(), kInclude ) == 0 )
	{
		syntax_include include_;

		if( !handleInclude( node, include_ ) )
			return false;

		s_syntax_tree.include_list.push_back( include_ );
	}
	// typedef
	else if( strcmp( node->name(), kTypedef ) == 0 )
	{
		syntax_typedef typedef_;

		if( !handleTypedef( node, typedef_ ) )
			return false;

		s_syntax_tree.typedef_list.push_back( typedef_ );
	}
	// global
	else if( strcmp( node->name(), kGlobal ) == 0 )
	{
		syntax_global global;

		if( !handleGlobal( node, global ) )
			return false;

		s_syntax_tree.global_list.push_back( global );
	}
	// class
	else if( strcmp( node->name(), kClass ) == 0 )
	{
		syntax_class class_;

		if( !handleClass( node, class_ ) )
			return false;

		s_syntax_tree.class_list.push_back( class_ );
	}

	return true;
}

bool handleRoot( rapidxml::xml_node<char>* node )
{
	auto* child = node->first_node();
	for(; child != nullptr; child = child->next_sibling() )
	{
		if( syntaxTreeStart( child ) == false )
			return false;
	}
	return true;
}

bool handleXml( rapidxml::xml_node<char>* node, syntax_xml& xml )
{
	auto* attr = node->first_attribute();
	for(; attr != nullptr; attr = attr->next_attribute() )
	{
		if( strcmp( attr->name(), kPath ) == 0 )
		{
			xml.path = attr->value();
		}
	}
	return true;
}

bool handleInclude( rapidxml::xml_node<char>* node, syntax_include& include_ )
{
	auto* attr = node->first_attribute();
	for(; attr != nullptr; attr = attr->next_attribute() )
	{
		if( strcmp( attr->name(), kHead ) == 0 )
		{
			include_.head = attr->value();
		}
	}
	return true;
}

bool handleTypedef( rapidxml::xml_node<char>* node, syntax_typedef& typedef_ )
{
	auto* attr = node->first_attribute();
	for(; attr != nullptr; attr = attr->next_attribute() )
	{
		if( strcmp( attr->name(), kType ) == 0 )
		{
			typedef_.type = attr->value();
		}
		else if( strcmp( attr->name(), kName ) == 0 )
		{
			typedef_.name = attr->value();
		}
	}
	return true;
}

bool handleGlobal( rapidxml::xml_node<char>* node, syntax_global& global )
{
	auto* child = node->first_node();
	for(; child != nullptr; child = child->next_sibling() )
	{
		// global variable
		if( strcmp( child->name(), kVariable ) == 0 )
		{
			syntax_variable variable;

			if( !handleVariable( child, variable ) )
				return false;

			global.variable_list.push_back( variable );
		}
		// global function
		else if( strcmp( child->name(), kFunction ) == 0 )
		{
			syntax_function function;

			if( !handleFunction( child, function ) )
				return false;

			global.function_list.push_back( function );
		}
	}

	return true;
}

bool handleVariable( rapidxml::xml_node<char>* node, syntax_variable& variable )
{
	auto* attr = node->first_attribute();
	for(; attr != nullptr; attr = attr->next_attribute() )
	{
		if( strcmp( attr->name(), kType ) == 0 )
		{
			variable.type = attr->value();
		}
		else if( strcmp( attr->name(), kName ) == 0 )
		{
			variable.name = attr->value();
		}
		else if( strcmp( attr->name(), kOp ) == 0 )
		{
			variable.op = attr->value();
		}
	}
	return true;
}

bool handleFunction( rapidxml::xml_node<char>* node, syntax_function& function )
{
	auto* attr = node->first_attribute();
	for(; attr != nullptr; attr = attr->next_attribute() )
	{
		if( strcmp( attr->name(), kName ) == 0 )
		{
			function.name = attr->value();
		}
		else if( strcmp( attr->name(), kType ) == 0 )
		{
			function.type = attr->value();
		}
		else if( strcmp( attr->name(), kReturn ) == 0 )
		{
			function.return_type = attr->value();
		}
	}

	auto* child = node->first_node();
	if( child != nullptr )
	{
		for(; child != nullptr; child = child->next_sibling() )
		{
			syntax_param param;

			if( !handleParam( child, param) )
				return false;

			function.param_list.push_back( param );
		}
	}

	return true;
}

bool handleParam( rapidxml::xml_node<char>* node, syntax_param& param )
{
	auto* attr = node->first_attribute();
	for(; attr != nullptr; attr = attr->next_attribute() )
	{
		if( strcmp( attr->name(), kType ) == 0 )
		{
			param.type = attr->value();
		}
	}

	if( node->value_size() == 0 )
	{
		printf("param name size < 0");
		return false;
	}

	param.name = node->value();
	return true;
}

bool handleClass( rapidxml::xml_node<char>* node, syntax_class& class_ )
{
	auto* attr = node->first_attribute();
	for(; attr != nullptr; attr = attr->next_attribute() )
	{
		if( strcmp( attr->name(), kName ) == 0 )
		{
			class_.name = attr->value();
		}
		else if( strcmp( attr->name(), kType ) == 0 )
		{
			class_.type = attr->value();
		}
		else if( strcmp( attr->name(), kExtend ) == 0 )
		{
			class_.extend = attr->value();
		}
	}

	auto* child = node->first_node();
	for(; child != nullptr; child = child->next_sibling() )
	{
		// class variable
		if( strcmp( child->name(), kVariable ) == 0 )
		{
			syntax_variable variable;

			if( !handleVariable( child, variable ) )
				return false;

			class_.variable_list.push_back( variable );
		}
		// class function
		else if( strcmp( child->name(), kFunction ) == 0 )
		{
			syntax_function function;

			if( !handleFunction( child, function ) )
				return false;

			class_.function_list.push_back( function );
		}
		// class operator
		else if( strcmp( child->name(), kFunction ) == 0 )
		{
			syntax_operator operator_;

			if( !handleOperator( child, operator_ ) )
				return false;

			class_.operator_list.push_back( operator_ );
		}
	}
	return true;
}

bool handleOperator( rapidxml::xml_node<char>* node, syntax_operator& operator_ )
{
	auto* attr = node->first_attribute();
	for(; attr != nullptr; attr = attr->next_attribute() )
	{
		if( strcmp( attr->name(), kOp ) == 0 )
		{
			operator_.op = attr->value();
		}
		else if( strcmp( attr->name(), kReturn ) == 0 )
		{
			operator_.return_type = attr->value();
		}
	}

	auto* child = node->first_node();
	if( child != nullptr )
	{
		for(; child != nullptr; child = child->next_sibling() )
		{
			syntax_param param;

			if( !handleParam( child, param) )
				return false;

			operator_.param_list.push_back( param );
		}
	}

	return true;
}