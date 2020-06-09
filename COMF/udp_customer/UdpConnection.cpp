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

//UdpConnection::UdpConnection( const UdpConnection& other ) :
//        name(other.name), udp_addr(other.udp_addr), port(other.port), family(other.family), mode(other.mode) {
//    receiver = new UdpReceiver(udp_addr, port, family);
//    sender = new UdpSender(udp_addr, port, family);
//}

int UdpConnection::enableSend() {
    if ( mode != SEND_RECEIVE && mode != SEND ) {
        sender = new UdpSender(udp_addr, port, family);
        if ( !sender ) {
            return -2;
        } else {
            if ( mode == RECEIVE ) {
                mode = SEND_RECEIVE;
            } else if ( mode == NO_OPEN_MODE ) {
                mode = SEND;
            }

        }
        return 0;
    } else {
        //Connection already in send mode
        return -1;
    }
}

int UdpConnection::enableReceive() {
    if ( mode != SEND_RECEIVE && mode != RECEIVE ) {
        receiver = new UdpReceiver(udp_addr, port, family);
        if ( !receiver ) {
            return -2;
        } else {
            if ( mode == SEND ) {
                mode = SEND_RECEIVE;
            } else if ( mode == NO_OPEN_MODE ) {
                mode = RECEIVE;
            }

        }
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

long UdpConnection::send( const char* msg, size_t size ) const {
    if ( mode != SEND_RECEIVE && mode != SEND ) { //Connection not in send mode
        return -1;
    } else {
        return sender->send(msg, size);
    }
}

long UdpConnection::recv( char* msg, size_t max_size ) const {
    if ( mode != SEND_RECEIVE && mode != RECEIVE ) { //Connection not in receive mode
        return -1;
    } else {
        return receiver->recv(msg, max_size);
    }
}

int UdpConnection::disableSend() {
    if ( mode != NO_OPEN_MODE && mode != RECEIVE ) {
        if ( sender ) {
            delete sender;
        }
        if ( mode == SEND ) {
            mode = NO_OPEN_MODE;
        } else if ( mode == SEND_RECEIVE ) {
            mode = SEND;
        }
        return 0;
    } else {
        //send mode already disabled
        return -1;
    }
}

int UdpConnection::disableReceive() {
    if ( mode != NO_OPEN_MODE && mode != SEND ) {
        if ( receiver ) {
            delete receiver;
        }
        if ( mode == RECEIVE ) {
            mode = NO_OPEN_MODE;
        } else if ( mode == SEND_RECEIVE ) {
            mode = SEND;
        }

        return 0;
    } else {
        //receive mode already disabled
        return -1;
    }
}

long UdpConnection::timed_recv( char* msg, const size_t max_size, const int max_wait_ms ) const {
    if ( mode != SEND_RECEIVE && mode != RECEIVE ) { //Connection not in receive mode
        return -1;
    } else {
        return receiver->timed_recv(msg, max_size, max_wait_ms);
    }
}

} /* namespace UDP */
} /* namespace COMF */
} /* namespace DUUF */
