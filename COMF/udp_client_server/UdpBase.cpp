/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   UdpBase.cpp
 * Author: matteo.botticci
 *
 * Created on 11 maggio 2020, 10.52
 */

#include "UdpBase.h"
#include <sstream>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <iostream>

namespace DUUF {
namespace COMF {
namespace UDP {

UdpBase::UdpBase( const std::string& address, const int& port, const int& family ) :
        l_udp_address(address), l_udp_port(port) {
    if ( l_udp_address.empty() ) {
        //ERROR
    }

    if ( l_udp_port < 0 || l_udp_port > 65536 ) {
        //ERROR
    }

    std::stringstream decimal_port;
    decimal_port << l_udp_port;
    std::string port_str(decimal_port.str());

    struct addrinfo hints = addrinfo();
    hints.ai_family = family;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;

    //struct addrinfo *info;
    int const r(getaddrinfo(l_udp_address.c_str(), port_str.c_str(), &hints, &l_udp_addrinfo));
    if ( r != 0 || l_udp_addrinfo == nullptr ) {
        //ERROR
    }

    l_udp_socket = socket(l_udp_addrinfo->ai_family, SOCK_DGRAM | SOCK_CLOEXEC, IPPROTO_UDP);
    if ( l_udp_socket == -1 ) {
        //ERROR
    }
    //std::cout << "creato UdpBase" << std::endl;
}

UdpBase::~UdpBase() {
    close(l_udp_socket);
    if ( l_udp_addrinfo ) {
        delete l_udp_addrinfo;
    }
}

int UdpBase::get_socket() const {
    return l_udp_socket;
}

int UdpBase::get_port() const {
    return l_udp_port;
}

std::string UdpBase::get_address() const {
    return l_udp_address;
}

}
}
}
