/*
 * test_tcp_server.cpp
 *
 *  Created on: 25 giu 2020
 *      Author: matteo
 */
#include "gtest/gtest.h"
#include <future>
#include "COMF/tcp_server_client/TcpClient.h"
#include "COMF/tcp_server_client/TcpServer.h"

TEST(test_tcp_server, test1) {
    DUUF::COMF::TCP::TcpServer* server = nullptr;
    server = new DUUF::COMF::TCP::TcpServer("127.0.0.1", 20000);

    EXPECT_TRUE(server != nullptr);

    delete (server);

}

