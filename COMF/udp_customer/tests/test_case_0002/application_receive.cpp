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
    DUUF::COMF::UDP::UdpConnection connection_receive("testConnection", DUUF::COMF::UDP::RECEIVE, "127.0.0.1", 20000);
    char message[4096];
    connection_receive.recv(message, 4096);

    cout << "Message Received : " << message << endl;

}
