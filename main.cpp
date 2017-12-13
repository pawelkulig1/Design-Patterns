#include <iostream>
#include "Pamiatka.h"
#include "Chain.h"
#include "Observer.h"
#include "Visitor.h"
#include "Mediator.h"
#include "Strategy.h"
#include "Proxy.h"

int main() {

    //pamiatka

    Boats *boat = new Boats();
    Pamiatka *mem = new Pamiatka();
    mem->addElement(boat->clone());
    boat->setAge(3);
    mem->addElement(boat->clone());

    std::cout<<*(mem->getElement(0))<<std::endl;
    std::cout<<*(mem->getElement(1))<<std::endl;
    std::cout<<*(boat)<<std::endl;


    //lancuch zobowiazan //tofix

    Boats *boat3 = new Boats();
    Boats *boat2 = new Boats();
    //Chain *chain = new Chain();
    HandleEngineDamage h1;
    HandleFreezerDamage h2;
    HandleTheathingDamage h3;


    h1.addItem(&h2);
    h1.addItem(&h3);
    h3.setNext(&h1);

    /*boat->setTheathingDamage(4);
    boat->setFreezerDamage(6);

    boat2->setFreezerDamage(3);
    boat2->setEngineDamage(4);

    boat->getTheathingDamage();
    boat->getFreezerDamage();

    boat2->getFreezerDamage();
    boat2->getEngineDamage();

    std::cout<<std::endl;
    std::cout<<*boat<<std::endl;
    std::cout<<*boat2<<std::endl;*/


    //observer
    Subject *subject = new Subject();
    subject->attach(boat);
    subject->attach(boat2);
    subject->attach(boat3);
    subject->setWeather("stormy");


    //visitor

    Captain *c = new Captain();
    FisherMan *f = new FisherMan();
    Mechanic *m = new Mechanic();

    c->setName("Captain");
    f->setName("Fisher");
    m->setName("Mechanic");

    std::vector<CrewMember*> crew;
    crew.push_back(c);
    crew.push_back(f);
    crew.push_back(m);

    Visitor *v = new Visitor();
    for(int i=0;i<crew.size();i++)
    {
        crew[i]->accept(*v);
    }

    //mediator

    boat->setFishesOnBoard(5);
    boat2->setFishesOnBoard(3);
    boat3->setShrimpsOnBoard(7);

    Port *p1 = new Port(10,10);
    Port *p2 = new Port(5,5);

    Mediator *med = new Mediator();
    med->addBoat(boat);
    med->addBoat(boat2);
    med->addBoat(boat3);

    med->addPort(p1);
    med->addPort(p2);

    cout<<med->spaceInPortsLeft()<<endl;
    boat2->setFishesOnBoard(10);
    cout<<med->spaceInPortsLeft()<<endl;
    cout<<boat3->getIsReturning()<<endl;

    //strategy

    FindBestStrategy *s = new FindBestStrategy();
    FindBestStrategy *s2 = new FindBestStrategy();
    s->chooseStrategy(2);
    s2->chooseStrategy(1);

    for(int i=0;i<5;i++)
    {
        s->strategy->addFishingPlace(new FishingPlace());
        s->strategy->places[i]->setPosition(i+3,i+3);
        s->strategy->places[i]->setFishes(i+1);

        s2->strategy->addFishingPlace(new FishingPlace());
        s2->strategy->places[i]->setPosition(i+3,i+3);
        s2->strategy->places[i]->setFishes(i+1);
    }


    FishingPlace *best = s->doIt();
    FishingPlace *best2 = s2->doIt();
    cout<<*best<<endl;
    cout<<*best2<<endl;

    //Proxy // pelnomocnik

    Proxy *prox = new Proxy();
    //Proxy *prox2 = new Proxy();

    //Weather *w1 = new Weather();
    Weather *w2 = new Weather();

    //w1->setBeufortScale(6);
    //w1->setName("Storm Eva");
    //prox->setWeather(w1);

    w2 = prox->checkWeather();
    w2 = prox->checkWeather();

    //prox2->checkWeather();









}