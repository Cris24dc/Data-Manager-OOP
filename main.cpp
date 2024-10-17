#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream>
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

    // Colors
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    // Get filename
    string filename;
    char input[100];
    bool validfilename = false;

    while (!validfilename) {
        mvprintw(0, 0, "Enter filename (no spaces): ");
        getnstr(input, sizeof(input) - 1);
        filename = string(input);
        
        if (filename.find(' ') != string::npos) {
            attron(COLOR_PAIR(1));
            mvprintw(1, 0, "Error: filename should not contain spaces. Try again.");
            attroff(COLOR_PAIR(1));
            refresh();
            memset(input, 0, sizeof(input));
        } else {
            validfilename = true;
        }
    }

    string filePath = "database/" + filename + ".csv";
    ifstream file(filePath);
    if (!file.good()) {
        ofstream newFile(filePath);
    }

    // Create file with singleton pattern using user input
    File& userfile = File::getInstance(filename);

     // Parse the CSV file
    parseCSV(filePath, infoList);

    // Size of the screen
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // Start state
    State currentState = MAIN_MENU;

    // Main loop
    while (true) {
        clear();

        print_title(currentState, xMax);

        userfile.print();

        print_choices(currentState, infoList, filePath);

        refresh();

        int choice = getch();

        currentState = next_state(currentState, choice);
    }

    // End UI
    endwin();

    return 0;
}
