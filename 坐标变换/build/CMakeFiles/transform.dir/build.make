# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/gky/tools/tools/坐标变换

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gky/tools/tools/坐标变换/build

# Include any dependencies generated for this target.
include CMakeFiles/transform.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/transform.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/transform.dir/flags.make

CMakeFiles/transform.dir/transform.cpp.o: CMakeFiles/transform.dir/flags.make
CMakeFiles/transform.dir/transform.cpp.o: ../transform.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gky/tools/tools/坐标变换/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/transform.dir/transform.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/transform.dir/transform.cpp.o -c /home/gky/tools/tools/坐标变换/transform.cpp

CMakeFiles/transform.dir/transform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/transform.dir/transform.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gky/tools/tools/坐标变换/transform.cpp > CMakeFiles/transform.dir/transform.cpp.i

CMakeFiles/transform.dir/transform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/transform.dir/transform.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gky/tools/tools/坐标变换/transform.cpp -o CMakeFiles/transform.dir/transform.cpp.s

CMakeFiles/transform.dir/transform.cpp.o.requires:

.PHONY : CMakeFiles/transform.dir/transform.cpp.o.requires

CMakeFiles/transform.dir/transform.cpp.o.provides: CMakeFiles/transform.dir/transform.cpp.o.requires
	$(MAKE) -f CMakeFiles/transform.dir/build.make CMakeFiles/transform.dir/transform.cpp.o.provides.build
.PHONY : CMakeFiles/transform.dir/transform.cpp.o.provides

CMakeFiles/transform.dir/transform.cpp.o.provides.build: CMakeFiles/transform.dir/transform.cpp.o


# Object files for target transform
transform_OBJECTS = \
"CMakeFiles/transform.dir/transform.cpp.o"

# External object files for target transform
transform_EXTERNAL_OBJECTS =

transform: CMakeFiles/transform.dir/transform.cpp.o
transform: CMakeFiles/transform.dir/build.make
transform: CMakeFiles/transform.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gky/tools/tools/坐标变换/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable transform"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/transform.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/transform.dir/build: transform

.PHONY : CMakeFiles/transform.dir/build

CMakeFiles/transform.dir/requires: CMakeFiles/transform.dir/transform.cpp.o.requires

.PHONY : CMakeFiles/transform.dir/requires

CMakeFiles/transform.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/transform.dir/cmake_clean.cmake
.PHONY : CMakeFiles/transform.dir/clean

CMakeFiles/transform.dir/depend:
	cd /home/gky/tools/tools/坐标变换/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gky/tools/tools/坐标变换 /home/gky/tools/tools/坐标变换 /home/gky/tools/tools/坐标变换/build /home/gky/tools/tools/坐标变换/build /home/gky/tools/tools/坐标变换/build/CMakeFiles/transform.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/transform.dir/depend

