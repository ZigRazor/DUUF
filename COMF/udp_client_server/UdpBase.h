/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   udp_base.h
 * Author: matteo.botticci
 *
 * Created on 11 maggio 2020, 10.52
 */

#ifndef UDP_BASE_H
#define UDP_BASE_H

#include <string>
#include <netdb.h>

namespace DUUF {
namespace COMF {
namespace UDP {

class UdpBase {
public:

    int get_socket() const;
    int get_port() const;
    std::string get_address() const;

protected:

    UdpBase( const std::string& address, const int& port, const int& family );
    virtual ~UdpBase();

    int l_udp_socket;
    int l_udp_port;
    std::string l_udp_address;
    struct addrinfo* l_udp_addrinfo;
private:
    UdpBase( const UdpBase& orig ) = delete;
};

}
}
}

#endif /* UDP_BASE_H */

