#include "gtest/gtest.h"
#include "02_Implementation/02_knight.h"
#include "02_Implementation/03_game.h"

TEST( Implementation, Knight )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(a1)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = knight::solve( );

	ASSERT_EQ( result, 2 );

	std::cin.rdbuf( orig );
}

TEST( Implementation, Game )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(4 4
1 1 0
1 1 1 1
1 0 0 1
1 1 0 1
1 1 1 1)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = game::solve( );

	ASSERT_EQ( result, 3 );

	std::cin.rdbuf( orig );
}