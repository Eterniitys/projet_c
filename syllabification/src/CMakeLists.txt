cmake_minimum_required(VERSION 3.5)
find_package(Valgrind)

project(syllabification C)

find_file(WORD_H "word.h")

if(WORD_H)
	# Search of directory
	get_filename_component(WORD_INCLUDE_DIR ${WORD_H} DIRECTORY)
	# Calling with <>
	include_directories("${WORD_INCLUDE_DIR}")
endif(WORD_H)


find_file(TREE_H "tree.h")
if(TREE_H)
	# Search of directory
	get_filename_component(TREE_INCLUDE_DIR ${TREE_H} DIRECTORY)
	# Calling with <>
	include_directories("${TREE_INCLUDE_DIR}")
endif(TREE_H)
find_library(TREE_LIB tree)
if(TREE_LIB)
	# Search of directory
	get_filename_component(TREE_LIB_DIR ${TREE_LIB} DIRECTORY)
	# Add file for research of library
	link_directories("${TREE_LIB_DIR}")
endif(TREE_LIB)


# include library parser
add_library(syllabification SHARED syllabification.c syllabification.h)

# library parser use library tree 
target_link_libraries(syllabification tree)


# Destination files
install(
	TARGETS syllabification
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
)
install(
	FILES syllabification.h
	DESTINATION include
)

#Allowed tests
enable_testing()

# Creation of executable
add_executable(test-syllabification test-syllabification.c)
add_dependencies(test-syllabification syllabification)
target_link_libraries(test-syllabification syllabification parser)
valgrind_test(test-syllabification ./test-syllabification)

