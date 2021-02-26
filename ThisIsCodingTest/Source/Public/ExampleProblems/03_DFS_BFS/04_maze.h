#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

namespace maze
{
	template <typename T>
	using Grid = std::vector<std::vector<T>>;

	int ShortestPath( Grid<int>& maze, int x, int y, int length, int n, int m )
	{
		constexpr int maxPath = 50000; // 가장 큰 미로의 모든 칸 수보다 큰 수

		if ( ( x == m ) && ( y == n ) )
		{
			return length + 1;
		}

		if ( ( x < 0 ) || ( y < 0 ) || ( x > m ) || y > n )
		{
			return maxPath;
		}

		if ( maze[y][x] == 0 )
		{
			return maxPath;
		}

		int min = maxPath;
		maze[y][x] = 0;
		min = std::min( min, ShortestPath( maze, x + 1, y, length + 1, n, m ) );
		min = std::min( min, ShortestPath( maze, x, y + 1, length + 1, n, m ) );
		min = std::min( min, ShortestPath( maze, x - 1, y, length + 1, n, m ) );
		min = std::min( min, ShortestPath( maze, x, y - 1, length + 1, n, m ) );
		maze[y][x] = 1;

		return min;
	}

	int solve1( )
	{
		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		Grid<int> maze( 200 );
		for ( int i = 0; i < n; ++i )
		{
			maze[i].resize( 200 );
			std::string row;
			std::cin >> row;
			for ( int j = 0; j < m; ++j )
			{
				maze[i][j] = row[j] - '0';
			}
		}

		int result = ShortestPath( maze, 0, 0, 0, n - 1, m - 1 );
		return result;
	}

	void DFS( Grid<int>& maze, int n, int m )
	{
		using Pos = std::pair<int, int>;

		std::queue<Pos> q;
		q.push( Pos( 0, 0 ) );

		Pos steps[] = {
			{ 1, 0 },
			{ 0, 1 },
			{ -1, 0 },
			{ 0, -1 }
		};

		while ( q.empty( ) == false )
		{
			const Pos& cur = q.front( );

			for ( Pos& step : steps )
			{
				int dx = cur.first + step.first;
				int dy = cur.second + step.second;

				if ( dx < 0 || dy < 0 || dx >= m || dy >= n )
				{
					continue;
				}

				if ( maze[dy][dx] == 0 )
				{
					continue;
				}

				if ( maze[dy][dx] == 1 )
				{
					maze[dy][dx] = maze[cur.second][cur.first] + 1;
					q.push( Pos( dx, dy ) );
				}
			}

			q.pop( );
		}
	}

	int solve2( )
	{
		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		Grid<int> maze( 200 );
		for ( int i = 0; i < n; ++i )
		{
			maze[i].resize( 200 );
			std::string row;
			std::cin >> row;
			for ( int j = 0; j < m; ++j )
			{
				maze[i][j] = row[j] - '0';
			}
		}

		DFS( maze, n, m );

		return maze[n - 1][m - 1];
	}
}