#include "gtest/gtest.h"
#include "02_Implementation/07_lucky_straight.h"
#include "02_Implementation/08_string_realign.h"
#include "02_Implementation/09_string_compression.h"
#include "02_Implementation/10_lock_and_key.h"
#include "02_Implementation/11_dummy.h"
#include "02_Implementation/12_pillar_and_beam.h"
#include "02_Implementation/13_chicken_delivery.h"
#include "02_Implementation/14_outer_wall.h"

#include <string>
#include <vector>

TEST( Implementation, LuckyStraight )
{
	const char* tc[] = {
R"(123402)",
R"(7755)"
	};

	std::string answer[] = { "LUCKY", "READY" };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = lucky_straight::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( Implementation, StringRealign )
{
	const char* tc[] = {
R"(K1KA5CB7)",
R"(AJKDLSI412K4JSJ9D)"
	};

	std::string answer[] = { "ABCKK13", "ADDIJJJKKLSS20" };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = string_realign::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
// https://programmers.co.kr/learn/courses/30/lessons/60057
TEST( Implementation, StringCompression )
{
//	const char* tc[] = {
//R"(aabbaccc)",
//R"(ababcdcdababcdcd)",
//R"(abcabcdede)"
//R"(abcabcabcabcdededededede)"
//R"(xababcdcdababcdcd)"
//	};
//
//	int answer[] = { 7, 9, 8, 14, 17 };
//
//	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
//	{
//		auto result = string_compression::solve( tc[i] );
//		ASSERT_EQ( result, answer[i] );
//	}
}

// v
// 풀기는 풀었는데 시간내에 못 풀음
// https://programmers.co.kr/learn/courses/30/lessons/60059
TEST( Implementation, LockAndKey )
{
	//std::vector<std::vector<int>> lock = {
	//	{1, 1, 1},
	//	{1, 1, 0},
	//	{1, 0, 1}
	//};

	//std::vector<std::vector<int>> key = {
	//	{ 0, 0, 0 },
	//	{ 1, 0, 0 },
	//	{ 0, 1, 1 }
	//};

	//bool answer = true;

	//auto result = lock_and_key::solve( lock, key );
	//ASSERT_EQ( result, answer );
}

// https://www.acmicpc.net/problem/3190
TEST( Implementation, Dummy )
{
	const char* tc[] = {
R"(6
3
3 4
2 5
5 3
3
3 D
15 L
17 D)",
R"(10
4
1 2
1 3
1 4
1 5
4
8 D
10 D
11 D
13 L)",
R"(10
5
1 5
1 3
1 2
1 6
1 7
4
8 D
10 D
11 D
13 L)"
	};

	int answer[] = { 9, 21, 13 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = dummy::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// https://programmers.co.kr/learn/courses/30/lessons/60061
TEST( Implementation, PillarAndBeam )
{
	int n[] = { 5, 5 };

	std::vector<std::vector<int>> build_frame[] =
	{
		{ { 1, 0, 0, 1 }, { 1, 1, 1, 1 }, { 2, 1, 0, 1 }, { 2, 2, 1, 1 }, { 5, 0, 0, 1 },{ 5, 1, 0, 1 }, { 4, 2, 1, 1 }, { 3, 2, 1, 1 } },
		{ {0, 0, 0, 1 }, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1 }, { 3, 1, 1, 1 }, { 2, 0, 0, 0 }, { 1, 1, 1, 0 }, { 2, 2, 0, 1 } }
	};

	std::vector<std::vector<int>> answer[] =
	{
		{ { 1, 0, 0 }, { 1, 1, 1 }, { 2, 1, 0 },{ 2, 2, 1 }, { 3, 2, 1 }, { 4, 2, 1 }, { 5, 0, 0 }, { 5, 1, 0 } },
		{ { 0, 0, 0 }, { 0, 1, 1 }, { 1, 1, 1 }, { 2, 1, 1 }, { 3, 1, 1 }, { 4, 0, 0 } }
	};

	for ( int i = 0; i < std::extent_v<decltype( build_frame )>; ++i )
	{
		auto result = piller_and_beam::solve( n[i], build_frame[i] );
		ASSERT_EQ( result, answer[i] );
	}
}

// https://www.acmicpc.net/problem/15686
TEST( Implementation, ChickenDelivery )
{
	const char* tc[] = {
R"(5 3
0 0 1 0 0
0 0 2 0 1
0 1 2 0 0
0 0 1 0 0
0 0 0 0 2)",
R"(5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2)",
R"(5 1
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0)"
	};

	int answer[] = { 5, 10, 11 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = chicken_delivery::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
// https://programmers.co.kr/learn/courses/30/lessons/60062
TEST( Implementation, OuterWall )
{
	int n[] = { 12, 12 };

	std::vector<int> weak[] =
	{
		{ 1, 5, 6, 10 },
		{ 1, 3, 4, 9, 10 }
	};

	std::vector<int> dist[] =
	{
		{ 1, 2, 3, 4 },
		{ 3, 5, 7 }
	};

	int answer[] = { 2, 1 };

	for ( int i = 0; i < std::extent_v<decltype( weak )>; ++i )
	{
		auto result = outer_wall::solve( n[i], weak[i], dist[i] );
		ASSERT_EQ( result, answer[i] );
	}
}
