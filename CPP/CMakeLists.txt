cmake_minimum_required(VERSION 3.10)
project(Sensors)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compile flags 
set(CMAKE_CXX_FLAGS " ")

# Definitions
# add_definitions(-D_DEBUG_FLAG)

# main file
set(MAIN ${CMAKE_SOURCE_DIR}/src/pir.cpp)

#SensorClass
set(SENSOR_CLASS_DIR ${CMAKE_SOURCE_DIR}/src/SensorClass)
set(SENSOR_CLASS ${SENSOR_CLASS_DIR}/SensorClass.hpp ${SENSOR_CLASS_DIR}/SensorClass.cpp)

# add the executable
add_executable(${CMAKE_PROJECT_NAME} ${MAIN} ${SENSOR_CLASS})

# Static library
target_link_libraries(${CMAKE_PROJECT_NAME} wiringPi)

# Directories
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC 
									"${CMAKE_SOURCE_DIR}/src/SensorClass"
									)