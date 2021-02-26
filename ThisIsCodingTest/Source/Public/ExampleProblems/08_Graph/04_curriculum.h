#include <iostream>
#include <queue>
#include <utility>

namespace curriculum
{
	using Adj = std::vector<int>;

	std::string solve( )
	{
		int n = 0;
		std::cin >> n;

		int indegree[501] = {};
		int duration[501] = {};
		Adj adj[501] = {};

		for ( int i = 1; i <= n; ++i )
		{
			std::cin >> duration[i];

			while ( true )
			{
				int subject = 0;
				std::cin >> subject;

				if ( subject == -1 )
				{
					break;
				}

				++indegree[i];
				adj[subject].emplace_back( i );
			}
		}

		int totalDuration[501] = {};
		std::queue<int> q;
		for ( int i = 1; i <= n; ++i )
		{
			if ( indegree[i] == 0 )
			{
				totalDuration[i] = duration[i];
				q.push( i );
			}
		}

		std::vector<int> v;

		while ( q.empty( ) == false )
		{
			int cur = q.front( );
			q.pop( );

			v.push_back( cur );

			for ( auto nxt : adj[cur] )
			{
				--indegree[nxt];
				if ( indegree[nxt] == 0 )
				{
					q.push( nxt );
				}
			}
		}

		for ( auto cur : v )
		{
			for ( auto nxt : adj[cur] )
			{
				totalDuration[nxt] = std::max( totalDuration[nxt], totalDuration[cur] + duration[nxt] );
			}
		}

		std::string result;
		for ( int i = 1; i <= n; ++i )
		{
			std::string time = std::to_string( totalDuration[i] );
			result += ( result.size( ) == 0 ) ? time : "\n" + time;
		}

		return result;
	}
}