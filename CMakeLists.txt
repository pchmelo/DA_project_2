cmake_minimum_required(VERSION 3.26.4)
project(projeto_2)

set(CMAKE_CXX_STANDARD 17)

file(COPY src/Data/Toy-Graphs DESTINATION ${CMAKE_BINARY_DIR})
file(COPY src/Data/Extra_Fully_Connected_Graphs DESTINATION ${CMAKE_BINARY_DIR})

include_directories(src/structs/aux_structs)
include_directories(src/structs/data_type)
include_directories(src)

add_executable(project_2 src/main.cpp
        src/structs/data_type/grafos.h
        src/structs/data_type/grafos.cpp
        src/structs/aux_structs/Graph.h
        src/structs/aux_structs/MutablePriorityQueue.h
        src/functions.h
        src/functions.cpp
        src/menu.h
        src/menu.cpp
)