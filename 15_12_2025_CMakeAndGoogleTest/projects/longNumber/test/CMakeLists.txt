set(SOURCES
	testLongNumber.cpp	
)

add_executable(testLongNumber ${SOURCES})
target_link_libraries(testLongNumber
	gtest_main
	gmock_main
	${LIB_NAME}
)

add_test(testLongNumber testLongNumber)

set(SOURCES
	busko_test.cpp	
)

add_executable(busko_test ${SOURCES})
target_link_libraries(busko_test
	gtest_main
	gmock_main
	${LIB_NAME}
)

add_test(busko_test busko_test)
