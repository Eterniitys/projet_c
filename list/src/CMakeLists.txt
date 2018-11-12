cmake_minimum_required(VERSION 3.0)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

project(List C)

add_library(list SHARED list.c list.h)

install(
	TARGETS list
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
)

install(
	FILES list.h
	DESTINATION include
)

# Ajout d'un fichier de configuration de type pkgconfig
#configure_file(
#	${CMAKE_CURRENT_SOURCE_DIR}/fraction.pc.in
#	${CMAKE_CURRENT_BINARY_DIR}/fraction.pc
#	@ONLY
#)
#install(
#	FILES ${CMAKE_CURRENT_BINARY_DIR}/fraction.pc
#	DESTINATION share/pkgconfig
#	COMPONENT "PkgConfig"
#)

# Ajout d'un fichier de configuration de type cmake
#include(CMakePackageConfigHelpers)
#configure_package_config_file(
#	${CMAKE_CURRENT_SOURCE_DIR}/FractionConfig.cmake.in
#	${CMAKE_CURRENT_BINARY_DIR}/FractionConfig.cmake
#	INSTALL_DESTINATION cmake
#)
#$install(
#	FILES ${CMAKE_CURRENT_BINARY_DIR}/FractionConfig.cmake
#	DESTINATION cmake
#)


enable_testing()

add_executable(test-list test-list.c)
add_dependencies(test-list list)
target_link_libraries(test-list list)
add_test(test-list ./test-list)

add_executable(test-lock test-lock.c)
add_dependencies(test-lock list)
target_link_libraries(test-lock list)
add_test(test-lock ./test-lock)

add_executable(test-find test-find.c)
add_dependencies(test-find list)
target_link_libraries(test-find list)
add_test(test-find ./test-find)

