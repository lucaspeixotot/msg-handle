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

# Include any dependencies generated for this target.
include zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/depend.make

# Include the progress variables for this target.
include zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/progress.make

# Include the compile flags for this target's objects.
include zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/flags.make

zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/uuid.c.obj: zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/flags.make
zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/uuid.c.obj: /home/lucas/Zephyr/zephyr-1-13-99/subsys/bluetooth/host/uuid.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/Projects/msg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/uuid.c.obj"
	cd /home/lucas/Projects/msg/build/zephyr/subsys/bluetooth/host && ccache /home/lucas/Zephyr/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/arm-zephyr-eabi/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/subsys__bluetooth__host.dir/uuid.c.obj   -c /home/lucas/Zephyr/zephyr-1-13-99/subsys/bluetooth/host/uuid.c

zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/uuid.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/subsys__bluetooth__host.dir/uuid.c.i"
	cd /home/lucas/Projects/msg/build/zephyr/subsys/bluetooth/host && /home/lucas/Zephyr/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/arm-zephyr-eabi/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lucas/Zephyr/zephyr-1-13-99/subsys/bluetooth/host/uuid.c > CMakeFiles/subsys__bluetooth__host.dir/uuid.c.i

zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/uuid.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/subsys__bluetooth__host.dir/uuid.c.s"
	cd /home/lucas/Projects/msg/build/zephyr/subsys/bluetooth/host && /home/lucas/Zephyr/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/arm-zephyr-eabi/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lucas/Zephyr/zephyr-1-13-99/subsys/bluetooth/host/uuid.c -o CMakeFiles/subsys__bluetooth__host.dir/uuid.c.s

zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.obj: zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/flags.make
zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.obj: /home/lucas/Zephyr/zephyr-1-13-99/subsys/bluetooth/host/hci_core.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/Projects/msg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.obj"
	cd /home/lucas/Projects/msg/build/zephyr/subsys/bluetooth/host && ccache /home/lucas/Zephyr/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/arm-zephyr-eabi/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.obj   -c /home/lucas/Zephyr/zephyr-1-13-99/subsys/bluetooth/host/hci_core.c

zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.i"
	cd /home/lucas/Projects/msg/build/zephyr/subsys/bluetooth/host && /home/lucas/Zephyr/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/arm-zephyr-eabi/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lucas/Zephyr/zephyr-1-13-99/subsys/bluetooth/host/hci_core.c > CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.i

zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.s"
	cd /home/lucas/Projects/msg/build/zephyr/subsys/bluetooth/host && /home/lucas/Zephyr/zephyr-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/arm-zephyr-eabi/arm-zephyr-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lucas/Zephyr/zephyr-1-13-99/subsys/bluetooth/host/hci_core.c -o CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.s

# Object files for target subsys__bluetooth__host
subsys__bluetooth__host_OBJECTS = \
"CMakeFiles/subsys__bluetooth__host.dir/uuid.c.obj" \
"CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.obj"

# External object files for target subsys__bluetooth__host
subsys__bluetooth__host_EXTERNAL_OBJECTS =

zephyr/subsys/bluetooth/host/libsubsys__bluetooth__host.a: zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/uuid.c.obj
zephyr/subsys/bluetooth/host/libsubsys__bluetooth__host.a: zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/hci_core.c.obj
zephyr/subsys/bluetooth/host/libsubsys__bluetooth__host.a: zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/build.make
zephyr/subsys/bluetooth/host/libsubsys__bluetooth__host.a: zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lucas/Projects/msg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libsubsys__bluetooth__host.a"
	cd /home/lucas/Projects/msg/build/zephyr/subsys/bluetooth/host && $(CMAKE_COMMAND) -P CMakeFiles/subsys__bluetooth__host.dir/cmake_clean_target.cmake
	cd /home/lucas/Projects/msg/build/zephyr/subsys/bluetooth/host && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/subsys__bluetooth__host.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/build: zephyr/subsys/bluetooth/host/libsubsys__bluetooth__host.a

.PHONY : zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/build

zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/clean:
	cd /home/lucas/Projects/msg/build/zephyr/subsys/bluetooth/host && $(CMAKE_COMMAND) -P CMakeFiles/subsys__bluetooth__host.dir/cmake_clean.cmake
.PHONY : zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/clean

zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/depend:
	cd /home/lucas/Projects/msg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucas/Projects/msg /home/lucas/Zephyr/zephyr-1-13-99/subsys/bluetooth/host /home/lucas/Projects/msg/build /home/lucas/Projects/msg/build/zephyr/subsys/bluetooth/host /home/lucas/Projects/msg/build/zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : zephyr/subsys/bluetooth/host/CMakeFiles/subsys__bluetooth__host.dir/depend

