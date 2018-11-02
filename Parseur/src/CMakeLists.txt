cmake_minimum_required(VERSION 3.12)

project(fraction C)

add_executable(test-parseur parseur.c)


enable_testing()
add_test(test-parseur ./test-parseur)


