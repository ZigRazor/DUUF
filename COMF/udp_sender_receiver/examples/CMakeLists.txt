#UDP Sender Receiver
#test case 1
add_executable(udp_client_server_test_0001_client example1/client.cpp)
add_executable(udp_client_server_test_0001_server example1/server.cpp)
target_link_libraries(udp_client_server_test_0001_client "udp")
target_link_libraries(udp_client_server_test_0001_server "udp")

#test case 2
add_executable(udp_client_server_test_0002_client example2/client.cpp)
add_executable(udp_client_server_test_0002_server example2/server.cpp)
target_link_libraries(udp_client_server_test_0002_client "udp")
target_link_libraries(udp_client_server_test_0002_server "udp")
