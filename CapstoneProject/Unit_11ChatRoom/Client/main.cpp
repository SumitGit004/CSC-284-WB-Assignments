#include <ncurses.h>
#include "ChatClientUI.h"

void initializeCurses();
int main(int args, char * argv[]) {
    
    std::string ip = "127.0.0.1";
    int port = 54000;
     
    if(args == 2)
    ip = argv[1];
     
    else if(args == 3){
    ip = argv[1];
    port = std::stoi(argv[2]);//convert string to int
    }
     
   initializeCurses();

   ChatClientUI chatUI;

   chatUI.run(ip, port);
   endwin();
}

void initializeCurses() {
    initscr();
    start_color();
    curs_set(0);
    refresh();
}

