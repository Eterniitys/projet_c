cmake_minimum_required(VERSION 3.5)

project(projet_c) # à renommée, on fait un vote ?

#Liste exécutables
add_executable(test-rhyme test-rhyme.c rhyme.c rhyme.h)

#Autorisation tests
enable_testing()

#Liste tests
add_test(test-rhyme ./test-rhyme)
