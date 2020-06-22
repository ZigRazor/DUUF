#UDP customer
#test case 1
add_executable(customer example1/application.cpp)
target_link_libraries(customer "udp")

#test case 2
add_executable(application_receive example2/application_receive.cpp)
target_link_libraries(application_receive "udp")
add_executable(application_send example2/application_send.cpp)
target_link_libraries(application_send "udp")

