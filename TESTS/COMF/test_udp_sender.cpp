/*
 * test_udp_sender.cpp
 *
 *  Created on: 10 giu 2020
 *      Author: matteo
 */

#include "gtest/gtest.h"
#include "COMF/udp_sender_receiver/UdpSender.h"

TEST(test_udp_sender, test1) {
    DUUF::COMF::UDP::UdpSender* mySender = nullptr;
    mySender = new DUUF::COMF::UDP::UdpSender("127.0.0.1", 20000);

    EXPECT_TRUE(mySender != nullptr);

    delete (mySender);

}

TEST(test_udp_sender, test2) {
    DUUF::COMF::UDP::UdpSender* mySender = nullptr;
    mySender = new DUUF::COMF::UDP::UdpSender("127.0.0.1", 20000);

    EXPECT_TRUE(mySender != nullptr);

    std::string msg = "test_send";

    size_t byte_sent = mySender->send(msg.c_str(), msg.length());

    EXPECT_EQ(byte_sent, msg.length());

    delete (mySender);
}

TEST(test_udp_sender, test3) {
    DUUF::COMF::UDP::UdpSender* mySender = nullptr;
    mySender = new DUUF::COMF::UDP::UdpSender("127.0.0.1", 20000);

    EXPECT_TRUE(mySender != nullptr);

    std::string addr = mySender->get_address();

    EXPECT_TRUE(addr == "127.0.0.1");

    delete (mySender);

}

TEST(test_udp_sender, test4) {
    DUUF::COMF::UDP::UdpSender* mySender = nullptr;
    mySender = new DUUF::COMF::UDP::UdpSender("127.0.0.1", 20000);

    EXPECT_TRUE(mySender != nullptr);

    int port = mySender->get_port();

    EXPECT_TRUE(port == 20000);

    delete (mySender);

}

TEST(test_udp_sender, test5) {
    DUUF::COMF::UDP::UdpSender* mySender = nullptr;
    mySender = new DUUF::COMF::UDP::UdpSender("127.0.0.1", 20000);

    EXPECT_TRUE(mySender != nullptr);

    int socket = mySender->get_socket();

    EXPECT_TRUE(socket > 0);

    delete (mySender);

}

TEST(test_udp_sender, test6) {
    DUUF::COMF::UDP::UdpSender* mySender = nullptr;
    mySender = new DUUF::COMF::UDP::UdpSender("127.0.0.1.20", 20000);

    EXPECT_TRUE(mySender != nullptr);

    int socket = mySender->get_socket();

    EXPECT_TRUE(socket < 0);

    delete (mySender);

}
