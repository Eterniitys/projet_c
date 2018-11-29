cmake_minimum_required(VERSION 3.5)

project(rhyme C)


find_file(TREE_H "list.h")

if(TREE_H)
	# Calcul du dossier
	get_filename_component(TREE_INCLUDE_DIR ${TREE_H} DIRECTORY)
	# Ajout du dossier pour la recherche des fichiers entre chevrons
	include_directories("${TREE_INCLUDE_DIR}")
endif(TREE_H)

find_library(TREE_LIB list)

if(TREE_LIB)
	# Calcul du dossier
	get_filename_component(TREE_LIB_DIR ${TREE_LIB} DIRECTORY)
	# Ajout du dossier pour la recherche des librairies
	link_directories("${TREE_LIB_DIR}")
endif(TREE_LIB)

#ajout de la librairie tree
add_library(rhyme SHARED rhyme.c rhyme.h)
#la librairie tree utilise la librairie list
target_link_libraries(rhyme tree)



#Liste exécutables/tests
foreach (dir_name IN ITEMS rhyme)
	add_executable(test-${dir_name} test-${dir_name}.c)
	add_dependencies(test-${dir_name} rhyme)
	target_link_libraries(test-${dir_name} rhyme)
	add_test(test-${dir_name} ./test-${dir_name})
endforeach(dir_name)
#Autorisation tests
enable_testing()
