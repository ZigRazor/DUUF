/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   UdpClient.h
 * Author: matteo.botticci
 *
 * Created on 11 maggio 2020, 10.50
 */

#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include "UdpBase.h"

namespace DUUF {
namespace COMF {
namespace UDP {

class UdpClient: public UdpBase {
public:
    UdpClient( std::string const& addr, const int& port, const int& family = AF_UNSPEC );

    virtual ~UdpClient() = default;

    size_t send( const char* msg, size_t size ) const;
private:

    UdpClient( const UdpClient& orig ) = delete;
};

}
}
}

#endif /* UDP_CLIENT_H */

