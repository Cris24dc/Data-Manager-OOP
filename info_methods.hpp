#include <iostream>
#include <string>
#include <cstring>
#include <ncurses.h>
#include "info_types.hpp"

void add_text(text* &start_text, text* &end_text, int &id, char* temp_name, char* temp_value, int &text_size) {
    text* ptr = start_text;
    bool found = false;

    while (ptr != nullptr) {
        if (strcmp(ptr->name, temp_name) == 0) {
            strcat(ptr->value, temp_value);
            attron(COLOR_PAIR(2));
            mvprintw(9, 0, "Text name already exists");
            mvprintw(10, 0, "Both texts have been concatenated");
            attroff(COLOR_PAIR(2));
            found = true;
            break;
        }
        ptr = ptr->next;
    }

    if (!found) {
        ptr = new text;
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

        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "Text added successfully");
        attroff(COLOR_PAIR(2));
    }
}

void add_number(number* &start_number, number* &end_number, int &id, char* temp_name, int temp_value, int &number_size) {
    number* ptr = start_number;
    bool found = false;

    while (ptr != nullptr) {
        if (strcmp(ptr->name, temp_name) == 0) {
            ptr->value += temp_value;
            attron(COLOR_PAIR(2));
            mvprintw(9, 0, "Number name already exists");
            mvprintw(10, 0, "Both numbers have been summed up");
            attroff(COLOR_PAIR(2));
            found = true;
            break;
        }
        ptr = ptr->next;
    }

    if (!found) {
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

        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "Number added successfully");
        attroff(COLOR_PAIR(2));
    }
}

void add_math(math* &start_math, math* &end_math, int &id, char* temp_name, int temp_a, int temp_b, int &math_size) {
    math* ptr = start_math;
    bool found = false;

    while (ptr != nullptr) {
        if (strcmp(ptr->name, temp_name) == 0) {
            ptr->part.a += temp_a;
            ptr->part.b += temp_b;
            attron(COLOR_PAIR(2));
            mvprintw(9, 0, "Complex number name already exists");
            mvprintw(10, 0, "Both complex numbers have been summed up");
            attroff(COLOR_PAIR(2));
            found = true;
            break;
        }
        ptr = ptr->next;
    }
    
    if (!found) {
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

        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "Complex number added successfully");
        attroff(COLOR_PAIR(2));
    }
}

void add_adress(adress* &start_adress, adress* &end_adress, int &id, char* temp_name, char* temp_tara, char* temp_judet, char* temp_oras, char* temp_strada, char* temp_numar, int &adress_size) {
    adress* ptr = start_adress;
    bool found = false;

    while (ptr != nullptr) {
        if (strcmp(ptr->name, temp_name) == 0) {
            attron(COLOR_PAIR(1));
            mvprintw(9, 0, "ERROR: Adress name already exists");
            mvprintw(10, 0, "Can't add an adress with the same name");
            attroff(COLOR_PAIR(1));
            found = true;
            break;
        }
        ptr = ptr->next;
    }
    
    if (!found) {
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

        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "Address added successfully");
        attroff(COLOR_PAIR(2));
    }
}

