#include <algorithm>
#include <queue>
#include <iostream>
#include <utility>
#include <vector>

namespace accurate_ranking
{
	int solve( )
	{
		constexpr int INF = 1e9;

		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		int node[501][501] = {};

		for ( int j = 0; j < 501; ++j )
		{
			for ( int i = 0; i < 501; ++i )
			{
				node[j][i] = ( i == j ) ? 0 : INF;
			}
		}

		for ( int i = 0; i < m; ++i )
		{
			int a = 0;
			int b = 0;

			std::cin >> a >> b;

			node[a][b] = 1;
		}

		for ( int k = 1; k <= n; ++k )
		{
			for ( int j = 1; j <= n; ++j )
			{
				for ( int i = 1; i <= n; ++i )
				{
					node[j][i] = std::min( node[j][i], node[j][k] + node[k][i] );
				}
			}
		}

		int result = 0;
		for ( int i = 1; i <= n; ++i )
		{
			int count = 0;
			for ( int j = 1; j <= n; ++j )
			{
				if ( ( node[i][j] != INF ) || ( node[j][i] != INF ) )
				{
					++count;
				}
			}

			if ( count == n )
			{
				++result;
			}
		}

		return result;
	}
}