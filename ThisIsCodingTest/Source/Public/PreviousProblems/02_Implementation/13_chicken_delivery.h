#include <algorithm>
#include <iostream>

namespace chicken_delivery
{
	const int INF = 1e8;

	int dfs( const std::vector<std::pair<int, int>>& chicken, std::vector<std::pair<int, int>>& house, int choice, int remain, int idx )
	{
		if ( remain <= 0 )
		{
			int chickenDist = 0;
			for ( const auto& h : house )
			{
				int minDist = INF;

				for ( int i = 0; i < chicken.size( ); ++i )
				{
					if ( choice & ( 1 << i ) )
					{
						minDist = std::min( minDist, std::abs( h.first - chicken[i].first ) + std::abs( h.second - chicken[i].second ) );
					}
				}

				chickenDist += minDist;
			}

			return chickenDist;
		}

		if ( chicken.size( ) <= idx )
		{
			return INF;
		}

		int left = dfs( chicken, house, ( choice | ( 1 << idx ) ), remain - 1, idx + 1 );
		int right = dfs( chicken, house, choice, remain, idx + 1 );

		return std::min( left, right );
	}

	int solve( )
	{
		int n = 0;
		int m = 0;
		std::cin >> n >> m;

		std::vector<std::pair<int, int>> house;
		std::vector<std::pair<int, int>> chicken;

		for ( int y = 0; y < n; ++y )
		{
			for ( int x = 0; x < n; ++x )
			{
				int v;
				std::cin >> v;

				if ( v == 1 )
				{
					house.emplace_back( x, y );
				}
				else if ( v == 2 )
				{
					chicken.emplace_back( x, y );
				}
			}
		}

		return dfs( chicken, house, 0, m, 0 );
	}
}