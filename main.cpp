#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstring>
using namespace std;

enum State { MAIN_MENU, ADD_INFO, DELETE_INFO, FIND_INFO, SEARCH_INFO};

int main() {
    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    State currentState = MAIN_MENU;

    while (true) {
        clear();

        const char* title;
        int numEquals;

        // Select the title based on the current state
        switch (currentState) {
            case MAIN_MENU:
                title = "Library";
                numEquals = (xMax - strlen(title) - 4) / 2;
                break;

            case ADD_INFO:
                title = "Add Information";
                numEquals = (xMax - strlen(title) - 4) / 2;
                break;

            case DELETE_INFO:
                title = "Delete Information";
                numEquals = (xMax - strlen(title) - 4) / 2;
                break;
            
            case FIND_INFO:
                title = "Find Information";
                numEquals = (xMax - strlen(title) - 4) / 2;
                break;

            case SEARCH_INFO:
                title = "Search Information";
                numEquals = (xMax - strlen(title) - 4) / 2;
                break;
        }

        // Print the title
        for (int i = 0; i < numEquals; ++i) {
            printw("=");
        }

        printw(" %s ", title);

        for (int i = 0; i < numEquals; ++i) {
            printw("=");
        }

        printw("\n");

        // Print the options based on the current state
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
            mvprintw(8, 0, "Press any key to search again");
            mvprintw(9, 0, "Press 'esc' to go back");
        }

        refresh();

        int choice = getch();

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
                        return 0;
                    default:
                        break;
                }
                break;

            case ADD_INFO:
                switch(choice) {
                    case '1':
                        break;
                    case '2':
                        break;
                    case '3':
                        break;
                    case '4':
                        break;
                    case 27: // 'esc' key
                        currentState = MAIN_MENU;
                        break;
                    default:
                        break;
                }
                break;
            
            case DELETE_INFO:
                switch(choice) {
                    case '1':
                        break;
                    case '2':
                        break;
                    case '3':
                        break;
                    case '4':
                        break;
                    case 27: // 'esc' key
                        currentState = MAIN_MENU;
                        break;
                    default:
                        break;
                }
                break;

            case FIND_INFO:
                switch(choice) {
                    case '1':
                        break;
                    case '2':
                        break;
                    case '3':
                        break;
                    case '4':
                        break;
                    case 27: // 'esc' key
                        currentState = MAIN_MENU;
                        break;
                    default:
                        break;
                }
                break;
            
            case SEARCH_INFO:
                switch(choice) {
                    case '1':
                        break;
                    case '2':
                        break;
                    case '3':
                        break;
                    case '4':
                        break;
                    case 27: // 'esc' key
                        currentState = MAIN_MENU;
                        break;
                    default:
                        break;
                }
                break;
        }
    }

    endwin();

    return 0;
}
