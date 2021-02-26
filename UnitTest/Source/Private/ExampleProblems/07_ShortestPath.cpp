#include "gtest/gtest.h"
#include "07_ShortestPath/02_future_city.h"
#include "07_ShortestPath/03_telegram.h"

TEST( ShortestPath, FutureCity_1 )
{
	const char* tc[] = {
R"(5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5)",
R"(4 2
1 3
2 4
3 4)"
	};

	int answer[] = { 3, -1 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		int result = future_city::solve1( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( ShortestPath, FutureCity_2 )
{
	const char* tc[] = {
R"(5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5)",
R"(4 2
1 3
2 4
3 4)"
	};

	int answer[] = { 3, -1 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		int result = future_city::solve2( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( ShortestPath, Telegram )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(3 2 1
1 2 4
1 3 2)" );

	std::cin.rdbuf( input.rdbuf( ) );

	std::string result = telegram::solve( );

	ASSERT_EQ( result, "2 4" );

	std::cin.rdbuf( orig );
}