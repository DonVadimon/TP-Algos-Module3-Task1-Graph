cmake_minimum_required(VERSION 3.16)
project(Graph)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/ArcGraph.cpp
        src/ListGraph.cpp
        src/MatrixGraph.cpp
        src/SetGraph.cpp
        )

set(HEADER_FILES
        includes/IGraph.h
        includes/ArcGraph.h
        includes/ListGraph.h
        includes/MatrixGraph.h
        includes/SetGraph.h
        )

include_directories(includes)

add_executable(Graph main.cpp
        ${SOURCE_FILES}
        ${HEADER_FILES})