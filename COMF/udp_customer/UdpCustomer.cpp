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
}

UdpCustomer::~UdpCustomer() {
    connections.clear();
}

int UdpCustomer::openConnection( const std::string& name, const Send_Receive_Mode_Enum& mode, const std::string& addr, const int& port, const int& family ) {
    if ( isConnectionOpen(name) ) {
        //connection name already used
        return -1;
    } else {
        std::shared_ptr<UdpConnection> newConnection = std::make_shared<UdpConnection>(name, mode, addr, port, family);
        connections.insert(std::make_pair(name, newConnection));
    }
    return 0;
}

int UdpCustomer::closeConnection( const std::string& name ) {
    std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
    if ( !isConnectionOpen(name) ) {
        //no connection open with this name
        return -1;
    } else {
        std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
        connections.erase(connectionsIt);
    }
    return 0;
}

int UdpCustomer::enableConnectionSend( const std::string& name ) {
    if ( !isConnectionOpen(name) ) {
        //no connection open with this name
        return -1;
    } else {
        std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
        if ( connectionsIt->second.get()->enableSend() == -1 ) {
            //connection already open in send mode
            return -2;
        }
    }
    return 0;
}

int UdpCustomer::enableConnectionReceive( const std::string& name ) {
    if ( !isConnectionOpen(name) ) {
        //no connection open with this name
        return -1;
    } else {
        std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
        if ( connectionsIt->second.get()->enableReceive() == -1 ) {
            //connection already open in receive mode
            return -2;
        }
    }
    return 0;
}

long UdpCustomer::send( const char* msg, size_t size, const std::string& name ) const {
    std::map<std::string, std::shared_ptr<UdpConnection>>::const_iterator connectionsIt = connections.find(name);
    if ( connectionsIt == connections.end() ) {
        //Connections not found
        return -1;
    } else {
        return connectionsIt->second.get()->send(msg, size);
    }
}

long UdpCustomer::recv( char* msg, size_t max_size, const std::string& name ) const {
    std::map<std::string, std::shared_ptr<UdpConnection>>::const_iterator connectionsIt = connections.find(name);
    if ( connectionsIt == connections.end() ) {
        //Connections not found
        return -1;
    } else {
        return connectionsIt->second.get()->recv(msg, max_size);
    }
}

long UdpCustomer::timed_recv( char* msg, const size_t max_size, const int max_wait_ms, const std::string& name ) const {
    std::map<std::string, std::shared_ptr<UdpConnection>>::const_iterator connectionsIt = connections.find(name);
    if ( connectionsIt == connections.end() ) {
        //Connections not found
        return -1;
    } else {
        return connectionsIt->second.get()->timed_recv(msg, max_size, max_wait_ms);
    }
}

int UdpCustomer::disableConnectionSend( const std::string& name ) {
    if ( !isConnectionOpen(name) ) {
        //no connection open with this name
        return -1;
    } else {
        std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
        if ( connectionsIt->second.get()->disableSend() == -1 ) {
            //connection already open in receive mode
            return -2;
        }
    }
    return 0;
}

int UdpCustomer::disableConnectionReceive( const std::string& name ) {
    if ( !isConnectionOpen(name) ) {
        //no connection open with this name
        return -1;
    } else {
        std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
        if ( connectionsIt->second.get()->disableReceive() == -1 ) {
            //connection already open in receive mode
            return -2;
        }
    }
    return 0;
}

bool UdpCustomer::isConnectionOpen( const std::string& name ) {
    std::map<std::string, std::shared_ptr<UdpConnection>>::const_iterator connectionsIt = connections.find(name);
    if ( connectionsIt == connections.end() ) {
        //no connection open with this name
        return false;
    }
    return true;

}

} /* namespace UDP */
} /* namespace COMF */
} /* namespace DUUF */
