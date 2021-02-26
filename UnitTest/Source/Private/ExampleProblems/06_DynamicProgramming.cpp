#include "gtest/gtest.h"
#include "06_DynamicProgramming/02_make_one.h"
#include "06_DynamicProgramming/03_ant_warrior.h"
#include "06_DynamicProgramming/04_tile.h"
#include "06_DynamicProgramming/05_money.h"

TEST( DynamicProgramming, MakeOne_1 )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(26)" );

	std::cin.rdbuf( input.rdbuf( ) );

	// bottom up
	int result = make_one::solve1( );

	ASSERT_EQ( result, 3 );

	std::cin.rdbuf( orig );
}

TEST( DynamicProgramming, MakeOne_2 )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(26)" );

	std::cin.rdbuf( input.rdbuf( ) );

	// top down
	int result = make_one::solve2( );

	ASSERT_EQ( result, 3 );

	std::cin.rdbuf( orig );
}

TEST( DynamicProgramming, AntWarrior_1 )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(4
1 3 1 5)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = ant_warrior::solve1( );

	ASSERT_EQ( result, 8 );

	std::cin.rdbuf( orig );
}

TEST( DynamicProgramming, AntWarrior_2 )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(4
1 3 1 5)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = ant_warrior::solve2( );

	ASSERT_EQ( result, 8 );

	std::cin.rdbuf( orig );
}

TEST( DynamicProgramming, Tile_1 )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(3)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = tile::solve1( );

	ASSERT_EQ( result, 5 );

	std::cin.rdbuf( orig );
}

TEST( DynamicProgramming, Tile_2 )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(3)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = tile::solve2( );

	ASSERT_EQ( result, 5 );

	std::cin.rdbuf( orig );
}

TEST( DynamicProgramming, Money_1 )
{
	const char* tc[] = {
R"(2 15
2
3)",
R"(3 4
3
5
7)"
	};

	int answer[] = { 5, -1 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		int result = money::solve1( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( DynamicProgramming, Money_2 )
{
	const char* tc[] = {
R"(2 15
2
3)",
R"(3 4
3
5
7)"
	};

	int answer[] = { 5, -1 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		int result = money::solve2( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}