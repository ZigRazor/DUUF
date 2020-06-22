/*
 * test_message.cpp
 *
 *  Created on: 22 giu 2020
 *      Author: matteo
 */

#include "gtest/gtest.h"
#include "COMF/message/BaseMessage.h"

TEST(test_message, test1) {

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

    EXPECT_EQ(message.GetHeader().GetDataSize(), 15);
    EXPECT_TRUE(message.GetData() != nullptr);

}

TEST(test_message, test2) {

    DUUF::COMF::MESSAGE::BaseMessage message;

    DUUF::COMF::MESSAGE::BASICTYPE::MessageHeader header;
    header.SetAddr("127.0.0.1");
    header.SetPort(10000);
    header.SetUsecTimestampNow();
    header.setMessageId(10);

    char data[15] = "test_message_2";

    message.SetHeader(header);
    message.SetData(data, 15);

    EXPECT_EQ(message.GetHeader().GetDataSize(), 15);
    EXPECT_TRUE(message.GetData() != nullptr);

    DUUF::COMF::MESSAGE::BaseMessage messageCopy(message);
    std::string data1 = message.GetData();
    std::string data2 = messageCopy.GetData();
    EXPECT_EQ(data1, data2);
    EXPECT_EQ(message.GetHeader().GetAddr(), messageCopy.GetHeader().GetAddr());
    EXPECT_EQ(message.GetHeader().GetPort(), messageCopy.GetHeader().GetPort());
    EXPECT_EQ(message.GetHeader().GetDataSize(), messageCopy.GetHeader().GetDataSize());
    EXPECT_EQ(message.GetHeader().getMessageId(), messageCopy.GetHeader().getMessageId());
    EXPECT_EQ(message.GetHeader().GetUsecTimestamp(), messageCopy.GetHeader().GetUsecTimestamp());

}

TEST(test_message, test3) {

    DUUF::COMF::MESSAGE::BaseMessage message;

    DUUF::COMF::MESSAGE::BASICTYPE::MessageHeader header;
    header.SetAddr("127.0.0.1");
    header.SetPort(10000);
    header.SetUsecTimestampNow();
    header.setMessageId(10);

    char data[15] = "test_message_3";

    message.SetHeader(header);
    message.SetData(data, 15);

    EXPECT_EQ(message.GetHeader().GetDataSize(), 15);
    EXPECT_TRUE(message.GetData() != nullptr);

    DUUF::COMF::MESSAGE::BaseMessage messageCopy = message;
    std::string data1 = message.GetData();
    std::string data2 = messageCopy.GetData();
    EXPECT_EQ(data1, data2);
    EXPECT_EQ(message.GetHeader(), messageCopy.GetHeader());

}

TEST(test_message, test4) {

    DUUF::COMF::MESSAGE::BaseMessage message;

    DUUF::COMF::MESSAGE::BASICTYPE::MessageHeader header;
    header.SetAddr("127.0.0.1");
    header.SetPort(10000);
    header.SetUsecTimestampNow();
    header.setMessageId(10);

    char data[15] = "test_message_4";

    message.SetHeader(header);
    message.SetData(data, 15);

    EXPECT_EQ(message.GetHeader().GetDataSize(), 15);
    EXPECT_TRUE(message.GetData() != nullptr);

    std::stringstream ss;

    message.serialize(ss);

    DUUF::COMF::MESSAGE::BaseMessage messageDeserialized;

    messageDeserialized.deserialize(ss);
    std::string data1 = message.GetData();
    std::string data2 = messageDeserialized.GetData();
    EXPECT_EQ(data1, data2);
    EXPECT_EQ(message.GetHeader(), messageDeserialized.GetHeader());

}

TEST(test_message, test5) {

    DUUF::COMF::MESSAGE::BaseMessage message;

    DUUF::COMF::MESSAGE::BASICTYPE::MessageHeader header;
    header.SetAddr("127.0.0.1");
    header.SetPort(10000);
    header.SetUsecTimestampNow();
    header.setMessageId(10);

    char data[15] = "test_message_4";

    message.SetHeader(header);
    message.SetData(data, 15);

    EXPECT_EQ(message.GetHeader().GetDataSize(), 15);
    EXPECT_TRUE(message.GetData() != nullptr);

    std::stringstream ss;

    message.serialize(ss);

    DUUF::COMF::MESSAGE::BaseMessage messageDeserialized;

    messageDeserialized.deserialize(ss);
    std::string data1 = message.GetData();
    std::string data2 = messageDeserialized.GetData();
    EXPECT_EQ(data1, data2);
    EXPECT_EQ(message.GetHeader(), messageDeserialized.GetHeader());

    ss.clear();

    message.serialize(ss);
    messageDeserialized.deserialize(ss);
    std::string data3 = message.GetData();
    std::string data4 = messageDeserialized.GetData();
    EXPECT_EQ(data3, data4);
    EXPECT_EQ(message.GetHeader(), messageDeserialized.GetHeader());

}
