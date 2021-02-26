set (HEADER)

set (EXAMPLE_PROBLEMS
	./Source/Private/ExampleProblems/01_Greedy.cpp
	./Source/Private/ExampleProblems/02_Implementation.cpp
	./Source/Private/ExampleProblems/03_DFS_BFS.cpp
	./Source/Private/ExampleProblems/04_Sort.cpp
	./Source/Private/ExampleProblems/05_BinarySearch.cpp
	./Source/Private/ExampleProblems/06_DynamicProgramming.cpp
	./Source/Private/ExampleProblems/07_ShortestPath.cpp
	./Source/Private/ExampleProblems/08_Graph.cpp
)

set (PREVIOUSE_PROBLEMS
	./Source/Private/PreviousProblems/01_Greedy.cpp
	./Source/Private/PreviousProblems/02_Implementation.cpp
	./Source/Private/PreviousProblems/03_DFS_BFS.cpp
	./Source/Private/PreviousProblems/04_Sort.cpp
	./Source/Private/PreviousProblems/05_BinarySearch.cpp
	./Source/Private/PreviousProblems/06_DynamicProrgramming.cpp
	./Source/Private/PreviousProblems/07_ShortestPath.cpp
	./Source/Private/PreviousProblems/08_Graph.cpp
)

source_group("ExampleProblems" FILES ${EXAMPLE_PROBLEMS})
source_group("PreviousProblems" FILES ${PREVIOUSE_PROBLEMS})

enable_testing()

add_executable(unit_test ${HEADER} ${EXAMPLE_PROBLEMS} ${PREVIOUSE_PROBLEMS})

target_include_directories(unit_test
PRIVATE
	../ThirdParty/googletest/googletest/include
)

target_link_libraries(unit_test 
PRIVATE 
	gtest_main
	ThisIsCodingTest
)

add_test(NAME unit_test COMMAND unit_test)