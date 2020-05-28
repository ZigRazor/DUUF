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

class BaseMessage {
public:
    BaseMessage();
    BaseMessage( const BaseMessage& orig );
    virtual ~BaseMessage();
    void SetData( char* data );
    char* GetData() const;
    void SetHeader( MessageHeader header );
    MessageHeader GetHeader() const;
private:

    MessageHeader header;
    char* data;

};

#endif /* BASE_MESSAGE_H */

