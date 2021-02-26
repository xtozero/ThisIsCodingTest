#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

namespace large_number
{
	int solve1( )
	{
		int n;
		int m;
		int k;

		std::cin >> n >> m >> k;

		std::vector<int> numbers;
		numbers.resize( n );
		for ( int i = 0; i < n; ++i )
		{
			std::cin >> numbers[i];
		}

		std::sort( std::begin( numbers ), std::end( numbers ), std::greater<int>() );

		int result = 0;
		for ( int i = 0, j = 0; i < m; ++i, ++j )
		{
			if ( j < k )
			{
				result += numbers[0];
			}
			else
			{
				result += numbers[1];
				j %= k;
			}
		}

		return result;
	}

	int solve2( )
	{
		int n;
		int m;
		int k;

		std::cin >> n >> m >> k;

		std::vector<int> numbers;
		numbers.resize( n );
		for ( int i = 0; i < n; ++i )
		{
			std::cin >> numbers[i];
		}

		std::sort( std::begin( numbers ), std::end( numbers ), std::greater<int>( ) );

		int count = ( m / ( k + 1 ) ) * k + ( m & k );
		int result = count * numbers[0] + ( m - count ) * numbers[1];

		return result;
	}
}