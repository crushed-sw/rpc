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
CMAKE_SOURCE_DIR = /home/crushed/cpp/rpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crushed/cpp/rpc/build

# Include any dependencies generated for this target.
include example/friendcaller/CMakeFiles/friendcustomer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include example/friendcaller/CMakeFiles/friendcustomer.dir/compiler_depend.make

# Include the progress variables for this target.
include example/friendcaller/CMakeFiles/friendcustomer.dir/progress.make

# Include the compile flags for this target's objects.
include example/friendcaller/CMakeFiles/friendcustomer.dir/flags.make

example/friendcaller/CMakeFiles/friendcustomer.dir/callFriendService.cpp.o: example/friendcaller/CMakeFiles/friendcustomer.dir/flags.make
example/friendcaller/CMakeFiles/friendcustomer.dir/callFriendService.cpp.o: ../example/friendcaller/callFriendService.cpp
example/friendcaller/CMakeFiles/friendcustomer.dir/callFriendService.cpp.o: example/friendcaller/CMakeFiles/friendcustomer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crushed/cpp/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/friendcaller/CMakeFiles/friendcustomer.dir/callFriendService.cpp.o"
	cd /home/crushed/cpp/rpc/build/example/friendcaller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/friendcaller/CMakeFiles/friendcustomer.dir/callFriendService.cpp.o -MF CMakeFiles/friendcustomer.dir/callFriendService.cpp.o.d -o CMakeFiles/friendcustomer.dir/callFriendService.cpp.o -c /home/crushed/cpp/rpc/example/friendcaller/callFriendService.cpp

example/friendcaller/CMakeFiles/friendcustomer.dir/callFriendService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/friendcustomer.dir/callFriendService.cpp.i"
	cd /home/crushed/cpp/rpc/build/example/friendcaller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crushed/cpp/rpc/example/friendcaller/callFriendService.cpp > CMakeFiles/friendcustomer.dir/callFriendService.cpp.i

example/friendcaller/CMakeFiles/friendcustomer.dir/callFriendService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/friendcustomer.dir/callFriendService.cpp.s"
	cd /home/crushed/cpp/rpc/build/example/friendcaller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crushed/cpp/rpc/example/friendcaller/callFriendService.cpp -o CMakeFiles/friendcustomer.dir/callFriendService.cpp.s

example/friendcaller/CMakeFiles/friendcustomer.dir/__/friend.pb.cc.o: example/friendcaller/CMakeFiles/friendcustomer.dir/flags.make
example/friendcaller/CMakeFiles/friendcustomer.dir/__/friend.pb.cc.o: ../example/friend.pb.cc
example/friendcaller/CMakeFiles/friendcustomer.dir/__/friend.pb.cc.o: example/friendcaller/CMakeFiles/friendcustomer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crushed/cpp/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object example/friendcaller/CMakeFiles/friendcustomer.dir/__/friend.pb.cc.o"
	cd /home/crushed/cpp/rpc/build/example/friendcaller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT example/friendcaller/CMakeFiles/friendcustomer.dir/__/friend.pb.cc.o -MF CMakeFiles/friendcustomer.dir/__/friend.pb.cc.o.d -o CMakeFiles/friendcustomer.dir/__/friend.pb.cc.o -c /home/crushed/cpp/rpc/example/friend.pb.cc

example/friendcaller/CMakeFiles/friendcustomer.dir/__/friend.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/friendcustomer.dir/__/friend.pb.cc.i"
	cd /home/crushed/cpp/rpc/build/example/friendcaller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crushed/cpp/rpc/example/friend.pb.cc > CMakeFiles/friendcustomer.dir/__/friend.pb.cc.i

example/friendcaller/CMakeFiles/friendcustomer.dir/__/friend.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/friendcustomer.dir/__/friend.pb.cc.s"
	cd /home/crushed/cpp/rpc/build/example/friendcaller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crushed/cpp/rpc/example/friend.pb.cc -o CMakeFiles/friendcustomer.dir/__/friend.pb.cc.s

# Object files for target friendcustomer
friendcustomer_OBJECTS = \
"CMakeFiles/friendcustomer.dir/callFriendService.cpp.o" \
"CMakeFiles/friendcustomer.dir/__/friend.pb.cc.o"

# External object files for target friendcustomer
friendcustomer_EXTERNAL_OBJECTS =

../bin/friendcustomer: example/friendcaller/CMakeFiles/friendcustomer.dir/callFriendService.cpp.o
../bin/friendcustomer: example/friendcaller/CMakeFiles/friendcustomer.dir/__/friend.pb.cc.o
../bin/friendcustomer: example/friendcaller/CMakeFiles/friendcustomer.dir/build.make
../bin/friendcustomer: ../lib/librpc.a
../bin/friendcustomer: example/friendcaller/CMakeFiles/friendcustomer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/crushed/cpp/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../bin/friendcustomer"
	cd /home/crushed/cpp/rpc/build/example/friendcaller && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/friendcustomer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/friendcaller/CMakeFiles/friendcustomer.dir/build: ../bin/friendcustomer
.PHONY : example/friendcaller/CMakeFiles/friendcustomer.dir/build

example/friendcaller/CMakeFiles/friendcustomer.dir/clean:
	cd /home/crushed/cpp/rpc/build/example/friendcaller && $(CMAKE_COMMAND) -P CMakeFiles/friendcustomer.dir/cmake_clean.cmake
.PHONY : example/friendcaller/CMakeFiles/friendcustomer.dir/clean

example/friendcaller/CMakeFiles/friendcustomer.dir/depend:
	cd /home/crushed/cpp/rpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crushed/cpp/rpc /home/crushed/cpp/rpc/example/friendcaller /home/crushed/cpp/rpc/build /home/crushed/cpp/rpc/build/example/friendcaller /home/crushed/cpp/rpc/build/example/friendcaller/CMakeFiles/friendcustomer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/friendcaller/CMakeFiles/friendcustomer.dir/depend
