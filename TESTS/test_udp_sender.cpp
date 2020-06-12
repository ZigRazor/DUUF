#include "gtest/gtest.h"
#include "../COMF/udp_sender_receiver/UdpSender.h"

TEST(test_udp_sender, test1) {
    DUUF::COMF::UDP::UdpSender* mySender = nullptr;
    mySender = new DUUF::COMF::UDP::UdpSender("127.0.0.1", 20000);

    EXPECT_TRUE(mySender != nullptr);

    delete (mySender);

    EXPECT_TRUE(mySender == nullptr);
}