void delete_by_id(text* &start_text, text* &end_text, number* &start_number, number* &end_number, math* &start_math, math* &end_math, adress* &start_adress, adress* &end_adress, int &text_size, int &number_size, int &math_size, int &adress_size, int search_input) {
    text* text_ptr = start_text;
    text* prev_text = nullptr;
    number* number_ptr = start_number;
    number* prev_number = nullptr;
    math* math_ptr = start_math;
    math* prev_math = nullptr;
    adress* adress_ptr = start_adress;
    adress* prev_adress = nullptr;
    bool found = false;

    if (text_ptr != nullptr) {
        while (text_ptr != nullptr) {
            if (text_ptr->id == search_input) {
                if (prev_text == nullptr) {
                    start_text = text_ptr->next;
                }
                else {
                    prev_text->next = text_ptr->next;
                }
                delete text_ptr;
                text_size--;
                found = true;
                break;
            }
            prev_text = text_ptr;
            text_ptr = text_ptr->next;
        }
    }

    if (number_ptr != nullptr && !found) {
        while (number_ptr != nullptr) {
            if (number_ptr->id == search_input) {
                if (prev_number == nullptr) {
                    start_number = number_ptr->next;
                }
                else {
                    prev_number->next = number_ptr->next;
                }
                delete number_ptr;
                number_size--;
                found = true;
                break;
            }
            prev_number = number_ptr;
            number_ptr = number_ptr->next;
        }
    }

    if (math_ptr != nullptr && !found) {
        while (math_ptr != nullptr) {
            if (math_ptr->id == search_input) {
                if (prev_math == nullptr) {
                    start_math = math_ptr->next;
                }
                else {
                    prev_math->next = math_ptr->next;
                }
                delete math_ptr;
                math_size--;
                found = true;
                break;
            }
            prev_math = math_ptr;
            math_ptr = math_ptr->next;
        }
    }

    if (adress_ptr != nullptr && !found) {
        while (adress_ptr != nullptr) {
            if (adress_ptr-> id == search_input) {
                if (prev_adress == nullptr) {
                    start_adress = adress_ptr->next;
                }
                else {
                    prev_adress->next = adress_ptr->next;
                }
                delete adress_ptr;
                adress_size--;
                found = true;
                break;
            }
            prev_adress = adress_ptr;
            adress_ptr = adress_ptr->next;
        }
    }

    if (found) {
        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "ID %d deleted successfully", search_input);
        attroff(COLOR_PAIR(2));
    }
    else {
        attron(COLOR_PAIR(1));
        mvprintw(9, 0, "ID %d not found", search_input);
        attroff(COLOR_PAIR(1));
    }
}

void delete_by_name(text* &start_text, text* &end_text, number* &start_number, number* &end_number, math* &start_math, math* &end_math, adress* &start_adress, adress* &end_adress, int &text_size, int &number_size, int &math_size, int &adress_size, const char* search_input) {
    text* text_ptr = start_text;
    text* prev_text = nullptr;
    number* number_ptr = start_number;
    number* prev_number = nullptr;
    math* math_ptr = start_math;
    math* prev_math = nullptr;
    adress* adress_ptr = start_adress;
    adress* prev_adress = nullptr;
    bool found = false;

    if (text_ptr != nullptr) {
        while (text_ptr != nullptr) {
            if (strcmp(text_ptr->name, search_input) == 0) {
                if (prev_text == nullptr) {
                    start_text = text_ptr->next;
                }
                else {
                    prev_text->next = text_ptr->next;
                }
                delete text_ptr;
                text_size--;
                found = true;
                break;
            }
            prev_text = text_ptr;
            text_ptr = text_ptr->next;
        }
    }

    if (number_ptr != nullptr && !found) {
        while (number_ptr != nullptr) {
            if (strcmp(number_ptr->name, search_input) == 0) {
                if (prev_number == nullptr) {
                    start_number = number_ptr->next;
                }
                else {
                    prev_number->next = number_ptr->next;
                }
                delete number_ptr;
                number_size--;
                found = true;
                break;
            }
            prev_number = number_ptr;
            number_ptr = number_ptr->next;
        }
    }

    if (math_ptr != nullptr && !found) {
        while (math_ptr != nullptr) {
            if (strcmp(math_ptr->name, search_input) == 0) {
                if (prev_math == nullptr) {
                    start_math = math_ptr->next;
                }
                else {
                    prev_math->next = math_ptr->next;
                }
                delete math_ptr;
                math_size--;
                found = true;
                break;
            }
            prev_math = math_ptr;
            math_ptr = math_ptr->next;
        }
    }

    if (adress_ptr != nullptr && !found) {
        while (adress_ptr != nullptr) {
            if (strcmp(adress_ptr->name, search_input) == 0) {
                if (prev_adress == nullptr) {
                    start_adress = adress_ptr->next;
                }
                else {
                    prev_adress->next = adress_ptr->next;
                }
                delete adress_ptr;
                adress_size--;
                found = true;
                break;
            }
            prev_adress = adress_ptr;
            adress_ptr = adress_ptr->next;
        }
    }

    if (found) {
        attron(COLOR_PAIR(2));
        mvprintw(9, 0, "Name \"%s\" deleted successfully", search_input);
        attroff(COLOR_PAIR(2));
    }
    else {
        attron(COLOR_PAIR(1));
        mvprintw(9, 0, "Name \"%s\" not found", search_input);
        attroff(COLOR_PAIR(1));
    }

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

void search_by_text(text* text_ptr, const char* search_input) {
    int line = 4;
    bool found = false;

    if (text_ptr != nullptr) {
        while (text_ptr != nullptr) {
            if (strcmp(text_ptr->value, search_input) == 0) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %s", text_ptr->id, text_ptr->name, text_ptr->value);
                attroff(COLOR_PAIR(2));
                line++;
                found = true;
            }
            text_ptr = text_ptr->next;
        }
    }

    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(line, 0, "Text \"%s\" not found", search_input);
        attroff(COLOR_PAIR(1));
    }
}

