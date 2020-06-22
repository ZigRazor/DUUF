/*
 * UdpConnection.h
 *
 *  Created on: 5 giu 2020
 *      Author: matteo
 */

#ifndef COMF_UDP_CUSTOMER_UDPCONNECTION_H_
#define COMF_UDP_CUSTOMER_UDPCONNECTION_H_

#include "UdpReceiver.h"
#include "UdpSender.h"
#include "UdpConnectionType.h"

namespace DUUF {
namespace COMF {
namespace UDP {

/*
 *
 */
class UdpConnection {
public:
    UdpConnection( const std::string& name, const Send_Receive_Mode_Enum& mode, std::string const& addr, const int& port, const int& family = AF_UNSPEC );
    virtual ~UdpConnection();
    UdpConnection( const UdpConnection& other ) = delete;

    int enableSend();
    int enableReceive();
    int disableSend();
    int disableReceive();
    int getFamily() const;
    Send_Receive_Mode_E getMode() const;
    const std::string& getName() const;
    int getPort() const;
    const std::string& getUdpAddr() const;

    long send( const char* msg, size_t size ) const;
    long recv( char* msg, size_t max_size ) const;
    long timed_recv( char* msg, size_t const max_size, int const max_wait_ms ) const;

private:

    std::string name;
    std::string udp_addr;
    int port;
    int family;
    Send_Receive_Mode_E mode;
    UdpReceiver* receiver;
    UdpSender* sender;
};

} /* namespace UDP */
} /* namespace COMF */
} /* namespace DUUF */

#endif /* COMF_UDP_CUSTOMER_UDPCONNECTION_H_ */
