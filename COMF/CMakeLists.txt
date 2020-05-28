cmake_minimum_required(VERSION 2.8)

#set the project name

include_directories(udp_client_server)
include_directories(message)
include_directories(udp_message_queue)

include_directories(/usr/include/tirpc) #ADDED for rpc/types.h include (need libtirpc-devel installed)


add_subdirectory(udp_client_server)
add_subdirectory(message)
add_subdirectory(udp_message_queue)

