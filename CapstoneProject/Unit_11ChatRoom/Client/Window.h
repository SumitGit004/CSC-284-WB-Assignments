#pragma once

#include <ncurses.h>
#include <string>
#include <memory>

/*
 *class that encapsulates  WINDOW* and provides its functionality 
*/
class Window {
    private:
   // void(*)(Window) is a function pointer to any function taking Window* as agrument
    std::unique_ptr<WINDOW, decltype(&delwin)> window;
    int colorPairId;
    static int nextColorPair;
    short bgColor;
    short fgColor;

    public:

    Window(int height, int width, int position_y, int position_x);
    ~Window() = default;
    void setBorder(chtype left, chtype right, chtype top, chtype bottom, chtype topLeft, chtype topRight, chtype bottomLeft, chtype bottomRight);
    void print(int position_y, int position_x, const std::string & message);
    void moveWindow(int position_y,int position_x);
    WINDOW* getWindow();
    void setColor(int backgroundColor, int foregroundColor);
    int getColorPairId() const;

};