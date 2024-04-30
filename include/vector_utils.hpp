#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <ncurses.h>
#include "classes/classes.hpp"
#include "classes/infoMethods.hpp"
#include "classes/textMethods.hpp"
#include "classes/numberMethods.hpp"
#include "classes/mathMethods.hpp"
#include "classes/addressMethods.hpp"


void findByID(vector<Info*> &data, int id) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i]->getId() == id) {
            data[i]->print();
            return;
        }
    }
    attron(COLOR_PAIR(1));
    mvprintw(4, 0, "ID %d not found", id);
    attroff(COLOR_PAIR(1));
}

void findByName(vector<Info*> &data, const char* name) {
    for (int i = 0; i < data.size(); i++) {
        if (strcmp(data[i]->getName(), name) == 0) {
            data[i]->print();
            return;
        }
    }
    attron(COLOR_PAIR(1));
    mvprintw(4, 0, "Name \"%s\" not found", name);
    attroff(COLOR_PAIR(1));
}

void addTextInfo(vector<Info*> &data, const char* name, const char* value) {
    bool found = false;

    for (int i = 0; i < data.size(); i++) {
        if (strcmp(data[i]->getName(), name) == 0) {
            Text* elem = dynamic_cast<Text*>(data[i]);
            const char* oldValue = elem->getValue();
            char* newValue = new char[strlen(oldValue) + strlen(value) + 1];
            strcpy(newValue, oldValue);
            strcat(newValue, value);
            elem->setValue(newValue);
            delete[] newValue;
            attron(COLOR_PAIR(2));
            mvprintw(9, 0, "Text name already exists");
            mvprintw(10, 0, "Both texts have been concatenated");
            attroff(COLOR_PAIR(2));
            found = true;
            break;
        }
    }

    if (!found) {
        Text* elem = new Text();
        elem->setName(name);
        elem->setValue(value);
        data.push_back(elem);

        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "Text added successfully");
        attroff(COLOR_PAIR(2));
    }
}

void addNumberInfo(vector<Info*> &data, const char* name, int value) {
    bool found = false;

    // Search if name already exists
    for (int i = 0; i < data.size(); i++) {
        if (strcmp(data[i]->getName(), name) == 0) {
            // Name already exists, add numbers
            Number* elem = dynamic_cast<Number*>(data[i]);
            int oldValue = elem->getValue();
            elem->setValue(oldValue + value);
            attron(COLOR_PAIR(2));
            mvprintw(9, 0, "Number name already exists");
            mvprintw(10, 0, "Both numbers have been added");
            attroff(COLOR_PAIR(2));
            found = true;
            break;
        }
    }

    if (!found) {
        Number* elem = new Number();
        elem->setName(name);
        elem->setValue(value);
        data.push_back(elem);

        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "Number added successfully");
        attroff(COLOR_PAIR(2));
    }
}

void addMathInfo(vector<Info*> &data, const char* name, int a, int b) {
    bool found = false;

    for (int i = 0; i < data.size(); i++) {
        if (strcmp(data[i]->getName(), name) == 0) {
            Math* elem = dynamic_cast<Math*>(data[i]);
            int oldA = elem->getA();
            int oldB = elem->getB();
            elem->setA(oldA + a);
            elem->setB(oldB + b);
            attron(COLOR_PAIR(2));
            mvprintw(9, 0, "Math name already exists");
            mvprintw(10, 0, "Both numbers have been added");
            attroff(COLOR_PAIR(2));
            found = true;
            break;
        }
    }

    if (!found) {
        Math* elem = new Math();
        elem->setName(name);
        elem->setA(a);
        elem->setB(b);
        data.push_back(elem);

        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "Math added successfully");
        attroff(COLOR_PAIR(2));
    }
}

