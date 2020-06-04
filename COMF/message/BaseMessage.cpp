/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   base_message.cpp
 * Author: matteo.botticci
 *
 * Created on 19 maggio 2020, 11.46
 */

#include "BaseMessage.h"
#include <string.h>
#include "Serialization.h"

namespace DUUF {
namespace COMF {
namespace MESSAGE {

BaseMessage::BaseMessage() :
        header() {
    data = nullptr;
}

BaseMessage::BaseMessage( const BaseMessage& orig ) {
    if ( data ) {
        delete[] data;
    }
    data = new char[orig.header.GetDataSize()];
    memcpy(data, orig.data, orig.header.GetDataSize());
}

BaseMessage::~BaseMessage() {
    if ( data ) {
        delete[] data;
    }
}

void BaseMessage::SetData( const char* data, unsigned int dataSize ) {
    if ( this->data ) {
        delete[] this->data;
    }
    this->data = new char[dataSize];
    memcpy(this->data, data, dataSize);
    header.SetDataSize(dataSize);
}

char* BaseMessage::GetData() const {
    return data;
}

void BaseMessage::SetHeader( BASICTYPE::MessageHeader& header ) {
    this->header = header;
}

BASICTYPE::MessageHeader& BaseMessage::GetHeader() {
    return header;
}

unsigned int BaseMessage::deserialize( std::istream& source ) {
    unsigned int byteDeserialized = 0;
    byteDeserialized += DUUF::COMF::Serialization::deserialize(source, header);
    if ( data ) {
        delete[] data;
    }
    data = new char[header.GetDataSize()];
    byteDeserialized += DUUF::COMF::Serialization::deserialize(source, header.GetDataSize(), data);
    return byteDeserialized;

}

unsigned int BaseMessage::serialize( std::ostream& dest ) const {
    unsigned int byteSerialized = 0;
    byteSerialized += DUUF::COMF::Serialization::serialize(header, dest);
    byteSerialized += DUUF::COMF::Serialization::serialize(data, header.GetDataSize(), dest);
    return byteSerialized;
}

}
}
}

