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
CMAKE_SOURCE_DIR = E:\cppProjects\019_time

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\cppProjects\019_time\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mt.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/mt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mt.dir/flags.make

CMakeFiles/mt.dir/src/mytime.cpp.obj: CMakeFiles/mt.dir/flags.make
CMakeFiles/mt.dir/src/mytime.cpp.obj: CMakeFiles/mt.dir/includes_CXX.rsp
CMakeFiles/mt.dir/src/mytime.cpp.obj: ../src/mytime.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\cppProjects\019_time\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mt.dir/src/mytime.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mt.dir\src\mytime.cpp.obj -c E:\cppProjects\019_time\src\mytime.cpp

CMakeFiles/mt.dir/src/mytime.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mt.dir/src/mytime.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\cppProjects\019_time\src\mytime.cpp > CMakeFiles\mt.dir\src\mytime.cpp.i

CMakeFiles/mt.dir/src/mytime.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mt.dir/src/mytime.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\cppProjects\019_time\src\mytime.cpp -o CMakeFiles\mt.dir\src\mytime.cpp.s

# Object files for target mt
mt_OBJECTS = \
"CMakeFiles/mt.dir/src/mytime.cpp.obj"

# External object files for target mt
mt_EXTERNAL_OBJECTS =

libmt.dll: CMakeFiles/mt.dir/src/mytime.cpp.obj
libmt.dll: CMakeFiles/mt.dir/build.make
libmt.dll: CMakeFiles/mt.dir/linklibs.rsp
libmt.dll: CMakeFiles/mt.dir/objects1.rsp
libmt.dll: CMakeFiles/mt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\cppProjects\019_time\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmt.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mt.dir/build: libmt.dll
.PHONY : CMakeFiles/mt.dir/build

CMakeFiles/mt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mt.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mt.dir/clean

CMakeFiles/mt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\cppProjects\019_time E:\cppProjects\019_time E:\cppProjects\019_time\cmake-build-debug E:\cppProjects\019_time\cmake-build-debug E:\cppProjects\019_time\cmake-build-debug\CMakeFiles\mt.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mt.dir/depend

