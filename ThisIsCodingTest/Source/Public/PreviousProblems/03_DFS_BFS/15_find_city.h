#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

namespace find_city
{
	std::string solve( )
	{
		std::ios::sync_with_stdio( false );

		int n = 0;
		int m = 0;
		int k = 0;
		int x = 0;
		std::cin >> n >> m >> k >> x;

		using Adj = std::vector<int>;

		std::vector<Adj> adjs( n + 1 );
		for ( int i = 0; i < m; ++i )
		{
			int from = 0;
			int to = 0;
			std::cin >> from >> to;

			adjs[from].push_back( to );
		}

		std::vector<bool> visit( n + 1 );
		std::vector<int> result;

		std::queue<std::pair<int, int>> q;
		q.push( { x, 0 } );
		visit[x] = true;
		while ( q.empty( ) == false )
		{
			auto cur = q.front( );
			q.pop( );

			int nextDist = cur.second + 1;
			for ( auto& to : adjs[cur.first] )
			{
				if ( visit[to] )
				{
					continue;
				}

				visit[to] = true;

				if ( nextDist == k )
				{
					result.push_back( to );
				}
				else
				{
					q.push( { to, nextDist } );
				}
			}
		}

		std::sort( std::begin( result ), std::end( result ) );

		if ( result.size( ) == 0 )
		{
			return "-1";
		}
		else
		{
			std::string resultStr;
			for ( auto city : result )
			{
				resultStr += ( resultStr.size( ) == 0 ) ? std::to_string( city ) : "\n" + std::to_string( city );
			}

			return resultStr;
		}
	}
}