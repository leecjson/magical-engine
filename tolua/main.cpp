#include "SyntaxTree.h"
#include <unordered_map>

int main( int argc, char* argv[] )
{
	if( argc == 0 || argc < 7 )
	{
		printf("Invalidate parameter! \n");
		return 0;
	}

	std::vector<std::string> param_array;
	for( int i = 1; i < argc; ++ i )
	{
		param_array.push_back( argv[i] );
	}

	std::unordered_map<std::string, std::string> params;
	for( int i = 0; i < argc - 1; i += 2 )
	{
		params.insert( std::pair<std::string, std::string>(param_array[i], param_array[i + 1]) );
	}

	syntaxTreeParse( params );
	system("pause");
	return 0;
}