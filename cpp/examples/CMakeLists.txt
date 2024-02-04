cmake_minimum_required(VERSION 3.21)


if(UNIX)
elseif(MSVC)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB sources FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_definitions(
    "/utf-8"
)
# file(GLOB sources FILES ${})
source_group(
    "Code" FILES ${sources}
)
 add_executable(example ${sources})
# add_executable(executor $<TARGET_OBJECTS:lib>)
endif()
