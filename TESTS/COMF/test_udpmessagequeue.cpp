/*
 * test_udpmessagequeue.cpp
 *
 *  Created on: 22 giu 2020
 *      Author: matteo
 */

#include "gtest/gtest.h"
#include "COMF/udp_message_queue/UdpMessageQueue.h"

TEST(test_udpmessagequeue, test1) {

    DUUF::COMF::MESSAGE::BaseMessage message;

    DUUF::COMF::MESSAGE::BASICTYPE::MessageHeader header;
    header.SetAddr("127.0.0.1");
    header.SetPort(10000);
    auto now = std::chrono::system_clock::now();
    auto now_us = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    auto epoch = now_us.time_since_epoch();
    std::chrono::microseconds usec = std::chrono::duration_cast<std::chrono::microseconds>(epoch);
    header.SetUsecTimestamp(usec);
    header.setMessageId(10);

    char data[15] = "test_message_1";

    message.SetHeader(header);
    message.SetData(data, 15);

    DUUF::COMF::UDP::UdpMessageQueue messageQueue;

    EXPECT_TRUE(messageQueue.isEmpty());

    messageQueue.push_back(message);

    EXPECT_FALSE(messageQueue.isEmpty());

    DUUF::COMF::MESSAGE::BaseMessage messagedeque = messageQueue.pop_front();

    EXPECT_EQ(message, messagedeque);
    EXPECT_TRUE(messageQueue.isEmpty());

}

TEST(test_udpmessagequeue, test2) {

    DUUF::COMF::MESSAGE::BaseMessage message;

    DUUF::COMF::MESSAGE::BASICTYPE::MessageHeader header;
    header.SetAddr("127.0.0.1");
    header.SetPort(10000);
    auto now = std::chrono::system_clock::now();
    auto now_us = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    auto epoch = now_us.time_since_epoch();
    std::chrono::microseconds usec = std::chrono::duration_cast<std::chrono::microseconds>(epoch);
    header.SetUsecTimestamp(usec);
    header.setMessageId(10);

    char data[15] = "test_message_2";

    message.SetHeader(header);
    message.SetData(data, 15);

    DUUF::COMF::UDP::UdpMessageQueue messageQueue;

    EXPECT_TRUE(messageQueue.isEmpty());

    messageQueue.push_back(message);

    EXPECT_FALSE(messageQueue.isEmpty());

    DUUF::COMF::MESSAGE::BaseMessage messagedeque = messageQueue.front();

    EXPECT_EQ(message, messagedeque);
    EXPECT_FALSE(messageQueue.isEmpty());

    messageQueue.pop();

    EXPECT_TRUE(messageQueue.isEmpty());

}

TEST(test_udpmessagequeue, test3) {

    DUUF::COMF::MESSAGE::BaseMessage message;

    DUUF::COMF::MESSAGE::BASICTYPE::MessageHeader header;
    header.SetAddr("127.0.0.1");
    header.SetPort(10000);
    auto now = std::chrono::system_clock::now();
    auto now_us = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    auto epoch = now_us.time_since_epoch();
    std::chrono::microseconds usec = std::chrono::duration_cast<std::chrono::microseconds>(epoch);
    header.SetUsecTimestamp(usec);
    header.setMessageId(10);

    char data[15] = "test_message_3";

    message.SetHeader(header);
    message.SetData(data, 15);

    DUUF::COMF::MESSAGE::BaseMessage message2;

    DUUF::COMF::MESSAGE::BASICTYPE::MessageHeader header2;
    header.SetAddr("127.0.0.1");
    header.SetPort(10000);
    header.SetUsecTimestampNow();
    header.setMessageId(11);

    char data2[18] = "test_message_3.10";

    message.SetHeader(header2);
    message.SetData(data2, 18);

    DUUF::COMF::UDP::UdpMessageQueue messageQueue;

    EXPECT_TRUE(messageQueue.isEmpty());

    messageQueue.push_back(message);
    messageQueue.push_back(message2);

    EXPECT_FALSE(messageQueue.isEmpty());

    DUUF::COMF::MESSAGE::BaseMessage messagedeque = messageQueue.front();

    EXPECT_EQ(message, messagedeque);
    EXPECT_FALSE(messageQueue.isEmpty());

    messageQueue.pop();

    EXPECT_FALSE(messageQueue.isEmpty());

    DUUF::COMF::MESSAGE::BaseMessage messagedeque2 = messageQueue.front();

    EXPECT_EQ(message, messagedeque);
    EXPECT_FALSE(messageQueue.isEmpty());

    messageQueue.pop();

    EXPECT_TRUE(messageQueue.isEmpty());

}

