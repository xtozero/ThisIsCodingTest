#include <algorithm>
#include <iostream>

namespace money
{
	int INF = 200000;
	int dp[100001] = {};

	int solve1( )
	{
		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		std::vector<int> coins( n );
		for ( auto& coin : coins )
		{
			std::cin >> coin;
		}

		for ( auto& v : dp )
		{
			v = INF;
		}
		dp[0] = 0;

		for ( int i = 1; i <= m; ++i )
		{
			for ( auto coin : coins )
			{
				if ( i >= coin )
				{
					dp[i] = std::min( dp[i], dp[i - coin] + 1 );
				}
			}
		}

		return ( dp[m] == INF ) ? -1 : dp[m];
	}

	int topdown( const std::vector<int>& coins, int x )
	{
		if ( x <= 0 )
		{
			return 0;
		}

		if ( dp[x] != INF )
		{
			return dp[x];
		}

		int& count = dp[x];

		for ( int coin : coins )
		{
			if ( x >= coin )
			{
				count = std::min( count, topdown( coins, x - coin ) + 1 );
			}
		}

		return count;
	}

	int solve2( )
	{
		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		std::vector<int> coins( n );
		for ( auto& coin : coins )
		{
			std::cin >> coin;
		}

		for ( auto& v : dp )
		{
			v = INF;
		}

		int result = topdown( coins, m );

		return ( result == INF ) ? -1 : result;
	}
}