project(merge_sort)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

