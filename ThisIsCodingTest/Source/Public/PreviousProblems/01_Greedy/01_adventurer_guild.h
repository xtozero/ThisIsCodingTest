#include <algorithm>
#include <iostream>
#include <vector>

namespace adventurer_guild
{
	int solve( )
	{
		int n = 0;
		std::cin >> n;

		std::vector<int> adventurers( n );
		for ( auto& adventurer : adventurers )
		{
			std::cin >> adventurer;
		}

		std::sort( std::begin( adventurers ), std::end( adventurers ) );

		int curCount = 0;
		int totalGroup = 0;
		for ( auto& adventurer : adventurers )
		{
			++curCount;

			if ( curCount >= adventurer )
			{
				curCount = 0;
				++totalGroup;
			}
		}

		return totalGroup;
	}
}