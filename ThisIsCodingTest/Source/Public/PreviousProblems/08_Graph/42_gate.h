#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

namespace gate
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

		if ( a < b )
		{
			parent[b] = a;
		}
		else
		{
			parent[a] = b;
		}
	}

	int solve( )
	{
		int g = 0;
		int p = 0;

		std::cin >> g >> p;

		int parent[100001] = {};
		std::iota( std::begin( parent ), std::end( parent ), 0 );

		int result = 0;
		int v = 0;
		for ( int i = 0; i < p; ++i )
		{
			std::cin >> v;
			
			int vp = FindParent( parent, v );
			if ( vp == 0 )
			{
				break;
			}
			else
			{
				++result;
				Union( parent, vp - 1, vp );
			}
		}

		return result;
	}
}