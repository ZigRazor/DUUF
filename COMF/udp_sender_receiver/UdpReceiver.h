/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   UdpSender.h
 * Author: matteo.botticci
 *
 * Created on 11 maggio 2020, 10.52
 */

#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include "UdpBase.h"

namespace DUUF {
namespace COMF {
namespace UDP {

class UdpReceiver: public UdpBase {
public:
    UdpReceiver( std::string const& addr, const int& port, const int& family = AF_UNSPEC, std::string const* multicast_addr = nullptr );
    virtual ~UdpReceiver() = default;

    size_t recv( char* msg, size_t max_size ) const;
    size_t timed_recv( char* msg, size_t const max_size, int const max_wait_ms ) const;
    std::string timed_recv( int const bufsize, int const max_wait_ms ) const;
private:
    UdpReceiver( const UdpReceiver& orig ) = delete;
};

}
}
}

#endif /* UDP_SERVER_H */

