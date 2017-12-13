//
// Created by Paweł Kulig on 12.12.2017.
//

#ifndef WZORCE2_STRATEGY_H
#define WZORCE2_STRATEGY_H


#include <vector>
#include <ostream>
#include <iostream>

class FishingPlace;
class Strategy;

class FishingPlace
{
    int xpoz;
    int ypoz;
    int distance;
public:
    int getFishes() const;

    void setFishes(int fishes);

    int getDistance() const;

    friend std::ostream &operator<<(std::ostream &os, const FishingPlace &place);

    void calculateDistance(int xpoz, int ypoz);

    void setPosition(int x, int y);
private:
    int fishes;
};

class Strategy {
public:
    std::vector<FishingPlace*> places;

    virtual FishingPlace *findBestPlace(){}
    void addFishingPlace(FishingPlace *place);
};

class ShortestPathStrategy : public Strategy
{
    FishingPlace *findBestPlace()
    {
        int min = places[0]->getDistance();
        int poz = 0;
        for(int i=0;i<places.size();i++)
        {
            if(min>places[i]->getDistance())
            {
                min = places[i]->getDistance();
                poz = i;
            }
        }
        return places[poz];
    }
};

class MostFishesStrategy : public Strategy
{
    FishingPlace *findBestPlace()
    {
        int max = places[0]->getFishes();
        int poz = 0;
        for(int i=0;i<places.size();i++)
        {
            if(max<places[i]->getFishes())
            {
                max = places[i]->getFishes();
                poz = i;
            }
        }
        return places[poz];
    }
};

class FindBestStrategy
{
public:
    void chooseStrategy(int number)
    {
        if(number == 1)
            strategy = new ShortestPathStrategy();
        if(number == 2)
            strategy = new MostFishesStrategy();

    }

    FishingPlace *doIt()
    {
        return strategy->findBestPlace();
    }

    Strategy *strategy = nullptr;
};

#endif //WZORCE2_STRATEGY_H
