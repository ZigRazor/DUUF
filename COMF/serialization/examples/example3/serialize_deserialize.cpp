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
#include "../example3/TestClass.h"

using namespace std;

/*
 *
 */

void test_class_serialize() {
    Test_Class class_a;
    Test_Class class_a_result;
    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    class_a.setA(12345);
    class_a.setB(999999);
    class_a.setC(454.65);
    class_a.setD("test_case_0003");
    class_a.setE('a');

    size_serialized = DUUF::COMF::Serialization::serialize(class_a, my_stream);

    if ( size_serialized != sizeof(int) + sizeof(long) + sizeof(float) + sizeof(unsigned int) + class_a.getD().length() + sizeof(char) ) {
        cout << "class serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, class_a_result);

    if ( size_deserialized != sizeof(int) + sizeof(long) + sizeof(float) + sizeof(unsigned int) + class_a.getD().length() + sizeof(char) ) {
        cout << "serialize deserialization size ERROR " << endl;
    }

    if ( class_a.getA() == class_a_result.getA() && class_a.getB() == class_a_result.getB() && class_a.getC() == class_a_result.getC() && class_a.getD() == class_a_result.getD()
            && class_a.getE() == class_a_result.getE() ) {
        cout << "class serialize  PASSED " << endl;
    } else {
        cout << "class serialize  ERROR " << endl;
    }
}

int main( int argc, char** argv ) {

    test_class_serialize();

    return 0;
}
