#ifndef INFO_CLASSES_HPP
#define INFO_CLASSES_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <ncurses.h>

using namespace std;

class info {
private:
    const int id;
    static int count;
    char name[255];
public:
    info();
    info(const char*);
    ~info();  
    void set_name(const char*);
    const char* get_name();
    int get_id();
    virtual void print() = 0;
};

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

class text : public info {
private:
    char value[255];
public:
    text();
    text(const char*, const char*);
    ~text();
    void set_value(const char*);
    const char* get_value();
    void print();
};

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

class number : public info {
private:
    int value;
public:
    number();
    number(const char*, int);
    ~number();
    void set_value(int);
    int get_value();
    void print();
};

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

// class math : public info {
// private:
//     int a;
//     int b;
// public:
//     math(): info() {};
//     math(const char* name): info(name) {};
//     ~math();
//     void set_values(int a, int b);
//     int get_a();
//     int get_b();
//     void print();
// };

// class adress : public info {
// private:
//     char country[255];
//     char county[255];
//     char city[255];
//     char street[255];
//     char number[255];
// public:
//     adress(): info() {};
//     adress(const char* name): info(name) {};
//     ~adress();
//     void set_values(const char* country, const char* county, const char* city, const char* street, const char* number);
//     const char* get_country();
//     const char* get_county();
//     const char* get_city();
//     const char* get_street();
//     const char* get_number();
//     void print();
// };

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

#endif