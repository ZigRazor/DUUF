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

BaseMessage::BaseMessage() {
}

BaseMessage::BaseMessage( const BaseMessage& orig ) {
}

BaseMessage::~BaseMessage() {
}

void BaseMessage::SetData( char* data ) {
    this->data = data;
}

char* BaseMessage::GetData() const {
    return data;
}

void BaseMessage::SetHeader( MessageHeader header ) {
    this->header = header;
}

MessageHeader BaseMessage::GetHeader() const {
    return header;
}

