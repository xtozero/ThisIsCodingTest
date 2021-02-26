#include <cctype>
#include <iostream>
#include <string>
#include <type_traits>

namespace string_realign
{
	std::string solve( )
	{
		std::string s;
		std::cin >> s;

		int alphabet[26] = {};
		int digitSum = 0;
		for ( auto c : s )
		{
			if ( std::isdigit( c ) )
			{
				digitSum += c - '0';
			}
			else
			{
				++alphabet[c - 'A'];
			}
		}

		std::string result;
		result.reserve( s.size( ) );

		for ( int i = 0; i < std::extent_v<decltype(alphabet)>; ++i )
		{
			for ( int j = 0; j < alphabet[i]; ++j )
			{
				result += 'A' + i;
			}
		}

		result += std::to_string( digitSum );

		return result;
	}
}