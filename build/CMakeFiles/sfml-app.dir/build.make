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
CMAKE_SOURCE_DIR = /home/ensta/IN104V3/repository

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ensta/IN104V3/build

# Include any dependencies generated for this target.
include CMakeFiles/sfml-app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sfml-app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfml-app.dir/flags.make

CMakeFiles/sfml-app.dir/src/Banana.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/Banana.cpp.o: /home/ensta/IN104V3/repository/src/Banana.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN104V3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfml-app.dir/src/Banana.cpp.o"
	clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/Banana.cpp.o -c /home/ensta/IN104V3/repository/src/Banana.cpp

CMakeFiles/sfml-app.dir/src/Banana.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/Banana.cpp.i"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN104V3/repository/src/Banana.cpp > CMakeFiles/sfml-app.dir/src/Banana.cpp.i

CMakeFiles/sfml-app.dir/src/Banana.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/Banana.cpp.s"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN104V3/repository/src/Banana.cpp -o CMakeFiles/sfml-app.dir/src/Banana.cpp.s

CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.o: /home/ensta/IN104V3/repository/src/CheckPoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN104V3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.o"
	clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.o -c /home/ensta/IN104V3/repository/src/CheckPoint.cpp

CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.i"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN104V3/repository/src/CheckPoint.cpp > CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.i

CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.s"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN104V3/repository/src/CheckPoint.cpp -o CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.s

CMakeFiles/sfml-app.dir/src/Menu.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/Menu.cpp.o: /home/ensta/IN104V3/repository/src/Menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN104V3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sfml-app.dir/src/Menu.cpp.o"
	clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/Menu.cpp.o -c /home/ensta/IN104V3/repository/src/Menu.cpp

CMakeFiles/sfml-app.dir/src/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/Menu.cpp.i"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN104V3/repository/src/Menu.cpp > CMakeFiles/sfml-app.dir/src/Menu.cpp.i

CMakeFiles/sfml-app.dir/src/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/Menu.cpp.s"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN104V3/repository/src/Menu.cpp -o CMakeFiles/sfml-app.dir/src/Menu.cpp.s

CMakeFiles/sfml-app.dir/src/game.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/game.cpp.o: /home/ensta/IN104V3/repository/src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN104V3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sfml-app.dir/src/game.cpp.o"
	clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/game.cpp.o -c /home/ensta/IN104V3/repository/src/game.cpp

CMakeFiles/sfml-app.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/game.cpp.i"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN104V3/repository/src/game.cpp > CMakeFiles/sfml-app.dir/src/game.cpp.i

CMakeFiles/sfml-app.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/game.cpp.s"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN104V3/repository/src/game.cpp -o CMakeFiles/sfml-app.dir/src/game.cpp.s

CMakeFiles/sfml-app.dir/src/main.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/main.cpp.o: /home/ensta/IN104V3/repository/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN104V3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sfml-app.dir/src/main.cpp.o"
	clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/main.cpp.o -c /home/ensta/IN104V3/repository/src/main.cpp

CMakeFiles/sfml-app.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/main.cpp.i"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN104V3/repository/src/main.cpp > CMakeFiles/sfml-app.dir/src/main.cpp.i

CMakeFiles/sfml-app.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/main.cpp.s"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN104V3/repository/src/main.cpp -o CMakeFiles/sfml-app.dir/src/main.cpp.s

CMakeFiles/sfml-app.dir/src/options.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/options.cpp.o: /home/ensta/IN104V3/repository/src/options.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN104V3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sfml-app.dir/src/options.cpp.o"
	clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/options.cpp.o -c /home/ensta/IN104V3/repository/src/options.cpp

CMakeFiles/sfml-app.dir/src/options.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/options.cpp.i"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN104V3/repository/src/options.cpp > CMakeFiles/sfml-app.dir/src/options.cpp.i

CMakeFiles/sfml-app.dir/src/options.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/options.cpp.s"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN104V3/repository/src/options.cpp -o CMakeFiles/sfml-app.dir/src/options.cpp.s

CMakeFiles/sfml-app.dir/src/pod.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/pod.cpp.o: /home/ensta/IN104V3/repository/src/pod.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN104V3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sfml-app.dir/src/pod.cpp.o"
	clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/pod.cpp.o -c /home/ensta/IN104V3/repository/src/pod.cpp

CMakeFiles/sfml-app.dir/src/pod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/pod.cpp.i"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN104V3/repository/src/pod.cpp > CMakeFiles/sfml-app.dir/src/pod.cpp.i

CMakeFiles/sfml-app.dir/src/pod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/pod.cpp.s"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN104V3/repository/src/pod.cpp -o CMakeFiles/sfml-app.dir/src/pod.cpp.s

CMakeFiles/sfml-app.dir/src/util.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/util.cpp.o: /home/ensta/IN104V3/repository/src/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN104V3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sfml-app.dir/src/util.cpp.o"
	clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/util.cpp.o -c /home/ensta/IN104V3/repository/src/util.cpp

CMakeFiles/sfml-app.dir/src/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/util.cpp.i"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN104V3/repository/src/util.cpp > CMakeFiles/sfml-app.dir/src/util.cpp.i

CMakeFiles/sfml-app.dir/src/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/util.cpp.s"
	clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN104V3/repository/src/util.cpp -o CMakeFiles/sfml-app.dir/src/util.cpp.s

# Object files for target sfml-app
sfml__app_OBJECTS = \
"CMakeFiles/sfml-app.dir/src/Banana.cpp.o" \
"CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.o" \
"CMakeFiles/sfml-app.dir/src/Menu.cpp.o" \
"CMakeFiles/sfml-app.dir/src/game.cpp.o" \
"CMakeFiles/sfml-app.dir/src/main.cpp.o" \
"CMakeFiles/sfml-app.dir/src/options.cpp.o" \
"CMakeFiles/sfml-app.dir/src/pod.cpp.o" \
"CMakeFiles/sfml-app.dir/src/util.cpp.o"

# External object files for target sfml-app
sfml__app_EXTERNAL_OBJECTS =

sfml-app: CMakeFiles/sfml-app.dir/src/Banana.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/CheckPoint.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/Menu.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/game.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/main.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/options.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/pod.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/util.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/build.make
sfml-app: CMakeFiles/sfml-app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ensta/IN104V3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable sfml-app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml-app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfml-app.dir/build: sfml-app

.PHONY : CMakeFiles/sfml-app.dir/build

CMakeFiles/sfml-app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfml-app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfml-app.dir/clean

CMakeFiles/sfml-app.dir/depend:
	cd /home/ensta/IN104V3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ensta/IN104V3/repository /home/ensta/IN104V3/repository /home/ensta/IN104V3/build /home/ensta/IN104V3/build /home/ensta/IN104V3/build/CMakeFiles/sfml-app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfml-app.dir/depend

