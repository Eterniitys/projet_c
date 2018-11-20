cmake_minimum_required(VERSION 3.5)

project(tree C)

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

#################################
find_file(PARSEUR_H "parseur.h")
if(PARSEUR_H)
	get_filename_component(PARSEUR_INCLUDE_DIR ${PARSEUR_H} DIRECTORY)
	include_directories("${PARSEUR_INCLUDE_DIR}")
endif(PARSEUR_H)

find_library(PARSEUR_LIB parseur)

if(PARSEUR_LIB)
	get_filename_component(PARSEUR_LIB_DIR ${PARSEUR_LIB} DIRECTORY)
	link_directories("${PARSEUR_LIB_DIR}")
endif(PARSEUR_LIB)

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

#Liste exécutables/tests
foreach (dir_name IN ITEMS generate_tree tree_destroy tree_get_node
		tree_add_node tree_get_branch tree_count_children tree_lock
		tree_unlock tree_find_child)
	add_executable(test-${dir_name} test-${dir_name}.c)
	add_dependencies(test-${dir_name} tree)
	target_link_libraries(test-${dir_name} tree parseur)
	add_test(test-${dir_name} ./test-${dir_name})
endforeach(dir_name)
#Autorisation tests
enable_testing()




