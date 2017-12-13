//
// Created by Paweł Kulig on 11.12.2017.
//

#ifndef WZORCE2_CHAIN_H
#define WZORCE2_CHAIN_H

#include "Boats.h"

class Chain {
    Chain *next;
    //Boats *boat;
public:
    Chain();
    void addItem(Chain *c);
    void setNext(Chain *c);
    virtual void handle(Boats *boat);
};

//fix Engine
class HandleEngineDamage : public Chain{
public:
    void handle(Boats *boat)
    {
        boat->setEngineDamage(0);
        Chain::handle(boat);
    }
};

class HandleFreezerDamage : public Chain{
public:
    void handle(Boats *boat)
    {
        boat->setFreezerDamage(0);
        Chain::handle(boat);
    }
};

class HandleTheathingDamage : public Chain{
public:
    void handle(Boats *boat)
    {
        boat->setTheathingDamage(0);
        Chain::handle(boat);
    }
};



#endif //WZORCE2_CHAIN_H
