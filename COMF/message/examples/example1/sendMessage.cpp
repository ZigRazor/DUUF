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
#include <sstream>
#include <bitset>
#include <iomanip>
#include <vector>

#include "UdpSender.h"
#include "BaseMessage.h"
#include "Serialization.h"

using namespace std;

/*
 *
 */
int main( int argc, char** argv ) {

    DUUF::COMF::UDP::UdpSender clientUDP("127.0.0.1", 20000);

    DUUF::COMF::MESSAGE::BaseMessage message;

    message.GetHeader().SetPort(20000);
    message.GetHeader().SetAddr("127.0.0.1");
    message.GetHeader().setMessageId(1);
    auto now = std::chrono::system_clock::now();
    auto now_us = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    auto epoch = now_us.time_since_epoch();
    std::chrono::microseconds usec = std::chrono::duration_cast<std::chrono::microseconds>(epoch);
    message.GetHeader().SetUsecTimestamp(usec);

    string message_string = "test_case_0001";

    message.SetData(message_string.c_str(), message_string.length());
    stringstream messageSerialized;
    unsigned int messageLength = 0;
    messageLength = message.serialize(messageSerialized);
    char buf[messageLength];
    DUUF::COMF::Serialization::streambufToCharBuf(messageSerialized, buf, messageLength);
    clientUDP.send(buf, messageLength);

    return 0;
}

