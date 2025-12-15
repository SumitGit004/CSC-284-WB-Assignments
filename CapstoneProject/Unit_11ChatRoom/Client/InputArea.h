#pragma once

#include "Window.h"

class InputArea{
    private:
    Window window;
    std::string inputString;
    std::string buffer;
    public:

    InputArea(int height, int width, int start_y, int start_x);

    std::string getUserInput();

    WINDOW* getWindow();
    
    void redraw();

    void handleKey(int ch);

    std::string retrieveBuffer();

};