/*
 * UdpConnectionType.h
 *
 *  Created on: 5 giu 2020
 *      Author: matteo
 */

#ifndef COMF_UDP_CUSTOMER_UDPCONNECTIONTYPE_H_
#define COMF_UDP_CUSTOMER_UDPCONNECTIONTYPE_H_

namespace DUUF {
namespace COMF {
namespace UDP {

typedef enum Send_Receive_Mode_Enum {
    NO_OPEN_MODE = 0,
    SEND = 1,
    RECEIVE = 2,
    SEND_RECEIVE = 3
} Send_Receive_Mode_E;

}
}
}

#endif /* COMF_UDP_CUSTOMER_UDPCONNECTIONTYPE_H_ */
