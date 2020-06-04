/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   message_info.h
 * Author: matteo.botticci
 *
 * Created on 19 maggio 2020, 11.25
 */

#ifndef MESSAGE_HEADER_H
#define MESSAGE_HEADER_H

#include <chrono>
#include <string>
#include "Serializable.h"

namespace DUUF {
namespace COMF {
namespace MESSAGE {
namespace BASICTYPE {

class MessageHeader: public DUUF::COMF::Serializable {
public:
    MessageHeader();
    MessageHeader( const MessageHeader& orig ) = default;
    virtual ~MessageHeader();

    unsigned int deserialize( std::istream& source ) override;
    unsigned int serialize( std::ostream& dest ) const override;

    void SetDataSize( unsigned int dataSize );
    unsigned int GetDataSize() const;
    void SetUsecTimestamp( std::chrono::microseconds usecTimestamp );
    std::chrono::microseconds GetUsecTimestamp() const;
    void SetPort( int port );
    int GetPort() const;
    void SetAddr( std::string addr );
    std::string GetAddr() const;
private:
    std::string addr;
    int port;
    std::chrono::microseconds usecTimestamp;
    unsigned int dataSize;

};

}
}
}
}

#endif /* MESSAGE_HEADER_H */

