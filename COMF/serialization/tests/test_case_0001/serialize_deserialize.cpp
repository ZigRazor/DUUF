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
int main( int argc, char** argv ) {

    int a = -12345;
    int a_result = 0;
    unsigned int b = 12345;
    unsigned int b_result = 0;
    short c = -128;
    short c_result = 0;
    unsigned short d = 453;
    unsigned short d_result = 0;
    long e = -12345;
    long e_result = 0;
    unsigned long f = 12345;
    unsigned long f_result = 0;
    char g = -25;
    char g_result = 0;
    unsigned char h = 68;
    unsigned char h_result = 0;
    float i = 6.857;
    float i_result = 0.0;
    double l = 78.445184;
    double l_result = 0.0;
    bool m = true;
    bool m_result = false;
    string n = "test_case_0001 string";
    string n_result = "";
    char o[21] = "test_case_0001 char*";
    char o_result[21] = "";

    stringstream my_stream;
    unsigned int size_serialized = 0;
    unsigned int size_deserialized = 0;

    size_serialized = DUUF::COMF::Serialization::serialize(a, my_stream);
    if ( size_serialized != sizeof(int) ) {
        cout << "int serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, a_result);
    if ( size_deserialized != sizeof(int) ) {
        cout << "int deserialization size ERROR " << endl;
    }

    if ( a_result == a ) {
        cout << "int  PASSED " << endl;
    } else {
        cout << "int  ERROR " << endl;
    }

    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(b, my_stream);
    if ( size_serialized != sizeof(unsigned int) ) {
        cout << "unsigned int serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, a_result);
    if ( size_deserialized != sizeof(unsigned int) ) {
        cout << "unsigned int deserialization size ERROR " << endl;
    }

    if ( b_result == b ) {
        cout << "unsigned int  PASSED " << endl;
    } else {
        cout << "unsigned int  ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(c, my_stream);
    if ( size_serialized != sizeof(short) ) {
        cout << "short  serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, c_result);
    if ( size_deserialized != sizeof(short) ) {
        cout << "short  deserialization size ERROR " << endl;
    }

    if ( c_result == c ) {
        cout << "short   PASSED " << endl;
    } else {
        cout << "short   ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(d, my_stream);
    if ( size_serialized != sizeof(unsigned short) ) {
        cout << "unsigned short  serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, d_result);
    if ( size_deserialized != sizeof(unsigned short) ) {
        cout << "unsigned short  deserialization size ERROR " << endl;
    }

    if ( d_result == d ) {
        cout << "unsigned short   PASSED " << endl;
    } else {
        cout << "unsigned short   ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(e, my_stream);
    if ( size_serialized != sizeof(long) ) {
        cout << "long  serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, e_result);
    if ( size_deserialized != sizeof(long) ) {
        cout << "long  deserialization size ERROR " << endl;
    }

    if ( e_result == e ) {
        cout << "long   PASSED " << endl;
    } else {
        cout << "long   ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(f, my_stream);
    if ( size_serialized != sizeof(unsigned long) ) {
        cout << "unsigned long  serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, f_result);
    if ( size_deserialized != sizeof(unsigned long) ) {
        cout << "unsigned long  deserialization size ERROR " << endl;
    }

    if ( f_result == f ) {
        cout << "unsigned long   PASSED " << endl;
    } else {
        cout << "unsigned long   ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(g, my_stream);
    if ( size_serialized != sizeof(char) ) {
        cout << "char  serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, g_result);
    if ( size_deserialized != sizeof(char) ) {
        cout << "char  deserialization size ERROR " << endl;
    }

    if ( g_result == g ) {
        cout << "char   PASSED " << endl;
    } else {
        cout << "char   ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(h, my_stream);
    if ( size_serialized != sizeof(unsigned char) ) {
        cout << "unsigned char  serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, h_result);
    if ( size_deserialized != sizeof(unsigned char) ) {
        cout << "unsigned char  deserialization size ERROR " << endl;
    }

    if ( h_result == h ) {
        cout << "unsigned char   PASSED " << endl;
    } else {
        cout << "unsigned char   ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(i, my_stream);
    if ( size_serialized != sizeof(float) ) {
        cout << "float  serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, i_result);
    if ( size_deserialized != sizeof(float) ) {
        cout << "float  deserialization size ERROR " << endl;
    }

    if ( i_result == i ) {
        cout << "float   PASSED " << endl;
    } else {
        cout << "float   ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(l, my_stream);
    if ( size_serialized != sizeof(double) ) {
        cout << "double  serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, l_result);
    if ( size_deserialized != sizeof(double) ) {
        cout << "double  deserialization size ERROR " << endl;
    }

    if ( l_result == l ) {
        cout << "double   PASSED " << endl;
    } else {
        cout << "double   ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(m, my_stream);
    if ( size_serialized != sizeof(bool) ) {
        cout << "bool  serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, m_result);
    if ( size_deserialized != sizeof(bool) ) {
        cout << "bool  deserialization size ERROR " << endl;
    }

    if ( m_result == m ) {
        cout << "bool   PASSED " << endl;
    } else {
        cout << "bool   ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(n, my_stream);
    if ( size_serialized != n.length() + sizeof(unsigned int) ) {
        cout << "string  serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, n_result);
    if ( size_deserialized != n.length() + sizeof(unsigned int) ) {
        cout << "string  deserialization size ERROR " << endl;
    }

    if ( n_result == n ) {
        cout << "string   PASSED " << endl;
    } else {
        cout << "string   ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    size_serialized = DUUF::COMF::Serialization::serialize(o, 21, my_stream);
    if ( size_serialized != 21 + sizeof(unsigned int) ) {
        cout << "char*  serialization size ERROR " << endl;
    }
    size_deserialized = DUUF::COMF::Serialization::deserialize(my_stream, 21, o_result);
    if ( size_deserialized != 21 + sizeof(unsigned int) ) {
        cout << "char*  deserialization size ERROR " << endl;
    }

    if ( strncmp(o_result, o, 21) == 0 ) {
        cout << "char*   PASSED " << endl;
    } else {
        cout << "char*   ERROR " << endl;
    }
    my_stream.str(string());
    my_stream.clear();

    return 0;
}

