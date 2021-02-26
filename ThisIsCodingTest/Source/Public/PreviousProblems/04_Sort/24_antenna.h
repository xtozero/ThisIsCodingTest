#include <iostream>
#include <vector>
namespace antenna
{
	int solve( )
	{
		int n = 0;
		std::cin >> n;

		std::vector<int> v;
		v.resize( n );

		for ( int i = 0; i < n; ++i )
		{
			std::cin >> v[i];
		}

		std::sort( std::begin( v ), std::end( v ) );

		if ( n % 1 == 0 )
		{
			return v[n / 2 - 1];
		}
		else
		{
			return v[n / 2];
		}
	}
}