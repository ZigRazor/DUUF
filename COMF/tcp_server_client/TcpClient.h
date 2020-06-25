/*
 * TcpClient.h
 *
 *  Created on: 23 giu 2020
 *      Author: matteo
 */

#ifndef COMF_TCP_SERVER_CLIENT_TCPCLIENT_H_
#define COMF_TCP_SERVER_CLIENT_TCPCLIENT_H_

#include <netdb.h>
#include "TcpBase.h"

namespace DUUF {
namespace COMF {
namespace TCP {

/*
 *
 */
class TcpClient: public TcpBase {
public:
    TcpClient( std::string const& addr, const int& port, const int& family = AF_UNSPEC );
    virtual ~TcpClient() = default;
    TcpClient( const TcpClient& other ) = delete;

    void connect();

    size_t send( const char* msg, size_t size ) const;

    void stop();
    bool isConnected() const;

private:
    bool terminate_connection_flag;
    bool connected;
};

} /* namespace TCP */
} /* namespace COMF */
} /* namespace DUUF */

#endif /* COMF_TCP_SERVER_CLIENT_TCPCLIENT_H_ */
