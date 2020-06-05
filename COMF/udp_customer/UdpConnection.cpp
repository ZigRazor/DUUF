/*
 * UdpConnection.cpp
 *
 *  Created on: 5 giu 2020
 *      Author: matteo
 */

#include "UdpConnection.h"

namespace DUUF {
namespace COMF {
namespace UDP {

UdpConnection::UdpConnection( const std::string& name, const Send_Receive_Mode_Enum& mode, std::string const& addr, const int& port, const int& family ) :
        name(name), mode(mode), udp_addr(addr), port(port), family(family) {
    switch ( mode ) {
        case NO_OPEN_MODE: {
            receiver = nullptr;
            sender = nullptr;
        }
            break;
        case SEND: {
            receiver = nullptr;
            sender = new UdpSender(addr, port, family);
        }
            break;
        case RECEIVE: {
            receiver = new UdpReceiver(addr, port, family);
            sender = nullptr;
        }
            break;
        case SEND_RECEIVE: {
            receiver = new UdpReceiver(addr, port, family);
            sender = new UdpSender(addr, port, family);
        }
            break;
        default: {
            receiver = nullptr;
            sender = nullptr;
        }

    }
}

UdpConnection::~UdpConnection() {
    if ( receiver ) {
        delete receiver;
    }
    if ( sender ) {
        delete sender;
    }
}

UdpConnection::UdpConnection( const UdpConnection& other ) :
        name(other.name), udp_addr(other.udp_addr), port(other.port), family(other.family), mode(other.mode) {
    receiver = new UdpReceiver(udp_addr, port, family);
    sender = new UdpSender(udp_addr, port, family);
}

int UdpConnection::enableSend() {
    if ( mode != SEND_RECEIVE && mode != SEND ) {
        sender = new UdpSender(udp_addr, port, family);
        return 0;
    } else {
        //Connection already in send mode
        return -1;
    }
}

int UdpConnection::enableReceive() {
    if ( mode != SEND_RECEIVE && mode != RECEIVE ) {
        receiver = new UdpReceiver(udp_addr, port, family);
        return 0;
    } else {
        //Connection already in receive mode
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

} /* namespace UDP */
} /* namespace COMF */
} /* namespace DUUF */
