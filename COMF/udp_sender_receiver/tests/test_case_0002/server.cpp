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

#include "../../UdpReceiver.h"

using namespace std;

/*
 *
 */
int main( int argc, char** argv ) {

    DUUF::COMF::UDP::UdpReceiver serverUDP("127.0.0.1", 20000);

    unsigned int max_length = 256;

    char message[max_length];

    unsigned long max_wait_ms = 5000;

    int byte_received = serverUDP.timed_recv(message, max_length, max_wait_ms);
    if ( byte_received == -1 ) {
        cout << "Timeout Expired" << endl;
    } else {
        cout << "Message Received: " << message << endl;
    }
    return 0;
}

