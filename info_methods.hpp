#include <iostream>
#include <string>
#include <cstring>
#include <ncurses.h>
#include "info_types.hpp"

void add_text(text* &start_text, text* &end_text, int &id, char* temp_name, char* temp_value, int &text_size) {
    text* ptr = new text;
    ptr->id = id++;
    strcpy(ptr->name, temp_name);
    strcpy(ptr->value, temp_value);
    ptr->next = nullptr;

    if (end_text == nullptr) {
        end_text = ptr;
        start_text = end_text;
    }
    else {
        end_text->next = ptr;
        end_text = ptr;
    }
    text_size++;
}

void add_number(number* &start_number, number* &end_number, int &id, char* temp_name, int temp_value, int &number_size) {
    number* ptr = new number;
    ptr->id = id++;
    strcpy(ptr->name, temp_name);
    ptr->value = temp_value;
    ptr->next = nullptr;

    if (end_number == nullptr) {
        end_number = ptr;
        start_number = end_number;
    }
    else {
        end_number->next = ptr;
        end_number = ptr;
    }
    number_size++;
}

void add_math(math* &start_math, math* &end_math, int &id, char* temp_name, int temp_a, int temp_b, int &math_size) {
    math* ptr = new math;
    ptr->id = id++;
    strcpy(ptr->name, temp_name);
    ptr->part.a = temp_a;
    ptr->part.b = temp_b;
    ptr->next = nullptr;

    if (end_math == nullptr) {
        end_math = ptr;
        start_math = end_math;
    }
    else {
        end_math->next = ptr;
        end_math = ptr;
    }
    math_size++;
}

void add_adress(adress* &start_adress, adress* &end_adress, int &id, char* temp_name, char* temp_tara, char* temp_judet, char* temp_oras, char* temp_strada, char* temp_numar, int &adress_size) {
    adress* ptr = new adress;
    ptr->id = id++;
    strcpy(ptr->name, temp_name);
    strcpy(ptr->field.tara, temp_tara);
    strcpy(ptr->field.judet, temp_judet);
    strcpy(ptr->field.oras, temp_oras);
    strcpy(ptr->field.strada, temp_strada);
    strcpy(ptr->field.numar, temp_numar);
    ptr->next = nullptr;

    if (end_adress == nullptr) {
        end_adress = ptr;
        start_adress = end_adress;
    }
    else {
        end_adress->next = ptr;
        end_adress = ptr;
    }
    adress_size++;
}

void find_by_name(text* text_ptr, number* number_ptr, math* math_ptr, adress* adress_ptr, const char* search_input) {
    int line = 4;
    bool found = false;

    if (text_ptr != nullptr) {
        while (text_ptr != nullptr) {
            if (strcmp(text_ptr->name, search_input) == 0) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %s", text_ptr->id, text_ptr->name, text_ptr->value);
                attroff(COLOR_PAIR(2));
                found = true;
                break;
            }
            text_ptr = text_ptr->next;
        }
    }

    if (number_ptr != nullptr && !found) {
        while (number_ptr != nullptr) {
            if (strcmp(number_ptr->name, search_input) == 0) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %d", number_ptr->id, number_ptr->name, number_ptr->value);
                attroff(COLOR_PAIR(2));
                found = true;
                break;
            }
            number_ptr = number_ptr->next;
        }
    }

    if (math_ptr != nullptr && !found) {
        while (math_ptr != nullptr) {
            if (strcmp(math_ptr->name, search_input) == 0) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %d + %di", math_ptr->id, math_ptr->name, math_ptr->part.a, math_ptr->part.b);
                attroff(COLOR_PAIR(2));
                found = true;
                break;
            }
            math_ptr = math_ptr->next;
        }
    }

    if (adress_ptr != nullptr && !found) {
        while (adress_ptr != nullptr) {
            if (strcmp(adress_ptr->name, search_input) == 0) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %s %s %s str. %s nr. %s", adress_ptr->id, adress_ptr->name, adress_ptr->field.tara, adress_ptr->field.judet, adress_ptr->field.oras, adress_ptr->field.strada, adress_ptr->field.numar);
                attroff(COLOR_PAIR(2));
                found = true;
                break;
            }
            adress_ptr = adress_ptr->next;
        }
    }

    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(line, 0, "Name \"%s\" not found", search_input);
        attroff(COLOR_PAIR(1));
    }
}

void find_by_id(text* text_ptr, number* number_ptr, math* math_ptr, adress* adress_ptr, int search_input) {
    int line = 4;
    bool found = false;

    if (text_ptr != nullptr) {
        while (text_ptr != nullptr) {
            if (text_ptr->id == search_input) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %s", text_ptr->id, text_ptr->name, text_ptr->value);
                attroff(COLOR_PAIR(2));
                found = true;
                break;
            }
            text_ptr = text_ptr->next;
        }
    }

    if (number_ptr != nullptr && !found) {
        while (number_ptr != nullptr) {
            if (number_ptr->id == search_input) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %d", number_ptr->id, number_ptr->name, number_ptr->value);
                attroff(COLOR_PAIR(2));
                found = true;
                break;
            }
            number_ptr = number_ptr->next;
        }
    }

    if (math_ptr != nullptr && !found) {
        while (math_ptr != nullptr) {
            if (math_ptr->id == search_input) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %d + %di", math_ptr->id, math_ptr->name, math_ptr->part.a, math_ptr->part.b);
                attroff(COLOR_PAIR(2));
                found = true;
                break;
            }
            math_ptr = math_ptr->next;
        }
    }

    if (adress_ptr != nullptr && !found) {
        while (adress_ptr != nullptr) {
            if (adress_ptr->id == search_input) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %s %s %s str. %s nr. %s", adress_ptr->id, adress_ptr->name, adress_ptr->field.tara, adress_ptr->field.judet, adress_ptr->field.oras, adress_ptr->field.strada, adress_ptr->field.numar);
                attroff(COLOR_PAIR(2));
                found = true;
                break;
            }
            adress_ptr = adress_ptr->next;
        }
    }

    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(line, 0, "ID %d not found", search_input);
        attroff(COLOR_PAIR(1));
    }
}
