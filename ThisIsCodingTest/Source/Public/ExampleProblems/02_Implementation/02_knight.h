#include <iostream>
#include <utility>

namespace knight
{
	bool IsInBoard( int x, int y )
	{
		return ( 0 <= x ) && ( 0 <= y ) && ( x < 8 ) && ( y < 8 );
	}

	int solve( )
	{
		std::string pos;
		std::cin >> pos;

		int x = ( pos[0] - 'a' );
		int y = ( pos[1] - '1' );

		std::pair<int, int> moves[] = {
			{ -1, 2 },
			{ -1, -2 },
			{ -2, -1 },
			{ -2, 1 },
			{ 1, 2 },
			{ 1, -2 },
			{ 2, -1 },
			{ 2, 1 }
		};

		int answer = 0;
		for ( auto move : moves )
		{
			int dx = x + move.first;
			int dy = y + move.second;

			if ( IsInBoard( dx, dy ) )
			{
				++answer;
			}
		}

		return answer;
	}
}