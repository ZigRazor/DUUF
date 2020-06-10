/*
 * TestClass.h
 *
 *  Created on: 3 giu 2020
 *      Author: matteo
 */

#ifndef COMF_SERIALIZATION_EXAMPLES_EXAMPLE3_TESTCLASS_H_
#define COMF_SERIALIZATION_EXAMPLES_EXAMPLE3_TESTCLASS_H_

#include "../../Serializable.h"
#include <string>
/*
 *
 */
class Test_Class: public DUUF::COMF::Serializable {
public:
    Test_Class();
    virtual ~Test_Class();
    unsigned int deserialize( std::istream& source ) override;
    unsigned int serialize( std::ostream& dest ) const override;
    int getA() const;
    void setA( int a );
    long getB() const;
    void setB( long b );
    float getC() const;
    void setC( float c );
    const std::string& getD() const;
    void setD( const std::string& d );
    char getE() const;
    void setE( char e );

private:

    int a;
    long b;
    float c;
    std::string d;
    char e;
};

#endif /* COMF_SERIALIZATION_EXAMPLES_EXAMPLE3_TESTCLASS_H_ */
