#include <algorithm>
#include <iostream>
#include <vector>

namespace price
{
	int solve( )
	{
		int n = 0;
		std::cin >> n;

		std::vector<int> coins( n );
		for ( auto& coin : coins )
		{
			std::cin >> coin;
		}

		std::sort( std::begin( coins ), std::end( coins ) );

		int target = 1;

		for ( auto coin : coins )
		{
			if ( target >= coin )
			{
				target += coin;
			}
			else
			{
				break;
			}
		}

		return target;
	}
}