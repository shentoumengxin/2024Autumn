# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/zzh/CS219 Advanced Programming/lab9/build"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/zzh/CS219 Advanced Programming/lab9/build"

# Include any dependencies generated for this target.
include CMakeFiles/CandyBar2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CandyBar2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CandyBar2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CandyBar2.dir/flags.make

CMakeFiles/CandyBar2.dir/main.cpp.o: CMakeFiles/CandyBar2.dir/flags.make
CMakeFiles/CandyBar2.dir/main.cpp.o: main.cpp
CMakeFiles/CandyBar2.dir/main.cpp.o: CMakeFiles/CandyBar2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/zzh/CS219 Advanced Programming/lab9/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CandyBar2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CandyBar2.dir/main.cpp.o -MF CMakeFiles/CandyBar2.dir/main.cpp.o.d -o CMakeFiles/CandyBar2.dir/main.cpp.o -c "/home/zzh/CS219 Advanced Programming/lab9/build/main.cpp"

CMakeFiles/CandyBar2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CandyBar2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/zzh/CS219 Advanced Programming/lab9/build/main.cpp" > CMakeFiles/CandyBar2.dir/main.cpp.i

CMakeFiles/CandyBar2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CandyBar2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/zzh/CS219 Advanced Programming/lab9/build/main.cpp" -o CMakeFiles/CandyBar2.dir/main.cpp.s

CMakeFiles/CandyBar2.dir/candybar.cpp.o: CMakeFiles/CandyBar2.dir/flags.make
CMakeFiles/CandyBar2.dir/candybar.cpp.o: candybar.cpp
CMakeFiles/CandyBar2.dir/candybar.cpp.o: CMakeFiles/CandyBar2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/zzh/CS219 Advanced Programming/lab9/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CandyBar2.dir/candybar.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CandyBar2.dir/candybar.cpp.o -MF CMakeFiles/CandyBar2.dir/candybar.cpp.o.d -o CMakeFiles/CandyBar2.dir/candybar.cpp.o -c "/home/zzh/CS219 Advanced Programming/lab9/build/candybar.cpp"

CMakeFiles/CandyBar2.dir/candybar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CandyBar2.dir/candybar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/zzh/CS219 Advanced Programming/lab9/build/candybar.cpp" > CMakeFiles/CandyBar2.dir/candybar.cpp.i

CMakeFiles/CandyBar2.dir/candybar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CandyBar2.dir/candybar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/zzh/CS219 Advanced Programming/lab9/build/candybar.cpp" -o CMakeFiles/CandyBar2.dir/candybar.cpp.s

# Object files for target CandyBar2
CandyBar2_OBJECTS = \
"CMakeFiles/CandyBar2.dir/main.cpp.o" \
"CMakeFiles/CandyBar2.dir/candybar.cpp.o"

# External object files for target CandyBar2
CandyBar2_EXTERNAL_OBJECTS =

CandyBar2: CMakeFiles/CandyBar2.dir/main.cpp.o
CandyBar2: CMakeFiles/CandyBar2.dir/candybar.cpp.o
CandyBar2: CMakeFiles/CandyBar2.dir/build.make
CandyBar2: CMakeFiles/CandyBar2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/zzh/CS219 Advanced Programming/lab9/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CandyBar2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CandyBar2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CandyBar2.dir/build: CandyBar2
.PHONY : CMakeFiles/CandyBar2.dir/build

CMakeFiles/CandyBar2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CandyBar2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CandyBar2.dir/clean

CMakeFiles/CandyBar2.dir/depend:
	cd "/home/zzh/CS219 Advanced Programming/lab9/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/zzh/CS219 Advanced Programming/lab9/build" "/home/zzh/CS219 Advanced Programming/lab9/build" "/home/zzh/CS219 Advanced Programming/lab9/build" "/home/zzh/CS219 Advanced Programming/lab9/build" "/home/zzh/CS219 Advanced Programming/lab9/build/CMakeFiles/CandyBar2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CandyBar2.dir/depend

