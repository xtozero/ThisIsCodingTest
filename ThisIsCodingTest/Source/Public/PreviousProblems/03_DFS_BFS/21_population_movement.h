#include <algorithm>
#include <iostream>

namespace population_movement
{
	struct Country
	{
		int x;
		int y;
		int population;
	};

	void dfs( const int( &grid )[50][50], bool( &visit )[50][50], std::vector<Country>& unite, int x, int y, int n, int l, int r )
	{
		if ( ( x < 0 ) || ( y < 0 ) || ( x >= n ) || ( y >= n ) )
		{
			return;
		}

		unite.push_back( { x, y, grid[y][x] } );
		
		int dx[] = { 1, 0, -1, 0 };
		int dy[] = { 0, 1, 0, -1 };

		for ( int i = 0; i < 4; ++i )
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if ( ( nextX < 0 ) || ( nextY < 0 ) || ( nextX >= n ) || ( nextY >= n ) )
			{
				continue;
			}

			if ( visit[nextY][nextX] )
			{
				continue;
			}

			int diff = std::abs( grid[y][x] - grid[nextY][nextX] );
			if ( l <= diff && diff <= r )
			{
				visit[nextY][nextX] = true;
				dfs( grid, visit, unite, nextX, nextY, n, l, r );
			}
		}
	}

	int solve( )
	{
		int n = 0;
		int l = 0;
		int r = 0;

		std::cin >> n >> l >> r;

		int grid[50][50] = {};
		bool visit[50][50] = {};

		for ( int y = 0; y < n; ++y )
		{
			for ( int x = 0; x < n; ++x )
			{
				std::cin >> grid[y][x];
			}
		}

		int result = 0;

		while ( true )
		{
			std::vector<std::vector<Country>> unites;

			for ( int y = 0; y < n; ++y )
			{
				for ( int x = 0; x < n; ++x )
				{
					visit[y][x] = false;
				}
			}

			for ( int y = 0; y < n; ++y )
			{
				for ( int x = 0; x < n; ++x )
				{
					if ( visit[y][x] == false )
					{
						visit[y][x] = true;
						unites.emplace_back( );
						dfs( grid, visit, unites.back( ), x, y, n, l, r );
					}
				}
			}

			bool noPopulationMovement = std::all_of( std::begin( unites ), std::end( unites ), []( const std::vector<Country>& unite ) { return unite.size( ) <= 1; } );

			if ( noPopulationMovement )
			{
				break;
			}

			for ( auto& unite : unites )
			{
				if ( unite.size( ) > 1 )
				{
					int total = 0;
					for ( auto& country : unite )
					{
						total += country.population;
					}
					total /= unite.size( );

					for ( auto& country : unite )
					{
						grid[country.y][country.x] = total;
					}
				}
			}			

			++result;
		}

		return result;
	}
}