#include <iostream>
#include <queue>
#include <utility>
#include <vector>

namespace dummy
{
	enum
	{
		North,
		East,
		South,
		West
	};

	int TurnRight( int dir )
	{
		return ( dir + 1 ) % 4;
	}

	int TurnLeft( int dir )
	{
		--dir;
		if ( dir < 0 )
		{
			dir = West;
		}

		return dir;
	}

	int solve( )
	{
		int board[101][101] = {};

		int n = 0;
		int k = 0;
		std::cin >> n >> k;

		for ( int i = 0; i < k; ++i )
		{
			int row = 0;
			int col = 0;
			std::cin >> row >> col;

			board[row][col] = 1;
		}

		int l = 0;
		std::cin >> l;
		std::queue<std::pair<int, char>> turnInfo;

		for ( int i = 0; i < l; ++i )
		{
			int second = 0;
			char turn = 0;

			std::cin >> second >> turn;
			turnInfo.emplace( second, turn );
		}

		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { -1, 0, 1, 0 };

		int direction = East;

		int sec = 0;
		std::queue<std::pair<int, int>> sneak;
		sneak.emplace( 1, 1 );
		board[1][1] = 2;
		while ( sneak.empty( ) == false )
		{
			const auto& head = sneak.back( );

			++sec;
			int x = head.first + dx[direction];
			int y = head.second + dy[direction];

			if ( x < 1 || x > n || y < 1 || y > n )
			{
				break;
			}

			if ( board[y][x] > 1 )
			{
				break;
			}

			sneak.emplace( x, y );
			if ( board[y][x] == 0 )
			{
				auto const& tail = sneak.front( );
				board[tail.second][tail.first] = 0;
				sneak.pop( );
			}

			board[y][x] = 2;

			if ( turnInfo.empty( ) == false )
			{
				const auto& info = turnInfo.front( );
				if ( info.first == sec )
				{
					if ( info.second == 'L' )
					{
						direction = TurnLeft( direction );
					}
					else
					{
						direction = TurnRight( direction );
					}

					turnInfo.pop( );
				}
			}
		}

		return sec;
	}
}