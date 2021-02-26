#include <algorithm>
#include <iostream>

namespace ant_warrior
{
	int dp[102] = {};
	int warehouse[102] = {};

	int solve1( )
	{
		int n = 0;
		std::cin >> n;

		for ( int i = 2; i < n + 2; ++i )
		{
			std::cin >> warehouse[i];
		}

		// bottom up
		for ( int i = 2; i < n + 2; ++i )
		{
			dp[i] = std::max( dp[i - 1], dp[i - 2] + warehouse[i] );
		}

		return dp[n + 1];
	}

	int topdown( int x )
	{
		if ( x < 0 )
		{
			return 0;
		}

		if ( dp[x] > -1 )
		{
			return dp[x];
		}

		int& ret = dp[x];

		ret = std::max( topdown( x - 1 ), topdown( x - 2 ) + warehouse[x] );

		return ret;
	}

	int solve2( )
	{
		int n = 0;
		std::cin >> n;

		for ( int i = 0; i < n; ++i )
		{
			std::cin >> warehouse[i];
			dp[i] = -1;
		}

		return topdown( n - 1 );
	}
}