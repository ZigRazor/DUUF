/*
 * UdpConnection.cpp
 *
 *  Created on: 5 giu 2020
 *      Author: matteo
 */

#include "UdpConnection.h"
#include "COMFLogger.h"

namespace DUUF {
namespace COMF {
namespace UDP {

UdpConnection::UdpConnection( const std::string& name, const Send_Receive_Mode_Enum& mode, std::string const& addr, const int& port, const int& family ) :
        name(name), mode(mode), udp_addr(addr), port(port), family(family) {
    switch ( mode ) {
        case NO_OPEN_MODE: {
            receiver = nullptr;
            sender = nullptr;
            LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Open Connection '" << name << "' address: " << addr << "port: " << port << "family: " << family << "in No Open mode");
        }
            break;
        case SEND: {
            receiver = nullptr;
            sender = new UdpSender(addr, port, family);
            LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Open Connection '" << name << "' address: " << addr << "port: " << port << "family: " << family << "in Send mode");
        }
            break;
        case RECEIVE: {
            receiver = new UdpReceiver(addr, port, family);
            sender = nullptr;
            LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Open Connection '" << name << "' address: " << addr << "port: " << port << "family: " << family << "in Receive mode");
        }
            break;
        case SEND_RECEIVE: {
            receiver = new UdpReceiver(addr, port, family);
            sender = new UdpSender(addr, port, family);
            LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Open Connection '" << name << "' address: " << addr << "port: " << port << "family: " << family << "in Send and Receive mode");
        }
            break;
        default: {
            receiver = nullptr;
            sender = nullptr;
            LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Open Connection '" << name << "' address: " << addr << "port: " << port << "family: " << family << "in No Open mode");
        }

    }
}

UdpConnection::~UdpConnection() {
    if ( receiver ) {
        delete receiver;
        receiver = nullptr;
    }
    if ( sender ) {
        delete sender;
        sender = nullptr;
    }
    LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Connection '" << name << "' Deleted");
}

//UdpConnection::UdpConnection( const UdpConnection& other ) :
//        name(other.name), udp_addr(other.udp_addr), port(other.port), family(other.family), mode(other.mode) {
//    receiver = new UdpReceiver(udp_addr, port, family);
//    sender = new UdpSender(udp_addr, port, family);
//}

int UdpConnection::enableSend() {
    if ( mode != SEND_RECEIVE && mode != SEND ) {
        sender = new UdpSender(udp_addr, port, family);
        if ( !sender ) {
            LOG4CXX_WARN(COMF_Logger::getLogger(), "Cannot Connect in send mode");
            return -2;
        } else {
            if ( mode == RECEIVE ) {
                mode = SEND_RECEIVE;
            } else if ( mode == NO_OPEN_MODE ) {
                mode = SEND;
            }

        }
        LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Send Enabled on Connection '" << name << "'");
        return 0;
    } else {
        //Connection already in send mode
        LOG4CXX_WARN(COMF_Logger::getLogger(), "Connection '" << name << "' already in send mode");
        return -1;
    }
}

int UdpConnection::enableReceive() {
    if ( mode != SEND_RECEIVE && mode != RECEIVE ) {
        receiver = new UdpReceiver(udp_addr, port, family);
        if ( !receiver ) {
            LOG4CXX_WARN(COMF_Logger::getLogger(), "Cannot Connect in receive mode");
            return -2;
        } else {
            if ( mode == SEND ) {
                mode = SEND_RECEIVE;
            } else if ( mode == NO_OPEN_MODE ) {
                mode = RECEIVE;
            }

        }
        LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Receive Enabled on Connection '" << name << "'");
        return 0;
    } else {
        //Connection already in receive mode
        LOG4CXX_WARN(COMF_Logger::getLogger(), "Connection '" << name << "' already in receive mode");
        return -1;
    }
}

int UdpConnection::getFamily() const {
    return family;
}

Send_Receive_Mode_E UdpConnection::getMode() const {
    return mode;
}

const std::string& UdpConnection::getName() const {
    return name;
}

int UdpConnection::getPort() const {
    return port;
}

const std::string& UdpConnection::getUdpAddr() const {
    return udp_addr;
}

long UdpConnection::send( const char* msg, size_t size ) const {
    if ( mode != SEND_RECEIVE && mode != SEND ) { //Connection not in send mode
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Connection '" << name << "' not in send mode");
        return -1;
    } else {
        long bytes_sent = 0;
        bytes_sent = sender->send(msg, size);
        LOG4CXX_TRACE(COMF_Logger::getLogger(), "Sent " << bytes_sent << "Bytes over Connection '" << name << "'");
        return bytes_sent;
    }
}

long UdpConnection::recv( char* msg, size_t max_size ) const {
    if ( mode != SEND_RECEIVE && mode != RECEIVE ) { //Connection not in receive mode
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Connection '" << name << "' not in receive mode");
        return -1;
    } else {
        long bytes_received = 0;
        bytes_received = receiver->recv(msg, max_size);
        LOG4CXX_TRACE(COMF_Logger::getLogger(), "Received " << bytes_received << "Bytes over Connection '" << name << "'");
        return bytes_received;
    }
}

int UdpConnection::disableSend() {
    if ( mode != NO_OPEN_MODE && mode != RECEIVE ) {
        if ( sender ) {
            delete sender;
            sender = nullptr;
        }
        if ( mode == SEND ) {
            mode = NO_OPEN_MODE;
        } else if ( mode == SEND_RECEIVE ) {
            mode = SEND;
        }
        LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Send Disabled on Connection '" << name << "'");
        return 0;
    } else {
        //send mode already disabled
        LOG4CXX_WARN(COMF_Logger::getLogger(), "Send mode already Disabled on Connection '" << name << "'");
        return -1;
    }
}

int UdpConnection::disableReceive() {
    if ( mode != NO_OPEN_MODE && mode != SEND ) {
        if ( receiver ) {
            delete receiver;
            receiver = nullptr;
        }
        if ( mode == RECEIVE ) {
            mode = NO_OPEN_MODE;
        } else if ( mode == SEND_RECEIVE ) {
            mode = SEND;
        }
        LOG4CXX_DEBUG(COMF_Logger::getLogger(), "Receive Disabled on Connection '" << name << "'");
        return 0;
    } else {
        //receive mode already disabled
        LOG4CXX_WARN(COMF_Logger::getLogger(), "Receive mode already Disabled on Connection '" << name << "'");
        return -1;
    }
}

long UdpConnection::timed_recv( char* msg, const size_t max_size, const int max_wait_ms ) const {
    if ( mode != SEND_RECEIVE && mode != RECEIVE ) { //Connection not in receive mode
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Connection '" << name << "' not in receive mode");
        return -1;
    } else {
        long bytes_received = 0;
        bytes_received = receiver->timed_recv(msg, max_size, max_wait_ms);
        LOG4CXX_TRACE(COMF_Logger::getLogger(), "Received " << bytes_received << "Bytes over Connection '" << name << "'");
        return bytes_received;
    }
}

} /* namespace UDP */
} /* namespace COMF */
} /* namespace DUUF */
