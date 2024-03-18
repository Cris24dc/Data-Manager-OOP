#include <iostream>
#include <string>
#include <cstring>
#include <ncurses.h>
#include "state.hpp"
#include "info_types.hpp"
#include "info_methods.hpp"

using namespace std;

void print_choices(State currentState, text* &start_text, text* &end_text, int &id, int &text_size, number* &start_number, number* &end_number, int &number_size, math* &start_math, math* &end_math, int &math_size, adress* &start_adress, adress* &end_adress, int &adress_size) {
    if (currentState == MAIN_MENU) {
        mvprintw(2, 0, "Choose an option:");
        mvprintw(4, 0, "1. Add Information");
        mvprintw(5, 0, "2. Delete Information");
        mvprintw(6, 0, "3. Find Information");
        mvprintw(7, 0, "4. Search Information");
        mvprintw(9, 0, "Press 'esc' to exit");
    }

    else if (currentState == ADD_INFO) {
        mvprintw(2, 0, "Choose an option:");
        mvprintw(4, 0, "1. Text");
        mvprintw(5, 0, "2. Number");
        mvprintw(6, 0, "3. Mathematics");
        mvprintw(7, 0, "4. Address");
        mvprintw(9, 0, "Press 'esc' to go back");
    }

    else if (currentState == ADD_INFO_TEXT) {
        mvprintw(2, 0, "Enter the name of the text: ");
        refresh();
        char temp_name[255], temp_value[255];
        echo();
        getstr(temp_name);
        mvprintw(3, 0, "Enter the value of the text: ");
        refresh();
        getstr(temp_value);
        noecho();
        add_text(start_text, end_text, id, temp_name, temp_value, text_size);
        mvprintw(9, 0, "Press any key to go back");
    }

    else if (currentState == ADD_INFO_NUMBER) {
        mvprintw(2, 0, "Enter the name of the number: ");
        refresh();
        char temp_name[255];
        echo();
        getstr(temp_name);
        noecho();
        mvprintw(3, 0, "Enter the value of the number: ");
        refresh();
        int temp_value;
        echo();
        scanw("%d", &temp_value);
        noecho();
        add_number(start_number, end_number, id, temp_name, temp_value, number_size);
        mvprintw(9, 0, "Press any key to go back");
    }

    else if (currentState == ADD_INFO_MATH) {
        mvprintw(2, 0, "Enter the name of the math: ");
        refresh();
        char temp_name[255];
        echo();
        getstr(temp_name);
        noecho();
        mvprintw(3, 0, "Enter the first value of the math: ");
        refresh();
        int temp_a;
        echo();
        scanw("%d", &temp_a);
        noecho();
        mvprintw(4, 0, "Enter the second value of the math: ");
        refresh();
        int temp_b;
        echo();
        scanw("%d", &temp_b);
        noecho();
        add_math(start_math, end_math, id, temp_name, temp_a, temp_b, math_size);
        mvprintw(9, 0, "Press any key to go back");
    }

    else if (currentState == ADD_INFO_ADDRESS) {
        mvprintw(2, 0, "Enter the name of the address: ");
        refresh();
        char temp_name[255];
        echo();
        getstr(temp_name);
        noecho();
        mvprintw(3, 0, "Enter the country: ");
        refresh();
        char temp_tara[255];
        echo();
        getstr(temp_tara);
        noecho();
        mvprintw(4, 0, "Enter the county: ");
        refresh();
        char temp_judet[255];
        echo();
        getstr(temp_judet);
        noecho();
        mvprintw(5, 0, "Enter the city: ");
        refresh();
        char temp_oras[255];
        echo();
        getstr(temp_oras);
        noecho();
        mvprintw(6, 0, "Enter the street: ");
        refresh();
        char temp_strada[255];
        echo();
        getstr(temp_strada);
        noecho();
        mvprintw(7, 0, "Enter the number: ");
        refresh();
        char temp_numar[255];
        echo();
        getstr(temp_numar);
        noecho();
        add_adress(start_adress, end_adress, id, temp_name, temp_tara, temp_judet, temp_oras, temp_strada, temp_numar, adress_size);
        mvprintw(9, 0, "Press any key to go back");
    }

    else if (currentState == DELETE_INFO) {
        mvprintw(2, 0, "Choose an option:");
        mvprintw(4, 0, "1. Delete by ID");
        mvprintw(5, 0, "2. Delete by Name");
        mvprintw(9, 0, "Press 'esc' to go back");
    }

    else if (currentState == FIND_INFO) {
        mvprintw(2, 0, "Choose an option:");
        mvprintw(4, 0, "1. Find by ID");
        mvprintw(5, 0, "2. Find by Name");
        mvprintw(9, 0, "Press 'esc' to go back");
    }

    else if (currentState == FIND_INFO_NAME){
        mvprintw(2, 0, "Enter the name to search: ");
        refresh();
        char search_input[255];
        echo();
        getstr(search_input);
        noecho();
        find_by_name(start_text, start_number, start_math, start_adress, search_input);
        mvprintw(9, 0, "Press any key to go back");
    }

    else if (currentState == FIND_INFO_ID) {
        mvprintw(2, 0, "Enter the ID to search: ");
        refresh();
        int search_input;
        echo();
        scanw("%d", &search_input);
        noecho();
        find_by_id(start_text, start_number, start_math, start_adress, search_input);
        mvprintw(9, 0, "Press any key to go back");
    }

    else if (currentState == SEARCH_INFO) {
        mvprintw(2, 0, "Search by value: ");
        // refresh();
        // char input[100];
        // echo();
        // getstr(input);
        // noecho();
        // printw("You entered: %s", input);
        // refresh();
        mvprintw(19, 0, "Press any key to go back");
    }
}

