/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   UdpSender.cpp
 * Author: matteo.botticci
 *
 * Created on 11 maggio 2020, 10.52
 */

#include <arpa/inet.h>
#include <rpc/types.h>
#include <sys/poll.h>
#include <vector>
#include <string.h>
#include <sstream>

#include "UdpReceiver.h"

namespace DUUF {
namespace COMF {
namespace UDP {

UdpReceiver::UdpReceiver( std::string const& addr, const int& port, const int& family, std::string const* multicast_addr ) :
        UdpBase(addr, port, family) {
    int r = bind(l_udp_socket, l_udp_addrinfo->ai_addr, l_udp_addrinfo->ai_addrlen);
    if ( r != 0 ) {
        int const e(errno);

        char addr_buf[256];
        switch ( l_udp_addrinfo->ai_family ) {
            case AF_INET:
                inet_ntop(AF_INET, &reinterpret_cast<struct sockaddr_in*>(l_udp_addrinfo->ai_addr)->sin_addr, addr_buf, sizeof(addr_buf));
                break;
            case AF_INET6:
                inet_ntop(AF_INET6, &reinterpret_cast<struct sockaddr_in6*>(l_udp_addrinfo->ai_addr)->sin6_addr, addr_buf, sizeof(addr_buf));
                break;
            default:
                strncpy(addr_buf, "Unknown Address Family", sizeof(addr_buf));
                break;
        }
        //TODO Log Error
    }
    // are we creating a server to liste to multicast packets?
    if ( multicast_addr != nullptr ) {
        struct ip_mreqn mreq;

        std::stringstream decimal_port;
        decimal_port << l_udp_port;
        std::string port_str(decimal_port.str());

        struct addrinfo hints = addrinfo();
        hints.ai_family = family;
        hints.ai_socktype = SOCK_DGRAM;
        hints.ai_protocol = IPPROTO_UDP;

        struct addrinfo* a(nullptr);
        int r(getaddrinfo(multicast_addr->c_str(), port_str.c_str(), &hints, &a));
        if ( r != 0 || a == nullptr ) {
            //ERROR
        }

        //both address must have the right size
        if ( a->ai_addrlen != sizeof(mreq.imr_multiaddr) || l_udp_addrinfo->ai_addrlen != sizeof(mreq.imr_address) ) {
            //ERROR
        }

        memcpy(&mreq.imr_multiaddr, a->ai_addr->sa_data, sizeof(mreq.imr_multiaddr));
        memcpy(&mreq.imr_address, l_udp_addrinfo->ai_addr->sa_data, sizeof(mreq.imr_address));
        mreq.imr_ifindex = 0; //no specific interface

        r = setsockopt(l_udp_socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
        if ( r < 0 ) {
            int const e(errno);
            //TODO Log Error
        }

        // setup the multicast to 0 so we don't receive other's message
        int multicast_all = 0;
        r = setsockopt(l_udp_socket, IPPROTO_IP, IP_MULTICAST_ALL, &multicast_all, sizeof(multicast_all));
        if ( r < 0 ) {
            //Still work also without IP_MULTICAST_ALL set to 0
            int const e(errno);
            // TODO Log ERROR
        }
    }

}

size_t UdpReceiver::recv( char* msg, size_t max_size ) const {
    return ::recv(l_udp_socket, msg, max_size, 0);
}

size_t UdpReceiver::timed_recv( char* msg, size_t const max_size, int const max_wait_ms ) const {
    struct pollfd fd;
    fd.events = POLLIN | POLLPRI | POLLRDHUP;
    fd.fd = l_udp_socket;
    int const retval(poll(&fd, 1, max_wait_ms));
    if ( retval == -1 ) {
        //ERROR
        return -1;
    } else if ( retval > 0 ) {
        //our socket has data
        return ::recv(l_udp_socket, msg, max_size, 0);
    }

    //our socket has no data
    errno = EAGAIN;
    return -1;
}

std::string UdpReceiver::timed_recv( int const bufsize, int const max_wait_ms ) const {
    std::vector<char> buf;
    buf.resize(bufsize + 1, '\0');
    int const r(timed_recv(&buf[0], bufsize, max_wait_ms));
    if ( r <= -1 ) {
        //Timed Out, return empty string;
        return std::string();
    }

    // Resize Buffer the convert to std string

    buf.resize(r + 1, '\0');

    std::string word;
    word.resize(r);
    std::copy(buf.begin(), buf.end(), word.begin());

    return word;
}

}
}
}

