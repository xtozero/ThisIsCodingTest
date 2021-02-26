#include <algorithm>
#include <iostream>
#include <vector>

namespace setup_wifi
{
	int solve( )
	{
		int n = 0;
		int c = 0;

		std::cin >> n >> c;

		std::vector<int> v( n );

		for ( int i = 0; i < n; ++i )
		{
			std::cin >> v[i];
		}

		std::sort( std::begin( v ), std::end( v ) );

		int min = 1;
		int max = v[n - 1] - v[0];
		int result = 0;

		while ( min <= max )
		{
			int mid = ( max + min ) / 2;
			int value = v[0];
			int count = 1;

			for ( int i = 1; i < n; ++i )
			{
				if ( value + mid <= v[i] )
				{
					value = v[i];
					++count;
				}
			}

			if ( count >= c )
			{
				min = mid + 1;
				result = mid;
			}
			else
			{
				max = mid - 1;
			}
		}

		return result;
	}
}