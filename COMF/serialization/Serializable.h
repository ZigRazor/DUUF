/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Serializable.h
 * Author: matteo.botticci
 *
 * Created on 19 maggio 2020, 14.25
 */

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

class Serializable {
public:
    virtual unsigned int serialize() = 0;
    virtual unsigned int deserialize() = 0;

};

#endif /* SERIALIZABLE_H */

