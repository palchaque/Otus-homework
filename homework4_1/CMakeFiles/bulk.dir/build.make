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


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /usr/local/cmake-3.16.8/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake-3.16.8/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/travis/build/palchaque/Otus-homework/homework4_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/travis/build/palchaque/Otus-homework/homework4_1

# Include any dependencies generated for this target.
include CMakeFiles/bulk.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bulk.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bulk.dir/flags.make

CMakeFiles/bulk.dir/main.cpp.o: CMakeFiles/bulk.dir/flags.make
CMakeFiles/bulk.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/palchaque/Otus-homework/homework4_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bulk.dir/main.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bulk.dir/main.cpp.o -c /home/travis/build/palchaque/Otus-homework/homework4_1/main.cpp

CMakeFiles/bulk.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bulk.dir/main.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/palchaque/Otus-homework/homework4_1/main.cpp > CMakeFiles/bulk.dir/main.cpp.i

CMakeFiles/bulk.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bulk.dir/main.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/palchaque/Otus-homework/homework4_1/main.cpp -o CMakeFiles/bulk.dir/main.cpp.s

CMakeFiles/bulk.dir/editor_model.cpp.o: CMakeFiles/bulk.dir/flags.make
CMakeFiles/bulk.dir/editor_model.cpp.o: editor_model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/palchaque/Otus-homework/homework4_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bulk.dir/editor_model.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bulk.dir/editor_model.cpp.o -c /home/travis/build/palchaque/Otus-homework/homework4_1/editor_model.cpp

CMakeFiles/bulk.dir/editor_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bulk.dir/editor_model.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/palchaque/Otus-homework/homework4_1/editor_model.cpp > CMakeFiles/bulk.dir/editor_model.cpp.i

CMakeFiles/bulk.dir/editor_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bulk.dir/editor_model.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/palchaque/Otus-homework/homework4_1/editor_model.cpp -o CMakeFiles/bulk.dir/editor_model.cpp.s

CMakeFiles/bulk.dir/editor_image.cpp.o: CMakeFiles/bulk.dir/flags.make
CMakeFiles/bulk.dir/editor_image.cpp.o: editor_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/palchaque/Otus-homework/homework4_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/bulk.dir/editor_image.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bulk.dir/editor_image.cpp.o -c /home/travis/build/palchaque/Otus-homework/homework4_1/editor_image.cpp

CMakeFiles/bulk.dir/editor_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bulk.dir/editor_image.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/palchaque/Otus-homework/homework4_1/editor_image.cpp > CMakeFiles/bulk.dir/editor_image.cpp.i

CMakeFiles/bulk.dir/editor_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bulk.dir/editor_image.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/palchaque/Otus-homework/homework4_1/editor_image.cpp -o CMakeFiles/bulk.dir/editor_image.cpp.s

CMakeFiles/bulk.dir/editor_controller.cpp.o: CMakeFiles/bulk.dir/flags.make
CMakeFiles/bulk.dir/editor_controller.cpp.o: editor_controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/palchaque/Otus-homework/homework4_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/bulk.dir/editor_controller.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bulk.dir/editor_controller.cpp.o -c /home/travis/build/palchaque/Otus-homework/homework4_1/editor_controller.cpp

CMakeFiles/bulk.dir/editor_controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bulk.dir/editor_controller.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/palchaque/Otus-homework/homework4_1/editor_controller.cpp > CMakeFiles/bulk.dir/editor_controller.cpp.i

CMakeFiles/bulk.dir/editor_controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bulk.dir/editor_controller.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/palchaque/Otus-homework/homework4_1/editor_controller.cpp -o CMakeFiles/bulk.dir/editor_controller.cpp.s

CMakeFiles/bulk.dir/editor_view.cpp.o: CMakeFiles/bulk.dir/flags.make
CMakeFiles/bulk.dir/editor_view.cpp.o: editor_view.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/palchaque/Otus-homework/homework4_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/bulk.dir/editor_view.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bulk.dir/editor_view.cpp.o -c /home/travis/build/palchaque/Otus-homework/homework4_1/editor_view.cpp

CMakeFiles/bulk.dir/editor_view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bulk.dir/editor_view.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/palchaque/Otus-homework/homework4_1/editor_view.cpp > CMakeFiles/bulk.dir/editor_view.cpp.i

CMakeFiles/bulk.dir/editor_view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bulk.dir/editor_view.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/palchaque/Otus-homework/homework4_1/editor_view.cpp -o CMakeFiles/bulk.dir/editor_view.cpp.s

# Object files for target bulk
bulk_OBJECTS = \
"CMakeFiles/bulk.dir/main.cpp.o" \
"CMakeFiles/bulk.dir/editor_model.cpp.o" \
"CMakeFiles/bulk.dir/editor_image.cpp.o" \
"CMakeFiles/bulk.dir/editor_controller.cpp.o" \
"CMakeFiles/bulk.dir/editor_view.cpp.o"

# External object files for target bulk
bulk_EXTERNAL_OBJECTS =

bulk: CMakeFiles/bulk.dir/main.cpp.o
bulk: CMakeFiles/bulk.dir/editor_model.cpp.o
bulk: CMakeFiles/bulk.dir/editor_image.cpp.o
bulk: CMakeFiles/bulk.dir/editor_controller.cpp.o
bulk: CMakeFiles/bulk.dir/editor_view.cpp.o
bulk: CMakeFiles/bulk.dir/build.make
bulk: CMakeFiles/bulk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/travis/build/palchaque/Otus-homework/homework4_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable bulk"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bulk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bulk.dir/build: bulk

.PHONY : CMakeFiles/bulk.dir/build

CMakeFiles/bulk.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bulk.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bulk.dir/clean

CMakeFiles/bulk.dir/depend:
	cd /home/travis/build/palchaque/Otus-homework/homework4_1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/travis/build/palchaque/Otus-homework/homework4_1 /home/travis/build/palchaque/Otus-homework/homework4_1 /home/travis/build/palchaque/Otus-homework/homework4_1 /home/travis/build/palchaque/Otus-homework/homework4_1 /home/travis/build/palchaque/Otus-homework/homework4_1/CMakeFiles/bulk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bulk.dir/depend
