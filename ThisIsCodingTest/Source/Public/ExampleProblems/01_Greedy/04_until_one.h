#include <iostream>
#include <algorithm>

namespace until_one
{
	int solve1( )
	{
		int n = 0;
		int k = 0;

		std::cin >> n >> k;

		int result = 0;

		while ( n != 1 )
		{
			if ( n % k == 0 )
			{
				n /= k;
			}
			else
			{
				--n;
			}

			++result;
		}

		return result;
	}

	int solve2( )
	{
		int n = 0;
		int k = 0;

		std::cin >> n >> k;

		int result = 0;

		while ( true )
		{
			int target = ( n / k ) * k;
			result += ( n - target );
			n = target;
			if ( n < k )
			{
				break;
			}

			++result;
			n /= k;
		}

		result += ( n - 1 );
		return result;
	}
}