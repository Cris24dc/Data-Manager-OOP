#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <ncurses.h>
#include "classes/classes.hpp"

Number::Number() : Info() {
    Value = 0;
}

Number::Number(const char* name, int value) : Info(name) {
    Value = value;
}

Number::Number(Number& number) : Info(number) {
    Value = number.Value;
}

Number::~Number() {}

void Number::operator=(Number& number) {
    Value = number.Value;
}

void Number::setValue(int value) {
    Value = value;
}

int Number::getValue() {
    return Value;
}

void Number::print() {
    attron(COLOR_PAIR(2));
    mvprintw(4, 0, "%d, %s, %d", this->getId(), this->getName(), this->getValue());
    attroff(COLOR_PAIR(2));
}

ostream& operator<<(ostream& os, Number& number) {
    os << number.getId() << ", " << number.getName() << ", " << number.getValue();
    return os;
}

Number Number::operator+(Number& number) {
    Number newNumber(this->getName(), this->Value + number.Value);
    return newNumber;
}

Number Number::operator+=(Number& number) {
    Value += number.Value;
    return *this;
}