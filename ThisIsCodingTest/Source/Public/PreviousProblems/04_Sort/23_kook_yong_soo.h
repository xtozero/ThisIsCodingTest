#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace kook_young_soo
{
	struct Student
	{
		std::string name;
		int korean;
		int english;
		int math;
	};

	std::string solve( )
	{
		int n = 0;
		std::cin >> n;

		std::vector<Student> students;
		students.reserve( n );

		for ( int i = 0; i < n; ++i )
		{
			students.emplace_back( );
			auto& student = students.back( );

			std::cin >> student.name >> student.korean >> student.english >> student.math;
		}

		std::sort( std::begin( students ), std::end( students ), 
			[]( const Student& lhs, const Student& rhs )
		{
			if ( lhs.korean != rhs.korean )
			{
				return lhs.korean > rhs.korean;
			}
			else if ( lhs.english != rhs.english )
			{
				return lhs.english < rhs.english;
			}
			else if ( lhs.math != rhs.math )
			{
				return lhs.math > rhs.math;
			}

			return lhs.name < rhs.name;
		} );

		std::string result;

		for ( const auto& student : students )
		{
			result += student.name;
			result += "\n";
		}

		result.pop_back( ); // remove last line feed
		return result;
	}
}