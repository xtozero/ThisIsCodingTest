#include <algorithm>
#include <iostream>

namespace floyd
{
	std::string solve( )
	{
		int n = 0;
		int m = 0;
		std::cin >> n >> m;

		constexpr long long INF = 1e12;
		long long city[101][101] = {};

		for ( int j = 1; j <= n; ++j )
		{
			for ( int i = 1; i <= n; ++i )
			{
				city[j][i] = ( i == j ) ? 0 : INF;
			}
		}

		for ( int i = 0; i < m; ++i )
		{
			int a = 0;
			int b = 0;
			long long c = 0;

			std::cin >> a >> b >> c;
			city[a][b] = std::min( city[a][b], c );
		}

		for ( int k = 1; k <= n; ++k )
		{
			for ( int j = 1; j <= n; ++j )
			{
				for ( int i = 1; i <= n; ++i )
				{
					city[j][i] = std::min( city[j][i], city[j][k] + city[k][i] );
				}
			}
		}

		for ( int j = 1; j <= n; ++j )
		{
			for ( int i = 1; i <= n; ++i )
			{
				if ( city[j][i] == INF )
				{
					city[j][i] = 0;
				}
			}
		}

		std::string result;

		for ( int j = 1; j <= n; ++j )
		{
			for ( int i = 1; i <= n; ++i )
			{
				result += ( i != 1 ) ? " " + std::to_string( city[j][i] ) : std::to_string( city[j][i] );
			}
			result += "\n";
		}

		result.pop_back( );
		return result;
	}
}