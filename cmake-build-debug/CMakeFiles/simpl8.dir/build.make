# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/olle/Documents/c/cosmos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/olle/Documents/c/cosmos/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/simpl8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simpl8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simpl8.dir/flags.make

CMakeFiles/simpl8.dir/main.c.o: CMakeFiles/simpl8.dir/flags.make
CMakeFiles/simpl8.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olle/Documents/c/cosmos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/simpl8.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simpl8.dir/main.c.o   -c /home/olle/Documents/c/cosmos/main.c

CMakeFiles/simpl8.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simpl8.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/olle/Documents/c/cosmos/main.c > CMakeFiles/simpl8.dir/main.c.i

CMakeFiles/simpl8.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simpl8.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/olle/Documents/c/cosmos/main.c -o CMakeFiles/simpl8.dir/main.c.s

CMakeFiles/simpl8.dir/src/instructionParser.c.o: CMakeFiles/simpl8.dir/flags.make
CMakeFiles/simpl8.dir/src/instructionParser.c.o: ../src/instructionParser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olle/Documents/c/cosmos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/simpl8.dir/src/instructionParser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simpl8.dir/src/instructionParser.c.o   -c /home/olle/Documents/c/cosmos/src/instructionParser.c

CMakeFiles/simpl8.dir/src/instructionParser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simpl8.dir/src/instructionParser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/olle/Documents/c/cosmos/src/instructionParser.c > CMakeFiles/simpl8.dir/src/instructionParser.c.i

CMakeFiles/simpl8.dir/src/instructionParser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simpl8.dir/src/instructionParser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/olle/Documents/c/cosmos/src/instructionParser.c -o CMakeFiles/simpl8.dir/src/instructionParser.c.s

CMakeFiles/simpl8.dir/src/emulator/cpu.c.o: CMakeFiles/simpl8.dir/flags.make
CMakeFiles/simpl8.dir/src/emulator/cpu.c.o: ../src/emulator/cpu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olle/Documents/c/cosmos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/simpl8.dir/src/emulator/cpu.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simpl8.dir/src/emulator/cpu.c.o   -c /home/olle/Documents/c/cosmos/src/emulator/cpu.c

CMakeFiles/simpl8.dir/src/emulator/cpu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simpl8.dir/src/emulator/cpu.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/olle/Documents/c/cosmos/src/emulator/cpu.c > CMakeFiles/simpl8.dir/src/emulator/cpu.c.i

CMakeFiles/simpl8.dir/src/emulator/cpu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simpl8.dir/src/emulator/cpu.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/olle/Documents/c/cosmos/src/emulator/cpu.c -o CMakeFiles/simpl8.dir/src/emulator/cpu.c.s

CMakeFiles/simpl8.dir/src/emulator/emulator.c.o: CMakeFiles/simpl8.dir/flags.make
CMakeFiles/simpl8.dir/src/emulator/emulator.c.o: ../src/emulator/emulator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olle/Documents/c/cosmos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/simpl8.dir/src/emulator/emulator.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simpl8.dir/src/emulator/emulator.c.o   -c /home/olle/Documents/c/cosmos/src/emulator/emulator.c

CMakeFiles/simpl8.dir/src/emulator/emulator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simpl8.dir/src/emulator/emulator.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/olle/Documents/c/cosmos/src/emulator/emulator.c > CMakeFiles/simpl8.dir/src/emulator/emulator.c.i

CMakeFiles/simpl8.dir/src/emulator/emulator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simpl8.dir/src/emulator/emulator.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/olle/Documents/c/cosmos/src/emulator/emulator.c -o CMakeFiles/simpl8.dir/src/emulator/emulator.c.s

CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.o: CMakeFiles/simpl8.dir/flags.make
CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.o: ../src/emulator/cpu_opcodes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olle/Documents/c/cosmos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.o   -c /home/olle/Documents/c/cosmos/src/emulator/cpu_opcodes.c

CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/olle/Documents/c/cosmos/src/emulator/cpu_opcodes.c > CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.i

CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/olle/Documents/c/cosmos/src/emulator/cpu_opcodes.c -o CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.s

CMakeFiles/simpl8.dir/src/assembler/assembler.c.o: CMakeFiles/simpl8.dir/flags.make
CMakeFiles/simpl8.dir/src/assembler/assembler.c.o: ../src/assembler/assembler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olle/Documents/c/cosmos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/simpl8.dir/src/assembler/assembler.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simpl8.dir/src/assembler/assembler.c.o   -c /home/olle/Documents/c/cosmos/src/assembler/assembler.c

CMakeFiles/simpl8.dir/src/assembler/assembler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simpl8.dir/src/assembler/assembler.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/olle/Documents/c/cosmos/src/assembler/assembler.c > CMakeFiles/simpl8.dir/src/assembler/assembler.c.i

CMakeFiles/simpl8.dir/src/assembler/assembler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simpl8.dir/src/assembler/assembler.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/olle/Documents/c/cosmos/src/assembler/assembler.c -o CMakeFiles/simpl8.dir/src/assembler/assembler.c.s

CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.o: CMakeFiles/simpl8.dir/flags.make
CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.o: ../src/disassembler/disassembler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olle/Documents/c/cosmos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.o   -c /home/olle/Documents/c/cosmos/src/disassembler/disassembler.c

CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/olle/Documents/c/cosmos/src/disassembler/disassembler.c > CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.i

CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/olle/Documents/c/cosmos/src/disassembler/disassembler.c -o CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.s

# Object files for target simpl8
simpl8_OBJECTS = \
"CMakeFiles/simpl8.dir/main.c.o" \
"CMakeFiles/simpl8.dir/src/instructionParser.c.o" \
"CMakeFiles/simpl8.dir/src/emulator/cpu.c.o" \
"CMakeFiles/simpl8.dir/src/emulator/emulator.c.o" \
"CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.o" \
"CMakeFiles/simpl8.dir/src/assembler/assembler.c.o" \
"CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.o"

# External object files for target simpl8
simpl8_EXTERNAL_OBJECTS =

simpl8: CMakeFiles/simpl8.dir/main.c.o
simpl8: CMakeFiles/simpl8.dir/src/instructionParser.c.o
simpl8: CMakeFiles/simpl8.dir/src/emulator/cpu.c.o
simpl8: CMakeFiles/simpl8.dir/src/emulator/emulator.c.o
simpl8: CMakeFiles/simpl8.dir/src/emulator/cpu_opcodes.c.o
simpl8: CMakeFiles/simpl8.dir/src/assembler/assembler.c.o
simpl8: CMakeFiles/simpl8.dir/src/disassembler/disassembler.c.o
simpl8: CMakeFiles/simpl8.dir/build.make
simpl8: /usr/lib/libSDL2_ttf.so
simpl8: CMakeFiles/simpl8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olle/Documents/c/cosmos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable simpl8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simpl8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simpl8.dir/build: simpl8

.PHONY : CMakeFiles/simpl8.dir/build

CMakeFiles/simpl8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simpl8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simpl8.dir/clean

CMakeFiles/simpl8.dir/depend:
	cd /home/olle/Documents/c/cosmos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olle/Documents/c/cosmos /home/olle/Documents/c/cosmos /home/olle/Documents/c/cosmos/cmake-build-debug /home/olle/Documents/c/cosmos/cmake-build-debug /home/olle/Documents/c/cosmos/cmake-build-debug/CMakeFiles/simpl8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simpl8.dir/depend
