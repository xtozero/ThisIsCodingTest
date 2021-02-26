#include <iostream>
#include <vector>

namespace bowling_ball
{
	int solve1( )
	{
		int n = 0;
		int m = 0;
		std::cin >> n >> m;

		std::vector<int> balls( n );

		for ( auto& ball : balls )
		{
			std::cin >> ball;
		}

		int count = 0;
		for ( int i = 0; i < n; ++i )
		{
			for ( int j = i + 1; j < n; ++j )
			{
				if ( balls[i] != balls[j] )
				{
					++count;
				}
			}
		}

		return count;
	}

	int solve2( )
	{
		int n = 0;
		int m = 0;
		std::cin >> n >> m;

		std::vector<int> balls( n );
		int ballCount[11] = {};

		for ( auto& ball : balls )
		{
			std::cin >> ball;
			++ballCount[ball];
		}

		int count = 0;
		for ( int i = 1; i <= m; ++i )
		{
			n -= ballCount[i];
			count += ballCount[i] * n;
		}

		return count;
	}
}