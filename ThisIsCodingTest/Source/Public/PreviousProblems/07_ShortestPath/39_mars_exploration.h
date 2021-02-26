#include <iostream>
#include <queue>
#include <string>
#include <utility>

namespace mars_exploration
{
	std::string solve( )
	{
		std::string result;

		int t = 0;
		std::cin >> t;

		while ( t-- )
		{
			int n = 0;
			std::cin >> n;

			int space[127][127];
			
			for ( int i = 0, end = n + 1; i <= end; ++i )
			{
				space[i][0] = -1;
				space[i][end] = -1;
			}

			for ( int i = 0, end = n + 1; i <= end; ++i )
			{
				space[0][i] = -1;
				space[end][i] = -1;
			}

			for ( int j = 1; j <= n; ++j )
			{
				for ( int i = 1; i <= n; ++i )
				{
					std::cin >> space[j][i];
				}
			}

			using Coord = std::pair<int, int>;
			auto cmp = []( const std::pair<Coord, int>& lhs, const std::pair<Coord, int>& rhs )
			{
				return lhs.second > rhs.second;
			};

			std::priority_queue<std::pair<Coord, int>, std::vector<std::pair<Coord, int>>, decltype( cmp )> q( cmp );

			int distance[127][127];
			for ( int j = 1; j <= n; ++j )
			{
				for ( int i = 1; i <= n; ++i )
				{
					distance[j][i] = 1e9;
				}
			}

			q.push( { {1, 1}, space[1][1] } );
			distance[1][1] = space[1][1];

			while ( q.empty( ) == false )
			{
				auto info = q.top( );
				q.pop( );

				const Coord& c = info.first;
				int x = c.first;
				int y = c.second;
				int weight = info.second;

				if ( weight > distance[y][x] )
				{
					continue;
				}

				int dx[] = { 0, 1, 0, -1 };
				int dy[] = { 1, 0, -1, 0 };

				for ( int i = 0; i < 4; ++i )
				{
					int nextX = x + dx[i];
					int nextY = y + dy[i];
					if ( space[nextY][nextX] < 0 )
					{
						continue;
					}

					int nextWeight = weight + space[nextY][nextX];

					if ( nextWeight < distance[nextY][nextX] )
					{
						q.push( { { nextX, nextY }, nextWeight } );
						distance[nextY][nextX] = nextWeight;
					}
				}
			}

			result += std::to_string( distance[n][n] ) + "\n";
		}

		result.pop_back( );
		return result;
	}
}