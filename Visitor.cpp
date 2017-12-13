//
// Created by Paweł Kulig on 12.12.2017.
//

#include "Visitor.h"

int CrewMember::getSalary() const {
    return salary;
}

void CrewMember::setSalary(int salary) {
    CrewMember::salary = salary;
}

const string &CrewMember::getName() const {
    return name;
}

int CrewMember::getAge() const {
    return age;
}

void CrewMember::setAge(int age) {
    CrewMember::age = age;
}

void CrewMember::setName(const string &name) {
    CrewMember::name = name;
}
