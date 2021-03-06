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
CMAKE_SOURCE_DIR = /mnt/e/cppProjects/007_cppgrpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/cppProjects/007_cppgrpc/build

# Include any dependencies generated for this target.
include CMakeFiles/hw_grpc_proto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw_grpc_proto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw_grpc_proto.dir/flags.make

helloworld.pb.cc: ../protos/helloworld.proto
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/e/cppProjects/007_cppgrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating helloworld.pb.cc, helloworld.pb.h, helloworld.grpc.pb.cc, helloworld.grpc.pb.h"
	/home/lucas/.local/bin/protoc-3.11.2.0 --grpc_out /mnt/e/cppProjects/007_cppgrpc/build --cpp_out /mnt/e/cppProjects/007_cppgrpc/build -I /mnt/e/cppProjects/007_cppgrpc/protos --plugin=protoc-gen-grpc="/home/lucas/.local/bin/grpc_cpp_plugin" /mnt/e/cppProjects/007_cppgrpc/protos/helloworld.proto

helloworld.pb.h: helloworld.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate helloworld.pb.h

helloworld.grpc.pb.cc: helloworld.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate helloworld.grpc.pb.cc

helloworld.grpc.pb.h: helloworld.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate helloworld.grpc.pb.h

CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.o: CMakeFiles/hw_grpc_proto.dir/flags.make
CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.o: helloworld.grpc.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/cppProjects/007_cppgrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.o"
	/bin/x86_64-linux-gnu-g++-4.8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.o -c /mnt/e/cppProjects/007_cppgrpc/build/helloworld.grpc.pb.cc

CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.i"
	/bin/x86_64-linux-gnu-g++-4.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/cppProjects/007_cppgrpc/build/helloworld.grpc.pb.cc > CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.i

CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.s"
	/bin/x86_64-linux-gnu-g++-4.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/cppProjects/007_cppgrpc/build/helloworld.grpc.pb.cc -o CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.s

CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.o: CMakeFiles/hw_grpc_proto.dir/flags.make
CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.o: helloworld.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/cppProjects/007_cppgrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.o"
	/bin/x86_64-linux-gnu-g++-4.8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.o -c /mnt/e/cppProjects/007_cppgrpc/build/helloworld.pb.cc

CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.i"
	/bin/x86_64-linux-gnu-g++-4.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/cppProjects/007_cppgrpc/build/helloworld.pb.cc > CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.i

CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.s"
	/bin/x86_64-linux-gnu-g++-4.8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/cppProjects/007_cppgrpc/build/helloworld.pb.cc -o CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.s

# Object files for target hw_grpc_proto
hw_grpc_proto_OBJECTS = \
"CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.o" \
"CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.o"

# External object files for target hw_grpc_proto
hw_grpc_proto_EXTERNAL_OBJECTS =

libhw_grpc_proto.a: CMakeFiles/hw_grpc_proto.dir/helloworld.grpc.pb.cc.o
libhw_grpc_proto.a: CMakeFiles/hw_grpc_proto.dir/helloworld.pb.cc.o
libhw_grpc_proto.a: CMakeFiles/hw_grpc_proto.dir/build.make
libhw_grpc_proto.a: CMakeFiles/hw_grpc_proto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/cppProjects/007_cppgrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libhw_grpc_proto.a"
	$(CMAKE_COMMAND) -P CMakeFiles/hw_grpc_proto.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw_grpc_proto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw_grpc_proto.dir/build: libhw_grpc_proto.a

.PHONY : CMakeFiles/hw_grpc_proto.dir/build

CMakeFiles/hw_grpc_proto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw_grpc_proto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw_grpc_proto.dir/clean

CMakeFiles/hw_grpc_proto.dir/depend: helloworld.pb.cc
CMakeFiles/hw_grpc_proto.dir/depend: helloworld.pb.h
CMakeFiles/hw_grpc_proto.dir/depend: helloworld.grpc.pb.cc
CMakeFiles/hw_grpc_proto.dir/depend: helloworld.grpc.pb.h
	cd /mnt/e/cppProjects/007_cppgrpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/cppProjects/007_cppgrpc /mnt/e/cppProjects/007_cppgrpc /mnt/e/cppProjects/007_cppgrpc/build /mnt/e/cppProjects/007_cppgrpc/build /mnt/e/cppProjects/007_cppgrpc/build/CMakeFiles/hw_grpc_proto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw_grpc_proto.dir/depend

