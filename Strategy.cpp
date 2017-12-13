//
// Created by Paweł Kulig on 12.12.2017.
//

#include "Strategy.h"
#include <math.h>

int FishingPlace::getDistance() const {
    return distance;
}

int FishingPlace::getFishes() const {
    return fishes;
}

void FishingPlace::setFishes(int fishes) {
    FishingPlace::fishes = fishes;
}

void FishingPlace::calculateDistance(int xpoz, int ypoz) {
    distance = sqrt(pow(xpoz, 2) + pow(ypoz, 2));

}

void FishingPlace::setPosition(int x, int y) {
    xpoz = x;
    ypoz = y;
}

std::ostream &operator<<(std::ostream &os, const FishingPlace &place) {
    os << "xpoz: " << place.xpoz << " ypoz: " << place.ypoz << " distance: " << place.distance << " fishes: "
       << place.fishes;
    return os;
}

void Strategy::addFishingPlace(FishingPlace *place) {
    places.push_back(place);
}
