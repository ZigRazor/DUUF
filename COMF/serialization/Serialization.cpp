/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Serialization.cpp
 * Author: matteo.botticci
 *
 * Created on 19 maggio 2020, 14.17
 */

#include "Serialization.h"
#include <cstring>
#include <string.h>
#include <sstream>

namespace DUUF {
namespace COMF {

template<typename T>
unsigned int deserialize_template( std::istream& source, T& dest ) {
    source.read(reinterpret_cast<char*>(&dest), sizeof(dest));
    return sizeof(dest);
}
template<typename T>
unsigned int serialize_template( const T& source, std::ostream& dest ) {
    dest.write(reinterpret_cast<const char*>(&source), sizeof(source));
    return sizeof(source);
}

unsigned int Serialization::serialize( const int& source, std::ostream& dest ) {
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const unsigned int& source, std::ostream& dest ) {
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const short& source, std::ostream& dest ) {
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const unsigned short& source, std::ostream& dest ) {
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const long& source, std::ostream& dest ) {
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const unsigned long& source, std::ostream& dest ) {
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const char& source, std::ostream& dest ) {
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const unsigned char& source, std::ostream& dest ) {
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const float& source, std::ostream& dest ) {
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const double& source, std::ostream& dest ) {
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const bool& source, std::ostream& dest ) {
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const std::string& source, std::ostream& dest ) {
    unsigned int stringLen = source.length();
    serialize_template(stringLen, dest);
    dest.write(source.c_str(), stringLen);
    return sizeof(stringLen) + stringLen;
}

unsigned int Serialization::serialize( const char* source, unsigned int sizeOfSource, std::ostream& dest ) {
    serialize_template(sizeOfSource, dest);
    dest.write(source, sizeOfSource);
    return sizeof(sizeOfSource) + sizeOfSource;
}

unsigned int Serialization::serialize( const Serializable& source, std::ostream& dest ) {
    return source.serialize(dest);
}

unsigned int Serialization::deserialize( std::istream& source, int& dest ) {
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, unsigned int& dest ) {
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, short& dest ) {
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, unsigned short& dest ) {
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, long& dest ) {
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, unsigned long& dest ) {
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, char& dest ) {
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, unsigned char& dest ) {
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, float& dest ) {
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, double& dest ) {
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, bool& dest ) {
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, std::string& dest ) {
    unsigned int stringlen = 0;
    deserialize_template(source, stringlen);
    char dest_c[stringlen + 1];
    source.read(dest_c, stringlen);
    dest_c[stringlen] = '\0';
    dest = dest_c;
    return sizeof(stringlen) + stringlen;
}

unsigned int Serialization::deserialize( std::istream& source, unsigned int sizeOfDestination, char* dest ) {
    unsigned int stringlen = 0;
    deserialize_template(source, stringlen);
    char dest_c[stringlen];
    source.read(dest_c, stringlen);
    if ( stringlen <= sizeOfDestination ) {
        std::memcpy(dest, dest_c, stringlen);
    } else {
        std::memcpy(dest, dest_c, sizeOfDestination);
    }
    return sizeof(stringlen) + stringlen;
}

unsigned int Serialization::deserialize( std::istream& source, Serializable& dest ) {
    return dest.deserialize(source);
}

int Serialization::streambufToCharBuf( std::stringstream& streamBuf, char* charBuf, unsigned int sizeOfCharBuffer ) {
    unsigned int streamLength = streamBuf.str().length();
    if ( streamLength > sizeOfCharBuffer ) {
        return -1;
    } else {
        memcpy(charBuf, streamBuf.str().c_str(), streamLength);
    }
    return 0;
}

int Serialization::charBufToStreamBuf( const char* charBuf, std::stringstream& streamBuf, unsigned int sizeOfCharBuffer ) {
    streamBuf.write(charBuf, sizeOfCharBuffer);
    return 0;
}

}
}
