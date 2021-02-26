#include <iostream>
#include <queue>
#include <utility>

namespace infection
{
	int solve( )
	{
		std::ios::sync_with_stdio( false );

		int n = 0;
		int k = 0;

		std::cin >> n >> k;

		int board[201][201];

		std::queue<std::pair<int, int>> q[1001];
		int virusCount[1001] = {};

		for ( int y = 1; y <= n; ++y )
		{
			for ( int x = 1; x <= n; ++x )
			{
				int virusType = 0;
				std::cin >> virusType;
				board[y][x] = virusType;

				if ( virusType > 0 )
				{
					++virusCount[virusType];
					q[virusType].push( { x, y } );
				}
			}
		}

		int s = 0;
		int row = 0;
		int col = 0;
		std::cin >> s >> row >> col;

		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { 1, 0, -1, 0 };

		for ( int i = 0; i < s; ++i )
		{
			for ( int j = 1; j <= k; ++j )
			{
				if ( virusCount[j] <= 0 )
				{
					continue;
				}

				while ( virusCount[j]-- > 0 )
				{
					auto pos = q[j].front( );
					q[j].pop( );

					for ( int l = 0; l < 4; ++l )
					{
						int infecX = pos.first + dx[l];
						int infecY = pos.second + dy[l];

						if ( infecX > 0 && infecX <= n && infecY > 0 && infecY <= n )
						{
							if ( board[infecY][infecX] == 0 )
							{
								board[infecY][infecX] = j;
								q[j].push( { infecX, infecY } );
							}
						}
					}
				}

				virusCount[j] = q[j].size( );
			}
		}

		return board[row][col];
	}
}