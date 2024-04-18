#include <vector>
#include <typeinfo>
#include "infoClasses.hpp"
#include "infoClasses.hpp"
#include <ncurses.h>
#include <cstring>
#include <iostream>

void findByID(vector<info*> &data, int id) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i]->get_id() == id) {
            data[i]->print();
            return;
        }
    }
    attron(COLOR_PAIR(1));
    mvprintw(4, 0, "ID %d not found", id);
    attroff(COLOR_PAIR(1));
}

void findByName(vector<info*> &data, const char* name) {
    for (int i = 0; i < data.size(); i++) {
        if (strcmp(data[i]->get_name(), name) == 0) {
            data[i]->print();
            return;
        }
    }
    attron(COLOR_PAIR(1));
    mvprintw(4, 0, "Name \"%s\" not found", name);
    attroff(COLOR_PAIR(1));
}

void addTextInfo(vector<info*> &data, const char* name, const char* value) {
    bool found = false;

    // Search if name already exists
    for (int i = 0; i < data.size(); i++) {
        if (strcmp(data[i]->get_name(), name) == 0) {
            // Name already exists, concatenate texts
            text* elem = dynamic_cast<text*>(data[i]);
            const char* oldValue = elem->get_value();
            char* newValue = new char[strlen(oldValue) + strlen(value) + 1];
            strcpy(newValue, oldValue);
            strcat(newValue, value);
            elem->set_value(newValue);
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
        // Name doesn't exist, create new info object
        text* elem = new text();
        elem->set_name(name);
        elem->set_value(value);
        data.push_back(elem);

        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "Text added successfully");
        attroff(COLOR_PAIR(2));
    }
}

void addNumberInfo(vector<info*> &data, const char* name, int value) {
    bool found = false;

    // Search if name already exists
    for (int i = 0; i < data.size(); i++) {
        if (strcmp(data[i]->get_name(), name) == 0) {
            // Name already exists, add numbers
            number* elem = dynamic_cast<number*>(data[i]);
            int oldValue = elem->get_value();
            elem->set_value(oldValue + value);
            attron(COLOR_PAIR(2));
            mvprintw(9, 0, "Number name already exists");
            mvprintw(10, 0, "Both numbers have been added");
            attroff(COLOR_PAIR(2));
            found = true;
            break;
        }
    }

    if (!found) {
        number* elem = new number();
        elem->set_name(name);
        elem->set_value(value);
        data.push_back(elem);

        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "Number added successfully");
        attroff(COLOR_PAIR(2));
    }
}

void deleteInfoById(vector<info*> &data, int id) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i]->get_id() == id) {
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

void deleteInfoByName(vector<info*> &data, const char* name) {
    for (int i = 0; i < data.size(); i++) {
        if (strcmp(data[i]->get_name(), name) == 0) {
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

void searchByTextValue(vector<info*> &data, const char* value) {
    bool found = false;
    for (int i = 0; i < data.size(); i++) {
        text* elem = dynamic_cast<text*>(data[i]);
        if (elem && typeid(*elem) == typeid(text) && strcmp(elem->get_value(), value) == 0) {
            elem->print();
            found = true;
        }
    }
    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(4, 0, "Text \"%s\" not found", value);
        attroff(COLOR_PAIR(1));
    }
}

void searchByNumberValue(vector<info*> &data, int value) {
    bool found = false;
    for (int i = 0; i < data.size(); i++) {
        number* elem = dynamic_cast<number*>(data[i]);
        if (elem && typeid(*elem) == typeid(number) && elem->get_value() == value) {
            elem->print();
            found = true;
        }
    }
    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(4, 0, "Number %d not found", value);
        attroff(COLOR_PAIR(1));
    }
}