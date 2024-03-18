#ifndef INFO_TYPES_HPP
#define INFO_TYPES_HPP

struct text {
    int id;
    char name[255];
    char value[255];
    text* next;
};

struct number {
    int id;
    char name[255];
    int value;
    number* next;
};

struct math {
    int id;
    char name[255];
    struct parts {
        int a;
        int b;
    }part;
    math* next;
};

struct adress {
    int id;
    char name[255];
    struct fields {
        char tara[255];
        char judet[255];
        char oras[255];
        char strada[255];
        char numar[255];
    }field;
    adress* next;
};


#endif