# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lucas/Projects/msg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucas/Projects/msg/build

# Utility rule file for code_data_relocation_target.

# Include the progress variables for this target.
include CMakeFiles/code_data_relocation_target.dir/progress.make

code_data_relocation_target: CMakeFiles/code_data_relocation_target.dir/build.make

.PHONY : code_data_relocation_target

# Rule to build all files generated by this target.
CMakeFiles/code_data_relocation_target.dir/build: code_data_relocation_target

.PHONY : CMakeFiles/code_data_relocation_target.dir/build

CMakeFiles/code_data_relocation_target.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/code_data_relocation_target.dir/cmake_clean.cmake
.PHONY : CMakeFiles/code_data_relocation_target.dir/clean

CMakeFiles/code_data_relocation_target.dir/depend:
	cd /home/lucas/Projects/msg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucas/Projects/msg /home/lucas/Projects/msg /home/lucas/Projects/msg/build /home/lucas/Projects/msg/build /home/lucas/Projects/msg/build/CMakeFiles/code_data_relocation_target.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/code_data_relocation_target.dir/depend

