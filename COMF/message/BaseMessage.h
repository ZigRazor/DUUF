/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   base_message.h
 * Author: matteo.botticci
 *
 * Created on 19 maggio 2020, 11.46
 */

#ifndef BASE_MESSAGE_H
#define BASE_MESSAGE_H
#include "basic_type/MessageHeader.h"

namespace DUUF {
namespace COMF {
namespace MESSAGE {

class BaseMessage: public DUUF::COMF::Serializable {
public:
    BaseMessage();
    BaseMessage( const BaseMessage& orig );
    virtual ~BaseMessage();
    void SetData( const char* data, unsigned int dataSize );
    char* GetData() const;
    void SetHeader( BASICTYPE::MessageHeader& header );
    BASICTYPE::MessageHeader& GetHeader();
    virtual unsigned int deserialize( std::istream& source ) override;
    virtual unsigned int serialize( std::ostream& dest ) const override;

    bool operator==( const BaseMessage& bm ) const;

private:

    BASICTYPE::MessageHeader header;
    char* data;

};

}
}
}

#endif /* BASE_MESSAGE_H */

