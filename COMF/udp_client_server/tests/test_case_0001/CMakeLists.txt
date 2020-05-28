cmake_minimum_required(VERSION 2.8)

#set the project name

#specify the C++ Standard
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11" ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(udp_client_server_test_0001_client client.cpp)
add_executable(udp_client_server_test_0001_server server.cpp)

target_include_directories(udp_client_server_test_0001_client PUBLIC ${PROJECT_DIR}/udp_client_server)
target_include_directories(udp_client_server_test_0001_server PUBLIC ${PROJECT_DIR}/udp_client_server)

target_link_libraries(udp_client_server_test_0001_client "udp")
target_link_libraries(udp_client_server_test_0001_server "udp")

