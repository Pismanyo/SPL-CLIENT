# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/99/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/99/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joni/CLionProjects/Boost_Echo_Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Boost_Echo_Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Boost_Echo_Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Boost_Echo_Client.dir/flags.make

CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.o: ../src/connectionHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.o -c /home/joni/CLionProjects/Boost_Echo_Client/src/connectionHandler.cpp

CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joni/CLionProjects/Boost_Echo_Client/src/connectionHandler.cpp > CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joni/CLionProjects/Boost_Echo_Client/src/connectionHandler.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o: ../src/echoClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o -c /home/joni/CLionProjects/Boost_Echo_Client/src/echoClient.cpp

CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joni/CLionProjects/Boost_Echo_Client/src/echoClient.cpp > CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joni/CLionProjects/Boost_Echo_Client/src/echoClient.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.o: ../src/Frame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.o -c /home/joni/CLionProjects/Boost_Echo_Client/src/Frame.cpp

CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joni/CLionProjects/Boost_Echo_Client/src/Frame.cpp > CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joni/CLionProjects/Boost_Echo_Client/src/Frame.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.o: ../src/User.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.o -c /home/joni/CLionProjects/Boost_Echo_Client/src/User.cpp

CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joni/CLionProjects/Boost_Echo_Client/src/User.cpp > CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joni/CLionProjects/Boost_Echo_Client/src/User.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.o: ../src/UserCommands.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.o -c /home/joni/CLionProjects/Boost_Echo_Client/src/UserCommands.cpp

CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joni/CLionProjects/Boost_Echo_Client/src/UserCommands.cpp > CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joni/CLionProjects/Boost_Echo_Client/src/UserCommands.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.s

CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.o: CMakeFiles/Boost_Echo_Client.dir/flags.make
CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.o: ../src/StompConnectionProtocal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.o -c /home/joni/CLionProjects/Boost_Echo_Client/src/StompConnectionProtocal.cpp

CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joni/CLionProjects/Boost_Echo_Client/src/StompConnectionProtocal.cpp > CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.i

CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joni/CLionProjects/Boost_Echo_Client/src/StompConnectionProtocal.cpp -o CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.s

# Object files for target Boost_Echo_Client
Boost_Echo_Client_OBJECTS = \
"CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.o" \
"CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.o"

# External object files for target Boost_Echo_Client
Boost_Echo_Client_EXTERNAL_OBJECTS =

Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/connectionHandler.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/echoClient.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/Frame.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/User.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/UserCommands.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/src/StompConnectionProtocal.cpp.o
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/build.make
Boost_Echo_Client: CMakeFiles/Boost_Echo_Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Boost_Echo_Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Boost_Echo_Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Boost_Echo_Client.dir/build: Boost_Echo_Client

.PHONY : CMakeFiles/Boost_Echo_Client.dir/build

CMakeFiles/Boost_Echo_Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Boost_Echo_Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Boost_Echo_Client.dir/clean

CMakeFiles/Boost_Echo_Client.dir/depend:
	cd /home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joni/CLionProjects/Boost_Echo_Client /home/joni/CLionProjects/Boost_Echo_Client /home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug /home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug /home/joni/CLionProjects/Boost_Echo_Client/cmake-build-debug/CMakeFiles/Boost_Echo_Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Boost_Echo_Client.dir/depend

