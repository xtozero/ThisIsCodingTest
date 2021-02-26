#include "gtest/gtest.h"
#include "04_Sort/23_kook_yong_soo.h"
#include "04_Sort/24_antenna.h"
#include "04_Sort/25_fail_rate.h"
#include "04_Sort/26_card_sorting.h"

// https://www.acmicpc.net/problem/10825
TEST( SORT, KookYongSoo )
{
	const char* tc = 
R"(12
Junkyu 50 60 100
Sangkeun 80 60 50
Sunyoung 80 70 100
Soong 50 60 90
Haebin 50 60 100
Kangsoo 60 80 100
Donghyuk 80 60 100
Sei 70 70 70
Wonseob 70 70 90
Sanghyun 70 70 80
nsj 80 80 80
Taewhan 50 60 90)";

	const char* answer = 
R"(Donghyuk
Sangkeun
Sunyoung
nsj
Wonseob
Sanghyun
Sei
Kangsoo
Haebin
Junkyu
Soong
Taewhan)";

	std::streambuf* orig = std::cin.rdbuf( );
	std::istringstream input( tc );
	std::cin.rdbuf( input.rdbuf( ) );

	auto result = kook_young_soo::solve( );

	ASSERT_STREQ( answer, result.c_str( ) );

	std::cin.rdbuf( orig );
}

// v
// https://www.acmicpc.net/problem/18310
TEST( SORT, Antenna )
{
	const char* tc =
R"(4
5 1 7 9)";

	auto answer = 5;

	std::streambuf* orig = std::cin.rdbuf( );
	std::istringstream input( tc );
	std::cin.rdbuf( input.rdbuf( ) );

	auto result = antenna::solve( );

	ASSERT_EQ( answer, result );

	std::cin.rdbuf( orig );
}

// https://programmers.co.kr/learn/courses/30/lessons/42889
TEST( SORT, FailRate )
{
	std::vector<int> stages[] = {
		{ 2, 1, 2, 6, 2, 4, 3, 3 },
		{ 4,4,4,4,4 }
	};

	int n[] = {
		5,
		4
	};

	std::vector<int> answer[] = {
		{ 3,4,2,1,5 },
		{ 4,1,2,3 }
	};

	for ( int i = 0; i < std::extent_v<decltype( stages[i] )>; ++i )
	{
		auto result = fail_rate::solve( n[i], stages[i] );

		ASSERT_EQ( answer[i], result );
	}
}

// https://www.acmicpc.net/problem/1715
TEST( SORT, CardSorting )
{
	const char* tc =
R"(3
10
20
40)";

	auto answer = 100;

	std::streambuf* orig = std::cin.rdbuf( );
	std::istringstream input( tc );
	std::cin.rdbuf( input.rdbuf( ) );

	auto result = card_sorting::solve( );

	ASSERT_EQ( answer, result );

	std::cin.rdbuf( orig );
}
