cmake_minimum_required (VERSION 3.5)
project (Symphonie C)

foreach(dir IN ITEMS list tree word parser rhyme)
	include_directories ("${PROJECT_SOURCE_DIR}/${dir}/src")
	add_subdirectory (${dir}/src) 
endforeach(dir)
 
# add the executable
add_executable (Symphonie Symphonie.c)
foreach(dir IN ITEMS list arbre_syll word parser rhyme)
	target_link_libraries (Symphonie ${dir})
endforeach(dir)
