cmake_minimum_required(VERSION 3.16)
project(editor)

if ($ENV{TRAVIS_BUILD_NUMBER})
    project(bulk VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(bulk VERSION 0.0.4)
endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp editor_model.cpp editor_model.h editor_image.cpp editor_image.h editor_controller.cpp editor_controller.h editor_view.cpp editor_view.h)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
