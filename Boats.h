//
// Created by Paweł Kulig on 11.12.2017.
//

#ifndef WZORCE2_BOATS_H
#define WZORCE2_BOATS_H

#include <iostream>


class Boats {
    int speed;
    int price;
    int age;
    int engineDamage;
    int freezerDamage;
    int theathingDamage; // poszycie
    bool isReturning;
    int fishesOnBoard;
    int shrimpsOnBoard;

public:

    void notify(bool state) //observer
    {
        isReturning = state;
        if(state == true)
            std::cout<<"Fine. Returning!"<<std::endl;
    }

    Boats* clone()
    {
        Boats *temp = new Boats();
        temp->setAge(this->age);
        temp->setSpeed(this->speed);
        temp->setPrice(this->price);
        temp->setEngineDamage(this->engineDamage);
        temp->setFreezerDamage(this->freezerDamage);
        temp->setTheathingDamage(this->theathingDamage);
        temp->setIsReturning(this->getIsReturning());
        temp->setFishesOnBoard(this->getFishesOnBoard());
        temp->setShrimpsOnBoard(this->getShrimpsOnBoard());
        return temp;
    }

    int getEngineDamage() const {
        return engineDamage;
    }

    int getFreezerDamage() const {
        return freezerDamage;
    }

    bool getIsReturning() const {
        return isReturning;
    }

    void setIsReturning(bool isReturning) {
        Boats::isReturning = isReturning;
    }

    int getShrimpsOnBoard() const;

    void setShrimpsOnBoard(int shrimpsOnBoard);

    int getTheathingDamage() const {
        return theathingDamage;
    }

    int getFishesOnBoard() const;

    void setFishesOnBoard(int fishesOnBoard);

    void setTheathingDamage(int theathingDamage) {
        Boats::theathingDamage = theathingDamage;
    }

    void setFreezerDamage(int FreezerDamage) {
        Boats::freezerDamage = FreezerDamage;
    }

    void setEngineDamage(int engineDamage) {
        Boats::engineDamage = engineDamage;
    }

    Boats()
    {
        speed = 5;
        price = 10;
        age = 0;
        engineDamage = 0;
        freezerDamage = 0;
        theathingDamage = 0;
        isReturning = false;
        fishesOnBoard = 0;
        shrimpsOnBoard = 0;

    }

    friend std::ostream &operator<<(std::ostream &os, const Boats &boats) {
        os << "speed: " << boats.speed << " price: " << boats.price << " age: " << boats.age << " engineDamage: "
           << boats.engineDamage << " FreezerDamage: " << boats.freezerDamage << " theathingDamage: "
           << boats.theathingDamage;
        return os;
    }

    Boats(int speed)
    {
        this->speed = speed;
        price = 10;
        age = 0;
        engineDamage = 0;
        freezerDamage = 0;
        theathingDamage = 0;
        isReturning = false;
        fishesOnBoard = 0;
        shrimpsOnBoard = 0;
    }

    int getSpeed() const {
        return speed;
    }

    int getPrice() const {
        return price;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Boats::age = age;
    }

    void setPrice(int price) {
        Boats::price = price;
    }

    void setSpeed(int speed) {
        Boats::speed = speed;
    }
};


#endif //WZORCE2_BOATS_H
