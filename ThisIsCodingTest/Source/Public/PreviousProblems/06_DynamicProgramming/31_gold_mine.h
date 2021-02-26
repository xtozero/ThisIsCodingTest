#include <algorithm>
#include <iostream>

namespace gold_mine
{
	std::string solve( )
	{
		std::string result;

		int t = 0;
		std::cin >> t;

		while ( t-- > 0 )
		{
			int n = 0;
			int m = 0;
			std::cin >> n >> m;

			int grid[22][22] = {};
			for ( int j = 1; j <= n; ++j )
			{
				for ( int i = 1; i <= m; ++i )
				{
					std::cin >> grid[j][i];
				}
			}

			int dp[22][22] = {};
			for ( int j = 1; j <= n; ++j )
			{
				dp[j][1] = grid[j][1];
			}

			for ( int i = 2; i <= m; ++i )
			{
				for ( int j = 1; j <= n; ++j )
				{
					dp[j][i] = grid[j][i] + std::max( dp[j - 1][i - 1], std::max( dp[j][i - 1], dp[j + 1][i - 1] ) );
				}
			}

			int maxGold = 0;

			for ( int j = 1; j <= n; ++j )
			{
				maxGold = std::max( maxGold, dp[j][m] );
			}

			result += std::to_string( maxGold ) + '\n';
		}

		result.pop_back( );
		return result;
	}
}