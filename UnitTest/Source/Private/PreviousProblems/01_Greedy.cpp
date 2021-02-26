#include "gtest/gtest.h"
#include "01_Greedy/01_adventurer_guild.h"
#include "01_Greedy/02_multiply_or_add.h"
#include "01_Greedy/03_flip_string.h"
#include "01_Greedy/04_price.h"
#include "01_Greedy/05_bowling_ball.h"
#include "01_Greedy/06_meogbang.h"

TEST( Greedy, AdventurerGuild )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(5
2 3 1 2 2)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = adventurer_guild::solve( );

	ASSERT_EQ( result, 2 );

	std::cin.rdbuf( orig );
}

TEST( Greedy, MultiplyOrAdd )
{
	const char* tc[] = {
R"(02984)",
R"(567)"
	};

	int answer[] = { 576, 210 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		int result = multiply_or_add::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
TEST( Greedy, FlipString )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(0001100)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = flip_string::solve( );

	ASSERT_EQ( result, 1 );

	std::cin.rdbuf( orig );
}

// v
TEST( Greedy, Price )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(5
3 2 1 1 9)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = price::solve( );

	ASSERT_EQ( result, 8 );

	std::cin.rdbuf( orig );
}

// 내가 작성한 답 O(n^2)
TEST( Greedy, BowlingBall_1 )
{
	const char* tc[] = {
R"(5 3
1 3 2 3 2)",
R"(8 5
1 5 4 3 2 4 5 2)"
	};

	int answer[] = { 8, 25 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		int result = bowling_ball::solve1( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
TEST( Greedy, BowlingBall_2 )
{
	const char* tc[] = {
R"(5 3
1 3 2 3 2)",
R"(8 5
1 5 4 3 2 4 5 2)"
	};

	int answer[] = { 8, 25 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		int result = bowling_ball::solve2( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
// https://programmers.co.kr/learn/courses/30/lessons/42891
TEST( Greedy, MeogBang )
{
	std::vector<int> food_times = { 3, 1, 2 };
	long long k = 5;

	int result = meogbang::solve( food_times, k );
	ASSERT_EQ( result, 1 );
}
