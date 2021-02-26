#include <iostream>
#include <queue>
#include <string>
#include <vector>

namespace final_ranking
{
	std::string solve( )
	{
		int t = 0;
		std::cin >> t;

		std::string result;

		while ( t-- )
		{
			int n = 0;
			std::cin >> n;

			int adj[501][501] = {};
			int indegree[501] = {};
			int lastRanking[500] = {};

			for ( int i = 0; i < n; ++i )
			{
				std::cin >> lastRanking[i];
			}

			for ( int i = 0; i < n; ++i )
			{
				for ( int j = i + 1; j < n; ++j )
				{
					int a = lastRanking[i];
					int b = lastRanking[j];

					adj[a][b] = 1;
					++indegree[b];
				}
			}

			int m = 0;
			std::cin >> m;

			for ( int i = 0; i < m; ++i )
			{
				int a = 0;
				int b = 0;
				std::cin >> a >> b;

				if ( adj[a][b] )
				{
					adj[a][b] = 0;
					adj[b][a] = 1;
					++indegree[a];
					--indegree[b];
				}
				else
				{
					adj[b][a] = 0;
					adj[a][b] = 1;
					++indegree[b];
					--indegree[a];
				}
			}

			std::queue<int> q;
			for ( int i = 1; i <= n; ++i )
			{
				if ( indegree[i] == 0 )
				{
					q.push( i );
				}
			}

			std::vector<int> ranking;
			bool ambiguity = false;
			while ( q.empty( ) == false )
			{
				if ( q.size( ) > 1 )
				{
					ambiguity = true;
					result += "?\n";
					break;
				}

				int team = q.front( );
				q.pop( );

				ranking.push_back( team );

				for ( int i = 1; i <= n; ++i )
				{
					if ( adj[team][i] > 0 )
					{
						--indegree[i];
						if ( indegree[i] == 0 )
						{
							q.push( i );
						}
					}
				}
			}

			if ( ambiguity == false )
			{
				if ( ranking.size( ) == n )
				{
					for ( auto rank : ranking )
					{
						result += std::to_string( rank ) + " ";
					}
					result.pop_back( );
					result += "\n";
				}
				else
				{
					result += "IMPOSSIBLE\n";
				}
			}
		}

		return result;
	}
}