cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(LogiParser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(LogiLib STATIC 
    src/MessageParser.cpp    
    src/Printer.cpp 
)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} LogiLib)