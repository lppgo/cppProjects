# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\SoftBox\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\SoftBox\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\cppProjects\002_cmake_demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\cppProjects\002_cmake_demo\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/calculate.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/calculate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calculate.dir/flags.make

CMakeFiles/calculate.dir/hello.cpp.obj: CMakeFiles/calculate.dir/flags.make
CMakeFiles/calculate.dir/hello.cpp.obj: ../hello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\cppProjects\002_cmake_demo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calculate.dir/hello.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\calculate.dir\hello.cpp.obj -c E:\cppProjects\002_cmake_demo\hello.cpp

CMakeFiles/calculate.dir/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculate.dir/hello.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\cppProjects\002_cmake_demo\hello.cpp > CMakeFiles\calculate.dir\hello.cpp.i

CMakeFiles/calculate.dir/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculate.dir/hello.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\cppProjects\002_cmake_demo\hello.cpp -o CMakeFiles\calculate.dir\hello.cpp.s

# Object files for target calculate
calculate_OBJECTS = \
"CMakeFiles/calculate.dir/hello.cpp.obj"

# External object files for target calculate
calculate_EXTERNAL_OBJECTS =

libcalculate.dll: CMakeFiles/calculate.dir/hello.cpp.obj
libcalculate.dll: CMakeFiles/calculate.dir/build.make
libcalculate.dll: CMakeFiles/calculate.dir/linklibs.rsp
libcalculate.dll: CMakeFiles/calculate.dir/objects1.rsp
libcalculate.dll: CMakeFiles/calculate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\cppProjects\002_cmake_demo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libcalculate.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\calculate.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calculate.dir/build: libcalculate.dll
.PHONY : CMakeFiles/calculate.dir/build

CMakeFiles/calculate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\calculate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/calculate.dir/clean

CMakeFiles/calculate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\cppProjects\002_cmake_demo E:\cppProjects\002_cmake_demo E:\cppProjects\002_cmake_demo\cmake-build-debug E:\cppProjects\002_cmake_demo\cmake-build-debug E:\cppProjects\002_cmake_demo\cmake-build-debug\CMakeFiles\calculate.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calculate.dir/depend

