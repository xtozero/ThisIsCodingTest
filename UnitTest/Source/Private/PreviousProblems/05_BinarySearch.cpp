#include "gtest/gtest.h"
#include "05_BinarySearch/27_counting_number.h"
#include "05_BinarySearch/28_find_pixed_point.h"
#include "05_BinarySearch/29_setup_wifi.h"
#include "05_BinarySearch/30_lyrics_search.h"

TEST( BinarySearch, CountingNumber )
{
	const char* tc[] = {
R"(7 2
1 1 2 2 2 2 3)",
R"(7 4
1 1 2 2 2 2 3)"};

	int answer[] = { 4, -1 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = counting_number::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

TEST( BinarySearch, FindFixedPoint )
{
	const char* tc[] = {
R"(5
-15 -6 1 3 7)",
R"(7
-15 -4 2 8 9 13 15)",
R"(7
-15 -4 3 8 9 13 15)" };

	int answer[] = { 3, 2, -1 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = find_fixed_point::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
// https://www.acmicpc.net/problem/2110
TEST( BinarySearch, SetupWifi )
{
	const char* tc[] = {
R"(5 3
1
2
8
4
9)" };

	int answer[] = { 3 };

	for ( int i = 0; i < std::extent_v<decltype( tc )>; ++i )
	{
		std::streambuf* orig = std::cin.rdbuf( );
		std::istringstream input( tc[i] );
		std::cin.rdbuf( input.rdbuf( ) );

		auto result = setup_wifi::solve( );

		ASSERT_EQ( result, answer[i] );

		std::cin.rdbuf( orig );
	}
}

// v
// https://programmers.co.kr/learn/courses/30/lessons/60060
TEST( BinarySearch, LyricsSearch )
{
	std::vector<std::string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };

	std::vector<std::string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };

	std::vector<int> answer = { 3, 2, 4, 1, 0 };

	auto result = lyrics_search::solve( words, queries );

	ASSERT_EQ( result, answer );
}