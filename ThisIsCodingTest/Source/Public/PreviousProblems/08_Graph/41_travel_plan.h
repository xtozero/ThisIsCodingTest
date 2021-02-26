#include <algorithm>
#include <iostream>
#include <numeric>

namespace travel_plan
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

		if ( a > b )
		{
			parent[a] = b;
		}
		else
		{
			parent[b] = a;
		}
	}

	std::string solve( )
	{
		int parent[501] = {};
		std::iota( std::begin( parent ), std::end( parent ), 0 );

		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		for ( int j = 1; j <= n; ++j )
		{
			for ( int i = 1; i <= n; ++i )
			{
				int v;
				std::cin >> v;

				if ( v == 1 )
				{
					Union( parent, j, i );
				}
			}
		}

		int dest = 0;
		std::cin >> dest;
		int rep = FindParent( parent, dest );

		for ( int i = 1; i < m; ++i )
		{
			std::cin >> dest;
			int next = FindParent( parent, dest );
			if ( next != rep )
			{
				return "NO";
			}
		}

		return "YES";
	}
}