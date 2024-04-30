#ifndef INFO_CLASSES_HPP
#define INFO_CLASSES_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <ncurses.h>

using namespace std;

class Info {
private:
    const int Id;
    static int Count;
    char* Name;
public:
    Info();
    Info(const char*);
    Info(Info&);
    ~Info();  
    void operator=(Info&);
    void setName(const char*);
    const char* getName();
    int getId();
    virtual void print() = 0;
};

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

class Text : public Info {
private:
    char* Value;
public:
    Text();
    Text(const char*, const char*);
    Text(Text&);
    ~Text();
    void operator=(Text&);
    void setValue(const char*);
    const char* getValue();
    void print();
    friend ostream& operator<<(ostream&, Text&);
    Text operator+(Text&);
    Text operator+=(Text&);
};

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

class Number : public Info {
private:
    int Value;
public:
    Number();
    Number(const char*, int);
    Number(Number&);
    ~Number();
    void operator=(Number&);
    void setValue(int);
    int getValue();
    void print();
    friend ostream& operator<<(ostream&, Number&);
    Number operator+(Number&);
    Number operator+=(Number&);
};

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

class Math : public Info {
private:
    int A;
    int B;
public:
    Math();
    Math(const char*, int, int);
    Math(Math&);
    ~Math();
    void operator=(Math&);
    void setA(int);
    void setB(int);
    int getA();
    int getB();
    void print();
    friend ostream& operator<<(ostream&, Math&);
    Math operator+(Math&);
    Math operator+=(Math&);
};

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

class Address : public Info {
private:
    char* Country;
    char* County;
    char* City;
    char* Street;
    char* Number;
public:
    Address();
    Address(const char*, const char*, const char*, const char*, const char*, const char*);
    Address(Address&);
    ~Address();
    void operator=(Address&);
    void setCountry(const char*);
    void setCounty(const char*);
    void setCity(const char*);
    void setStreet(const char*);
    void setNumber(const char*);
    const char* getCountry();
    const char* getCounty();
    const char* getCity();
    const char* getStreet();
    const char* getNumber();
    void print();
    friend ostream& operator<<(ostream&, Address&);
};

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

#endif