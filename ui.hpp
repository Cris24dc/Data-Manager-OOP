#include <iostream>
#include <string>
#include <cstring>
#include <ncurses.h>
#include "state.hpp"
#include "classes.hpp"

using namespace std;

void print_choices(State currentState, vector<Info*> &data, const string& filePath) {
    if (currentState == MAIN_MENU) {
        mvprintw(2, 0, "Choose an option:");
        mvprintw(4, 0, "1. Add Information");
        mvprintw(5, 0, "2. Delete Information");
        mvprintw(6, 0, "3. Find Information");
        mvprintw(7, 0, "4. Search Information");
        mvprintw(12, 0, "Press 'esc' to exit");
    }

    else if (currentState == ADD_INFO) {
        mvprintw(2, 0, "Choose an option:");
        mvprintw(4, 0, "1. Text");
        mvprintw(5, 0, "2. Number");
        mvprintw(6, 0, "3. Complex Number");
        mvprintw(7, 0, "4. Address");
        mvprintw(12, 0, "Press 'esc' to go back");
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
        addInfo(data, temp_name, temp_value, filePath);
        mvprintw(12, 0, "Press any key to go back");
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
        char temp_value[255];
        echo();
        getstr(temp_value);
        int temp_value_int;
        try {
            temp_value_int = stoi(temp_value);
        } catch (invalid_argument e) {
            attron(COLOR_PAIR(1));
            mvprintw(12, 0, "Invalid number");
            attroff(COLOR_PAIR(1));
            mvprintw(13, 0, "Press any key to go back");
            return;
        }
        noecho();
        addInfo(data, temp_name, temp_value_int, filePath);
        mvprintw(12, 0, "Press any key to go back");
    }

    else if (currentState == ADD_INFO_MATH) {
        mvprintw(2, 0, "Enter the name of the complex number: ");
        refresh();
        char temp_name[255];
        echo();
        getstr(temp_name);
        noecho();
        mvprintw(3, 0, "Enter the real part: ");
        refresh();
        char temp_a[255];
        echo();
        getstr(temp_a);
        int temp_a_int;
        try {
            temp_a_int = stoi(temp_a);
        } catch (invalid_argument e) {
            attron(COLOR_PAIR(1));
            mvprintw(12, 0, "Invalid real part number");
            attroff(COLOR_PAIR(1));
            mvprintw(13, 0, "Press any key to go back");
            return;
        }
        noecho();
        mvprintw(4, 0, "Enter the imaginary part: ");
        refresh();
        char temp_b[255];
        echo();
        getstr(temp_b);
        int temp_b_int;
        try {
            temp_b_int = stoi(temp_b);
        } catch (invalid_argument e) {
            attron(COLOR_PAIR(1));
            mvprintw(12, 0, "Invalid imaginary part number");
            attroff(COLOR_PAIR(1));
            mvprintw(13, 0, "Press any key to go back");
            return;
        }
        noecho();
        addInfo(data, temp_name, temp_a_int, temp_b_int, filePath);
        mvprintw(12, 0, "Press any key to go back");
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
        int temp_numar_int;
        try {
            temp_numar_int = stoi(temp_numar);
        } catch (invalid_argument e) {
            attron(COLOR_PAIR(1));
            mvprintw(12, 0, "Invalid address number");
            attroff(COLOR_PAIR(1));
            mvprintw(13, 0, "Press any key to go back");
            return;
        }
        noecho();
        addInfo(data, temp_name, temp_tara, temp_judet, temp_oras, temp_strada, temp_numar, filePath);
        mvprintw(12, 0, "Press any key to go back");
    }

    else if (currentState == DELETE_INFO) {
        mvprintw(2, 0, "Choose an option:");
        mvprintw(4, 0, "1. Delete by ID");
        mvprintw(5, 0, "2. Delete by Name");
        mvprintw(12, 0, "Press 'esc' to go back");
    }

    else if (currentState == DELETE_INFO_ID) {
        mvprintw(2, 0, "Enter the ID to delete: ");
        refresh();
        int delete_input;
        echo();
        scanw("%d", &delete_input);
        noecho();
        deleteInfoById(data, delete_input, filePath);
        mvprintw(12, 0, "Press any key to go back");
    }

    else if (currentState == DELETE_INFO_NAME) {
        mvprintw(2, 0, "Enter the name to delete: ");
        refresh();
        char delete_input[255];
        echo();
        getstr(delete_input);
        noecho();
        deleteInfoByName(data, delete_input, filePath);
        mvprintw(12, 0, "Press any key to go back");
    }

    else if (currentState == FIND_INFO) {
        mvprintw(2, 0, "Choose an option:");
        mvprintw(4, 0, "1. Find by ID");
        mvprintw(5, 0, "2. Find by Name");
        mvprintw(12, 0, "Press 'esc' to go back");
    }

    else if (currentState == FIND_INFO_NAME){
        mvprintw(2, 0, "Enter the name to search: ");
        refresh();
        char search_input[255];
        echo();
        getstr(search_input);
        noecho();
        findByName(data, search_input);
        mvprintw(12, 0, "Press any key to go back");
    }

    else if (currentState == FIND_INFO_ID) {
        mvprintw(2, 0, "Enter the ID to search: ");
        refresh();
        int search_input;
        echo();
        scanw("%d", &search_input);
        noecho();
        findByID(data, search_input);
        mvprintw(12, 0, "Press any key to go back");
    }

    else if (currentState == SEARCH_INFO) {
        mvprintw(2, 0, "Choose an option:");
        mvprintw(4, 0, "1. Search by Text");
        mvprintw(5, 0, "2. Search by Number");
        mvprintw(6, 0, "3. Search by Complex Number");
        mvprintw(7, 0, "4. Search by Address");
        mvprintw(12, 0, "Press any key to go back");
    }

    else if(currentState == SEARCH_INFO_TEXT) {
        mvprintw(2, 0, "Enter the text value: ");
        refresh();
        char search_input_text[255];
        echo();
        getstr(search_input_text);
        noecho();
        seachByValue(data, search_input_text);
        mvprintw(12, 0, "Press any key to go back");
    }

    else if(currentState == SEARCH_INFO_NUMBER) {
        mvprintw(2, 0, "Enter the number value: ");
        refresh();
        int search_input_number;
        echo();
        scanw("%d", &search_input_number);
        noecho();
        seachByValue(data, search_input_number);
        mvprintw(12, 0, "Press any key to go back");
    }

    else if(currentState == SEARCH_INFO_MATH) {
        mvprintw(2, 0, "Enter the real part: ");
        refresh();
        int search_input_real;
        echo();
        scanw("%d", &search_input_real);
        noecho();
        mvprintw(3, 0, "Enter the imaginary part: ");
        refresh();
        int search_input_imag;
        echo();
        scanw("%d", &search_input_imag);
        noecho();
        seachByValue(data, search_input_real, search_input_imag);
        mvprintw(12, 0, "Press any key to go back");
    }

    else if(currentState == SEARCH_INFO_ADDRESS) {
        mvprintw(2, 0, "Enter the country: ");
        refresh();
        char search_input_country[255];
        echo();
        getstr(search_input_country);
        noecho();
        mvprintw(3, 0, "Enter the county: ");
        refresh();
        char search_input_county[255];
        echo();
        getstr(search_input_county);
        noecho();
        mvprintw(4, 0, "Enter the city: ");
        refresh();
        char search_input_city[255];
        echo();
        getstr(search_input_city);
        noecho();
        mvprintw(5, 0, "Enter the street: ");
        refresh();
        char search_input_street[255];
        echo();
        getstr(search_input_street);
        noecho();
        mvprintw(6, 0, "Enter the number: ");
        refresh();
        char search_input_number[255];
        echo();
        getstr(search_input_number);
        noecho();
        seachByValue(data, search_input_country, search_input_county, search_input_city, search_input_street, search_input_number);
        mvprintw(12, 0, "Press any key to go back");
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
        case SEARCH_INFO_TEXT:
        case SEARCH_INFO_NUMBER:
        case SEARCH_INFO_MATH:
        case SEARCH_INFO_ADDRESS:
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
                case '1':
                    currentState = SEARCH_INFO_TEXT;
                    break;
                case '2':
                    currentState = SEARCH_INFO_NUMBER;
                    break;
                case '3':
                    currentState = SEARCH_INFO_MATH;
                    break;
                case '4':
                    currentState = SEARCH_INFO_ADDRESS;
                    break;
                default:
                    currentState = MAIN_MENU;
                    break;
            }
            break;

        case SEARCH_INFO_TEXT:
            switch(choice) {
                default:
                    currentState = SEARCH_INFO;
                    break;
            }
            break;

        case SEARCH_INFO_NUMBER:
            switch(choice) {
                default:
                    currentState = SEARCH_INFO;
                    break;
            }
            break;

        case SEARCH_INFO_MATH:
            switch(choice) {
                default:
                    currentState = SEARCH_INFO;
                    break;
            }
            break;

        case SEARCH_INFO_ADDRESS:    
            switch(choice) {
                default:
                    currentState = SEARCH_INFO;
                    break;
            }
            break;
    }
    return currentState;
}


