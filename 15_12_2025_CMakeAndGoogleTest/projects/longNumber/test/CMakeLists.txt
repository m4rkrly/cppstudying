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
