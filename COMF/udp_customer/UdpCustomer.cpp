/*
 * UdpCustomer.cpp
 *
 *  Created on: 5 giu 2020
 *      Author: matteo
 */

#include "UdpCustomer.h"

namespace DUUF {
namespace COMF {
namespace UDP {

UdpCustomer::UdpCustomer() {
    connections.clear();
}

UdpCustomer::~UdpCustomer() {
    connections.clear();
}

int UdpCustomer::openConnection( const std::string& name, const Send_Receive_Mode_Enum& mode, const std::string& addr, const int& port, const int& family ) {
    if ( connections.find(name) != connections.end() ) {
        //connection name already used
        return -1;
    } else {
        UdpConnection newConnection(name, mode, addr, port, family);
        connections.insert(std::make_pair(name, newConnection));
    }
    return 0;
}

int UdpCustomer::closeConnection( const std::string& name ) {
    std::map<std::string, UdpConnection>::iterator connectionsIt = connections.find(name);
    if ( connectionsIt == connections.end() ) {
        //no connection open with this name
        return -1;
    } else {
        connections.erase(connectionsIt);
    }
    return 0;
}

int UdpCustomer::enableConnectionSend( const std::string& name ) {
    std::map<std::string, UdpConnection>::iterator connectionsIt = connections.find(name);
    if ( connectionsIt == connections.end() ) {
        //no connection open with this name
        return -1;
    } else {
        if ( connectionsIt->second.enableSend() == -1 ) {
            //connection already open in send mode
            return -2;
        }
    }
    return 0;
}

int UdpCustomer::enableConnectionReceive( const std::string& name ) {
    std::map<std::string, UdpConnection>::iterator connectionsIt = connections.find(name);
    if ( connectionsIt == connections.end() ) {
        //no connection open with this name
        return -1;
    } else {
        if ( connectionsIt->second.enableReceive() == -1 ) {
            //connection already open in receive mode
            return -2;
        }
    }
    return 0;
}

} /* namespace UDP */
} /* namespace COMF */
} /* namespace DUUF */
