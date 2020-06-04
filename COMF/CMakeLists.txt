include_directories(udp_sender_receiver)
include_directories(message)
include_directories(udp_message_queue)
include_directories(serialization)

include_directories(/usr/include/tirpc) #ADDED for rpc/types.h include (need libtirpc-devel installed)


add_subdirectory(udp_sender_receiver)
add_subdirectory(message)
add_subdirectory(udp_message_queue)
add_subdirectory(serialization)

