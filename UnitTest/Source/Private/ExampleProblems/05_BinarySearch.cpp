#include "gtest/gtest.h"
#include "05_BinarySearch/02_find_components.h"
#include "05_BinarySearch/03_tteokbokki.h"

TEST( BinarySearch, find_components )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(5
8 3 7 9 2
3
5 7 9)" );

	std::cin.rdbuf( input.rdbuf( ) );

	std::string result = find_components::solve( );

	ASSERT_EQ( result, "no yes yes " );

	std::cin.rdbuf( orig );
}

TEST( BinarySearch, tteokbokki )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(4 6
19 15 10 17)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = tteokbokki::solve( );

	ASSERT_EQ( result, 15 );

	std::cin.rdbuf( orig );
}