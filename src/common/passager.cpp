// Copyright 2018 Cedric Lemaitre

#include "passager.hpp"

Passager::Passager(bool survived,
                   int pclass,
                   bool sex,
                   int age,
                   int slbsp,
                   int parch,
                   int fare,
                   std::string embarked,
                   std::string type_class,
                   std::string who,
                   bool adult_male,
                   std::string deck,
                   std::string embark_town,
                   bool alive,
                   bool alone)
{
    this->survived = survived;
    this->pclass = pclass;
    this->sex = sex;
    this->age = age;
    this->slbsp = slbsp;
    this->parch = parch;
    this->fare = fare;
    this->embarked = embarked;
    this->type_class = type_class;
    this->who = who;
    this->adult_male = adult_male;
    this->deck = deck;
    this->embark_town = embark_town;
    this->alive = alive;
    this->alone = alone;
}

std::ostream &operator<<(std::ostream &out, const Passager &passenger)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << std::boolalpha
        << "survived : " << passenger.survived << ", "
        << "pclass : " << passenger.pclass << ", "
        << "sex : " << passenger.sex << ", "
        << "age : " << passenger.age << ", "
        << "slbsp : " << passenger.slbsp << ", "
        << "parch : " << passenger.parch << ", "
        << "fare : " << passenger.fare << ", "
        << "embarked : " << passenger.embarked << ", "
        << "type_class : " << passenger.type_class << ", "
        << "who : " << passenger.who << ", "
        << "adult_male : " << passenger.adult_male << ", "
        << "deck : " << passenger.deck << ", "
        << "embark_town : " << passenger.embark_town << ", "
        << "alive : " << passenger.alive << ", "
        << "alone : " << passenger.alone;

    return out; // return std::ostream so we can chain calls to operator<<
}
