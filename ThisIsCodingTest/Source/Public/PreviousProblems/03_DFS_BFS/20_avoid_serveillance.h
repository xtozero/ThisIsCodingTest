#include <iostream>

namespace avoid_serveillance
{
	bool IsAllHide( const char( &grid )[6][6], int n )
	{
		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { 1, 0, -1, 0 };

		for ( int y = 0; y < n; ++y )
		{
			for ( int x = 0; x < n; ++x )
			{
				if ( grid[y][x] == 'T' )
				{
					for ( int i = 0; i < 4; ++i )
					{
						int checkX = x + dx[i];
						int checkY = y + dy[i];

						while ( ( checkX >= 0 && checkX < n ) && ( checkY >= 0 && checkY < n ) )
						{
							if ( grid[checkY][checkX] == 'S' )
							{
								return false;
							}
							else if ( grid[checkY][checkX] == 'O' )
							{
								break;
							}

							checkX += dx[i];
							checkY += dy[i];
						}
					}
				}
			}
		}

		return true;
	}

	bool dfs( char(&grid)[6][6], int obstacle, int prevY, int n )
	{
		if ( obstacle == 3 )
		{
			return IsAllHide( grid, n );
		}

		bool result = false;
		for ( int y = prevY; y < n; ++y )
		{
			for ( int x = 0; x < n; ++x )
			{
				if ( grid[y][x] == 'X' )
				{
					grid[y][x] = 'O';
					result |= dfs( grid, obstacle + 1, y, n );
					grid[y][x] = 'X';
				}
			}
		}

		return result;
	}

	std::string solve( )
	{
		int n = 0;
		std::cin >> n;

		char grid[6][6] = {};
		for ( int y = 0; y < n; ++y )
		{
			for ( int x = 0; x < n; ++x )
			{
				std::cin >> grid[y][x];
			}
		}

		return dfs( grid, 0, 0, n ) ? "YES" : "NO";
	}
}