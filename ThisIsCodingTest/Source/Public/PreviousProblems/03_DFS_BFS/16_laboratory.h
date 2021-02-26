#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

namespace laboratory
{
	int board[8][8] = {};
	std::vector<std::pair<int, int>> empty;
	std::vector<std::pair<int, int>> toxin;
	int result = 0;
	int n = 0;
	int m = 0;

	void fillToxin( int x, int y, int (&b)[8][8], int width, int height )
	{
		int dx[] = { 1, 0, -1, 0 };
		int dy[] = { 0, 1, 0, -1 };

		for ( int i = 0; i < 4; ++i )
		{
			int newX = x + dx[i];
			int newY = y + dy[i];

			if ( newX >= 0 && newX < width && newY >= 0 && newY < height )
			{
				if ( b[newY][newX] == 0 )
				{
					b[newY][newX] = 2;
					fillToxin( newX, newY, b, width, height );
				}
			}
		}
	}

	void combi( int cur, int depth, int* num, int count, int* v )
	{
		if ( depth == 3 )
		{
			int copy[8][8] = {};

			for ( int y = 0; y < 8; ++y )
			{
				for ( int x = 0; x < 8; ++x )
				{
					copy[y][x] = board[y][x];
				}
			}

			for ( int i = 0; i < 3; ++i )
			{
				int x = empty[v[i]].first;
				int y = empty[v[i]].second;
				copy[y][x] = 1;
			}

			for ( auto& t : toxin )
			{
				fillToxin( t.first, t.second, copy, m, n );
			}

			int count = 0;

			for ( int y = 0; y < n; ++y )
			{
				for ( int x = 0; x < m; ++x )
				{
					if ( copy[y][x] == 0 )
					{
						++count;
					}
				}
			}

			result = std::max( result, count );

			return;
		}

		if ( cur >= count )
		{
			return;
		}

		v[depth] = num[cur];
		combi( cur + 1, depth + 1, num, count, v );
		combi( cur + 1, depth, num, count, v );
	}

	int solve( )
	{
		empty.clear();
		toxin.clear();
		result = 0;
		n = 0;
		m = 0;

		std::cin >> n >> m;

		for ( int y = 0; y < n; ++y )
		{
			for ( int x = 0; x < m; ++x )
			{
				std::cin >> board[y][x];
				if ( board[y][x] == 0 )
				{
					empty.push_back( { x, y } );
				}
				else if ( board[y][x] == 2 )
				{
					toxin.push_back( { x, y } );
				}
			}
		}

		std::vector<int> idx( empty.size( ) );
		std::iota( std::begin( idx ), std::end( idx ), 0 );
		int v[3] = {};
		combi( 0, 0, idx.data( ), idx.size( ), v );

		return result;
	}
}