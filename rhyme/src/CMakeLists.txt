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

########
find_file(WORD_H "word.h")

if(WORD_H)
	# Calcul du dossier
	get_filename_component(WORD_INCLUDE_DIR ${WORD_H} DIRECTORY)
	# Ajout du dossier pour la recherche des fichiers entre chevrons
	include_directories("${WORD_INCLUDE_DIR}")
endif(WORD_H)

find_library(WORD_LIB list)

if(WORD_LIB)
	# Calcul du dossier
	get_filename_component(WORD_LIB_DIR ${WORD_LIB} DIRECTORY)
	# Ajout du dossier pour la recherche des librairies
	link_directories("${WORD_LIB_DIR}")
endif(WORD_LIB)

########
find_file(WORD_H "word.h")

if(PARSEUR_H)
	# Calcul du dossier
	get_filename_component(PARSEUR_INCLUDE_DIR ${PARSEUR_H} DIRECTORY)
	# Ajout du dossier pour la recherche des fichiers entre chevrons
	include_directories("${PARSEUR_INCLUDE_DIR}")
endif(PARSEUR_H)

find_library(PARSEUR_LIB list)

if(PARSEUR_LIB)
	# Calcul du dossier
	get_filename_component(PARSEUR_LIB_DIR ${PARSEUR_LIB} DIRECTORY)
	# Ajout du dossier pour la recherche des librairies
	link_directories("${PARSEUR_LIB_DIR}")
endif(PARSEUR_LIB)



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
