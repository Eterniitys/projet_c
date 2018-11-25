cmake_minimum_required(VERSION 3.5)

project(hash C)

#################################
#find_file(PARSEUR_H "parseur.h")
#if(PARSEUR_H)
#	get_filename_component(PARSEUR_INCLUDE_DIR ${PARSEUR_H} DIRECTORY)
#	include_directories("${PARSEUR_INCLUDE_DIR}")
#endif(PARSEUR_H)
#
#find_library(PARSEUR_LIB parseur)

#if(PARSEUR_LIB)
#	get_filename_component(PARSEUR_LIB_DIR ${PARSEUR_LIB} DIRECTORY)
#	link_directories("${PARSEUR_LIB_DIR}")
#endif(PARSEUR_LIB)*/

#ajout de la librairie tree
add_library(hash SHARED hash.c hash.h)

#fichiers de destination
install(
	TARGETS hash
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
)

install(
	FILES hash.h
	DESTINATION include
)

#Liste exécutables/tests
foreach (dir_name IN ITEMS hash)
	add_executable(test-${dir_name} test-${dir_name}.c)
	add_dependencies(test-${dir_name} hash)
	target_link_libraries(test-${dir_name} hash)
	add_test(test-${dir_name} ./test-${dir_name})
endforeach(dir_name)
#Autorisation tests
enable_testing()




