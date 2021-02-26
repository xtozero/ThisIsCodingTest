#include <algorithm>
#include <iostream>

namespace make_one
{
	int dp[30001] = {};
	int solve1( )
	{
		int x = 0;
		std::cin >> x;

		for ( int i = 2; i <= x; ++i )
		{
			dp[i] = dp[i - 1] + 1;

			if ( ( i % 5 ) == 0 )
			{
				dp[i] = std::min( dp[i], dp[i / 5] + 1 );
			}

			if ( ( i % 3 ) == 0 )
			{
				dp[i] = std::min( dp[i], dp[i / 3] + 1 );
			}

			if ( ( i % 2 ) == 0 )
			{
				dp[i] = std::min( dp[i], dp[i / 2] + 1 );
			}
		}

		return dp[x];
	}

	constexpr int INF = 40000;
	int topdown( int x )
	{
		if ( x == 1 )
		{
			return 0;
		}

		if ( dp[x] != INF )
		{
			return dp[x];
		}

		int& count = dp[x];
		if ( ( x % 5 ) == 0 )
		{
			count = std::min( count, topdown( x / 5 ) + 1 );
		}

		if ( ( x % 3 ) == 0 )
		{
			count = std::min( count, topdown( x / 3 ) + 1 );
		}

		if ( ( x % 2 ) == 0 )
		{
			count = std::min( count, topdown( x / 2 ) + 1 );
		}

		count = std::min( count, topdown( x - 1 ) + 1 );

		return count;
	}

	int solve2( )
	{
		int x = 0;
		std::cin >> x;

		for ( auto& v : dp )
		{
			v = INF;
		}

		return topdown( x );
	}
}