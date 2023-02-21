cmake_minimum_required(VERSION 3.0.0)
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(exp VERSION 1.0)
include_directories(./include)
aux_source_directory(. SRCS)    
add_executable(${PROJECT_NAME}  ${SRCS})

