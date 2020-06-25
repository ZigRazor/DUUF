/*
 * TcpServer.cpp
 *
 *  Created on: 23 giu 2020
 *      Author: matteo
 */

#include <thread>
#include <sys/socket.h>
#include <unistd.h>
#include "TcpServer.h"
#include "COMFLogger.h"

#define TCP_MAX_MSG_LEN 65535

namespace DUUF {
namespace COMF {
namespace TCP {

TcpServer::TcpServer( std::string const& addr, const int& port, const int& family, unsigned int accepted_number_of_connections ) :
        TcpBase(addr, port, family) {
    this->accepted_number_of_connections = accepted_number_of_connections;
    stop_server_flag = false;
    client_addr_info = nullptr;
    tcp_client_socket = -1;
}

TcpServer::~TcpServer() {
    if ( client_addr_info ) {
        delete (client_addr_info);
    }
}

int TcpServer::listen() {
    int bind_result = ::bind(l_tcp_socket, l_tcp_addrinfo->ai_addr, l_tcp_addrinfo->ai_addrlen);

    int listen_result = ::listen(l_tcp_socket, accepted_number_of_connections);

    if ( listen_result != 0 || bind_result != 0 ) {
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Bind or Listen Failed");
        return -1;
    }

    while ( true ) {
        if ( stop_server_flag ) {
            LOG4CXX_INFO(COMF_Logger::getLogger(), "Server is Stopped");
            stop_server_flag = false;
            break;
        }
        if ( !client_addr_info ) {
            client_addr_info = new struct addrinfo;
        }

        client_addr_info->ai_addrlen = sizeof(client_addr_info->ai_addrlen);

        tcp_client_socket = ::accept(l_tcp_socket, client_addr_info->ai_addr, &(client_addr_info->ai_addrlen));

        if ( tcp_client_socket == -1 ) {
            continue;
        }
        LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Connection accepted - " << tcp_client_socket);

        auto connectionHandle = [ this ]() {
            while ( 1 ) {
                char message[TCP_MAX_MSG_LEN];
                //receive a message from client to msg buffer
                int messagelength = recvfrom(tcp_client_socket, message, TCP_MAX_MSG_LEN, 0, client_addr_info->ai_addr, &(client_addr_info->ai_addrlen));

                //check if there is no more messages
                if ( messagelength <= 0 ) {
                    close(tcp_client_socket);
                    LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Connection lost - " << tcp_client_socket);
                    break;
                }

                // execute OnMessage function if available
                if ( onMessageFunction_ptr != nullptr ) {
                    onMessageFunction_ptr(message, messagelength);
                }
            }
            return;
        };

        std::thread thr_connHandler(connectionHandle);

    }
    return 0;

}
void TcpServer::setOnMessageFunction( void (*fptr)( char*, unsigned int ) ) {
    onMessageFunction_ptr = fptr;
}
void TcpServer::stop() {
    stop_server_flag = true;
}

} /* namespace TCP */
} /* namespace COMF */
} /* namespace DUUF */
