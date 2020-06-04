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
#include "Serialization.h"

namespace DUUF {
namespace COMF {
namespace MESSAGE {
namespace BASICTYPE {

MessageHeader::MessageHeader() :
        addr(""), usecTimestamp(std::chrono::microseconds(0)) {
    port = 0;
    dataSize = 0;
}

MessageHeader::~MessageHeader() {
}

void MessageHeader::SetDataSize( unsigned int dataSize ) {
    this->dataSize = dataSize;
}

unsigned int MessageHeader::GetDataSize() const {
    return dataSize;
}

void MessageHeader::SetUsecTimestamp( const std::chrono::microseconds& usecTimestamp ) {
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

void MessageHeader::SetAddr( const std::string& addr ) {
    this->addr = addr;
}

std::string MessageHeader::GetAddr() const {
    return addr;
}

unsigned int MessageHeader::deserialize( std::istream& source ) {
    unsigned int size_deserialized = 0;
    unsigned long timestamp;
    size_deserialized += DUUF::COMF::Serialization::deserialize(source, addr);
    size_deserialized += DUUF::COMF::Serialization::deserialize(source, port);
    size_deserialized += DUUF::COMF::Serialization::deserialize(source, timestamp);
    usecTimestamp = std::chrono::microseconds(timestamp);
    size_deserialized += DUUF::COMF::Serialization::deserialize(source, dataSize);
    return size_deserialized;
}

unsigned int MessageHeader::serialize( std::ostream& dest ) const {
    unsigned int size_serialized = 0;
    unsigned long timestamp = static_cast<unsigned long>(usecTimestamp.count());
    size_serialized += DUUF::COMF::Serialization::serialize(addr, dest);
    size_serialized += DUUF::COMF::Serialization::serialize(port, dest);
    size_serialized += DUUF::COMF::Serialization::serialize(timestamp, dest);
    size_serialized += DUUF::COMF::Serialization::serialize(dataSize, dest);
    return size_serialized;
}

}
}
}
}
