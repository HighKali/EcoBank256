# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
SHELL = /data/data/com.termux/files/usr/bin/sh

# The CMake executable.
CMAKE_COMMAND = /data/data/com.termux/files/usr/bin/cmake

# The command to remove a file.
RM = /data/data/com.termux/files/usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data/data/com.termux/files/home/EcoBank256

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/data/com.termux/files/home/EcoBank256/build

# Include any dependencies generated for this target.
include CMakeFiles/ecobank256d.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ecobank256d.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ecobank256d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ecobank256d.dir/flags.make

CMakeFiles/ecobank256d.dir/codegen:
.PHONY : CMakeFiles/ecobank256d.dir/codegen

CMakeFiles/ecobank256d.dir/src/main.c.o: CMakeFiles/ecobank256d.dir/flags.make
CMakeFiles/ecobank256d.dir/src/main.c.o: /data/data/com.termux/files/home/EcoBank256/src/main.c
CMakeFiles/ecobank256d.dir/src/main.c.o: CMakeFiles/ecobank256d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/data/data/com.termux/files/home/EcoBank256/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ecobank256d.dir/src/main.c.o"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ecobank256d.dir/src/main.c.o -MF CMakeFiles/ecobank256d.dir/src/main.c.o.d -o CMakeFiles/ecobank256d.dir/src/main.c.o -c /data/data/com.termux/files/home/EcoBank256/src/main.c

CMakeFiles/ecobank256d.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ecobank256d.dir/src/main.c.i"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /data/data/com.termux/files/home/EcoBank256/src/main.c > CMakeFiles/ecobank256d.dir/src/main.c.i

CMakeFiles/ecobank256d.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ecobank256d.dir/src/main.c.s"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /data/data/com.termux/files/home/EcoBank256/src/main.c -o CMakeFiles/ecobank256d.dir/src/main.c.s

CMakeFiles/ecobank256d.dir/src/blockchain.c.o: CMakeFiles/ecobank256d.dir/flags.make
CMakeFiles/ecobank256d.dir/src/blockchain.c.o: /data/data/com.termux/files/home/EcoBank256/src/blockchain.c
CMakeFiles/ecobank256d.dir/src/blockchain.c.o: CMakeFiles/ecobank256d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/data/data/com.termux/files/home/EcoBank256/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ecobank256d.dir/src/blockchain.c.o"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ecobank256d.dir/src/blockchain.c.o -MF CMakeFiles/ecobank256d.dir/src/blockchain.c.o.d -o CMakeFiles/ecobank256d.dir/src/blockchain.c.o -c /data/data/com.termux/files/home/EcoBank256/src/blockchain.c

CMakeFiles/ecobank256d.dir/src/blockchain.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ecobank256d.dir/src/blockchain.c.i"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /data/data/com.termux/files/home/EcoBank256/src/blockchain.c > CMakeFiles/ecobank256d.dir/src/blockchain.c.i

CMakeFiles/ecobank256d.dir/src/blockchain.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ecobank256d.dir/src/blockchain.c.s"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /data/data/com.termux/files/home/EcoBank256/src/blockchain.c -o CMakeFiles/ecobank256d.dir/src/blockchain.c.s

CMakeFiles/ecobank256d.dir/src/wallet.c.o: CMakeFiles/ecobank256d.dir/flags.make
CMakeFiles/ecobank256d.dir/src/wallet.c.o: /data/data/com.termux/files/home/EcoBank256/src/wallet.c
CMakeFiles/ecobank256d.dir/src/wallet.c.o: CMakeFiles/ecobank256d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/data/data/com.termux/files/home/EcoBank256/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ecobank256d.dir/src/wallet.c.o"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ecobank256d.dir/src/wallet.c.o -MF CMakeFiles/ecobank256d.dir/src/wallet.c.o.d -o CMakeFiles/ecobank256d.dir/src/wallet.c.o -c /data/data/com.termux/files/home/EcoBank256/src/wallet.c

CMakeFiles/ecobank256d.dir/src/wallet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ecobank256d.dir/src/wallet.c.i"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /data/data/com.termux/files/home/EcoBank256/src/wallet.c > CMakeFiles/ecobank256d.dir/src/wallet.c.i

CMakeFiles/ecobank256d.dir/src/wallet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ecobank256d.dir/src/wallet.c.s"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /data/data/com.termux/files/home/EcoBank256/src/wallet.c -o CMakeFiles/ecobank256d.dir/src/wallet.c.s

CMakeFiles/ecobank256d.dir/src/mixing.c.o: CMakeFiles/ecobank256d.dir/flags.make
CMakeFiles/ecobank256d.dir/src/mixing.c.o: /data/data/com.termux/files/home/EcoBank256/src/mixing.c
CMakeFiles/ecobank256d.dir/src/mixing.c.o: CMakeFiles/ecobank256d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/data/data/com.termux/files/home/EcoBank256/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ecobank256d.dir/src/mixing.c.o"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ecobank256d.dir/src/mixing.c.o -MF CMakeFiles/ecobank256d.dir/src/mixing.c.o.d -o CMakeFiles/ecobank256d.dir/src/mixing.c.o -c /data/data/com.termux/files/home/EcoBank256/src/mixing.c

