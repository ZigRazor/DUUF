/*
 * TestClass.cpp
 *
 *  Created on: 3 giu 2020
 *      Author: matteo
 */

#include "TestClass.h"
#include "../../Serialization.h"

Test_Class::Test_Class() :
        d("") {
    a = 0;
    b = 0;
    c = 0.0;
    e = 0;
}

Test_Class::~Test_Class() {
    // TODO Auto-generated destructor stub
}

unsigned int Test_Class::deserialize( std::istream& source ) {
    unsigned int size_deserialized = 0;
    size_deserialized += DUUF::COMF::Serialization::deserialize(source, a);
    size_deserialized += DUUF::COMF::Serialization::deserialize(source, b);
    size_deserialized += DUUF::COMF::Serialization::deserialize(source, c);
    size_deserialized += DUUF::COMF::Serialization::deserialize(source, d);
    size_deserialized += DUUF::COMF::Serialization::deserialize(source, e);
    return size_deserialized;
}

unsigned int Test_Class::serialize( std::ostream& dest ) const {
    unsigned int size_serialized = 0;
    size_serialized += DUUF::COMF::Serialization::serialize(a, dest);
    size_serialized += DUUF::COMF::Serialization::serialize(b, dest);
    size_serialized += DUUF::COMF::Serialization::serialize(c, dest);
    size_serialized += DUUF::COMF::Serialization::serialize(d, dest);
    size_serialized += DUUF::COMF::Serialization::serialize(e, dest);
    return size_serialized;
}

int Test_Class::getA() const {
    return a;
}

void Test_Class::setA( int a ) {
    this->a = a;
}

long Test_Class::getB() const {
    return b;
}

void Test_Class::setB( long b ) {
    this->b = b;
}

float Test_Class::getC() const {
    return c;
}

void Test_Class::setC( float c ) {
    this->c = c;
}

const std::string& Test_Class::getD() const {
    return d;
}

void Test_Class::setD( const std::string& d ) {
    this->d = d;
}

char Test_Class::getE() const {
    return e;
}

void Test_Class::setE( char e ) {
    this->e = e;
}
