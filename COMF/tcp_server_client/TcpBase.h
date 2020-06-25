/*
 * TcpBase.h
 *
 *  Created on: 23 giu 2020
 *      Author: matteo
 */

#ifndef COMF_TCP_SERVER_CLIENT_TCPBASE_H_
#define COMF_TCP_SERVER_CLIENT_TCPBASE_H_

#include <string>
#include <netdb.h>

namespace DUUF {
namespace COMF {
namespace TCP {

/*
 *
 */
class TcpBase {
public:
public:

    int get_socket() const;
    int get_port() const;
    std::string get_address() const;

protected:

    TcpBase( const std::string& address, const int& port, const int& family );
    virtual ~TcpBase();

    int l_tcp_socket;
    int l_tcp_port;
    std::string l_tcp_address;
    struct addrinfo* l_tcp_addrinfo;
private:
    TcpBase( const TcpBase& orig ) = delete;
};

} /* namespace TCP */
} /* namespace COMF */
} /* namespace DUUF */

#endif /* COMF_TCP_SERVER_CLIENT_TCPBASE_H_ */
