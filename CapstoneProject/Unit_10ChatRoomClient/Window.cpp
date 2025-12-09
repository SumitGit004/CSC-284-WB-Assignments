#include "Window.h"

int Window::nextColorPair = 2;


Window::Window(int height, int width, int position_y, int position_x)
     :window(newwin(height, width, position_y, position_x), delwin){
      
     if(window == nullptr) {
          throw std::runtime_error("failed to create window");
     }

     colorPairId = 0;

      static bool borderPairInitialized = false;  //global borderpair 
    if (!borderPairInitialized) {
        init_pair(1, COLOR_WHITE, COLOR_BLACK); // global white border for each window
        borderPairInitialized = true;
    }
    
     if(has_colors()){

        if(nextColorPair < COLOR_PAIRS) {
            colorPairId = nextColorPair++;
            bgColor = COLOR_BLACK;
            fgColor = COLOR_WHITE;
            init_pair(colorPairId, fgColor, bgColor); 
            wattron(window.get(), COLOR_PAIR(colorPairId));//set the attribute for window
            wbkgd(window.get(), COLOR_PAIR(colorPairId));
             werase(window.get());
        }
        else 
        colorPairId = 0;
    }
    wrefresh(window.get());
 }

      


void Window::setBorder(chtype left, chtype right, chtype top, chtype bottom, chtype topLeft, chtype topRight, chtype bottomLeft, chtype bottomRight){
   
    
    
    wattron(getWindow(), COLOR_PAIR(1));
    wborder(window.get(),left,right,top,bottom, topLeft, topRight, bottomLeft,bottomRight);
    wattroff(getWindow(),COLOR_PAIR(1));

    wrefresh(window.get());
}

void Window::print(int position_y, int position_x, const std::string & message){
  
wattron(window.get(), COLOR_PAIR(colorPairId));
mvwprintw(window.get(), position_y, position_x,message.c_str());
wattroff(window.get(), COLOR_PAIR(colorPairId));
wrefresh(window.get());
}


WINDOW* Window::getWindow() {
    return window.get();
}

 void Window::setColor(int backgroundColor, int foregroundColor){
    
     bgColor = backgroundColor;
     fgColor = foregroundColor;
    
    init_pair(colorPairId, fgColor,bgColor);
    
    wbkgd(window.get(), COLOR_PAIR(colorPairId));
    werase(window.get());
    wrefresh(window.get());
 }

 int Window::getColorPairId() const{
  return colorPairId;
 }



