/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   UdpMessageQueue.cpp
 * Author: matteo.botticci
 *
 * Created on 18 maggio 2020, 16.20
 */

#include "UdpMessageQueue.h"

namespace DUUF {
namespace COMF {
namespace UDP {

UdpMessageQueue::UdpMessageQueue() {
}

UdpMessageQueue::~UdpMessageQueue() {
}

DUUF::COMF::MESSAGE::BaseMessage UdpMessageQueue::front() {
    if ( !isEmpty() ) {
        return messageQueue.front();
    } else {
        return DUUF::COMF::MESSAGE::BaseMessage(); //TODO return Invlaid Message
    }
}

DUUF::COMF::MESSAGE::BaseMessage UdpMessageQueue::pop_front() {
    if ( !isEmpty() ) {
        DUUF::COMF::MESSAGE::BaseMessage msg = messageQueue.front();
        messageQueue.pop();
        return msg;
    } else {
        return DUUF::COMF::MESSAGE::BaseMessage(); //TODO return Invlaid Message
    }
}

void UdpMessageQueue::pop() {
    if ( !isEmpty() ) {
        messageQueue.pop();
    }
}

void UdpMessageQueue::push_back( DUUF::COMF::MESSAGE::BaseMessage& message ) {
    messageQueue.push(message);
}

bool UdpMessageQueue::isEmpty() {
    return messageQueue.empty();
}

}
}
}
