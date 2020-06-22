/*
 * UdpCustomer.cpp
 *
 *  Created on: 5 giu 2020
 *      Author: matteo
 */

#include "UdpCustomer.h"
#include "COMFLogger.h"

namespace DUUF {
namespace COMF {
namespace UDP {

UdpCustomer::UdpCustomer() {
}

UdpCustomer::~UdpCustomer() {
}

int UdpCustomer::openConnection( const std::string& name, const Send_Receive_Mode_Enum& mode, const std::string& addr, const int& port, const int& family ) {
    if ( isConnectionOpen(name) ) {
        //connection name already used
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Connection name already used. (" << name << ")");
        return -1;
    } else {
        std::shared_ptr<UdpConnection> newConnection = std::make_shared<UdpConnection>(name, mode, addr, port, family);
        connections.insert(std::make_pair(name, newConnection));
    }
    LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Open Connection '" << name << "' mode: " << mode << " address: " << addr << " port: "<< port << "family: " << family);
    return 0;
}

int UdpCustomer::closeConnection( const std::string& name ) {
    std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
    if ( !isConnectionOpen(name) ) {
        //no connection open with this name
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "No Connection with this name. (" << name << ")");
        return -1;
    } else {
        std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
        connections.erase(connectionsIt);
    }
    LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Close Connection '" << name << "'");
    return 0;
}

int UdpCustomer::enableConnectionSend( const std::string& name ) {
    if ( !isConnectionOpen(name) ) {
        //no connection open with this name
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "No Connection with this name. (" << name << ")");
        return -1;
    } else {
        std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
        if ( connectionsIt->second.get()->enableSend() == -1 ) {
            //connection already open in send mode
            LOG4CXX_WARN(COMF_Logger::getLogger(), "Connection '" << name << "' already open in send mode");
            return -2;
        }
    }
    LOG4CXX_WARN(COMF_Logger::getLogger(), "Connection '" << name << "' enabled in send mode");
    return 0;
}

int UdpCustomer::enableConnectionReceive( const std::string& name ) {
    if ( !isConnectionOpen(name) ) {
        //no connection open with this name
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "No Connection with this name. (" << name << ")");
        return -1;
    } else {
        std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
        if ( connectionsIt->second.get()->enableReceive() == -1 ) {
            //connection already open in receive mode
            LOG4CXX_WARN(COMF_Logger::getLogger(), "Connection '" << name << "' already open in receive mode");
            return -2;
        }
    }
    LOG4CXX_WARN(COMF_Logger::getLogger(), "Connection '" << name << "' enabled in receive mode");
    return 0;
}

long UdpCustomer::send( const char* msg, size_t size, const std::string& name ) const {
    std::map<std::string, std::shared_ptr<UdpConnection>>::const_iterator connectionsIt = connections.find(name);
    if ( connectionsIt == connections.end() ) {
        //Connections not found
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "No Connection with this name. (" << name << ")");
        return -1;
    } else {
        long bytes_sent = 0;
        bytes_sent = connectionsIt->second.get()->send(msg, size);
        LOG4CXX_TRACE(COMF_Logger::getLogger(), "Sent " << bytes_sent << "Bytes over Connection '" << name << "'");
        return bytes_sent;
    }
}

long UdpCustomer::recv( char* msg, size_t max_size, const std::string& name ) const {
    std::map<std::string, std::shared_ptr<UdpConnection>>::const_iterator connectionsIt = connections.find(name);
    if ( connectionsIt == connections.end() ) {
        //Connections not found
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "No Connection with this name. (" << name << ")");
        return -1;
    } else {
        long bytes_received = 0;
        bytes_received = connectionsIt->second.get()->recv(msg, max_size);
        LOG4CXX_TRACE(COMF_Logger::getLogger(), "Received " << bytes_received << "Bytes over Connection '" << name << "'");
        return bytes_received;
    }
}

long UdpCustomer::timed_recv( char* msg, const size_t max_size, const int max_wait_ms, const std::string& name ) const {
    std::map<std::string, std::shared_ptr<UdpConnection>>::const_iterator connectionsIt = connections.find(name);
    if ( connectionsIt == connections.end() ) {
        //Connections not found
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "No Connection with this name. (" << name << ")");
        return -1;
    } else {
        long bytes_received = 0;
        bytes_received = connectionsIt->second.get()->timed_recv(msg, max_size, max_wait_ms);
        LOG4CXX_TRACE(COMF_Logger::getLogger(), "Received " << bytes_received << "Bytes over Connection '" << name << "'");
        return bytes_received;
    }
}

int UdpCustomer::disableConnectionSend( const std::string& name ) {
    if ( !isConnectionOpen(name) ) {
        //no connection open with this name
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "No Connection with this name. (" << name << ")");
        return -1;
    } else {
        std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
        if ( connectionsIt->second.get()->disableSend() == -1 ) {
            //connection not in send mode
            LOG4CXX_WARN(COMF_Logger::getLogger(), "Connection '" << name << "' not open in send mode");
            return -2;
        }
    }
    LOG4CXX_WARN(COMF_Logger::getLogger(), "Connection '" << name << "' disabled in send mode");
    return 0;
}

int UdpCustomer::disableConnectionReceive( const std::string& name ) {
    if ( !isConnectionOpen(name) ) {
        //no connection open with this name
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "No Connection with this name. (" << name << ")");
        return -1;
    } else {
        std::map<std::string, std::shared_ptr<UdpConnection>>::iterator connectionsIt = connections.find(name);
        if ( connectionsIt->second.get()->disableReceive() == -1 ) {
            //connection not in receive mode
            LOG4CXX_WARN(COMF_Logger::getLogger(), "Connection '" << name << "' not open in receive mode");
            return -2;
        }
    }
    LOG4CXX_WARN(COMF_Logger::getLogger(), "Connection '" << name << "' disabled in receive mode");
    return 0;
}

bool UdpCustomer::isConnectionOpen( const std::string& name ) {
    std::map<std::string, std::shared_ptr<UdpConnection>>::const_iterator connectionsIt = connections.find(name);
    if ( connectionsIt == connections.end() ) {
        //no connection open with this name
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "No Connection with this name. (" << name << ")");
        return false;
    }
    return true;

}

} /* namespace UDP */
} /* namespace COMF */
} /* namespace DUUF */
