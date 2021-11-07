cmake_minimum_required(VERSION 3.7)

project(otus_9_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(otus_9_1 main.cpp commandsserver.h commandsserver.cpp commandsession.h commandsession.cpp commandsoutput.h commandsoutput.cpp)

find_package(Boost COMPONENTS system REQUIRED)
find_package(Threads)

target_link_libraries(otus_9_1
        ${Boost_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        )
