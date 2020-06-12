include_directories(udp_sender_receiver)
include_directories(udp_customer)
include_directories(udp_message_queue)
include_directories(message)
include_directories(serialization)

include_directories(/usr/include/tirpc) #ADDED for rpc/types.h include (need libtirpc-devel installed)

set(TESTS_DIR ${PROJECT_DIR}/TEST)
link_directories(${TESTS_DIR} )
	
add_executable( test_suite test_main.cpp test_example.cpp test_udp_sender.cpp)
target_link_libraries( test_suite 
"libgtest.a" 
"libgtest_main.a"
"pthread"
"udp"
)

