cmake_minimum_required(VERSION 2.8)

#set the project name
add_subdirectory(test_case_0001)
add_subdirectory(test_case_0002)
#specify the C++ Standard
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11" ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_STANDARD_REQUIRED True)

#target_include_directories(master_election PUBLIC /home/matteo.botticci/SCM/prove_varie)
