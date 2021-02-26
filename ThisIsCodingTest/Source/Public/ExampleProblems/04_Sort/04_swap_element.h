#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

namespace swap_element
{
	long long solve( )
	{
		int n = 0;
		int k = 0;
		std::cin >> n >> k;

		std::vector<int> a( n );
		std::vector<int> b( n );

		for ( int i = 0; i < n; ++i )
		{
			std::cin >> a[i];
		}

		for ( int i = 0; i < n; ++i )
		{
			std::cin >> b[i];
		}

		std::sort( std::begin( a ), std::end( a ) );
		std::sort( std::begin( b ), std::end( b ), std::greater<int>() );

		for ( int i = 0; i < k; ++i )
		{
			if ( a[i] < b[i] )
			{
				std::swap( a[i], b[i] );
			}
			else
			{
				break;
			}
		}

		return std::accumulate( std::begin( a ), std::end( a ), 0LL );
	}
}