cmake_minimum_required (VERSION 3.5)
project (Symphonie C)

set(DIR hash list tree word parser rhyme syllabification)

foreach(dir IN LISTS DIR)
	include_directories ("${PROJECT_SOURCE_DIR}/${dir}/src")
	add_subdirectory (${dir}/src) 
endforeach(dir)
 
# add the executable
add_executable (symphonie symphonie.c)
foreach(dir IN LISTS DIR)
	target_link_libraries (symphonie ${dir})
endforeach(dir)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

TARGET_LINK_LIBRARIES(symphonie ${GTK3_LIBRARIES})
