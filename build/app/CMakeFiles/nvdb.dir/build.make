# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/jacc/Cpp Examples/back_to_cmake"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jacc/Cpp Examples/back_to_cmake/build"

# Include any dependencies generated for this target.
include app/CMakeFiles/nvdb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include app/CMakeFiles/nvdb.dir/compiler_depend.make

# Include the progress variables for this target.
include app/CMakeFiles/nvdb.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/nvdb.dir/flags.make

app/CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.o: app/CMakeFiles/nvdb.dir/flags.make
app/CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.o: app/nvdb_autogen/mocs_compilation.cpp
app/CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.o: app/CMakeFiles/nvdb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jacc/Cpp Examples/back_to_cmake/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.o"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT app/CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.o -MF CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.o -c "/Users/jacc/Cpp Examples/back_to_cmake/build/app/nvdb_autogen/mocs_compilation.cpp"

app/CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.i"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jacc/Cpp Examples/back_to_cmake/build/app/nvdb_autogen/mocs_compilation.cpp" > CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.i

app/CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.s"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jacc/Cpp Examples/back_to_cmake/build/app/nvdb_autogen/mocs_compilation.cpp" -o CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.s

app/CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.o: app/CMakeFiles/nvdb.dir/flags.make
app/CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.o: /Users/jacc/Cpp\ Examples/back_to_cmake/sources/nvdb_engine.cpp
app/CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.o: app/CMakeFiles/nvdb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jacc/Cpp Examples/back_to_cmake/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object app/CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.o"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT app/CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.o -MF CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.o.d -o CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.o -c "/Users/jacc/Cpp Examples/back_to_cmake/sources/nvdb_engine.cpp"

app/CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.i"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jacc/Cpp Examples/back_to_cmake/sources/nvdb_engine.cpp" > CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.i

app/CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.s"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jacc/Cpp Examples/back_to_cmake/sources/nvdb_engine.cpp" -o CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.s

app/CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.o: app/CMakeFiles/nvdb.dir/flags.make
app/CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.o: /Users/jacc/Cpp\ Examples/back_to_cmake/sources/road_object_type.cpp
app/CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.o: app/CMakeFiles/nvdb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jacc/Cpp Examples/back_to_cmake/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object app/CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.o"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT app/CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.o -MF CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.o.d -o CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.o -c "/Users/jacc/Cpp Examples/back_to_cmake/sources/road_object_type.cpp"

app/CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.i"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jacc/Cpp Examples/back_to_cmake/sources/road_object_type.cpp" > CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.i

app/CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.s"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jacc/Cpp Examples/back_to_cmake/sources/road_object_type.cpp" -o CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.s

app/CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.o: app/CMakeFiles/nvdb.dir/flags.make
app/CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.o: /Users/jacc/Cpp\ Examples/back_to_cmake/sources/rest_http_handler.cpp
app/CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.o: app/CMakeFiles/nvdb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jacc/Cpp Examples/back_to_cmake/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object app/CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.o"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT app/CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.o -MF CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.o.d -o CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.o -c "/Users/jacc/Cpp Examples/back_to_cmake/sources/rest_http_handler.cpp"

app/CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.i"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jacc/Cpp Examples/back_to_cmake/sources/rest_http_handler.cpp" > CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.i

app/CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.s"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jacc/Cpp Examples/back_to_cmake/sources/rest_http_handler.cpp" -o CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.s

# Object files for target nvdb
nvdb_OBJECTS = \
"CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.o" \
"CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.o" \
"CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.o"

# External object files for target nvdb
nvdb_EXTERNAL_OBJECTS =

app/libnvdb.a: app/CMakeFiles/nvdb.dir/nvdb_autogen/mocs_compilation.cpp.o
app/libnvdb.a: app/CMakeFiles/nvdb.dir/__/sources/nvdb_engine.cpp.o
app/libnvdb.a: app/CMakeFiles/nvdb.dir/__/sources/road_object_type.cpp.o
app/libnvdb.a: app/CMakeFiles/nvdb.dir/__/sources/rest_http_handler.cpp.o
app/libnvdb.a: app/CMakeFiles/nvdb.dir/build.make
app/libnvdb.a: app/CMakeFiles/nvdb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/jacc/Cpp Examples/back_to_cmake/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libnvdb.a"
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && $(CMAKE_COMMAND) -P CMakeFiles/nvdb.dir/cmake_clean_target.cmake
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nvdb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/nvdb.dir/build: app/libnvdb.a
.PHONY : app/CMakeFiles/nvdb.dir/build

app/CMakeFiles/nvdb.dir/clean:
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build/app" && $(CMAKE_COMMAND) -P CMakeFiles/nvdb.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/nvdb.dir/clean

app/CMakeFiles/nvdb.dir/depend:
	cd "/Users/jacc/Cpp Examples/back_to_cmake/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jacc/Cpp Examples/back_to_cmake" "/Users/jacc/Cpp Examples/back_to_cmake/app" "/Users/jacc/Cpp Examples/back_to_cmake/build" "/Users/jacc/Cpp Examples/back_to_cmake/build/app" "/Users/jacc/Cpp Examples/back_to_cmake/build/app/CMakeFiles/nvdb.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : app/CMakeFiles/nvdb.dir/depend

