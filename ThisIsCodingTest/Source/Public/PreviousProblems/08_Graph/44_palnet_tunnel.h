#include <algorithm>
#include <numeric>
#include <iostream>

namespace planet_tunnel
{
	int CalcCost( int xa, int ya, int za, int xb, int yb, int zb )
	{
		return std::min( { std::abs( xa - xb ), std::abs( ya - yb ), std::abs( za - zb ) } );
	}

	int FindParent( int* parent, int n )
	{
		if ( parent[n] != n )
		{
			parent[n] = FindParent( parent, parent[n] );
		}

		return parent[n];
	}

	void Union( int* parent, int a, int b )
	{
		a = FindParent( parent, a );
		b = FindParent( parent, b );

		if ( a < b )
		{
			parent[b] = a;
		}
		else
		{
			parent[a] = b;
		}
	}

	int solve( )
	{
		int n = 0;
		std::cin >> n;

		int parent[100000] = {};
		std::iota( std::begin( parent ), std::end( parent ), 0 );

		using Pos = std::tuple<int, int, int>;
		std::vector<Pos> planets( n );

		for ( auto& p : planets )
		{
			std::cin >> std::get<0>( p ) >> std::get<1>( p ) >> std::get<2>( p );
		}

		using Edge = std::tuple<int, int, int>;
		std::vector<Edge> edges;
		for ( int i = 0; i < n; ++i )
		{
			for ( int j = i; j < n; ++j )
			{
				if ( i == j )
				{
					continue;
				}

				auto [xa, ya, za] = planets[i];
				auto [xb, yb, zb] = planets[j];
				int cost = CalcCost( xa, ya, za, xb, yb, zb );

				edges.emplace_back( i, j, cost );
			}
		}

		std::sort( std::begin( edges ), std::end( edges ), []( const Edge& lhs, const Edge& rhs )
		{
			return std::get<2>( lhs ) < std::get<2>( rhs );
		} );

		int connected = 0;
		int totalCost = 0;
		for ( const auto& edge : edges )
		{
			auto [p1, p2, cost] = edge;
			if ( FindParent( parent, p1 ) != FindParent( parent, p2 ) )
			{
				++connected;
				Union( parent, p1, p2 );
				totalCost += cost;
			}
		}

		return totalCost;
	}
}