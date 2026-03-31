set(SOURCES
	testSorts.cpp
)

add_executable(testSorts ${SOURCES})
target_link_libraries(testSorts
	gtest_main
	gmock_main
	${LIB_NAME}
)

#add_test(testSorts testSorts)
