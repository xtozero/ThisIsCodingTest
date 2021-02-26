#include "gtest/gtest.h"
#include "01_Greedy/02_large_numbers.h"
#include "01_Greedy/03_card_game.h"
#include "01_Greedy/04_until_one.h"

#include <iostream>
#include <string>
#include <type_traits>

TEST( Greedy, LargeNumber_1 )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input( 
		R"(5 8 3
2 4 5 4 6)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = large_number::solve1( );

	ASSERT_EQ( result, 46 );

	std::cin.rdbuf( orig );
}

TEST( Greedy, LargeNumber_2 )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(5 8 3
2 4 5 4 6)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = large_number::solve2( );

	ASSERT_EQ( result, 46 );

	std::cin.rdbuf( orig );
}

TEST( Greedy, CardGame )
{
	const char* tc[] = {
R"(3 3
3 1 2
4 1 4
2 2 2)",
R"(2 4
7 3 1 8
3 3 3 4)"
	};

	int answer[] = { 2, 3 };

	for ( int i = 0; i < std::extent_v<decltype(tc)>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		int result = card_game::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( Greedy, UntilOne_1 )
{
	const char* tc[] = {
R"(25 5)",
R"(100000 27)"
	};

	int answer[] = { 2, 32 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		int result = until_one::solve1( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( Greedy, UntilOne_2 )
{
	const char* tc[] = {
R"(25 5)",
R"(100000 27)"
	};

	int answer[] = { 2, 32 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		int result = until_one::solve2( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}