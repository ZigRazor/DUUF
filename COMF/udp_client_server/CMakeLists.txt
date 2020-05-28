cmake_minimum_required(VERSION 2.8)

#set the project name
add_subdirectory(tests)

#specify the C++ Standard
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11" ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(udp SHARED UdpBase.cpp UdpClient.cpp UdpServer.cpp)
#target_include_directories(master_election PUBLIC /home/matteo.botticci/SCM/prove_varie)
