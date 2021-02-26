#include <iostream>
#include <string>

namespace flip_string
{
	int solve( )
	{
		std::string s;
		std::cin >> s;

		int countZero = 0;
		int countOne = 0;

		for ( int i = 0, end = s.size( ); i < end; ++i )
		{
			if ( ( i + 1 ) == end || s[i + 1] != s[i] )
			{
				if ( s[i] == '0' )
				{
					++countZero;
				}
				else
				{
					++countOne;
				}
			}
		}
		
		return std::min( countZero, countOne );
	}
}