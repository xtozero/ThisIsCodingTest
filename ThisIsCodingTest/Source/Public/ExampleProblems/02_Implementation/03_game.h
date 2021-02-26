#include <algorithm>
#include <iostream>
#include <utility>

namespace game
{
	enum Direction
	{
		North,
		East,
		South,
		West,
		Count,
	};

	int solve( )
	{
		int map[50][50] = {};
		bool visited[50][50] = {};

		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		int x;
		int y;
		int dir;

		std::cin >> x >> y >> dir;
		visited[y][x] = true;

		for ( int i = 0; i < n; ++i )
		{
			for ( int j = 0; j < m; ++j )
			{
				std::cin >> map[i][j];
			}
		}
		
		std::pair<int, int> step[] = {
			{ 0, -1 },
			{ 1, 0 },
			{ 0, 1 },
			{ -1, 0 }
		};

		int answer = 1;
		while ( true )
		{
			bool findPath = false;
			// 4 방향 검사
			for ( int i = 0; i < 4; ++i )
			{
				int dx = x + step[dir].first;
				int dy = y + step[dir].second;

				if ( ( -1 < dx ) && ( -1 < dy ) && ( dx < m ) && ( dy < n ) )
				{
					if ( map[dy][dx] == 0 && visited[dy][dx] == false )
					{
						++answer;
						visited[dy][dx] = true;
						x = dx;
						y = dy;
						findPath = true;
						break;
					}
				}

				--dir;
				if ( dir < 0 )
				{
					dir = West;
				}
			}

			// 길을 찾지 못한 경우 후진
			if ( findPath == false )
			{
				int backward = ( dir + 2 ) % 4;
				int dx = x + step[backward].first;
				int dy = y + step[backward].second;

				if ( map[dx][dy] == 1 )
				{
					break;
				}
				else
				{
					x = dx;
					y = dy;
				}
			}
		}

		return answer;
	}
}