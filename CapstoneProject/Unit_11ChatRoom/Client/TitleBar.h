#pragma once

#include "Window.h"

/*
 * A class that models TitleBar
 */
class TitleBar{

    private:
    Window window;
    std::string title;
    int getCenterPos();
    public:

    TitleBar(int height, int width, int position_y,int  position_x, const std::string & title);

    void setTitle(const std::string& title);

    WINDOW* getWindow();

};