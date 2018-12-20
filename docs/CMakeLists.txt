cmake_minimum_required(VERSION 3.5)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../cmake")

find_package(Sphinx REQUIRED)
 
if(NOT DEFINED SPHINX_THEME)
    set(SPHINX_THEME default)
endif()
 
if(NOT DEFINED SPHINX_THEME_DIR)
    set(SPHINX_THEME_DIR)
endif()

set(SPHINX_HTML_DIR "${CMAKE_CURRENT_BINARY_DIR}/html")

#if(SPHINX_EXECUTABLE) 
	add_custom_target(docs
		COMMAND
			${SPHINX_EXECUTABLE}
				-q
				-b html
				"${CMAKE_CURRENT_SOURCE_DIR}"
				"${CMAKE_CURRENT_BINARY_DIR}/html"
		WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
		COMMENT "Building HTML documentation with Sphinx."
	)

	add_custom_command(TARGET docs POST_BUILD
		COMMENT "HTML documentation is in ${CMAKE_CURRENT_BINARY_DIR}/html"
	)

	install(
		DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html
		DESTINATION share/docs
		COMPONENT "Docs"
	)
#endif()