void search_by_number(number* number_ptr, int search_input) {
    int line = 4;
    bool found = false;

    if (number_ptr != nullptr) {
        while (number_ptr != nullptr) {
            if (number_ptr->value == search_input) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %d", number_ptr->id, number_ptr->name, number_ptr->value);
                attroff(COLOR_PAIR(2));
                line++;
                found = true;
            }
            number_ptr = number_ptr->next;
        }
    }

    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(line, 0, "Number %d not found", search_input);
        attroff(COLOR_PAIR(1));
    }
}

void search_by_math(math* math_ptr, int search_input_real, int search_input_imaginary) {
    int line = 5;
    bool found = false;

    if (math_ptr != nullptr) {
        while (math_ptr != nullptr) {
            if (math_ptr->part.a == search_input_real && math_ptr->part.b == search_input_imaginary) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %d + %di", math_ptr->id, math_ptr->name, math_ptr->part.a, math_ptr->part.b);
                attroff(COLOR_PAIR(2));
                line++;
                found = true;
            }
            math_ptr = math_ptr->next;
        }
    }

    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(line, 0, "Complex number %d + %di not found", search_input_real, search_input_imaginary);
        attroff(COLOR_PAIR(1));
    }
}

void search_by_adress(adress* adress_ptr, const char* search_input_country, const char* search_input_county, const char* search_input_city, const char* search_input_street, const char* search_input_number) {
    int line = 8;
    bool found = false;

    if (adress_ptr != nullptr) {
        while (adress_ptr != nullptr) {
            if (strcmp(adress_ptr->field.tara, search_input_country) == 0 && strcmp(adress_ptr->field.judet, search_input_county) == 0 && strcmp(adress_ptr->field.oras, search_input_city) == 0 && strcmp(adress_ptr->field.strada, search_input_street) == 0 && strcmp(adress_ptr->field.numar, search_input_number) == 0) {
                attron(COLOR_PAIR(2));
                mvprintw(line, 0, "%d, %s, %s %s %s str. %s nr. %s", adress_ptr->id, adress_ptr->name, adress_ptr->field.tara, adress_ptr->field.judet, adress_ptr->field.oras, adress_ptr->field.strada, adress_ptr->field.numar);
                attroff(COLOR_PAIR(2));
                line++;
                found = true;
            }
            adress_ptr = adress_ptr->next;
        }
    }

    if (!found) {
        attron(COLOR_PAIR(1));
        mvprintw(line, 0, "Adress \"%s %s %s str. %s nr. %s\" not found", search_input_country, search_input_county, search_input_city, search_input_street, search_input_number);
        attroff(COLOR_PAIR(1));
    }
}
