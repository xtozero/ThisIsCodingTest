#include <functional>
#include <iostream>
#include <queue>
#include <vector>

namespace ugly_numbers
{
	int solve1( )
	{
		int n = 0;
		std::cin >> n;

		std::priority_queue<int, std::vector<int>, std::greater<int>> q;
		q.push( 1 );
		int dp[1001] = {};

		for ( int i = 0; i < n; ++i )
		{
			while ( dp[i] == q.top( ) )
			{
				q.pop( );
			}

			int min = q.top( );
			q.pop( );

			dp[i + 1] = min;
			q.push( min * 2 );
			q.push( min * 3 );
			q.push( min * 5 );
		}

		return dp[n];
	}

	int solve2( )
	{
		int n = 0;
		std::cin >> n;

		int dp[1001] = {};
		dp[1] = 1;
		int mul2 = 2;
		int mul3 = 3;
		int mul5 = 5;

		int i2 = 1;
		int i3 = 1;
		int i5 = 1;

		for ( int i = 2; i <= n; ++i )
		{
			dp[i] = std::min( { mul2, mul3, mul5 } );

			if ( dp[i] == mul2 )
			{
				++i2;
				mul2 = dp[i2] * 2;
			}

			if ( dp[i] == mul3 )
			{
				++i3;
				mul3 = dp[i3] * 3;
			}

			if ( dp[i] == mul5 )
			{
				++i5;
				mul5 = dp[i5] * 5;
			}
		}

		return dp[n];
	}
}