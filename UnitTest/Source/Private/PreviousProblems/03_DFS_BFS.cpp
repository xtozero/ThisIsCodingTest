#include "gtest/gtest.h"
#include "03_DFS_BFS/15_find_city.h"
#include "03_DFS_BFS/16_laboratory.h"
#include "03_DFS_BFS/17_infection.h"
#include "03_DFS_BFS/18_parentheses_convert.h"
#include "03_DFS_BFS/19_operator_insertion.h"
#include "03_DFS_BFS/20_avoid_serveillance.h"
#include "03_DFS_BFS/21_population_movement.h"
#include "03_DFS_BFS/22_moving_blocks.h"

// https://www.acmicpc.net/problem/18352
TEST( DFS_BFS, FindCity )
{
	const char* tc[] = {
R"(4 4 2 1
1 2
1 3
2 3
2 4)",
R"(4 3 2 1
1 2
1 3
1 4)",
R"(4 4 1 1
1 2
1 3
2 3
2 4)"
	};

	std::string answer[] = { 
R"(4)", 
R"(-1)",  
R"(2
3)"};

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = find_city::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
// 맞았지만 시간 초과 ㅜㅜ
// https://www.acmicpc.net/problem/14502
TEST( DFS_BFS, Laboratory )
{
	const char* tc[] = {
R"(7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0)",
R"(4 6
0 0 0 0 0 0
1 0 0 0 0 2
1 1 1 0 0 2
0 0 0 0 0 2)",
R"(8 8
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0)"
	};

	int answer[] = { 27, 9, 3 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = laboratory::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// https://www.acmicpc.net/problem/18405
TEST( DFS_BFS, Infection )
{
	const char* tc[] = {
R"(3 3
1 0 2
0 0 0
3 0 0
2 3 2)",
R"(3 3
1 0 2
0 0 0
3 0 0
1 2 2)",
	};

	int answer[] = { 3, 0 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = infection::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// https://programmers.co.kr/learn/courses/30/lessons/60058
TEST( DFS_BFS, ParenthesesConvert )
{
	const char* tc[] = {
		"(()())()",
		")(",
		"()))((()" };

	const char* answer[] = { 
		"(()())()",
		"()",
		"()(())()" };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		auto result = parentheses_convert::solve( tc[i] );

		ASSERT_EQ( result, answer[i] );
	}
}

TEST( DFS_BFS, OperatorInsertion )
{
	const char* tc[] = {
R"(2
5 6
0 0 1 0)",
R"(3
3 4 5
1 0 1 0)",
R"(6
1 2 3 4 5 6
2 1 1 1)" };

	const char* answer[] = { 
R"(30
30)",
R"(35
17)",
R"(54
-24)"
	};

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = operator_insertion::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// https://www.acmicpc.net/problem/18428
TEST( DFS_BFS, AvoidServeillance )
{
	const char* tc[] = {
R"(5
X S X X T
T X S X X
X X X X X
X T X X X
X X T X X)",
R"(4
S S S T
X X X X
X X X X
T T T X)"};

	const char* answer[] = { "YES", "NO" };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = avoid_serveillance::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v 시간내에 못 품
// https://www.acmicpc.net/problem/16234
TEST( DFS_BFS, PopulationMovement )
{
	const char* tc[] = {
R"(2 20 50
50 30
20 40)",
R"(2 40 50
50 30
20 40)",
R"(2 20 50
50 30
30 40)",
R"(3 5 10
10 15 20
20 30 25
40 22 10)",
R"(4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10)" };

	int answer[] = { 1, 0, 1, 2, 3 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = population_movement::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
// https://programmers.co.kr/learn/courses/30/lessons/60063
TEST( DFS_BFS, MovingBlocks )
{
	std::vector<std::vector<int>> board( { {0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0} } );

	auto result = moving_blocks::solve( board );

	ASSERT_EQ( result, 7 );
}