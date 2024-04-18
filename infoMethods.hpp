#include <ncurses.h>
#include <cstring>
#include <vector>
#include <typeinfo>
#include "infoClasses.hpp"

//info class

int info::count = 0;

info::info() : id(++count) {
    strcpy(this->name, "No name");
}

info::info(const char* name) : id(++count) {
    strcpy(this->name, name);
}

info::~info() {
}

void info::set_name(const char* name) {
    strcpy(this->name, name);
}

const char* info::get_name() {
    return this->name;
}

int info::get_id() {
    return this->id;
}

// text class

text::text() : info() {
    strcpy(this->value, "No value");
}

text::text(const char* name, const char* value) : info(name) {
    strcpy(this->value, value);
}

text::~text() {}

void text::set_value(const char* value) {
    strcpy(this->value, value);
}

const char* text::get_value() {
    return this->value;
}

void text::print() {
    attron(COLOR_PAIR(2));
    mvprintw(4, 0, "%d, %s, %s", this->get_id(), this->get_name(), this->get_value());
    attroff(COLOR_PAIR(2));
}

// number class

number::number() : info() {
    this->value = 0;
}

number::number(const char* name, int value) : info(name) {
    this->value = value;
}

number::~number() {}

void number::set_value(int value) {
    this->value = value;
}

int number::get_value() {
    return this->value;
}

void number::print() {
    attron(COLOR_PAIR(2));
    mvprintw(4, 0, "%d, %s, %d", this->get_id(), this->get_name(), this->get_value());
    attroff(COLOR_PAIR(2));
}