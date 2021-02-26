#include <iostream>

namespace tile
{
	int dp[1000] = {};

	int solve1( )
	{
		int n = 0;
		std::cin >> n;

		// botoom up
		dp[0] = 1;
		dp[1] = 3;
		for ( int i = 2; i < n; ++i )
		{
			dp[i] = ( dp[i - 1] + dp[i - 2] * 2 ) % 796796;
		}

		return dp[n - 1];
	}

	int topdown( int x )
	{
		if ( x < 0 )
		{
			return 0;
		}

		if ( x == 0 )
		{
			return 1;
		}

		if ( x == 1 )
		{
			return 3;
		}

		if ( dp[x] > 0 )
		{
			return dp[x];
		}

		int& count = dp[x];

		count = ( topdown( x - 2 ) * 2 + topdown( x - 1 ) ) % 796796;

		return count;
	}

	int solve2( )
	{
		int n = 0;
		std::cin >> n;

		for ( auto& i : dp )
		{
			i = -1;
		}
		
		return topdown(n - 1);
	}
}