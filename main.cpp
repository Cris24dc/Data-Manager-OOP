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

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();

    // Prompt for username
    string username;
    char input[100];
    mvprintw(0, 0, "Enter username: ");
    getnstr(input, sizeof(input) - 1);
    username = string(input);

    // Create owner with singleton pattern using user input
    Owner& owner = Owner::getInstance(username);

    // Colors
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    // Size of the screen
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // Start state
    State currentState = MAIN_MENU;

    // Main loop
    while (true) {
        clear();

        print_title(currentState, xMax);

        owner.print();

        print_choices(currentState, infoList);

        refresh();

        int choice = getch();

        currentState = next_state(currentState, choice);
    }

    // End UI
    endwin();

    return 0;
}