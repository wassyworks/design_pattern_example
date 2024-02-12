cmake_minimum_required(VERSION 3.21)


if(UNIX)
elseif(MSVC)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB SRC_STRATEGY FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/strategy/*.h ${CMAKE_CURRENT_SOURCE_DIR}/src/strategy/*.cpp)

add_definitions(
    "/utf-8"
)
# file(GLOB sources FILES ${})
source_group(
    "Main" FILES ${SRC}
)
source_group(
    "Strategy" FILES ${SRC_STRATEGY}
)
 add_executable(example ${SRC} ${SRC_STRATEGY})
# add_executable(executor $<TARGET_OBJECTS:lib>)
endif()