void addAddressInfo(vector<Info*> &data, const char* name, const char* country, const char* county, const char* city, const char* street, const char* number) {
    bool found = false;

    for (int i = 0; i < data.size(); i++) {
        if (strcmp(data[i]->getName(), name) == 0) {
            attron(COLOR_PAIR(1));
            mvprintw(9, 0, "ERROR: Adress name already exists");
            mvprintw(10, 0, "Can't add an adress with the same name");
            attroff(COLOR_PAIR(1));
            found = true;
            break;
        }
    }

    if (!found) {
        Address* elem = new Address();
        elem->setName(name);
        elem->setCountry(country);
        elem->setCounty(county);
        elem->setCity(city);
        elem->setStreet(street);
        elem->setNumber(number);
        data.push_back(elem);

        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "Address added successfully");
        attroff(COLOR_PAIR(2));
    }
}

void deleteInfoById(vector<Info*> &data, int id) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i]->getId() == id) {
            delete data[i];
            data.erase(data.begin() + i);
            attron(COLOR_PAIR(2));
            mvprintw(9, 0, "ID %d deleted successfully", id);
            attroff(COLOR_PAIR(2));
            return;
        }
    }
    attron(COLOR_PAIR(1));
    mvprintw(9, 0, "ID %d not found", id);
    attroff(COLOR_PAIR(1));
}

void deleteInfoByName(vector<Info*> &data, const char* name) {
    for (int i = 0; i < data.size(); i++) {
        if (strcmp(data[i]->getName(), name) == 0) {
            delete data[i];
            attron(COLOR_PAIR(2));
            mvprintw(9, 0, "Name \"%s\" deleted successfully", name);
            attroff(COLOR_PAIR(2));
            return;
        }
    }
    attron(COLOR_PAIR(1));
    mvprintw(9, 0, "Name \"%s\" not found", name);
    attroff(COLOR_PAIR(1));
}

//search by values

void searchByTextValue(vector<Info*> &data, const char* value) {
    bool found = false;

    for (int i = 0; i < data.size(); i++) {
        Text* elem = dynamic_cast<Text*>(data[i]);
        if (elem && typeid(*elem) == typeid(Text) && strcmp(elem->getValue(), value) == 0) {
            elem->print();
            found = true;
        }
    }
    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(9, 0, "Text \"%s\" not found", value);
        attroff(COLOR_PAIR(1));
    }
}

void searchByNumberValue(vector<Info*> &data, int value) {
    bool found = false;

    for (int i = 0; i < data.size(); i++) {
        Number* elem = dynamic_cast<Number*>(data[i]);
        if (elem && typeid(*elem) == typeid(Number) && elem->getValue() == value) {
            elem->print();
            found = true;
        }
    }
    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(9, 0, "Number %d not found", value);
        attroff(COLOR_PAIR(1));
    }
}

void searchByMathValue(vector<Info*> &data, int a, int b) {
    bool found = false;

    for (int i = 0; i < data.size(); i++) {
        Math* elem = dynamic_cast<Math*>(data[i]);
        if (elem && typeid(*elem) == typeid(Math) && elem->getA() == a && elem->getB() == b) {
            elem->print();
            found = true;
        }
    }
    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(9, 0, "Math %d + %di not found", a, b);
        attroff(COLOR_PAIR(1));
    }
}

void searchByAddressValue(vector<Info*> &data, const char* country, const char* county, const char* city, const char* street, const char* number) {
    bool found = false;

    for (int i = 0; i < data.size(); i++) {
        Address* elem = dynamic_cast<Address*>(data[i]);
        if (elem && typeid(*elem) == typeid(Address) && strcmp(elem->getCountry(), country) == 0 && strcmp(elem->getCounty(), county) == 0 && strcmp(elem->getCity(), city) == 0 && strcmp(elem->getStreet(), street) == 0 && strcmp(elem->getNumber(), number) == 0) {
            elem->print();
            found = true;
        }
    }
    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(9, 0, "Address %s %s %s str. %s nr. %s not found", country, county, city, street, number);
        attroff(COLOR_PAIR(1));
    }
}