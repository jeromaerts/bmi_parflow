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

# Include any dependencies generated for this target.
include heat/CMakeFiles/bmiheatc.dir/depend.make

# Include the progress variables for this target.
include heat/CMakeFiles/bmiheatc.dir/progress.make

# Include the compile flags for this target's objects.
include heat/CMakeFiles/bmiheatc.dir/flags.make

heat/CMakeFiles/bmiheatc.dir/bmi_heat.c.o: heat/CMakeFiles/bmiheatc.dir/flags.make
heat/CMakeFiles/bmiheatc.dir/bmi_heat.c.o: ../heat/bmi_heat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jerom/bmi-example-c/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object heat/CMakeFiles/bmiheatc.dir/bmi_heat.c.o"
	cd /home/jerom/bmi-example-c/_build/heat && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmiheatc.dir/bmi_heat.c.o   -c /home/jerom/bmi-example-c/heat/bmi_heat.c

heat/CMakeFiles/bmiheatc.dir/bmi_heat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmiheatc.dir/bmi_heat.c.i"
	cd /home/jerom/bmi-example-c/_build/heat && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jerom/bmi-example-c/heat/bmi_heat.c > CMakeFiles/bmiheatc.dir/bmi_heat.c.i

heat/CMakeFiles/bmiheatc.dir/bmi_heat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmiheatc.dir/bmi_heat.c.s"
	cd /home/jerom/bmi-example-c/_build/heat && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jerom/bmi-example-c/heat/bmi_heat.c -o CMakeFiles/bmiheatc.dir/bmi_heat.c.s

heat/CMakeFiles/bmiheatc.dir/heat.c.o: heat/CMakeFiles/bmiheatc.dir/flags.make
heat/CMakeFiles/bmiheatc.dir/heat.c.o: ../heat/heat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jerom/bmi-example-c/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object heat/CMakeFiles/bmiheatc.dir/heat.c.o"
	cd /home/jerom/bmi-example-c/_build/heat && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmiheatc.dir/heat.c.o   -c /home/jerom/bmi-example-c/heat/heat.c

heat/CMakeFiles/bmiheatc.dir/heat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmiheatc.dir/heat.c.i"
	cd /home/jerom/bmi-example-c/_build/heat && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jerom/bmi-example-c/heat/heat.c > CMakeFiles/bmiheatc.dir/heat.c.i

heat/CMakeFiles/bmiheatc.dir/heat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmiheatc.dir/heat.c.s"
	cd /home/jerom/bmi-example-c/_build/heat && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jerom/bmi-example-c/heat/heat.c -o CMakeFiles/bmiheatc.dir/heat.c.s

# Object files for target bmiheatc
bmiheatc_OBJECTS = \
"CMakeFiles/bmiheatc.dir/bmi_heat.c.o" \
"CMakeFiles/bmiheatc.dir/heat.c.o"

# External object files for target bmiheatc
bmiheatc_EXTERNAL_OBJECTS =

heat/libbmiheatc.so: heat/CMakeFiles/bmiheatc.dir/bmi_heat.c.o
heat/libbmiheatc.so: heat/CMakeFiles/bmiheatc.dir/heat.c.o
heat/libbmiheatc.so: heat/CMakeFiles/bmiheatc.dir/build.make
heat/libbmiheatc.so: heat/CMakeFiles/bmiheatc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jerom/bmi-example-c/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library libbmiheatc.so"
	cd /home/jerom/bmi-example-c/_build/heat && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bmiheatc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
heat/CMakeFiles/bmiheatc.dir/build: heat/libbmiheatc.so

.PHONY : heat/CMakeFiles/bmiheatc.dir/build

heat/CMakeFiles/bmiheatc.dir/clean:
	cd /home/jerom/bmi-example-c/_build/heat && $(CMAKE_COMMAND) -P CMakeFiles/bmiheatc.dir/cmake_clean.cmake
.PHONY : heat/CMakeFiles/bmiheatc.dir/clean

heat/CMakeFiles/bmiheatc.dir/depend:
	cd /home/jerom/bmi-example-c/_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jerom/bmi-example-c /home/jerom/bmi-example-c/heat /home/jerom/bmi-example-c/_build /home/jerom/bmi-example-c/_build/heat /home/jerom/bmi-example-c/_build/heat/CMakeFiles/bmiheatc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : heat/CMakeFiles/bmiheatc.dir/depend

