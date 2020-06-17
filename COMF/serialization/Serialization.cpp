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

#include "COMFLogger.h"

namespace DUUF {
namespace COMF {

template<typename T>
unsigned int deserialize_template( std::istream& source, T& dest ) {
    source.read(reinterpret_cast<char*>(&dest), sizeof(dest));
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialized "<< sizeof(dest) << " Bytes");
    return sizeof(dest);
}
template<typename T>
unsigned int serialize_template( const T& source, std::ostream& dest ) {
    dest.write(reinterpret_cast<const char*>(&source), sizeof(source));
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialized "<< sizeof(source) << " Bytes");
    return sizeof(source);
}

unsigned int Serialization::serialize( const int& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize int");
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const unsigned int& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize unsigned int");
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const short& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize short");
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const unsigned short& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize unsigned short");
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const long& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize long");
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const unsigned long& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize unsigned long");
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const char& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize char");
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const unsigned char& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize unsigned char");
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const float& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize float");
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const double& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize double");
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const bool& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize bool");
    return serialize_template(source, dest);
}

unsigned int Serialization::serialize( const std::string& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize string");
    unsigned int stringLen = source.length();
    serialize_template(stringLen, dest);
    dest.write(source.c_str(), stringLen);
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialized "<< stringLen << " Bytes");
    return sizeof(stringLen) + stringLen;
}

unsigned int Serialization::serialize( const char* source, unsigned int sizeOfSource, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize buffer");
    serialize_template(sizeOfSource, dest);
    dest.write(source, sizeOfSource);
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialized "<< sizeOfSource << " Bytes");
    return sizeof(sizeOfSource) + sizeOfSource;
}

unsigned int Serialization::serialize( const Serializable& source, std::ostream& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Serialize object");
    return source.serialize(dest);
}

unsigned int Serialization::deserialize( std::istream& source, int& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize int");
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, unsigned int& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize unsigned int");
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, short& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize short");
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, unsigned short& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize unsigned short");
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, long& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize long");
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, unsigned long& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize unsigned long");
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, char& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize char");
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, unsigned char& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize unsigned char");
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, float& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize float");
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, double& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize double");
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, bool& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize bool");
    return deserialize_template(source, dest);
}

unsigned int Serialization::deserialize( std::istream& source, std::string& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize string");
    unsigned int stringlen = 0;
    deserialize_template(source, stringlen);
    char dest_c[stringlen + 1];
    source.read(dest_c, stringlen);
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialized "<< stringlen << " Bytes");
    dest_c[stringlen] = '\0';
    dest = dest_c;
    return sizeof(stringlen) + stringlen;
}

unsigned int Serialization::deserialize( std::istream& source, unsigned int sizeOfDestination, char* dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize buffer");
    unsigned int stringlen = 0;
    deserialize_template(source, stringlen);
    char dest_c[stringlen];
    source.read(dest_c, stringlen);
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialized "<< stringlen << " Bytes");
    if ( stringlen <= sizeOfDestination ) {
        std::memcpy(dest, dest_c, stringlen);
    } else {
        std::memcpy(dest, dest_c, sizeOfDestination);
    }
    return sizeof(stringlen) + stringlen;
}

unsigned int Serialization::deserialize( std::istream& source, Serializable& dest ) {
    LOG4CXX_TRACE(COMF_Logger::getLogger(), "Deserialize object");
    return dest.deserialize(source);
}

int Serialization::streambufToCharBuf( std::stringstream& streamBuf, char* charBuf, unsigned int sizeOfCharBuffer ) {
    unsigned int streamLength = streamBuf.str().length();
    if ( streamLength > sizeOfCharBuffer ) {
        LOG4CXX_ERROR(COMF_Logger::getLogger(), "Input size is major than the buffer size");
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
