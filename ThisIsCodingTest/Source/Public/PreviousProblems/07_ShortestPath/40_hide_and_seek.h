#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

namespace hide_and_seek
{
	std::string solve( )
	{
		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		using Adj = std::vector<int>;
		Adj adjs[20001];

		for ( int i = 0; i < m; ++i )
		{
			int a = 0;
			int b = 0;

			std::cin >> a >> b;
			adjs[a].push_back( b );
			adjs[b].push_back( a );
		}

		int distance[20001];
		std::fill( std::begin( distance ), std::end( distance ), static_cast<int>( 1e9 ) );
	
		auto cmp = []( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs )
		{
			return lhs.second > rhs.second;
		};

		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype( cmp )> q( cmp );

		q.push( { 1, 0 } );
		distance[1] = 0;

		while ( q.empty( ) == false )
		{
			auto node = q.top( );
			q.pop( );

			if ( node.second > distance[node.first] )
			{
				continue;
			}

			for ( const auto& neighbor : adjs[node.first] )
			{
				int weight = node.second + 1;
				if ( weight < distance[neighbor] )
				{
					q.push( { neighbor, weight } );
					distance[neighbor] = weight;
				}
			}
		}

		int hideNode = 1;
		int hideDistance = 0;
		int sameDistance = 0;

		for ( int i = 1; i <= n; ++i )
		{
			if ( hideDistance < distance[i] )
			{
				hideNode = i;
				hideDistance = distance[i];
				sameDistance = 1;
			}
			else if ( hideDistance == distance[i] )
			{
				++sameDistance;
			}
		}

		std::string result = std::to_string( hideNode ) + " " + std::to_string( hideDistance ) + " " + std::to_string( sameDistance );
		return result;
	}
}