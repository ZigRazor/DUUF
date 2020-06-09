#UDP customer
#test case 1
add_executable(customer test_case_0001/application.cpp)
target_link_libraries(customer "udp")

#test case 2
add_executable(application_receive test_case_0002/application_receive.cpp)
target_link_libraries(application_receive "udp")
add_executable(application_send test_case_0002/application_send.cpp)
target_link_libraries(application_send "udp")

