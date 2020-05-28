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
#include "Serializable.h"

class Serialization {
public:
    static unsigned int serialize( const int& source, char* dest );
    static unsigned int serialize( const unsigned int& source, char* dest );
    static unsigned int serialize( const short& source, char* dest );
    static unsigned int serialize( const unsigned short& source, char* dest );
    static unsigned int serialize( const long& source, char* dest );
    static unsigned int serialize( const unsigned long& source, char* dest );
    static unsigned int serialize( const char& source, char* dest );
    static unsigned int serialize( const unsigned char& source, char* dest );
    static unsigned int serialize( const float& source, char* dest );
    static unsigned int serialize( const double& source, char* dest );
    static unsigned int serialize( const bool& source, char* dest );
    static unsigned int serialize( const std::string& source, char* dest );
    static unsigned int serialize( const char*& source, unsigned int sizeOfSource, char* dest );
    static unsigned int serialize( const Serializable& source, char* dest );

    static unsigned int deserialize( const char* source, int& dest );
    static unsigned int deserialize( const char* source, unsigned int& dest );
    static unsigned int deserialize( const char* source, short& dest );
    static unsigned int deserialize( const char* source, unsigned short& dest );
    static unsigned int deserialize( const char* source, long& dest );
    static unsigned int deserialize( const char* source, unsigned long& dest );
    static unsigned int deserialize( const char* source, char& dest );
    static unsigned int deserialize( const char* source, unsigned char& dest );
    static unsigned int deserialize( const char* source, float& dest );
    static unsigned int deserialize( const char* source, double& dest );
    static unsigned int deserialize( const char* source, bool& dest );
    static unsigned int deserialize( const char* source, std::string& dest );
    static unsigned int deserialize( const char* source, Serializable& dest );

private:
    Serialization() = delete;
    Serialization( const Serialization& orig ) = delete;
    virtual ~Serialization() = delete;
};

#endif /* SERIALIZATION_H */

