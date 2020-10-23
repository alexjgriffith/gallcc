cmake_minimum_required(VERSION 3.0.2)
project(sample VERSION 0.1.0 DESCRIPTION "A sample lua wrapper.")

set(CMAKE_CXX_FLAGS "-fPIC -g -Wno-write-strings")

set(INCLUDE_DIRECTORIES include)

set(SOURCES src/test.cpp src/utils.cpp)

## set(MAIN src/main.cpp)

set(LIB src/sample.cpp)

## add_executable(sbin ${MAIN} ${SOURCES})
## target_link_libraries(sbin ${LUA_LIBRARIES})


add_library(sample SHARED ${LIB} ${SOURCES})
set_target_properties(sample PROPERTIES PREFIX "")


if(EXISTS "${ROOT}/.lua/lib/liblua.so")
  set(LOCAL_LUA_LIBARAY .lua/lib/liblua.so)
  set(LOCAL_LUA_INCLUDE .lua/include/)
  include_directories(${INCLUDE_DIRECTORIES} ${LOCAL_LUA_INCLDUE})
  target_link_libraries(sample ${LOCAL_LUA} ${LOCAL_LUA})
else()
  find_package(Lua51 REQUIRED)
  include_directories(${INCLUDE_DIRECTORIES} ${LUA_INCLUDE_DIR})
  target_link_libraries(sample ${LOCAL_LUA} ${LUA_LIBRARIES})
endif()
