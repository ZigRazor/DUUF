cmake_minimum_required(VERSION 2.8)

#set the project name
#project(MasterElection VERSION 1.0)
project(DUUF)

#configure_file(master_election.h.in master_election.h)

set(PROJECT_DIR ${PROJECT_SOURCE_DIR})
set(COMF_DIR ${PROJECT_DIR}/COMF)

add_subdirectory(COMF)
#add the executable
add_executable(MasterElection main.cpp)

target_link_libraries(MasterElection udp)
#specify the C++ Standard
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11" ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_library(udp SHARED udp_base.cpp udp_client.cpp udp_server.cpp)
target_include_directories(MasterElection PUBLIC "${COMF_DIR}" "${COMF_DIR}/udp_client_server")
