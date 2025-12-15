#pragma once
#include "Window.h"

class MessageArea{

    private:
    Window window;
    int messageLine;
    
    public:
    MessageArea(int height, int width, int position_y, int position_x);
    void displayMessage(const std::string & string);
    WINDOW* getWindow();
};