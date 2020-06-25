/*
 * TcpBase.cpp
 *
 *  Created on: 23 giu 2020
 *      Author: matteo
 */

#include "TcpBase.h"

#include <sstream>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "COMFLogger.h"

namespace DUUF {
namespace COMF {
namespace TCP {

TcpBase::TcpBase( const std::string& address, const int& port, const int& family ) :
        l_tcp_address(address), l_tcp_port(port) {
    if ( l_tcp_address.empty() ) {
        //ERROR
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Address String Empty");
    }

    if ( l_tcp_port < 0 || l_tcp_port > 65536 ) {
        //ERROR
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Not Valid tcp port");
    }

    std::stringstream decimal_port;
    decimal_port << l_tcp_port;
    std::string port_str(decimal_port.str());

    struct addrinfo hints = addrinfo();
    hints.ai_family = family;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    //struct addrinfo *info;
    int const r(getaddrinfo(l_tcp_address.c_str(), port_str.c_str(), &hints, &l_tcp_addrinfo));
    if ( r != 0 || l_tcp_addrinfo == nullptr ) {
        //ERROR
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Cannot get Address Info");
    }

    l_tcp_socket = socket(l_tcp_addrinfo->ai_family, SOCK_STREAM | SOCK_CLOEXEC, IPPROTO_TCP);
    if ( l_tcp_socket == -1 ) {
        //ERROR
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Cannot Open Socket");
    }
}

TcpBase::~TcpBase() {
    close(l_tcp_socket);
    if ( l_tcp_addrinfo ) {
        delete l_tcp_addrinfo;
    }
}

int TcpBase::get_socket() const {
    return l_tcp_socket;
}

int TcpBase::get_port() const {
    return l_tcp_port;
}

std::string TcpBase::get_address() const {
    return l_tcp_address;
}

} /* namespace TCP */
} /* namespace COMF */
} /* namespace DUUF */
