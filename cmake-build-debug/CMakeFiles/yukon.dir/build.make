# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "/Users/tobiasmaneschijn/Library/Application Support/JetBrains/Toolbox/apps/CLion-ARM/ch-0/211.6693.114/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/tobiasmaneschijn/Library/Application Support/JetBrains/Toolbox/apps/CLion-ARM/ch-0/211.6693.114/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tobiasmaneschijn/Documents/GitHub/yukon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tobiasmaneschijn/Documents/GitHub/yukon/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/yukon.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/yukon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/yukon.dir/flags.make

CMakeFiles/yukon.dir/main.c.o: CMakeFiles/yukon.dir/flags.make
CMakeFiles/yukon.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tobiasmaneschijn/Documents/GitHub/yukon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/yukon.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/yukon.dir/main.c.o -c /Users/tobiasmaneschijn/Documents/GitHub/yukon/main.c

CMakeFiles/yukon.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/yukon.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tobiasmaneschijn/Documents/GitHub/yukon/main.c > CMakeFiles/yukon.dir/main.c.i

CMakeFiles/yukon.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/yukon.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tobiasmaneschijn/Documents/GitHub/yukon/main.c -o CMakeFiles/yukon.dir/main.c.s

# Object files for target yukon
yukon_OBJECTS = \
"CMakeFiles/yukon.dir/main.c.o"

# External object files for target yukon
yukon_EXTERNAL_OBJECTS =

yukon: CMakeFiles/yukon.dir/main.c.o
yukon: CMakeFiles/yukon.dir/build.make
yukon: CMakeFiles/yukon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tobiasmaneschijn/Documents/GitHub/yukon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable yukon"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yukon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/yukon.dir/build: yukon

.PHONY : CMakeFiles/yukon.dir/build

CMakeFiles/yukon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/yukon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/yukon.dir/clean

CMakeFiles/yukon.dir/depend:
	cd /Users/tobiasmaneschijn/Documents/GitHub/yukon/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tobiasmaneschijn/Documents/GitHub/yukon /Users/tobiasmaneschijn/Documents/GitHub/yukon /Users/tobiasmaneschijn/Documents/GitHub/yukon/cmake-build-debug /Users/tobiasmaneschijn/Documents/GitHub/yukon/cmake-build-debug /Users/tobiasmaneschijn/Documents/GitHub/yukon/cmake-build-debug/CMakeFiles/yukon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/yukon.dir/depend

