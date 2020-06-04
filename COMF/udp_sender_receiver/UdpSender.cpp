/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   UdpReceiver.cpp
 * Author: matteo.botticci
 *
 * Created on 11 maggio 2020, 10.50
 */

#include <iostream>
#include "UdpSender.h"

namespace DUUF {
namespace COMF {
namespace UDP {

UdpSender::UdpSender( std::string const& addr, const int& port, const int& family ) :
        UdpBase(addr, port, family) {
    //std::cout << "creato client" << std::endl;
}

size_t UdpSender::send( const char* msg, size_t size ) const {
    return sendto(l_udp_socket, msg, size, 0, l_udp_addrinfo->ai_addr, l_udp_addrinfo->ai_addrlen);
}

}
}
}
