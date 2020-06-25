/*
 * TcpServer.h
 *
 *  Created on: 23 giu 2020
 *      Author: matteo
 */

#ifndef COMF_TCP_SERVER_CLIENT_TCPSERVER_H_
#define COMF_TCP_SERVER_CLIENT_TCPSERVER_H_

#include <netdb.h>
#include "TcpBase.h"

namespace DUUF {
namespace COMF {
namespace TCP {

/*
 *
 */
class TcpServer: public TcpBase {
public:
    TcpServer( std::string const& addr, const int& port, const int& family = AF_UNSPEC, unsigned int accepted_number_of_connections = 1000 );
    virtual ~TcpServer();
    TcpServer( const TcpServer& other ) = delete;
    int listen();
    void setOnMessageFunction( void (*fptr)( char*, unsigned int ) );
    void stop();

private:
    unsigned int accepted_number_of_connections;
    bool stop_server_flag;
    addrinfo* client_addr_info;
    int tcp_client_socket;

    void (*onMessageFunction_ptr)( char*, unsigned int ) = nullptr;
};

} /* namespace TCP */
} /* namespace COMF */
} /* namespace DUUF */

#endif /* COMF_TCP_SERVER_CLIENT_TCPSERVER_H_ */
