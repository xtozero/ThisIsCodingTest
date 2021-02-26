#include "gtest/gtest.h"
#include "08_Graph/41_travel_plan.h"
#include "08_Graph/42_gate.h"
#include "08_Graph/43_dark_road.h"
#include "08_Graph/44_palnet_tunnel.h"
#include "08_Graph/45_final_ranking.h"

// https://www.acmicpc.net/problem/1976
TEST( Graph, TravelPlan )
{
	const char* tc[] = {
R"(5 4
0 1 0 1 1
1 0 1 1 0
0 1 0 0 0
1 1 0 0 0
1 0 0 0 0
2 3 4 3)" };

	const char* answer[] = {
R"(YES)" };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = travel_plan::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// https://www.acmicpc.net/problem/10775
TEST( Graph, Gate )
{
	const char* tc[] = {
R"(4
3
4
1
1)",
R"(4
6
2
2
3
3
4
4)" };

	int answer[] = { 2, 3 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = gate::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// https://www.acmicpc.net/problem/6497
TEST( Graph, DarkRoad )
{
	const char* tc[] = {
R"(7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11)" };

	int answer[] = { 51 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = dark_road::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( Graph, PlanetTunnel )
{
	const char* tc[] = {
R"(5
11 -15 -15
14 -5 -15
-1 -1 -5
10 -4 -1
19 -4 19)" };

	int answer[] = { 4 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = planet_tunnel::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
// https://www.acmicpc.net/problem/3665
TEST( Graph, FianlRanking )
{
	const char* tc[] = {
R"(3
5
5 4 3 2 1
2
2 4
3 4
3
2 3 1
0
4
1 2 3 4
3
1 2
3 4
2 3)" };

	const char* answer[] = {
R"(5 3 2 4 1
2 3 1
IMPOSSIBLE)" };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = final_ranking::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}