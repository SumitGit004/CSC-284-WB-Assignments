#include "MessageArea.h"

MessageArea::MessageArea(int height, int width, int position_y, int position_x) : 
    window(height,width,position_y,position_x), messageLine(1){
    this->window.setColor(COLOR_BLACK, COLOR_YELLOW);
    this->window.setBorder(0,0,0,' ',0,0,0,0);
    messageLine = 1;

    scrollok(window.getWindow(), TRUE);

    displayMessage("Welcome to the chat!");
    displayMessage("This is a placeholder message");
    displayMessage("More messages will appear here later");
}


void MessageArea::displayMessage(const std::string & message){
    window.print(messageLine,1, message);
    messageLine++;
}

WINDOW* MessageArea::getWindow(){
    return window.getWindow();
}