# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/138/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/138/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hotash/CLionProjects/stratagem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hotash/CLionProjects/stratagem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stratagem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stratagem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stratagem.dir/flags.make

CMakeFiles/stratagem.dir/main.cpp.o: CMakeFiles/stratagem.dir/flags.make
CMakeFiles/stratagem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hotash/CLionProjects/stratagem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stratagem.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stratagem.dir/main.cpp.o -c /home/hotash/CLionProjects/stratagem/main.cpp

CMakeFiles/stratagem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stratagem.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hotash/CLionProjects/stratagem/main.cpp > CMakeFiles/stratagem.dir/main.cpp.i

CMakeFiles/stratagem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stratagem.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hotash/CLionProjects/stratagem/main.cpp -o CMakeFiles/stratagem.dir/main.cpp.s

# Object files for target stratagem
stratagem_OBJECTS = \
"CMakeFiles/stratagem.dir/main.cpp.o"

# External object files for target stratagem
stratagem_EXTERNAL_OBJECTS =

stratagem: CMakeFiles/stratagem.dir/main.cpp.o
stratagem: CMakeFiles/stratagem.dir/build.make
stratagem: ../SFML/lib/libsfml-system.so
stratagem: ../SFML/lib/libsfml-window.so
stratagem: ../SFML/lib/libsfml-graphics.so
stratagem: ../SFML/lib/libsfml-network.so
stratagem: ../SFML/lib/libsfml-audio.so
stratagem: CMakeFiles/stratagem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hotash/CLionProjects/stratagem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stratagem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stratagem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stratagem.dir/build: stratagem

.PHONY : CMakeFiles/stratagem.dir/build

CMakeFiles/stratagem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stratagem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stratagem.dir/clean

CMakeFiles/stratagem.dir/depend:
	cd /home/hotash/CLionProjects/stratagem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hotash/CLionProjects/stratagem /home/hotash/CLionProjects/stratagem /home/hotash/CLionProjects/stratagem/cmake-build-debug /home/hotash/CLionProjects/stratagem/cmake-build-debug /home/hotash/CLionProjects/stratagem/cmake-build-debug/CMakeFiles/stratagem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stratagem.dir/depend

