#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

namespace telegram
{
	using Passage = std::vector<std::pair<int, int>>;

	constexpr int INF = 1e9;

	std::string solve( )
	{
		int n = 0;
		int m = 0;
		int c = 0;

		std::cin >> n >> m >> c;

		std::vector<Passage> city( 30001 );
		for ( int i = 0; i < m; ++i )
		{
			int from = 0;
			int to = 0;
			int weight = 0;

			std::cin >> from >> to >> weight;

			city[from].emplace_back( to, weight );
		}

		auto cmp = []( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs )
		{
			return lhs.first > rhs.first;
		};
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype( cmp )> q( cmp );

		std::vector<int> distance( 30001 );
		std::fill( std::begin( distance ), std::end( distance ), INF );

		distance[c] = 0;
		q.push( { 0, c } );

		while ( q.empty( ) == false )
		{
			auto v = q.top( );
			q.pop( );

			int fromWeight = v.first;
			int fromCity = v.second;
			
			if ( distance[fromCity] < fromWeight )
			{
				continue;
			}

			for ( auto edge : city[fromCity] )
			{
				int toWeight = fromWeight + edge.second;
				int toCity = edge.first;

				if ( toWeight < distance[toCity] )
				{
					distance[toCity] = toWeight;
					q.push( { toWeight, toCity } );
				}
			}
		}

		int totalCity = 0;
		int maxWeight = 0;

		for ( int i = 1; i <= n; ++i )
		{
			if ( ( distance[i] < INF ) && ( distance[i] != 0 ) )
			{
				++totalCity;
				maxWeight = std::max( maxWeight, distance[i] );
			}
		}

		return std::to_string( totalCity ) + " " + std::to_string( maxWeight );
	}
}