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

foreach(name IN ITEMS list lock find lock_qs qs remove add_locked)
	add_executable("test-${name}" "test-${name}.c")
	add_dependencies("test-${name}" list)
	target_link_libraries("test-${name}" list)
	add_test("test-${name}" "./test-${name}")
	add_test("test-${name}-valgrind" "/usr/bin/valgrind" "--error-exitcode=42" "--leak-check=full" "./test-${name}")
endforeach(name)

