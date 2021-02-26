#include <iostream>

namespace card_game
{
	int solve( )
	{
		int n = 0;
		int m = 0;

		std::cin >> n >> m;

		int result = 0;
		for ( int i = 0; i < n; ++i )
		{
			int minValue = 10'001;
			int value = 0;
			for ( int j = 0; j < m; ++j )
			{
				std::cin >> value;
				minValue = std::min( value, minValue );
			}

			result = std::max( minValue, result );
		}

		return result;
	}
}