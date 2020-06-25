include_directories(${PROJECT_DIR})
include_directories(${COMF_DIR})
include_directories(${COMF_DIR}/udp_sender_receiver)
include_directories(${COMF_DIR}/udp_customer)
include_directories(${COMF_DIR}/udp_message_queue)
include_directories(${COMF_DIR}/message)
include_directories(${COMF_DIR}/serialization)


set(TESTS_DIR ${PROJECT_DIR}/TEST)
link_directories(${TESTS_DIR} )
	
add_executable( test_suite test_main.cpp 
	COMF/test_udp_sender.cpp 
	COMF/test_udp_receiver.cpp 
	COMF/test_udp_customer.cpp 
	COMF/test_message.cpp
	COMF/test_udpmessagequeue.cpp
	COMF/test_serialization.cpp
	COMF/test_tcp_server.cpp
	COMF/test_tcp_client.cpp
)
target_link_libraries( test_suite 
	"libgtest.a" 
	"libgtest_main.a"
	"pthread"
	"udp"
	"tcp"
)

