#include <algorithm>
#include <iostream>
#include <vector>

namespace deploying_soldiers
{
	int solve( )
	{
		int n = 0;
		std::cin >> n;

		int soldiers[2000] = {};
		for ( int i = 0; i < n; ++i )
		{
			std::cin >> soldiers[i];
		}

		int dp[2000] = {};
		std::fill( std::begin( dp ), std::end( dp ), 1 );
		for ( int i = 1; i < n; ++i )
		{
			for ( int j = 0; j < i; ++j )
			{
				if ( soldiers[j] > soldiers[i] )
				{
					dp[i] = std::max( dp[i], dp[j] + 1 );
				}
			}
		}

		int deploy = *std::max_element( std::begin( dp ), std::end( dp ) );

		return n - deploy;
	}
}