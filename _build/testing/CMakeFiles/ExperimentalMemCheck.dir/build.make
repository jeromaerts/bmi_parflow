# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/jerom/bmi-example-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jerom/bmi-example-c/_build

# Utility rule file for ExperimentalMemCheck.

# Include the progress variables for this target.
include testing/CMakeFiles/ExperimentalMemCheck.dir/progress.make

testing/CMakeFiles/ExperimentalMemCheck:
	cd /home/jerom/bmi-example-c/_build/testing && /usr/bin/ctest -D ExperimentalMemCheck

ExperimentalMemCheck: testing/CMakeFiles/ExperimentalMemCheck
ExperimentalMemCheck: testing/CMakeFiles/ExperimentalMemCheck.dir/build.make

.PHONY : ExperimentalMemCheck

# Rule to build all files generated by this target.
testing/CMakeFiles/ExperimentalMemCheck.dir/build: ExperimentalMemCheck

.PHONY : testing/CMakeFiles/ExperimentalMemCheck.dir/build

testing/CMakeFiles/ExperimentalMemCheck.dir/clean:
	cd /home/jerom/bmi-example-c/_build/testing && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalMemCheck.dir/cmake_clean.cmake
.PHONY : testing/CMakeFiles/ExperimentalMemCheck.dir/clean

testing/CMakeFiles/ExperimentalMemCheck.dir/depend:
	cd /home/jerom/bmi-example-c/_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jerom/bmi-example-c /home/jerom/bmi-example-c/testing /home/jerom/bmi-example-c/_build /home/jerom/bmi-example-c/_build/testing /home/jerom/bmi-example-c/_build/testing/CMakeFiles/ExperimentalMemCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : testing/CMakeFiles/ExperimentalMemCheck.dir/depend

