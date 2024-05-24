#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstring>
#include <vector>
#include "state.hpp"
#include "ui.hpp"
#include "classes.hpp"
using namespace std;

int main() {

    // list of info objects
    vector<Info*> infoList;

    // create owner with singleton pattern
    Owner& owner = Owner::getInstance("Andrei Cristian");

    //ui:
    initscr();
    cbreak();
    noecho();

    //colors:
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    //size of the screen
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // start state
    State currentState = MAIN_MENU;

    // main loop
    while (true) {
        clear();

        print_title(currentState, xMax);

        owner.print();

        print_choices(currentState, infoList);

        refresh();

        int choice = getch();

        currentState = next_state(currentState, choice);
    }

    //end ui
    endwin();

    return 0;
}