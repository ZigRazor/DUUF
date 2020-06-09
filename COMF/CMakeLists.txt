include_directories(udp_sender_receiver)
include_directories(udp_customer)
include_directories(udp_message_queue)
include_directories(message)
include_directories(serialization)

include_directories(/usr/include/tirpc) #ADDED for rpc/types.h include (need libtirpc-devel installed)


add_subdirectory(udp_sender_receiver/tests)
add_subdirectory(udp_customer/tests)
add_subdirectory(message)
#add_subdirectory(udp_message_queue)
add_subdirectory(serialization)

add_library(udp SHARED 
	udp_sender_receiver/UdpBase.cpp 
	udp_sender_receiver/UdpSender.cpp 
	udp_sender_receiver/UdpReceiver.cpp
	udp_customer/UdpConnection.cpp 
	udp_customer/UdpCustomer.cpp
	udp_message_queue/UdpMessageQueue.cpp 
	)
