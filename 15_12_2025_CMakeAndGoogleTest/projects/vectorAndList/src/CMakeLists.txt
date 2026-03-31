target_sources(${CONTAINERS_LIB} 
	PRIVATE
		doubly_linked_list.cpp
		vector.cpp
)

target_include_directories(${CONTAINERS_LIB} PUBLIC
	"${PROJECT_SOURCE_DIR}/src"	
	#${CURRENT_SOURCE_DIR}
)
