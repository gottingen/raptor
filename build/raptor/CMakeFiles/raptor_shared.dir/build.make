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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /Users/liyinbin/github/gottingen/raptor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liyinbin/github/gottingen/raptor/build

# Include any dependencies generated for this target.
include raptor/CMakeFiles/raptor_shared.dir/depend.make

# Include the progress variables for this target.
include raptor/CMakeFiles/raptor_shared.dir/progress.make

# Include the compile flags for this target's objects.
include raptor/CMakeFiles/raptor_shared.dir/flags.make

raptor/CMakeFiles/raptor_shared.dir/engine/factory.cc.o: raptor/CMakeFiles/raptor_shared.dir/flags.make
raptor/CMakeFiles/raptor_shared.dir/engine/factory.cc.o: ../raptor/engine/factory.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liyinbin/github/gottingen/raptor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object raptor/CMakeFiles/raptor_shared.dir/engine/factory.cc.o"
	cd /Users/liyinbin/github/gottingen/raptor/build/raptor && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raptor_shared.dir/engine/factory.cc.o -c /Users/liyinbin/github/gottingen/raptor/raptor/engine/factory.cc

raptor/CMakeFiles/raptor_shared.dir/engine/factory.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raptor_shared.dir/engine/factory.cc.i"
	cd /Users/liyinbin/github/gottingen/raptor/build/raptor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liyinbin/github/gottingen/raptor/raptor/engine/factory.cc > CMakeFiles/raptor_shared.dir/engine/factory.cc.i

raptor/CMakeFiles/raptor_shared.dir/engine/factory.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raptor_shared.dir/engine/factory.cc.s"
	cd /Users/liyinbin/github/gottingen/raptor/build/raptor && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liyinbin/github/gottingen/raptor/raptor/engine/factory.cc -o CMakeFiles/raptor_shared.dir/engine/factory.cc.s

# Object files for target raptor_shared
raptor_shared_OBJECTS = \
"CMakeFiles/raptor_shared.dir/engine/factory.cc.o"

# External object files for target raptor_shared
raptor_shared_EXTERNAL_OBJECTS =

lib/libraptor.0.1.0.dylib: raptor/CMakeFiles/raptor_shared.dir/engine/factory.cc.o
lib/libraptor.0.1.0.dylib: raptor/CMakeFiles/raptor_shared.dir/build.make
lib/libraptor.0.1.0.dylib: raptor/CMakeFiles/raptor_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liyinbin/github/gottingen/raptor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../lib/libraptor.dylib"
	cd /Users/liyinbin/github/gottingen/raptor/build/raptor && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raptor_shared.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/liyinbin/github/gottingen/raptor/build/raptor && $(CMAKE_COMMAND) -E cmake_symlink_library ../lib/libraptor.0.1.0.dylib ../lib/libraptor.0.dylib ../lib/libraptor.dylib

lib/libraptor.0.dylib: lib/libraptor.0.1.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libraptor.0.dylib

lib/libraptor.dylib: lib/libraptor.0.1.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libraptor.dylib

# Rule to build all files generated by this target.
raptor/CMakeFiles/raptor_shared.dir/build: lib/libraptor.dylib

.PHONY : raptor/CMakeFiles/raptor_shared.dir/build

raptor/CMakeFiles/raptor_shared.dir/clean:
	cd /Users/liyinbin/github/gottingen/raptor/build/raptor && $(CMAKE_COMMAND) -P CMakeFiles/raptor_shared.dir/cmake_clean.cmake
.PHONY : raptor/CMakeFiles/raptor_shared.dir/clean

raptor/CMakeFiles/raptor_shared.dir/depend:
	cd /Users/liyinbin/github/gottingen/raptor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liyinbin/github/gottingen/raptor /Users/liyinbin/github/gottingen/raptor/raptor /Users/liyinbin/github/gottingen/raptor/build /Users/liyinbin/github/gottingen/raptor/build/raptor /Users/liyinbin/github/gottingen/raptor/build/raptor/CMakeFiles/raptor_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : raptor/CMakeFiles/raptor_shared.dir/depend

