//
// Created by Paweł Kulig on 12.12.2017.
//

#include <iostream>
#include "Proxy.h"

int Proxy::counter = 0;
int Weather::nextId = 0;

const std::string &Weather::getName() const {
    return name;
}

void Weather::setName(const std::string &name) {
    Weather::name = name;
}

int Weather::getTime() const {
    return time;
}

void Weather::setTime(int time) {
    Weather::time = time;
}

int Weather::getBeufortScale() const {
    return beufortScale;
}

void Weather::setBeufortScale(int beufortScale) {
    Weather::beufortScale = beufortScale;
}

int Weather::getId() const {
    return id;
}

void Weather::setId(int id) {
    Weather::id = id;
}

Proxy::Proxy() {
    counter++;
    w_p = nullptr;
}

Weather *Proxy::checkWeather() {
    if(w_p == nullptr)
    {
        w_p = new Weather();
        std::cout<<"creating new weather!"<<std::endl;
    }
    else
        return w_p;
}

Proxy::~Proxy() {
    delete w_p;

}

