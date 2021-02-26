#include "gtest/gtest.h"
#include "08_Graph/02_team_up.h"
#include "08_Graph/03_city_divide.h"
#include "08_Graph/04_curriculum.h"

TEST( Graph, TeamUp )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1)" );

	std::cin.rdbuf( input.rdbuf( ) );

	std::string result = team_up::solve( );

	constexpr char* answer = R"(NO
NO
YES)";

	ASSERT_EQ( result, answer );

	std::cin.rdbuf( orig );
}

TEST( Graph, CityDivide )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = city_divide::solve( );

	ASSERT_EQ( result, 8 );

	std::cin.rdbuf( orig );
}

TEST( Graph, Curriculum )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1)" );

	std::cin.rdbuf( input.rdbuf( ) );

	std::string result = curriculum::solve( );

	ASSERT_EQ( result, R"(10
20
14
18
17)" );

	std::cin.rdbuf( orig );
}
