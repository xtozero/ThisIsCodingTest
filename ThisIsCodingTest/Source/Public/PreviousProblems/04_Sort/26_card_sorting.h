#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>

namespace card_sorting
{
	int solve( )
	{
		int n = 0;
		std::cin >> n;

		std::priority_queue<int, std::vector<int>, std::greater<int>> q;

		for ( int i = 0; i < n; ++i )
		{
			int cards;
			std::cin >> cards;
			q.push( cards );
		}

		int result = 0;

		while ( q.size( ) > 1 )
		{
			int first = q.top();
			q.pop( );
			int second = q.top();
			q.pop( );

			int newCards = first + second;
			result += newCards;
			q.push( newCards );
		}

		return result;
	}
}