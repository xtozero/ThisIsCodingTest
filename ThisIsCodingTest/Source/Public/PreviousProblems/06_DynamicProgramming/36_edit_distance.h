#include <iostream>
#include <string>

namespace edit_distance
{
	int solve( )
	{
		std::string src;
		std::string dest;

		std::cin >> src >> dest;

		std::vector<std::vector<int>> dp( src.size( ) + 1 );
		for ( auto& v : dp )
		{
			v.resize( dest.size( ) + 1 );
		}

		for ( int i = 0; i <= dest.size( ); ++i )
		{
			dp[0][i] = i;
		}

		for ( int i = 0; i <= src.size( ); ++i )
		{
			dp[i][0] = i;
		}

		for ( int j = 1; j <= src.size( ); ++j )
		{
			for ( int i = 1; i <= dest.size( ); ++i )
			{
				if ( src[j] == dest[i] )
				{
					dp[j][i] = dp[j - 1][i - 1];
				}
				else
				{
					dp[j][i] = 1 + std::min( { dp[j][i - 1], dp[j - 1][i - 1], dp[j - 1][i] } );
				}
			}
		}

		return dp[src.size( )][dest.size( )];
	}
}