CMakeFiles/ecobank256d.dir/src/mixing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ecobank256d.dir/src/mixing.c.i"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /data/data/com.termux/files/home/EcoBank256/src/mixing.c > CMakeFiles/ecobank256d.dir/src/mixing.c.i

CMakeFiles/ecobank256d.dir/src/mixing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ecobank256d.dir/src/mixing.c.s"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /data/data/com.termux/files/home/EcoBank256/src/mixing.c -o CMakeFiles/ecobank256d.dir/src/mixing.c.s

CMakeFiles/ecobank256d.dir/src/cli.c.o: CMakeFiles/ecobank256d.dir/flags.make
CMakeFiles/ecobank256d.dir/src/cli.c.o: /data/data/com.termux/files/home/EcoBank256/src/cli.c
CMakeFiles/ecobank256d.dir/src/cli.c.o: CMakeFiles/ecobank256d.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/data/data/com.termux/files/home/EcoBank256/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ecobank256d.dir/src/cli.c.o"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ecobank256d.dir/src/cli.c.o -MF CMakeFiles/ecobank256d.dir/src/cli.c.o.d -o CMakeFiles/ecobank256d.dir/src/cli.c.o -c /data/data/com.termux/files/home/EcoBank256/src/cli.c

CMakeFiles/ecobank256d.dir/src/cli.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ecobank256d.dir/src/cli.c.i"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /data/data/com.termux/files/home/EcoBank256/src/cli.c > CMakeFiles/ecobank256d.dir/src/cli.c.i

CMakeFiles/ecobank256d.dir/src/cli.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ecobank256d.dir/src/cli.c.s"
	/data/data/com.termux/files/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /data/data/com.termux/files/home/EcoBank256/src/cli.c -o CMakeFiles/ecobank256d.dir/src/cli.c.s

# Object files for target ecobank256d
ecobank256d_OBJECTS = \
"CMakeFiles/ecobank256d.dir/src/main.c.o" \
"CMakeFiles/ecobank256d.dir/src/blockchain.c.o" \
"CMakeFiles/ecobank256d.dir/src/wallet.c.o" \
"CMakeFiles/ecobank256d.dir/src/mixing.c.o" \
"CMakeFiles/ecobank256d.dir/src/cli.c.o"

# External object files for target ecobank256d
ecobank256d_EXTERNAL_OBJECTS =

ecobank256d: CMakeFiles/ecobank256d.dir/src/main.c.o
ecobank256d: CMakeFiles/ecobank256d.dir/src/blockchain.c.o
ecobank256d: CMakeFiles/ecobank256d.dir/src/wallet.c.o
ecobank256d: CMakeFiles/ecobank256d.dir/src/mixing.c.o
ecobank256d: CMakeFiles/ecobank256d.dir/src/cli.c.o
ecobank256d: CMakeFiles/ecobank256d.dir/build.make
ecobank256d: CMakeFiles/ecobank256d.dir/compiler_depend.ts
ecobank256d: /data/data/com.termux/files/usr/lib/libboost_filesystem.so
ecobank256d: /data/data/com.termux/files/usr/lib/libboost_date_time.so
ecobank256d: /data/data/com.termux/files/usr/lib/libboost_chrono.so
ecobank256d: /data/data/com.termux/files/usr/lib/libboost_regex.so
ecobank256d: /data/data/com.termux/files/usr/lib/libboost_serialization.so
ecobank256d: /data/data/com.termux/files/usr/lib/libboost_program_options.so
ecobank256d: /data/data/com.termux/files/usr/lib/libssl.so
ecobank256d: /data/data/com.termux/files/usr/lib/libcrypto.so
ecobank256d: /data/data/com.termux/files/usr/lib/libboost_atomic.so
ecobank256d: /data/data/com.termux/files/usr/lib/libboost_system.so
ecobank256d: CMakeFiles/ecobank256d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/data/data/com.termux/files/home/EcoBank256/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable ecobank256d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ecobank256d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ecobank256d.dir/build: ecobank256d
.PHONY : CMakeFiles/ecobank256d.dir/build

CMakeFiles/ecobank256d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ecobank256d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ecobank256d.dir/clean

CMakeFiles/ecobank256d.dir/depend:
	cd /data/data/com.termux/files/home/EcoBank256/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/data/com.termux/files/home/EcoBank256 /data/data/com.termux/files/home/EcoBank256 /data/data/com.termux/files/home/EcoBank256/build /data/data/com.termux/files/home/EcoBank256/build /data/data/com.termux/files/home/EcoBank256/build/CMakeFiles/ecobank256d.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ecobank256d.dir/depend

