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
CMAKE_SOURCE_DIR = /mnt/e/cppProjects001/013_amagrpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/cppProjects001/013_amagrpc/cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/grpc_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/grpc_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/grpc_server.dir/flags.make

CMakeFiles/grpc_server.dir/grpc_server.cpp.o: CMakeFiles/grpc_server.dir/flags.make
CMakeFiles/grpc_server.dir/grpc_server.cpp.o: ../../grpc_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/cppProjects001/013_amagrpc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/grpc_server.dir/grpc_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/grpc_server.dir/grpc_server.cpp.o -c /mnt/e/cppProjects001/013_amagrpc/grpc_server.cpp

CMakeFiles/grpc_server.dir/grpc_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/grpc_server.dir/grpc_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/cppProjects001/013_amagrpc/grpc_server.cpp > CMakeFiles/grpc_server.dir/grpc_server.cpp.i

CMakeFiles/grpc_server.dir/grpc_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/grpc_server.dir/grpc_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/cppProjects001/013_amagrpc/grpc_server.cpp -o CMakeFiles/grpc_server.dir/grpc_server.cpp.s

# Object files for target grpc_server
grpc_server_OBJECTS = \
"CMakeFiles/grpc_server.dir/grpc_server.cpp.o"

# External object files for target grpc_server
grpc_server_EXTERNAL_OBJECTS =

grpc_server: CMakeFiles/grpc_server.dir/grpc_server.cpp.o
grpc_server: CMakeFiles/grpc_server.dir/build.make
grpc_server: libhw_grpc_proto.a
grpc_server: /home/lucas/.local/lib/libgrpc++_reflection.a
grpc_server: /home/lucas/.local/lib/libgrpc++.a
grpc_server: /home/lucas/.local/lib/libprotobuf.a
grpc_server: /home/lucas/.local/lib/libgrpc.a
grpc_server: /home/lucas/.local/lib/libz.a
grpc_server: /home/lucas/.local/lib/libcares.a
grpc_server: /home/lucas/.local/lib/libaddress_sorting.a
grpc_server: /home/lucas/.local/lib/libre2.a
grpc_server: /home/lucas/.local/lib/libabsl_hash.a
grpc_server: /home/lucas/.local/lib/libabsl_city.a
grpc_server: /home/lucas/.local/lib/libabsl_wyhash.a
grpc_server: /home/lucas/.local/lib/libabsl_raw_hash_set.a
grpc_server: /home/lucas/.local/lib/libabsl_hashtablez_sampler.a
grpc_server: /home/lucas/.local/lib/libabsl_exponential_biased.a
grpc_server: /home/lucas/.local/lib/libabsl_statusor.a
grpc_server: /home/lucas/.local/lib/libabsl_bad_variant_access.a
grpc_server: /home/lucas/.local/lib/libgpr.a
grpc_server: /home/lucas/.local/lib/libupb.a
grpc_server: /home/lucas/.local/lib/libabsl_status.a
grpc_server: /home/lucas/.local/lib/libabsl_cord.a
grpc_server: /home/lucas/.local/lib/libabsl_str_format_internal.a
grpc_server: /home/lucas/.local/lib/libabsl_synchronization.a
grpc_server: /home/lucas/.local/lib/libabsl_stacktrace.a
grpc_server: /home/lucas/.local/lib/libabsl_symbolize.a
grpc_server: /home/lucas/.local/lib/libabsl_debugging_internal.a
grpc_server: /home/lucas/.local/lib/libabsl_demangle_internal.a
grpc_server: /home/lucas/.local/lib/libabsl_graphcycles_internal.a
grpc_server: /home/lucas/.local/lib/libabsl_malloc_internal.a
grpc_server: /home/lucas/.local/lib/libabsl_time.a
grpc_server: /home/lucas/.local/lib/libabsl_strings.a
grpc_server: /home/lucas/.local/lib/libabsl_throw_delegate.a
grpc_server: /home/lucas/.local/lib/libabsl_strings_internal.a
grpc_server: /home/lucas/.local/lib/libabsl_base.a
grpc_server: /home/lucas/.local/lib/libabsl_spinlock_wait.a
grpc_server: /home/lucas/.local/lib/libabsl_int128.a
grpc_server: /home/lucas/.local/lib/libabsl_civil_time.a
grpc_server: /home/lucas/.local/lib/libabsl_time_zone.a
grpc_server: /home/lucas/.local/lib/libabsl_bad_optional_access.a
grpc_server: /home/lucas/.local/lib/libabsl_raw_logging_internal.a
grpc_server: /home/lucas/.local/lib/libabsl_log_severity.a
grpc_server: /home/lucas/.local/lib/libssl.a
grpc_server: /home/lucas/.local/lib/libcrypto.a
grpc_server: CMakeFiles/grpc_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/cppProjects001/013_amagrpc/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable grpc_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/grpc_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/grpc_server.dir/build: grpc_server

.PHONY : CMakeFiles/grpc_server.dir/build

CMakeFiles/grpc_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/grpc_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/grpc_server.dir/clean

CMakeFiles/grpc_server.dir/depend:
	cd /mnt/e/cppProjects001/013_amagrpc/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/cppProjects001/013_amagrpc /mnt/e/cppProjects001/013_amagrpc /mnt/e/cppProjects001/013_amagrpc/cmake/build /mnt/e/cppProjects001/013_amagrpc/cmake/build /mnt/e/cppProjects001/013_amagrpc/cmake/build/CMakeFiles/grpc_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/grpc_server.dir/depend

