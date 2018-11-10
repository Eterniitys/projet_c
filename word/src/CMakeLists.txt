cmake_minimum_required(VERSION 3.12)

project(word C)

#ajout de la librairie word
add_library(word SHARED word.c word.h)

#fichiers de destination
install(
	TARGETS word
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
)

install(
	FILES word.h
	DESTINATION include
)

#Liste exécutables
add_executable(test-word test-word.c word.c word.h)
add_dependencies(test-word word)
target_link_libraries(test-word word)

#Autorisation tests
enable_testing()

#Liste tests
add_test(test-word ./test-word)
