cmake_minimum_required(VERSION 3.8.2)
project(sample VERSION 0.1.0 DESCRIPTION "A sample lua wrapper.")

set(INCLUDE_DIRECTORIES include)

# Set Lua Library and Include Locations
# LOCAL options are used with the CI

if(UNIX)
  set(CMAKE_CXX_FLAGS "-fPIC -g -Wno-write-strings")
  set(LOCAL_LUA_LIBRARY_LOCATION .lua/lib/liblua.so)
  set(LOCAL_LUA_INCLUDE_LOCATION .lua/include)
elseif(APPLE)
  set(CMAKE_CXX_FLAGS "-fPIC -g -Wno-write-strings")
  set(LOCAL_LUA_LIBRARY_LOCATION .lua/lib/liblua.dylib)
  set(LOCAL_LUA_INCLUDE_LOCATION .lua/include)
elseif(WIN32)
  set(LOCAL_LUA_LIBRARY_LOCATION .lua/lib/liblua.dll)
  set(LOCAL_LUA_INCLUDE_LOCATION .lua/include)
else()
  message("Only supports Linux, Macos and Windows.")
endif()

if(EXISTS "${PROJECT_SOURCE_DIR}/${LOCAL_LUA_LIBRARY_LOCATION}")
  set(LUA_LIBRARIES "${PROJECT_SOURCE_DIR}/${LOCAL_LUA_LIBRARY_LOCATION}")
  set(LUA_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/${LOCAL_LUA_INCLUDE_LOCATION}")
else()
  find_package(Lua51 REQUIRED)
endif()

set(SOURCES src/test.cpp src/utils.cpp)

set(LIB src/sample.cpp)

add_library(sample SHARED ${LIB} ${SOURCES})
include_directories(${INCLUDE_DIRECTORIES} ${LUA_INCLUDE_DIR})
target_link_libraries(sample ${LUA_LIBRARIES})
set_target_properties(sample PROPERTIES PREFIX "")
