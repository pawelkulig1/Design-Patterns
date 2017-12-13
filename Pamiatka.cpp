//
// Created by Paweł Kulig on 11.12.2017.
//

#include "Pamiatka.h"


void Pamiatka::addElement(Boats *boat)
{
    boatsVec.push_back(boat);
}

Boats *Pamiatka::getElement(int number)
{
    return boatsVec[number];
}