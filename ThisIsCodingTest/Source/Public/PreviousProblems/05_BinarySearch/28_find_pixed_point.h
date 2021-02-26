#include <iostream>
#include <vector>

namespace find_fixed_point
{
	int binarySearch( int begin, int end, int* sequence )
	{
		if ( begin > end )
		{
			return -1;
		}

		int mid = ( begin + end ) / 2;

		if ( mid > sequence[mid] )
		{
			return binarySearch( mid + 1, end, sequence );
		}
		else if ( mid < sequence[mid] )
		{
			return binarySearch( begin, mid - 1, sequence );
		}
		else
		{
			return mid;
		}
	}

	int solve( )
	{
		int n = 0;
		std::cin >> n;

		std::vector<int> v( n );

		for ( int i = 0; i < n; ++i )
		{
			std::cin >> v[i];
		}

		return binarySearch( 0, n - 1, v.data() );
	}
}