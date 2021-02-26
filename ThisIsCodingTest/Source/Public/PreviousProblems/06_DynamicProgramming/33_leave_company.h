#include <iostream>

namespace leave_company
{
	int topDown( const int( &t )[16], const int( &p )[16], int( &dp )[16], int i, int n )
	{
		if ( i > n )
		{
			return 0;
		}

		if ( dp[i] > 0 )
		{
			return dp[i];
		}

		int& ret = dp[i];

		if ( i + t[i] <= n + 1 )
		{
			ret = std::max( ret, topDown( t, p, dp, i + t[i], n ) + p[i] );
		}
		ret = std::max( ret, topDown( t, p, dp, i + 1, n ) );

		return ret;
	}

	int solve( )
	{
		int n = 0;
		std::cin >> n;

		int t[16] = {};
		int p[16] = {};

		for ( int i = 1; i <= n; ++i )
		{
			std::cin >> t[i] >> p[i];
		}

		int dp[16] = {};
		return topDown( t, p, dp, 1, n );
	}
}