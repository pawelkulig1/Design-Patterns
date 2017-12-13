//
// Created by Paweł Kulig on 11.12.2017.
//

#ifndef WZORCE2_PAMIATKA_H
#define WZORCE2_PAMIATKA_H

#include <vector>
#include <ostream>

#include "Boats.h"

class Boats;

class Pamiatka {
    std::vector<Boats*> boatsVec;
public:
    void addElement(Boats *boat);
    Boats* getElement(int number);

};


#endif //WZORCE2_PAMIATKA_H
