//
// Created by Paweł Kulig on 11.12.2017.
//

#include "Chain.h"

Chain::Chain()
{
    next = nullptr;
}

void Chain::addItem(Chain *c)
{
    if (next != nullptr)
        next->addItem(c);
    else
        next = c;
}

void Chain::setNext(Chain *c)
{
    next = c;
}

void Chain::handle(Boats *boat)
{
    next->handle(boat);
}
