/*
 * test_serialization.cpp
 *
 *  Created on: 22 giu 2020
 *      Author: matteo
 */
#include "gtest/gtest.h"
#include "COMF/serialization/Serialization.h"

using namespace std;

TEST(test_serialization, test_int) {
    int a = -12345;
    int a_result = 0;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(a, my_stream);
    EXPECT_EQ(size_serialized, sizeof(int));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, a_result);
    EXPECT_EQ(size_deserialized, sizeof(int));
    EXPECT_EQ(a_result, a);
}

TEST(test_serialization, test_unsigned_int) {
    unsigned int b = 12345;
    unsigned int b_result = 0;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(b, my_stream);
    EXPECT_EQ(size_serialized, sizeof(unsigned int));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, b_result);
    EXPECT_EQ(size_deserialized, sizeof(unsigned int));
    EXPECT_EQ(b_result, b);
}

TEST(test_serialization, test_short) {
    short c = -128;
    short c_result = 0;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(c, my_stream);
    EXPECT_EQ(size_serialized, sizeof(short));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, c_result);
    EXPECT_EQ(size_deserialized, sizeof(short));
    EXPECT_EQ(c_result, c);
}

TEST(test_serialization, test_unsigned_short) {
    unsigned short d = 453;
    unsigned short d_result = 0;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(d, my_stream);
    EXPECT_EQ(size_serialized, sizeof(unsigned short));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, d_result);
    EXPECT_EQ(size_deserialized, sizeof(unsigned short));
    EXPECT_EQ(d_result, d);
}

TEST(test_serialization, test_long) {
    long e = -12345;
    long e_result = 0;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(e, my_stream);
    EXPECT_EQ(size_serialized, sizeof(long));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, e_result);
    EXPECT_EQ(size_deserialized, sizeof(long));
    EXPECT_EQ(e_result, e);
}

TEST(test_serialization, test_unsigned_long) {
    unsigned long f = 12345;
    unsigned long f_result = 0;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(f, my_stream);
    EXPECT_EQ(size_serialized, sizeof(unsigned long));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, f_result);
    EXPECT_EQ(size_deserialized, sizeof(unsigned long));
    EXPECT_EQ(f_result, f);
}

TEST(test_serialization, test_float) {
    float i = 6.857;
    float i_result = 0.0;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(i, my_stream);
    EXPECT_EQ(size_serialized, sizeof(float));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, i_result);
    EXPECT_EQ(size_deserialized, sizeof(float));
    EXPECT_EQ(i_result, i);
}

TEST(test_serialization, test_double) {
    double l = 78.445184;
    double l_result = 0.0;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(l, my_stream);
    EXPECT_EQ(size_serialized, sizeof(double));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, l_result);
    EXPECT_EQ(size_deserialized, sizeof(double));
    EXPECT_EQ(l_result, l);
}

TEST(test_serialization, test_char) {
    char g = -25;
    char g_result = 0;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(g, my_stream);
    EXPECT_EQ(size_serialized, sizeof(char));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, g_result);
    EXPECT_EQ(size_deserialized, sizeof(char));
    EXPECT_EQ(g_result, g);
}

TEST(test_serialization, test_unsigned_char) {
    unsigned char h = 68;
    unsigned char h_result = 0;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(h, my_stream);
    EXPECT_EQ(size_serialized, sizeof(unsigned char));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, h_result);
    EXPECT_EQ(size_deserialized, sizeof(unsigned char));
    EXPECT_EQ(h_result, h);
}

TEST(test_serialization, test_bool) {
    bool m = true;
    bool m_result = false;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(m, my_stream);
    EXPECT_EQ(size_serialized, sizeof(bool));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, m_result);
    EXPECT_EQ(size_deserialized, sizeof(bool));
    EXPECT_EQ(m_result, m);
}

TEST(test_serialization, test_string) {
    string n = "test_case_0001 string";
    string n_result = "";
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(n, my_stream);
    EXPECT_EQ(size_serialized, n.length() + sizeof(unsigned int));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, n_result);

    EXPECT_EQ(size_deserialized, n.length() + sizeof(unsigned int));
    EXPECT_EQ(n_result, n);
}

TEST(test_serialization, test_char_star) {
    char o[21] = "test_case_0001 char*";
    char o_result[21] = "";
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(o, 21, my_stream);
    EXPECT_EQ(size_serialized, 21 + sizeof(unsigned int));
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, 21, o_result);

    EXPECT_EQ(size_deserialized, 21 + sizeof(unsigned int));
    EXPECT_TRUE(strncmp(o_result, o, 21) == 0);
}

