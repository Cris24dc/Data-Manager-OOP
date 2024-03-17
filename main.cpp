#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstring>
#include "state.hpp"
#include "ui.hpp"
using namespace std;


int main() {
    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    State currentState = MAIN_MENU;

    while (true) {
        clear();

        print_title(currentState, xMax);

        print_choices(currentState);

        refresh();

        int choice = getch();

        currentState = next_state(currentState, choice);
    }

    endwin();

    return 0;
}
