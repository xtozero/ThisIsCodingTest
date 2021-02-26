#include <iostream>
#include <vector>

namespace frozen_juice
{
	template<typename T>
	using Grid = std::vector<std::vector<T>>;

	bool Dfs( Grid<int>& board, int x, int y, int w, int h )
	{
		if ( x < 0 || y < 0 || x >= w || y >= h )
		{
			return false;
		}

		if ( board[y][x] == 1 )
		{
			return false;
		}

		board[y][x] = 1;

		Dfs( board, x + 1, y, w, h );
		Dfs( board, x, y + 1, w, h );
		Dfs( board, x - 1, y, w, h );
		Dfs( board, x, y - 1, w, h );
		return true;
	}

	int solve( )
	{
		Grid<int> board( 1000 );
		for ( auto& row : board )
		{
			row.resize( 1000 );
		}

		int n = 0;
		int m = 0;
		
		std::cin >> n >> m;

		for ( int i = 0; i < n; ++i )
		{
			std::string row;
			std::cin >> row;
			for ( int j = 0; j < m; ++j )
			{
				board[i][j] = row[j] - '0';
			}
		}

		int result = 0;

		for ( int i = 0; i < n; ++i )
		{
			for ( int j = 0; j < m; ++j )
			{
				if ( Dfs( board, j, i, m, n ) )
				{
					++result;
				}
			}
		}

		return result;
	}
}