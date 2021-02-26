#include <algorithm>
#include <iostream>
#include <string>

namespace multiply_or_add
{
	int solve( )
	{
		std::string s;
		std::cin >> s;

		auto maximize = []( int a, int b )
		{
			if ( a > b )
			{
				std::swap( a, b );
			}

			if ( a <= 1 )
			{
				return a + b;
			}
			else
			{
				return a * b;
			}
		};

		int result = 0;
		for ( auto c : s )
		{
			result = maximize( result, c - '0' );
		}

		return result;
	}
}