/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   server.cpp
 * Author: matteo.botticci
 *
 * Created on 11 maggio 2020, 16.18
 */

#include <cstdlib>
#include <iostream>
#include <sstream>

#include "UdpReceiver.h"
#include "BaseMessage.h"
#include "Serialization.h"

using namespace std;

/*
 *
 */
int main( int argc, char** argv ) {

    DUUF::COMF::UDP::UdpReceiver serverUDP("127.0.0.1", 20000);

    unsigned int max_length = 1024;

    char message[max_length];

    size_t byteReceived = serverUDP.recv(message, max_length);

    std::cout << "Byte received = " << byteReceived << std::endl;
    std::cout << message << std::endl;

    stringstream ss;
    DUUF::COMF::Serialization::charBufToStreamBuf(message, ss, byteReceived);

    DUUF::COMF::MESSAGE::BaseMessage b_message;
    b_message.deserialize(ss);

    cout << "Message Received: " << endl;
    cout << "   port: " << b_message.GetHeader().GetPort() << endl;
    cout << "   addr: " << b_message.GetHeader().GetAddr() << endl;
    cout << "   time: " << b_message.GetHeader().GetUsecTimestamp().count() << endl;
    cout << "   dataSize: " << b_message.GetHeader().GetDataSize() << endl;
    cout << "   DATA : " << b_message.GetData() << endl;

    return 0;
}

