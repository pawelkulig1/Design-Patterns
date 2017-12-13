//
// Created by Paweł Kulig on 12.12.2017.
//

#include "Mediator.h"

int Port::getFreeSpaceFish() const {
    return freeSpaceFish;
}

int Port::getFreeSpaceShrimps() const {
    return freeSpaceShrimps;
}

void Port::setFreeSpaceShrimps(int freeSpaceShrimps) {
    Port::freeSpaceShrimps = freeSpaceShrimps;
}

void Port::setFreeSpaceFish(int freeSpaceFish) {
    Port::freeSpaceFish = freeSpaceFish;
}

Port::Port(int freeSpaceFish, int freeSpaceShrimps){
    this->freeSpaceFish = freeSpaceFish;
    this->freeSpaceShrimps = freeSpaceShrimps;
}


void Mediator::setBoats(const std::vector<Boats *> &boats) {
    Mediator::boats = boats;
}
