cmake_minimum_required(VERSION 3.5)

project(tree C)

# Important, il faut initialisé le path d'installation des lib soit la variable
# CMAKE_INSTALL_PREFIX
find_file(LIST_H "list.h")

if(LIST_H)
	# Calcul du dossier
	get_filename_component(LIST_INCLUDE_DIR ${LIST_H} DIRECTORY)
	# Ajout du dossier pour la recherche des fichiers entre chevrons
	include_directories("${LIST_INCLUDE_DIR}")
endif(LIST_H)

find_library(LIST_LIB list)

if(LIST_LIB)
	# Calcul du dossier
	get_filename_component(LIST_LIB_DIR ${LIST_LIB} DIRECTORY)
	# Ajout du dossier pour la recherche des librairies
	link_directories("${LIST_LIB_DIR}")
endif(LIST_LIB)

#ajout de la librairie tree
add_library(tree SHARED tree.c tree.h)
#la librairie tree utilise la librairie list
target_link_libraries(tree list)

#fichiers de destination
install(
	TARGETS tree
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
)

install(
	FILES tree.h
	DESTINATION include
)

#Liste exécutables
add_executable(test-tree test-tree.c tree.c tree.h)
add_dependencies(test-tree tree)
target_link_libraries(test-tree tree)

#Autorisation tests
enable_testing()

#Liste tests
add_test(test-tree ./test-tree)


