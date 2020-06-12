cmake_minimum_required(VERSION 3.17.2)
project(deezer-api-cpp)

set(CMAKE_CXX_STANDARD 17)

set(DEEZER_API_++_VERSION 1.0)

find_package(CURL)
set(LIBS ${LIBS} ${CURL_LIBRARIES})
include_directories(${CURL_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(src)

add_executable(GoogleTest test/tests.cpp)

target_link_libraries(GoogleTest
        gtest
        gtest_main
        deezer-api-cpp
        pthread
        )
