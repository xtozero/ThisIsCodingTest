#include <numeric>
#include <iostream>
#include <string>

namespace team_up
{
	int FindParent( int* parent, int n )
	{
		if ( parent[n] != n )
			parent[n] = FindParent( parent, parent[n] );

		return parent[n];
	}

	void Union( int* parentList, int lhs, int rhs )
	{
		lhs = FindParent( parentList, lhs );
		rhs = FindParent( parentList, rhs );

		if ( lhs < rhs )
		{
			parentList[rhs] = lhs;
		}
		else
		{
			parentList[lhs] = rhs;
		}
	}

	std::string solve( )
	{
		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		int parent[100001] = {};
		std::iota( std::begin( parent ), std::end( parent ), 0 );

		std::string result;
		for ( int i = 0; i < m; ++i )
		{
			int command = 0;
			int team1 = 0;
			int team2 = 0;
			std::cin >> command >> team1 >> team2;

			switch ( command )
			{
			case 0:
				Union( parent, team1, team2 );
				break;
			case 1:
			{
				int team1Parent = FindParent( parent, team1 );
				int team2Parent = FindParent( parent, team2 );

				std::string sameTeam = ( team1Parent == team2Parent ) ? "YES" : "NO";

				result += ( result.size( ) == 0 ) ? sameTeam : ( "\n" + sameTeam );

				break;
			}	
			default:
				break;
			}
		}

		return result;
	}
}