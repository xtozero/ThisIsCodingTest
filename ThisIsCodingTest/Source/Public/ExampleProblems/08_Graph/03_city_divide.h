#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

namespace city_divide
{
	int FindParent( int* parent, int n )
	{
		if ( parent[n] != n )
		{
			parent[n] = FindParent( parent, parent[n] );
		}

		return parent[n];
	}

	void Union( int* parent, int lhs, int rhs )
	{
		lhs = FindParent( parent, lhs );
		rhs = FindParent( parent, rhs );

		if ( lhs < rhs )
		{
			parent[rhs] = lhs;
		}
		else
		{
			parent[lhs] = rhs;
		}
	}

	struct Edge
	{
		int house1;
		int house2;
		int weight;
	};

	int solve( )
	{
		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		std::vector<Edge> v;
		for ( int i = 0; i < m; ++i )
		{
			v.emplace_back( );
			auto& e = v.back( );

			std::cin >> e.house1 >> e.house2 >> e.weight;
		}

		std::sort( std::begin( v ), std::end( v ), 
			[]( const Edge& lhs, const Edge& rhs ) 
			{
				return lhs.weight < rhs.weight;
			} );

		int parent[100001] = {};
		std::iota( std::begin( parent ), std::end( parent ), 0 );

		int totalWeight = 0;
		int groupCount = n;

		for ( auto& e : v )
		{
			if ( groupCount == 2 )
			{
				break;
			}

			int p1 = FindParent( parent, e.house1 );
			int p2 = FindParent( parent, e.house2 );

			if ( p1 != p2 )
			{
				Union( parent, e.house1, e.house2 );
				totalWeight += e.weight;
				--groupCount;
			}
		}
		
		return totalWeight;
	}
}