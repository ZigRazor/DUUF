/*
 * application_receive.cpp
 *
 *  Created on: 8 giu 2020
 *      Author: matteo
 */

#include <iostream>
#include "UdpConnection.h"

using namespace std;

int main() {
    DUUF::COMF::UDP::UdpConnection connection_send("testConnection", DUUF::COMF::UDP::SEND, "127.0.0.1", 20000);
    std::string message = "Test_Case_2";
    connection_send.send(message.c_str(), message.length());

    cout << "Message Sent " << endl;

}
