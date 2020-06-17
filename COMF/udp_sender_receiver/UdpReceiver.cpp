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
#include <cstring>
#include <sstream>

#include "UdpReceiver.h"
#include "COMFLogger.h"

namespace DUUF {
namespace COMF {
namespace UDP {

UdpReceiver::UdpReceiver( std::string const& addr, const int& port, const int& family, std::string const* multicast_addr ) :
        UdpBase(addr, port, family) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "");
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
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Cannot Bind Socket (error = " << e << " )");
    }
    // are we creating a server to liste to multicast packets?
    if ( multicast_addr != nullptr ) {
        LOG4CXX_TRACE(COMF_Logger::getLogger(), "Multicast Address");
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
            LOG4CXX_ERROR(COMF_Logger::getLogger(), "Cannot get multicast address info");
        }

        //both address must have the right size
        if ( a == nullptr || a->ai_addrlen != sizeof(mreq.imr_multiaddr) || l_udp_addrinfo->ai_addrlen != sizeof(mreq.imr_address) ) {
            LOG4CXX_ERROR(COMF_Logger::getLogger(), "Wrong Size of Address");
        }
        if ( a != nullptr ) {
            memcpy(&mreq.imr_multiaddr, a->ai_addr->sa_data, sizeof(mreq.imr_multiaddr));
            memcpy(&mreq.imr_address, l_udp_addrinfo->ai_addr->sa_data, sizeof(mreq.imr_address));
            mreq.imr_ifindex = 0; //no specific interface

            r = setsockopt(l_udp_socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
            if ( r < 0 ) {
                int const e(errno);
                LOG4CXX_ERROR(COMF_Logger::getLogger(), "setsockopt error" << e);
            }

            // setup the multicast to 0 so we don't receive other's message
            int multicast_all = 0;
            r = setsockopt(l_udp_socket, IPPROTO_IP, IP_MULTICAST_ALL, &multicast_all, sizeof(multicast_all));
            if ( r < 0 ) {
                //Still work also without IP_MULTICAST_ALL set to 0
                int const e(errno);
                LOG4CXX_ERROR(COMF_Logger::getLogger(), "setsockopt error" << e);
            }
        }
    }

}

size_t UdpReceiver::recv( char* msg, size_t max_size ) const {
    size_t bytes_received = 0;
    memset(msg, 0, max_size);
    bytes_received = ::recv(l_udp_socket, msg, max_size, 0);
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Received " << bytes_received << " Bytes");
    return bytes_received;
}

size_t UdpReceiver::timed_recv( char* msg, size_t const max_size, int const max_wait_ms ) const {
    memset(msg, 0, max_size);
    struct pollfd fd;
    fd.events = POLLIN | POLLPRI | POLLRDHUP;
    fd.fd = l_udp_socket;
    int const retval(poll(&fd, 1, max_wait_ms));
    if ( retval == -1 ) {
        LOG4CXX_WARN(COMF_Logger::getLogger(), "Timeout Expired (no data received)");
        return -1;
    } else if ( retval > 0 ) {
        //our socket has data
        size_t bytes_received = 0;
        bytes_received = ::recv(l_udp_socket, msg, max_size, 0);
        LOG4CXX_TRACE(COMF_Logger::getLogger(), "Received " << bytes_received << " Bytes");
        return bytes_received;
    }

    //our socket has no data
    LOG4CXX_WARN(COMF_Logger::getLogger(), "Timeout Expired (no data received)");
    errno = EAGAIN;
    return -1;
}

std::string UdpReceiver::timed_recv( int const bufsize, int const max_wait_ms ) const {
    std::vector<char> buf;
    buf.resize(bufsize + 1, '\0');
    int const r(timed_recv(&buf[0], bufsize, max_wait_ms));
    if ( r <= -1 ) {
        //Timed Out, return empty string;
        LOG4CXX_WARN(COMF_Logger::getLogger(), "Timeout Expired (no data received)");
        return std::string();
    }

    // Resize Buffer the convert to std string

    buf.resize(r + 1, '\0');

    std::string word;
    word.resize(r);
    std::copy(buf.begin(), buf.end(), word.begin());
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Received " << r << " Bytes");
    return word;
}

}
}
}

