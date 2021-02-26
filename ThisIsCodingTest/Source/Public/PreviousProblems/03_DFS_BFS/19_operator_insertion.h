#include <iostream>
#include <limits>
#include <string>

namespace operator_insertion
{
	void dfs( int cur, int n, int( &a )[11], int( &opCounts )[4], int value, int& min, int& max )
	{
		if ( cur >= n )
		{
			min = std::min( min, value );
			max = std::max( max, value );
			return;
		}

		for ( int i = 0; i < 4; ++i )
		{
			if ( opCounts[i] > 0 )
			{
				--opCounts[i];

				int result = value;

				switch ( i )
				{
				case 0:
					result += a[cur];
					break;
				case 1:
					result -= a[cur];
					break;
				case 2:
					result *= a[cur];
					break;
				case 3:
					result /= a[cur];
					break;
				default:
					break;
				}

				dfs( cur + 1, n, a, opCounts, result, min, max );

				++opCounts[i];
			}
		}
	}

	std::string solve( )
	{
		int n = 0;
		std::cin >> n;

		int a[11];
		for ( int i = 0; i < n; ++i )
		{
			std::cin >> a[i];
		}

		int opCounts[4];
		for ( auto& count : opCounts )
		{
			std::cin >> count;
		}

		int min = std::numeric_limits<int>::max( );
		int max = std::numeric_limits<int>::min( );

		dfs( 1, n, a, opCounts, a[0], min, max );

		return std::to_string( max ) + "\n" + std::to_string( min );
	}
}