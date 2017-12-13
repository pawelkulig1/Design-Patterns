//
// Created by Paweł Kulig on 12.12.2017.
//

#ifndef WZORCE2_OBSERVER_H
#define WZORCE2_OBSERVER_H


#include <string>
#include <vector>
#include "Boats.h"

class Subject
{

    std::vector<Boats*> boats;
    bool theyAreReturning;
    std::string weather;

public:
    const std::string &getWeather() const {
        return weather;
    }

    void setWeather(const std::string &weather) {
        Subject::weather = weather;
        checkIfHaveToReturn();
    }

    bool isTheyAreReturning() const {
        return theyAreReturning;
    }

    void setTheyAreReturning(bool theyAreReturning) {
        Subject::theyAreReturning = theyAreReturning;
        notifyAll();
    }

    Subject()
    {
        theyAreReturning = false;
    }

    void checkIfHaveToReturn()
    {
        if(weather == "stormy")
        {
            theyAreReturning = true;
            notifyAll();
        }
    }

    void notifyAll()
    {
        for(int i=0;i<boats.size();i++)
        {
            boats[i]->notify(theyAreReturning);
        }
    }

    void attach(Boats* boat)
    {
        boats.push_back(boat);
    }


};






#endif //WZORCE2_OBSERVER_H
