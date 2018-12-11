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

find_library(WORD_LIB word)

if(WORD_LIB)
	# Calcul du dossier
	get_filename_component(WORD_LIB_DIR ${WORD_LIB} DIRECTORY)
	# Ajout du dossier pour la recherche des librairies
	link_directories("${WORD_LIB_DIR}")
endif(WORD_LIB)

########
find_file(PARSER_H "parser.h")

if(PARSER_H)
	# Calcul du dossier
	get_filename_component(PARSER_INCLUDE_DIR ${PARSER_H} DIRECTORY)
	# Ajout du dossier pour la recherche des fichiers entre chevrons
	include_directories("${PARSER_INCLUDE_DIR}")
endif(PARSER_H)

find_library(PARSER_LIB parser)

if(PARSER_LIB)
	# Calcul du dossier
	get_filename_component(PARSER_LIB_DIR ${PARSER_LIB} DIRECTORY)
	# Ajout du dossier pour la recherche des librairies
	link_directories("${PARSER_LIB_DIR}")
endif(PARSER_LIB)

########

########
find_file(LIST_H "list.h")

if(LIST_H)
	# Calcul du dossier
	get_filename_component(LIST_INCLUDE_DIR ${LIST_H} DIRECTORY)
	# Ajout du dossier pour la recherche des fichiers entre chevrons
	include_directories("${LIST_INCLUDE_DIR}")
endif(LIST_H)

find_library(LIST_LIB parser)

if(LIST_LIB)
	# Calcul du dossier
	get_filename_component(LIST_INCLUDE_DIR ${PARSER_LIB} DIRECTORY)
	# Ajout du dossier pour la recherche des librairies
	link_directories("${LIST_INCLUDE_DIR}")
endif(LIST_LIB)

########

#ajout de la librairie tree
add_library(rhyme SHARED rhyme.c rhyme.h )
#la librairie tree utilise la librairie list
target_link_libraries(rhyme tree parser list)



#Liste exécutables/tests
foreach (dir_name IN ITEMS rhyme)
	add_executable(test-${dir_name} test-${dir_name}.c)
	add_dependencies(test-${dir_name} rhyme)
	target_link_libraries(test-${dir_name} rhyme)
	add_test(test-${dir_name} ./test-${dir_name})
endforeach(dir_name)
#Autorisation tests
enable_testing()
