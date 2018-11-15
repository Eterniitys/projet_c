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

#ajout de la librairie parseur
add_library(parseur SHARED parseur.c parseur.h)
#la librairie parseur utilise la librairie word
target_link_libraries(parseur word)

#fichiers de destination
install(
	TARGETS parseur
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
)
install(
	FILES parseur.h
	DESTINATION include
)


add_executable(test-parseur test-parseur.c)
add_dependencies(test-parseur parseur)
target_link_libraries(test-parseur parseur)

#Autorisation tests
enable_testing()

add_test(test-parseur ./test-parseur)


