# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/build"

# Include any dependencies generated for this target.
include CMakeFiles/test-parseur.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test-parseur.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test-parseur.dir/flags.make

CMakeFiles/test-parseur.dir/parseur.c.o: CMakeFiles/test-parseur.dir/flags.make
CMakeFiles/test-parseur.dir/parseur.c.o: /win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation\ C/projet/projet_c/src/parseur.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test-parseur.dir/parseur.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-parseur.dir/parseur.c.o   -c "/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/src/parseur.c"

CMakeFiles/test-parseur.dir/parseur.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-parseur.dir/parseur.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/src/parseur.c" > CMakeFiles/test-parseur.dir/parseur.c.i

CMakeFiles/test-parseur.dir/parseur.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-parseur.dir/parseur.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/src/parseur.c" -o CMakeFiles/test-parseur.dir/parseur.c.s

# Object files for target test-parseur
test__parseur_OBJECTS = \
"CMakeFiles/test-parseur.dir/parseur.c.o"

# External object files for target test-parseur
test__parseur_EXTERNAL_OBJECTS =

test-parseur: CMakeFiles/test-parseur.dir/parseur.c.o
test-parseur: CMakeFiles/test-parseur.dir/build.make
test-parseur: CMakeFiles/test-parseur.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test-parseur"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-parseur.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test-parseur.dir/build: test-parseur

.PHONY : CMakeFiles/test-parseur.dir/build

CMakeFiles/test-parseur.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test-parseur.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test-parseur.dir/clean

CMakeFiles/test-parseur.dir/depend:
	cd "/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/src" "/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/src" "/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/build" "/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/build" "/win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/projet/projet_c/build/CMakeFiles/test-parseur.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test-parseur.dir/depend

