cmake_minimum_required(VERSION 3.9)

project(async LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(async SHARED
  otus_82_global.h
  libasync.cpp
  libasync.h
)

target_compile_definitions(async PRIVATE ASYNC_LIBRARY)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(async PRIVATE Threads::Threads)

add_executable(async_cli main.cpp)
target_link_libraries(async_cli async)

