/*
 * test_udp_customer.cpp
 *
 *  Created on: 15 giu 2020
 *      Author: matteo
 */

#include "gtest/gtest.h"
#include "COMF/udp_customer/UdpCustomer.h"

TEST(test_udp_customer, test1) {
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    delete (myCustomer);

}

TEST(test_udp_customer, test2) {
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    int result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::SEND, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    delete (myCustomer);

}

TEST(test_udp_customer, test3) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::SEND, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::SEND, "127.0.0.1", 20000);

    EXPECT_TRUE(result == -1);

    delete (myCustomer);

}

TEST(test_udp_customer, test4) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::SEND, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->closeConnection("testConnection");

    EXPECT_TRUE(result == 0);

    delete (myCustomer);

}

TEST(test_udp_customer, test5) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::SEND, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->closeConnection("testConnection_");

    EXPECT_TRUE(result == -1);

    delete (myCustomer);

}

TEST(test_udp_customer, test6) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::NO_OPEN_MODE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->enableConnectionSend("testConnection");

    EXPECT_TRUE(result == 0);

    delete (myCustomer);

}

TEST(test_udp_customer, test7) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::SEND, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->enableConnectionSend("testConnection");

    EXPECT_TRUE(result == -2);

    delete (myCustomer);

}

TEST(test_udp_customer, test8) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::NO_OPEN_MODE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->enableConnectionSend("testConnection_");

    EXPECT_TRUE(result == -1);

    delete (myCustomer);

}

TEST(test_udp_customer, test9) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::NO_OPEN_MODE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->enableConnectionReceive("testConnection");

    EXPECT_TRUE(result == 0);

    delete (myCustomer);

}

TEST(test_udp_customer, test10) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::RECEIVE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->enableConnectionReceive("testConnection");

    EXPECT_TRUE(result == -2);

    delete (myCustomer);

}

TEST(test_udp_customer, test11) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::NO_OPEN_MODE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->enableConnectionReceive("testConnection_");

    EXPECT_TRUE(result == -1);

    delete (myCustomer);

}

TEST(test_udp_customer, test12) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::SEND, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->disableConnectionSend("testConnection");

    EXPECT_TRUE(result == 0);

    delete (myCustomer);

}

TEST(test_udp_customer, test13) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::NO_OPEN_MODE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->disableConnectionSend("testConnection");

    EXPECT_TRUE(result == -2);

    delete (myCustomer);

}

TEST(test_udp_customer, test14) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::SEND, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->disableConnectionSend("testConnection_");

    EXPECT_TRUE(result == -1);

    delete (myCustomer);

}

TEST(test_udp_customer, test15) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::RECEIVE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->disableConnectionReceive("testConnection");

    EXPECT_TRUE(result == 0);

    delete (myCustomer);

}

TEST(test_udp_customer, test16) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::NO_OPEN_MODE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->disableConnectionReceive("testConnection");

    EXPECT_TRUE(result == -2);

    delete (myCustomer);

}

TEST(test_udp_customer, test17) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::RECEIVE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    result = myCustomer->disableConnectionReceive("testConnection_");

    EXPECT_TRUE(result == -1);

    delete (myCustomer);

}

TEST(test_udp_customer, test18) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::SEND_RECEIVE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    std::string msg = "test_customer";

    result = myCustomer->send(msg.c_str(), msg.length(), "testConnection");
    EXPECT_TRUE(result > 0);

    delete (myCustomer);

}

TEST(test_udp_customer, test19) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::SEND_RECEIVE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    std::string msg = "test_customer";

    result = myCustomer->send(msg.c_str(), msg.length(), "testConnection_");

    EXPECT_TRUE(result == -1);

    delete (myCustomer);

}

TEST(test_udp_customer, test20) {
    int result = 0;
    DUUF::COMF::UDP::UdpCustomer* myCustomer = nullptr;
    myCustomer = new DUUF::COMF::UDP::UdpCustomer();

    EXPECT_TRUE(myCustomer != nullptr);

    result = myCustomer->openConnection("testConnection", DUUF::COMF::UDP::RECEIVE, "127.0.0.1", 20000);

    EXPECT_TRUE(result == 0);

    std::string msg = "test_customer";

    result = myCustomer->send(msg.c_str(), msg.length(), "testConnection");

    EXPECT_TRUE(result == -1);

    delete (myCustomer);

}
