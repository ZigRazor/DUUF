/*
 * UdpCustomer.h
 *
 *  Created on: 5 giu 2020
 *      Author: matteo
 */

#ifndef COMF_UDP_CUSTOMER_UDPCUSTOMER_H_
#define COMF_UDP_CUSTOMER_UDPCUSTOMER_H_

#include <map>
#include "UdpConnection.h"

namespace DUUF {
namespace COMF {
namespace UDP {

/*
 *
 */
class UdpCustomer {
public:

    UdpCustomer();
    virtual ~UdpCustomer();
    UdpCustomer( const UdpCustomer& other ) = delete;

    int openConnection( const std::string& name, const Send_Receive_Mode_Enum& mode, std::string const& addr, const int& port, const int& family = AF_UNSPEC );
    int closeConnection( const std::string& name );
    int enableConnectionSend( const std::string& name );
    int enableConnectionReceive( const std::string& name );
private:

    bool isConnectionOpen( const std::string& name );

    std::map<std::string, UdpConnection> connections;
};

} /* namespace UDP */
} /* namespace COMF */
} /* namespace DUUF */

#endif /* COMF_UDP_CUSTOMER_UDPCUSTOMER_H_ */
