# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ranju/CLionProjects/ComputerGraphics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ComputerGraphics.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ComputerGraphics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ComputerGraphics.dir/flags.make

CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.o: CMakeFiles/ComputerGraphics.dir/flags.make
CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.o: ../resources/Glad/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.o -c /home/ranju/CLionProjects/ComputerGraphics/resources/Glad/glad.c

CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ranju/CLionProjects/ComputerGraphics/resources/Glad/glad.c > CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.i

CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ranju/CLionProjects/ComputerGraphics/resources/Glad/glad.c -o CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.s

CMakeFiles/ComputerGraphics.dir/source/main.cpp.o: CMakeFiles/ComputerGraphics.dir/flags.make
CMakeFiles/ComputerGraphics.dir/source/main.cpp.o: ../source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ComputerGraphics.dir/source/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputerGraphics.dir/source/main.cpp.o -c /home/ranju/CLionProjects/ComputerGraphics/source/main.cpp

CMakeFiles/ComputerGraphics.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputerGraphics.dir/source/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ranju/CLionProjects/ComputerGraphics/source/main.cpp > CMakeFiles/ComputerGraphics.dir/source/main.cpp.i

CMakeFiles/ComputerGraphics.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputerGraphics.dir/source/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ranju/CLionProjects/ComputerGraphics/source/main.cpp -o CMakeFiles/ComputerGraphics.dir/source/main.cpp.s

CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.o: CMakeFiles/ComputerGraphics.dir/flags.make
CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.o: ../source/Features/indexBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.o -c /home/ranju/CLionProjects/ComputerGraphics/source/Features/indexBuffer.cpp

CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ranju/CLionProjects/ComputerGraphics/source/Features/indexBuffer.cpp > CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.i

CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ranju/CLionProjects/ComputerGraphics/source/Features/indexBuffer.cpp -o CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.s

CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.o: CMakeFiles/ComputerGraphics.dir/flags.make
CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.o: ../source/Features/vertexBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.o -c /home/ranju/CLionProjects/ComputerGraphics/source/Features/vertexBuffer.cpp

CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ranju/CLionProjects/ComputerGraphics/source/Features/vertexBuffer.cpp > CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.i

CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ranju/CLionProjects/ComputerGraphics/source/Features/vertexBuffer.cpp -o CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.s

CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.o: CMakeFiles/ComputerGraphics.dir/flags.make
CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.o: ../source/Features/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.o -c /home/ranju/CLionProjects/ComputerGraphics/source/Features/shader.cpp

CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ranju/CLionProjects/ComputerGraphics/source/Features/shader.cpp > CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.i

CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ranju/CLionProjects/ComputerGraphics/source/Features/shader.cpp -o CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.s

CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.o: CMakeFiles/ComputerGraphics.dir/flags.make
CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.o: ../source/Features/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.o -c /home/ranju/CLionProjects/ComputerGraphics/source/Features/texture.cpp

CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ranju/CLionProjects/ComputerGraphics/source/Features/texture.cpp > CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.i

CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ranju/CLionProjects/ComputerGraphics/source/Features/texture.cpp -o CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.s

CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.o: CMakeFiles/ComputerGraphics.dir/flags.make
CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.o: ../source/Features/vertexArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.o -c /home/ranju/CLionProjects/ComputerGraphics/source/Features/vertexArray.cpp

CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ranju/CLionProjects/ComputerGraphics/source/Features/vertexArray.cpp > CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.i

CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ranju/CLionProjects/ComputerGraphics/source/Features/vertexArray.cpp -o CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.s

CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.o: CMakeFiles/ComputerGraphics.dir/flags.make
CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.o: ../source/Features/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.o -c /home/ranju/CLionProjects/ComputerGraphics/source/Features/renderer.cpp

CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ranju/CLionProjects/ComputerGraphics/source/Features/renderer.cpp > CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.i

CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ranju/CLionProjects/ComputerGraphics/source/Features/renderer.cpp -o CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.s

CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.o: CMakeFiles/ComputerGraphics.dir/flags.make
CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.o: ../source/Features/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.o -c /home/ranju/CLionProjects/ComputerGraphics/source/Features/camera.cpp

CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ranju/CLionProjects/ComputerGraphics/source/Features/camera.cpp > CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.i

CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ranju/CLionProjects/ComputerGraphics/source/Features/camera.cpp -o CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.s

# Object files for target ComputerGraphics
ComputerGraphics_OBJECTS = \
"CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.o" \
"CMakeFiles/ComputerGraphics.dir/source/main.cpp.o" \
"CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.o" \
"CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.o" \
"CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.o" \
"CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.o" \
"CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.o" \
"CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.o" \
"CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.o"

# External object files for target ComputerGraphics
ComputerGraphics_EXTERNAL_OBJECTS =

ComputerGraphics: CMakeFiles/ComputerGraphics.dir/resources/Glad/glad.c.o
ComputerGraphics: CMakeFiles/ComputerGraphics.dir/source/main.cpp.o
ComputerGraphics: CMakeFiles/ComputerGraphics.dir/source/Features/indexBuffer.cpp.o
ComputerGraphics: CMakeFiles/ComputerGraphics.dir/source/Features/vertexBuffer.cpp.o
ComputerGraphics: CMakeFiles/ComputerGraphics.dir/source/Features/shader.cpp.o
ComputerGraphics: CMakeFiles/ComputerGraphics.dir/source/Features/texture.cpp.o
ComputerGraphics: CMakeFiles/ComputerGraphics.dir/source/Features/vertexArray.cpp.o
ComputerGraphics: CMakeFiles/ComputerGraphics.dir/source/Features/renderer.cpp.o
ComputerGraphics: CMakeFiles/ComputerGraphics.dir/source/Features/camera.cpp.o
ComputerGraphics: CMakeFiles/ComputerGraphics.dir/build.make
ComputerGraphics: CMakeFiles/ComputerGraphics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ComputerGraphics"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ComputerGraphics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ComputerGraphics.dir/build: ComputerGraphics

.PHONY : CMakeFiles/ComputerGraphics.dir/build

CMakeFiles/ComputerGraphics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ComputerGraphics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ComputerGraphics.dir/clean

CMakeFiles/ComputerGraphics.dir/depend:
	cd /home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ranju/CLionProjects/ComputerGraphics /home/ranju/CLionProjects/ComputerGraphics /home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug /home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug /home/ranju/CLionProjects/ComputerGraphics/cmake-build-debug/CMakeFiles/ComputerGraphics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ComputerGraphics.dir/depend
