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
#include <string.h>
#include "../../Serialization.h"

using namespace std;

/*
 *
 */

void test_complex_serialize() {
    int a = -12345;
    int a_result = 0;
    long e = -12345;
    long e_result = 0;
    double l = 78.445184;
    double l_result = 0.0;
    bool m = true;
    bool m_result = false;
    string n = "test_case_0001 string";
    string n_result = "";
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(a, my_stream);
    size_serialized += DUUF::COMF::Serialization::serialize(e, my_stream);
    size_serialized += DUUF::COMF::Serialization::serialize(l, my_stream);
    size_serialized += DUUF::COMF::Serialization::serialize(m, my_stream);
    size_serialized += DUUF::COMF::Serialization::serialize(n, my_stream);
    if ( size_serialized != sizeof(int) + sizeof(long) + sizeof(double) + sizeof(bool) + sizeof(unsigned int) + n.length() ) {
        cout << "complex serialize serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, a_result);
    size_deserialized += DUUF::COMF::Serialization::deserialize(my_stream, e_result);
    size_deserialized += DUUF::COMF::Serialization::deserialize(my_stream, l_result);
    size_deserialized += DUUF::COMF::Serialization::deserialize(my_stream, m_result);
    size_deserialized += DUUF::COMF::Serialization::deserialize(my_stream, n_result);

    if ( size_deserialized != sizeof(int) + sizeof(long) + sizeof(double) + sizeof(bool) + sizeof(unsigned int) + n.length() ) {
        cout << "complex serialize deserialization size ERROR " << endl;
    }

    if ( a_result == a && e_result == e && l_result == l && m_result == m && n_result == n ) {
        cout << "complex serialize  PASSED " << endl;
    } else {
        cout << "complex serialize  ERROR " << endl;
    }
}

int main( int argc, char** argv ) {

    test_complex_serialize();

    return 0;
}
