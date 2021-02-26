#include <algorithm>
#include <iostream>

namespace integer_triangle
{
	int solve( )
	{
		int n = 0;
		std::cin >> n;

		int grid[501][501] = {};
		for ( int j = 1; j <= n; ++j )
		{
			for ( int i = 1; i <= j; ++i )
			{
				std::cin >> grid[j][i];
				grid[j][i] += std::max( grid[j - 1][i - 1], grid[j - 1][i] );
			}
		}

		auto iter = std::max_element( std::begin( grid[n] ), std::end( grid[n] ) );
		return *iter;
	}

	// 다른 풀이 1차원 배열로 해결
	int solve2( )
	{
		int n = 0;
		std::cin >> n;

		int grid[501] = {};
		for ( int j = 1; j <= n; ++j )
		{
			for ( int i = j; i >= 1; --i )
			{
				int val = 0;
				std::cin >> val;
				grid[i] = val + std::max( grid[i], grid[i - 1] );
			}
		}

		auto iter = std::max_element( std::begin( grid ), std::end( grid ) );
		return *iter;
	}
}