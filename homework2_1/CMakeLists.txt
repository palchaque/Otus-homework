cmake_minimum_required(VERSION 3.5)

add_definitions(-std=gnu++14)

if ($ENV{TRAVIS_BUILD_NUMBER})
    project(custom_allocator VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(custom_allocator VERSION 0.0.4)
endif()

add_executable(${PROJECT_NAME} "main.cpp" "pretty.h" "custom_allocator.cpp" "custom_list.cpp")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(benchmark REQUIRED)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
