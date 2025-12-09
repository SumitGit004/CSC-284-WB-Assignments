#include "TitleBar.h"

TitleBar::TitleBar(int height, int width, int position_y,int  position_x, const std::string & title)
:window (height, width, position_y, position_x), title(title){
   
    window.setColor(COLOR_BLACK, COLOR_WHITE);
    window.setBorder(' ', ' ', ' ', 0 , ' ',' ',' ',' ');
   
    int titleHorizontalCursor = getCenterPos();
    window.print(0,titleHorizontalCursor,title);

} 

int TitleBar::getCenterPos() {

     int titleLength = title.length(),
         width = getmaxx(window.getWindow());
    
    return (width - titleLength)/2;
    
}

 void TitleBar::setTitle(const std::string& title){
    this->title = title;
    
    WINDOW * win = window.getWindow();

    werase(window.getWindow());

    window.setBorder(' ', ' ', ' ', 0, ' ',' ',' ',' ');

    int titlePosX = getCenterPos();
    
    int titlePosY = getmaxy(win) / 2;

    window.print(titlePosY, titlePosX, this->title);

    wrefresh(window.getWindow());
 }


    