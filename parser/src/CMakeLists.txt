cmake_minimum_required(VERSION 3.5)
find_package(Valgrind)

project(parser C)

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


find_file(TREE_H "hash.h")
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



# include library parser
add_library(parser SHARED parser.c parser.h)

# library parser use library tree 
target_link_libraries(parser tree)
# library parser use library hash
target_link_libraries(parser hash)
# library parser use library list
target_link_libraries(parser list)


# Destination files
install(
	TARGETS parser
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	)
install(
	FILES parser.h
	DESTINATION include
	)

# Creation of executable
add_executable(test-tree_syll test-tree_syll.c)
add_dependencies(test-tree_syll parser)
target_link_libraries(test-tree_syll parser)
valgrind_test(test-tree_syll ./test-tree_syll)

add_executable(test-invalid_input test-invalid_input.c)
add_dependencies(test-invalid_input parser)
target_link_libraries(test-invalid_input parser)
valgrind_test(test-invalid_input ./test-invalid_input)

add_executable(test-tree_phon test-tree_phon.c)
add_dependencies(test-tree_phon parser)
target_link_libraries(test-tree_phon parser)
valgrind_test(test-tree_phon ./test-tree_phon)

add_executable(test-fill_hash test-fill_hash.c)
add_dependencies(test-fill_hash parser)
target_link_libraries(test-fill_hash parser list)
valgrind_test(test-fill_hash ./test-fill_hash)

#Allowed tests
enable_testing()


