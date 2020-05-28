/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: matteo.botticci
 *
 * Created on 11 maggio 2020, 10.50
 */

#include <cstdlib>
#include "UdpClient.h"
#include <iostream>

using namespace std;

/*
 *
 */
int main( int argc, char** argv ) {

    std::cout << "prova main 1" << std::endl;

    DUUF::COMF::UDP::UdpClient pippo("10.180.96.238", 1400);

    std::cout << "fine prova main 1" << std::endl;
    return 0;
}

