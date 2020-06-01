/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Serialization.h
 * Author: matteo.botticci
 *
 * Created on 19 maggio 2020, 14.17
 */

#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <string>
#include <iostream>
#include "Serializable.h"

namespace DUUF {
namespace COMF {

class Serialization {
public:
    static unsigned int serialize( const int& source, std::ostream& dest );
    static unsigned int serialize( const unsigned int& source, std::ostream& dest );
    static unsigned int serialize( const short& source, std::ostream& dest );
    static unsigned int serialize( const unsigned short& source, std::ostream& dest );
    static unsigned int serialize( const long& source, std::ostream& dest );
    static unsigned int serialize( const unsigned long& source, std::ostream& dest );
    static unsigned int serialize( const char& source, std::ostream& dest );
    static unsigned int serialize( const unsigned char& source, std::ostream& dest );
    static unsigned int serialize( const float& source, std::ostream& dest );
    static unsigned int serialize( const double& source, std::ostream& dest );
    static unsigned int serialize( const bool& source, std::ostream& dest );
    static unsigned int serialize( const std::string& source, std::ostream& dest );
    static unsigned int serialize( const char* source, unsigned int sizeOfSource, std::ostream& dest );
    static unsigned int serialize( const Serializable& source, std::ostream& dest );

    static unsigned int deserialize( std::istream& source, int& dest );
    static unsigned int deserialize( std::istream& source, unsigned int& dest );
    static unsigned int deserialize( std::istream& source, short& dest );
    static unsigned int deserialize( std::istream& source, unsigned short& dest );
    static unsigned int deserialize( std::istream& source, long& dest );
    static unsigned int deserialize( std::istream& source, unsigned long& dest );
    static unsigned int deserialize( std::istream& source, char& dest );
    static unsigned int deserialize( std::istream& source, unsigned char& dest );
    static unsigned int deserialize( std::istream& source, float& dest );
    static unsigned int deserialize( std::istream& source, double& dest );
    static unsigned int deserialize( std::istream& source, bool& dest );
    static unsigned int deserialize( std::istream& source, std::string& dest );
    static unsigned int deserialize( std::istream& source, unsigned int sizeOfDestination, char* dest );
    static unsigned int deserialize( std::istream& source, Serializable& dest );

private:
    Serialization() = delete;
    Serialization( const Serialization& orig ) = delete;
    virtual ~Serialization() = delete;
};

}
}

#endif /* SERIALIZATION_H */

