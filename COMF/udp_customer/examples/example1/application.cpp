/*
 * application.cpp
 *
 *  Created on: 8 giu 2020
 *      Author: matteo
 */

#include <iostream>
#include "UdpCustomer.h"

using namespace std;

int main() {

    int option = -1;
    DUUF::COMF::UDP::UdpCustomer customer;
    while ( option != 0 ) {
        cout << "UDP Customer Test" << endl;
        cout << "Select an option: " << endl;
        cout << "  1.  Open Connection" << endl;
        cout << "  2.  Close Connection" << endl;
        cout << "  3.  Send Message" << endl;
        cout << "  4.  Receive Message" << endl;
        cout << "  5.  Receive Message With Timeout" << endl;
        cout << "  6.  Enable Connection Send" << endl;
        cout << "  7.  Enable Connection Receive" << endl;
        cout << "  8.  Disable Connection Send" << endl;
        cout << "  9.  Disable Connection Receive" << endl;
        cout << "  0.  Exit" << endl;
        cin >> option;
        switch ( option ) {
            case 0:
                exit(0);
            case 1: {
                cout << "Connection Name? " << endl;
                string connectioName = "";
                cin >> connectioName;
                cout << "Send Receive Mode? [NO_OPEN_MODE = 0, SEND = 1, RECEIVE = 2, SEND_RECEIVE = 3] " << endl;
                int mode = -1;
                cin >> mode;
                cout << "IP Address ? " << endl;
                string ipAddr = "";
                cin >> ipAddr;
                cout << "Port ? " << endl;
                int port = -1;
                cin >> port;

                int result = customer.openConnection(connectioName, (DUUF::COMF::UDP::Send_Receive_Mode_Enum) mode, ipAddr, port);
                if ( result < 0 ) {
                    cout << "ERROR" << endl;
                } else {
                    cout << "Connection Opened" << endl;
                }
            }
                break;
            case 2: {
                cout << "Connection Name? " << endl;
                string connectioName = "";
                cin >> connectioName;
                int result = customer.closeConnection(connectioName);
                if ( result < 0 ) {
                    cout << "ERROR" << endl;
                } else {
                    cout << "Connection Closed" << endl;
                }
            }
                break;
            case 3: {
                cout << "Message ? " << endl;
                string message = "";
                cin >> message;
                cout << "Connection Name? " << endl;
                string connectioName = "";
                cin >> connectioName;
                int result = customer.send(message.c_str(), message.length(), connectioName);
                if ( result < 0 ) {
                    cout << "ERROR" << endl;
                } else {
                    cout << "Message Sent" << endl;
                }

            }
                break;
            case 4: {
                cout << "Connection Name? " << endl;
                string connectioName = "";
                cin >> connectioName;
                char message[4096];
                int result = customer.recv(message, 4096, connectioName);
                if ( result < 0 ) {
                    cout << "ERROR" << endl;
                } else {
                    cout << "Message Received : '" << message << "'" << endl;
                }
            }
                break;
            case 5: {
                cout << "Connection Name? " << endl;
                string connectioName = "";
                cin >> connectioName;
                cout << "max wait time in ms? " << endl;
                int wt = -1;
                cin >> wt;
                char message[4096];
                int result = customer.timed_recv(message, 4096, wt, connectioName);
                if ( result < 0 ) {
                    cout << "ERROR" << endl;
                } else {
                    cout << "Message Received : '" << message << "'" << endl;
                }
            }
                break;
            case 6: {
                cout << "Connection Name? " << endl;
                string connectioName = "";
                cin >> connectioName;
                int result = customer.enableConnectionSend(connectioName);
                if ( result < 0 ) {
                    cout << "ERROR " << result << endl;
                } else {
                    cout << "Send Enabled" << endl;
                }
            }
                break;
            case 7: {
                cout << "Connection Name? " << endl;
                string connectioName = "";
                cin >> connectioName;
                int result = customer.enableConnectionReceive(connectioName);
                if ( result < 0 ) {
                    cout << "ERROR" << result << endl;
                } else {
                    cout << "Receive Enabled" << endl;
                }
            }
                break;
            case 8: {
                cout << "Connection Name? " << endl;
                string connectioName = "";
                cin >> connectioName;
                int result = customer.disableConnectionSend(connectioName);
                if ( result < 0 ) {
                    cout << "ERROR " << result << endl;
                } else {
                    cout << "Send Disabled" << endl;
                }
            }
                break;
            case 9: {
                cout << "Connection Name? " << endl;
                string connectioName = "";
                cin >> connectioName;
                int result = customer.disableConnectionReceive(connectioName);
                if ( result < 0 ) {
                    cout << "ERROR" << result << endl;
                } else {
                    cout << "Receive Disabled" << endl;
                }
            }
                break;
            default:
                cout << "Wrong Option" << endl;
                break;
        }
    }

}
