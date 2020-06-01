/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   client.cpp
 * Author: matteo.botticci
 *
 * Created on 11 maggio 2020, 16.19
 */

#include <cstdlib>

#include "../../UdpReceiver.h"

using namespace std;

/*
 *
 */
int main( int argc, char** argv ) {

    DUUF::COMF::UDP::UdpReceiver clientUDP("127.0.0.1", 20000);

    string message = "test_case_0002";

    clientUDP.send(message.c_str(), message.length());

    return 0;
}

