#pragma once
#include "Window.h"
//incomplete for this assignment:
//sockets and other features to be added in next part
class MessageArea{

    private:
    Window window;
    int messageLine;
    
    public:
    MessageArea(int height, int width, int position_y, int position_x);
    void displayMessage(const std::string & string);
    WINDOW* getWindow();
};