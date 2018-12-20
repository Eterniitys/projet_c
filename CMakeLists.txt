cmake_minimum_required (VERSION 3.5)
project (Symphonie C)

find_package(FlawFinder)
enable_flaw_finder()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set (CMAKE_C_FLAGS "-rdynamic")
set(DIR hash list tree word parser rhyme syllabification phonetics)
set(LIBS hash list tree parser rhyme syllabification phonetics)
set(FILES window.glade symphonie.png Lexique382.csv)





foreach(dir IN LISTS DIR)
	include_directories ("${PROJECT_SOURCE_DIR}/${dir}/src")
	add_subdirectory (${dir}/src) 
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


# add the executable
add_executable (symphonie symphonie.c)

foreach(lib IN LISTS LIBS)
	target_link_libraries (symphonie ${lib})
endforeach(lib)
TARGET_LINK_LIBRARIES(symphonie ${GTK3_LIBRARIES})


install(TARGETS symphonie
	RUNTIME DESTINATION bin
)

# Copy files
foreach(file IN LISTS FILES)
	configure_file("${PROJECT_SOURCE_DIR}/${file}" "${CMAKE_CURRENT_BINARY_DIR}/${file}" COPYONLY)
endforeach(file)





