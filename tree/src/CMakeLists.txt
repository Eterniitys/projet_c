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

#Liste exécutables
add_executable(test-tree test-tree.c)
add_dependencies(test-tree tree)
target_link_libraries(test-tree tree)

add_executable(test-generate-tree test-generate-tree.c)
add_dependencies(test-tree tree)
target_link_libraries(test-generate-tree tree parseur)

add_executable(test-tree_create test-tree_create.c)
add_dependencies(test-tree_create tree)
target_link_libraries(test-tree_create tree)

add_executable(test-tree_destroy test-tree_destroy.c)
add_dependencies(test-tree_destroy tree)
target_link_libraries(test-tree_destroy tree parseur)

add_executable(test-tree_get_node test-tree_get_node.c)
add_dependencies(test-tree_get_node tree)
target_link_libraries(test-tree_get_node tree parseur)

add_executable(test-tree_add_node test-tree_add_node.c)
add_dependencies(test-tree_add_node tree)
target_link_libraries(test-tree_add_node tree parseur)

add_executable(test-tree_get_branch test-tree_get_branch.c)
add_dependencies(test-tree_get_branch tree)
target_link_libraries(test-tree_get_branch tree parseur)

add_executable(test-tree_count_children test-tree_count_children.c)
add_dependencies(test-tree_count_children tree)
target_link_libraries(test-tree_count_children tree parseur)

add_executable(test-tree_lock test-tree_lock.c)
add_dependencies(test-tree_lock tree)
target_link_libraries(test-tree_lock tree parseur)

add_executable(test-tree_unlock test-tree_unlock.c)
add_dependencies(test-tree_unlock tree)
target_link_libraries(test-tree_unlock tree parseur)

add_executable(test-tree_find_child test-tree_find_child.c)
add_dependencies(test-tree_find_child tree)
target_link_libraries(test-tree_find_child tree parseur)

#Autorisation tests
enable_testing()

#Liste tests
add_test(test-tree ./test-tree)
add_test(test-generate-tree ./test-generate-tree)
add_test(test-tree_create ./test-tree_create)
add_test(test-tree_destroy ./test-tree_destroy)
add_test(test-tree_get_node ./test-tree_get_node)
add_test(test-tree_add_node ./test-tree_add_node)
add_test(test-tree_get_branch ./test-tree_get_branch)
add_test(test-tree_count_children ./test-tree_count_children)
add_test(test-tree_lock ./test-tree_lock)
add_test(test-tree_unlock ./test-tree_unlock)
add_test(test-tree_find_child ./test-tree_find_child)