void print_title(State currentState, int xMax) {
    const char* title;

    switch (currentState) {
        case MAIN_MENU:
            title = "Library";
            break;

        case ADD_INFO:
        case ADD_INFO_TEXT:
        case ADD_INFO_NUMBER:
        case ADD_INFO_MATH:
        case ADD_INFO_ADDRESS:
            title = "Add Information";
            break;

        case DELETE_INFO:
        case DELETE_INFO_ID:
        case DELETE_INFO_NAME:
            title = "Delete Information";
            break;

        case FIND_INFO:
        case FIND_INFO_ID:
        case FIND_INFO_NAME:
            title = "Find Information";
            break;

        case SEARCH_INFO:
            title = "Search Information";
            break;
    }

    int numEquals = (xMax - strlen(title) - 4) / 2;

    // Print the title
    for (int i = 0; i < numEquals; ++i) {
        printw("=");
    }

    printw(" %s ", title);

    for (int i = 0; i < numEquals; ++i) {
        printw("=");
    }

    printw("\n");
}


State next_state(State currentState, int choice) {
    switch (currentState) {
        case MAIN_MENU:
            switch(choice) {
                case '1':
                    currentState = ADD_INFO;
                    break;
                case '2':
                    currentState = DELETE_INFO;
                    break;
                case '3':
                    currentState = FIND_INFO;
                    break;
                case '4':
                    currentState = SEARCH_INFO;
                    break;
                case 27: // 'esc' key
                    endwin();
                    exit(0);
                default:
                    break;
            }
            break;

        case ADD_INFO:
            switch(choice) {
                case '1':
                    currentState = ADD_INFO_TEXT;
                    break;
                case '2':
                    currentState = ADD_INFO_NUMBER;
                    break;
                case '3':
                    currentState = ADD_INFO_MATH;
                    break;
                case '4':
                    currentState = ADD_INFO_ADDRESS;
                    break;
                case 27: // 'esc' key
                    currentState = MAIN_MENU;
                    break;
                default:
                    break;
            }
            break;

        case ADD_INFO_TEXT:
            switch(choice) {
                default:
                    currentState = ADD_INFO;
                    break;
            }
            break;

        case ADD_INFO_NUMBER:
            switch(choice) {
                default:
                    currentState = ADD_INFO;
                    break;
            }
            break;

        case ADD_INFO_MATH:
            switch(choice) {
                default:
                    currentState = ADD_INFO;
                    break;
            }
            break;

        case ADD_INFO_ADDRESS:
            switch(choice) {
                default:
                    currentState = ADD_INFO;
                    break;
            }
            break;
        
        case DELETE_INFO:
            switch(choice) {
                case '1':
                    currentState = DELETE_INFO_ID;
                    break;
                case '2':
                    currentState = DELETE_INFO_NAME;
                    break;
                case 27: // 'esc' key
                    currentState = MAIN_MENU;
                    break;
                default:
                    break;
            }
            break;

        case DELETE_INFO_ID:
            switch(choice) {
                default:
                    currentState = DELETE_INFO;
                    break;
            }
            break;

        case DELETE_INFO_NAME:
            switch(choice) {
                default:
                    currentState = DELETE_INFO;
                    break;
            }
            break;

        case FIND_INFO:
            switch(choice) {
                case '1':
                    currentState = FIND_INFO_ID;
                    break;
                case '2':
                    currentState = FIND_INFO_NAME;
                    break;
                case 27: // 'esc' key
                    currentState = MAIN_MENU;
                    break;
                default:
                    break;
            }
            break;

        case FIND_INFO_ID:
            switch(choice) {
                default:
                    currentState = FIND_INFO;
                    break;
            }
            break;

        case FIND_INFO_NAME:
            switch(choice) {
                default:
                    currentState = FIND_INFO;
                    break;
            }
            break;
        
        case SEARCH_INFO:
            switch(choice) {
                default:
                    currentState = MAIN_MENU;
                    break;
            }
            break;
    }
    return currentState;
}


