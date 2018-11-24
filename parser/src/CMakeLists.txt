cmake_minimum_required(VERSION 3.5)

project(parseur C) 

find_file(WORD_H "word.h")

if(WORD_H)
	# Search of directory
	get_filename_component(WORD_INCLUDE_DIR ${WORD_H} DIRECTORY)
	# Calling with <>
	include_directories("${WORD_INCLUDE_DIR}")
endif(WORD_H)

find_library(WORD_LIB word)

if(WORD_LIB)
	# Search of directory
	get_filename_component(WORD_LIB_DIR ${WORD_LIB} DIRECTORY)
	# Add file for research of library
	link_directories("${WORD_LIB_DIR}")
endif(WORD_LIB)



find_file(TREE_H "tree.h")
if(TREE_H)
	# Search of directory
	get_filename_component(TREE_INCLUDE_DIR ${TREE_H} DIRECTORY)
	# Calling with <>
	include_directories("${TREE_INCLUDE_DIR}")
endif(TREE_H)
find_library(TREE_LIB word)
if(TREE_LIB)
	# Search of directory
	get_filename_component(TREE_LIB_DIR ${TREE_LIB} DIRECTORY)
	# Add file for research of library
	link_directories("${TREE_LIB_DIR}")
endif(TREE_LIB)


# include library parseur
add_library(parseur SHARED parseur.c parseur.h)

# library parseur use library word 
target_link_libraries(parseur word)
# library parseur use library tree 
target_link_libraries(parseur tree)


# Destination files
install(
	TARGETS parseur
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	)
install(
	FILES parseur.h
	DESTINATION include
	)

# Creation of executable
add_executable(test-parseur test-parseur.c)
add_dependencies(test-parseur parseur)
target_link_libraries(test-parseur parseur)

#Allowed tests
enable_testing()

# add test
add_test(test-parseur ./test-parseur)



