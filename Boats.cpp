//
// Created by Paweł Kulig on 11.12.2017.
//

#include "Boats.h"

int Boats::getFishesOnBoard() const {
    return fishesOnBoard;
}

void Boats::setFishesOnBoard(int fishesOnBoard) {
    Boats::fishesOnBoard = fishesOnBoard;
}

int Boats::getShrimpsOnBoard() const {
    return shrimpsOnBoard;
}

void Boats::setShrimpsOnBoard(int shrimpsOnBoars) {
    Boats::shrimpsOnBoard = shrimpsOnBoars;
}
