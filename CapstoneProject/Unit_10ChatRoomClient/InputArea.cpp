#include "InputArea.h"

InputArea::InputArea(int height, int width, int start_y, int start_x): 
  window(height,width, start_y, start_x){

    window.setColor(COLOR_BLACK, COLOR_WHITE); 

   
    wbkgd(window.getWindow(), COLOR_PAIR(window.getColorPairId())); // set attribute
    werase(window.getWindow()); // overwrite any existing content with bg


    window.setBorder(0, 0, 0, 0, 0, 0, 0, 0);

    int middleY = height/2;
    window.print(middleY, 1, "> ");


    wrefresh(window.getWindow());
}

void InputArea::handleKey(int key) {
  
  if(key == KEY_BACKSPACE || key == 127 || key == '\b'){
    if(!buffer.empty())
     buffer.pop_back();
  }
  else if(key >=32 && key<= 126)//check if the key is printable
     buffer.push_back(static_cast<char>(key));

  redraw();

}

WINDOW* InputArea::getWindow(){
  return window.getWindow();
}

void InputArea::redraw(){
    
    WINDOW* win = window.getWindow();

    int height, width;
    getmaxyx(win, height, width);

    int middleY = height/2,
       inputX = 3;

   // clears previous input line;
    mvwhline(win, middleY, inputX,' ', width - inputX - 1);

    //draw the text in the buffer
    mvwprintw(win, middleY, inputX, "%s", buffer.c_str());

    wmove(win, middleY, buffer.length() + inputX);
    
    wrefresh(win);
}


std::string InputArea::retrieveBuffer(){
   
  std::string temp = buffer;

  buffer.clear();

  redraw();

  return temp;
}

