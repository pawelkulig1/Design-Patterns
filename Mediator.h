//
// Created by Paweł Kulig on 12.12.2017.
//

#ifndef WZORCE2_MEDIATOR_H
#define WZORCE2_MEDIATOR_H


#include <vector>
#include "Boats.h"

class Port
{
    int freeSpaceFish;
    int freeSpaceShrimps;

public:
    Port(int freeSpaceFish, int freeSpaceShrimps);

    int getFreeSpaceFish() const;

    void setFreeSpaceFish(int freeSpaceFish);

    int getFreeSpaceShrimps() const;

    void setFreeSpaceShrimps(int freeSpaceShrimps);
};

class Mediator {
    std::vector<Port*> ports;
    std::vector <Boats*> boats;

public:
    //Mediator();
    //Mediator(Port *p);
    //Mediator(Port *p, std::vector<Boats*> b);

    void setBoats(const std::vector<Boats *> &boats);

    void addBoat(Boats *boat)
    {
        boats.push_back(boat);
    }

    void addPort(Port *port)
    {
        ports.push_back(port);
    }

    bool spaceInPortsLeft() {
        int freeSpaceLeftFish = 0;
        int freeSpaceLeftShrimps = 0;
        for (int i = 0; i < ports.size(); i++) {
            freeSpaceLeftFish += ports[i]->getFreeSpaceFish();
            freeSpaceLeftShrimps += ports[i]->getFreeSpaceShrimps();
        }

        for (int i = 0; i < boats.size(); i++) {
            freeSpaceLeftFish -= boats[i]->getFishesOnBoard();
            freeSpaceLeftShrimps -= boats[i]->getShrimpsOnBoard();
        }

        if (freeSpaceLeftFish == 0) {
            for (int i = 0; i < boats.size(); i++) {
                boats[i]->setIsReturning(true);
            }
            return false;
        }
        return true;
    }
};




#endif //WZORCE2_MEDIATOR_H
