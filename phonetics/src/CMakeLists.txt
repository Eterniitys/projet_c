cmake_minimum_required(VERSION 3.5)
find_package(Valgrind)

project(phonetics C)

find_file(HASH_H "hash.h")
if(HASH_H)
	# Search of directory
	get_filename_component(HASH_INCLUDE_DIR ${HASH_H} DIRECTORY)
	# Calling with <>
	include_directories("${HASH_INCLUDE_DIR}")
endif(HASH_H)
find_library(HASH_LIB hash)
if(HASH_LIB)
	# Search of directory
	get_filename_component(HASH_LIB_DIR ${HASH_LIB} DIRECTORY)
	# Add file for research of library
	link_directories("${HASH_LIB_DIR}")
endif(HASH_LIB)


find_file(SYLLABIFICATION_H "syllabification.h")
if(SYLLABIFICATION_H)
	# Search of directory
	get_filename_component(SYLLABIFICATION_INCLUDE_DIR ${SYLLABIFICATION_H} DIRECTORY)
	# Calling with <>
	include_directories("${SYLLABIFICATION_INCLUDE_DIR}")
endif(SYLLABIFICATION_H)

find_library(SYLLABIFICATION_LIB syllabification)
if(SYLLABIFICATION_LIB)
	# Search of directory
	get_filename_component(SYLLABIFICATION_LIB_DIR ${SYLLABIFICATION_LIB} DIRECTORY)
	# Add file for research of library
	link_directories("${SYLLABIFICATION_LIB_DIR}")
endif(SYLLABIFICATION_LIB)


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
add_library(phonetics SHARED phonetics.c phonetics.h)

# library parser use library hash 
target_link_libraries(phonetics hash)
# library parser use library syllabification 
target_link_libraries(phonetics syllabification)
# library parser use library tree 
target_link_libraries(phonetics tree)


# Destination files
install(
	TARGETS phonetics
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
)
install(
	FILES phonetics.h
	DESTINATION include
)

#Allowed tests
enable_testing()

# Creation of executable
add_executable(test-phonetics test-phonetics.c)
add_dependencies(test-phonetics phonetics)
target_link_libraries(test-phonetics phonetics parser)
valgrind_test(test-phonetics ./test-phonetics)

