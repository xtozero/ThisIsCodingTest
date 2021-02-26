#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

namespace uptodown
{
	std::string solve( )
	{
		int n = 0;
		std::cin >> n;

		std::vector<int> v( n );
		for ( auto& num : v )
		{
			std::cin >> num;
		}

		std::sort( std::begin( v ), std::end( v ), std::greater<int>() );

		std::string result;

		for ( std::size_t i = 0; i < v.size(); ++i )
		{
			result += std::to_string( v[i] );
			if ( ( i + 1 ) != v.size( ) )
			{
				result += " ";
			}
		}

		return result;
	}
}