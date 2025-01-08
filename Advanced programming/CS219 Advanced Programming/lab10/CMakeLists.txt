cmake_minimum_required(VERSION 3.10)
project(Lab10)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/liba LIBA_SOURCES)
add_library(liba STATIC ${LIBA_SOURCES})

aux_source_directory(${PROJECT_SOURCE_DIR}/libs LIBS_SOURCES)
add_library(libs SHARED ${LIBS_SOURCES})

add_executable(main main.cpp)

target_link_libraries(main liba libs)