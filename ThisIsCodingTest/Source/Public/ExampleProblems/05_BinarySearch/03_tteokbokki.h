#include <algorithm>
#include <iostream>
#include <vector>

namespace tteokbokki
{
	int CuttingLength( std::vector<int>& v, int l )
	{
		int length = 0;

		for ( int number : v )
		{
			length += ( number > l ) ? number - l : 0;
		}

		return length;
	}

	int solve( )
	{
		int n = 0;
		int m = 0;
		std::cin >> n >> m;

		std::vector<int> v( n );
		for ( int i = 0; i < n; ++i )
		{
			std::cin >> v[i];
		}

		auto maxlength = std::max_element( std::begin( v ), std::end( v ) );

		int start = 0;
		int end = *maxlength;

		int result = 0;
		while ( start <= end )
		{
			int mid = ( end + start ) / 2;
			int cuttingLength = CuttingLength( v, mid );
			if ( cuttingLength < m )
			{
				end = mid - 1;
			}
			else
			{
				result = mid;
				start = mid + 1;
			}
		}

		return result;
	}
}