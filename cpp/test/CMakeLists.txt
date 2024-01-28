cmake_minimum_required(VERSION 3.21)

if(UNIX)
elseif(MSVC)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB sources FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_definitions(
    "/utf-8"
)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG f8d7d77 #v1.14
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
# file(GLOB sources FILES ${})
source_group(
    "Code" FILES ${sources}
)
 add_executable(unit_test ${sources})

 target_link_libraries(unit_test
 GTest::gmock
 GTest::gtest
 GTest::gtest_main
 )

 set_target_properties(
     gmock gtest gmock_main gtest_main PROPERTIES FOLDER "Libs"
 )


 include(GoogleTest)
 gtest_discover_tests(unit_test)
# add_executable(executor $<TARGET_OBJECTS:lib>)
endif()
