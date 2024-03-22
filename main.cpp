#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstring>
#include "state.hpp"
#include "ui.hpp"
using namespace std;


int main() {


    int id = 0;
    int text_size = 0;
    int number_size = 0;
    int math_size = 0;
    int adress_size = 0;

    text* start_text = nullptr;
    text* end_text = nullptr;
    number* start_number = nullptr;
    number* end_number = nullptr;
    math* start_math = nullptr;
    math* end_math = nullptr;
    adress* start_adress = nullptr;
    adress* end_adress = nullptr;

    loader(id, start_text, end_text, text_size, start_number, end_number, number_size, start_math, end_math, math_size, start_adress, end_adress, adress_size);
    
    //ui:
    initscr();
    cbreak();
    noecho();

    //colors:
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

    //size of the screen
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    State currentState = MAIN_MENU;

    while (true) {
        clear();

        print_title(currentState, xMax);

        print_choices(currentState, start_text, end_text, id, text_size, start_number, end_number, number_size, start_math, end_math, math_size, start_adress, end_adress, adress_size);

        refresh();

        int choice = getch();

        currentState = next_state(currentState, choice);
    }

    endwin();

    return 0;
}
