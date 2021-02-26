#include "gtest/gtest.h"
#include "06_DynamicProgramming/31_gold_mine.h"
#include "06_DynamicProgramming/32_integer_triangle.h"
#include "06_DynamicProgramming/33_leave_company.h"
#include "06_DynamicProgramming/34_deploying_soldiers.h"
#include "06_DynamicProgramming/35_ugly_numbers.h"
#include "06_DynamicProgramming/36_edit_distance.h"

TEST( DynamicPorgramming, GoldMine )
{
	const char* tc[] = {
R"(2
3 4
1 3 3 2 2 1 4 1 0 6 4 7
4 4
1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2)" };

	const char* answer[] = { 
R"(19
16)" };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = gold_mine::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( DynamicProgramming, IntegerTriangle_1 )
{
	const char* tc[] = {
R"(5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5)" };

	int answer[] = { 30 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = integer_triangle::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( DynamicProgramming, IntegerTriangle_2 )
{
	const char* tc[] = {
R"(5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5)" };

	int answer[] = { 30 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = integer_triangle::solve2( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( DynamicProgramming, LeaveCompany )
{
	const char* tc[] = {
R"(7
3 10
5 20
1 10
1 20
2 15
4 40
2 200)",
R"(10
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10)",
R"(10
5 10
5 9
5 8
5 7
5 6
5 10
5 9
5 8
5 7
5 6)",
R"(10
5 50
4 40
3 30
2 20
1 10
1 10
2 20
3 30
4 40
5 50)" };

	int answer[] = { 45, 55, 20, 90 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = leave_company::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
// https://www.acmicpc.net/problem/18353
TEST( DynamicProgramming, DeployingSoldiers )
{
	const char* tc[] = {
R"(7
15 11 4 8 5 2 4)" };

	int answer[] = { 2 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = deploying_soldiers::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( DynamicProgramming, UglyNumbers_1 )
{
	const char* tc[] = {
R"(10)",
R"(4)",
R"(1000)" };

	int answer[] = { 12, 4, 51200000 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = ugly_numbers::solve1( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( DynamicProgramming, UglyNumbers_2 )
{
	const char* tc[] = {
R"(10)",
R"(4)",
R"(1000)" };

	int answer[] = { 12, 4, 51200000 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = ugly_numbers::solve2( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( DynamicProgramming, EditDistance )
{
	const char* tc[] = {
R"(cat
cut)",
R"(sunday
saturday)" };

	int answer[] = { 1, 3 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = edit_distance::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}