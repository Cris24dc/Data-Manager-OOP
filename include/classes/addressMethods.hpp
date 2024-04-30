#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <ncurses.h>
#include "classes/classes.hpp"

Address::Address() : Info() {
    Country = new char[8];
    strcpy(Country, "No Country");
    County = new char[8];
    strcpy(County, "No County");
    City = new char[8];
    strcpy(City, "No City");
    Street = new char[8];
    strcpy(Street, "No Street");
    Number = new char[8];
    strcpy(Number, "No Number");
}

Address::Address(const char* name, const char* country, const char* county, const char* city, const char* street, const char* number) : Info(name) {
    Country = new char[strlen(country) + 1];
    strcpy(Country, country);
    County = new char[strlen(county) + 1];
    strcpy(County, county);
    City = new char[strlen(city) + 1];
    strcpy(City, city);
    Street = new char[strlen(street) + 1];
    strcpy(Street, street);
    Number = new char[strlen(number) + 1];
    strcpy(Number, number);
}

Address::Address(Address& address) : Info(address) {
    Country = new char[strlen(address.Country) + 1];
    strcpy(Country, address.Country);
    County = new char[strlen(address.County) + 1];
    strcpy(County, address.County);
    City = new char[strlen(address.City) + 1];
    strcpy(City, address.City);
    Street = new char[strlen(address.Street) + 1];
    strcpy(Street, address.Street);
    Number = new char[strlen(address.Number) + 1];
    strcpy(Number, address.Number);
}

Address::~Address() {
    delete[] Country;
    delete[] County;
    delete[] City;
    delete[] Street;
    delete[] Number;
}

void Address::operator=(Address& address) {
    delete[] Country;
    Country = new char[strlen(address.Country) + 1];
    strcpy(Country, address.Country);
    delete[] County;
    County = new char[strlen(address.County) + 1];
    strcpy(County, address.County);
    delete[] City;
    City = new char[strlen(address.City) + 1];
    strcpy(City, address.City);
    delete[] Street;
    Street = new char[strlen(address.Street) + 1];
    strcpy(Street, address.Street);
    delete[] Number;
    Number = new char[strlen(address.Number) + 1];
    strcpy(Number, address.Number);
}

void Address::setCountry(const char* country) {
    delete[] Country;
    Country = new char[strlen(country) + 1];
    strcpy(Country, country);
}

void Address::setCounty(const char* county) {
    delete[] County;
    County = new char[strlen(county) + 1];
    strcpy(County, county);
}

void Address::setCity(const char* city) {
    delete[] City;
    City = new char[strlen(city) + 1];
    strcpy(City, city);
}

void Address::setStreet(const char* street) {
    delete[] Street;
    Street = new char[strlen(street) + 1];
    strcpy(Street, street);
}

void Address::setNumber(const char* number) {
    delete[] Number;
    Number = new char[strlen(number) + 1];
    strcpy(Number, number);
}

const char* Address::getCountry() {
    return Country;
}

const char* Address::getCounty() {
    return County;
}

const char* Address::getCity() {
    return City;
}

const char* Address::getStreet() {
    return Street;
}

const char* Address::getNumber() {
    return Number;
}

void Address::print() {
    attron(COLOR_PAIR(2));
    mvprintw(4, 0, "%d, %s, %s %s %s str. %s, nr. %s", this->getId(), this->getName(), this->getCountry(), this->getCounty(), this->getCity(), this->getStreet(), this->getNumber());
    attroff(COLOR_PAIR(2));
}

ostream& operator<<(ostream& os, Address& address) {
    os << address.getId() << ", " << address.getName() << ", " << address.getCountry() << ", " << address.getCounty() << ", " << address.getCity() << ", " << address.getStreet() << ", " << address.getNumber();
    return os;
}