cmake_minimum_required(VERSION 3.5.1)
project(utils)

set(HEADERS utils.h)
set(SOURCES utils.cc)
add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

