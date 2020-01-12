cmake_minimum_required(VERSION 3.15)
project(Boost_Echo_Client)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Boost_Echo_Client
        include/connectionHandler.h
        include/Frame.h
        include/User.h
        include/UserCommands.h
        src/connectionHandler.cpp
        src/echoClient.cpp
        src/Frame.cpp
        src/User.cpp
        src/UserCommands.cpp src/StompConnectionProtocal.cpp include/StompConnectionProtocal.h)
