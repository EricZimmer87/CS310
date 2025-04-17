cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Use C++17
set(CMAKE_CXX_STANDARD 17)

# Get all .cpp files in this folder
file(GLOB SOURCES "*.cpp")

# Build executable
add_executable(MyExecutable ${SOURCES})

# Custom run target
add_custom_target(run
    COMMAND $<TARGET_FILE:MyExecutable>
    DEPENDS MyExecutable
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Custom clean target to delete build files
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_BINARY_DIR}
)