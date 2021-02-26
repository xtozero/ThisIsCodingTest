#include <iostream>
#include <string>

namespace lucky_straight
{
	std::string solve( )
	{
		std::string s;
		std::cin >> s;

		int mid = s.size( ) / 2;
		int leftScore = 0;
		for ( int i = 0; i < mid; ++i )
		{
			leftScore += s[i] - '0';
		}

		int rightScore = 0;
		for ( int i = mid; i < s.size( ); ++i )
		{
			rightScore += s[i] - '0';
		}

		return ( leftScore == rightScore ) ? "LUCKY" : "READY";
	}
}