cmake_minimum_required(VERSION 3.15)
project(Boost_Echo_Client)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
find_package(Boost 1.65.1 REQUIRED COMPONENTS
        date_time filesystem iostreams system)
find_package(Threads)
include_directories(include)
add_executable(Boost_Echo_Client
        include/connectionHandler.h
        include/Frame.h
        include/StompConnectionProtocal.h
        include/User.h
        include/UserCommands.h
        src/connectionHandler.cpp
        src/echoClient.cpp
        src/Frame.cpp
        src/StompConnectionProtocal.cpp
        src/User.cpp
        src/UserCommands.cpp src/Books.cpp include/Books.h src/Book.cpp include/Book.h)


target_link_libraries(Boost_Echo_Client Boost::date_time Boost::filesystem
        Boost::iostreams Boost::system)