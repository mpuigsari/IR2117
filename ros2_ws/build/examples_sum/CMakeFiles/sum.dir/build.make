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
CMAKE_SOURCE_DIR = /home/max/Documents/GitHub/IR2117/ros2_ws/src/examples/sum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/max/Documents/GitHub/IR2117/ros2_ws/build/examples_sum

# Include any dependencies generated for this target.
include CMakeFiles/sum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sum.dir/flags.make

CMakeFiles/sum.dir/sum.cpp.o: CMakeFiles/sum.dir/flags.make
CMakeFiles/sum.dir/sum.cpp.o: /home/max/Documents/GitHub/IR2117/ros2_ws/src/examples/sum/sum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/Documents/GitHub/IR2117/ros2_ws/build/examples_sum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sum.dir/sum.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sum.dir/sum.cpp.o -c /home/max/Documents/GitHub/IR2117/ros2_ws/src/examples/sum/sum.cpp

CMakeFiles/sum.dir/sum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sum.dir/sum.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/Documents/GitHub/IR2117/ros2_ws/src/examples/sum/sum.cpp > CMakeFiles/sum.dir/sum.cpp.i

CMakeFiles/sum.dir/sum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sum.dir/sum.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/Documents/GitHub/IR2117/ros2_ws/src/examples/sum/sum.cpp -o CMakeFiles/sum.dir/sum.cpp.s

# Object files for target sum
sum_OBJECTS = \
"CMakeFiles/sum.dir/sum.cpp.o"

# External object files for target sum
sum_EXTERNAL_OBJECTS =

sum: CMakeFiles/sum.dir/sum.cpp.o
sum: CMakeFiles/sum.dir/build.make
sum: /opt/ros/foxy/lib/librclcpp.so
sum: /opt/ros/foxy/lib/liblibstatistics_collector.so
sum: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_introspection_c.so
sum: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_generator_c.so
sum: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_c.so
sum: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_introspection_cpp.so
sum: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_cpp.so
sum: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
sum: /opt/ros/foxy/lib/libstd_msgs__rosidl_generator_c.so
sum: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_c.so
sum: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
sum: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_cpp.so
sum: /opt/ros/foxy/lib/librcl.so
sum: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
sum: /opt/ros/foxy/lib/librcl_interfaces__rosidl_generator_c.so
sum: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_c.so
sum: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
sum: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_cpp.so
sum: /opt/ros/foxy/lib/librmw_implementation.so
sum: /opt/ros/foxy/lib/librmw.so
sum: /opt/ros/foxy/lib/librcl_logging_spdlog.so
sum: /usr/lib/x86_64-linux-gnu/libspdlog.so.1.5.0
sum: /opt/ros/foxy/lib/librcl_yaml_param_parser.so
sum: /opt/ros/foxy/lib/libyaml.so
sum: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
sum: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_generator_c.so
sum: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_c.so
sum: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
sum: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
sum: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
sum: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_generator_c.so
sum: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_c.so
sum: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
sum: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
sum: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
sum: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_generator_c.so
sum: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
sum: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
sum: /opt/ros/foxy/lib/librosidl_typesupport_introspection_cpp.so
sum: /opt/ros/foxy/lib/librosidl_typesupport_introspection_c.so
sum: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
sum: /opt/ros/foxy/lib/librosidl_typesupport_cpp.so
sum: /opt/ros/foxy/lib/librosidl_typesupport_c.so
sum: /opt/ros/foxy/lib/librcpputils.so
sum: /opt/ros/foxy/lib/librosidl_runtime_c.so
sum: /opt/ros/foxy/lib/librcutils.so
sum: /opt/ros/foxy/lib/libtracetools.so
sum: CMakeFiles/sum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/max/Documents/GitHub/IR2117/ros2_ws/build/examples_sum/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sum.dir/build: sum

.PHONY : CMakeFiles/sum.dir/build

CMakeFiles/sum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sum.dir/clean

CMakeFiles/sum.dir/depend:
	cd /home/max/Documents/GitHub/IR2117/ros2_ws/build/examples_sum && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/max/Documents/GitHub/IR2117/ros2_ws/src/examples/sum /home/max/Documents/GitHub/IR2117/ros2_ws/src/examples/sum /home/max/Documents/GitHub/IR2117/ros2_ws/build/examples_sum /home/max/Documents/GitHub/IR2117/ros2_ws/build/examples_sum /home/max/Documents/GitHub/IR2117/ros2_ws/build/examples_sum/CMakeFiles/sum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sum.dir/depend

