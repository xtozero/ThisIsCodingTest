#include "gtest/gtest.h"
#include "04_Sort/02_uptodown.h"
#include "04_Sort/03_low_grade_student.h"
#include "04_Sort/04_swap_element.h"

TEST( Sort, UpToDown )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(3
15
27
12)" );

	std::cin.rdbuf( input.rdbuf( ) );

	std::string result = uptodown::solve( );

	ASSERT_EQ( result, "27 15 12" );

	std::cin.rdbuf( orig );
}

TEST( Sort, LowGradeStudent )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(3
������ 100
ȫ�浿 95
�̼��� 77)" );

	std::cin.rdbuf( input.rdbuf( ) );

	std::string result = low_grade_student::solve( );

	ASSERT_EQ( result, "�̼��� ȫ�浿 ������ " );

	std::cin.rdbuf( orig );
}

TEST( Sort, SwapElement )
{
	std::streambuf* orig = std::cin.rdbuf( );

	std::istringstream input(
		R"(5 3
1 2 5 4 3
5 5 6 6 5)" );

	std::cin.rdbuf( input.rdbuf( ) );

	int result = swap_element::solve( );

	ASSERT_EQ( result, 26 );

	std::cin.rdbuf( orig );
}