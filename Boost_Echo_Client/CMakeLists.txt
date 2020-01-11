cmake_minimum_required(VERSION 3.15)
project(Boost_Echo_Client)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)

find_package(Boost 1.65.1 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

include_directories(.)
include_directories(bin)
include_directories(cmake-build-debug)
include_directories(include)
include_directories(src)

add_executable(Boost_Echo_Client
        include/connectionHandler.h
        src/connectionHandler.cpp
        src/echoClient.cpp
        makefile include/Frame.h src/Frame.cpp include/StompMessageProtocol.h include/StompMessageEncoderDecoder.h include/StompConnectionHandler.h)

target_link_libraries(Boost_Echo_Client ${Boost_LIBRARIES})