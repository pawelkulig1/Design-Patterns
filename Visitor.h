//
// Created by Paweł Kulig on 12.12.2017.
//

#ifndef WZORCE2_VISITOR_H
#define WZORCE2_VISITOR_H

#include <iostream>
#include "Boats.h"

using namespace std;


class AbstractVisitor;

class CrewMember
{
    string name;
public:
    const string &getName() const;

    void setName(const string &name);

private:
    int age;
    int salary;

public:
    virtual void accept(AbstractVisitor &v)=0;
    int getSalary() const;

    void setSalary(int salary);

    int getAge() const;

    void setAge(int age);
};

class Captain;
class FisherMan;
class Mechanic;

class AbstractVisitor
{
public:
    virtual void raiseSalary(Captain &p)=0;
    virtual void raiseSalary(FisherMan &p)=0;
    virtual void raiseSalary(Mechanic &p)=0;

};

class Captain: public CrewMember
{
    void takeSteer(Boats* b){}
    void accept(AbstractVisitor &v)
    {
        v.raiseSalary(*this);
    }
};

class FisherMan: public CrewMember
{
    void startFishing(string what){}
    void accept(AbstractVisitor &v)
    {
        v.raiseSalary(*this);
    }
};

class Mechanic: public CrewMember
{
    void startRepairing(){}
    void accept(AbstractVisitor &v)
    {
        v.raiseSalary(*this);
    }
};

class Visitor: public AbstractVisitor {
public:
    void raiseSalary(Captain &p)
    {
        p.setSalary(p.getSalary()+100);
        cout<<"raising "+ p.getName() +" salary!"<<endl;
    }

    void raiseSalary(FisherMan &p)
    {
        p.setSalary(p.getSalary()+50);
        cout<<"raising "+ p.getName() +" salary!"<<endl;
    }

    void raiseSalary(Mechanic &p)
    {
        p.setSalary(p.getSalary()+80);
        cout<<"raising "+ p.getName() +" salary!"<<endl;
    }
};


#endif //WZORCE2_VISITOR_H
