#include <iostream>
#include <vector>

namespace counting_number
{
	int* lowerBound( int* begin, int* end, int x )
	{
		int count = end - begin;

		while ( count > 0 )
		{
			int* it = begin;
			int step = count / 2;
			it += step;
			if ( *it < x )
			{
				begin = ++it;
				count -= step + 1;
			}
			else
			{
				count = step;
			}
		}

		return begin;
	}

	int* upperBound( int* begin, int* end, int x )
	{
		int count = end - begin;

		while ( count > 0 )
		{
			int* it = begin;
			int step = count / 2;
			it += step;
			if ( *it <= x )
			{
				begin = ++it;
				count -= step + 1;
			}
			else
			{
				count = step;
			}
		}

		return begin;
	}

	int solve( )
	{
		int n = 0;
		int x = 0;

		std::cin >> n >> x;

		std::vector<int> v( n );
		for ( int i = 0; i < n; ++i )
		{
			std::cin >> v[i];
		}

		int* lower = lowerBound( &v[0], &v[0] + n, x );
		int* upper = upperBound( &v[0], &v[0] + n, x );

		int count = upper - lower;
		return count == 0 ? -1 : count;
	}
}