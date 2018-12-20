cmake_minimum_required(VERSION 3.5)
find_package(Valgrind)

project(hash C)

#################################


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
foreach (dir_name IN ITEMS hash hashmap_new hashmap_set hashmap_get)
	add_executable(test-${dir_name} test-${dir_name}.c)
	add_dependencies(test-${dir_name} hash)
	target_link_libraries(test-${dir_name} hash)
	valgrind_test(test-${dir_name} ./test-${dir_name})
endforeach(dir_name)
#Autorisation tests
enable_testing()




