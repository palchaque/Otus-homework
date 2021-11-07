cmake_minimum_required(VERSION 3.7)

project(otus_10_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(otus_10_1 main.cpp table.h table.cpp tableserver.h tableserver.cpp tablesession.h tablesession.cpp)

find_package(Boost COMPONENTS system regex REQUIRED)
find_package(Threads)

target_link_libraries(otus_10_1
        ${Boost_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        )
