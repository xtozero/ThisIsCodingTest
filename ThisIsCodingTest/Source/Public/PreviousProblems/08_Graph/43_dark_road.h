#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

namespace dark_road
{
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
		int m = 0;
		std::cin >> n >> m;

		int parent[200001];

		std::iota( std::begin( parent ), std::end( parent ), 0 );

		using Edge = std::tuple<int, int, int>;
		std::vector<Edge> edges( m );

		int totalCost = 0;
		for ( int i = 0; i < m; ++i )
		{
			std::cin >> std::get<0>( edges[i] ) >> std::get<1>( edges[i] ) >> std::get<2>( edges[i] );

			totalCost += std::get<2>( edges[i] );
		}

		std::sort( std::begin( edges ), std::end( edges ), []( const Edge& lhs, const Edge& rhs )
		{
			return std::get<2>( lhs ) < std::get<2>( rhs );
		} );

		int edgeCount = 0;
		int cost = 0;

		for ( int i = 0; ( i < m ) && ( edgeCount < n - 1 ); ++i )
		{
			const Edge& edge = edges[i];
			int x = std::get<0>( edge );
			int y = std::get<1>( edge );
			int z = std::get<2>( edge );

			if ( FindParent( parent, x ) != FindParent( parent, y ) )
			{
				Union( parent, x, y );
				cost += z;
				++edgeCount;
			}
		}

		return totalCost - cost;
	}
}