/*
 * test_udp_receiver.cpp
 *
 *  Created on: 15 giu 2020
 *      Author: matteo
 */

#include "gtest/gtest.h"
#include <future>
#include "COMF/udp_sender_receiver/UdpReceiver.h"
#include "COMF/udp_sender_receiver/UdpSender.h"

TEST(test_udp_receiver, test1) {
    DUUF::COMF::UDP::UdpReceiver* myReceiver = nullptr;
    myReceiver = new DUUF::COMF::UDP::UdpReceiver("127.0.0.1", 20000);

    EXPECT_TRUE(myReceiver != nullptr);

    delete (myReceiver);

}

TEST(test_udp_receiver, test2) {
    DUUF::COMF::UDP::UdpReceiver* myReceiver = nullptr;
    myReceiver = new DUUF::COMF::UDP::UdpReceiver("127.0.0.1", 20000);

    EXPECT_TRUE(myReceiver != nullptr);
    int msg_length = 1024;
    char msg[msg_length];

    size_t byte_received = myReceiver->timed_recv(msg, msg_length, 500);

    EXPECT_EQ(byte_received, -1);

    delete (myReceiver);

}

TEST(test_udp_receiver, test3) {
    DUUF::COMF::UDP::UdpReceiver* myReceiver = nullptr;
    myReceiver = new DUUF::COMF::UDP::UdpReceiver("127.0.0.1", 20000);

    EXPECT_TRUE(myReceiver != nullptr);

    int msg_length = 1024;
    std::string msg = "";

    msg = myReceiver->timed_recv(msg_length, 500);

    EXPECT_EQ(msg, "");

    delete (myReceiver);

}

TEST(test_udp_receiver, test4) {
    DUUF::COMF::UDP::UdpReceiver* myReceiver = nullptr;
    myReceiver = new DUUF::COMF::UDP::UdpReceiver("127.0.0.1", 20000);

    EXPECT_TRUE(myReceiver != nullptr);

    int msg_length = 1024;
    char msg[msg_length];

    std::future<size_t> fut_byte_received = std::async(&DUUF::COMF::UDP::UdpReceiver::recv, myReceiver, static_cast<char*>(msg), msg_length);

    DUUF::COMF::UDP::UdpSender* mySender = nullptr;
    mySender = new DUUF::COMF::UDP::UdpSender("127.0.0.1", 20000);

    EXPECT_TRUE(mySender != nullptr);

    std::string msg_to_send = "test_receive";

    size_t byte_sent = mySender->send(msg_to_send.c_str(), msg_to_send.length());

    EXPECT_EQ(byte_sent, msg_to_send.length());

    size_t byte_received = fut_byte_received.get();

    EXPECT_EQ(byte_received, msg_to_send.length());
    EXPECT_EQ(std::string(msg), msg_to_send);

    delete (mySender);
    delete (myReceiver);

}

TEST(test_udp_receiver, test5) {
    DUUF::COMF::UDP::UdpReceiver* myReceiver = nullptr;
    myReceiver = new DUUF::COMF::UDP::UdpReceiver("127.0.0.1", 20000);

    EXPECT_TRUE(myReceiver != nullptr);

    int msg_length = 1024;
    char msg[msg_length];

    std::future<size_t> fut_byte_received = std::async(static_cast<size_t (DUUF::COMF::UDP::UdpReceiver::*)( char*, size_t, int ) const >(&DUUF::COMF::UDP::UdpReceiver::timed_recv), myReceiver,
            static_cast<char*>(msg), msg_length, 1000);

    DUUF::COMF::UDP::UdpSender* mySender = nullptr;
    mySender = new DUUF::COMF::UDP::UdpSender("127.0.0.1", 20000);

    EXPECT_TRUE(mySender != nullptr);

    std::string msg_to_send = "test_receive";

    size_t byte_sent = mySender->send(msg_to_send.c_str(), msg_to_send.length());

    EXPECT_EQ(byte_sent, msg_to_send.length());

    size_t byte_received = fut_byte_received.get();

    EXPECT_EQ(byte_received, msg_to_send.length());
    EXPECT_EQ(std::string(msg), msg_to_send);

    delete (mySender);
    delete (myReceiver);

}

TEST(test_udp_receiver, test6) {
    DUUF::COMF::UDP::UdpReceiver* myReceiver = nullptr;
    myReceiver = new DUUF::COMF::UDP::UdpReceiver("127.0.0.1", 20000);

    EXPECT_TRUE(myReceiver != nullptr);

    int msg_length = 1024;
    std::string msg = "";

    std::future<std::string> fut_msg = std::async(static_cast<std::string (DUUF::COMF::UDP::UdpReceiver::*)( int, int ) const >(&DUUF::COMF::UDP::UdpReceiver::timed_recv), myReceiver, msg_length,
            1000);

    DUUF::COMF::UDP::UdpSender* mySender = nullptr;
    mySender = new DUUF::COMF::UDP::UdpSender("127.0.0.1", 20000);

    EXPECT_TRUE(mySender != nullptr);

    std::string msg_to_send = "test_receive";

    size_t byte_sent = mySender->send(msg_to_send.c_str(), msg_to_send.length());

    EXPECT_EQ(byte_sent, msg_to_send.length());

    msg = fut_msg.get();

    EXPECT_EQ(msg, msg_to_send);

    delete (mySender);
    delete (myReceiver);

}

TEST(test_udp_receiver, test7) {
    DUUF::COMF::UDP::UdpReceiver* myReceiver = nullptr;
    std::string multicast_addr = "255.255.255.1";
    myReceiver = new DUUF::COMF::UDP::UdpReceiver("127.0.0.1", 20000, AF_UNSPEC, &multicast_addr);

    EXPECT_TRUE(myReceiver != nullptr);

    delete (myReceiver);

}

TEST(test_udp_receiver, test8) {
    DUUF::COMF::UDP::UdpReceiver* myReceiver = nullptr;
    myReceiver = new DUUF::COMF::UDP::UdpReceiver("127.0.0.1", 20000);

    EXPECT_TRUE(myReceiver != nullptr);

    std::string addr = myReceiver->get_address();

    EXPECT_TRUE(addr == "127.0.0.1");

    delete (myReceiver);

}

TEST(test_udp_receiver, test9) {
    DUUF::COMF::UDP::UdpReceiver* myReceiver = nullptr;
    myReceiver = new DUUF::COMF::UDP::UdpReceiver("127.0.0.1", 20000);

    EXPECT_TRUE(myReceiver != nullptr);

    int port = myReceiver->get_port();

    EXPECT_TRUE(port == 20000);

    delete (myReceiver);

}

TEST(test_udp_receiver, test10) {
    DUUF::COMF::UDP::UdpReceiver* myReceiver = nullptr;
    myReceiver = new DUUF::COMF::UDP::UdpReceiver("127.0.0.1", 20000);

    EXPECT_TRUE(myReceiver != nullptr);

    int socket = myReceiver->get_socket();

    EXPECT_TRUE(socket > 0);

    delete (myReceiver);

}

//TEST(test_udp_receiver, test11) {
//    DUUF::COMF::UDP::UdpReceiver* myReceiver = nullptr;
//    myReceiver = new DUUF::COMF::UDP::UdpReceiver("127.0.0.1.20", 20000);
//
//    EXPECT_TRUE(myReceiver != nullptr);
//
//    int socket = myReceiver->get_socket();
//
//    EXPECT_TRUE(socket < 0);
//
//    delete (myReceiver);
//
//}

