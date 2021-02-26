#include <iostream>
#include <string>
#include <map>

namespace low_grade_student
{
	std::string solve( )
	{
		int n = 0;
		std::cin >> n;

		std::multimap<int, std::string> students;
		for ( int i = 0; i < n; ++i )
		{
			std::string name;
			int grade = 0;

			std::cin >> name >> grade;

			students.emplace( grade, name );
		}

		std::string result;
		for ( const auto& student : students )
		{
			result += student.second;
			result += " ";
		}

		return result;
	}
}