#include "ui.h"

char border_character = (char)219; 
void init_ui(){
    initscr();
    nodelay(stdscr ,TRUE); 
    noecho(); 
    curs_set(0); 
}

void tear_down_ui(){
    endwin();
}

void paint_border(){
    // COLS , LINES
    for(int i= 0 ; i < COLS ; i ++){
        move(0,i);
        addch(border_character);
        move(LINES - 1, i);
        addch(border_character);
    }
    for(int i = 1; i < LINES - 1; i ++){
        move(i, 0);
        addch(border_character);
        move(i, COLS - 1);
        addch(border_character);
    }
   
}