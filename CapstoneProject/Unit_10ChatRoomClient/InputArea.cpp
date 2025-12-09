#include "InputArea.h"

InputArea::InputArea(int height, int width, int start_y, int start_x): 
  window(height,width, start_y, start_x){

    window.setColor(COLOR_BLACK, COLOR_WHITE); 

   
    wbkgd(window.getWindow(), COLOR_PAIR(window.getColorPairId())); // set attribute
    werase(window.getWindow()); // overwrite any existing content with bg


    window.setBorder(0, 0, 0, 0, 0, 0, 0, 0);


    window.print(1, 1, "> ");


    wrefresh(window.getWindow());
}

std::string InputArea::getUserInput() {

    WINDOW* win = window.getWindow();
    char userInput[60];
    
    nocbreak(); //enable line buffering
    echo();
    
    mvwgetnstr(win,1, 3, userInput, 59);

    noecho();
    cbreak();

    int height, width;
    getmaxyx(win, height, width);
    mvwhline(win, 1, 3, ' ', width - 5);

    // Move cursor back to input start
    wmove(win, 1, 3);
    inputString = std::string(userInput);

    return inputString;
}


