#include "gtest/gtest.h"
#include "07_ShortestPath/37_floyd.h"
#include "07_ShortestPath/38_accurate_ranking.h"
#include "07_ShortestPath/39_mars_exploration.h"
#include "07_ShortestPath/40_hide_and_seek.h"

TEST( ShortestPath, Floyd )
{
	const char* tc[] = {
R"(5
14
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
3 5 10
3 1 8
1 4 2
5 1 7
3 4 2
5 2 4)" };

	const char* answer[] = { 
R"(0 2 3 1 4
12 0 15 2 5
8 5 0 1 1
10 7 13 0 3
7 4 10 6 0)" };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = floyd::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
TEST( ShortestPath, AccurateRanking )
{
	const char* tc[] = {
R"(6 6
1 5
3 4
4 2
4 6
5 2
5 4)" };

	int answer[] = { 1 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = accurate_ranking::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( ShortestPath, MarsExploration )
{
	const char* tc[] = {
R"(3
3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5
7 
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4)" };

	const char* answer[] = {
R"(20
19
36)" };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = mars_exploration::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( ShortestPath, HideAndSeek )
{
	const char* tc[] = {
R"(6 7
3 6
4 3
3 2
1 3
1 2
2 4
5 2)" };

	const char* answer[] = {
R"(4 2 3)" };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = hide_and_seek::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}