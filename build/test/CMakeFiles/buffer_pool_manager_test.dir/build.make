# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build

# Include any dependencies generated for this target.
include test/CMakeFiles/buffer_pool_manager_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/buffer_pool_manager_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/buffer_pool_manager_test.dir/flags.make

test/CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.o: test/CMakeFiles/buffer_pool_manager_test.dir/flags.make
test/CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.o: ../test/buffer/buffer_pool_manager_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.o"
	cd /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.o -c /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/test/buffer/buffer_pool_manager_test.cpp

test/CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.i"
	cd /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/test/buffer/buffer_pool_manager_test.cpp > CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.i

test/CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.s"
	cd /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/test/buffer/buffer_pool_manager_test.cpp -o CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.s

# Object files for target buffer_pool_manager_test
buffer_pool_manager_test_OBJECTS = \
"CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.o"

# External object files for target buffer_pool_manager_test
buffer_pool_manager_test_EXTERNAL_OBJECTS =

test/buffer_pool_manager_test: test/CMakeFiles/buffer_pool_manager_test.dir/buffer/buffer_pool_manager_test.cpp.o
test/buffer_pool_manager_test: test/CMakeFiles/buffer_pool_manager_test.dir/build.make
test/buffer_pool_manager_test: lib/libvtable.so
test/buffer_pool_manager_test: lib/libsqlite3.so
test/buffer_pool_manager_test: lib/libgtest.so
test/buffer_pool_manager_test: test/CMakeFiles/buffer_pool_manager_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable buffer_pool_manager_test"
	cd /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/buffer_pool_manager_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/buffer_pool_manager_test.dir/build: test/buffer_pool_manager_test

.PHONY : test/CMakeFiles/buffer_pool_manager_test.dir/build

test/CMakeFiles/buffer_pool_manager_test.dir/clean:
	cd /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build/test && $(CMAKE_COMMAND) -P CMakeFiles/buffer_pool_manager_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/buffer_pool_manager_test.dir/clean

test/CMakeFiles/buffer_pool_manager_test.dir/depend:
	cd /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/test /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build/test /home/HwHiAiUser/Desktop/database/hw02/scudb_proghw1_new/build/test/CMakeFiles/buffer_pool_manager_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/buffer_pool_manager_test.dir/depend

