cmake_minimum_required(VERSION 3.5)

project(parseur C) 


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

add_executable(test-parseur test-parseur.c parseur.c parseur.h)
#add_dependencies(test-parseur word)
target_link_libraries(test-parseur word)

#Autorisation tests
enable_testing()

#Liste tests
add_test(test-parseur ./test-parseur)


