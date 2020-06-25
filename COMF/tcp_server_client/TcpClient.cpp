/*
 * TcpClient.cpp
 *
 *  Created on: 23 giu 2020
 *      Author: matteo
 */

#include <thread>
#include "TcpClient.h"
#include <sys/socket.h>
#include <unistd.h>
#include "COMFLogger.h"

#define TCP_MAX_MSG_LEN 65535

namespace DUUF {
namespace COMF {
namespace TCP {

TcpClient::TcpClient( std::string const& addr, const int& port, const int& family ) :
        TcpBase(addr, port, family) {
    terminate_connection_flag = false;
    connected = false;
}

void TcpClient::connect() {
    //Connect to Host Node
    if ( !connected ) {
        int connResult = ::connect(l_tcp_socket, l_tcp_addrinfo->ai_addr, sizeof(*(l_tcp_addrinfo->ai_addr)));

        if ( connResult == 0 ) {

            auto connectionHandle = [ this ]() {
                while ( !terminate_connection_flag ) {
                    char message[TCP_MAX_MSG_LEN];
                    //receive incoming message from host
                    int messagelength = recvfrom(l_tcp_socket, message, TCP_MAX_MSG_LEN, 0, NULL, NULL);

                    //check if message is not empty
                    if ( messagelength > 0 ) {
                        LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Message Received");

                    }
                }

                //check if terminate connection flag is on
                if ( terminate_connection_flag ) {

                    //close host connection socket
                    close(l_tcp_socket);

                    //reset terminate connection flag
                    terminate_connection_flag = 0;
                }
                return;
            };

            std::thread thr_connHandler(connectionHandle);
            connected = true;
        } else {
            LOG4CXX_WARN(COMF_Logger::getLogger(), "Cannot connect");
        }
    } else {
        LOG4CXX_INFO(COMF_Logger::getLogger(), "Already Connected");
    }

}

size_t TcpClient::send( const char* msg, size_t size ) const {
    if ( connected ) {
        size_t bytes_sent = 0;
        bytes_sent = sendto(l_tcp_socket, msg, size, 0, l_tcp_addrinfo->ai_addr, l_tcp_addrinfo->ai_addrlen);
        LOG4CXX_TRACE(COMF_Logger::getLogger(), bytes_sent << " bytes sent");
        return bytes_sent;
    } else {
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Cannot Send (Socket not connected)");
        return -1;
    }

}

void TcpClient::stop() {
    terminate_connection_flag = true;
}

bool TcpClient::isConnected() const {
    return connected;
}

}/* namespace TCP */
} /* namespace COMF */
} /* namespace DUUF */
