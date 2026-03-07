target_sources(${LIB_NAME}
	PRIVATE
		longNumber.cpp
	PUBLIC
		longNumber.hpp
)

target_include_directories(${LIB_NAME} PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
