/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   message_info.cpp
 * Author: matteo.botticci
 *
 * Created on 19 maggio 2020, 11.25
 */

#include "MessageHeader.h"

MessageHeader::MessageHeader() {
}

MessageHeader::MessageHeader( const MessageHeader& orig ) {
}

MessageHeader::~MessageHeader() {
}

void MessageHeader::SetDataSize( unsigned int dataSize ) {
    this->dataSize = dataSize;
}

unsigned int MessageHeader::GetDataSize() const {
    return dataSize;
}

void MessageHeader::SetUsecTimestamp( std::chrono::microseconds usecTimestamp ) {
    this->usecTimestamp = usecTimestamp;
}

std::chrono::microseconds MessageHeader::GetUsecTimestamp() const {
    return usecTimestamp;
}

void MessageHeader::SetPort( int port ) {
    this->port = port;
}

int MessageHeader::GetPort() const {
    return port;
}

void MessageHeader::SetAddr( std::string addr ) {
    this->addr = addr;
}

std::string MessageHeader::GetAddr() const {
    return addr;
}

