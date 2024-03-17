#include <string>
#include <cstring>
#include <ncurses.h>
#include "state.hpp"

struct text{
    unsigned int id;
    char* name;
    char* value;
};

void print_choices(State currentState) {
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
        mvprintw(2, 0, "Search by value: ");
        refresh();
        char input[100];
        echo();
        getstr(input);
        noecho();
        printw("You entered: %s", input);
        refresh();
        mvprintw(9, 0, "Press any key to go back");
    }

    else if (currentState == ADD_INFO_NUMBER) {
        mvprintw(2, 0, "Search by value: ");
        refresh();
        char input[100];
        echo();
        getstr(input);
        noecho();
        printw("You entered: %s", input);
        refresh();
        mvprintw(9, 0, "Press any key to go back");
    }
    
    else if (currentState == ADD_INFO_MATH) {
        mvprintw(2, 0, "Search by value: ");
        refresh();
        char input[100];
        echo();
        getstr(input);
        noecho();
        printw("You entered: %s", input);
        refresh();
        mvprintw(9, 0, "Press any key to go back");
    }

    else if (currentState == ADD_INFO_ADDRESS) {
        mvprintw(2, 0, "Search by value: ");
        refresh();
        char input[100];
        echo();
        getstr(input);
        noecho();
        printw("You entered: %s", input);
        refresh();
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

    else if (currentState == SEARCH_INFO) {
        mvprintw(2, 0, "Search by value: ");
        refresh();
        char input[100];
        echo();
        getstr(input);
        noecho();
        printw("You entered: %s", input);
        refresh();
        mvprintw(9, 0, "Press any key to go back");
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


