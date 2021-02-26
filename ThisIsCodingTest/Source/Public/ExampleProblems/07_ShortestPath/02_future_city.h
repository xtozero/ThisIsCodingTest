#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

namespace future_city
{
	using Adj = std::vector<int>;

	int Dijkstra( Adj* roads, int start, int end )
	{
		int distance[101];
		std::fill_n( std::begin( distance ), 101, int(1e9) );
		distance[start] = 0;

		auto cmp = []( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs ) { return lhs.first > rhs.first; };
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype( cmp )> q( cmp );

		q.push( { 0, start } );

		while ( q.empty( ) == false )
		{
			auto p = q.top( );
			q.pop( );

			int company = p.second;
			int pathDistance = p.first;

			if ( distance[company] < pathDistance )
			{
				continue;
			}

			for ( auto to : roads[company] )
			{
				if ( pathDistance + 1 < distance[to] )
				{
					q.push( { pathDistance + 1, to } );
					distance[to] = pathDistance + 1;
				}
			}
		}

		return distance[end];
	}

	int solve1( )
	{
		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		Adj roads[101];

		for ( int i = 0; i < m; ++i )
		{
			int c1 = 0;
			int c2 = 0;

			std::cin >> c1 >> c2;

			roads[c1].push_back( c2 );
			roads[c2].push_back( c1 );
		}

		int x = 0;
		int k = 0;

		std::cin >> x >> k;

		int distToK = Dijkstra( roads, 1, k );
		int distToX = Dijkstra( roads, k, x );

		int distance = distToK + distToX;
		return distance >= ( int )1e9 ? -1 : distance;
	}

	int solve2( )
	{
		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		int road[101][101] = {};

		constexpr int INF = 1e9;
		for ( int i = 0; i < 101; ++i )
		{
			for ( int j = 0; j < 101; ++j )
			{
				road[i][j] = ( i == j ) ? 0 : INF;
			}
		}

		for ( int i = 0; i < m; ++i )
		{
			int c1 = 0;
			int c2 = 0;

			std::cin >> c1 >> c2;

			road[c1][c2] = 1;
			road[c2][c1] = 1;
		}

		int x = 0;
		int k = 0;

		std::cin >> x >> k;

		for ( int i = 1; i < 101; ++i )
		{
			for ( int j = 1; j < 101; ++j )
			{
				for ( int k = 1; k < 101; ++k )
				{
					road[i][j] = std::min( road[i][j], road[i][k] + road[k][j] );
				}
			}
		}

		int distance = road[1][k] + road[k][x];
		return distance >= ( int )1e9 ? -1 : distance;
	}
}