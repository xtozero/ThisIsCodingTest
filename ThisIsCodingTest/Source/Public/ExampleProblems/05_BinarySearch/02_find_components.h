#include <iostream>
#include <set>
#include <sstream>
#include <string>

namespace find_components
{
	std::string solve( )
	{
		int n = 0;
		std::cin >> n;

		std::cin.ignore( );

		std::string line;
		std::getline( std::cin, line );

		std::stringstream ss( line );

		std::set<int> stock;

		for ( int i = 0; i < n; ++i )
		{
			int number = 0;
			ss >> number;
			stock.emplace( number );
		}

		int m = 0;
		std::cin >> m;

		std::cin.ignore( );

		std::getline( std::cin, line );
		ss = std::stringstream( line );

		std::string result;
		for ( int i = 0; i < m; ++i )
		{
			int number = 0;
			ss >> number;
			if ( stock.find( number ) == std::end( stock ) )
			{
				result += "no ";
			}
			else
			{
				result += "yes ";
			}
		}

		return result;
	}
}