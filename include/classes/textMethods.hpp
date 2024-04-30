#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <ncurses.h>
#include "classes/classes.hpp"

Text::Text() : Info() {
    Value = new char[8];
    strcpy(Value, "No Value");
}

Text::Text(const char* name, const char* value) : Info(name) {
    Value = new char[strlen(value) + 1];
    strcpy(Value, value);
}

Text::Text(Text& text) : Info(text) {
    Value = new char[strlen(text.Value) + 1];
    strcpy(Value, text.Value);
}

Text::~Text() {
    delete[] Value;
}

void Text::operator=(Text& text) {
    delete[] Value;
    Value = new char[strlen(text.Value) + 1];
    strcpy(Value, text.Value);
}

void Text::setValue(const char* value) {
    delete[] Value;
    Value = new char[strlen(value) + 1];
    strcpy(Value, value);
}

const char* Text::getValue() {
    return Value;
}

void Text::print() {
    attron(COLOR_PAIR(2));
    mvprintw(4, 0, "%d, %s, %s", this->getId(), this->getName(), this->getValue());
    attroff(COLOR_PAIR(2));
}

ostream& operator<<(ostream& os, Text& text) {
    os << text.getId() << ", " << text.getName() << ", " << text.getValue();
    return os;
}

Text Text::operator+(Text& text) {
    char* temp = new char[strlen(this->Value) + strlen(text.Value) + 1];
    strcpy(temp, this->Value);
    strcat(temp, text.Value);
    Text newText(this->getName(), temp);
    delete[] temp;
    return newText;
}

Text Text::operator+=(Text& text) {
    char* temp = new char[strlen(this->Value) + strlen(text.Value) + 1];
    strcpy(temp, this->Value);
    strcat(temp, text.Value);
    delete[] Value;
    Value = new char[strlen(temp) + 1];
    strcpy(Value, temp);
    delete[] temp;
    return *this;
}