/*
 * test_tcp_client.cpp
 *
 *  Created on: 25 giu 2020
 *      Author: matteo
 */

#include "gtest/gtest.h"
#include "COMF/tcp_server_client/TcpClient.h"

TEST(test_tcp_client, test1) {
    DUUF::COMF::TCP::TcpClient* client = nullptr;
    client = new DUUF::COMF::TCP::TcpClient("127.0.0.1", 20000);

    EXPECT_TRUE(client != nullptr);

    delete (client);

}

TEST(test_tcp_client, test2) {
    DUUF::COMF::TCP::TcpClient* client = nullptr;
    client = new DUUF::COMF::TCP::TcpClient("127.0.0.1", 20000);

    EXPECT_TRUE(client != nullptr);

    std::string msg = "test_send";

    size_t byte_sent = client->send(msg.c_str(), msg.length());

    EXPECT_EQ(byte_sent, -1);

    delete (client);
}

TEST(test_tcp_client, test3) {
    DUUF::COMF::TCP::TcpClient* client = nullptr;
    client = new DUUF::COMF::TCP::TcpClient("127.0.0.1", 20000);

    EXPECT_TRUE(client != nullptr);

    std::string addr = client->get_address();

    EXPECT_TRUE(addr == "127.0.0.1");

    delete (client);

}

TEST(test_tcp_client, test4) {
    DUUF::COMF::TCP::TcpClient* client = nullptr;
    client = new DUUF::COMF::TCP::TcpClient("127.0.0.1", 20000);

    EXPECT_TRUE(client != nullptr);

    int port = client->get_port();

    EXPECT_TRUE(port == 20000);

    delete (client);

}

TEST(test_tcp_client, test5) {
    DUUF::COMF::TCP::TcpClient* client = nullptr;
    client = new DUUF::COMF::TCP::TcpClient("127.0.0.1", 20000);

    EXPECT_TRUE(client != nullptr);

    int socket = client->get_socket();

    EXPECT_TRUE(socket > 0);

    delete (client);

}

TEST(test_tcp_client, test6) {
    DUUF::COMF::TCP::TcpClient* client = nullptr;
    client = new DUUF::COMF::TCP::TcpClient("127.0.0.1", 20000);

    EXPECT_TRUE(client != nullptr);

    client->connect();

    EXPECT_FALSE(client->isConnected());

    delete (client);
}

