#include "gtest/gtest.h"
#include "03_DFS_BFS/03_frozen_juice.h"
#include "03_DFS_BFS/04_maze.h"

TEST( DFS_BFS, FrozenJuice )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = frozen_juice::solve( );

	ASSERT_EQ( result, 8 );

	std::cin.rdbuf( orig );
}

TEST( DFS_BFS, Maze_1 )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(5 6
101010
111111
000001
111111
111111)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = maze::solve1( );

	ASSERT_EQ( result, 10 );

	std::cin.rdbuf( orig );
}

TEST( DFS_BFS, Maze_2 )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(5 6
101010
111111
000001
111111
111111)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = maze::solve2( );

	ASSERT_EQ( result, 10 );

	std::cin.rdbuf( orig );
}
