#include <ncurses.h>
#include "ChatClientUI.h"

void initializeCurses();
int main() {
     
   initializeCurses();
   
   ChatClientUI chatUI;
   
   chatUI.run();

   endwin();
}

void initializeCurses() {
    initscr();
    start_color();
    curs_set(0);
    refresh();
}

