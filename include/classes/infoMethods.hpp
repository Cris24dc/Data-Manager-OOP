
#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <ncurses.h>
#include "classes/classes.hpp"

int Info::Count = 0;

Info::Info() : Id(++Count) {
    Name = new char[8];
    strcpy(Name, "No Name");
}

Info::Info(const char* name) : Id(++Count) {
    Name = new char[strlen(name) + 1];
    strcpy(Name, name);
}

Info::Info(Info& info) : Id(++Count) {
    Name = new char[strlen(info.Name) + 1];
    strcpy(Name, info.Name);
}

Info::~Info() {
    delete[] Name;
}

void Info::operator=(Info& info) {
    delete[] Name;
    Name = new char[strlen(info.Name) + 1];
    strcpy(Name, info.Name);
}

void Info::setName(const char* name) {
    delete[] Name;
    Name = new char[strlen(name) + 1];
    strcpy(Name, name);
}

const char* Info::getName() {
    return Name;
}

int Info::getId() {
    return Id;
}