/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   UdpMessageQueue.h
 * Author: matteo.botticci
 *
 * Created on 18 maggio 2020, 16.20
 */

#ifndef UDP_MESSAGE_QUEUE_H
#define UDP_MESSAGE_QUEUE_H

#include <queue>
#include <list>
#include "BaseMessage.h"

namespace DUUF {
namespace COMF {
namespace UDP {

class UdpMessageQueue {
public:
    UdpMessageQueue();
    UdpMessageQueue( const UdpMessageQueue& orig ) = delete;
    virtual ~UdpMessageQueue();

    DUUF::COMF::MESSAGE::BaseMessage front();
    DUUF::COMF::MESSAGE::BaseMessage pop_front();
    void pop();
    void push_back( DUUF::COMF::MESSAGE::BaseMessage& message );
    bool isEmpty();

private:

    std::queue<DUUF::COMF::MESSAGE::BaseMessage> messageQueue;

};

}
}
}

#endif /* UDP_MESSAGE_QUEUE_H */

