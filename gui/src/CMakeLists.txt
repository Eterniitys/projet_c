cmake_minimum_required(VERSION 3.12)

project(graphic-interface C) # à renommée, on fait un vote ?

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})


#Liste exécutables
add_executable(glade glade.c)
TARGET_LINK_LIBRARIES(glade ${GTK3_LIBRARIES})

#Autorisation tests
#enable_testing()

#Liste tests
#add_test(test-parseur ./test-parseur)


