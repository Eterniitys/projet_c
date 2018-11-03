cmake_minimum_required(VERSION 3.12)

project(fraction C) # à renommée, on fait un vote ?

#Liste exécutables
add_executable(test-parseur test-parseur.c parseur.c parseur.h)

#Autorisation tests
enable_testing()

#Liste tests
add_test(test-parseur ./test-parseur)


