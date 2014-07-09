#ifndef __SYNTAX_TREE_H__
#define __SYNTAX_TREE_H__

#include <vector>
#include <string>
#include <unordered_map>
#include "rapidxml.hpp"

extern const char* const kName;
extern const char* const kType;
extern const char* const kOp;
extern const char* const kReturn;
extern const char* const kClass;
extern const char* const kGlobal;
extern const char* const kVariable;
extern const char* const kFunction;
extern const char* const kInclude;
extern const char* const kHead;
extern const char* const kXml;
extern const char* const kPath;
extern const char* const kRoot;
extern const char* const kTypedef;
extern const char* const kExtend;

struct syntax_xml
{
	std::string path;
};

struct syntax_include
{
	std::string head;
};

struct syntax_typedef
{
	std::string name;
	std::string type;
};

struct syntax_variable
{
	std::string name;
	std::string type;
	std::string op;
};

struct syntax_param
{
	std::string name;
	std::string type;
};

struct syntax_function
{
	std::string name;
	std::string return_type;
	std::string type;
	std::vector<syntax_param> param_list;
};

struct syntax_operator
{
	std::string op;
	std::string return_type;
	std::vector<syntax_param> param_list;
};

struct syntax_global
{
	std::vector<syntax_variable> variable_list;
	std::vector<syntax_function> function_list;
};

struct syntax_class
{
	std::string name;
	std::string type;
	std::string extend;
	std::vector<syntax_variable> variable_list;
	std::vector<syntax_function> function_list;
	std::vector<syntax_operator> operator_list;
};

struct syntax_tree
{
	std::vector<syntax_xml> xml_list;
	std::vector<syntax_include> include_list;
	std::vector<syntax_typedef> typedef_list;
	std::vector<syntax_global> global_list;
	std::vector<syntax_class> class_list;
};

extern bool syntaxTreeParse( std::unordered_map<std::string, std::string> params );
extern bool syntaxTreeFile( const char* path );
extern bool syntaxTreeStart( rapidxml::xml_node<char>* node );

extern bool handleRoot( rapidxml::xml_node<char>* node );
extern bool handleXml( rapidxml::xml_node<char>* node, syntax_xml& xml );
extern bool handleInclude( rapidxml::xml_node<char>* node, syntax_include& include_ );
extern bool handleTypedef( rapidxml::xml_node<char>* node, syntax_typedef& typedef_ );

extern bool handleGlobal( rapidxml::xml_node<char>* node, syntax_global& global );
extern bool handleVariable( rapidxml::xml_node<char>* node, syntax_variable& variable );
extern bool handleFunction( rapidxml::xml_node<char>* node, syntax_function& function );
extern bool handleParam( rapidxml::xml_node<char>* node, syntax_param& param );

extern bool handleClass( rapidxml::xml_node<char>* node, syntax_class& class_ );
extern bool handleOperator( rapidxml::xml_node<char>* node, syntax_operator& operator_ );


#endif //__SYNTAX_TREE_H__