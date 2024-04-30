#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <ncurses.h>
#include "classes/classes.hpp"

Math::Math() : Info() {
    A = 0;
    B = 0;
}

Math::Math(const char* name, int a, int b) : Info(name) {
    A = a;
    B = b;
}

Math::Math(Math& math) : Info(math) {
    A = math.A;
    B = math.B;
}

Math::~Math() {}

void Math::operator=(Math& math) {
    A = math.A;
    B = math.B;
}

void Math::setA(int a) {
    A = a;
}

void Math::setB(int b) {
    B = b;
}

int Math::getA() {
    return A;
}

int Math::getB() {
    return B;
}

void Math::print() {
    attron(COLOR_PAIR(2));
    mvprintw(4, 0, "%d, %s, %d + %di", this->getId(), this->getName(), this->getA(), this->getB());
    attroff(COLOR_PAIR(2));
}

ostream& operator<<(ostream& os, Math& math) {
    os << math.getId() << ", " << math.getName() << ", " << math.getA() << " + " << math.getB() << "i";
    return os;
}

Math Math::operator+(Math& math) {
    Math newMath(this->getName(), this->A + math.A, this->B + math.B);
    return newMath;
}

Math Math::operator+=(Math& math) {
    A += math.A;
    B += math.B;
    return *this;
}