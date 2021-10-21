cmake_minimum_required(VERSION 3.5)

project(otus_81 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(otus_81 main.cpp bulkcommandprinter.h bulkcommandprinter.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(otus_81 PRIVATE Threads::Threads)
