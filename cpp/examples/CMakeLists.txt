cmake_minimum_required(VERSION 3.21)


if(UNIX)
elseif(MSVC)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB SRC_STRATEGY FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/strategy/*.h ${CMAKE_CURRENT_SOURCE_DIR}/src/strategy/*.cpp)
file(GLOB SRC_STRATEGY_OO FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/strategy_object_oriented/*.h ${CMAKE_CURRENT_SOURCE_DIR}/src/strategy_object_oriented/*.cpp)
file(GLOB SRC_ADAPTER FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/adapter/*.h ${CMAKE_CURRENT_SOURCE_DIR}/src/adapter/*.cpp)
file(GLOB SRC_OBSERVER FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/observer/*.h ${CMAKE_CURRENT_SOURCE_DIR}/src/observer/*.cpp)
file(GLOB SRC_BRIDGE FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/bridge/*.h ${CMAKE_CURRENT_SOURCE_DIR}/src/bridge/*.cpp)

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
source_group(
    "StrategyObjectOriented" FILES ${SRC_STRATEGY_OO}
)
source_group(
    "Adapter" FILES ${SRC_ADAPTER}
)
source_group(
    "Observer" FILES ${SRC_OBSERVER}
)
source_group(
    "Bridge" FILES ${SRC_BRIDGE}
)
 add_executable(example ${SRC} ${SRC_STRATEGY} ${SRC_STRATEGY_OO} ${SRC_ADAPTER} ${SRC_OBSERVER} ${SRC_BRIDGE})
# add_executable(executor $<TARGET_OBJECTS:lib>)
endif()
