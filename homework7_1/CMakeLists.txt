cmake_minimum_required(VERSION 3.5)

project(otus_7_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(otus_7_1 main.cpp filescomparator.cpp filescomparator.h scannedfile.cpp scannedfile.h)

find_package(Boost REQUIRED COMPONENTS
    date_time filesystem iostreams program_options regex)

target_link_libraries(otus_7_1 Boost::date_time Boost::filesystem
                          Boost::iostreams Boost::program_options Boost::regex)
